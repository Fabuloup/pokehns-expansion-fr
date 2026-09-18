# Glossaire français

Ce glossaire fixe les choix récurrents du projet. Il doit évoluer à partir des traductions françaises officielles et des vérifications en jeu.

| Anglais | Français retenu | Remarque |
|---|---|---|
| Ability | talent | Terme des jeux Pokémon modernes |
| accuracy | Précision | Statistique de combat |
| Attack | Attaque | Statistique |
| Bag | Sac | Nom du menu |
| battle | combat | Selon le contexte |
| Berry | Baie | Majuscule pour un nom d'objet |
| Defense | Défense | Statistique |
| Egg | Œuf | Terme Pokémon |
| Elm | Orme | Professeur Pokémon de Bourg Geon |
| fainted | est K.O. | Adapter à la phrase et au sujet |
| item | objet | Terme générique |
| HP | PV | Abréviation française officielle de « points de vie » |
| Level | Niveau | Utiliser `Niv.` lorsque l'espace est limité |
| move | capacité | Attaque utilisable par un Pokémon |
| party | équipe | Pokémon actuellement transportés |
| Pokédex | Pokédex | Graphie officielle |
| Pokégear | Pokématos | Graphie officielle française |
| Pokémon Center | Centre Pokémon | Graphie officielle |
| Running Shoes | Chaussures de Sport | Nom officiel de l'objet |
| Special Attack | Attaque Spéciale | Abréviation à valider selon l'écran |
| Special Defense | Défense Spéciale | Abréviation à valider selon l'écran |
| Speed | Vitesse | Statistique |
| Trainer | Dresseur / Dresseuse | Accorder seulement si le contexte permet de connaître le genre |
| wild Pokémon | Pokémon sauvage | Accorder le reste de la phrase avec Pokémon |

## Commandes et interactions

| Anglais | Français retenu |
|---|---|
| Back | Retour |
| Cancel | Annuler |
| Confirm | Confirmer |
| Down | Bas |
| Exit | Quitter |
| Next | Suivant |
| Pick / Select | Choisir / Sélectionner | Selon l'espace disponible et le contexte |
| Up | Haut |

## Lieux et personnages de Johto

| Anglais | Français retenu |
|---|---|
| Azalea Town | Écorcia |
| Burned Tower | Tour Cendrée |
| Bugsy | Hector |
| Cherrygrove City | Ville Griotte |
| Cianwood City | Irisia |
| Ecruteak City | Rosalia |
| Elder Li | Ancien Jehan |
| Eusine | Eusine |
| Falkner | Albert |
| Indigo Plateau | Plateau Indigo |
| Kurt | Fargas |
| Lance | Peter |
| Morty | Mortimer |
| New Bark Town | Bourg Geon |
| Oak | Chen |
| Olivine City | Oliville |
| Proton | Lance |
| Tin Tower | Tour Ferraille |
| Violet City | Mauville |
| Whirl Islands | Tourb'Îles |

> **Piège à ne pas inverser.** L'anglais `Lance`, le maître dragon, devient
> **Peter**. L'anglais `Proton`, le sbire de la Team Rocket, devient **Lance**.
> Le mot « Lance » existe donc dans les deux langues mais ne désigne pas la même
> personne.

`Tin Tower` reste **Tour Ferraille**, nom français des versions Or, Argent et
Cristal : les scripts et les cartes de Heart & Soul emploient explicitement le
nom anglais historique `Tin Tower`, et non `Bell Tower` (Tour Carillon).

## Lieux de Kanto

| Anglais | Français retenu |
|---|---|
| Celadon City | Céladopole |
| Cycling Road | Piste Cyclable |
| Game Corner | Casino |
| Saffron City | Safrania |

## Classes de Dresseurs du début du jeu

| Anglais | Français officiel retenu |
|---|---|
| Bird Keeper | Ornithologue |
| Bug Catcher | Scout |
| Camper | Campeur |
| Cooltrainer | Topdresseur |
| Firebreather | Crache-Feu |
| Fisherman | Pêcheur |
| Gym Leader | Champion |
| Hiker | Montagnard |
| Picnicker | Pique-Nique |
| Rocket Executive / Admin | Cadre Rocket |
| School Kid | Écolier |
| Twins | Jumelles |
| Youngster | Gamin |

