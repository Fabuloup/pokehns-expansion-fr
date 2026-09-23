![Logo de Pokémon Heart & Soul](HnS_Logo.png)

# Pokémon Heart & Soul 2.0, traduction française

[![Build](https://github.com/nhykola/HeartAndSoul-FR/actions/workflows/build.yml/badge.svg?branch=fr%2Fmain)](https://github.com/nhykola/HeartAndSoul-FR/actions/workflows/build.yml)

Ce dépôt héberge une **traduction française communautaire de Pokémon Heart & Soul 2.0**. Certaines traductions sont récupérées de [https://github.com/nhykola/HeartAndSoul-FR](https://github.com/nhykola/HeartAndSoul-FR).

Il s'agit d'un fork du projet anglais [`PokemonHnS-Development/pokehns-expansion`](https://github.com/PokemonHnS-Development/pokehns-expansion). La traduction est réalisée directement dans les sources afin de rester maintenable lorsque le projet original reçoit des corrections.

> [!WARNING]
> La traduction française est en cours de développement. Aucune version française complète et stable n'est encore disponible.

![Exploration dans Pokémon Heart & Soul](HnS_Collage_Exploration.PNG)

## État du projet

- Base actuelle : **Heart & Soul 2.0.6**
- Branche officielle conservée : [`master`](https://github.com/Fabuloup/pokehns-expansion-fr/tree/master)
- Branche de traduction : [`trad/fr`](https://github.com/Fabuloup/pokehns-expansion-fr/tree/trad/fr)
- Traduction : **scripts de cartes terminés, interfaces en cours**
- Première version jouable française : **pas encore publiée**
- Aucun texte n'a encore été vérifié en jeu

État au 22/09/2026 :

| Zone | Avancement |
|---|---|
| Scripts de cartes (`data/maps/*_hns`) | 423 / 423 traduits |
| Textes transversaux (`data/text`, `src/data/text`) | 44 / 44 traduits |
| Cartes héritées accessibles (Hoenn via la Zone de Combat) | ~10 900 chaînes anglaises |
| Reste des sources (`src/`, `data/scripts`) | ~3 300 chaînes anglaises |

Le suivi détaillé, fichier par fichier, est dans
[`translation/SCRIPT_STATUS.md`](translation/SCRIPT_STATUS.md). Attention : son
compteur ne porte que sur les zones qu'il recense, et ne mesure donc pas
l'avancement du jeu entier.

Le plus visible de ce qui reste est `src/battle_message.c`, qui contient tous les
messages de combat. Chaque lot doit être compilé, relu et vérifié en jeu.

## Qu'est-ce que Pokémon Heart & Soul ?

Pokémon Heart & Soul 2.0 est un ROM hack GBA qui recrée l'aventure de Johto. Il combine des éléments de Pokémon Or, Argent et Cristal avec des éléments de HeartGold et SoulSilver, tout en ajoutant des améliorations de confort et des mécaniques issues de générations plus récentes.

Le projet original repose notamment sur :

- [`pokehns-expansion`](https://github.com/PokemonHnS-Development/pokehns-expansion), le projet Heart & Soul original ;
- [`Modern Emerald`](https://github.com/resetes12/pokeemerald) de resetes12 ;
- [`pokeemerald-expansion`](https://github.com/rh-hideout/pokeemerald-expansion) de Rom Hacking Hideout ;
- [`pokeemerald`](https://github.com/pret/pokeemerald) de pret.

La liste détaillée des fonctionnalités est disponible dans [`FEATURES.md`](FEATURES.md). Les fonctionnalités héritées de `pokeemerald-expansion` sont recensées dans [`AVAILABLE_FEATURES.md`](AVAILABLE_FEATURES.md).

## Objectifs de la traduction

- employer les noms français officiels des Pokémon, capacités, talents, objets et types ;
- proposer des dialogues naturels, pas une traduction automatique mot à mot ;
- respecter les variables et les codes de contrôle du moteur ;
- adapter les formulations aux contraintes d'affichage de la GBA ;
- permettre la synchronisation avec les futures corrections du projet original ;
- publier uniquement des fichiers légaux et redistribuables, jamais une ROM Pokémon.

Les choix de traduction sont documentés dans le [guide de style](translation/STYLE_GUIDE.md), le [glossaire](translation/GLOSSARY.md) et la [hiérarchie des sources françaises](translation/SOURCES.md).

## Tester et signaler une erreur

Pendant les phases de test, un problème peut être signalé dans les [Issues GitHub](https://github.com/nhykola/HeartAndSoul-FR/issues/new/choose) avec le formulaire **« Problème de traduction française »**.

Merci d'indiquer :

- l'endroit exact dans le jeu ;
- le texte affiché ;
- la version ou le commit utilisé ;
- une capture d'écran si possible ;
- la correction proposée, si vous en avez une.

Les textes encore en anglais, les formulations maladroites, les incohérences de terminologie et les dépassements de boîtes de dialogue doivent tous être signalés.

## Sauvegardes

Les sauvegardes antérieures à Heart & Soul 2.0 ne sont pas compatibles avec la version 2.x.

Les mises à jour qui ne modifient que les textes sont conçues pour conserver la compatibilité des sauvegardes internes entre les builds françaises. Faites malgré tout une copie du fichier `.sav` avant chaque changement de version.

N'utilisez pas un save state d'émulateur pour migrer vers une nouvelle build. Sauvegardez d'abord normalement depuis le menu du jeu.

## Installer, compiler et tester

Les instructions adaptées à la traduction française sont disponibles dans [`INSTALL.md`](INSTALL.md). Elles expliquent comment compiler une ROM de test, conserver une sauvegarde entre deux builds et, lorsqu'un patch sera publié, l'appliquer légalement à la ROM de base demandée.

La commande principale de compilation est :

```sh
make hns
```

Le commande optimisée de compilation est :

```sh
make hns -j$(nproc)
```

Le dépôt ne contient et ne distribuera aucune ROM `.gba`. Les Releases proposeront uniquement des éléments redistribuables, comme un patch, lorsque la traduction sera suffisamment avancée.

## Contribuer

Les principes de travail sont détaillés dans [`translation/README.md`](translation/README.md).

Les contributions doivent rester limitées à un ensemble cohérent, par exemple une carte, un menu ou une famille de données. Les variables comme `{PLAYER}`, ainsi que les commandes `\n`, `\l`, `\p` et `$`, doivent être conservées avec précision.

## Crédits

La traduction française n'existerait pas sans le travail de l'équipe de **Pokémon Heart & Soul** et de tous les projets dont elle dépend. La chaîne complète des contributeurs doit être conservée. Consultez [`CREDITS.md`](CREDITS.md) pour les crédits détaillés.

Le serveur Discord du projet original est accessible [ici](https://discord.gg/ksNTFNSBj). Les problèmes propres à la traduction française doivent être signalés sur ce dépôt, pas aux développeurs du projet original.

## Utilisation de l'intelligence artificielle

Cette localisation utilise ChatGPT, Codex et éventuellement d'autres assistants pour analyser le code, repérer les textes, préparer les outils et produire une première proposition de traduction française. L'intelligence artificielle participe donc directement au travail de traduction, mais aucune proposition n'est considérée comme fiable par défaut. Les textes doivent être comparés aux sources françaises officielles disponibles, relus, corrigés, compilés et testés dans leur contexte avant validation.

Les consignes permettant de reprendre le travail avec un autre assistant sont disponibles dans [`translation/AI_HANDOFF.md`](translation/AI_HANDOFF.md).

Le projet original possède également sa propre politique concernant l'utilisation d'outils d'intelligence artificielle. Elle reste consultable dans l'historique et le dépôt officiel.

## Avertissement

Ce projet communautaire n'est affilié ni à Nintendo, ni à Game Freak, ni à Creatures Inc., ni à The Pokémon Company. Pokémon et les marques associées appartiennent à leurs détenteurs respectifs.
