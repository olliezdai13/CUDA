/*
    Author: Oliver Dai
    
    Portfolio Library
*/

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "stock.h"
#include "llist.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct portfolio {
    node* stocks;
} portfolio;


portfolio* create_portfolio();
void print_portfolio();
void free_portfolio();
int total_value();


#endif
