#!/usr/bin/env python3
"""Audit or import canonical French names from pinned PokéAPI CSV files.

The script changes names only. Descriptions and game logic are deliberately
left untouched. Run without --apply to get a coverage report.
"""

from __future__ import annotations

import argparse
import csv
import re
import unicodedata
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def normalized(value: str) -> str:
    value = unicodedata.normalize("NFKD", value)
    value = "".join(char for char in value if not unicodedata.combining(char))
    return "".join(char for char in value.casefold() if char.isalnum())


def gba_name(value: str) -> str:
    return (
        value.replace("’", "'")
        .replace("‐", "-")
        .replace("‑", "-")
        .replace("–", "-")
        .upper()
    )


def localized_names(csv_path: Path) -> dict[str, str]:
    by_id: dict[str, dict[int, str]] = {}
    with csv_path.open(encoding="utf-8", newline="") as source:
        for row in csv.DictReader(source):
            entity_id = next(value for key, value in row.items() if key.endswith("_id"))
            language_id = int(row["local_language_id"])
            if language_id in (5, 9):
                by_id.setdefault(entity_id, {})[language_id] = row["name"]

    names: dict[str, str] = {}
    for translations in by_id.values():
        if 5 in translations and 9 in translations:
            names[normalized(translations[9])] = gba_name(translations[5])
    return names


def replace_names(
    paths: list[Path],
    pattern: re.Pattern[str],
    names: dict[str, str],
    max_length: int,
    apply: bool,
) -> tuple[int, int, set[str], set[str]]:
    matched = 0
    changed = 0
    missing: set[str] = set()
    too_long: set[str] = set()

    for path in paths:
        source = path.read_text(encoding="utf-8")

        def replacement(match: re.Match[str]) -> str:
            nonlocal matched, changed
            english = match.group("name")
            french = names.get(normalized(english))
            if french is None:
                if english not in ("-", "--", "-------", "??????????"):
                    missing.add(english)
                return match.group(0)
            matched += 1
            if len(french) > max_length:
                too_long.add(f"{french} ({len(french)}/{max_length})")
                return match.group(0)
            if french == english:
                return match.group(0)
            changed += 1
            return f'{match.group("prefix")}{french}{match.group("suffix")}'

        updated = pattern.sub(replacement, source)
        if apply and updated != source:
            path.write_text(updated, encoding="utf-8")

    return matched, changed, missing, too_long


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--csv-dir", type=Path, required=True)
    parser.add_argument("--apply", action="store_true")
    args = parser.parse_args()

    jobs = [
        (
            "Pokémon",
            sorted((ROOT / "src/data/pokemon/species_info").glob("*.h")),
            re.compile(r'(?P<prefix>\.speciesName\s*=\s*_\(")(?P<name>[^"]+)(?P<suffix>"\))'),
            localized_names(args.csv_dir / "pokemon_species_names.csv"),
            12,
        ),
        (
            "capacités",
            [ROOT / "src/data/moves_info.h"],
            re.compile(r'(?P<prefix>\.name\s*=\s*COMPOUND_STRING\(")(?P<name>[^"]+)(?P<suffix>"\))'),
            localized_names(args.csv_dir / "move_names.csv"),
            16,
        ),
        (
            "objets",
            [ROOT / "src/data/items.h"],
            re.compile(r'(?P<prefix>\.name\s*=\s*ITEM_NAME\(")(?P<name>[^"]+)(?P<suffix>"\))'),
            localized_names(args.csv_dir / "item_names.csv"),
            20,
        ),
        (
            "talents",
            [ROOT / "src/data/abilities.h"],
            re.compile(r'(?P<prefix>\.name\s*=\s*_\(")(?P<name>[^"]+)(?P<suffix>"\))'),
            localized_names(args.csv_dir / "ability_names.csv"),
            16,
        ),
        (
            "types",
            [ROOT / "src/data/types_info.h"],
            re.compile(r'(?P<prefix>\.name\s*=\s*_\(")(?P<name>[^"]+)(?P<suffix>"\))'),
            localized_names(args.csv_dir / "type_names.csv"),
            12,
        ),
    ]

    mode = "IMPORT" if args.apply else "AUDIT"
    print(f"{mode} DES NOMS FRANÇAIS CANONIQUES")
    for label, paths, pattern, names, max_length in jobs:
        matched, changed, missing, too_long = replace_names(
            paths, pattern, names, max_length, args.apply
        )
        print(
            f"{label}: {matched} correspondances, {changed} modifications, "
            f"{len(missing)} absences, {len(too_long)} dépassements"
        )
        if missing:
            print("  absents: " + ", ".join(sorted(missing)[:20]))
        if too_long:
            print("  trop longs: " + ", ".join(sorted(too_long)[:20]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
