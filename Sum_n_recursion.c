#include<stdio.h>

int sum();

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int a=sum(n);
    printf("Sum of first %d natural numbers is: %d\n", n, a);
    return 0;
}

int sum(int n){
    if(n == 0) {
        return 0;
    } else {
        return n + sum(n - 1);
    }
}