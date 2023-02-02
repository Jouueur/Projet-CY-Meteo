//
// Created by Marius on 14/12/22.
//

#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

struct sta{
    int codes;
    float avg, min, max;
};

typedef struct sta Station;

typedef struct AVL{
    int eq;
    Station elt;
    struct AVL *droit,*gauche;
}ArbreVL;

typedef ArbreVL *pavl;


pavl rotdroite(pavl a);
pavl rotgauche(pavl a);
pavl doubleg(pavl a);
pavl doubled(pavl a);
pavl equilibrer(pavl a);
void duplicateAVL(pavl a, Station val);
pavl insertAVL(pavl a, Station st, int* h);
void infixeAVL(pavl a, FILE* fp);

#endif //AVL_H
