#include <iostream>
using namespace std;
// floyds triangle pattern

int main(){
    int a = 1;
    for (int i = 1; i <5; i++)
    {
        for (int j = 1; j < i+1 ; j++)
        {
            cout << a << " ";
            a++;
        }
        cout << endl ;
    }
    
    return 0;
}
