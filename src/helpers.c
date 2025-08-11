#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "helpers.h"

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
        case 's': case 'c': case 't': case 'q': case 'i': return 5;
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
        case '+': case '-': case '*': case '/': case '^': case '!': return true;
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

// function operators
double eval_fexpr(double x, char op)
{
    switch (op)
    {
        case 's': return sin(deg_to_rad(x));
        case 'c': return cos(deg_to_rad(x));
        case 't': return tan(deg_to_rad(x));
        case 'q': return sqrt(x);
        case 'i': return isqrt(x);
        case '!': return fact(x);
        case 'm': return x * -1;
        case 'p': return x * 1;
    }
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

double deg_to_rad(double deg)
{
    return deg * M_PI / 180.0;
}
