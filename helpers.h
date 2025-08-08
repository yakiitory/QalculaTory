#ifndef HELPERS_H
#define HELPERS_H

#include <stdbool.h>

// Maximum length for expressions
#define MAX_LEN 256

//  Converts an infix expression to postfix
// returns true if successful, false if invalid
bool toPostfix(const char *infix, char *postfix);

// Evaluates a postfix expression
bool evalPostfix(const char *postfix, double *result);
