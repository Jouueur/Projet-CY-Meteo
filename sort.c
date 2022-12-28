#include <stdio.h>
#include <stdlib.h>


// Sort by AVL

typedef struct AVL{
    int elt,eq;
    struct AVL *gauche,*droit;
}AVL;

typedef AVL *pavl;

pavl creer(int x){
    pavl c = malloc(sizeof(pavl));
    c->elt = x;
    c->gauche = NULL;
    c->droit = NULL;
    c->eq = 0;
}


int max(int a, int b){
    if(a>b)return a;
    else return b;
}

int min(int a, int b){
    if(a<b)return a;
    else return b;
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
    pivot->eq = min(min(ea-2,ep-ea-2),ep-1);
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
    else if(e < a->elt)a->gauche = insertAVL(a->droit,e,h);
    else {
        *h=0;
        return a;
    }
    if(*h != 0){
        a->eq = a->elt + *h;
        a = equilibrer(a);
        if(a->elt == 0)*h = 0;
        else *h = 1;
    }
    return a;
}

// Sort by ABR

typedef struct Arbre{
    int elt;
    struct Arbre* droit,*gauche;
    
}Arbre;

typedef Arbre* parbre;


Arbre *creerarbre(int a){
    Arbre *c = malloc(sizeof(Arbre));
    if(c == NULL)exit(1);
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