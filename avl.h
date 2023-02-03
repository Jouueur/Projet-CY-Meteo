

#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include "global_defs.h"

typedef struct AVL{
    int eq;
    Station elt;
    struct AVL *right,*left;
}ArbreVL;

typedef ArbreVL *pavl;


pavl rotdroite(pavl a);
pavl rotgauche(pavl a);
pavl doubleg(pavl a);
pavl doubled(pavl a);
pavl equilibrer(pavl a);
pavl insertAVL(pavl a, Station st, int* h);
void infixeAVL(pavl a, FILE* fp);

#endif //AVL_H
