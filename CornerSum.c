#include <stdio.h>

int CornerSum(int rows, int cols, int mat[10][10]) {//general assumption 
    if (rows < 2 || cols < 2)//corner doesnt form
        return 0;

    int sum = mat[0][0] + mat[0][cols - 1] + mat[rows - 1][0] + mat[rows - 1][cols - 1];
    return sum;
}

int main() {
    int rows, cols, mat[10][10];

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);

    int sum = CornerSum(rows, cols, mat);
    printf("Sum of four corners = %d\n", sum);

    return 0;
}
