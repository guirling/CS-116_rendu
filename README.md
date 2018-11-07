# CS-116_rendu

Projet Network.
Niko Guirlinger
Novembre 2018


A. Présentation du programme:

Le but de ce programme est de simuler un réseau de noeuds, liés entre eux par des liens.
Chaque noeud a un indice et une valeur. Les liens associent certains noeuds ensembles : 
ils sont bidirectionnels ( i.e. (a,b)=(b,a) ).
Les valeurs des noeuds sont choisies aléatoirement selon une distribution normale (N(0,1)).
Le nombre de liens crées pour chaque noeud respecte un loi de poisson (l’utilisateur peut choisir la moyenne).
Ainsi l’utilisateur entre le nombre de noeuds ainsi que le nombrede liens (moyenne de poisson)
par noeud voulu. En sortie (sur le terminal, flux standard de sortie), le programme renvoie la
valeur de chaque noeud pour chaque pas de temps. Cette valeur est calculée en fonction
des échanges fait entre les noeuds. S’il y a des erreurs dans les données entrées par l’utilisateur, 
le programme l’en averti via des messages d’erreur sur le terminal ou utilisera des valeurs par
défaut.



B. Compilation du programme:

Pour compiler/exécuter le programme général (NetSim), il est nécessaire de lancer les 
commandes suivantes depuis le répertoire build : 
« cmake .. » 
« make » 
« ./NetSim»

Lors de l’execution ./NetSim, plusieurs arguments sont facultatifs :
- Nombre de noeuds (-n)
- Nombre moyen (degré) de liens voulu par noeud  (-d)
- Une graine (seed) particulière (-S)
- Une pas de temps de simulation (-t)
