#include <stdio.h>
#include <stdlib.h>
#include "longnum_engine.h"
#define alloc(type) (type*)malloc(sizeof(type))

#ifdef __cplusplus
#include <queue>
//using namespace std;
#endif // __cplusplus


longnum longnum_duplicate(longnum num) {
    longnum_digit * num_curr=NULL, *new_curr=NULL, *new_tail=NULL;
    longnum new_head=NULL;

    if (num == NULL) return NULL;
    else {
        num_curr = num;
        while (num_curr->right != NULL && num_curr->digit == 0) {
            num_curr = num_curr->right;
        }
        while (num_curr != NULL) {
            new_curr = alloc(longnum_digit);
            new_curr->digit = num_curr->digit;
            new_curr->right = NULL;
            if (new_head == NULL) {
                new_curr->left = NULL;
                new_head = new_curr;
            }
            else {
                new_curr->left = new_tail;
                new_tail->right = new_curr;
            }
            new_tail = new_curr;
            num_curr = num_curr->right;
        }
    }

    return new_head;
}

longnum longnum_freezero(longnum num_head) {
    if (num_head == NULL) return NULL;

    while (num_head->right != NULL && num_head->digit == 0) {
        num_head = num_head->right;
        free(num_head->left);
    }

    num_head->left = NULL;
    return num_head;
}

longnum longnum_sum (longnum num1_head, longnum num2_head) {
        char leftover=0;
        longnum_digit *num1_curr=NULL;
        longnum_digit *num2_curr=NULL;
        longnum_digit *sum_head=NULL,  *sum_curr=NULL;

        if (num1_head == NULL && num2_head == NULL)
           return NULL;
        else if (num1_head == NULL)
            return longnum_duplicate(num2_head);
        else if (num2_head == NULL)
            return longnum_duplicate(num1_head);
        else {
             num1_curr = num1_head;
             while (num1_curr->right != NULL)
                   num1_curr = num1_curr->right;
             num2_curr = num2_head;
             while (num2_curr->right != NULL)
                   num2_curr = num2_curr->right;
        }

        while ((num1_curr != NULL) || (num2_curr != NULL) || leftover != 0) {
          sum_curr = alloc(longnum_digit);
          sum_curr->digit = leftover;
          if (num1_curr != NULL) {
            sum_curr->digit += num1_curr->digit;
            num1_curr = num1_curr->left;
          }
          if (num2_curr != NULL) {
            sum_curr->digit += num2_curr->digit;
            num2_curr = num2_curr->left;
          }

          leftover = sum_curr->digit / 10;
          sum_curr->digit %= 10;
          sum_curr->left=NULL;
          if (sum_head == NULL) {
             sum_curr->right=NULL;
          }
          else {
             sum_curr->right=sum_head;
             sum_head->left=sum_curr;
          }
          sum_head = sum_curr;
    }

    return longnum_freezero(sum_head);
}

int longnum_cmp (longnum num1_head, longnum num2_head) {
    //sign of num1-num2
    //num1 > num2? return 1
    //num1 < num2? return -1
    //return 0 otherwise
    longnum_digit *num1_curr=NULL;
    longnum_digit *num2_curr=NULL;

    if (num1_head == NULL && num2_head == NULL)
       return 0;
    else if (num1_head == NULL)
         return -1;
    else if (num2_head == NULL)
         return 1;
    else {
        num1_curr = num1_head;
        num2_curr = num2_head;

        while (num1_curr->right != NULL && num1_curr->digit == 0) {
            num1_curr = num1_curr->right;
        }
        while (num2_curr->right != NULL && num2_curr->digit == 0) {
            num2_curr = num2_curr->right;
        }

        while ((num1_curr != NULL) || (num2_curr != NULL)) {
            if (num1_curr == NULL && num2_curr != NULL) return -1;
            else if (num2_curr == NULL && num1_curr != NULL) return 1;
            else {
                num1_curr = num1_curr->right;
                num2_curr = num2_curr->right;
            }
        }
    }

    num1_curr = num1_head;
    num2_curr = num2_head;

    while (num1_curr->right != NULL && num1_curr->digit == 0) {
        num1_curr = num1_curr->right;
    }
    while (num2_curr->right != NULL && num2_curr->digit == 0) {
        num2_curr = num2_curr->right;
    }

    while ((num1_curr != NULL) || (num2_curr != NULL)) {
        if (num1_curr->digit > num2_curr->digit) return 1;
        else if (num2_curr->digit > num1_curr->digit) return -1;
        else {
            num1_curr = num1_curr->right;
            num2_curr = num2_curr->right;
        }
    }
    return 0;
}

