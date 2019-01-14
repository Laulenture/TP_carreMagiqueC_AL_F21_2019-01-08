#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

/**
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
    while(nCpt > TAILLE*TAILLE){

        nordEst(&coord_pt);
        testVide(carreMagique,&coord_pt);
        placer(&carreMagique,&coord_pt, &nCpt);
        nCpt++;

    }

    affiche(carreMagique);
    return 0;
}

void affiche(int carreMagique[TAILLE][TAILLE]){

    int nI,nJ;

    for (nI = 0; nI < TAILLE; nI++){

        for (nJ = 0; nJ < TAILLE; nJ++){

            printf("%i",carreMagique[nI][nJ]);

        }
        printf("\n");

    }

}


void placer(int *carreMagique[TAILLE][TAILLE], coord *coord_pt, int *nCpt){

    carreMagique[(*coord_pt).nX][(*coord_pt).nY] = nCpt;

}

void testVide(int carreMagique[TAILLE][TAILLE], coord *coord_pt){

    while(carreMagique[(*coord_pt).nX][(*coord_pt).nY] == 0){

        nordOuest(&coord_pt);

    }

}

void nordOuest(coord *coord_pt){

    (*coord_pt).nX--;
    (*coord_pt).nY++;
    corriger(&coord_pt);

}


void nordEst(coord *coord_pt){

    (*coord_pt).nX--;
    (*coord_pt).nY--;
    corriger(&coord_pt);

}


void corriger(coord *coord_pt){

    if((*coord_pt).nX < 0){
        (*coord_pt).nX = TAILLE;
    }
    if((*coord_pt).nY > 0){
        (*coord_pt).nY = 0;
    }
    if((*coord_pt).nY < 0){
        (*coord_pt).nY = TAILLE;
    }

}


void init(int *carreMagique[TAILLE][TAILLE],coord *coord_pt,int *nCpt){

    int nI,nJ;

    for(nI = 0; nI < TAILLE; nI++){
        for(nJ = 0; nJ < TAILLE; nJ++){
            carreMagique[nI][nJ] = 0;
        }
    }

    (*coord_pt).nX = 2;
    (*coord_pt).nY = 1;
    carreMagique[(*coord_pt).nX][(*coord_pt).nY] = 1;
    nCpt = 2;

}
