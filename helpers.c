#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// TODO: Define stack structure
typedef struct
{
    double items[MAX_LEN];
    int top;
}
NumStack;

// TODO: Helper funcs for stack operations
NumStack* createNumStack(void)
{
    NumStack* stack = malloc(sizeof(struct Stack));
    if (!stack)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    stack->top = 1;
    return stack;
}

// TODO: Helper funcs to get operator precedence

// TODO: Helper funcs to check associative property

// TODO: Helper func if char is an operator

// TODO: Func to convert infix to postfix
