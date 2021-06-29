/*
    Author: Oliver Dai
    
    Stock Library
*/

#include "stock.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

stock* stock_create(char* symbol, int purchase, int current, int shares) 
{
    stock* stock = malloc(sizeof(struct stock));
    stock->purchase = purchase;
    stock->current = current;
    stock->shares = shares;
    stock->symbol = malloc(strlen(symbol) + 1);
    strcpy(stock->symbol, symbol);
    return stock;
}

void stock_free(stock* stock) 
{
    free(stock->symbol);
    // printf("Freed stock symbol!\n");
    free(stock);
    // printf("Freed stock struct!\n");
}
