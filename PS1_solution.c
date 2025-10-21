#include <stdio.h>

struct student {
    int Rno;
    char Name[50];
    float attendancePercentage;
    float marks[3];
    float averagemarks;
    char grade;
};

int main() {
    int n, topper = 0;
    float highestmarks = 0.0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student stu[n];

    for (int i = 0; i < n; i++) {
        printf("\n---------------------Enter the details of student %d---------------------\n", i + 1);
        
        printf("Enter Roll number: ");
        scanf("%d", &stu[i].Rno);
        
        printf("Enter Name: ");
        scanf(" %[^\n]", stu[i].Name); 
        
        printf("Enter Attendance Percentage: ");
        scanf("%f", &stu[i].attendancePercentage);
        
        for (int j = 0; j < 3; j++) {
            printf("Enter marks in subject %d: ", j + 1);
            scanf("%f", &stu[i].marks[j]);
        }


        stu[i].averagemarks = 0;
        for (int j = 0; j < 3; j++) {
            stu[i].averagemarks += stu[i].marks[j];
        }
        stu[i].averagemarks /= 3.0;


        if (stu[i].averagemarks >= 90)
            stu[i].grade = 'A';
        else if (stu[i].averagemarks >= 75)
            stu[i].grade = 'B';
        else if (stu[i].averagemarks >= 60)
            stu[i].grade = 'C';
        else if (stu[i].averagemarks >= 40)
            stu[i].grade = 'D';
        else
            stu[i].grade = 'F';


        if (stu[i].averagemarks > highestmarks) {
            highestmarks = stu[i].averagemarks;
            topper = i;
        }
    }

    printf("\n---------- STUDENT DETAILS ----------\n");
    for (int i = 0; i < n; i++) {
        printf("\nRoll number: %d", stu[i].Rno);
        printf("\nName: %s", stu[i].Name);
        printf("\nAttendance Percentage: %.2f", stu[i].attendancePercentage);
        printf("\nAverage Marks: %.2f", stu[i].averagemarks);
        printf("\nGrade achieved: %c\n", stu[i].grade);
    }

    printf("\n---------- SHORTAGE LIST (Attendance < 75%) ----------\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (stu[i].attendancePercentage < 75.0) {
            printf("%d - %s (%f)\n", stu[i].Rno, stu[i].Name, stu[i].attendancePercentage);
            found = 1;
        }
    }
    if (!found)
        printf("No students have attendance shortage.\n");


    printf("\n---------- TOPPER ----------\n");
    printf("Roll number: %d\n", stu[topper].Rno);
    printf("Name: %s\n", stu[topper].Name);
    printf("Average Marks: %f\n", stu[topper].averagemarks);
    printf("Grade achieved: %c\n", stu[topper].grade);

    return 0;
}
