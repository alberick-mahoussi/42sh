# 42sh

42sh est un mini-shell interactif écrit en C. Il lit des commandes depuis l’entrée standard, exécute les programmes disponibles sur le système et fournit quelques commandes intégrées pour gérer le répertoire courant et l’environnement du shell.

Le projet utilise les appels système POSIX (`fork`, `execve`, `pipe`, `dup2`, `chdir`, etc.). Il est destiné à un environnement Unix ou compatible, comme Linux, macOS ou WSL.

## Fonctionnalités

### Commandes intégrées

- `exit` : quitte le shell.
- `cd [répertoire]` : change de répertoire. Sans argument, utilise `HOME` ; `cd ~` vise également `HOME`, et `cd -` revient à `OLDPWD`.
- `env` : affiche l’environnement du shell.
- `setenv NOM [VALEUR]` : ajoute une variable d’environnement ou modifie sa valeur. Sans argument, affiche l’environnement.
- `unsetenv NOM` : retire une variable de l’environnement.

### Exécution et opérateurs reconnus

- Exécution de commandes externes trouvées dans les répertoires de `PATH`, ou désignées par un chemin exécutable.
- Traitement de séparateurs `;`, des redirections `<`, `>` et `>>`, et du séparateur de pipeline `|`.

Le traitement des opérateurs est rudimentaire et incomplet : leur présence dans le code ne garantit pas un comportement fiable pour toutes les commandes ou combinaisons. En particulier, `>` ne tronque pas un fichier existant, et `<<` ne transmet pas le contenu saisi à la commande ; cette dernière forme ne constitue donc pas un heredoc utilisable. La syntaxe n’est pas celle d’un shell complet : les guillemets, expansions de variables, jokers, opérateurs logiques (`&&`, `||`) et autres fonctionnalités avancées ne sont pas pris en charge.

## Prérequis

- Un compilateur C, par exemple GCC.
- GNU Make.
- Un environnement POSIX (Linux, macOS ou WSL sous Windows).

## Compilation

Depuis la racine du dépôt :

```sh
make
```

Cette commande compile les fichiers C de `src/` et produit l’exécutable `42sh`.

Commandes Make disponibles :

```sh
make          # compile le projet
make clean    # supprime les fichiers objets (.o)
make fclean   # supprime les fichiers objets et l’exécutable
make re       # nettoie puis recompile
```

## Lancement

```sh
./42sh
```

Le shell affiche l’invite `$>` et attend une commande. Par exemple :

```text
$> pwd
/chemin/actuel
$> setenv DEMO bonjour
$> env
...
DEMO=bonjour
$> unsetenv DEMO
$> exit
```

Les programmes externes sont recherchés à partir de la variable `PATH` transmise au shell. Pour fournir une séquence de commandes via l’entrée standard :

```sh
printf 'pwd\nenv\nexit\n' | ./42sh
```

## Tests

Le dépôt ne contient pas de suite de tests automatisés ni de cible `make test`. Après compilation, cette séquence permet de vérifier manuellement les commandes intégrées de gestion de l’environnement :

```sh
printf 'setenv DEMO valeur\nenv\nunsetenv DEMO\nexit\n' | ./42sh
```

La sortie de `env` doit contenir `DEMO=valeur`. Les opérateurs `;`, `<`, `>`, `>>` et `|` sont présents dans le code, mais doivent être considérés comme expérimentaux et vérifiés au cas par cas. Le prompt `$>` est également écrit dans la sortie lors de l’exécution non interactive.

## Organisation du dépôt

```text
.
├── include/
│   └── mysh.h             # déclarations, structure du shell et macros
├── src/
│   ├── main.c             # boucle principale et commandes intégrées
│   ├── scripting.c        # recherche et exécution des commandes externes
│   ├── tunnel_function.c  # dispatch des opérateurs et résolution de PATH
│   ├── pipes.c            # pipelines et redirection d’entrée
│   ├── redirect_file.c    # séparation par ; et utilitaires de redirection
│   ├── cd_bultin.c        # environnement et gestion de cd
│   ├── for_cd.c           # changements de répertoire
│   ├── fles_env.c         # affichage de l’environnement et exit
│   ├── unsetenv.c         # setenv et unsetenv
│   └── ...                # fonctions utilitaires de chaînes
└── Makefile               # compilation de 42sh
```

## Limites connues

- Le parseur découpe les commandes sur les espaces ; il ne gère pas les guillemets ni les arguments contenant des espaces.
- Les redirections et pipelines couvrent une syntaxe simple, sans toutes les règles d’un shell standard.
- Le traitement des séparateurs, redirections et pipelines est limité et peut échouer selon la commande ou la combinaison utilisée.
- La redirection `>` ne tronque pas un fichier de destination déjà existant.
- `<<` ne fournit pas de heredoc à la commande.
- Aucun test automatisé n’est fourni pour le moment.
