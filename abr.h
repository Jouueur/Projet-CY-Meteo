//
// Created by Marius on 14/12/22.
//

#ifndef ABR_H
#define ABR_H

#include <stdio.h>
#include <stdlib.h>
#include "global_defs.h"

typedef struct ABR{
    Station elt;
    struct ABR *right;
    struct ABR *left;
} ArbreBR;

typedef ArbreBR* pabr;

pabr creerABR(Station a);
pabr insertABR(pabr a, Station st);
pabr duplicateABR(pabr a, Station val);
void infixeABR(pabr a, FILE* fp);

#endif //ABR_H
