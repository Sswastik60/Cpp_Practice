#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int exponent;
    struct node *next;
};

struct node *create_polynomial(float coeff, int exponent)
{
    struct node *temp = malloc(sizeof(struct node));

    temp->coeff = coeff;
    temp->exponent = exponent;
    temp->next = NULL;

    return temp;
}

void print_polynomial(struct node *poly)
{
    struct node *temp = poly;

    while (temp != NULL)
    {
        printf("%.2fx^%d", temp->coeff, temp->exponent);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    printf("\n");
}

void addition_of_polynomial(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *tail = NULL;
    struct node *newNode;
    
    struct node *p1 = head1;
    struct node *p2 = head2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exponent == p2->exponent)
        {
            newNode = create_polynomial(
                p1->coeff + p2->coeff,
                p1->exponent
            );

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exponent > p2->exponent)
        {
            newNode = create_polynomial(
                p1->coeff,
                p1->exponent
            );

            p1 = p1->next;
        }
        else
        {
            newNode = create_polynomial(
                p2->coeff,
                p2->exponent
            );

            p2 = p2->next;
        }

        if (result == NULL)
        {
            result = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    /* Add remaining terms of p1 */
    while (p1 != NULL)
    {
        newNode = create_polynomial(p1->coeff, p1->exponent);

        if (result == NULL)
        {
            result = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        p1 = p1->next;
    }

    /* Add remaining terms of p2 */
    while (p2 != NULL)
    {
        newNode = create_polynomial(p2->coeff, p2->exponent);

        if (result == NULL)
        {
            result = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        p2 = p2->next;
    }

    printf("Result: ");
    print_polynomial(result);
}

int main()
{
    struct node *poly1 = create_polynomial(5.0, 3);
    poly1->next = create_polynomial(-3.0, 2);

    struct node *poly2 = create_polynomial(-3.0, 2);
    poly2->next = create_polynomial(2.0, 1);

    printf("Polynomial 1: ");
    print_polynomial(poly1);

    printf("Polynomial 2: ");
    print_polynomial(poly2);

    addition_of_polynomial(poly1, poly2);

    return 0;
}