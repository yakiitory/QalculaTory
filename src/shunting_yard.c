#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "stack.h"
#include "helpers.h"
#include "shunting_yard.h"

static int handle_math_function(const char* infix, int i, OpStack* stack)
{
    struct {
        const char* name;
        char op;
    } funcs[] = {
        {"sin",  's'},
        {"cos",  'c'},
        {"tan",  't'},
        {"sqrt", 'q'},
        {"isqrt",'i'}
    };

    for (size_t f = 0; f < sizeof(funcs)/sizeof(funcs[0]); f++)
    {
        size_t len = strlen(funcs[f].name);
        if (strncmp(&infix[i], funcs[f].name, len) == 0)
        {
            push_op(stack, funcs[f].op);
            return (int)(len - 1);
        }
    }
    return 0; // no match
}


bool infix_to_postfix(char* infix, char* postfix)
{
    remove_spaces(infix);
    int len = strlen(infix);
    char* result = malloc(len * 3);
    int j = 0;

    if (!result)
    {
        fprintf(stderr, "%s\n", ERR_MALLOC);
        exit(1);
    }

    OpStack* stack = create_op_stack();

    for (int i = 0; i < len; i++)
    {
        char c = infix[i];

        // Number (integer/float)
        if (isdigit(c) || c == '.')
        {
            char token[64];
            int index = 0;
            while (i < len && (isdigit(infix[i]) || infix[i] == '.'))
            {
                token[index++] = infix[i++];
            }
            token[index] = '\0';
            for (int k = 0; token[k] != '\0'; k++)
                result[j++] = token[k];
            result[j++] = ' ';
            i--; // step back because for-loop will increment
            continue;
        }

        // Math function handling (sin, cos, etc.)
        int skip = handle_math_function(infix, i, stack);
        if (skip > 0)
        {
            i += skip;
            continue;
        }

        // Left parenthesis or factorial
        if (c == '(' || c == '!')
        {
            push_op(stack, c);
            continue;
        }

        // Right parenthesis
        if (c == ')')
        {
            while (!is_opstack_empty(stack) && peek_op(stack) != '(')
            {
                result[j++] = pop_op(stack);
                result[j++] = ' ';
            }
            if (!is_opstack_empty(stack) && peek_op(stack) == '(')
                pop_op(stack); // discard '('

            if (!is_opstack_empty(stack) && is_func(peek_op(stack)))
            {
                result[j++] = pop_op(stack);
                result[j++] = ' ';
            }
            continue;
        }

        // Operators
        if (is_op(c))
        {
            // Unary detection
            if (i == 0 || is_op(infix[i-1]) || infix[i-1] == '(')
            {
                if (c == '+') c = 'p';
                if (c == '-') c = 'm';
            }

            while (!is_opstack_empty(stack) && lower_or_equal_prec(c, peek_op(stack)))
            {
                result[j++] = pop_op(stack);
                result[j++] = ' ';
            }
            push_op(stack, c);
            continue;
        }

        // Skip spaces (already mostly removed)
        if (isspace(c))
            continue;

        // If we reach here, it’s truly invalid
        fprintf(stderr, "Invalid character: %c\n", c);
        free_opstack(stack);
        free(result);
        return false;
    }

    // Pop remaining operators
    while (!is_opstack_empty(stack))
    {
        result[j++] = pop_op(stack);
        result[j++] = ' ';
    }

    result[j] = '\0';
    strcpy(postfix, result);
    free_opstack(stack);
    free(result);
    return true;
}

bool eval_postfix(char* postfix, double* result)
{
    // build stack
    NumStack* stack = create_num_stack();
    if (!stack)
    {
        fprintf(stderr, "%s\n", ERR_STACK_MEMORY);
        exit(1);
    }
    int len = strlen(postfix);
    // iterate over each char in postfix
    for (int i = 0; i < len; i++)
    {
        char c = postfix[i];
        if (isdigit(c) || c == '.')
        {
            char token[64];
            int index = 0;
            while (i < len && (isdigit(postfix[i]) || postfix[i] == '.'))
            {
                token[index++] = postfix[i];
                i++;
            }
            token[index] = '\0';
            push_num(stack, atof(token));
            i--;
        }

        else if (is_op(c))
        {
            double x = 0.0;
            double y = 0.0;
            double value = 0.0;
            if (!is_numstack_empty(stack)) x = pop_num(stack);
            if (!is_numstack_empty(stack)) y = pop_num(stack);
            value = eval_expr(x, y, c);
            push_num(stack, value);
        }

        else if (is_func(c))
        {
            double x = 0.0;
            double value = 0.0;
            if (!is_numstack_empty(stack)) x = pop_num(stack);
            value = eval_fexpr(x, c);
            push_num(stack, value);
        }
        else if (isspace(c)) continue;
    }
    *result = pop_num(stack);
    free_numstack(stack);
    return true;
}
