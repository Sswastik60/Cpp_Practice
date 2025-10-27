#include <stdio.h>

int FIB(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return FIB(n - 1) + FIB(n - 2);
}

int main() {
    int n;
    printf("Enter number of Fibonacci terms: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++)
        printf("%d ", FIB(i));

    printf("\n");
    return 0;
}
