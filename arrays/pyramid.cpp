#include <iostream>
using namespace std;

int main()
{
    int spc = 3 ;
    for (int i = 1; i < 5; i++)
    {
        // For spaces
        for (int j = spc; j >0; j-- )
        {
            cout << " ";
        }
        spc--;
        
        for (int j = 1; j < i+1; j++)
        {
            cout << j ;
        }
        cout << endl ;
// third loop will be the other symmetric part
        // for (int j = 1; j < i; j++)
        // {
        //     cout << j ;
        // }
        
    }
    
    return 0;
}
