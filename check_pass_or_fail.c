#include<stdio.h>

int main(){
    int marks;
    printf("Enter marks");
    scanf("%d",marks);
    (marks>30)? printf("pass"):printf("fail");//ternary operator
    return 0;
}