void longnum_free (longnum num) {
     longnum tmp;
     while (num != NULL) {
           tmp = num;
           num = num->right;
           free(tmp);
     }
}

longnum longnum_multiply (longnum num1_head, longnum num2_head) {
        char leftover=0;
        longnum_digit *num1_curr=NULL;
        longnum_digit *num2_curr=NULL;
        longnum_digit *sum_head=NULL;
        longnum_digit *tmp_head=NULL, *tmp_curr=NULL, *tmp_tail=NULL;
        unsigned long long int num2_count=0, i;
        //std::queue <longnum >sum_queue;
        longnum *sum_numbers = NULL;
        unsigned sum_numbers_amount = 0, sum_numbers_limit=0;

         if (num1_head == NULL && num2_head == NULL)
           return NULL;

        if (longnum_cmp (num1_head, num2_head) == -1) {
           num1_curr = num1_head;
           num1_head = num2_head;
           num2_head = num1_curr;
        }

        num1_curr = num1_head;
        while (num1_curr->right != NULL)
              num1_curr = num1_curr->right;
        num2_curr = num2_head;
        while (num2_curr->right != NULL)
              num2_curr = num2_curr->right;

        sum_numbers_limit = 4;
        sum_numbers = (longnum *) malloc(sum_numbers_limit * sizeof(longnum));

        while (num2_curr != NULL) {
              if (num2_curr->digit == 0) {
                num2_curr = num2_curr->left;
                num2_count++;
                continue;
              }
              while (num1_curr != NULL || leftover != 0) {
                    tmp_curr = alloc(longnum_digit);
                    tmp_curr->digit = leftover;
                    if (num1_curr != NULL) {
                        tmp_curr->digit += num1_curr->digit * num2_curr->digit;
                        num1_curr = num1_curr->left;
                    }
                    leftover = tmp_curr->digit / 10;
                    tmp_curr->digit %= 10;
                    tmp_curr->left=NULL;
                    if (tmp_head == NULL) {
                       tmp_tail=tmp_curr;
                       tmp_curr->right=NULL;
                    }
                    else {
                         tmp_curr->right=tmp_head;
                         tmp_head->left=tmp_curr;
                    }
                    tmp_head = tmp_curr;
              }

              for (i=0; i<num2_count; i++) {
                  tmp_curr = alloc(longnum_digit);
                  tmp_curr->digit = 0;
                  tmp_curr->right = NULL;
                  tmp_curr->left = tmp_tail;
                  tmp_tail->right = tmp_curr;
                  tmp_tail = tmp_curr;
              }

              /* sum_head = longnum_sum(tmp_head, last_head);
              longnum_free(last_head);
              last_head = sum_head;
              sum_head = NULL;
              longnum_free(tmp_head);
              tmp_head = NULL;
              tmp_curr = NULL;
              tmp_tail = NULL; */

              //sum_queue.push(tmp_head);
              if (sum_numbers_amount == sum_numbers_limit) {
                sum_numbers_limit *= 2;
                sum_numbers = (longnum *) realloc(sum_numbers, sum_numbers_limit * sizeof(longnum));
              }
              sum_numbers[sum_numbers_amount] = tmp_head;
              sum_numbers_amount++;

              tmp_head = NULL;
              tmp_curr = NULL;
              tmp_tail = NULL;

              num1_curr = num1_head;
              while (num1_curr->right != NULL)
                num1_curr = num1_curr->right;
            num2_curr = num2_curr->left;
            num2_count++;
        }

        sum_head = longnum_multinum_sum(/*sum_queue*/sum_numbers, sum_numbers_amount);

        /*while (!sum_queue.empty()) {
            longnum_free(sum_queue.front());
            sum_queue.pop();
        }*/
        for (i=0; i<sum_numbers_amount; i++) {
            longnum_free(sum_numbers[i]);
        }
        free(sum_numbers);

        return sum_head;
}

void longnum_print(longnum num) {
    if (num == NULL) return;
    longnum_digit * num_curr = num;
    char started=0;
    while (num_curr != NULL) {
          if (num_curr->digit != 0 || started) {
             printf("%hhd", num_curr->digit);
             started = 1;
          }
          num_curr = num_curr->right;
    }
    if (!started) printf("0");
}

longnum int_to_longnum(unsigned int integer) {
    longnum_digit * num_head=NULL, * num_curr=NULL;

    do {
        num_curr = alloc(longnum_digit);
        num_curr->digit = integer % 10;
        integer /= 10;
        num_curr->left = NULL;
        if (num_head == NULL) {
            num_curr->right = NULL;
        }
        else {
            num_curr->right = num_head;
            num_head->left = num_curr;
        }
        num_head = num_curr;
    } while (integer != 0);
    return num_head;
}

