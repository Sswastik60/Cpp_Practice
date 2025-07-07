#include <iostream>
using namespace std;

int main(){
    int a,b;
    cout << "Enter a" << endl;
    cin >> a;
    cout << "Enter b" << endl;
    cin >> b;
    int sum = a+b;
    cout << "sum = " << sum << endl;
    cout << "product = " << a*b <<endl ;
    cout << "remainder = " << a%b <<endl ;
    cout << "division = " << a/b <<endl;
    cout << "Thank you" << endl;

    return 0;
}