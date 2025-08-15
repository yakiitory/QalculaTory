#include <stdio.h>
#include <string.h>
#include "helpers.h"
#include "shunting_yard.h"
#include "stack.h"

static char result_static[25];

const char* parser(const char* infix)
{
    char postfix[MAX_LEN];

    // Convert to postfix
    if (!infix_to_postfix(infix, postfix))
        return SYNTAX_ERROR;

    // Evaluate postfix into result_static
    if (!eval_postfix(postfix, result_static))
        return SYNTAX_ERROR;

    return result_static;
}
