/*
    Author: Oliver Dai
    
    Linked List of Stocks
*/

#ifndef LLIST_H
#define LLIST_H

#include "stock.h"

typedef struct node {
    stock* stock;
    struct node* next;
} node;

void list_create(node** list);

void list_push(node** list, stock* stock);

int list_length(node* list);

stock* list_at(node* list, int ii);

void list_free(node* list);

#endif