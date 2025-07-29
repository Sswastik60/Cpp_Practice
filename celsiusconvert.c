#include <stdio.h >

int main(){
    float a,b;
    printf("Enter temperature in fahrenheit:");
    scanf("%f",&a);
    b=0.55*(a-32);
    printf("Fahrenheit =%f centigrade= %f",a,b);
    return 0;
}