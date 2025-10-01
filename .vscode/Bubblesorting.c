#include <stdio.h>

int main(){
    int arr[5]={4,3,6,2,1};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4-i; j++)//n-i-1 for faster execution
        {
            if (arr[j]>arr[j+1])
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            else continue;
        }
        
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}