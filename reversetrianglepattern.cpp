#include <iostream>
using namespace std;

int main(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j > 0 ; j-- )
        {
            cout << j;
        }
        cout << endl;
        
    }
    

    return 0;
}
