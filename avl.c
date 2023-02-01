#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)

pavl creer(int x){
    pavl c = malloc(sizeof(pavl));
    c->elt = x;
    c->gauche = NULL;
    c->droit = NULL;
    c->eq = 0;
}

pavl rotdroite(pavl a){
    pavl pivot;
    int ea,ep;
    pivot = a->gauche;
    a->gauche = pivot->droit;
    pivot->droit = a;
    ea = a->eq;
    ep = pivot->eq;
    a->eq = ea - min(ep,0) + 1;
    pivot->eq = max(max(ea+2,ep+ea+2),ep+1);
    a = pivot;
}

pavl rotgauche(pavl a){
    pavl pivot;
    int ea,ep;
    pivot = a->droit;
    a->droit = pivot->gauche;
    pivot->gauche = a;
    ea = a->eq;
    ep = pivot->eq;
    a->eq = ea - max(ep,0) - 1;
    pivot->eq = min(min(ea-2,ep+ea-2),ep-1);
    a = pivot;
}

pavl doubleg(pavl a){
    a->droit = rotdroite(a->droit);
    return rotgauche(a);
}

pavl doubled(pavl a){          
    a->gauche = rotgauche(a->gauche);
    return rotdroite(a);
}

pavl equilibrer(pavl a){
    if(a->eq >= 2){
        if(a->droit->eq >= 0)return rotgauche(a);
        else return doubleg(a);
    }
    else if(a->eq <= -2){
        if(a->gauche->eq <= 0)return rotdroite(a);
        else return doubled(a);
    }
}



pavl insertAVL(pavl a, int e, int* h){
    if(a==NULL){
        *h=1;
        return creer(e);
    }
    else if(e < a->elt){
        a->gauche = insertAVL(a->gauche,e,h);
        *h = -*h;
    }
    else if(e > a->elt)a->gauche = insertAVL(a->droit,e,h);
    else {
        *h=0;
        return a;
    }
    if(*h != 0){
        a->eq = a->eq + *h;
        a = equilibrer(a);
        if(a->eq == 0)*h = 0;
        else *h = 1;
    }
    return a;
}
