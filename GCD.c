#include <stdio.h>

int GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    printf("GCD of %d and %d is %d\n", x, y, GCD(x, y));

    return 0;
}
