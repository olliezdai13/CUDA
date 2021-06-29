#include "portfolio.h"

#include <stdio.h>

int main() {
    portfolio* p = create_portfolio();
    print_portfolio(p);
    printf("Value = %i\n", total_value(p));
    free_portfolio(p);
}