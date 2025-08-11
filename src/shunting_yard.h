#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <stdbool.h>

bool infix_to_postfix(char* infix, char* postfix);
bool eval_postfix(char* postfix, double* result);

#endif