## Famille des jours de la semaine

| Jour | Anglais | Français officiel |
|---|---|---|
| Lundi | Monica | Lucie |
| Mardi | Tuscany | Marie |
| Mercredi | Wesley | Homer |
| Jeudi | Arthur | Jérome |
| Vendredi | Frieda | Vanessa |
| Samedi | Santos | Samuel |
| Dimanche | Sunny | Dimitri |

## Dresseurs récurrents

| Identifiant anglais | Français retenu | Référence |
|---|---|---|
| Bug Catcher Wade | Scout Francis | Localisation française de HeartGold et SoulSilver |
| Bruno | Aldo | Membre du Conseil 4 |
| Daisy | Nina | Sœur du Champion de Jadielle |
| Janine | Jeannine | Championne de Parmanie |

## Libellés de classes affichés

Définis dans `gTrainerClasses` de `src/battle_main.c`, et non dans
`trainers_hns.party` dont le champ `Class:` n'est qu'une clé. Longueur de
référence : **13 caractères**, la plus longue valeur préexistante.

Ancrés dans le dépôt, déjà employés dans les dialogues traduits :

| Anglais | Français | Ancrage |
|---|---|---|
| Elite Four | CONSEIL 4 | Employé dans les scripts traduits |
| Kimono Girl | FILLE KIMONO | Employé dans les scripts traduits |

Choix du projet, vocabulaire courant des classes de Dresseurs. À confirmer
en jeu :

| Anglais | Français | | Anglais | Français |
|---|---|---|---|---|
| Battle Girl | COMBATTANTE | | Lass | FILLETTE |
| Beauty | CANON | | Mystery Man | HOMME MYSTÈRE |
| Biker | MOTARD | | Officer | AGENT |
| Black Belt | KARATÉKA | | Parasol Lady | MISS PARASOL |
| Burglar | CAMBRIOLEUR | | Psychic | KINÉSISTE |
| Collector | COLLECTIONNEUR | | Sailor | MARIN |
| Developer | DÉVELOPPEUR | | Skier | SKIEUR |
| Dragon Tamer | DRACOLOGUE | | Super Nerd | INTELLO |
| Guitarist | GUITARISTE | | Swimmer | NAGEUR / NAGEUSE |
| Hex Maniac | MYSTIMANIAC | | Young Couple | JEUNE COUPLE |
| Juggler | JONGLEUR | | | |

`COLLECTIONNEUR` fait 14 caractères et dépasse la norme de 13 : à vérifier
en priorité sur un écran de combat.

Titres de la Zone de Combat. Aucune source, invention assumée, les plus
fragiles de la liste :

| Anglais | Français |
|---|---|
| Arena Tycoon | MAGNAT ARÈNE |
| Dome Ace | AS DU DÔME |
| Factory Head | CHEF USINE |
| Palace Maven | GUIDE PALAIS |
| Pike Queen | REINE PIKE |
| Pyramid King | ROI PYRAMIDE |
| Salon Maiden | HÔTESSE SALON |

## Termes non résolus

Ces termes ont été employés faute de mieux et demandent une décision avant
d'être figés. Ils apparaissent déjà dans des fichiers traduits.

| Anglais | Employé provisoirement | Problème |
|---|---|---|
| Frontier Brains | Cerveaux de la Zone | Terme collectif, non vérifié dans le dépôt |
| Scott | Scott | Laissé en anglais, aucun équivalent vérifiable |
| Steven | Steven | Laissé en anglais, aucun équivalent vérifiable |

## À décider avant traduction massive

- conventions précises de majuscules pour les catégories de Dresseurs ;
- abréviations des statistiques dans chaque écran ;
- noms français retenus pour les lieux propres à Heart & Soul ;
- tutoiement ou vouvoiement des dialogues ambigus ;
- stratégie pour les textes graphiques intégrés aux images.
