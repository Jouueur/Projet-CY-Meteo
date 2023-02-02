#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


pavl creer(struct Station x){
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



pavl insertAVL(pavl a, struct Station st, int* h){
    if(a==NULL){
        *h=1;
        return creer(st);
    }
    else if(st.codes < a->elt.codes){
        a->gauche = insertAVL(a->gauche,st,h);
        *h = -*h;
    }
    else if(st.codes > a->elt.codes)a->gauche = insertAVL(a->droit,st,h);
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

void duplicate(pavl a, struct Station val){
    
    if (a == NULL){
        insertAVL(a,val,0);
    }
        
    else if (a->elt.codes == val.codes){
        if(a->elt.min > val.min && val.min != 0.000000) a->elt.min = val.min;
        if(a->elt.max < val.max && val.max != 0.000000) a->elt.max = val.max;

        if(a->elt.min > val.avg ) a->elt.min = val.avg;
        if(a->elt.max < val.avg ) a->elt.max = val.avg;
        
        // moyenne challah
       
    } 

        
    else if (a->elt.codes > val.codes)
        duplicate (a->gauche,val);
    else if (a->elt.codes < val.codes)
        duplicate (a->droit,val);
}


void infixe(pavl a, FILE* fp){
  infixe(a->gauche,fp);
  fprintf(fp, "%d, %f, %f, %f\n", a->elt.codes, a->elt.avg, a->elt.min, a->elt.max);
  infixe(a->droit,fp);
}


