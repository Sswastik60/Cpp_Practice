#include <stdio.h>

int main(){
    int a,b,sum,dif,pro,quo;
    printf("Enter two numbers:");
    scanf("%d %d",&a,&b);
    sum=a+b;
    dif=a-b;
    pro=a*b;
    quo=a/b;
    printf("Sum=%d\ndif=%d\npro=%d\nquo=%d\n",sum,dif,pro,quo);
    return 0;
}