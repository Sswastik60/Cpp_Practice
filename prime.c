#include <stdio.h>

int prime(int k);

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    prime(n) == 1 ? printf("Prime\n") : printf("Not Prime\n");
    return 0;
}

int prime(int k) {
    if (k < 2)
        return 0; // 0 and 1 are not prime

    for (int i = 2; i < k; i++) {
        if (k % i == 0) {
            return 0; // Not prime
        }
    }
    return 1; // Prime
    //correct logic
    
}
