#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct num_node NumNode;
typedef struct op_node OpNode;

typedef struct
{
    NumNode* head;
} NumStack;

typedef struct
{
    OpNode* head;
} OpStack;

NumStack* create_num_stack(void);
OpStack* create_op_stack(void);

bool is_numstack_empty(NumStack* stack);
bool is_opstack_empty(OpStack* stack);

void push_num(NumStack* stack, double value);
void push_op(OpStack* stack, char op);

double pop_num(NumStack* stack);
char pop_op(OpStack* stack);

double peek_num(NumStack* stack);
char peek_op(OpStack* stack);

void free_numstack(NumStack* stack);
void free_opstack(OpStack* stack);

#endif
