#include <stdio.h>
#include <stdlib.h>
#include "longnum_engine.h"
#define alloc(type) (type*)malloc(sizeof(type))

int main() {
    char input;
    longnum_digit *num1_head=NULL, *num1_tail=NULL, *num1_curr=NULL;
    longnum_digit *num2_head=NULL, *num2_tail=NULL, *num2_curr=NULL;
    longnum_digit *sum_head=NULL;

    do {
       printf("Enter number : ");
       input = getchar();
    } while (input == '\n');

    while (input != '\n') {
        num1_curr = alloc(longnum_digit);
        num1_curr->digit=input-'0';
        num1_curr->right=NULL;
        if (num1_head == NULL) {
            num1_head = num1_curr;
            num1_curr->left=NULL;
        }
        else {
            num1_curr->left=num1_tail;
            num1_tail->right=num1_curr;
        }
        num1_tail = num1_curr;
        input = getchar();
    }

    do {
       printf("Enter number : ");
       input = getchar();
    } while (input == '\n');

    while (input != '\n') {
        num2_curr = alloc(longnum_digit);
        num2_curr->digit=input-'0';
        num2_curr->right=NULL;
        if (num2_head == NULL) {
            num2_head = num2_curr;
            num2_curr->left=NULL;
        }
        else {
            num2_curr->left=num2_tail;
            num2_tail->right=num2_curr;
        }
        num2_tail = num2_curr;
        input = getchar();
    }
    printf("\n");

    sum_head = longnum_multiply(num1_head, num2_head);

    printf("Result of multiplication is : ");
    /*sum_curr = sum_head;
    while (sum_curr != NULL) {
          printf("%d", sum_curr->digit);
          sum_curr = sum_curr->right;
    }*/
    longnum_print(sum_head);
    printf("\n");

    return 0;
}
