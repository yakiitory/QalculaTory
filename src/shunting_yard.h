#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

// Calculator Modes
#define MODE_DEG 0
#define MODE_RAD 1
#define MODE_GRAD 2

bool infix_to_postfix(char* infix, char* postfix);
bool eval_postfix(char* postfix, char* result);

#ifdef __cplusplus
}
#endif

#endif // SHUNTING_YARD_H
