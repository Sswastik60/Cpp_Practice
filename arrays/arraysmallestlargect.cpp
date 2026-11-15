#include <iostream>
using namespace std;
#include <limits.h>


int large(int arr[],int n){
    int large=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>large)
        {
            large=arr[i];
        }
        else{
            continue;
        }
    }
    return large;
}

int small(int arr[],int n){
    int small= INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < small)
        {
            small=arr[i];
        }
        // else{
        //     continue;
        // }
    }
    return small;
}
// better way would be to use the min() function and max() function.

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int largest=large(arr,n);
    cout<<"Largest number: "<<largest << endl;
    int smallest=small(arr,n);
    cout<<"Smallest number: "<<smallest << endl;
    return 0;

}