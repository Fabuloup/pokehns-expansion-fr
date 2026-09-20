# Notice IA — poursuivre la traduction française

Ce document sert à confier la traduction à un assistant, sans lui réexpliquer
le projet à chaque fois. Copier le bloc « Prompt de reprise » tel quel ; les
sections suivantes sont la référence que l'assistant consultera au besoin.

## Prompt de reprise

```text
Tu poursuis la traduction française de Pokémon Heart & Soul 2.0.6, dépôt
https://github.com/nhykola/HeartAndSoul-FR, branche de travail fr/main.

DÉMARRAGE
1. Place-toi sur fr/main, récupère le dernier état, vérifie que l'arbre est propre.
2. Vérifie que la dernière exécution de GitHub Actions est verte.
3. Lis translation/README.md, STYLE_GUIDE.md, GLOSSARY.md, SOURCES.md et SCRIPT_STATUS.md.
4. Regarde les derniers commits pour trouver le point de reprise.
5. Contrôle que src/data/pokemon/species_info/gen_2_families.h fait environ
   8 876 lignes et n'est pas tronqué.

MÉTHODE PAR LOT
Travaille par lots larges. Dans un lot, termine un fichier avant de passer au
suivant. Ne pousse pas, ne lance pas la CI et ne touche pas au suivi entre deux
fichiers : tout cela se fait une seule fois, à la fin du lot.

MÉTHODE PAR FICHIER
1. Lis le fichier entier et repère toutes les chaînes affichées.
2. Traduis tout le fichier.
3. Vérifie chaque nom propre dans les données du dépôt (voir la notice).
4. Vérifie les variables, les codes de contrôle et les largeurs.
5. Relis le diff.
6. Un commit, ne contenant que ce fichier : « FR: traduire <NomDuFichier> ».

QUALITÉ D'ÉCRITURE
Le texte doit se lire comme s'il avait été écrit en français. Jamais de mot à
mot. Respecte l'âge et le ton du personnage, l'humour, le tutoiement, le
contexte de la scène. N'ajoute aucune information absente de la source.
Rédige ton propre français : ne recopie pas le texte d'une localisation
publiée, sers-toi des références uniquement pour vérifier des noms et des
termes.

TERMINOLOGIE
Ne devine jamais un nom propre. Les noms d'espèces, de capacités et d'objets se
vérifient dans les fichiers de données du dépôt (recettes dans la notice). Un
terme introuvable est laissé en anglais et signalé dans le rapport de lot, pas
inventé. Consulte GLOSSARY.md avant d'introduire une traduction récurrente.

CONTRAINTES TECHNIQUES
- Préserve à l'identique {PLAYER}, {RIVAL}, {STR_VAR_1}, {STR_VAR_2}, {STRING}
  et toute accolade, ainsi que \n, \l, \p et $.
- Le nombre et l'ordre des variables doivent rester identiques à l'anglais.
- 34 caractères visibles maximum par segment entre deux codes \n, \l ou \p.
  Les codes ne comptent pas. Vise 30 à 32 sur les lignes à lettres larges.
  Tiens compte de la longueur variable des noms injectés par les variables.
- Le contrôle automatique de largeur ne vaut pas validation visuelle.
- Caractères disponibles : À Â Ç È É Ê Ë Î Ï Ô Œ Ù Û œ … Ü.
  Interdits : « » et l'apostrophe typographique. Utilise l'apostrophe droite.
- POKéMON s'écrit avec un é minuscule.
- Ne touche jamais aux labels, constantes, identifiants, flags, logique de
  script, structures de données, format de sauvegarde ni mécaniques de jeu.

FIN DE LOT, DANS CET ORDRE
1. git diff --check
2. python tools/translation/check_integrity.py
3. Contrôle de largeur sur tous les fichiers du lot.
4. Contrôle de dérive : mêmes variables, mêmes labels, mêmes terminateurs $
   qu'avant le lot.
5. Inspecte git diff --stat et --numstat. Une suppression massive ou un fichier
   réduit de moitié est un blocage : comprends-le avant de pousser.
6. Mets à jour SCRIPT_STATUS.md : toutes les lignes du lot d'un coup, puis le
   compteur. Vérifie que le compteur égale le nombre de lignes marquées.
7. Un commit de suivi distinct : « docs: actualiser le suivi du lot de traduction ».
8. Pousse tous les commits ensemble.
9. Attends une exécution complète de GitHub Actions et corrige tout échec.

Ne lance make hns que si la CI échoue, si un fichier contient des changements
de script hors chaînes, si un asset est ajouté, ou en préparation d'un jalon
de test.

ÉTATS DE SUIVI
à traduire — traduit, à valider en jeu — validé en jeu — sans chaîne locale à traduire —
bloqué (avec raison). Tant qu'aucun test sur émulateur n'a eu lieu, l'état
maximal est « traduit, à valider en jeu » : « validé en jeu » est interdit.
Les fichiers « sans chaîne locale à traduire » ne contiennent aucune définition de texte
locale. Ils peuvent appeler un texte ou une interface partagée : cela relève de l'audit
transversal. Ils sont exclus du décompte par carte : ne pas les traiter comme du travail
restant sans vérifier leurs appels externes.

SÉCURITÉ GIT
Travaille uniquement sur fr/main. Jamais de force-push, jamais de réécriture de
l'historique distant, ne touche pas à master, ne fusionne pas une version
upstream sans audit. N'ajoute jamais de ROM .gba, de ROM de base, de .sav ni de
save state, et ne publie aucun fichier provenant d'une ROM commerciale.

RAPPORT DE FIN DE LOT
Fichiers traduits, nombre de chaînes, décisions de terminologie, termes non
résolus, contrôles effectués, résultat de GitHub Actions, SHA des commits,
nouvelle progression globale, prochain fichier prévu.

Ne prétends jamais qu'une zone ou qu'une interface est entièrement traduite :
le fait que le projet compile ne prouve rien sur l'exhaustivité.
```

