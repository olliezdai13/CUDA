/*
    Author: Oliver Dai
    
    Portfolio Library
*/

#include "portfolio.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

portfolio* create_portfolio() 
{
    portfolio* p = malloc(sizeof(portfolio));
    list_create(&(p->stocks));

    FILE* fp;
    fp=fopen("portfolio.txt", "r");
    
    char symbol[10];

    int current;
    int purchase;
    int shares;
    while (fscanf(fp, "%s %i %i %i", symbol, &purchase, &current, &shares) != EOF) {
        list_push(&(p->stocks), stock_create(symbol, purchase, current, shares));
    }
    return p;
}

void print_portfolio(portfolio* p) 
{
    node* head = p->stocks;
    while (head != NULL) {
        printf("%-5s | %-5i | %-5i | %-5i |\n", head->stock->symbol, head->stock->purchase, head->stock->current, head->stock->shares);
        head = head->next;
    }
}

void free_portfolio(portfolio* p) 
{
    list_free(p->stocks);
    free(p);
    // printf("Freed portfolio!");
}

int total_value(portfolio* p)
{
    int total = 0;
    node* head = p->stocks;
    while (head != NULL) {
        int currVal = head->stock->shares * head->stock->current;
        total += currVal;
        head = head->next;
    }

    return total;
}
