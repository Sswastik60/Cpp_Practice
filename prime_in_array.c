#include <stdio.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Prime numbers: ");
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        int isPrime = 1;

        if(num < 2) {
            isPrime = 0;
        } else {
            for(int j = 2; j <= num / 2; j++) {   // using n/2
                if(num % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }

        if(isPrime)
            printf("%d ", num);
    }
    printf("\n");
    return 0;
}
