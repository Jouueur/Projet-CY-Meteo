//
// Created by Marius on 14/12/22.
//

#ifndef ABR_H
#define ABR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codes;
    float moy, min, max;
} Station;

typedef struct ABR{
    struct Station* elt;
    struct ABR *droit,*gauche;

} ArbreBR;

typedef ArbreBR* pabr;

pabr creerarbre(Station *a);
int recherche(pabr a, int e);
pabr insertABR(pabr a, int e);
void infixe(pabr a, int station);

#endif //ABR_H
