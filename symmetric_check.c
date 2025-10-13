#include <stdio.h>

int main() {
    int n, m;

    // Taking input for rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of columns: ");
    scanf("%d", &m);

    int arr[n][m]; // declaring matrix after getting dimensions

    // Input elements
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // If not square matrix, can't be symmetric
    if (n != m) {
        printf("The matrix is not symmetric (not a square matrix).\n");
        return 0;
    }

    // Check symmetry
    int symmetric = 1; // assume symmetric
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != arr[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric)
            break;
    }

    // Output result
    if (symmetric)
        printf("symmetric.\n");
    else
        printf("not symmetric.\n");

    return 0;
}
