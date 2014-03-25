#ifndef H_LONGNUM_ENGINE

#define H_LONGNUM_ENGINE

struct s_longnum_digit {
       signed char digit;
       struct s_longnum_digit * left;
       struct s_longnum_digit * right;
};
typedef struct s_longnum_digit longnum_digit;
typedef struct s_longnum_digit * longnum;

typedef struct s_longnum_div_t {
    longnum quotient;
    longnum remainder;
} longnum_div_t;

#ifdef __cplusplus
//This fuction is usable only if using c++
#include <queue>
longnum longnum_multinum_sum(std::queue<longnum> queue);
extern "C" {
#endif // __cplusplus
longnum longnum_sum (longnum num1_head, longnum num2_head);
longnum longnum_multiply (longnum num1_head, longnum num2_head);
longnum longnum_diff (longnum num1_head, longnum num2_head);
longnum longnum_uint_multiply(longnum num1_head, unsigned int num);
longnum_div_t longnum_div_wr (longnum dividend_head, longnum divisor_head);
longnum longnum_devide (longnum dividend_head, longnum divisor_head);
longnum longnum_modulo (longnum dividend_head, longnum divisor_head);

int longnum_cmp (longnum num1_head, longnum num2_head);
void longnum_free (longnum num);
longnum longnum_duplicate(longnum num);
void longnum_print(longnum num);
longnum longnum_read();

longnum int_to_longnum(unsigned int integer);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // Not H_LONGNUM_ENGINE
