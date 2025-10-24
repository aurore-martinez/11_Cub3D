/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:30:16 by aumartin          #+#    #+#             */
/*   Updated: 2025/10/24 15:30:21 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Comprendre la base d’un rayon

🎯 Objectif
Tirer un seul dans une petite carte et observer ce qu’il traverse.

1. La carte
Imagine une grille 5×5 où chaque cellule vaut :

1 → un mur

0 → du vide

P → la position du joueur

y↑
4 | 1 1 1 1 1
3 | 1 0 0 0 1
2 | 1 0 P 0 1
1 | 1 0 0 0 1
0 | 1 1 1 1 1     → x→
    0 1 2 3 4

Chaque case mesure 1 unité.
Donc si ton joueur est au centre de la case (2,2), ses coordonnées réelles sont :

(x, y) = (2.5, 2.5)

2. Le rayon

Le joueur regarde vers la droite, donc vers l’axe +X.

Angle θ = 0°

Direction du rayon :
dirX = cos(θ) = 1
dirY = sin(θ) = 0
⇒ Le rayon va tout droit vers la droite.

3. On avance petit à petit

On va faire des “petits pas” de 0.1 unité.

Formule de position du rayon :
x = posX + dirX * t
y = posY + dirY * t
→ Ici posX = 2.5, posY = 2.5, et dir = (1, 0)
donc ça donne :
x = 2.5 + t, y = 2.5

t	(x, y)	Cellule (floor(x), floor(y))	Contenu	commentaire
0	(2.5, 2.5)	(2, 2)	P	point de départ
0.1	(2.6, 2.5)	(2, 2)	P	encore dans la même case
0.5	(3.0, 2.5)	(3, 2)	0	vide → continue
1.4	(3.9, 2.5)	(3, 2)	0	toujours rien
1.5	(4.0, 2.5)	(4, 2)	1	💥 mur touché !
➡️ Le rayon a parcouru environ 1.5 unités avant de heurter un mur.

4. Distance du joueur au mur

Distance brute (comme on est horizontal) :
d = 4.0 - 2.5 = 1.5
Pas besoin de trigonométrie ici, c’est direct.

5. Visualisation mentale
         (y)
4 | █████████████████
3 | █···············█
2 | █···P———💥█
1 | █···············█
0 | █████████████████
    0  1  2  3  4   (x)

	——— : le rayon.
💥 : point d’impact avec le mur.

✅ Résultat

Le premier mur sur la droite est à une distance de 1.5 unités.

✏️ Petit défi

Refais la même logique mais :

Avec θ = 90° (vers le haut)

Puis θ = 45° (diagonale)

Tu verras que :

à 90°, le mur est aussi à 1.5 unité, mais en Y ;

à 45°, tu devras avancer un peu plus avant de toucher le mur, car la diagonale
est plus longue (≈ 1.5 × √2 ≈ 2.12).
 */

#include "../include/cub3d.h"

int main(int ac, char **av)
{
	/* --- Carte 5x5 --- */
	/* 1 = mur, 0 = vide, P ≈ (2.5, 2.5) */
	int map[5][5] =
	{
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1}
	};
	int W = 5, H = 5;

	/* --- Position joueur au centre de la case (2,2) --- */
	double px = 2.5;
	double py = 2.5;

	/* --- Angle en degrés (par défaut 0 = droite) --- */
	double deg = 0.0;
	if (ac > 1)
		deg = atof(av[1]);

	/* --- Direction du rayon --- */
	double rad = deg * M_PI / 180.0;
	double dirx = cos(rad);
	double diry = sin(rad);

	/* --- Pas d'avancement et limites --- */
	double t = 0.0;         /* distance parcourue le long du rayon */
	double step = 0.1;      /* “petits pas” */
	double hit_dist = -1.0; /* distance au premier mur */
	int    hit = 0;

	/* --- Pour éviter d'imprimer 1000 lignes: mémoriser la cellule courante --- */
	int last_ix = -1, last_iy = -1;

	/* --- Boucle d'avancement --- */
	while (!hit && t < 100.0) /* 100.0 = garde-fou */
	{
		double x = px + dirx * t;
		double y = py + diry * t;

		int ix = (int)floor(x);
		int iy = (int)floor(y);

		/* En dehors de la carte -> on s'arrête */
		if (ix < 0 || iy < 0 || ix >= W || iy >= H)
			break;

		/* Affiche quand on change de cellule (lecture "humaine") */
		if (ix != last_ix || iy != last_iy)
		{
			printf("t=%.2f  pos=(%.2f,%.2f)  cell=(%d,%d)  map=%d\n",
				t, x, y, ix, iy, map[iy][ix]);
			last_ix = ix; last_iy = iy;
		}

		/* Mur touché ? */
		if (map[iy][ix] == 1)
		{
			hit = 1;
			hit_dist = t;
			break ;
		}

		t += step;
	}

	if (hit)
		printf("\n💥 Mur touché à distance ≈ %.2f (angle %.1f°)\n", hit_dist, deg);
	else
		printf("\nAucun mur touché (angle %.1f°)\n", deg);

	return (0);
}
