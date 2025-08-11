#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

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

// Remove whitespaces
void remove_spaces(char* s)
{
    char* d = s;
    do
    {
        while (*d == ' ')
        {
            ++d;
        }
    } while (*s++ = *d++);
}

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
    return stack->head == NULL;
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
    stack->head = new_node;
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

int get_prec(char op)
{
    switch (op)
    {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        case '!': return 4;
        case 's': case 'c': case 't': case 'q': case 'i': 5;
        default: return -1;
    }
}

bool lower_or_equal_prec(char x, char y)
{
    return get_prec(x) <  get_prec(y) ||
           get_prec(x) == get_prec(y);
}

bool is_op(char c)
{
    switch (c)
    {
        // Standard operators
        case '+': case '-': case '*': case '/': case '^': return true;
        default: return false;
    }
}

bool is_func(char c)
{
    switch (c)
    {
        // sin, cos, tan, sqrt, isqrt
        case 's': return true;
        case 'c': return true;
        case 't': return true;
        case 'q': return true;
        case 'i': return true;

        // positive, negative
        case 'p': return true;
        case 'm': return true;
        case '!': return true;
        default: return false;
    }
}

double eval_expr(double x, double y, char op)
{
    switch (op)
    {
        case '+': return y + x;
        case '-': return y - x;
        case '*': return y * x;
        case '/': return y / x;
        case '^': return pow(y,x);
    }
}

double deg_to_rad(double deg)
{
    return deg * M_PI / 180.0;
}

unsigned int isqrt(unsigned int n)
{
    int L = 0, M = 0, H = n;
    while (L <= H)
    {
        M = (L + H) / 2;
        if ((M*M) == n) return M;
        else if ((M*M) < n) L=M+1;
        else H=M-1;
    }
    return H;
}

double fact(double x)
{
    double ret = 1;
    while (x) ret *= x--;
    return ret;
}

double eval_fexpr(double x, char op)
{
    switch (op)
    {
        case 's': return sin(deg_to_rad(x));
        case 'c': return cos(deg_to_rad(x));
        case 't': return tan(deg_to_rad(x));
        case 'q': return sqrt(x);
        case 'i': return isqrt(x);
        case '!': return fact(x);
        case 'm': return x * -1;
        case 'p': return x * 1;
    }
}

