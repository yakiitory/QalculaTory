#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// TODO: Define linked list
typedef struct num_node
{
    double value;
    struct num_node* next;
}
NumNode;

typedef struct op_node
{
    char op;
    struct op_node* next;
}
OpNode;

// TODO: Define stack structures
typedef struct
{
    NumNode* head;
}
NumStack;

typedef struct
{
    OpNode* head;
}
OpStack;

// TODO: Helper funcs for stack operations
NumStack* create_num_stack(void)
{
    NumStack* stack = malloc(sizeof(NumStack));
    if (!stack)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    stack->head = NULL;
    return stack;
}


// Returns true if passed head from top of stack is null
bool is_numstack_empty(NumStack* stack)
{
    return stack->head = NULL;
}

// Inserts on top of stack
void push_num(NumStack* stack, double value)
{
    NumNode* new_node = malloc(sizeof(NumNode));
    if (!new_node)
    {
        fprintf(stderr, "Not enough memory to create node");
        exit(1);
    }

    // Inserts 'value' in the item field of the stack at the top index
    new_node->value = value;
    new_node->next = stack->head;
    stack->head = new_node->next;
}

// Retrieves on top of stack
double pop_num(NumStack* stack)
{
    if (is_numstack_empty(stack))
    {
        fprintf(stderr, "Stack is empty!\n");
        exit(1);
    }
    // Create temporary node, store top node
    NumNode* temp = stack->head;

    // Store current value at top node
    double value = temp->value;

    // Move current top node to the next node underneath, stored by temp node
    stack->head = temp->next;

    // Free temp node
    free(temp);

    // Return value
    return value;
}

// Only peeks at whatever value on top of stack
double peek_num(NumStack* stack)
{
    if (is_numstack_empty(stack))
    {
        fprintf(stderr, "Stack is empty!\n");
        exit(1);
    }
    NumNode* temp = stack->head;
    double value = temp->value;
    free(temp);
    return value;
}

// Free stack loaded onto memory
void free_numstack(NumStack* stack)
{
    NumNode* temp_node;
    NumNode* current_node = stack->head;
    while (current_node != NULL)
    {
        temp_node = current_node;
        current_node = current_node->next;
        free(temp_node);
    }
    stack->head = NULL;
}

OpStack* create_op_stack(void)
{
    OpStack* stack = malloc(sizeof(OpStack));
    if (!stack)
    {
        fprintf(stderr, "Failed to allocate memory!\n");
        exit(1);
    }
    stack->head = NULL;
    return stack;
}

bool is_opstack_empty(OpStack* stack)
{
    return stack->head == NULL;
}

void push_op(OpStack* stack, char op)
{
    OpNode* op_node = malloc(sizeof(OpNode));
    if (!op_node)
    {
        fprintf(stderr,"Failed to allocate memory");
        exit(1);
    }

    op_node->op = op;
    op_node->next = stack->head;
    stack->head = op_node;
}

char pop_op(OpStack* stack)
{
    if (is_opstack_empty(stack))
    {
        fprintf(stderr, "Stack is empty!\n");
        exit(1);
    }
    OpNode* temp = stack->head;
    char op = temp->op;
    stack->head = temp->next;
    free(temp);
    return op;
}

char peek_op(OpStack* stack)
{
    if (is_opstack_empty(stack))
    {
        fprintf(stderr, "Stack is empty!\n");
        exit(1);
    }
    return stack->head->op;
}

void free_opstack(OpStack* stack)
{
    OpNode* current = stack->head;
    while (current)
    {
        OpNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

// TODO: Helper funcs to get operator precedence
int get_prec(char op)
{
    switch (op)
    {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

bool lower_or_equal_prec(char x, char y)
{
    return get_prec(x) <  get_prec(y) ||
           get_prec(x) == get_prec(y);
}
// TODO: Helper funcs to check associative property
bool is_right_associative(char op)
{
    return op == '^';
}

bool is_left_associative(char op)
{
    return op != '^';
}
// TODO: Helper func if char is an operator
bool is_operator(char c)
{
    return c == '+' || '-' || '*' || '/' || "^";
}

// TODO: Func to convert infix to postfix
bool infix_to_postfix(char* infix, char* postfix)
{
    // Get length of infix equation
    int len = strlen(infix);

    // Create resultant string and counter
    char result[len + 1];
    int j = 0;

    // Create OpStack for holding operators
    OpStack* stack = create_op_stack();

    // Iterate over each
    for (int i = 0; i < len; i++)
    {
        char c = infix[i];

        // If c is an operand, append to result
        if (isalnum(c))
        {
            result[j++] = c;
        }

        // If c is '(', push onto stack
        else if (c == '(')
        {
            push_op(stack, c);
        }

        // If c is ')',
        else if (c == ')')
        {
            // pop and add to string from the stack until opening parenthesis is found
            while (!is_opstack_empty(stack) && peek_op(stack) != '(')
            {
                result[j++] = pop_op(stack);
            }
            (void) pop_op(stack);
        }

        // If c is an operator
        else if (is_operator(c))
        {
            while (!is_opstack_empty(stack) && lower_or_equal_prec(c, peek_op(stack)))
            {
                result[j++] = pop_op(stack);
            }
            push_op(stack, c);
        }
    }

    // Pop all remaining in the stack
    while (!is_opstack_empty(stack))
    {
        result[j++] = pop_op(stack);
    }

    result[j] = '\0';
    strcpy(postfix, result);

    free_opstack(stack);

    return true;
}

bool evalPostfix(char* postfix, double* result)
{
    // TODO: Implement postfix evaluation here
    // - Use stack for operands
    // - Push numbers onto stack
    // - Pop operands when operator is found, apply, push result back
    // - Handle division by zero
    // Return false if invalid
    return false; // placeholder
}
