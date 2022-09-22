Achraf Ben Jilali 52877  
Rémy De Poorter 52063

# Rapport Du Projet Abalone

### Modélisation

#### Introduction ####
Notre projet consiste à implémenter le jeu Abalone grâce au concept MVC (Modèle-Vue-Contrôleur).
Pour les règles du jeu consulter : https://poesi.esi-bru.be/mod/resource/view.php?id=3839

Ce projet est divisé en 3 remises (une modélisation logicielle, une interface console et une interface graphique). Nous estimons le temps néccessaire pour ce travail à 10h pour l'analyse, 25h pour la partie console et 20h pour la partie graphique par personne. 

#### Les outils utilisés ####  
Le logiciel StarUML pour pouvoir créer notre vision logique du programme Abalone.  
Pour le développement de notre application en version console ainsi que la version graphique en C++17 nous avons choisi l'IDE Qt Creator et le compilateur Desktop Qt 5.13.1 MinGW 64-bit.  
Le logiciel GitLab pour gérer le versioning.  

#### Structure ####
Notre dossier est réparti en 2 répertoires :
Le dossier d'analyse comportant le diagramme de classe (MCD) sous format PDF(DEV4-Modélisation) + le fichier StarUML(Modelisation_Abalone.mdj).
Le dossier abalone, qui contiendra le programme à proprement parler.
Pour la première remise, le projet comprendra les fichiers headers de notre programme.

Class **Board** : Représente le plateau du jeu. Comme celui-ci est hexagonal nous avons choisit un tableau carré de 9x9 cases. Ces cases seront occupée par les balles des joueurs, vide, ou encore inacessibles. Ce système nous permet d'avoir facilement accès aux cases voisines.      
* `put(Position position, Status status)` : Permet de placer une balle(un status) sur le plateau.
* `remove(Position position)` : Retire une balle du plateau.
* `isMyOwn(Position position, PlayerColor color)` : Permet de savoir si la balle à une position reçue est bien à un joueur.  
* `bool isOutside(Position position)` : Permet de vérifier si le status d'une case est OUTSIDE.  
* `isInsidePos(Position position)` : Permet de savoir si une position(D28) est bien dans le plateau ou non.  
* `isInsideTab(int row, int column)` : Vérifie si une case fait bien partie du tableau 2D squares(ex : squares[10][10]).  
* `moveLateral(Position posStartLine, Position posEndLine, Position posEnd)` : Permet de faire une déplacement latéral de 2 ou 3 balles.  
* `void moveLine(Position posStartLine, Position posEnd)` : Permet de déplacer/pousser une balle dans une direction.  
* `char getLetterCoord(int i)` : Transforme une coordonnée ligne [ici][] en une lettre pour obtenir une coordonnée ABA-PRO(A->I).  
* `int getIntCoord(int j)` : Transforme une coordonnée colonne [][ici] en un chiffre pour obtenir une coordonnée ABA-PRO(1->9). 
* `int getRowCoord(char coordLetter)` : Transforme la lettre d'une coordonnée ABA-PRO en coordonné ligne [ici][] (0->8).  
* `int getColumnCoord(int coordInt)` : Transforme le chiffre d'une coordonnée ABA-PRO en coordonné colone [][ici] (0->8).  

Class **Game** : Elle est le coeur du programme, elle s’occupe de la dynamique du jeu, nous avons créé 2 méthodes différentes pour gérer le mouvement grâce a la notation ABA-PRO.
* `moveLateral(Position posStartLine, Position posEndLine, Position posEnd)` : Déplace en latéralement une ou une série de balles.  
* `moveLine(Position posStartLine, Position posEnd)` : Déplace en ligne une ou une série de balles.     
* `isOver()` : Vérife si une partie est finie ou non.  
* `removeBall()` : Permet de décrémenter le nombre de balle restante d'un joueur.  
* `initialize()` : Permet d'initialiser le plateau en plaçant les 28 balles(14 noires et blanches).  

Class **Player** : Il s'agit d'un joueur, celui-ci aura comme paramètre une couleur ainsi que son nombre de balle restante sur le plateau.  
* `decrementNbBall()` : Permettra de pouvoir décrémenter le nombre de balle du joueur de manière robuste. Si on utilisait un Setter il serait possible de modifier complètement son nombre.  

Class **Square** : Représente une case du plateau. Chaque case possède un statut. 

Class **Position** : Elle sera composée d'un char et d'un int, conformément à la notation ABA-PRO.  

Enumération **PlayerColor** : Représente la couleur d'un joueur du jeu.  

Enumération **Status** : Permet de savoir si une case est Libre, si une balle est présente ou encore si celle-ci est en hors du plateau de jeu.
