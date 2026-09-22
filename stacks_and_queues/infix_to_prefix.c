#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int IsOperator(char c);
int IsOperand(char c);
int Precedence(char c);
int isRightAssociative(char c);
void ReverseString(char str[]);
void ReverseAndSwap(char str[]);
void Convert(char infix[], char prefix[]);

int main()
{
    char infix[MAX_SIZE], prefix[MAX_SIZE];
    int ch;

    do
    {
        printf("Enter an infix expression: ");
        scanf("%s", infix);

        Convert(infix, prefix);

        printf("\nPrefix Expression: %s\n", prefix);

        printf("\nDo you want to enter another (1/0)? ");
        scanf("%d", &ch);

    } while (ch == 1);

    return 0;
}

// Check if character is an operator
int IsOperator(char c)
{
    return (c == '+' || c == '-' ||
            c == '*' || c == '/' || c == '^');
}

// Check if character is an operand
int IsOperand(char c)
{
    return ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'));
}

// Return precedence
int Precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;

    if (c == '*' || c == '/')
        return 2;

    if (c == '^')
        return 3;

    return 0;
}

// Right associativity check
// Only ^ is right-associative
int isRightAssociative(char c)
{
    if (c == '^')
        return 1;

    return 0;
}

// Reverse a string
void ReverseString(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Reverse string and swap brackets
void ReverseAndSwap(char str[])
{
    ReverseString(str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
            str[i] = ')';

        else if (str[i] == ')')
            str[i] = '(';
    }
}

// Convert infix to prefix
void Convert(char infix[], char prefix[])
{
    char stack[MAX_SIZE];
    int top = -1;
    int i = 0, j = 0;
    char ch;

    // Step 1:
    // Reverse infix and swap brackets
    ReverseAndSwap(infix);

    // Step 2:
    // Scan reversed infix
    while ((ch = infix[i++]) != '\0')
    {
        // Ignore spaces
        if (ch == ' ')
            continue;

        // Operand
        if (IsOperand(ch))
        {
            prefix[j++] = ch;
        }

        // Left parenthesis
        else if (ch == '(')
        {
            stack[++top] = ch;
        }

        // Right parenthesis
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                prefix[j++] = stack[top--];
            }

            // Discard '('
            if (top != -1)
                top--;
        }

        // Operator
        else if (IsOperator(ch))
        {
            while (top != -1 &&
                   IsOperator(stack[top]) &&
                   (Precedence(stack[top]) > Precedence(ch) ||
                   (Precedence(stack[top]) == Precedence(ch) &&
                    isRightAssociative(ch))))
            {
                prefix[j++] = stack[top--];
            }

            stack[++top] = ch;
        }
    }

    // Step 3:
    // Pop remaining operators
    while (top != -1)
    {
        prefix[j++] = stack[top--];
    }

    prefix[j] = '\0';

    // Step 4:
    // Reverse result
    ReverseString(prefix);
}