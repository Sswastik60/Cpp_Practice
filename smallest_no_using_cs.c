#include <stdio.h>

int main(){
    int a,b,c;
    printf("Enter three numbers a,b,c = ");
    scanf("%d %d %d",&a,&b,&c);
    (a<b) ? (a<c ? printf("a is smallest"): printf("c is smallest")) :(b<c ? printf("b is smallest") : printf("c is smallest"));
    return 0;
}