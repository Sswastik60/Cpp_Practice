#include <stdio.h >

int main(){
    float r,area,vol;
    printf("Enter radius:");
    scanf("%f",&r);
    vol=1.33*3.14*r*r*r;
    area=4*3.14*r*r;
    printf("Area =%f ,Volume= %f",area,vol);
    return 0;
}