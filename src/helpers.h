#ifndef HELPERS_H
#define HELPERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <string.h>

// Maximum length for expressions
#define MAX_LEN 256

// Calculator Modes
#define MODE_DEG 0
#define MODE_RAD 1
#define MODE_GRAD 2

// Constant values
#define PI_VAL "3.14159265358979311600"
#define E_VAL "2.71828"

#define ERR_STACK_MEMORY "Failed to allocate memory for stack"
#define ERR_STACK_EMPTY "Stack is empty"
#define ERR_NODE_MEMORY "Failed to allocate memory for node"
#define ERR_MALLOC "Failed to allocate memory"
#define SYNTAX_ERROR "Syntax ERROR!"

void remove_spaces(char* s);
int get_prec(char op);
bool lower_or_equal_prec(char x, char y);
bool is_op(char c);
bool is_func(char c);
double eval_expr(double x, double y, char op);
double eval_fexpr(double x, char op);
unsigned int isqrt(unsigned int n);
double fact(double x);
double to_radians(double x);
double from_radians(double x);
void set_mode(int mode);
void set_ans(double ans);
double get_ans(void);

#ifdef __cplusplus
}
#endif

#endif // HELPERS_H
