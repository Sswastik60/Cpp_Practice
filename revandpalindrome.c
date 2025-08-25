#include <stdio.h>

int main(){
    int n;
    int onum;
    printf("Enter a number = ");
    scanf("%d",&n);
    onum = n;
    int rev = 0;
    while (n!=0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10; 
    }
    printf("Reverse is = %d \n",rev);

    if (rev == onum)
    {
        printf("Palindrome \n");
    }
    else printf("Not Palindrome \n");
    return 0;
}
