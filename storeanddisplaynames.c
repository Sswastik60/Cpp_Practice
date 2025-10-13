#include <stdio.h>

int main() {
    int N, i;
    char STUDENT_NAMES[100][50];

    printf("Enter number of students: ");
    scanf("%d", &N);

    for(i = 0; i < N; i++) {
        printf("Enter name of student %d:\n", i + 1);
        gets(STUDENT_NAMES[i]); // Unsafe but matches request
    }

    printf("Student names:\n");
    for(i = 0; i < N; i++) {
        puts(STUDENT_NAMES[i]); // Unsafe but matches request
    }
    return 0;
}
