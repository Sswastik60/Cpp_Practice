#include <stdio.h>

long Fact(int n) {//used long cause factorial can result in a large amount of output
    if (n == 0 || n == 1)
        return 1;
    else
        return n * Fact(n - 1);
}

int main() {
    int n, r;
    long nCr;

    printf("Enter value of n and r: ");
    scanf("%d %d", &n, &r);

    if (r > n) {
        printf("Invalid input! r cannot be greater than n.\n");
    } else {
        nCr = Fact(n) / (Fact(r) * Fact(n - r));
        printf("nCr = %ld\n", nCr);
    }

    return 0;
}
