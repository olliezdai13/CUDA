/*
    Author: Oliver Dai
    
    Stock Library
*/

#ifndef STOCK_H
#define STOCK_H

typedef struct stock {
    char* symbol;
    int purchase;
    int current;
    int shares;
} stock;

stock* stock_create(char* symbol, int purchase, int current, int shares);

void stock_free(stock* stock);

#endif