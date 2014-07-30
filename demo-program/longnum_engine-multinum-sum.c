#include <stdio.h>
#include "longnum_engine.h"
//#include <queue>
//using namespace std;
#include <stdlib.h>

int main () {
    //unsigned int input;
    //std::queue <longnum >q;
    longnum *sum_numbers = NULL;
    unsigned sum_numbers_amount = 0, sum_numbers_limit=0;
    longnum result, tmp;
    longnum zero = int_to_longnum(0);

    sum_numbers_limit = 4;
    sum_numbers = (longnum *) malloc(sum_numbers_limit * sizeof(longnum));

    do {
        printf("Enter num : ");
        tmp = longnum_read();

        if (longnum_cmp(zero, tmp) != 0) {
           //q.push(tmp);
           if (sum_numbers_amount == sum_numbers_limit) {
             sum_numbers_limit *= 2;
             sum_numbers = (longnum *) realloc(sum_numbers, sum_numbers_limit * sizeof(longnum));
           }
           sum_numbers[sum_numbers_amount] = tmp;
           sum_numbers_amount++;
        }
        else break;
    } while (1);

    result = longnum_multinum_sum(/*q*/sum_numbers, sum_numbers_amount);
    printf("\n");
    longnum_print(result);
    printf("\n");
    longnum_free(result);

    return 0;
}
