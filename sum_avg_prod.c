#include <stdio.h>
void fx(int x, int y,int *sum,int *product,int *average);

int main() {
    int x,y;
    x=2;
    y=3;
    int sum,product,average;
    fx(x,y,&sum,&product,&average);
    printf("sum %d,product %d,average %d",sum,product,average);
    return 0;

}

void fx(int x, int y,int *sum,int *product,int *average){
    *sum = x + y;
    *product=x*y;
    *average=(x+y)/2;
}

