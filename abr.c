#include <stdio.h>
#include <stdlib.h>
#include "abr.h"
#include "global_defs.h"

pabr creerABR(Station a){
    pabr c = malloc(sizeof(pabr));
    if(c == NULL) exit(1);
    c->elt = a;
    c->droit = NULL;
    c->gauche = NULL;  

    return c;
}


pabr insertABR(pabr a, Station st){
    if(a == NULL){
        a=creerABR(st);
    }
    else if(a->elt.codes > st.codes){
        a->gauche = insertABR(a->gauche,st);
    }
    else if(a->elt.codes < st.codes){
        a->droit = insertABR(a->droit,st);
    }
    return a;
}

void duplicateABR(pabr a, Station val){

    if (a == NULL){
        a = insertABR(a,val);
    }

    else if (a->elt.codes == val.codes){
        if(a->elt.min > val.min && val.min != 0.000000) a->elt.min = val.min;
        if(a->elt.max < val.max && val.max != 0.000000) a->elt.max = val.max;

        if(a->elt.min > val.avg ) a->elt.min = val.avg;
        if(a->elt.max < val.avg ) a->elt.max = val.avg;

        // moyenne challah

    }


    else if (a->elt.codes > val.codes)
        duplicateABR (a->gauche,val);
    else if (a->elt.codes < val.codes)
        duplicateABR (a->droit,val);
}



void infixeABR(pabr a, FILE* fp){
    if (a == NULL){
        infixeABR(a->gauche,fp);
        fprintf(fp, "%d, %f, %f, %f\n", a->elt.codes, a->elt.avg, a->elt.min, a->elt.max);
        infixeABR(a->droit,fp);
    }

}


