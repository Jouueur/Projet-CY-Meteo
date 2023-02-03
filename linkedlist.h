//
// Created by Marius on 03/02/23.
//

#ifndef PROJET_CY_METEO_LINKEDLIST_H
#define PROJET_CY_METEO_LINKEDLIST_H

#include <stdio.h>
#include "global_defs.h"

typedef struct elmt {
    Station elt;
    struct elmt* next;
}list;

typedef list *LinkedList;

LinkedList createLL();
int is_empty(LinkedList l);
LinkedList allocNode(Station st);
LinkedList getNode(LinkedList l, Station st);
void writeCSV(LinkedList l, FILE *fp);
void freeLL(LinkedList l);


#endif //PROJET_CY_METEO_LINKEDLIST_H