bool infix_to_postfix(char* infix, char* postfix)
{
    // Remove whitespaces first
    remove_spaces(infix);

    // Get length of infix equation
    int len = strlen(infix);

    // Create resultant string and counter
    char* result = malloc(len * 3);
    if (!result)
    {
        fprintf(stderr, "Failed to allocate memory for [result]\n");
        exit(1);
    }
    int j = 0;

    // Create OpStack for holding operators
    OpStack* stack = create_op_stack();
    if (!stack)
    {
        fprintf(stderr, "Failed to allocate memory for operator stack\n");
        exit(1);
    }

    // Iterate over each
    for (int i = 0; i < len; i++)
    {
        char c = infix[i];

        // If c is an operand, append to result
        if (isdigit(c) || c == '.')
        {
            // Instantiate token
            char token[64];
            int index = 0;

            while (i < len && (isdigit(infix[i]) || infix[i] == '.'))
            {
                // Iterate over each character until an operand is found
                token[index++] = infix[i];
                i++;
            }
            token[index] = '\0';

            for (int k = 0; token[k] != '\0'; k++)
            {
                // Append token onto result
                result[j++] = token[k];
            }
            // Add whitespace
            result[j++] = ' ';
            // Decrement for loop counter
            i--;
        }

        // If c is '(', push onto stack
        else if (c == '(')
        {
            push_op(stack, c);
        }

        // func with higher precedence
        else if (c == '!')
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
                result[j++] = ' ';
            }
            (void) pop_op(stack);

            if (!is_opstack_empty(stack) && is_func(peek_op(stack)))
            {
                result[j++] = pop_op(stack);
                result[j++] = ' ';
            }
        }

        // If c is an operator
        else if (is_op(c))
        {
            if (is_op(infix[i - 1]) && (infix[i-1] != '+' || infix[i-1] != '-'))
            {
                fprintf(stderr, "Operator placed in place I don't want it to be!\n");
                exit(1);
            }

            // Unary conditional
            if (i == 0 || is_op(infix[i-1]) || infix[i-1] == '(')
            {
                if (c == '+')
                {
                    infix[i] = 'p';
                }

                if (c == '-')
                {
                    infix[i] = 'm';
                }
            }

            while (!is_opstack_empty(stack) && lower_or_equal_prec(c, peek_op(stack)))
            {
                // Keep popping from stack and send onto result
                result[j++] = pop_op(stack);
                result[j++] = ' ';
            }
            // Append operator onto stack
            push_op(stack, c);
        }

        // Functional Operators
        // If the next n chars correspond to a func(), push a func op onto the stack and skip over to '('
        else if (strncmp(&infix[i], "sin", 3) == 0)
        {
            char f_op = 's';
            push_op(stack, f_op);
            i += 2;
        }

        else if (strncmp(&infix[i], "cos", 3) == 0)
        {
            char f_op = 'c';
            push_op(stack, f_op);
            i += 2;
        }

        else if (strncmp(&infix[i], "tan", 3) == 0)
        {
            char f_op = 't';
            push_op(stack, f_op);
            i += 2;
        }

        else if (strncmp(&infix[i], "sqrt", 4) == 0)
        {
            char f_op = 'q';
            push_op(stack, f_op);
            i += 3;
        }

        else if (strncmp(&infix[i], "isqrt", 5) == 0)
        {
            char f_op = 'i';
            push_op(stack, f_op);
            i += 4;
        }

        // Invalid character case
        else {
            fprintf(stderr, "Invalid character!\n");
            free_opstack(stack);
            free(result);
            return false;
        }
    }

    // Pop all remaining in the stack
    while (!is_opstack_empty(stack))
    {
        result[j++] = pop_op(stack);
        result[j++] = ' ';
    }

    // Terminate result string
    result[j] = '\0';

    // Copy result onto postfix pointer
    strcpy(postfix, result);

    // Free memory
    free_opstack(stack);
    free(result);

    return true;
}

bool eval_postfix(char* postfix, double* result)
{
    NumStack* stack = create_num_stack();
    if (!stack)
    {
        fprintf(stderr, "Failed to allocate memory for stack!\n");
        exit(1);
    }
    int len = strlen(postfix);
    int j = 0;

    for (int i = 0; i < len; i++)
    {
        char c = postfix[i];

        // Push onto stack if operand
        if (isdigit(c) || c == '.')
        {
            // Instantiate token
            char token[64];
            int index = 0;

            while (i < len && (isdigit(postfix[i]) || postfix[i] == '.'))
            {
                // Iterate over each character until an operand is found
                token[index++] = postfix[i];
                i++;
            }
            token[index] = '\0';

            // Push onto stack the tokenised double
            push_num(stack, atof(token));
            // Decrement for loop counter
            i--;
        }

        else if (is_op(c))
        {
            double x = 0.0;
            double y = 0.0;
            double value = 0.0;

            if (!is_numstack_empty(stack))
            {
                x = pop_num(stack);
            }

            if (!is_numstack_empty(stack))
            {
                y = pop_num(stack);
            }

            value = eval_expr(x, y, c);
            push_num(stack, value);
        }

        else if (is_func(c))
        {
            double x = 0.0;
            double value = 0.0;

            if (!is_numstack_empty(stack))
            {
                x = pop_num(stack);
            }

            value = eval_fexpr(x, c);
            push_num(stack, value);
        }

        else if (isspace(c)) continue;
    }
    *result = pop_num(stack);
    free_numstack(stack);

    return true;
}
