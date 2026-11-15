#include <iostream>
using namespace std;

int main(){
    char t = 'A';
    for (int i = 1; i < 6; i++)
    {
        
        for (int j = 1; j < i+1; j++)
        {    
            cout << t;
            
        }
        cout << endl;
        
        t++;
    }
    return 0;
}