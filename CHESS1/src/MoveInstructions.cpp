#include "MoveInstructions.h"
#include <string>

using namespace std ;

pair<int, int> dest_conv(string nextDest){
    char letter;
    letter = nextDest[0];

    char digiStr;
    digiStr = nextDest[1];

    int line ;
    line = (int) digiStr;
    line -= 48; // ascii to int ('1' = 49 => '1' - 48 = 1
    line--; //start from 0 not 1
    line = 7 - line ; //mettre le plateau à l'endroit

    int col ;
    col = (int) letter;
    col -= 96 ; //ascii to int ('a' = 97 => 'a' - 96 =  1
    col--; // start from 0 not 1

    return make_pair(line,col);
}


pair<int, int> findPiece(string nextPiece, string aBoard[8][8]){
    for(int i = 0; i < 8 ; i++){
        for(int j=0; j < 8 ; j++){
            if(aBoard[i][j].compare(nextPiece)==0){
                    return make_pair(i,j);
            }
        }
    }
}
