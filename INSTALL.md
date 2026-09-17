# Installer et tester Heart & Soul FR

Ce document concerne la branche française de Pokémon Heart & Soul. La traduction est encore en développement et aucun patch français stable n'est publié pour le moment.

Deux méthodes seront possibles :

1. **compiler les sources**, méthode actuelle destinée aux contributeurs et testeurs ;
2. **appliquer un patch publié**, méthode prévue pour les futures versions distribuées.

Le dépôt ne contient aucune ROM commerciale et il ne faut jamais y ajouter de fichier `.gba`.

## 1. Compiler la version française actuelle

### Choisir son environnement

- **Windows 10 ou 11** : WSL2 est la méthode recommandée et la plus rapide. Suivre d'abord le [guide WSL](docs/install/windows/WSL.md).
- **Linux** : suivre le guide correspondant à [Ubuntu](docs/install/linux/UBUNTU.md), [Debian](docs/install/linux/DEBIAN.md), [Arch Linux](docs/install/linux/ARCH_LINUX.md), [NixOS](docs/install/linux/NIXOS.md), [Fedora](docs/install/linux/FEDORA.md) ou les [instructions générales](docs/install/linux/OTHERS.md).
- **macOS** : suivre le [guide macOS](docs/install/mac/MAC_OS.md).
- **ChromeOS x86-64** : suivre le [guide ChromeOS](docs/install/chromeos/CHROME_OS.md).

WSL1, MSYS2 et Cygwin peuvent fonctionner sous Windows, mais leur compilation est nettement plus lente. WSL2 doit être privilégié.

### Télécharger la bonne branche

```sh
git clone --branch fr/main --single-branch https://github.com/nhykola/HeartAndSoul-FR.git
cd HeartAndSoul-FR
```

Vérifier la branche active :

```sh
git branch --show-current
```

La commande doit afficher `fr/main`. Ne compilez pas `master` si vous voulez tester la traduction française : cette branche reste le miroir anglais de l'upstream.

### Compiler

Compilation simple :

```sh
make hns
```

Compilation parallèle sous Linux ou WSL2 :

```sh
make hns -j$(nproc) -O
```

Sous macOS :

```sh
make hns -j$(sysctl -n hw.ncpu) -O
```

Lorsque la compilation réussit, la ROM de test se trouve à la racine du dépôt sous le nom :

```text
pokehns.gba
```

Cette ROM est générée localement. Elle ne doit pas être commitée, jointe à une Issue ou redistribuée depuis le dépôt.

### Mettre à jour sa build

Avant de récupérer une nouvelle traduction, faire une sauvegarde normale dans le menu du jeu, fermer l'émulateur et copier le fichier `.sav` dans un emplacement sûr.

Mettre ensuite les sources à jour :

```sh
git switch fr/main
git pull --ff-only
make hns -j$(nproc) -O
```

Remplacer l'ancienne ROM par la nouvelle build en conservant le même nom de fichier. Si la ROM est renommée, la sauvegarde doit généralement porter le même nom de base :

```text
HeartAndSoul-FR.gba
HeartAndSoul-FR.sav
```

Utiliser la sauvegarde interne `.sav`, jamais un save state `.state`, `.state1` ou équivalent pour migrer entre deux builds.

## 2. Appliquer un futur patch français

Cette section deviendra utilisable lorsqu'une Release française fournira un patch `.bps`, `.ups` ou `.xdelta`.

1. Télécharger le patch uniquement depuis les [Releases du dépôt](https://github.com/nhykola/HeartAndSoul-FR/releases).
2. Lire la note de version et utiliser exactement la ROM de base demandée.
3. Vérifier le hash de la ROM de base si la Release en fournit un.
4. Appliquer le patch avec un outil compatible, par exemple Floating IPS pour un fichier `.bps` ou Rom Patcher JS dans un navigateur.
5. Générer une nouvelle ROM. Ne jamais appliquer la nouvelle version par-dessus une ROM déjà patchée.
6. Conserver une copie de la sauvegarde `.sav` avant de remplacer la ROM précédente.

La chaîne correcte sera toujours :

```text
ROM de base propre + patch français de la version choisie = nouvelle ROM française
```

Un patch ne doit pas être appliqué successivement sur les versions françaises précédentes.

## 3. Tester la traduction

Pour chaque build testée :

1. noter le commit avec `git rev-parse --short HEAD` ;
2. utiliser de préférence mGBA ou un cœur mGBA récent ;
3. commencer par une sauvegarde interne connue et copiée en lieu sûr ;
4. vérifier les dialogues, menus, noms, accents, coupures de ligne et textes graphiques ;
5. tester aussi les aides de touches et interactions, pas seulement les dialogues ;
6. signaler chaque problème dans le formulaire [Problème de traduction française](https://github.com/nhykola/HeartAndSoul-FR/issues/new/choose).

Un signalement utile contient :

- le lieu ou l'écran précis ;
- le texte affiché ;
- le texte attendu ou une proposition ;
- le commit testé ;
- une capture d'écran si possible ;
- l'émulateur ou le cœur utilisé.

## 4. Contrôles avant contribution

Avant de pousser une modification :

```sh
git diff --check
make hns -j$(nproc) -O
```

Examiner ensuite le résumé :

```sh
git diff --stat
```

Une suppression massive inattendue, un fichier remplacé presque entièrement ou une baisse brutale du nombre de lignes doit bloquer le push jusqu'à vérification.

## 5. Outils utiles

- [Porymap](https://github.com/huderlem/porymap) pour visualiser et modifier les cartes ;
- [Porytiles](https://github.com/grunt-lucas/porytiles) pour les metatiles ;
- [Poryscript](https://github.com/huderlem/poryscript) pour les scripts ;
- [Tilemap Studio](https://github.com/Rangi42/tilemap-studio) pour les tilemaps.

Les problèmes propres à la traduction française doivent être signalés sur ce dépôt. Les développeurs du projet anglais ne sont pas responsables des erreurs introduites par la localisation.
