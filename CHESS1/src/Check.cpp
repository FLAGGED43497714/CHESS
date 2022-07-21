#include "Check.h"
#include "legal.h"
#include "MoveInstructions.h"
#include "UpdateBoard.h"
#include "coutBoard.h"

#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;


// is check : a Board => are you in check rn
bool IsCheck(string aBoard[8][8], int moveNb){
    bool isCheck (false);

    //defining the king
    string allyKing = "wK" ;
    bool isWhiteTurn(moveNb % 2 == 0) ;
    if (!isWhiteTurn){
        //cout << "black's turn" << endl;
        allyKing = "bK" ;
    }
    pair<int, int> allyKingCoord ;
    allyKingCoord = findPiece(allyKing, aBoard) ;
    //cout << "Ally king is on " << allyKingCoord.first << allyKingCoord.second << endl;


    // checking if any move of the opponent will attack your king
    vector<pair<string, pair<int, int>>> legalOppMoves ;

    legalOppMoves = RawLegalMoves(aBoard, moveNb+1); // les coups au tour de l'adversaire


    for (int i = 0 ; i < legalOppMoves.size() ; i++ ){
        if ((legalOppMoves[i].second.first == allyKingCoord.first)
        &&(legalOppMoves[i].second.second == allyKingCoord.second))
        {
            //cout << "ally king is " << allyKing << " it is on " << allyKingCoord.first << allyKingCoord.second ;
            //cout << "checked by "<< legalOppMoves[i].first << endl;
            //sleep(3);
            isCheck = true;
        }
    }
    return isCheck;
}

bool IsCheck2(string aBoard[8][8], int moveNb, vector<pair<string, pair<int, int>>> legalOppMoves){
    bool isCheck (false);

    //defining the king
    string allyKing = "wK" ;
    bool isWhiteTurn(moveNb % 2 == 0) ;
    if (!isWhiteTurn){
        //cout << "black's turn" << endl;
        allyKing = "bK" ;
    }
    pair<int, int> allyKingCoord ;
    allyKingCoord = findPiece(allyKing, aBoard) ;
    //cout << "Ally king is on " << allyKingCoord.first << allyKingCoord.second << endl;


    // checking if any move of the opponent will attack your king
    //vector<pair<string, pair<int, int>>> legalOppMoves ;

    //legalOppMoves = RawLegalMoves(aBoard, moveNb+1); // les coups au tour de l'adversaire


    for (int i = 0 ; i < legalOppMoves.size() ; i++ ){
        if ((legalOppMoves[i].second.first == allyKingCoord.first)
        &&(legalOppMoves[i].second.second == allyKingCoord.second))
        {
            //cout << "ally king is " << allyKing << " it is on " << allyKingCoord.first << allyKingCoord.second ;
            //cout << "checked by "<< legalOppMoves[i].first << endl;
            //sleep(3);
            isCheck = true;
        }
    }
    return isCheck;
}




bool MoveChecksAllyKing(string aBoard[8][8], int moveNb, string thePiece, pair<int, int> theDest){
    bool moveChecksAllyKing (false);

    //create a parallel board to test a move
    string possibleBoard[8][8] ;
    for (int i=0; i < 8 ; i++){
        for (int j=0; j < 8 ; j++){
            possibleBoard[i][j] = aBoard[i][j] ;
        }
    }
    updateBoard2(thePiece, theDest.first, theDest.second,possibleBoard) ;
    //cout << "possible board" << endl;
    //coutBoard(possibleBoard);
    //sleep(1);
    moveChecksAllyKing = IsCheck(possibleBoard,moveNb) ;

    return moveChecksAllyKing;

}
