#include <stdio.h>
struct student
{
    char name[50];
    int rollno;
    float marks[3];
};

int main(){
    float average[3];
    float avg=0;
    struct student s;
    printf("---STUDENT DETAILS---\n");
    for (int i = 0; i < ; i++)
    {
        printf("Name-\n");
        gets(s.name);
        printf("Roll Number-\n");
        scanf("%d",&s.rollno);
        for (int j = 0; i < 3; i++)
        {
            printf("Marks of student %d in subject %d-\n"),i+1,j+1;
            scanf("%d",&s[i].marks[j]);
            avg+=s[i].marks[j];
            average[i]=avg/3;
        }
    }
    printf("Student data display\n");
    for (int i = 0; i < 3; i++)
    {
        {
        printf("Name-\n",s.name);
        printf("Roll Number-\n");
        scanf("%d",&s.rollno);
        for (int j = 0; i < 3; i++)
        {
            printf("Marks of student %d in subject %d-\n"),i+1,j+1;
            scanf("%d",&s[i].marks[j]);
            avg+=s[i].marks[j];
            average[i]=avg/3;
        }
        }
    }
        
    
}

