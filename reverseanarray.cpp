#include <iostream>
using namespace std;

void revArray(int arr[],int sz){
    int start=0;
    int end=sz-1;
    if (sz%2==0)
    {
        while (start < end)
         
            int temp;
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        } 
    }
    else
    {
        while (start!=end)
        {
            int temp;
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp; 
            start++;
            end--;
        }   
    }

    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int sz=6;
    revArray(arr,sz);//here arr points to the address of the array and hence we are actually invoking the pass by reference concept

}