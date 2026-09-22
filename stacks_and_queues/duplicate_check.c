#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int isDuplicate(char s[])
{
    char Stack[MAX_SIZE];
    int top = -1;
    int n = strlen(s);
    int i;

    for (i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            /* Case 1: Empty or duplicate parentheses */
            if (top != -1 && Stack[top] == '(')
            {
                return 1;
            }

            int elementsInside = 0;

            /* Pop until '(' is found */
            while (top != -1 && Stack[top] != '(')
            {
                elementsInside++;
                top--;
            }

            /* Pop the '(' */
            if (top != -1)
            {
                top--;
            }

            /* No valid content inside parentheses */
            if (elementsInside < 1)
            {
                return 1;
            }
        }
        else
        {
            /* Push every other character */
            Stack[++top] = s[i];
        }
    }

    /* Check for unmatched '(' */
    while (top != -1)
    {
        if (Stack[top] == '(')
        {
            return 1;
        }

        top--;
    }

    return 0;
}

int main()
{
    char s[MAX_SIZE] = "(((a+(b))+(c+d)))";

    if (isDuplicate(s))
    {
        printf("Expression contains duplicate parenthesis.\n");
    }
    else
    {
        printf("Expression does not contain duplicate parenthesis.\n");
    }

    return 0;
}