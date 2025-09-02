#include <stdio.h>

int main() {
    int num;
    int primeCount = 0, compositeCount = 0;

    do {
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &num);

        if (num == -1)  // exit condition
            break;

        if (num == 1) {
            printf("1 is neither prime nor composite.\n");
        } 
        else if (num > 1) {
            int i = 2, isPrime = 1;   // assume prime
            while (i <= num / 2) {
                if (num % i == 0) {
                    isPrime = 0;      // not prime
                    break;
                }
                i++;
            }

            if (isPrime == 1) {
                primeCount++;
                printf("%d is Prime.\n", num);
            } else {
                compositeCount++;
                printf("%d is Composite.\n", num);
            }
        }

    } while (num != -1);

    printf("\nTotal Prime numbers entered: %d\n", primeCount);
    printf("Total Composite numbers entered: %d\n", compositeCount);

    return 0;
}
