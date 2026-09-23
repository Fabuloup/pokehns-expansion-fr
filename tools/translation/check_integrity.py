#!/usr/bin/env python3

"""Refuse obvious file truncation and invalid UTF-8 in translation sources."""

from pathlib import Path
import sys


MINIMUM_FILE_SIZES = {
    Path("src/data/pokemon/species_info/gen_1_families.h"): 700_000,
    Path("src/data/pokemon/species_info/gen_2_families.h"): 300_000,
    Path("src/data/pokemon/species_info/gen_3_families.h"): 450_000,
    Path("src/data/pokemon/species_info/gen_4_families.h"): 250_000,
    Path("src/data/pokemon/species_info/gen_5_families.h"): 450_000,
    Path("src/data/pokemon/species_info/gen_6_families.h"): 260_000,
    Path("src/data/pokemon/species_info/gen_7_families.h"): 260_000,
    Path("src/data/pokemon/species_info/gen_8_families.h"): 280_000,
    Path("src/data/pokemon/species_info/gen_9_families.h"): 280_000,
    Path("src/data/moves_info.h"): 700_000,
    Path("src/data/items.h"): 450_000,
    Path("src/data/abilities.h"): 50_000,
    Path("src/data/types_info.h"): 18_000,
}

TEXT_PATHS = (
    Path("README.md"),
    Path("INSTALL.md"),
    Path("translation"),
    Path("src/data/pokemon/species_info"),
    Path("src/data/moves_info.h"),
    Path("src/data/items.h"),
    Path("src/data/abilities.h"),
    Path("src/data/types_info.h"),
    Path("data/text/oak_speech_hns.inc"),
    Path("data/maps/NewBarkTown_hns/scripts.inc"),
    Path("data/maps/NewBarkTown_Lab_hns/scripts.inc"),
    Path("data/maps/NewBarkTown_PlayersHouse_1F_hns/scripts.inc"),
    Path("data/maps/NewBarkTown_PlayersHouse_2F_hns/scripts.inc"),
    Path("data/maps/NewBarkTown_House1_hns/scripts.inc"),
    Path("data/maps/NewBarkTown_House2_hns/scripts.inc"),
)


def iter_files(path: Path):
    if path.is_file():
        yield path
    elif path.is_dir():
        yield from (candidate for candidate in path.rglob("*") if candidate.is_file())


def main() -> int:
    errors = []

    for path, minimum_size in MINIMUM_FILE_SIZES.items():
        if not path.is_file():
            errors.append(f"fichier critique absent : {path}")
            continue
        size = path.stat().st_size
        if size < minimum_size:
            errors.append(
                f"fichier critique probablement tronqué : {path} "
                f"({size} octets, minimum {minimum_size})"
            )

    for root in TEXT_PATHS:
        for path in iter_files(root):
            try:
                path.read_text(encoding="utf-8")
            except UnicodeDecodeError as error:
                errors.append(f"UTF-8 invalide dans {path} : {error}")

    if errors:
        for error in errors:
            print(f"ERREUR : {error}", file=sys.stderr)
        return 1

    print("Intégrité des fichiers de traduction vérifiée.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
