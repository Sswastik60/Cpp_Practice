#include <stdio.h>
int prime();

int main(){
    int n;
    printf("Enter the number");
    scanf("%d",&n);
    prime(n) == 1? printf("Prime") : printf("not prime");
    return 0;
}

int prime(int k){
    int count = 0;
    for (int i = 2; i < k; i++)
    {
        if (k%i==0)
        {
            count++;
            
        }   
    }
    if (count>0)
    {
       return 0; 
    }else{
        return 1;
    }
    
    
}