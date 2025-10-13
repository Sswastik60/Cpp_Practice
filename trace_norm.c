#include <stdio.h>
#include <math.h>

int main() {
    int n, m;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of columns: ");
    scanf("%d", &m);
    int arr[n][m];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    if (n != m) {
        printf("The matrix is not symmetric (not a square matrix).\n");
        return 0;
    }
    int trace=0;
    int sos=0,norm=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sos+=pow(arr[i][j],2);
            if (i==j)
            {
                trace+=arr[i][j];
            }
        }
        
    }
    norm=sqrt(sos);
    printf("Trace of the matrix is:%d",trace);
    printf("Norm of the matrix is:%d",norm);
    return 0;
}
