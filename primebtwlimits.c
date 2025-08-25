#include <stdio.h>

int main() {
    int l, u;
    printf("Enter lower and upper limits: ");
    scanf("%d %d", &l, &u);

    int a = l;   

    while (a <= u) {   
        if (a >= 2) {  
            int i = 2, count = 0;

            while (i <= a - 1) {
                if (a % i == 0) {
                    count++;
                    break;  
                }
                i++;
            }

            if (count == 0) {
                printf("%d ", a);
            }
        }
        a++;
    }

    return 0;
}
