/*
*   Helper funcs for infix to postfix as well as postfix evaluation
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "helpers.h"

// Default angle mode
int angle_mode = MODE_DEG;
double ANS = 0.0f;

// Remove whitespaces
void remove_spaces(char* s)
{
    char* d = s;
    do { while (*d == ' ') { ++d;} }
    while (*s++ = *d++);
}

// Returns operator precedence as value
int get_prec(char op)
{
    switch (op)
    {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        case '!': return 4;
        case 's': case 'c': case 't': case 'S': case 'C': case 'T': case 'q': case 'i': case 'p': case 'm': return 5;
        default: return -1;
    }
}

// Returns true if prec of x <= y
bool lower_or_equal_prec(char x, char y)
{
    return get_prec(x) <  get_prec(y) ||
           get_prec(x) == get_prec(y);
}

bool is_op(char c)
{
    switch (c)
    {
        case '+': case '-': case '*': case '/': case '^': return true;
        default: return false;
    }
}

bool is_func(char c)
{
    switch (c)
    {
        // sin, cos, tan, sqrt, isqrt
        case 's': return true;
        case 'c': return true;
        case 't': return true;
        case 'S': return true;
        case 'C': return true;
        case 'T': return true;
        case 'q': return true;
        case 'i': return true;

        // positive, negative
        case 'p': return true;
        case 'm': return true;
        case '!': return true;
        default: return false;
    }
}

// standard operators
double eval_expr(double x, double y, char op)
{
    switch (op)
    {
        case '+': return y + x;
        case '-': return y - x;
        case '*': return y * x;
        case '/': return y / x;
        case '^': return pow(y,x);
    }
}

// Function operators
double eval_fexpr(double x, char op)
{
    switch (op)
    {
        // Forward trig
        case 's': return sin(to_radians(x));
        case 'c': return cos(to_radians(x));
        case 't': return tan(to_radians(x));

        // Inverse trig
        case 'S': return from_radians(asin(x));
        case 'C': return from_radians(acos(x));
        case 'T': return from_radians(atan(x));

        // Other functions
        case 'q': return sqrt(x);
        case 'i': return isqrt(x);
        case '!': return fact(x);
        case 'm': return x * -1;
        case 'p': return x;
    }
    return NAN;
}


unsigned int isqrt(unsigned int n)
{
    int L = 0, M = 0, H = n;
    while (L <= H)
    {
        M = (L + H) / 2;
        if ((M*M) == n) return M;
        else if ((M*M) < n) L=M+1;
        else H=M-1;
    }
    return H;
}

double fact(double x)
{
    double ret = 1;
    while (x) ret *= x--;
    return ret;
}

double to_radians(double x)
{
    switch (angle_mode) {
        case MODE_DEG:  return x * M_PI / 180.0;
        case MODE_GRAD: return x * M_PI / 200.0;
        default:        return x;
    }
}

double from_radians(double x)
{
    switch (angle_mode) {
        case MODE_DEG:  return x * 180.0 / M_PI;
        case MODE_GRAD: return x * 200.0 / M_PI;
        default:        return x;
    }
}

void set_mode(int mode)
{
    angle_mode = mode;
}

void set_ans(double ans)
{
    ANS = ans;
}

double get_ans(void)
{
    return ANS;
}
