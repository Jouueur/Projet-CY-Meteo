//
// Created by Marius on 14/12/22.
//

#ifndef ABR_H
#define ABR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codes;
    float moy, min, max;
}Station;

typedef struct Arbre{
    struct Station* elt;
    struct Arbre *droit,*gauche;

}Arbre;

typedef Arbre* parbre;

#endif //ABR_H
