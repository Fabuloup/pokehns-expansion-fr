# Traduction française de Pokémon Heart & Soul 2.0

Ce dossier regroupe les règles et les ressources propres à la localisation française.

## Base technique

- Projet source : `PokemonHnS-Development/pokehns-expansion`
- Version de départ : `2.0.6`
- Commit de départ : `167aa6d537b109bb229c231ddce4616974c4da71`
- Branche de synchronisation : `master`
- Branche de traduction : `fr/main`

La branche `master` doit rester identique au dépôt officiel. Les mises à jour officielles y sont synchronisées avant d'être intégrées à `fr/main`.

## Principes

1. Traduire directement les sources, jamais une ROM compilée.
2. Employer les noms et termes français officiels de Pokémon lorsqu'ils existent.
3. Préserver exactement les variables, commandes et codes de contrôle.
4. Vérifier chaque texte dans son contexte et dans les limites de l'écran GBA.
5. Garder les commits petits, thématiques et faciles à relire.
6. Ne jamais ajouter de ROM `.gba` au dépôt ou aux tickets GitHub.

## Organisation des contributions

Une modification doit idéalement couvrir un ensemble cohérent : une carte, un menu ou une famille de données. Le message de commit suit la forme `FR: sujet traduit`, par exemple :

```text
FR: dialogues de Bourg Geon
FR: menu principal
FR: noms des objets de soin
```

Chaque lot doit compiler et être testé en jeu avant d'être considéré comme terminé.

## Signalement pendant une partie

Utiliser le formulaire GitHub « Problème de traduction française » et fournir :

- l'emplacement exact dans le jeu ;
- le texte affiché ;
- une capture d'écran si possible ;
- la version ou le commit de la build ;
- une proposition de correction, si utile.

Une sauvegarde interne de Heart & Soul 2.x doit rester compatible entre les builds qui ne changent que les textes. Les save states d'émulateur ne constituent pas une méthode de migration fiable entre deux builds.

## Documents

- [Guide de style](STYLE_GUIDE.md)
- [Glossaire](GLOSSARY.md)
