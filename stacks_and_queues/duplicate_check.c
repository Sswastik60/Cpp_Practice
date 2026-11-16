// #include <stdio.h>
// #include <string.h>

// #define MAX_SIZE 100

// int isDuplicate(char s[])
// {
//     char Stack[MAX_SIZE];
//     int top = -1;
//     int n = strlen(s);
//     int i;

//     for (i = 0; i < n; i++)
//     {
//         if (s[i] == ')')
//         {
//             /* Case 1: Empty or duplicate parentheses */
//             if (top != -1 && Stack[top] == '(')
//             {
//                 return 1;
//             }

//             int elementsInside = 0;

//             /* Pop until '(' is found */
//             while (top != -1 && Stack[top] != '(')
//             {
//                 elementsInside++;
//                 top--;
//             }

//             /* Pop the '(' */
//             if (top != -1)
//             {
//                 top--;
//             }

//             /* No valid content inside parentheses */
//             if (elementsInside < 1)
//             {
//                 return 1;
//             }
//         }
//         else
//         {
//             /* Push every other character */
//             Stack[++top] = s[i];
//         }
//     }

//     /* Check for unmatched '(' */
//     while (top != -1)
//     {
//         if (Stack[top] == '(')
//         {
//             return 1;
//         }

//         top--;
//     }

//     return 0;
// }

// int main()
// {
//     char s[MAX_SIZE] = "(((a+(b))+(c+d)))";

//     if (isDuplicate(s))
//     {
//         printf("Expression contains duplicate parenthesis.\n");
//     }
//     else
//     {
//         printf("Expression does not contain duplicate parenthesis.\n");
//     }

//     return 0;
// }
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char expression[MAX];
    char stack[MAX];
    int top = -1;
    int duplicate = 0;

    strcpy(expression, "((a+b))");

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == ')') {
            int hasOperator = 0;

            /* Pop until the matching opening parenthesis */
            while (top != -1 && stack[top] != '(') {
                if (stack[top] == '+' || stack[top] == '-' ||
                    stack[top] == '*' || stack[top] == '/') {
                    hasOperator = 1;
                }

                top--;
            }

            if (top == -1) {
                printf("Unbalanced expression\n");
                return 1;
            }

            /* Remove the opening parenthesis */
            top--;

            if (hasOperator == 0) {
                duplicate = 1;
                break;
            }
        } else {
            stack[++top] = ch;
        }
    }

    if (duplicate)
        printf("Duplicate parentheses found\n");
    else
        printf("No duplicate parentheses\n");

    return 0;
}