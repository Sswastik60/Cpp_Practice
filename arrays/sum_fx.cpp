#include <iostream>
using namespace std;

int sum(int a,int b){
    return a+b;
}

int main() {
    int x,y;
    cout << "Enter first number" << endl;
    cin >> x ;
    cout << "Enter second number" << endl;
    cin >> y ;
    cout << "Sum is = " << sum(x,y) << endl;
    return 0;
}