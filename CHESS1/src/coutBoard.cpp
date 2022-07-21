#include "coutBoard.h"
#include <string>
#include <iostream>

using namespace std ;

void coutBoard(string aBoard[8][8]){
    for(int k=0; k < 8; k++)
    {
        for(int j=0; j < 8; j++)
        {
            cout<<aBoard[k][j] << "\t";
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
}
