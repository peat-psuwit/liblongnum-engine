#include <stdio.h>
#include "longnum_engine.h"

int main () {
    longnum fib[10001];
    int stop;
    unsigned int i;

    fib[0] = int_to_longnum(0);
    fib[1] = int_to_longnum(1);
    fib[2] = int_to_longnum(1);
    for (i=3; i<=10000; i++) fib[i] = NULL;

    do {
        printf("Fibonacci number (-1 to exit)? : ");
        scanf("%d", &stop);

        if (stop > -1) {
            for (i=3; i<=stop; i++) {
                if (fib[i] == NULL)
                    fib[i] = longnum_sum(fib[i-1], fib[i-2]);
            }

            printf("%d'th Fibonacci = ", stop);
            longnum_print(fib[stop]);
            printf("\n");
        }
    } while (stop > -1);
    return 0;
}
