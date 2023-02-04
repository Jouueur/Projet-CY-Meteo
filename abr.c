
#include "abr.h"


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
    // verify duplicates station, stock min, max and calculate the average
    else if (a->elt.codes == st.codes){
        if (a->elt.min > st.avg && st.avg != 0.000000) a->elt.min = st.avg;
        if (a->elt.max < st.avg && st.avg != 0.000000) a->elt.max = st.avg;
        a->elt.avg = a->elt.avg * a->elt.total;
        a->elt.avg = a->elt.avg + st.avg;
        a->elt.total += 1;
        a->elt.avg = a->elt.avg / a->elt.total;
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
    // verify duplicates station, stock min, max and calculate the average
    else if (a->elt.codes == st.codes){
        if(a->elt.min > st.avg && st.avg != 0.000000) a->elt.min = st.avg;
        if(a->elt.max < st.avg && st.avg != 0.000000) a->elt.max = st.avg;

        if(a->elt.min > st.avg ) a->elt.min = st.avg;
        if(a->elt.max < st.avg ) a->elt.max = st.avg;
        a->elt.avg = a->elt.avg * a->elt.total;
        a->elt.avg = a->elt.avg + st.avg;
        a->elt.total += 1;
        a->elt.avg = a->elt.avg / a->elt.total;
    }

    else if(a->elt.codes > st.codes){
        a->left = insertt1ABR(a->left,st);
    }
    else if(a->elt.codes < st.codes){
        a->right = insertt1ABR(a->right,st);
    }
    return a;
}




void infixeABR(pabr a, FILE* fp, int* linenumber){
    if (a != NULL){
        infixeABR(a->left,fp,linenumber);
        fprintf(fp, "%d, %f, %f, %f, %d\n", a->elt.codes, a->elt.avg, a->elt.min, a->elt.max,(*linenumber)++);
        infixeABR(a->right,fp,linenumber);
    }

}

void freeABR(pabr root) {
    if (root == NULL) return;
    freeABR(root->left);
    freeABR(root->right);
    free(root);
}
