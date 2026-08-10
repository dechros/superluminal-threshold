# ============================================================================
#  superluminal-threshold
# ----------------------------------------------------------------------------
#  Each source compiles to its own object under build/obj, which buys both
#  parallel and incremental builds. A single g++ invocation over all sources
#  took about 50 s; this takes about 7 s on 8 jobs, and about 3 s when one file
#  has changed.
#
#  .vscode/tasks.json calls these targets. By hand:
#     make -j        release build, the default
#     make -j debug  debug build
#     make run       build release and run it
#     make clean     remove the build output
# ============================================================================

CXX      := g++
STD      := -std=c++26
WARN     := -Wall -Wextra -Wpedantic
INCLUDES := -I src

RELEASE_FLAGS := -O2 -DNDEBUG
DEBUG_FLAGS   := -O0 -g3 -fno-omit-frame-pointer

SOURCES := main.cpp $(wildcard src/*/*.cpp)

RELEASE_OBJDIR := build/obj/release
DEBUG_OBJDIR   := build/obj/debug
RELEASE_OBJS   := $(SOURCES:%.cpp=$(RELEASE_OBJDIR)/%.o)
DEBUG_OBJS     := $(SOURCES:%.cpp=$(DEBUG_OBJDIR)/%.o)

RELEASE_BIN := build/superluminal
DEBUG_BIN   := build/superluminal-debug

# Dependency files, so a changed header also triggers a rebuild.
DEPFLAGS = -MMD -MP

.PHONY: all release debug run clean pdf
.DEFAULT_GOAL := release

all: release debug

release: $(RELEASE_BIN)

debug: $(DEBUG_BIN)

#  The physics half and the article-analysis half are two processes (see
#  tools/check_article.py), so both always run and both print their full
#  report even when one of them fails; only the combined exit code decides
#  whether the target fails, the way a single process's report used to.
run: $(RELEASE_BIN)
	@mkdir -p build
	@./$(RELEASE_BIN); cpp=$$?; python tools/check_article.py; py=$$?; test $$cpp -eq 0 -a $$py -eq 0

$(RELEASE_BIN): $(RELEASE_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(RELEASE_OBJS) -o $@

$(DEBUG_BIN): $(DEBUG_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(DEBUG_OBJS) -o $@

$(RELEASE_OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(STD) $(WARN) $(RELEASE_FLAGS) $(INCLUDES) $(DEPFLAGS) -c $< -o $@

$(DEBUG_OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(STD) $(WARN) $(DEBUG_FLAGS) $(INCLUDES) $(DEPFLAGS) -c $< -o $@

# ----------------------------------------------------------------------------
#  Manuscript
# ----------------------------------------------------------------------------
#  The text carries its own section numbers, so automatic numbering stays off
#  and two passes are needed: the first writes the table of contents, the second
#  places the page numbers in it. A missing engine is reported rather than
#  skipped, because a build that quietly produces nothing reads as a build that
#  had nothing to do.

PDF_DIR := build/pdf
PDF     := $(PDF_DIR)/article.pdf

# The engine is looked up in the shell rather than in a variable, because the
# Windows location of a per user install is held in an environment variable
# whose separators make would eat.
FIND_XELATEX = command -v xelatex 2>/dev/null ||                ls "$$HOME/AppData/Local/Programs/MiKTeX/miktex/bin/x64/xelatex.exe" 2>/dev/null

pdf: $(PDF)

$(PDF): article/article.md tools/prepare-pdf.py tools/preamble.tex
	@mkdir -p $(PDF_DIR)
	@command -v pandoc >/dev/null || { echo "pandoc not found"; exit 1; }
	@$(FIND_XELATEX) >/dev/null || { echo "xelatex not found, install a TeX distribution"; exit 1; }
	python tools/prepare-pdf.py article/article.md $(PDF_DIR)/prepared.md $(PDF_DIR)/meta.yaml
	pandoc $(PDF_DIR)/meta.yaml $(PDF_DIR)/prepared.md -f markdown+raw_tex -t latex -s 	  --pdf-engine=xelatex -V documentclass=report -V geometry:a4paper,margin=2.4cm 	  -V fontsize=10pt -V colorlinks=true -V linkcolor=black -V toccolor=black 	  -H tools/preamble.tex --toc --toc-depth=2 -o $(PDF_DIR)/article.tex
	@xe=$$($(FIND_XELATEX)); cd $(PDF_DIR) && 	  "$$xe" -interaction=nonstopmode article.tex > pass1.log 2>&1 && 	  "$$xe" -interaction=nonstopmode article.tex > pass2.log 2>&1
	@test -f $(PDF) || { echo "no pdf produced, see $(PDF_DIR)/pass2.log"; exit 1; }
	@grep -a "Output written" $(PDF_DIR)/pass2.log

clean:
	rm -rf build/obj $(RELEASE_BIN) $(DEBUG_BIN) $(PDF_DIR)

-include $(RELEASE_OBJS:.o=.d) $(DEBUG_OBJS:.o=.d)
