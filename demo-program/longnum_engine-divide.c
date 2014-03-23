#include <stdio.h>
#include "longnum_engine.h"

int main () {
    longnum dividend, divisor;
    longnum_div_t ret;

    printf("Enter dividend : ");
    dividend = longnum_read();

    printf("Enter divisor : ");
    divisor = longnum_read();

    ret = longnum_div_wr(dividend, divisor);

    printf("\nQuotient is : ");
    longnum_print(ret.quotient);

    printf("\nRemainder is : ");
    longnum_print(ret.remainder);

    putchar('\n');
    return 0;
}
