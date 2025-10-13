#include <stdio.h>

int main() {
    int n, m, p;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &n, &m);
    printf("Enter columns of second matrix: ");
    scanf("%d", &p);
    int a[n][m], b[m][p], c[n][p];
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &b[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    printf("Resultant matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}
