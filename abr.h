//
// Created by Marius on 14/12/22.
//

#ifndef ABR_H
#define ABR_H

#include <stdio.h>
#include <stdlib.h>

struct Station{
    int codes;
    float moy, min, max;
} ;

typedef struct ABR{
    struct Station elt;
    struct ABR *droit,*gauche;

} ArbreBR;

typedef ArbreBR* pabr;

pabr creerABR(Station *a);
pabr insertABR(pabr a, int e);
void infixe(pabr a, FILE* fp);

#endif //ABR_H
