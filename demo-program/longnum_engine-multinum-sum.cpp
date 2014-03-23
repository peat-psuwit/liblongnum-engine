#include <stdio.h>
#include "longnum_engine.h"
#include <queue>
using namespace std;

int main () {
    unsigned int input;
    std::queue <longnum >q;
    longnum result, tmp;
    
    do {
        printf("Enter num : ");
        scanf("%u", &input);
        
        if (input != 0) {
           tmp = int_to_longnum(input);
           q.push(tmp);
        }
    } while (input != 0);
    
    result = longnum_multinum_sum(q);
    printf("\n");
    longnum_print(result);
    printf("\n");
    longnum_free(result);
    
    return 0;
}
