#include <stdio.h>
#include <stdlib.h>
#include "abr.h"

Arbre *creerarbre(Station *a){
    Arbre *c = malloc(sizeof(Arbre));
    if(c == NULL) exit(1);
    c->elt = a;


    c->droit = NULL;
    c->gauche = NULL;  

    return c;
} 

int recherche(parbre a, int e){
    
    if(a == NULL)return 0;
    else if(a->elt == e)return 1;
    else if(e < a->elt)recherche(a->gauche,e);
    else recherche(a->gauche,e);   
}


parbre insertABR(parbre a, int e){
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


int verif(){

}

void infixe(parbre a, int station){
    infixe(a->gauche);
    
    infixe(a->droit);
}
