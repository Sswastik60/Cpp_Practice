#include <stdio.h>

int main(){
    int a,b,c;
    printf("Enter 3 nos");
    scanf("%d %d %d",&a,&b,&c);
    if (a>=b && a>=c)
    {
        printf("a is greatest");
    }
    else if (b>= a && b>=c)
    {
        printf("b is greatest");
    }
    else printf("c is greatest");

    // equality check
    if (a==b && b==c)
    {
        printf("All are equal");
    }
    else if (a==b && b!=c)
    {
        printf("a and b are equal");
    }
    else printf("")
    
    
    
    
}