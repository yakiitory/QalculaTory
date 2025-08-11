#ifndef HELPERS_H
#define HELPERS_H

#include <stdbool.h>
#include <string.h>

// Maximum length for expressions
#define MAX_LEN 256

#define ERR_STACK_MEMORY "Failed to allocate memory for stack"
#define ERR_STACK_EMPTY "Stack is empty"
#define ERR_NODE_MEMORY "Failed to allocate memory for node"
#define ERR_MALLOC "Failed to allocate memory"
#define SYNTAX_ERROR "Syntax Error!"

void remove_spaces(char* s);
int get_prec(char op);
bool lower_or_equal_prec(char x, char y);
bool is_op(char c);
bool is_func(char c);
double eval_expr(double x, double y, char op);
double eval_fexpr(double x, char op);
unsigned int isqrt(unsigned int n);
double fact(double x);
double deg_to_rad(double deg);

#endif // HELPERS_H
