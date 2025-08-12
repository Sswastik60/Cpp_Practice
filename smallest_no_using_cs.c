#include <stdio.h>

int main(){
    int a,b,c;
    a=1;
    b=2;
    c=3;
    (a<b) ? (a<c ? printf("a is smallest"): printf("c is smallest")) :(b<c ? printf("b is smallest") : printf("c is smallest"));
    return 0;
}