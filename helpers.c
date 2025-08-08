#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    NumStack* stack = malloc(sizeof(NumStack));
    if (!stack)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    stack->top = -1;
    return stack;
}

// Returns true if stack is full
bool isFull(NumStack* stack)
{
    // Returns true if the value of top inside stack is equal to the value of MAX_LEN - 1
    return stack->top == (MAX_LEN - 1);
}

// Returns true if stack is empty
bool isEmpty(NumStack* stack)
{
    // Empty value of a top in stack is always -1
    return stack->top == -1;
}

// Inserts on top of stack
void pushNum(NumStack* stack, double value)
{
    if (isFull(stack))
    {
        fprintf(stderr, "Stack Overflow!\n");
        exit(1);
    }
    // Inserts 'value' in the item field of the stack at the top index
    stack->items[++stack->top] = value;
}

// Retrieves on top of stack
double popNum(NumStack* stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Stack is empty!\n");
        exit(1);
    }
    // Takes the top value of the stack
    return stack->items[stack->top--];
}

// Only peeks at whatever value on top of stack
double peekNum(NumStack* stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Stack is empty!\n");
        exit(1);
    }
    // Only peek at value
    return stack->items[stack->top];
}

// Free stack loaded onto memory
void freeStack(NumStack* stack)
{
    if (stack)
    {
        free(stack);
    }
}

// TODO: Helper funcs to get operator precedence
int getPrecendence(char op)
{
    switch (op)
    {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// TODO: Helper funcs to check associative property
bool isRightAssociative(char op)
{
    return op == '^';
}

bool isLeftAssociative(char op)
{
    return op != '^';
}
// TODO: Helper func if char is an operator
bool isOperator(char c)
{
    return c == '+' || '-' || '*' || '/' || "^";
}

// TODO: Func to convert infix to postfix
bool toPostfix(const char *postfix, double *result)
{
    // TODO: Implement postfix evaluation here
    // - Use stack for operands
    // - Push numbers onto stack
    // - Pop operands when operator is found, apply, push result back
    // - Handle division by zero
    // Return false if invalid

    NumStack* stack = createNumStack();
    if (!stack)
    {
        fprintf(stderr, "Failed to create stack!\n");
        exit(1);
    }

    return false; // placeholder
}
