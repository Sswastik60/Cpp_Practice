#include<stdio.h>

int main(){
    int age;
    printf("Enter age");
    scanf("%d",age);
    (age>=18)? printf("Adult"):printf("Not adult");//ternary operator
    return 0;
}