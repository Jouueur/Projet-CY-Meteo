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

Arbre *creerarbre(Station *a);
int recherche(parbre a, int e);
parbre insertABR(parbre a, int e);
void infixe(parbre a, int station);

#endif //ABR_H
