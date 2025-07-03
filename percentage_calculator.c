#include <stdio.h>
int percentage(int a, int b, int c);

int main(){
    int a, b, c;
    printf("Enter maths marks/100: ");
    scanf("%d", &a);
    printf("Enter science marks/100: ");
    scanf("%d", &b);
    printf("Enter Sanskrit marks/100: ");
    scanf("%d", &c);
    printf("percentage of student is: %d\n", percentage(a,b,c));
    return 0;
}

int percentage(int a, int b, int c) {
    return ((a + b + c) / 3);   
}