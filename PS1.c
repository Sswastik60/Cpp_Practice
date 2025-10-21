#include <stdio.h>

// Structure to store student details
struct Student {
    int roll;
    char name[50];
    float attendance;
    float marks[3];
    float average;
    char grade;
};

int main() {
    int n, topperIndex = 0;
    float highestAvg = 0.0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Input details
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);  // Read string with spaces

        printf("Enter Attendance Percentage: ");
        scanf("%f", &s[i].attendance);

        printf("Enter marks in 3 subjects:\n");
        for (j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);
        }

        // Calculate average marks
        s[i].average = 0;
        for (j = 0; j < 3; j++) {
            s[i].average += s[i].marks[j];
        }
        s[i].average /= 3.0;

        // Assign grade based on average marks
        if (s[i].average >= 90)
            s[i].grade = 'A';
        else if (s[i].average >= 75)
            s[i].grade = 'B';
        else if (s[i].average >= 60)
            s[i].grade = 'C';
        else if (s[i].average >= 40)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';

        // Find topper
        if (s[i].average > highestAvg) {
            highestAvg = s[i].average;
            topperIndex = i;
        }
    }

    // Display all student details
    printf("\n===== CLASS DETAILS =====\n");
    for (i = 0; i < n; i++) {
        printf("\nRoll No: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nAttendance: %.2f%%", s[i].attendance);
        printf("\nAverage Marks: %.2f", s[i].average);
        printf("\nGrade: %c\n", s[i].grade);
    }

    // Generate shortage list
    printf("\n===== SHORTAGE LIST (Attendance < 75%) =====\n");
    int found = 0;
    for (i = 0; i < n; i++) {
        if (s[i].attendance < 75.0) {
            printf("%d - %s (%.2f%%)\n", s[i].roll, s[i].name, s[i].attendance);
            found = 1;
        }
    }
    if (!found)
        printf("No students with attendance shortage.\n");

    // Display class topper
    printf("\n===== CLASS TOPPER =====\n");
    printf("Roll No: %d\nName: %s\nAverage Marks: %.2f\nGrade: %c\n",
           s[topperIndex].roll, s[topperIndex].name, s[topperIndex].average, s[topperIndex].grade);

    return 0;
}
