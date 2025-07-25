#include <iostream>
using namespace std;

// Conceptual Program with double inner loops in functioning

int main(){
    for (int i = 1; i < 5; i++)
    {


        // this is for the spaces
        // This is the space loop which is increasing by 1 increment
        for (int j = 1; j <i+1; j++ )
        {
            cout << " ";
        }



        // This is for the numbers which are decreasing each row
        for (int j = 0; j < 5 - i; j++)
        {
            cout << i ;
        }
        
        cout << endl;
    }
    
    return 0 ;
    
}

