/*
    Compile with: gcc -o stocks main.c stock.c llist.c portfolio.c
*/

#include "portfolio.h"

#include <stdio.h>

int main() {
    portfolio* p = create_portfolio();
    print_portfolio(p);
    printf("Value = %i\n", total_value(p));
    free_portfolio(p);
}