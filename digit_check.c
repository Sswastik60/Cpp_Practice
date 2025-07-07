#include<stdio.h>

int main(){
    char a;
    printf("Enter a");
    scanf("%c",&a);
    if (a>='0' && a<='9')//use '' quotes for characters and "" for string
    {
        printf("digit");
    }
    else{
        printf("Not digit");
    }
    
    return 0;
}