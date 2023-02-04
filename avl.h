

#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include "global_defs.h"

typedef struct AVL{
    int eq,height;
    Station st;
    struct AVL *right,*left;
}ArbreVL;

typedef ArbreVL *pavl;


int height(pavl N);
pavl insertt1AVL(pavl a, Station st);
pavl insertp1AVL(pavl a, Station st);
void infixeAVL(pavl a, FILE* fp);

#endif //AVL_H
