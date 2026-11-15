#include <iostream>
using namespace std;

int minimum(int a,int b){
    if (a>b)
    {
        return a;
    }
    else if (a==b)
    {
        return a;
    }
    else return b;
}


int main() {
    int x,y;
    cout << "Enter two numbers" << endl ;
    cin >> x;
    cin >> y;
    cout << "The bigger no is = " << minimum(x,y);
    return 0;
}