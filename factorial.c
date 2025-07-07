#include <stdio.h>
int fact(int n);

int main(){
    int k;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &k);
    printf("Factorial of %d is: %d\n", k, fact(k));
    return 0;
}

int fact(int n){
    if(n == 0 || n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}