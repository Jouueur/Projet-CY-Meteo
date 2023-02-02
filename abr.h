//
// Created by Marius on 14/12/22.
//

#ifndef ABR_H
#define ABR_H

#include <stdio.h>
#include <stdlib.h>

struct Station{
    int codes;
    float avg, min, max;
};

typedef struct ABR{
    struct Station elt;
    struct ABR *droit;
    struct ABR *gauche;
} ArbreBR;

typedef ArbreBR* pabr;

pabr creerABR(struct Station a);
pabr insertABR(pabr a, struct Station e);
void duplicateABR(pabr a, struct Station val);
void infixeABR(pabr a, FILE* fp);

#endif //ABR_H
