#include <stdio.h>
#include "longnum_engine.h"

int main () {
    longnum num1, num2, diff;

    printf("Enter first number : ");
    num1 = longnum_read();

    printf("Enter second number : ");
    num2 = longnum_read();

    diff = longnum_diff(num1, num2);

    printf("Difference is ");
    longnum_print(diff);
    putchar('\n');

    return 0;
}
