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

Le travail se fait par lots. À l'intérieur d'un lot, **un commit par fichier**, et
un fichier est terminé avant de passer au suivant. Le message suit la forme
`FR: traduire <NomDuFichier>` :

```text
FR: traduire BurnedTower_1F_hns
FR: traduire EcruteakCity_Gym_hns
```

Le lot se termine par un commit de suivi distinct, qui met à jour
`SCRIPT_STATUS.md` et son compteur en une seule fois :

```text
docs: actualiser le suivi du lot de traduction
```

Les commits ne sont poussés qu'à la fin du lot, tous ensemble, après les
contrôles automatiques. Attention : `[skip ci]` sur le dernier commit poussé
annule la CI de **tout** le lot, puisque GitHub n'évalue que le commit de tête.

## Avancement

État actuel du chantier :

- scripts de cartes H&S : **423 / 423 traduits**, dont **0 validé en jeu** ;
- `src/data/text/` : **5 / 5 fichiers traduits**, soit 735 chaînes contrôlées ;
- `data/text/` : **35 / 39 fichiers traduits** ;
- fichiers restant à traduire dans `data/text/` : `apprentice.inc`,
  `match_call.inc`, `trainers.inc` et `tv.inc`.

Ces chiffres ne signifient pas que l'intégralité du jeu est traduite. Les menus,
interfaces et autres textes partagés qui ne figurent pas encore dans l'audit
transversal restent à inventorier. Aucun des fichiers ci-dessus n'a encore été
validé visuellement en jeu.

Le détail fichier par fichier et la source de vérité du suivi se trouvent dans
[SCRIPT_STATUS.md](SCRIPT_STATUS.md).

États employés :

- `à traduire` : rien n'a encore été fait sur le fichier ;
- `traduit, à valider en jeu` : les sources françaises sont en place et les
  contrôles automatiques passent, mais le texte n'a pas encore été vu en jeu ;
- `validé en jeu` : le texte a été vérifié visuellement pendant une partie ;
- `sans chaîne locale à traduire` : le fichier ne contient aucune définition de texte
  locale. Il peut néanmoins appeler un texte ou une interface partagée, suivis dans
  l'audit transversal. Il est exclu du décompte de progression ;
- `bloqué` : accompagné d'une explication.

Aucun fichier ne peut passer à `validé en jeu` sans test sur émulateur. Tant que
ce test n'a pas eu lieu, l'état maximal atteignable est `traduit, à valider en jeu`.

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
- [Sources françaises et ordre de priorité](SOURCES.md)
- [Suivi fichier par fichier des scripts](SCRIPT_STATUS.md)
- [Notice IA : poursuivre la traduction](AI_HANDOFF.md)
