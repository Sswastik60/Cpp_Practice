#include <iostream>
using namespace std;

int main(){
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < i+1 ; j++)
        {
            cout << " _ ";
            cout << j;
        }
        cout << endl; 
    }
    
    
    return 0 ;
    
}

