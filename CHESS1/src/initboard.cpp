#include "initboard.h"
#include <string>
#include <iostream>
using namespace std;

typedef string (*pointer_to_arrays)[8];

void initBoard(string aBoard[8][8]){

    for(int i = 0 ; i<8 ; i++)
    {
        if(i == 0){
            aBoard[i][0] = "bR1";
            aBoard[i][1] = "bN1";
            aBoard[i][2] = "bB1";
            aBoard[i][3] = "bQ";
            aBoard[i][4] = "bK";
            aBoard[i][5] = "bB2";
            aBoard[i][6] = "bN2";
            aBoard[i][7] = "bR2";
        } else {
        if(i == 1){
            for(int j = 0 ; j<8 ; j++)
            {
                aBoard[i][j] = "bP"+to_string(j);
            }
        } else {
        if(i == 6){
            for(int j = 0 ; j<8 ; j++)
            {
                aBoard[i][j] = "wP"+to_string(j);
            }
        } else {
        if(i == 7){
            aBoard[i][0] = "wR1";
            aBoard[i][1] = "wN1";
            aBoard[i][2] = "wB1";
            aBoard[i][3] = "wQ";
            aBoard[i][4] = "wK";
            aBoard[i][5] = "wB2";
            aBoard[i][6] = "wN2";
            aBoard[i][7] = "wR2";
        } else {

            for(int j = 0 ; j<8 ; j++)
            {
                aBoard[i][j] = "*";
            }
        }
        }
        }
        }

    }
}

void initSpeBoard(string aBoard[8][8]){

    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j<8 ; j++)
        {
            aBoard[i][j] = "*";
        }
    }

    aBoard[0][0] = "wQ" ;
    aBoard[0][5] = "bK" ;
    aBoard[0][7] = "bR2" ;

    aBoard[1][3] = "wB2" ;

    aBoard[2][3] = "bN1" ;
    aBoard[2][4] = "wR1" ;
    aBoard[2][6] = "bP6" ;

    aBoard[3][5] = "bP5" ;
    aBoard[3][6] = "wB1" ;

    aBoard[4][0] = "wP0" ;
    aBoard[4][1] = "bQ" ;

    aBoard[6][5] = "wK" ;

    aBoard[7][7] = "bQ" ;

}

void initFenBoard(string aBoard[8][8],string aFen){
    int line = 0 ;
    int col = 0 ;
    int bRCountInd = 0 ;
    int wRCountInd = 0 ;
    int bNCountInd = 0 ;
    int wNCountInd = 0 ;
    int bBCountInd = 0 ;
    int wBCountInd = 0 ;
    int bPCountInd = 0 ;
    int wPCountInd = 0 ;

    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j<8 ; j++)
        {
            aBoard[i][j] = "*";
        }
    }

    string val ;
    for (int k = 0 ; k < aFen.size() ; k++){
        switch(aFen[k]){

            case '1' :
                col += 1 ;
                break;

            case '2' :
                col += 2 ;
                break;

            case '3' :
                col += 3 ;
                break;

            case '4' :
                col += 4 ;
                break;

            case '5' :
                col += 5 ;
                break;

            case '6' :
                col += 6 ;
                break;

            case '7' :
                col += 7 ;
                break;

            case '8' :
                col += 8 ;
                break;

            case 'r' :
                bRCountInd += 1 ;
                aBoard[line][col] = "bR" + to_string(bRCountInd);
                col += 1 ;
                break;

            case 'R' :
                wRCountInd += 1 ;
                aBoard[line][col] = "wR" + to_string(wRCountInd);
                col+= 1 ;
                break;

            case 'b' :
                bBCountInd += 1 ;
                val =
                aBoard[line][col] = "bB" + to_string(bBCountInd) ;
                col+= 1 ;
                break;

            case 'B' :
                wBCountInd += 1 ;
                aBoard[line][col] = "wB" + to_string(wBCountInd) ;
                col+= 1 ;
                break;

            case 'n' :
                bNCountInd += 1 ;
                aBoard[line][col] = "bN" + to_string(bNCountInd) ;
                col+= 1 ;
                break;

            case 'N' :
                wNCountInd += 1 ;
                aBoard[line][col] = "wN" + to_string(wNCountInd) ;
                col+= 1 ;
                break;

            case 'p' :
                bPCountInd += 1 ;
                aBoard[line][col] = "bP" + to_string(bPCountInd) ;
                col+= 1 ;
                break;

            case 'P' :
                wPCountInd += 1 ;
                aBoard[line][col] = "wP" + to_string(wPCountInd) ;
                col+= 1 ;
                break;

            case 'k' :
                aBoard[line][col] = "bK" ;
                col+= 1 ;
                break;

            case 'K' :
                aBoard[line][col] = "wK" ;
                col += 1 ;
                break;

            case 'q' :
                aBoard[line][col] = "bQ" ;
                col+= 1 ;
                break;

            case 'Q' :
                aBoard[line][col] = "wQ" ;
                col+= 1 ;
                break;

            case '/' :
                line += 1 ;
                col = 0 ;
                break;

        }
    }
}