## Recettes de vérification terminologique

À utiliser systématiquement plutôt que de se fier à sa mémoire. Le nom anglais
s'écrit en majuscules dans la constante.

```bash
# Espèce : CRY_PIKACHU, CRY_TYROGUE...
awk 'index($0,".cryId = CRY_PIKACHU,")&&!d{print prev;d=1} {if($0~/speciesName/) prev=$0}' \
  src/data/pokemon/species_info/*.h

# Capacité
grep -n '\[MOVE_THUNDER\]' -A4 src/data/moves_info.h | grep -i name

# Objet
grep -n '\[ITEM_COIN_CASE\]' -A6 src/data/items.h | grep name

# Terme déjà employé ailleurs dans les scripts traduits
grep -rhn "MONT ARGENT" data/maps/*_hns/scripts.inc | head
```

La dernière recette est la plus importante : avant d'introduire une traduction,
regarder si le dépôt en emploie déjà une. La cohérence prime sur la préférence.

## Pièges connus

**Lance n'est pas Lance.** L'anglais `Lance`, le maître dragon, devient
**Peter**. L'anglais `Proton`, le sbire de la Team Rocket, devient **Lance**.
Le mot existe dans les deux langues sans désigner la même personne.

**`[skip ci]` annule la CI de tout le lot.** GitHub n'évalue que le commit de
tête d'un push. Si le commit de suivi le porte, aucun des commits de traduction
du lot n'est compilé. Le mettre uniquement sur un commit de documentation
poussé seul, après que la CI a déjà tourné sur le code.

**Un fichier sans variable peut passer entre les mailles.** Un contrôleur de
dérive qui compare les variables n'émet rien pour un fichier qui n'en contient
aucune : ni succès, ni échec. Compter les fichiers rapportés et vérifier à la
main ceux qui manquent à l'appel.

**Indentation mélangée.** Un même fichier peut mélanger tabulations et espaces,
parfois d'une ligne à l'autre au sein d'un même bloc. Toute édition par
correspondance exacte doit reproduire l'indentation réelle : la vérifier avec
`sed -n 'X,Yp' fichier | cat -A` avant d'éditer.

**Blocs identiques en double.** Plusieurs labels peuvent porter exactement le
même texte anglais. Un remplacement par correspondance exacte échouera ou, pire,
touchera le mauvais. Ajouter des lignes de contexte pour rendre chaque bloc unique.

**Mesurer le bon segment.** Une chaîne `.string` peut contenir un `\n` en
milieu de ligne. La largeur se mesure sur le plus long segment entre deux codes,
pas sur la chaîne entière, sinon le contrôle signale de fausses alertes.

**Les libellés de classes ne sont pas dans le fichier de dresseurs.** Dans
`src/data/trainers_hns.party`, `Class:` et `Pic:` sont des clés vers
`TRAINER_CLASS_*` et vers les assets : les traduire casse la compilation. Seul
`Name:` est du texte affiché. Les libellés de classes sont dans `gTrainerClasses`,
fichier `src/battle_main.c`. Leur champ réserve 13 octets, terminateur compris :
ils sont limités à 12 caractères affichés.

**Un même nom peut désigner deux personnages.** Avant un renommage de masse dans
les données de dresseurs, cibler par identifiant et non par valeur affichée :
`TRAINER_PROTON_*` porte légitimement `Name: LANCE`, alors que `TRAINER_LANCE_*`
doit porter `PETER`. Un remplacement global aurait renommé les deux.

## Chantiers ouverts

Ces points sont connus et non traités. Les garder en tête avant d'annoncer une
zone comme terminée.

- **Les libellés de classes attendent une vérification en jeu.** La plupart sont
  des choix du projet et non des relevés. `COLLECTEUR` est une forme raccourcie
  imposée par la limite de 12 caractères. Six titres de la Zone de Combat n'ont
  aucune source et sont les plus fragiles. Voir GLOSSARY.md, qui sépare les
  libellés ancrés des choix assumés.
- **Trois termes restent non résolus** : `Scott`, `Steven` et le terme collectif
  `Frontier Brains`. Ils sont recensés dans GLOSSARY.md.
- **Aucun fichier n'a été validé en jeu.** Le compteur « validé en jeu » est à 0
  et doit le rester tant qu'aucun test sur émulateur n'a eu lieu.
- **L'audit transversal reste à faire** : interfaces, menus, aides de touches,
  écrans de combat, textes globaux, scripts hérités de pokeemerald-expansion
  réellement utilisés, et textes intégrés aux images. Suivre des fichiers `_hns`
  n'en dispense pas.

## État attendu du dépôt

- `master` : miroir de l'upstream `PokemonHnS-Development/pokehns-expansion` ;
- `fr/main` : branche de traduction et branche par défaut ;
- aucune ROM ni sauvegarde dans Git ;
- une mise à jour qui ne modifie que des textes doit conserver la compatibilité
  des sauvegardes internes 2.x.
