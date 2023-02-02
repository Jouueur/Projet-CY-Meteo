#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


pavl creer(Station x){
    pavl c = malloc(sizeof(pavl)*6);
    c->elt.codes = x.codes;
    c->elt.avg = x.avg;
    c->elt.min = x.min;
    c->elt.max = x.max;
    c->left = NULL;
    c->right = NULL;
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

pavl rotrighte(pavl A){
    pavl B; int a,b;
    B = A->left;
    a = A->eq; b = B->eq;
    A->left = B->right; B->right = A; /* rotation */
    A->eq = a-min(b,0)+1;
    B->eq = max(max(a+2,a+b+2),b+1);
    return B;
}

pavl rotleft(pavl A){
    pavl B; int a,b;
    B = A->right;
    a = A->eq; b = B->eq;
    A->right = B->left; B->left = A; /* rotation */
    A->eq = a-max(b,0)-1;
    B->eq = min(min(a-2,a+b-2),b-1);
    return B;
}

pavl doubleg(pavl a){
    a->right = rotrighte(a->right);
    return rotleft(a);
}

pavl doubled(pavl a){
    a->left = rotleft(a->left);
    return rotrighte(a);
}

pavl equilibrer(pavl a){
    if(a->eq >= 2){
        if(a->right->eq >= 0) return rotleft(a);
        else return doubleg(a);
    }
    else if(a->eq <= -2){
        if(a->left->eq <= 0) return rotrighte(a);
        else return doubled(a);
    }
    return NULL;
}



pavl insertAVL(pavl a, Station st, int* h){
    if(a==NULL){
        *h=1;
        return creer(st);
    } else if (a->elt.codes == st.codes){
        if(a->elt.min > st.min && st.min != 0.000000) a->elt.min = st.min;
        if(a->elt.max < st.max && st.max != 0.000000) a->elt.max = st.max;

        if(a->elt.min > st.avg ) a->elt.min = st.avg;
        if(a->elt.max < st.avg ) a->elt.max = st.avg;

        // moyenne challah
    }

    else if(st.codes < a->elt.codes){
        a->left = insertAVL(a->left,st,h);
        *h = -*h;
    }
    else if(st.codes > a->elt.codes)a->left = insertAVL(a->right,st,h);
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

void infixeAVL(pavl a, FILE* fp){
    if (a != NULL){
        infixeAVL(a->left,fp);
        fprintf(fp, "%d, %f, %f, %f\n", a->elt.codes, a->elt.avg, a->elt.min, a->elt.max);
        infixeAVL(a->right,fp);
    }

}
