#include <stdio.h>

int prime(int start, int end);

int main() {
    int start, end;
    printf("Enter the start: ");
    scanf("%d", &start);
    printf("Enter the end: ");
    scanf("%d", &end);

    prime(start, end);
    return 0;
}

int prime(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (i < 2)   // Numbers less than 2 are not prime
            continue;
        int isPrime = 1;  // Assume i is prime until proven otherwise

        // Check divisibility from 2 to i/2
        for (int k = 2; k <= i / 2; k++) {
            if (i % k == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            printf("%d ", i);
        }
    }
    return 0;
}