longnum longnum_multinum_sum(longnum *numbers, unsigned numbers_amount) {
        unsigned int leftover=0;
        //std::queue <longnum> sum_queue;
        //std::queue <longnum> tmp_queue;
        //longnum num_curr=NULL;
        longnum_digit ** num_curr = (longnum_digit **) malloc(numbers_amount * sizeof(longnum_digit *));
        longnum result_head=NULL, result_curr=NULL;
        //longnum new_digit=NULL;
        unsigned int sum_tmp;
        unsigned int i, finishFlag = 0;

        if (/*queue.empty()*/ numbers_amount == 0) return int_to_longnum(0);

        /*while(!queue.empty())*/ for (i=0; i<numbers_amount; i++) {
            /*num_curr = queue.front();
            queue.pop();*/
            num_curr[i] = numbers[i];
            if (num_curr[i] == NULL) continue;
            while (num_curr[i]->right != NULL)
                  num_curr[i] = num_curr[i]->right;
            //sum_queue.push(num_curr);
        }

        //new_digit = sum_queue.back();
        //num_curr = NULL;
        while (/* !sum_queue.empty() */ !finishFlag || leftover != 0) {
              finishFlag = 1;
              result_curr = alloc(longnum_digit);
              sum_tmp = leftover;
              //if (!sum_queue.empty()) {
              /*while (num_curr != new_digit)*/ for (i=0; i<numbers_amount; i++) {
                    //num_curr = sum_queue.front();
                    //sum_queue.pop();
                    if (num_curr[i] != NULL) {
                        sum_tmp += num_curr[i]->digit;
                        /*if (num_curr->left != NULL)
                            sum_queue.push(num_curr->left);*/
                        finishFlag = 0;
                        num_curr[i] = num_curr[i]->left;
                    }
              }
              //if (!sum_queue.empty()) new_digit = sum_queue.back();
              //}

              leftover = sum_tmp / 10;
              result_curr->digit = sum_tmp % 10;
              result_curr->left=NULL;
              if (result_head == NULL) {
                 result_head = result_curr;
                 result_curr->right = NULL;
              }
              else {
                   result_curr->right = result_head;
                   result_head->left = result_curr;
              }
              result_head = result_curr;

              /*while (!tmp_queue.empty()) {
                    sum_queue.push(tmp_queue.front());
                    tmp_queue.pop();
              }*/
        }

        return longnum_freezero(result_head);
}

longnum longnum_uint_multiply(longnum num1_head, unsigned int num) {
    unsigned long int tmp, leftover=0;
    longnum num1_curr=NULL, result_head=NULL, result_curr=NULL;

    num1_curr = num1_head;
    while (num1_curr->right != NULL)
        num1_curr = num1_curr->right;

    while (num1_curr != NULL || leftover != 0) {
        result_curr = alloc(longnum_digit);
        tmp = leftover;
        if (num1_curr != NULL) {
            tmp += num1_curr->digit * num;
            num1_curr = num1_curr->left;
        }
        result_curr->digit = tmp % 10;
        leftover = tmp / 10;
        result_curr->left = NULL;
        if (result_head == NULL) {
            result_curr->right = NULL;
        }
        else {
            result_curr->right = result_head;
            result_head->left = result_curr;
        }
        result_head = result_curr;
    }

    return longnum_freezero(result_head);
}

longnum longnum_diff (longnum num1_head, longnum num2_head) {
    longnum_digit* num1_curr = NULL;
    longnum_digit* num2_curr = NULL;
    longnum_digit* diff_head = NULL, *diff_curr = NULL;
    int leftover = 0;

    if (longnum_cmp(num1_head, num2_head) == -1) {
        return int_to_longnum(0);
    }

    num1_curr = num1_head;
    while (num1_curr->right != NULL) {
        num1_curr = num1_curr->right;
    }
    num2_curr = num2_head;
    while (num2_curr->right != NULL) {
        num2_curr = num2_curr->right;
    }

    while (num2_curr != NULL) {
        diff_curr = alloc(longnum_digit);
        diff_curr->digit = num1_curr->digit - num2_curr->digit + leftover;

        leftover = 0;
        while (diff_curr->digit < 0) {
            diff_curr->digit += 10;
            leftover -= 1;
        }

        if (diff_head == NULL) {
            diff_curr->right = NULL;
        }
        else {
            diff_curr->right = diff_head;
            diff_head->left = diff_curr;
        }
        diff_curr->left = NULL;
        diff_head = diff_curr;

        num1_curr = num1_curr->left;
        num2_curr = num2_curr->left;
    }

    while (leftover != 0 || num1_curr != NULL) {
        diff_curr = alloc(longnum_digit);
        diff_curr->digit = leftover;
        if (num1_curr != NULL) {
            diff_curr->digit += num1_curr->digit;
        }

        leftover = 0;
        while (diff_curr->digit < 0) {
            diff_curr->digit += 10;
            leftover -= 1;
        }

        //leftover = diff_curr->digit / 10;
        //diff_curr->digit %= 10;

        if (diff_head == NULL) {
            diff_curr->right = NULL;
        }
        else {
            diff_curr->right = diff_head;
            diff_head->left = diff_curr;
        }
        diff_curr->left = NULL;
        diff_head = diff_curr;

        if (num1_curr != NULL) num1_curr = num1_curr->left;
    }

    return longnum_freezero(diff_head);
}

