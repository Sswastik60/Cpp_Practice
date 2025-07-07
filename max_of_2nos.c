#include <stdio.h>
int max(int x, int y,int *number);

int main() {
    int a,b;
    int num;
    printf("enter 1st num: ");
    scanf("%d",&a);//&==address
    printf("enter 2nd num: ");
    scanf("%d",&b);
    max(a,b,&num);
    printf("%d",num);      
}

int max(int x, int y,int *number){//*== pointer
    if (x>y)
    {   
        *number = x;
    }
    else{
        *number = y;
    } 
}


