#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


pavl creer(Station x){
    pavl c = malloc(sizeof(pavl));
    c->elt.codes = x.codes;
    c->elt.avg = x.avg;
    c->elt.min = x.min;
    c->elt.max = x.max;
    c->gauche = NULL;
    c->droit = NULL;
    c->eq = 0;
    return c;
}


int max(int a, int b){
    if(a>b)return a;
    else return b;
}

int min(int a, int b){
    if(a<b)return a;
    else return b;
}

pavl rotdroite(pavl A){
    pavl B; int a,b;
    B = A->gauche;
    a = A->eq; b = B->eq;
    A->gauche = B->droit; B->droit = A; /* rotation */
    A->eq = a-min(b,0)+1;
    B->eq = max(max(a+2,a+b+2),b+1);
    return B;
}

pavl rotgauche(pavl A){
    pavl B; int a,b;
    B = A->droit;
    a = A->eq; b = B->eq;
    A->droit = B->gauche; B->gauche = A; /* rotation */
    A->eq = a-max(b,0)-1;
    B->eq = min(min(a-2,a+b-2),b-1);
    return B;
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
        if(a->droit->eq >= 0) return rotgauche(a);
        else return doubleg(a);
    }
    else if(a->eq <= -2){
        if(a->gauche->eq <= 0) return rotdroite(a);
        else return doubled(a);
    }
    return NULL;
}



pavl insertAVL(pavl a, Station st, int* h){
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

void duplicateAVL(pavl a, Station val){
    
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
        duplicateAVL (a->gauche,val);
    else if (a->elt.codes < val.codes)
        duplicateAVL (a->droit,val);
}


void infixeAVL(pavl a, FILE* fp){
    if (a == NULL){
        infixeAVL(a->gauche,fp);
        fprintf(fp, "%d, %f, %f, %f\n", a->elt.codes, a->elt.avg, a->elt.min, a->elt.max);
        infixeAVL(a->droit,fp);
    }

}


