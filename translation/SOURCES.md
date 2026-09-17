# Sources de terminologie française

Il n'existe pas une base unique qui couvre correctement tous les textes de Heart & Soul. La traduction utilise donc plusieurs références, avec un ordre de priorité explicite.

## Ordre de priorité

1. **Localisation française de Pokémon HeartGold et SoulSilver** pour les lieux, personnages, classes et noms de Dresseurs de Johto, ainsi que les dialogues repris de ces jeux.
2. **Localisation française de Pokémon Or, Argent et Cristal** pour les dialogues ou éléments absents de HGSS.
3. **Données françaises de PokéAPI** pour les noms structurés : Pokémon, capacités, talents, objets, types et Baies.
4. **Poképédia** pour vérifier manuellement un nom, une différence entre générations ou le contexte d'une localisation.
5. **Bulbapedia** pour retrouver les correspondances entre identifiants anglais et personnages, jamais comme autorité principale pour la formulation française.

Lorsqu'une traduction diffère entre Cristal et HGSS, la version HGSS est privilégiée si Heart & Soul reprend le personnage ou la scène du remake. Par exemple, `Bug Catcher Wade` devient `Scout Francis`, et non `Scout Maxime`.

## Noms structurés

Les listes importantes ne doivent pas être traduites à la main au fil des fichiers. Une table de référence versionnée doit être générée à partir d'une version figée de PokéAPI, puis relue avant application :

- noms des Pokémon et de leurs formes ;
- capacités ;
- talents ;
- objets ;
- types ;
- Baies.

L'import actuel utilise les fichiers CSV de PokéAPI au commit
`5c776e225f2150862e021062d7f304c8958368cc`. Le script
`tools/translation/import_canonical_names.py` rapproche les noms anglais déjà
présents dans le moteur des noms français partageant le même identifiant. Il
refuse les noms dépassant les limites de stockage du moteur et signale les
formes ou objets sans correspondance.

Le type `Stellaire` constitue actuellement une exception documentée : son nom
français compte neuf caractères, alors que `TYPE_NAME_LENGTH` est limité à
huit. Le projet conserve donc provisoirement `STELLAR` plutôt que de tronquer
le nom officiel ou de modifier la structure du moteur sans audit dédié.

Pour les données des trois premières générations, le résultat est également
comparé à la décompilation de la ROM française officielle Pokémon Émeraude :
`kleeenexfeu/pokeemerald-french`. Cette seconde source permet de repérer les
différences dues aux accents, aux abréviations historiques et aux limites de la
version GBA.

Les CT et CS demandent un traitement particulier. Leur numéro dépend de la table utilisée par Heart & Soul. Il faut d'abord relier chaque CT ou CS à sa capacité dans les sources du jeu, puis employer le nom français officiel de cette capacité. Copier une liste de CT d'un autre jeu produirait des associations incorrectes.

## Dresseurs et personnages

PokéAPI ne fournit pas une table suffisamment complète des Dresseurs scénarisés. Les noms français doivent être rapprochés de leur identifiant anglais à partir des jeux concernés. Le couple complet est versionné dans le glossaire ou dans une future table dédiée afin d'éviter qu'un même personnage change de nom selon les fichiers.

## Règle de validation

Une donnée issue d'une API ou d'un wiki est une référence de travail, pas une validation automatique. Avant intégration, il faut contrôler :

1. la génération et le jeu concernés ;
2. les variantes de formes ou d'objets ;
3. les limites de longueur du moteur GBA ;
4. la cohérence avec les autres textes déjà traduits ;
5. l'affichage réel dans le jeu.
