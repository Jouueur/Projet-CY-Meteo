//
// Created by Marius on 14/12/22.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef AVL_H
#define AVL_H


struct Station{
    int codes;
    float avg, min, max;
};

typedef struct AVL{
    int eq;
    struct Station elt;
    struct AVL *droit,*gauche;

}ArbreVL;

typedef ArbreVL *pavl;


pavl rotdroite(pavl a);
pavl rotgauche(pavl a);
void doubleg(pavl a);
void doubled(pavl a);
pavl equilibrer(pavl a);
void duplicate(pavl a, struct Station val);
pavl insertAVL(pavl a, struct Station st, int* h);
void infixe(pavl a, FILE* fp);

#endif //AVL_H
