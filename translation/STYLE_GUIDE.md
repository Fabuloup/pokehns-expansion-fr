# Guide de style français

## Objectif

La traduction doit donner l'impression d'un jeu Pokémon officiellement localisé en français. Une traduction littérale n'est pas une bonne traduction si elle paraît raide, ambiguë ou trop longue à l'écran.

## Terminologie

- Consulter le [glossaire](GLOSSARY.md) avant de traduire un terme récurrent.
- Employer les noms français officiels des Pokémon, capacités, talents, objets, types et lieux lorsqu'ils existent.
- Ne pas traduire un nom propre sans décision documentée dans le glossaire.
- Distinguer une capacité utilisée en combat d'une statistique comme l'Attaque.

## Ton

- Conserver l'intention du personnage : âge, registre, humour et niveau de politesse.
- Préférer une phrase française naturelle à une reproduction mot à mot de l'anglais.
- Éviter les anglicismes lorsqu'un terme Pokémon officiel existe.
- Ne pas ajouter d'information absente du texte source.

## Contraintes techniques

- Conserver à l'identique les variables comme `{PLAYER}`, `{STR_VAR_1}` et `{B_ATK_NAME_WITH_PREFIX}`.
- Conserver les commandes comme `\n`, `\l`, `\p`, `$` et les séquences de contrôle.
- Ne pas déplacer une coupure de page sans vérifier le résultat en jeu.
- Vérifier visuellement chaque texte long. Le nombre de caractères ne suffit pas, car les glyphes n'ont pas tous la même largeur.
- Les caractères français déjà présents dans `charmap.txt`, notamment `à`, `ç`, `è`, `é`, `ê`, `ë`, `î`, `ï`, `ô`, `œ`, `ù` et `û`, peuvent être utilisés.
- Éviter `«` et `»`, absents de la table de caractères actuelle. Utiliser les guillemets disponibles seulement si le contexte l'exige.

## Typographie

- Mettre une espace avant `:`, `;`, `?` et `!` uniquement si l'affichage reste naturel et tient dans la boîte de dialogue.
- Utiliser l'apostrophe typographique `’` lorsque le contexte et les outils la préservent correctement.
- Conserver l'accent sur les majuscules : `É`, `À`, `Ç`.
- Écrire `Pokémon`, `Pokédex` et `Poké Ball` avec leur graphie officielle.

## Relecture

Avant validation, contrôler :

1. le sens par rapport au texte anglais ;
2. la cohérence avec le glossaire ;
3. les variables et codes de contrôle ;
4. les coupures de ligne et de page ;
5. l'affichage réel dans le jeu ;
6. la compilation et les tests automatiques.
