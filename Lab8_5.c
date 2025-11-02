#include <stdio.h>

// Function returns the number of students whose averages were calculated
int Calculate_Average(int STUDENT_MARK[10][10], int students, int subjects, float AVERAGE[10]) {
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < subjects; j++) {
            sum += STUDENT_MARK[i][j];
        }
        AVERAGE[i] = (float)sum / subjects;
    }
    return students; // returns total count of averages calculated
}

int main() {
    int students, subjects;
    int STUDENT_MARK[10][10];
    float AVERAGE[10];

    printf("Enter number of students: ");
    scanf("%d", &students);

    printf("Enter number of subjects: ");
    scanf("%d", &subjects);

    printf("Enter STUDENT_MARK of %d students (each having %d subjects):\n", students, subjects);
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            scanf("%d", &STUDENT_MARK[i][j]);
        }
    }

    int count = Calculate_Average(STUDENT_MARK, students, subjects, AVERAGE);

    printf("\nAverage STUDENT_MARK of each student:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: %.2f\n", i + 1, AVERAGE[i]);
    }

    return 0;
}
