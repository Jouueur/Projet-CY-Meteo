//
// Created by Marius on 14/12/22.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef AVL_H
#define AVL_H


typedef struct AVL{
    int elt,eq;
    struct AVL *gauche,*droit;
}AVL;

typedef AVL *pavl;

pavl rotdroite(pavl a);
pavl rotgauche(pavl a);
pavl doubleg(pavl a);
pavl doubled(pavl a);
pavl equilibrer(pavl a);
pavl insertAVL(pavl a, int e, int* h);

#endif //AVL_H
