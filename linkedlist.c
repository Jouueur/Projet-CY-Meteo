//
// Created by Marius on 03/02/23.
//

#include "linkedlist.h"

LinkedList createLL(){
    return NULL;
}

int is_empty(LinkedList l){
    if (l == NULL) return 1;
    return 0;
}

LinkedList allocNode(Station st){
    LinkedList temp;
    temp = (LinkedList) malloc(sizeof (LinkedList));
    temp->elt = st;
    temp->next = NULL;
    return temp;
}

LinkedList getNode(LinkedList l, Station st){
    LinkedList x = l, temp = allocNode(st);

    if (is_empty(l)){
        return temp;
    }

    while (!is_empty(x->next)){

        if (x->elt.codes == st.codes){
            if(x->elt.min > st.min && st.min != 0.000000) x->elt.min = st.min;
            if(x->elt.max < st.max && st.max != 0.000000) x->elt.max = st.max;

            if(x->elt.min > st.avg ) x->elt.min = st.avg;
            if(x->elt.max < st.avg ) x->elt.max = st.avg;

            x->elt.avg = (x->elt.avg + st.avg ) /2 -0.5;
            break;
        }

        if (x->next->elt.codes < st.codes ){
            temp->next = x->next;
            x->next = temp;
            break;
        }
        x = x->next;
    }

    if (is_empty(x->next)){
        x->next = temp;
    }

    return l;
}

void writeCSV(LinkedList l, FILE *fp){
    if (!is_empty(l)){
        fprintf(fp, "%d, %f, %f, %f\n", l->elt.codes, l->elt.avg, l->elt.min, l->elt.max);
        writeCSV(l->next, fp);
    }
}

void freeLL(LinkedList l){
    if (!is_empty(l)){
        freeLL(l->next);
        free(l);
    }
}