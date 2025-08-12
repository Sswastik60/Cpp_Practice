#include <stdio.h>
#include <math.h>

int main(){
    float a,b,c;
    int cnum;
    a=1;
    b=3;
    c=2;
    float d = pow(b,2)-4*a*c;
    float df = pow(d,0.5);
    float r1 = (-1*b+df)/(2*a);
    float r2 = (-1*b-df)/(2*a);

    if (d<0)
    {
        cnum = 1;
    }
    else if (d == 0)
    {
        cnum = 2;
    }
    else cnum = 3;

    printf("Roots are %f  ,  %f \n",r1,r2);
    
    switch (cnum)
    {
    case 1:
        printf("Imaginary roots");
        break;
    
    case 2:
        printf("Equal roots");
        break;
    
    case 3:
        printf("Real roots");
        break;

    default:
        printf("Invalid");
        break;
    }
    return 0;
    
}