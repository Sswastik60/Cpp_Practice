#include <stdio.h>
#include <stdlib.h>

void push(char *stack, int *top, char value)
{
    (*top)++;
    stack[*top] = value;
}

void pop(char *stack, int *top)
{
    if (*top != -1)
        (*top)--;
}

int isBalanced(char *expression)
{
    int top = -1;
    char stack[100];
    int i;

    for (i = 0; expression[i] != '\0'; i++)
    {
        char current = expression[i];

        /* Opening brackets */
        if (current == '(' || current == '{' || current == '[')
        {
            push(stack, &top, current);
        }

        /* Closing brackets */
        else if (current == ')' || current == '}' || current == ']')
        {
            /* No opening bracket available */
            if (top == -1)
                return 0;

            char last = stack[top];

            /* Check matching pair BEFORE popping */
            if ((current == ')' && last != '(') ||
                (current == '}' && last != '{') ||
                (current == ']' && last != '['))
            {
                return 0;
            }

            pop(stack, &top);
        }
    }

    /* Stack must be empty */
    return top == -1;
}


int main()
{
    char expression[100];

    printf("Enter an expression: ");
    scanf("%99s", expression);

    if (isBalanced(expression))
        printf("The expression is balanced.\n");
    else
        printf("The expression is not balanced.\n");

    return 0;
}