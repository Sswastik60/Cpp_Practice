#include <stdio.h>
int gcd(int,int,int);
int main(){
    int x,y,n;
    printf("Enter 2 numbers:");
    scanf("%d %d",&x,&y);
    if (x>y){
        n=y;
    }else{
        n=x;
    }
    printf("%d is the gcd",gcd(x,y,n));
    return 0;
}
int gcd(int a,int b,int i){
    if(a%i==0 && b%i==0){
        return i;
    }else gcd(a,b,i-1);
}

