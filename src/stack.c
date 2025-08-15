/*
*   Implementation of stack using linked lists as well as stack functions
*/
#include "helpers.h"
#include "stack.h"

typedef struct num_node
{
    double value;
    struct num_node* next;
} NumNode;

typedef struct op_node
{
    char op;
    struct op_node* next;
} OpNode;


NumStack* create_num_stack(void)
{
    NumStack* stack = malloc(sizeof(NumStack));
    if (!stack)
    {
        fprintf(stderr, "%s\n", ERR_STACK_MEMORY);
        exit(1);
    }
    stack->head = NULL;
    return stack;
}

bool is_numstack_empty(NumStack* stack)
{
    return stack->head == NULL;
}

void push_num(NumStack* stack, double value)
{
    NumNode* new_node = malloc(sizeof(NumNode));
    if (!new_node)
    {
        fprintf(stderr, "%s\n", ERR_NODE_MEMORY);
        exit(1);
    }
    new_node->value = value;
    new_node->next = stack->head;
    stack->head = new_node;
}

double pop_num(NumStack* stack)
{
    if (is_numstack_empty(stack))
    {
        fprintf(stderr, "%s\n", ERR_STACK_EMPTY);
        return 0.0f;
    }
    NumNode* temp = stack->head;
    double value = temp->value;
    stack->head = temp->next;
    free(temp);
    return value;
}

double peek_num(NumStack* stack)
{
    if (is_numstack_empty(stack))
    {
        fprintf(stderr, "%s\n", ERR_STACK_EMPTY);
        return 0.0f;
    }
    return stack->head->value;
}

void free_numstack(NumStack* stack)
{
    NumNode* current = stack->head;
    while (current)
    {
        NumNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

OpStack* create_op_stack(void)
{
    OpStack* stack = malloc(sizeof(OpStack));
    if (!stack)
    {
        fprintf(stderr,"%s\n",ERR_STACK_MEMORY);
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
        fprintf(stderr,"%s\n",ERR_STACK_MEMORY);
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
        fprintf(stderr,"%s\n", ERR_STACK_EMPTY);
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
        fprintf(stderr,"%s\n",ERR_STACK_EMPTY);
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
