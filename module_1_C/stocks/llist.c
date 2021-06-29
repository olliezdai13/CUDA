/*
    Author: Oliver Dai
    
    Linked List of Stocks
*/

#include "llist.h"

#include <stdio.h>
#include <stdlib.h>

void list_create(node** list)
{
    *list = NULL;
}

void list_push(node** list, stock* stock)
{
    while (*list != NULL) {
        list = &(*list)->next;
    }
    *list = malloc(sizeof(node));
    (*list)->stock = stock;
    (*list)->next = NULL;
}

int list_length(node* list)
{
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

stock* list_at(node* list, int ii) {
    if (list == NULL) {
        printf("ERROR: out of bounds\n");
        return NULL;
    }
    if (ii <= 0) {
        return list->stock;
    } else {
        return list_at(list->next, --ii);
    }
}


void list_free_acc(node* list, int count)
{
    if (list != NULL) {
        list_free_acc(list->next, ++count);
        stock_free(list->stock);
        free(list);
    } else {
        // printf("Freeing %i nodes!\n", count);
    }
}

void list_free(node* list) {
    list_free_acc(list, 0);
}

