#include <iostream>
using namespace std;

int linearsearch(int arr[],int n,int etbs){
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==etbs)
        {
            return i;
        }
    }
    return -1;
    
}

int main(){ 
    int n;
    n=5;
    int arr[n]={1,2,3,4,5};
    int etbs=6;
    int lsresult=linearsearch(arr,n,etbs);
    cout<<"Result : "<< lsresult <<endl;
    return 0;
    
    
}