#include <stdio.h>
#include <string.h>

int main() {
    int N, i, j, k;
    char STUDENT_NAMES[100][50];
    char STUDENTS_NAME_SORTED[100][50];
    char temp[50];

    printf("Enter number of students: ");
    scanf("%d", &N);

    getchar(); // <-- Add this line to consume leftover newline very very important *****************

    for(i = 0; i < N; i++) {
        printf("Enter name of student %d: ", i + 1);
        gets(STUDENT_NAMES[i]);
    }

    for(i = 0; i < N; i++) {
        strcpy(STUDENTS_NAME_SORTED[i], STUDENT_NAMES[i]);
    }

    for(i = 0; i < N - 1; i++) {
        for(j = i + 1; j < N; j++) {
            k = 0;
            while (STUDENTS_NAME_SORTED[i][k] != '\0' && STUDENTS_NAME_SORTED[j][k] != '\0') {
                if(STUDENTS_NAME_SORTED[i][k] < STUDENTS_NAME_SORTED[j][k]) {
                    break;
                } else if(STUDENTS_NAME_SORTED[i][k] > STUDENTS_NAME_SORTED[j][k]) {
                    strcpy(temp, STUDENTS_NAME_SORTED[i]);
                    strcpy(STUDENTS_NAME_SORTED[i], STUDENTS_NAME_SORTED[j]);
                    strcpy(STUDENTS_NAME_SORTED[j], temp);
                    break;
                }
                k++;
            }
        }
    }

    printf("\nSorted student names:\n");
    for(i = 0; i < N; i++) {
        printf("%d. %s\n", i + 1, STUDENTS_NAME_SORTED[i]);
    }
    return 0;
}
