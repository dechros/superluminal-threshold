"""Measurable rules for the register a Turkish scientific text is written in,
gathered from the article file and folded into one list.

Each rule is a number, so a text can be held to it instead of argued about,
and each rule is owned by its own module in this package. The rules come
from the conventions Turkish journals state for scientific prose and from
measuring prose accepted as well written in that language. This module opens
the file the rules are measured against and combines their findings; it
states no rule of its own.

Mirrors src/critique/ProseRegister.h/.cpp, run() included.
"""

from __future__ import annotations

from pathlib import Path

from .report import Report
from . import (
    first_person,
    heading,
    nominal_chain,
    number_suffix,
    opening_conjunction,
    passive_voice,
    predicate_mix,
    self_reference,
    sentence_length,
    typography,
)

ARTICLE_PATH = Path("article/article.md")


def text() -> str:
    try:
        return ARTICLE_PATH.read_text(encoding="utf-8")
    except OSError:
        return ""


def run(report: Report) -> None:
    document = text()

    report.subsection("The text has to be there to be measured")
    report.check("the text was opened and is not empty", bool(document))
    if not document:
        return

    report.subsection("First person, which this register does not allow")
    persons = first_person.first_person(document)
    for fault in persons:
        report.check(f"  line {fault.line}: {fault.excerpt}", False)
    report.check(
        "no sentence is written in the first person, singular or plural, and the "
        "work is not spoken of as the writer's own",
        not persons,
    )

    report.subsection("The text discussing the text")
    selves = self_reference.self_reference(document)
    for fault in selves:
        report.check(f"  line {fault.line}: {fault.excerpt}", False)
    report.check(
        "no sentence instructs the reader about the document instead of stating "
        "the claim it was wrapping",
        not selves,
    )

    report.subsection("Sentence length, measured against Turkish prose of this kind")
    longs = sentence_length.long_sentences(document)
    for fault in longs:
        report.check(f"  line {fault.line}: {fault.excerpt}", False)
    report.check(
        f"no sentence passes {sentence_length.word_limit} words unless it is carrying a list",
        not longs,
    )

    report.subsection("Passives, which are allowed but may not stack")
    stacked = passive_voice.stacked_passives(document)
    for fault in stacked:
        report.check(f"  line {fault.line}: {fault.rule} | {fault.excerpt}", False)
    report.check(
        f"no paragraph carries more than {passive_voice.passives_per_paragraph} passive "
        "constructions, past which nothing in it has a subject",
        not stacked,
    )

    report.subsection("Sentences opening with a bare conjunction")
    openers = opening_conjunction.opening_conjunctions(document)
    for fault in openers:
        report.check(f"  line {fault.line}: {fault.excerpt}", False)
    report.check(
        "no sentence begins with a conjunction, which is how breaking a long "
        "sentence turns written Turkish into spoken Turkish",
        not openers,
    )

    report.subsection("Chains of verbal nouns, the fault the other rules leave behind")
    chains = nominal_chain.nominal_chains(document)
    for fault in chains:
        report.check(f"  line {fault.line}: {fault.rule} | {fault.excerpt}", False)
    report.check(
        f"no sentence carries more than {nominal_chain.nominals_per_sentence} verbal nouns "
        "unless it is an enumeration",
        not chains,
    )

    report.subsection("Suffixes agreeing with how a number is read")
    suffixes = number_suffix.number_suffixes(document)
    for fault in suffixes:
        report.check(f"  line {fault.line}: {fault.excerpt}", False)
    report.check(
        "every reference takes the possessive ending its number takes when it "
        "is said aloud, which the digit alone does not decide",
        not suffixes,
    )

    report.subsection("Headings that name rather than assert")
    headings = heading.verbal_headings(document)
    for fault in headings:
        report.check(f"  line {fault.line}: {fault.excerpt} ({fault.rule})", False)
    report.check(
        "every heading is a noun phrase, which is what the two hundred and "
        "thirty eight headings of the measured corpus are",
        not headings,
    )
    mean = heading.heading_word_mean(document)
    report.check(
        f"  the headings average {mean // 10}.{mean % 10} words, at most "
        f"{heading.mean_tenths // 10}.{heading.mean_tenths % 10}, against a corpus median of "
        "three",
        mean <= heading.mean_tenths,
    )

    report.subsection("The mix of predicate forms, which a drifting text concentrates")
    mix = predicate_mix.predicate_mix(document)
    for name, share in mix:
        report.check(f"  {name} carries {share}% of the sentence endings", True)
    shares = dict(mix)
    copula = shares.get("-dır", 0)
    continuous = shares.get("-maktadır", 0)
    aorist = shares.get("-ir", 0)
    past_passive = shares.get("-mıştır", 0)
    report.check(
        f"the copula carries {copula}% of the endings, at most {predicate_mix.copula_share_limit}",
        copula <= predicate_mix.copula_share_limit,
    )
    report.check(
        f"the aorist carries {aorist}%, at most {predicate_mix.aorist_share_limit}, so a "
        "finding is not always stated as a timeless law",
        aorist <= predicate_mix.aorist_share_limit,
    )
    report.check(
        f"the present continuous carries {continuous}%, at least "
        f"{predicate_mix.continuous_share_floor}",
        continuous >= predicate_mix.continuous_share_floor,
    )
    report.check(
        f"the reported past carries {past_passive}%, at least "
        f"{predicate_mix.past_passive_share_floor}, which is the form a completed operation "
        "takes",
        past_passive >= predicate_mix.past_passive_share_floor,
    )

    report.subsection("Passive density, which a per-paragraph cap cannot see")
    density = passive_voice.passive_density(document)
    report.check(
        f"the prose carries {density:.1f} passives per thousand words, at most "
        f"{passive_voice.passive_per_thousand_limit}",
        density <= passive_voice.passive_per_thousand_limit,
    )

    report.subsection("The house rule on the em dash")
    report.check("the em dash appears nowhere", not typography.em_dashes(document))
    report.check(
        "every number inside mathematics carries a comma for its decimal separator, the way "
        "the text reads it aloud",
        not typography.decimal_points(document),
    )

    report.subsection("What this section still does not measure")
    report.check(
        "word order inside a clause, and whether a paragraph argues in the order a reader "
        "needs, are not counted anywhere here, so a green run is not a certificate that the "
        "prose reads well",
        True,
    )
