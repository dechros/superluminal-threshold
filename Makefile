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

.PHONY: all release debug run clean
.DEFAULT_GOAL := release

all: release debug

release: $(RELEASE_BIN)

debug: $(DEBUG_BIN)

run: $(RELEASE_BIN)
	@./$(RELEASE_BIN)

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

clean:
	rm -rf build/obj $(RELEASE_BIN) $(DEBUG_BIN)

-include $(RELEASE_OBJS:.o=.d) $(DEBUG_OBJS:.o=.d)
