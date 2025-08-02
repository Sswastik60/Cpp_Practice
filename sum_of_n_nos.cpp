#include <iostream>
using namespace std;

int sum(int n){
    int sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        sum=sum+i;
    }
    return sum;
}

int main() {
    int N;
    cout << "Enter the n value " << endl ;
    cin >> N;
    cout << "Sum is = " << sum(N); 
    return 0;
}