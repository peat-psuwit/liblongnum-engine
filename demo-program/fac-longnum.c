#include <stdio.h>
#include "longnum_engine.h"
#define CACHE_SIZE 1000

int main () {
    int start, zerocount;
    unsigned int i;
    longnum multiplyer=NULL, tmp_result=NULL, result=NULL, result_curr=NULL;
    longnum cache[CACHE_SIZE + 1];
    cache[0] = int_to_longnum(1);
    cache[1] = int_to_longnum(1);
    for (i=2; i<=CACHE_SIZE; i++)
        cache[i]=NULL;

    do {
        printf("How much fac? (-1 = exit) : ");
        scanf("%d", &start);
        //while (getchar() == '\n');
        //start = 1000; //use with automated test

        if (start > -1) {
            for (i=0; i<=start; i++) {
                if (i>CACHE_SIZE) {
                    //multiplyer = int_to_longnum(i);
                   tmp_result = longnum_uint_multiply(result, i);
                   if (result != cache[CACHE_SIZE]) longnum_free(result);
                   result = tmp_result;
                }
                else {
                     if (cache[i] == NULL) {
                        //multiplyer = int_to_longnum(i);
                        cache[i] = longnum_uint_multiply(cache[i-1], i);
                     }
                     result = cache[i];
                }
                //longnum_free(multiplyer);
                //multiplyer = NULL;
            }

            printf("\n%d! = ", start);
            longnum_print(result);

            printf("\n0 in result = ");

            result_curr = result;
            while (result_curr->right != NULL)
                result_curr = result_curr->right;
            zerocount = 0;
            while (result_curr->left != NULL) {
                if (result_curr->digit == 0) {
                    zerocount++;
                    result_curr = result_curr->left;
                }
                else break;
            }
            printf("%d\n\n", zerocount);

            if (start > CACHE_SIZE) longnum_free(result);
            result = tmp_result = multiplyer = NULL;

            //for (i=0; i<=1000; i++) longnum_free(cache[i]); //will be freed at exit

            //start = -1; //use for automated test
        }
    } while (start > -1);

    return 0;
}
