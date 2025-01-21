#include <stdio.h>


struct Noeud
{
	struct Noeud *gauche;
	struct Noeud *droite;
	int valeur;
};

struct Arbre
{
	struct Noeud racine;
};


/* TODO: Implement function creer_arbre and afficher arbre 
 *
 *
 *
 *
 */

struct Arbre creer_arbre();
void afficher_arbre(struct Arbre *arbre);
struct Noeud creer_noeud(int valeur);
void afficher_noeud(struct Noeud *noeud);
void insere_gauche(struct Noeud *base, struct Noeud *noeud_fils);
void insere_droite(struct Noeud *base, struct Noeud *noeud_fils);


int main(void)
{
	struct Arbre mon_arbre = creer_arbre();
	struct Noeud my_node = creer_noeud(2);
	struct Noeud my_child_node_right = creer_noeud(4);
	insere_droite(&my_node, &my_child_node_right);
	struct Noeud my_child_node_left = creer_noeud(5);
	insere_gauche(&my_node, &my_child_node_left);

	struct Noeud right2 = creer_noeud(6);
	insere_droite(&my_child_node_right, &right2);
	struct Noeud right3 = creer_noeud(8);
	insere_droite(&right2, &right3);
	struct Noeud right4 = creer_noeud(9);
	insere_droite(&right3, &right4);

	//afficher_noeud(&my_node);
	return 0;
}


struct Noeud creer_noeud(int valeur)
{
	struct Noeud noeud;
	noeud.gauche = NULL;
	noeud.droite = NULL;
	noeud.valeur = valeur;
	return noeud;
}

void afficher_noeud(struct Noeud *noeud)
{
	struct Noeud *current = noeud;

	if(current == NULL)
		printf("Noeud vide\n");
	else
	{
		printf("valeur du noeud courant: %d\n", current->valeur);
		afficher_noeud(current->gauche);
		afficher_noeud(current->droite);
	}
}

void insere_droite(struct Noeud *base, struct Noeud *noeud_fils)
{
	base->droite = noeud_fils;
}

void insere_gauche(struct Noeud *base, struct Noeud *noeud_fils)
{
	base->gauche = noeud_fils;
}

void afficher_arbre(struct Arbre *arbre)
{
	afficher_noeuds_suivants(arbre->racine);
}
struct Arbre creer_arbre()
{
	struct Arbre arbre;
	arbre.racine = creer_noeud(0);
	return arbre;
}
