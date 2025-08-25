#include<stdio.h>
#include<math.h>

int main(){
    int a,r,s,o;
    
    printf("Enter a =");
    scanf("%d",&a);
    s=0;
    o=a;
    while (a!=0)
    {
        r=a%10;
        s=s+(r*r*r);
        a=a/10;
        // printf("%d\n",s);
    }
    
    
    if (s==o)
    {
        printf("armstrong");
    }else{
        printf("Not armstrong");
    }
    
    return 0;

}