longnum longnum_read() {
    longnum_digit *num1_head = NULL, *num1_curr=NULL, *num1_tail = NULL;
    char input;

    input = getchar();
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

    return num1_head;
}

longnum_div_t longnum_div_wr_simple (longnum dividend_head, longnum divisor_head) {
    longnum_div_t ret;
    ret.quotient = int_to_longnum(0);
    ret.remainder = longnum_duplicate(dividend_head);
    longnum tmp, one = int_to_longnum(1);
    //int cmp;
    if (longnum_cmp(ret.quotient, divisor_head) == 0) return ret;

    while (longnum_cmp(ret.remainder, divisor_head) >= 0) {
    //cmp = longnum_cmp(ret.remainder, divisor_head);
    //while (cmp >= 0) {
        tmp = ret.remainder;
        ret.remainder = longnum_diff(tmp, divisor_head);
        longnum_free(tmp);

        tmp = ret.quotient;
        ret.quotient = longnum_sum(tmp, one);
        longnum_free(tmp);

        //cmp = longnum_cmp(ret.remainder, divisor_head);
    }

    ret.quotient = longnum_freezero(ret.quotient);
    ret.remainder = longnum_freezero(ret.remainder);
    return ret;
}

longnum_div_t longnum_div_wr_longdiv (longnum dividend_head, longnum divisor_head) {
    longnum_div_t ret;
    ret.quotient = NULL;
    ret.remainder = NULL;
    longnum_digit *quotient_curr=NULL, *quotient_tail=NULL;
    longnum_digit *remainder_curr=NULL, *remainder_tail=NULL;
    longnum_digit *dividend_curr = dividend_head;
    longnum tmp;

    while (dividend_curr != NULL) {
        quotient_curr = alloc(longnum_digit);
        quotient_curr->digit = 0;
        quotient_curr->right = NULL;
        if (ret.quotient == NULL) {
            ret.quotient = quotient_curr;
            quotient_curr->left = NULL;
        }
        else {
            quotient_tail->right = quotient_curr;
            quotient_curr->left = quotient_tail;
        }
        quotient_tail = quotient_curr;

        remainder_curr = alloc(longnum_digit);
        remainder_curr->digit = dividend_curr->digit;
        remainder_curr->right = NULL;
        if (ret.remainder == NULL) {
            ret.remainder = remainder_curr;
            remainder_curr->left = NULL;
        }
        else {
            remainder_tail = ret.remainder;
            while (remainder_tail->right != NULL) {
                remainder_tail = remainder_tail->right;
            }
            remainder_tail->right = remainder_curr;
            remainder_curr->left = remainder_tail;
        }

        while (longnum_cmp(ret.remainder, divisor_head) >= 0) {
            tmp = ret.remainder;
            ret.remainder = longnum_diff(tmp, divisor_head);
            longnum_free(tmp);

            quotient_curr->digit += 1;
        }

        dividend_curr = dividend_curr->right;
    }

    ret.quotient = longnum_freezero(ret.quotient);
    ret.remainder = longnum_freezero(ret.remainder);
    return ret;
}

longnum_div_t longnum_div_wr (longnum dividend_head, longnum divisor_head) {
    //simple algorithm: loop subtraction;
    //return longnum_div_wr_simple (dividend_head, divisor_head);

    //long division algorithm
    return longnum_div_wr_longdiv(dividend_head, divisor_head);
}

longnum longnum_devide (longnum dividend_head, longnum divisor_head) {
    longnum_div_t result = longnum_div_wr(dividend_head, divisor_head);
    longnum_free(result.remainder);
    return result.quotient;
}

longnum longnum_modulo (longnum dividend_head, longnum divisor_head) {
    longnum_div_t result = longnum_div_wr(dividend_head, divisor_head);
    longnum_free(result.quotient);
    return result.remainder;
}
