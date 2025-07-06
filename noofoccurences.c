#include<stdio.h>

int main(){
    int arr[5] = {1,2,3,2,2};
    int target = 2;
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (arr [i] == target)
        {
            count ++;
        }   
    }
    printf("%d",count);
    return 0;
}