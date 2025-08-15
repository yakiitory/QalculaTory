#include <stdio.h>
#include "helpers.h"
#include "shunting_yard.h"
#include "stack.h"

int main(void)
{
    char infix[MAX_LEN];
    char postfix[MAX_LEN];
    char res_buff[25];

    printf("Enter infix expression: ");
    if (!fgets(infix, sizeof(infix), stdin))
    {
        printf("[ERROR]: Failed to read input.\n");
        return 1;
    }

    infix[strcspn(infix, "\n")] = '\0';

    if (!infix_to_postfix(infix, postfix))
    {
        printf("%s\n", SYNTAX_ERROR);
        return 1;
    }

    printf("Postfix: %s\n", postfix);

    if (!eval_postfix(postfix, res_buff))
    {
        printf("%s\n", SYNTAX_ERROR);
        return 1;
    }

    printf("Result: %s\n", res_buff);
    return 0;
}
