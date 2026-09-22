#include <stdio.h>
#include <stdlib.h>

int isBalanced(char *expression)
{
    int top = -1;
    char stack[100];

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char current = expression[i];

        if (current == '(' || current == '{' || current == '[')
        {
            stack[++top] = current;
        }
        else if (current == ')' || current == '}' || current == ']')
        {
            if (top == -1)
                return 0; // Unbalanced

            char last = stack[top--];

            if ((current == ')' && last != '(') ||
                (current == '}' && last != '{') ||
                (current == ']' && last != '['))
            {
                return 0; // Unbalanced
            }
        }
    }

    return top == -1; // Balanced if stack is empty
}

int main()
{
    char expression[100];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression))
        printf("The expression is balanced.\n");
    else
        printf("The expression is not balanced.\n");

    return 0;
}