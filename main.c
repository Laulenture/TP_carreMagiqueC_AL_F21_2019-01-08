#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

/*
    i : int             :nVar
    f : float           :flVar
    d : double          :dblVar
    c : char            :cVar
    l : long int        :lnVar
    ll: long long int   :llnVar
    L : double long     :ldblVar
    h : short int       :srVar
    ui: unsigned int    :unVar
    uf: unsigned float  :unfVar
    s : *STRING*
    * : *POINTEUR*      :pVar
*/

#define TAILLE 5

typedef struct coord{
        int nX;
        int nY;
}coord;

void affiche(int carreMagique[TAILLE][TAILLE]);
void placer(int *carreMagique[TAILLE][TAILLE], coord *coord_pt, int *nCpt);
void testVide(int carreMagique[TAILLE][TAILLE], coord *coord_pt);
void nordOuest(coord *coord_pt);
void nordEst(coord *coord_pt);
void corriger(coord *coord_pt);
void init(int *carreMagique[TAILLE][TAILLE],coord *coord_pt,int *nCpt);

int main()
{
    int carreMagique[TAILLE][TAILLE];
    int nX,nY,nCpt;
    char sTexte[512] = "";
    coord coord_pt;

    CharToOemA("Programme Carré Magique",sTexte);
    printf("%s\n",sTexte);

    init(*carreMagique,&coord_pt,&nCpt);
    for(nCpt = 0,nCpt < TAILLE*TAILLE,nCpt++){

        nordEst(&coord_pt);
        testVide(carreMagique,&coord_pt);
        if (carreMagique[(coord_pt).nX][(coord_pt).nY] != 0){
            nordOuest(&coord_pt);
        }
        placer(&carreMagique,&coord_pt, &nCpt);

    }

    affiche(carreMagique);
    system("pause");
    return 0;
}

/**
  * BUT : En fin de programme, afiche le tableau renseigné.
  * ENTREE : le tableau
  * SORTIE : tableau affiché
  */
void affiche(int carreMagique[TAILLE][TAILLE]){

    int nI,nJ;

    for (nI = 0; nI < TAILLE; nI++){

        for (nJ = 0; nJ < TAILLE; nJ++){

            printf("%i",carreMagique[nI][nJ]);

            if(carreMagique[nI][nJ]>9){
                printf(" ");
            }else{
                printf("  ");
            }
        }
        printf("\n");

    }

}

/**
  * BUT : Renseigne la case une foie les coordonnées selectionnées
  * ENTREE : la tableau et les coordonnées
  * SORTIE : la case remplie
  */
void placer(int *carreMagique[TAILLE][TAILLE], coord *coord_pt, int *nCpt){

    carreMagique[(*coord_pt).nX][(*coord_pt).nY] = *nCpt;

}

/**
  * BUT : Vérifie que la case présente est vide, sinon la procédure nordOuest est éxetutée pour changer les coordonnées sur une case vide
  * ENTREE : le tableau et les coordonnées
  * SORTIE : -
  */
void testVide(int carreMagique[TAILLE][TAILLE], coord *coord_pt){

    if(carreMagique[(*coord_pt).nX][(*coord_pt).nY] != 0){

        ///Pour une raison qui m'échappe appeller la procédure nordOuest ici la rend incappable d'acceder correctement à coord_pt
        ///Note: j'ai évaluer et testé une solution à base de poiter de poiter mais je n'ai pus l'implémenter et j'ai du enlever les ** pour faire fonctionner à nouveau la fonction
        //nordOuest(&coord_pt);

    }

}

/**
  * BUT : Déplace les coordonnées sur la case en haut à gauche de la case présente si elle à déjà été renseignée
  * ENTREE : les coordonnées
  * SORTIE : les coordonnées misent à jour
  */
void nordOuest(coord *coord_pt){

    (*coord_pt).nX=(*coord_pt).nX-1;
	(*coord_pt).nY=(*coord_pt).nY-1;
    corriger(&(*coord_pt));

}

/**
  * BUT : Déplace les coordonnées sur la case en haut à droite de la case présente
  * ENTREE : les coordonnées
  * SORTIE : les coordonnées misent à jour
  */
void nordEst(coord *coord_pt){

    (*coord_pt).nX=(*coord_pt).nX-1;
	(*coord_pt).nY=(*coord_pt).nY+1;
    corriger(&(*coord_pt));

}

/**
  * BUT : S'assure que les coordonnées ne sortent pas du tableau
  * ENTREE : les coordonnées
  * SORTIE : -
  */
void corriger(coord *coord_pt){

    if((*coord_pt).nX < 0){
        (*coord_pt).nX = TAILLE - 1;
	}

	if((*coord_pt).nX >= TAILLE){
        (*coord_pt).nX = 0;
	}

    if((*coord_pt).nY < 0){
        (*coord_pt).nY = TAILLE - 1;
	}

    if((*coord_pt).nY >= TAILLE){
        (*coord_pt).nY = 0;
	}

}

/**
  * BUT : Initialise le tableau, les coordonnées et le compteur
  * ENTREE : le tableau, les coordonnées et le compteur
  * SORTIE : le tableau, les coordonnées et le compteur initialisé
  */
void init(int *carreMagique[TAILLE][TAILLE],coord *coord_pt,int *nCpt){

    int nI,nJ;

    for(nI = 0; nI < TAILLE; nI++){
        for(nJ = 0; nJ < TAILLE; nJ++){
            carreMagique[nI][nJ] = 0;
        }
    }

    (*coord_pt).nX = 1;
    (*coord_pt).nY = 2;
    carreMagique[(*coord_pt).nX][(*coord_pt).nY] = 1;
    *nCpt = 2;

}
