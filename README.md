🧊 Cub3D — Mon premier RayCaster avec la MiniLibX

« Et maintenant, c’est votre tour de revivre l’Histoire... »

🎮 Introduction

Cub3D est un projet d’exploration de la 3D simulée à travers une approche mathématique appelée raycasting.
Inspiré du légendaire Wolfenstein 3D (1992), ce projet te plonge dans la genèse des moteurs 3D :
tu y découvriras comment créer une vue subjective dans un labyrinthe, à l’aide de calculs trigonométriques simples, et de la MiniLibX pour afficher le rendu graphique.

🧠 Le saviez-vous ?
🎯 1. Le faux 3D de Wolfenstein

Wolfenstein 3D n’était pas en 3D réelle, mais utilisait un procédé malin :
le raycasting. Chaque rayon projeté depuis la caméra s’arrête au premier mur rencontré,
et sa distance détermine la hauteur du mur affiché à l’écran.
Résultat : un effet 3D fluide, rapide et ultra-léger, rendu sur des PC des années 90 !

💾 2. John Carmack, le magicien du code

Le jeune John Carmack a inventé des techniques d’optimisation révolutionnaires pour Wolfenstein.
Grâce à lui, un ordinateur doté de moins de 2 Mo de RAM pouvait afficher un labyrinthe complet en pseudo-3D.
Il deviendra plus tard l’architecte des moteurs de Doom et Quake, et une légende du code.

🕹️ 3. Un FPS mythique, ancêtre des jeux modernes

Wolfenstein 3D est considéré comme le premier FPS (First Person Shooter) de l’histoire.
Il a ouvert la voie à Doom, Duke Nukem 3D et Quake — des pierres angulaires de la culture jeu vidéo.

🔍 Objectif du projet

Créer une vue en 3D subjective d’un environnement 2D, à l’aide de la MiniLibX et de la technique du raycasting.

Le joueur se déplace dans un labyrinthe :

Les flèches gauche/droite font tourner la caméra.

Les touches W, A, S, D permettent d’avancer/reculer ou se déplacer latéralement.

Les murs affichent des textures différentes selon leur orientation (N, S, E, O).

Le sol et le plafond ont des couleurs distinctes.

La fenêtre doit se fermer proprement avec ESC ou la croix rouge.

⚙️ Entrées & Parsing (.cub)

Le programme reçoit un seul argument :
./cub3D maps/example.cub

Le fichier .cub contient :
   - Les chemins vers les textures :
	NO ./textures/north.xpm
	SO ./textures/south.xpm
	WE ./textures/west.xpm
	EA ./textures/east.xpm
   - Les couleurs du sol et du plafond :
	F 220,100,0
	C 225,30,0
   - La carte (labyrinthe) :
	111111
	100101
	1100N1
	111111
		→ N, S, E, W marquent la position et l’orientation de départ.
		→ La carte doit être fermée par des murs.


🧩 Pour aller plus loin

👉 Le moteur de Wolfenstein 3D a ouvert la voie à des moteurs modernes comme Unreal et Unity.
👉 Le raycasting est encore utilisé aujourd’hui pour des jeux rétro, des moteurs 2D simplifiés ou des effets de lumière.

Pour tester l’original : Wolf3D Online
