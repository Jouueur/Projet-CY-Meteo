#include <stdio.h>
#include <stdlib.h>

typedef struct AVL{
    int elt,eq;
    struct AVL *gauche,*droit;
}AVL;

typedef AVL *pavl;