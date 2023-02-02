#include <stdio.h>
#include <stdlib.h>
#include "abr.h"

pabr creerarbre(Station *a){
    pabrc = malloc(sizeof(Arbre));
    if(c == NULL) exit(1);
    c->elt = a;


    c->droit = NULL;
    c->gauche = NULL;  

    return c;
} 

int recherche(pabr a, int e){
    
    if(a == NULL)return 0;
    else if(a->elt == e)return 1;
    else if(e < a->elt)recherche(a->gauche,e);
    else recherche(a->gauche,e);   
}


pabr insertABR(pabr a, int e){
    if(a == NULL){
        a=creerarbre(e);
    }
    else if(a->elt > e){
        a->gauche = insertABR(a->gauche,e);
    }
    else if(a->elt < e){
        a->droit = insertABR(a->droit,e);
    }
    return a;
}


