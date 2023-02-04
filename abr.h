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
pabr insertp1ABR(pabr a, Station st);
pabr insertt1ABR(pabr a, Station st);
void infixeABR(pabr a, FILE* fp, int *linenumber);

#endif //ABR_H

