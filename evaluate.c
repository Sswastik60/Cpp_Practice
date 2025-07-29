#include <stdio.h >

int main(){
    int a,b,c,d;
    a=30;
    b=10;
    c=5;
    d=15;
    printf("ans1=%d\n",(a+b)*c/d);
    printf("ans2=%d\n",((a+b)*c)/d);
    printf("ans3=%d\n",a+(b*c)/d);
    printf("ans4=%d\n",(a+b)*(c/d));
    return 0;
}