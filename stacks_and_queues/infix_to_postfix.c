```c
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Function prototypes
int IsOperator(char c);
int IsOperand(char c);
int precedence(char op);
int hasHigherOrEqualPrecedence(char op1, char op2);
void convert(char infix[], char postfix[]);

// Check if character is operator
int IsOperator(char c)
{
    return (c == '+' || c == '-' ||
            c == '*' || c == '/' || c == '^');
}

// Check if character is operand
int IsOperand(char c)
{
    return ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'));
}

// Return precedence value
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

// Check precedence and associativity
int hasHigherOrEqualPrecedence(char op1, char op2)
{
    int p1 = precedence(op1);
    int p2 = precedence(op2);

    if (p1 == p2)
    {
        if (op1 == '^')       // ^ is right-associative
            return 0;

        return 1;             // Other operators are left-associative
    }

    return (p1 > p2);
}

// Convert infix to postfix
void convert(char infix[], char postfix[])
{
    char stack[MAX_SIZE];
    int top = -1;
    int i = 0;
    int j = 0;
    char ch;

    // Add '(' to stack and ')' to infix
    // Sentinel trick
    stack[++top] = '(';
    strcat(infix, ")");

    while ((ch = infix[i++]) != '\0')
    {
        // Ignore spaces
        if (ch == ' ')
        {
            continue;
        }

        // Left parenthesis
        else if (ch == '(')
        {
            stack[++top] = ch;
        }

        // Operand
        else if (IsOperand(ch))
        {
            postfix[j++] = ch;
        }

        // Operator
        else if (IsOperator(ch))
        {
            while (top != -1 &&
                   hasHigherOrEqualPrecedence(stack[top], ch))
            {
                postfix[j++] = stack[top--];
            }

            stack[++top] = ch;
        }

        // Right parenthesis
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }

            // Remove '('
            top--;
        }
    }

    postfix[j] = '\0';
}

// Main function
int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    int ch;

    do
    {
        printf("Enter an infix expression: ");

        fgets(infix, MAX_SIZE, stdin);

        // Remove newline
        infix[strcspn(infix, "\n")] = '\0';

        convert(infix, postfix);

        printf("\nInfix   : %s", infix);
        printf("\nPostfix : %s", postfix);

        printf("\n\nDo you want to enter another expression? (1/0): ");
        scanf("%d", &ch);

        getchar();   // Clear newline from input buffer

    } while (ch == 1);

    return 0;
}
```
