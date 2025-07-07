#include<stdio.h>

int main(){
    int n = 5;
    int arr[5]={1,2,3,4,5};
    for (int i = 0; i < n/2; i++)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
        
    }

    for (int i = 0; i <5 ; i++)
    {
        printf("%d \t",arr[i]);
    }
    

    printf("\n");
    
    return 0;
}