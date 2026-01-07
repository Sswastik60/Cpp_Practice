#include <iostream>
using namespace std;

void swap(string &x, string &y){
    string temp;
    temp=x;
    x=y;
    y=temp;


}

int main(){
    string a, b;
    cout << "Enter 1st word: ";
    cin >> a;
    cout << "Enter 2nd word: ";
    cin >> b;
    cout<< "Before Swap" << &a <<endl;
    cout<< "Before Swap" << &b <<endl;
    swap(a,b);
    // after swapping the address remains same but the values are swapped
    cout<< "After Swap" << &a <<endl;
    cout<< "After Swap" << &b <<endl;
    cout<< "a: " << a << endl;
    cout<< "b: " << b << endl;
    return 0;

}