#include <stdio.h>
#include "helpers.h"

int main(void)
{
    char infix[MAX_LEN];
    char postfix[MAX_LEN];
    double result;

    printf("Enter infix expression: ");
    if (!fgets(infix, sizeof(infix), stdin))
    {
        printf("[ERROR]: Failed to read input.\n");
        return 1;
    }

    infix[strcspn(infix, "\n")] = '\0';

    if (!infix_to_postfix(infix, postfix))
    {
        printf("Error: Invalid infix expression.\n");
        return 1;
    }

    printf("Postfix: %s\n", postfix);

    if (!evaluate_postfix(postfix, &result))
    {
        printf("Error: Failed to evaluate expression.\n");
        return 1;
    }

    printf("Result: %.6f\n", result);
    return 0;
}
