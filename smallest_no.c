#include<stdio.h>

int main(){
    int a,b,c;
    printf("Enter a");
    scanf("%d",&a);
    printf("Enter b");
    scanf("%d",&b);
    a>b?printf("%d is smaller",b):printf("%d is smaller",a);
    return 0;
}