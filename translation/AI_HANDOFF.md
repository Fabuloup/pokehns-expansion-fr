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
- faire des lots petits et cohérents, avec des commits de forme « FR: sujet traduit » ;
- contrôler git diff --check, les caractères via le préprocesseur du projet et la compilation make hns ;
- inspecter le résumé du diff avant chaque push. Une suppression massive ou un fichier réduit de moitié est un blocage, pas un changement à valider ;
- après le push, attendre la fin de GitHub Actions et corriger tout échec avant de déclarer le lot terminé.

Ne prétends jamais que toute la zone ou toute l'interface est traduite s'il reste des chaînes anglaises dynamiques. À la fin, indique les fichiers modifiés, les contrôles réalisés, le commit et ce qui reste à traduire.
```

## État attendu du dépôt

- `master` : miroir de l'upstream ;
- `fr/main` : branche de traduction et branche par défaut ;
- aucune ROM distribuée dans Git ;
- chaque mise à jour doit conserver les sauvegardes internes de la version 2.x tant qu'elle ne modifie que les textes.
