#include <stdio.h>
#include <stdlib.h>
#include "abr.h"
#include "global_defs.h"

pabr creerABR(Station a){
    pabr c = malloc(sizeof(pabr)*6);
    if(c == NULL) exit(1);
    c->elt = a;
    c->right = NULL;
    c->left = NULL;

    return c;
}


pabr insertp1ABR(pabr a, Station st){
    if(a == NULL){
        a=creerABR(st);
    }

    else if (a->elt.codes == st.codes){
        
    }

    else if(a->elt.codes > st.codes){
        a->left = insertp1ABR(a->left,st);
    }
    else if(a->elt.codes < st.codes){
        a->right = insertp1ABR(a->right,st);
    }
    return a;
}

pabr insertt1ABR(pabr a, Station st){
    if(a == NULL){
        a=creerABR(st);
    }

    else if (a->elt.codes == st.codes){
        if(a->elt.min > st.min && st.min != 0.000000) a->elt.min = st.min;
        if(a->elt.max < st.max && st.max != 0.000000) a->elt.max = st.max;

        if(a->elt.min > st.avg ) a->elt.min = st.avg;
        if(a->elt.max < st.avg ) a->elt.max = st.avg;
    }

    else if(a->elt.codes > st.codes){
        a->left = insertt1ABR(a->left,st);
    }
    else if(a->elt.codes < st.codes){
        a->right = insertt1ABR(a->right,st);
    }
    return a;
}




void infixeABR(pabr a, FILE* fp){
    if (a != NULL){
        infixeABR(a->left,fp);
        fprintf(fp, "%d, %f, %f, %f\n", a->elt.codes, a->elt.avg, a->elt.min, a->elt.max);
        infixeABR(a->right,fp);
    }

}

void freeABR(pabr root) {
    if (root == NULL) return;
    freeABR(root->left);
    freeABR(root->right);
    free(root);
}
