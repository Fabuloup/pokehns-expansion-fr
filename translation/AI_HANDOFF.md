# Relais vers un autre assistant

Ce document permet de confier temporairement la traduction à un autre assistant sans perdre les règles du projet.

## Prompt de reprise

```text
Tu travailles sur le dépôt public https://github.com/nhykola/HeartAndSoul-FR, traduction française de Pokémon Heart & Soul 2.0.6.

Travaille exclusivement sur la branche fr/main. La branche master doit rester identique à l'upstream PokemonHnS-Development/pokehns-expansion.

Avant toute modification :
1. récupère le dernier état de fr/main et vérifie que la CI est verte ;
2. lis intégralement translation/README.md, translation/STYLE_GUIDE.md, translation/GLOSSARY.md et translation/SOURCES.md ;
3. examine les commits récents et le diff avant de modifier un fichier ;
4. vérifie que src/data/pokemon/species_info/gen_2_families.h contient environ 8 876 lignes et n'est pas tronqué.

Règles impératives :
- traduire les sources, jamais une ROM binaire ;
- ne jamais ajouter de fichier .gba, de ROM de base ou de sauvegarde personnelle ;
- employer les noms français officiels des Pokémon, capacités, talents, objets, Baies, lieux, personnages et Dresseurs ;
- privilégier HGSS français pour Johto, puis Or/Argent/Cristal français, puis les données françaises de PokéAPI selon translation/SOURCES.md ;
- conserver exactement les variables et jetons comme {PLAYER}, {RIVAL}, {STR_VAR_1}, ainsi que les contrôles \n, \l, \p, $ et autres séquences ;
- traduire aussi les interfaces, aides de touches et libellés globaux : HP devient PV, Level devient Niveau ou Niv., Next devient Suivant, Back devient Retour, etc. ;
- ne pas modifier la logique du jeu, les identifiants, la structure de sauvegarde ou les mécaniques ;
- travailler par lots larges, avec un commit par fichier de forme « FR: traduire <NomDuFichier> », puis un commit de suivi distinct en fin de lot ;
- ne pousser qu'en fin de lot, tous les commits ensemble ; ne jamais mettre [skip ci] sur le commit de tête, sinon la CI de tout le lot est annulée ;
- contrôler git diff --check, python tools/translation/check_integrity.py, la largeur des chaînes (34 caractères visibles par segment entre \n, \l et \p) et l'absence de dérive des variables et des labels ;
- ne lancer make hns que si la CI échoue, si un fichier contient des changements de script hors chaînes, ou en préparation d'un jalon de test ;
- inspecter le résumé du diff avant chaque push. Une suppression massive ou un fichier réduit de moitié est un blocage, pas un changement à valider ;
- après le push, attendre la fin de GitHub Actions et corriger tout échec avant de déclarer le lot terminé.

N'emploie que les états définis dans translation/README.md. Tant qu'aucun test sur émulateur n'a eu lieu, l'état maximal est « traduit, à valider en jeu » : « validé en jeu » est interdit.

Ne prétends jamais que toute la zone ou toute l'interface est traduite s'il reste des chaînes anglaises dynamiques. Le fait que le projet compile ne prouve rien sur l'exhaustivité d'une zone. À la fin, indique les fichiers modifiés, les contrôles réalisés, les commits et ce qui reste à traduire.
```

## État attendu du dépôt

- `master` : miroir de l'upstream ;
- `fr/main` : branche de traduction et branche par défaut ;
- aucune ROM distribuée dans Git ;
- chaque mise à jour doit conserver les sauvegardes internes de la version 2.x tant qu'elle ne modifie que les textes.
