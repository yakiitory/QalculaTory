#define HELPERS_H

#include <stdbool.h>
#include <string.h>

// Maximum length for expressions
#define MAX_LEN 256

//  Converts an infix expression to postfix
// returns true if successful, false if invalid
bool infix_to_postfix(char* infix, char* postfix);

// Evaluates a postfix expression
bool eval_postfix(char* postfix, double* result);
