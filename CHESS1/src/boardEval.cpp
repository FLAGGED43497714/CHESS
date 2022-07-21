

#include "boardEval.h"
#include "UpdateBoard.h"
#include "legal.h"
#include "PieceValue.h"

#include <iostream>
#include <string>
#include <unistd.h>
#include <cmath>
#include <coutBoard.h>
#include <Check.h>
#include <MoveInstructions.h>

using namespace std;

const double PawnSqTbW[8][8] = {
    {0,  0,  0,  0,  0,  0,  0,  0},
    {50, 50, 50, 50, 50, 50, 50, 50},
    {10, 10, 20, 30, 30, 20, 10, 10},
    {5,  5, 10, 27, 27, 10,  5,  5},
    {0,  0,  0, 25, 25,  0,  0,  0},
    {5, 10, 10,  0,  0,-10, -5,  5},
    {5, 10, 10,-25,-25, 10, 10,  5},
    {0,  0,  0,  0,  0,  0,  0,  0}
    };

const double PawnSqTbB[8][8] = {
    {0,  0,  0,  0,  0,  0,  0,  0},
    {5, 10, 10,-25,-25, 10, 10,  5},
    {5, 10, 10,  0,  0,-10, -5,  5},
    {0,  0,  0, 25, 25,  0,  0,  0},
    {5,  5, 10, 27, 27, 10,  5,  5},
    {10, 10, 20, 30, 30, 20, 10, 10},
    {50, 50, 50, 50, 50, 50, 50, 50},
    {0,  0,  0,  0,  0,  0,  0,  0},

};

const double KnightSqTbW[8][8] = {
    {-50,-40,-30,-30,-30,-30,-40,-50},
    {-40,-20,  0,  0,  0,  0,-20,-40},
    {-30,  0, 10, 15, 15, 10,  0,-30},
    {-30,  5, 15, 20, 20, 15,  5,-30},
    {-30,  0, 15, 20, 20, 15,  0,-30},
    {-30,  5, 10, 15, 15, 10,  5,-30},
    {-40,-20,  0,  5,  5,  0,-20,-40},
    {-50,-40,-20,-30,-30,-20,-40,-50}
};

const double KnightSqTbB[8][8] =
{
    {-50,-40,-20,-30,-30,-20,-40,-50},
    {-40,-20,  0,  5,  5,  0,-20,-40},
    {-30,  5, 10, 15, 15, 10,  5,-30},
    {-30,  0, 15, 20, 20, 15,  0,-30},
    {-30,  5, 15, 20, 20, 15,  5,-30},
    {-30,  0, 10, 15, 15, 10,  0,-30},
    {-40,-20,  0,  0,  0,  0,-20,-40},
    {-50,-40,-30,-30,-30,-30,-40,-50},
};

const double BishopSqTbW[8][8] =
{
    {-20,-10,-10,-10,-10,-10,-10,-20},
    {-10,  0,  0,  0,  0,  0,  0,-10},
    {-10,  0,  5, 10, 10,  5,  0,-10},
    {-10,  5,  5, 10, 10,  5,  5,-10},
    {-10,  0, 10, 10, 10, 10,  0,-10},
    {-10, 10, 10,-20,-20, 10, 10,-10},
    {-10,  5,  0,  0,  0,  0,  5,-10},
    {-20,-10,-40,-10,-10,-40,-10,-20}
};

const double BishopSqTbB[8][8] =
{
    {-20,-10,-40,-10,-10,-40,-10,-20},
    {-10,  5,  0,  0,  0,  0,  5,-10},
    {-10, 10, 10,-20,-20, 10, 10,-10},
    {-10,  0, 10, 10, 10, 10,  0,-10},
    {-10,  5,  5, 10, 10,  5,  5,-10},
    {-10,  0,  5, 10, 10,  5,  0,-10},
    {-10,  0,  0,  0,  0,  0,  0,-10},
    {-20,-10,-10,-10,-10,-10,-10,-20}


};

const double KingSqTbW[8][8] =
{
  {-30, -40, -40, -50, -50, -40, -40, -30},
  {-30, -40, -40, -50, -50, -40, -40, -30},
  {-30, -40, -40, -50, -50, -40, -40, -30},
  {-30, -40, -40, -50, -50, -40, -40, -30},
  {-20, -30, -30, -40, -40, -30, -30, -20},
  {-10, -20, -20, -20, -20, -20, -20, -10},
   {20,  20,   0,   0,   0,   0,  20,  20},
   {20,  30,  10,   0,   0,  10,  30,  20}
};

const double KingSqTbB[8][8] =
{
{20,  30,  10,   0,   0,  10,  30,  20},
{20,  20,   0,   0,   0,   0,  20,  20},
{-10, -20, -20, -20, -20, -20, -20, -10},
{-20, -30, -30, -40, -40, -30, -30, -20},
{-30, -40, -40, -50, -50, -40, -40, -30},
{-30, -40, -40, -50, -50, -40, -40, -30},
{-30, -40, -40, -50, -50, -40, -40, -30},
{-30, -40, -40, -50, -50, -40, -40, -30}
};

const double RookSqTbW[8][8] =
{
{0,  0,  0,  0,  0,  0,  0,  0},
{5, 10, 10, 10, 10, 10, 10,  5},
{-5,  0,  0,  0,  0,  0,  0, -5},
{-5,  0,  0,  0,  0,  0,  0, -5},
{-5,  0,  0,  0,  0,  0,  0, -5},
{-5,  0,  0,  0,  0,  0,  0, -5},
{-5,  0,  0,  0,  0,  0,  0, -5},
{0,  0,  0,  5,  5,  0,  0,  0}
};

const double RookSqTbB[8][8] =
{
{0,  0,  0,  5,  5,  0,  0,  0},
{-5,  0,  0,  0,  0,  0,  0, -5},
{-5,  0,  0,  0,  0,  0,  0, -5},
{-5,  0,  0,  0,  0,  0,  0, -5},
{-5,  0,  0,  0,  0,  0,  0, -5},
{-5,  0,  0,  0,  0,  0,  0, -5},
{5, 10, 10, 10, 10, 10, 10,  5},
{0,  0,  0,  0,  0,  0,  0,  0}
};

const double QueenSqTbW[8][8] =
{
{-20,-10,-10, -5, -5,-10,-10,-20},
{-10,  0,  0,  0,  0,  0,  0,-10},
{-10,  0,  5,  5,  5,  5,  0,-10},
{ -5,  0,  5,  5,  5,  5,  0, 0},
{ 0,  0,  5,  5,  5,  5,  0, -5},
{-10,  5,  5,  5,  5,  5,  0,-10},
{-10,  0,  5,  0,  0,  0,  0,-10},
{-20,-10,-10, -5, -5,-10,-10,-20}
};

const double QueenSqTbB[8][8] =
{
{-20,-10,-10, -5, -5,-10,-10,-20},
{-10,  0,  5,  0,  0,  0,  0,-10},
{-10,  5,  5,  5,  5,  5,  0,-10},
{  0,  0,  5,  5,  5,  5,  0, -5},
{-5,  0,  5,  5,  5,  5,  0, 0},
{-10,  0,  5,  5,  5,  5,  0,-10},
{-10,  0,  0,  0,  0,  0,  0,-10},
{-20,-10,-10, -5, -5,-10,-10,-20}
};



bool isBetter(double eval1, double eval2, int moveNb){
    bool isWhiteTurn = (moveNb % 2 == 0) ;
    if (isWhiteTurn){
        return eval1 > eval2 ;
    } else {
        return eval1 < eval2 ;
    }

}

double evalMated(string aBoard[8][8],int moveNb){
    bool isWhiteTurn = (moveNb % 2 == 0) ; //not white turn
    vector<pair<string, pair<int, int>>> legalMovesPlayer ;
    vector<pair<string, pair<int, int>>> legalMovesWatcher ;
    legalMovesPlayer = LegalMoves(aBoard,moveNb) ;
    legalMovesWatcher = LegalMoves(aBoard,moveNb+1) ; //ke1 kf1

    if (legalMovesPlayer.size() == 0){
        cout << "I see player in mate  !" << endl ;
        //sleep(1.5);
        if (isWhiteTurn){
            return -90000 ;
        } else {
            return 90000 ;
        }
    }
    return 0 ;
}

double evalTurn(int moveNb){
    if (moveNb % 2 == 0){
        return 10 ; // ATTENTION on évalue avant le coup
    }
    else {
        return -10 ;
    }
}

/*
double evalPieces(string aBoard[8][8])
{
    double eval (0);
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            switch(aBoard[i][j][1])
            {
                case 'P' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += 100 ;
                    } else {
                        eval -= 100 ;
                    }
                    break;

                case 'N' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += 300 ;
                    } else {
                        eval -= 300 ;
                    }
                    break;

                case 'B' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += 300 ;
                    } else {
                        eval -= 300 ;
                    }
                    break;

                case 'R' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += 500 ;
                    } else {
                        eval -= 500 ;
                    }
                    break;

                case 'Q' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += 900 ;
                    } else {
                        eval -= 900 ;
                    }
                    break;

                case 'K' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += 10000 ;
                    } else {
                        eval -= 10000 ;
                    }
                    break;
            }
        }
    }

    return eval;
}*/

/*double evalPieces2(string aBoard[8][8])
{
    double eval1 = evalPieces(aBoard) / 100 ;
    bool advWhite = true ;
    if (eval1 < 0){
        advWhite = false ;
    }
    double eval (0);
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            switch(aBoard[i][j][1])
            {
                case 'P' :
                    if (aBoard[i][j][0] == 'w'){
                        if (!advWhite){
                            eval += 100*eval1 ;
                        }
                        else {
                            eval += 100 ;
                        }
                    } else {
                        if (!advWhite){
                            eval += 100*eval1 ;
                        }
                        else {
                            eval += 100 ;
                        }
                        eval -= 100 ;
                    }
                    break;
                case 'N' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += 300 ;
                    } else {
                        eval -= 300 ;
                    }
                    break;
                case 'B' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += 300 ;
                    } else {
                        eval -= 300 ;
                    }
                    break;
                case 'R' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += 500 ;
                    } else {
                        eval -= 500 ;
                    }
                    break;
                case 'Q' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += 900 ;
                    } else {
                        eval -= 900 ;
                    }
                    break;
                case 'K' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += 10000 ;
                    } else {
                        eval -= 10000 ;
                    }
                    break;
            }
        }
    }
    return eval;
}*/

/*
double EvalSqPcTable(string aBoard[8][8], int moveNb){
    //cout << "exec EvalSqPcTable" << endl;
    //bool isWhiteTurn = (moveNb % 2 == 0) ;
    double eval (0) ;

    for (int i=0 ; i < 8 ; i ++)
    {
        for (int j=0 ; j < 8 ; j ++)
        {
            switch(aBoard[i][j][1])
            {
                case 'P' :
                    if (aBoard[i][j][0] == 'w'){
                        //cout << "pawn " << aBoard[i][j] << " add " << PawnSqTbW[i][j] << endl;
                        eval += PawnSqTbW[i][j] ;
                    } else {
                        //cout << "pawn " << aBoard[i][j] << " sub " << PawnSqTbB[i][j] << endl;
                        eval -= PawnSqTbB[i][j] ;
                    }
                    break;

                case 'N' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += KnightSqTbW[i][j] ;
                    } else {
                        eval -= KnightSqTbB[i][j] ;
                    }
                    break;

                case 'B' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += BishopSqTbW[i][j] ;
                    } else {
                        eval -= BishopSqTbB[i][j] ;
                    }
                    break;

                case 'R' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += RookSqTbW[i][j] ;
                    } else {
                        eval -= RookSqTbB[i][j] ;
                    }
                    break;

                case 'Q' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += QueenSqTbW[i][j] ;
                    } else {
                        eval -= QueenSqTbB[i][j] ;
                    }
                    break;

                case 'K' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += KingSqTbW[i][j] ;
                    } else {
                        eval -= KingSqTbB[i][j] ;
                    }
                    break;
            }
        }
    }
    return eval ;
}*/

double evalPiecesANDSqPcTb (string aBoard[8][8], int moveNb){
        double eval (0) ;

    for (int i=0 ; i < 8 ; i ++)
    {
        for (int j=0 ; j < 8 ; j ++)
        {
            switch(aBoard[i][j][1])
            {
                case 'P' :
                    if (aBoard[i][j][0] == 'w'){
                        //cout << "pawn " << aBoard[i][j] << " add " << PawnSqTbW[i][j] << endl;
                        eval += PawnSqTbW[i][j] ;
                        eval += 100 ;
                    } else {
                        //cout << "pawn " << aBoard[i][j] << " sub " << PawnSqTbB[i][j] << endl;
                        eval -= PawnSqTbB[i][j] ;
                        eval -= 100 ;
                    }
                    break;

                case 'N' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += KnightSqTbW[i][j] ;
                        eval += 300 ;
                    } else {
                        eval -= KnightSqTbB[i][j] ;
                        eval -= 300 ;
                    }
                    break;

                case 'B' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += BishopSqTbW[i][j] ;
                        eval += 300 ;
                    } else {
                        eval -= BishopSqTbB[i][j] ;
                        eval -= 300 ;
                    }
                    break;

                case 'R' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += RookSqTbW[i][j] ;
                        eval += 500 ;
                    } else {
                        eval -= RookSqTbB[i][j] ;
                        eval -= 500 ;
                    }
                    break;

                case 'Q' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += QueenSqTbW[i][j] ;
                        eval += 900 ;
                    } else {
                        eval -= QueenSqTbB[i][j] ;
                        eval -= 900 ;
                    }
                    break;

                case 'K' :
                    if (aBoard[i][j][0] == 'w'){
                        eval += KingSqTbW[i][j] ;
                        eval += 10000 ;
                    } else {
                        eval -= KingSqTbB[i][j] ;
                        eval -= 10000 ;
                    }
                    break;
            }
        }
    }
    return eval ;
}

/*
double evalMoveSz(string aBoard[8][8],int moveNb, bool wC1, bool wC2, bool bC1, bool bC2){
    bool isWhiteTurn = (moveNb % 2 == 0) ;

    double weight = 1 ;

    int moveSzThis = unSortedLegalMoves(aBoard, moveNb, wC1, wC2, bC1, bC2).size() ;
    int moveSzNext = unSortedLegalMoves(aBoard, moveNb+1, wC1, wC2, bC1, bC2).size() ;

    if (isWhiteTurn){
        return ( moveSzThis - moveSzNext ) * weight ;
    } else {
        return ( moveSzNext - moveSzThis ) * weight ;
    }

}*/


double eval(string aBoard[8][8],int moveNb, bool wC1, bool wC2, bool bC1, bool bC2)
{
    double theEval (0);

    //theEval = evalPieces(aBoard);
    //cout << "piece eval is " << theEval << endl;
    //double evalSqPcTable = EvalSqPcTable(aBoard,moveNb) ;
    //cout << "square table eval is " << evalSqPcTable << endl;
    //theEval += evalSqPcTable ;
    //cout << "total eval is " << theEval << endl;
    //double evalMate = evalMated(aBoard,moveNb) ;


    //theEval += evalMate ;

    //double theEvalMoveSz = evalMoveSz(aBoard,moveNb,wC1, wC2, bC1, bC2) ;

    //theEval += theEvalMoveSz ;

    theEval += evalPiecesANDSqPcTb(aBoard,moveNb) ;

    theEval += evalTurn(moveNb+1) ; // le coup est joué, c'est au tour de l'adversaire

    theEval = floor(theEval);

    return theEval ;

}
/*
pair<string, pair<int, int>> bestMove(vector<pair<string, pair<int, int>>> legalMoves,string aBoard[8][8],int moveNb){
    bool isWhiteTurn = (moveNb % 2 == 0) ;
    pair<string, pair<int, int>> bestMove ;
    string possibleBoard[8][8];
    double currentEval ;
    double bestEval = -90000.5 ;
    if (!isWhiteTurn){
        bestEval = 90000.5 ;
    }
    for (int k = 0 ; k < legalMoves.size() ; k++){
        for (int i=0; i < 8 ; i++){
            for (int j=0; j < 8 ; j++){
                possibleBoard[i][j] = aBoard[i][j] ;
            }
        }
        updateBoard2(legalMoves[k].first,legalMoves[k].second.first,legalMoves[k].second.second,possibleBoard);
        currentEval = eval(possibleBoard,moveNb) ;
        //cout << "move " << legalMoves[k].first << legalMoves[k].second.first << legalMoves[k].second.second ;
        //cout << " gives eval : " << currentEval << endl ;
        if (isWhiteTurn){
            if (currentEval > bestEval){
                bestMove = legalMoves[k] ;
                bestEval = currentEval ;
            }
        } else {
            if (currentEval < bestEval){
                bestMove = legalMoves[k] ;
                bestEval = currentEval ;
            }
        }
    }
    return bestMove ;
}
pair<string, pair<int, int>> bestMove2(string aBoard[8][8],int moveNb){
    vector<pair<string, pair<int, int>>> legalMovest0 ;
    vector<pair<string, pair<int, int>>> legalMovest1 ;
    vector<pair<int, double>> evals1 ;
    legalMovest0 = LegalMoves(aBoard,moveNb);
    double evals0[legalMovest0.size()] ;
    for (int k = 0 ; k < legalMovest0.size() ; k++){
        evals0[k] = (2 * (moveNb % 2 == 0) - 1) * 9000 ;
    }
    bool isWhiteTurn = (moveNb % 2 == 0) ;
    pair<string, pair<int, int>> bestMove ;
    string possibleBoardt1[8][8];
    string possibleBoardt2[8][8];
    pair<int,double> currentEvalsAndMove ;
    double currentEval ;
    for (int k = 0 ; k < legalMovest0.size() ; k++){
        for (int i=0; i < 8 ; i++){
            for (int j=0; j < 8 ; j++){
                possibleBoardt1[i][j] = aBoard[i][j] ;
            }
        }
        //new Board
        updateBoard2(legalMovest0[k].first,legalMovest0[k].second.first,legalMovest0[k].second.second,possibleBoardt1);
        //new Moves
        legalMovest1 = LegalMoves(possibleBoardt1,moveNb+1);
        //init new board
        //cout << "for move : " << legalMovest0[k].first << legalMovest0[k].second.first << legalMovest0[k].second.second << endl ;
        //cout << "legalMovess1 size :" << legalMovest1.size() << endl;
        if (legalMovest1.size() == 0){
            //cout << "can mate" << endl;
            //sleep(10) ;
            currentEvalsAndMove.first = k ;
            currentEvalsAndMove.second = (((moveNb) % 2 == 1)*2 - 1) * -9000 ;
            evals1.push_back(currentEvalsAndMove);
        }
        for (int kk = 0 ; kk < legalMovest1.size() ; kk++){
            //cout << "moves are : " << legalMovest1[kk].first ;
            //cout << legalMovest1[kk].second.first << legalMovest1[kk].second.second << endl;
            for (int ii=0; ii < 8 ; ii++){
                for (int jj=0; jj < 8 ; jj++){
                    possibleBoardt2[ii][jj] = possibleBoardt1[ii][jj] ;
                }
            }
            updateBoard2(legalMovest1[kk].first,legalMovest1[kk].second.first,legalMovest1[kk].second.second,possibleBoardt2);
            currentEval = eval(possibleBoardt2,moveNb+1) ;
            currentEvalsAndMove.first = k ;
            currentEvalsAndMove.second = currentEval ;
            evals1.push_back(currentEvalsAndMove);
        }
    }
    //sleep(300);
    for (int k = 0 ; k < legalMovest0.size() ; k++){
        for (int u = 0 ; u < evals1.size() ; u++){
            if ((evals1[u].first == k) && (isBetter(evals1[u].second,evals0[k], moveNb+1))){
                evals0[k] = evals1[u].second;
            }
        }
    }
    currentEval = evals0[0] ;
    bestMove = legalMovest0[0];
    for (int k = 1 ; k < legalMovest0.size() ; k++){
        if (isBetter(evals0[k],currentEval,moveNb)){
            bestMove = legalMovest0[k] ;
            currentEval = evals0[k];
        }
    }
    return bestMove ;
}
pair<int, double> subBestMove3(string aBoard[8][8],int moveNb, int maxIter, int iter = 1){
    //cout << "entering new layer with " << endl;
    //cout << "iter = " << iter << " max iter = " << maxIter << "moveNb = " << moveNb << endl ;
    bool isWhiteTurn = (moveNb % 2 == 0) ;
    vector<pair<string, pair<int, int>>> legalMovest0 ;
    //coups légaux et leur éval
    legalMovest0 = LegalMoves(aBoard,moveNb);
    int evalSize = 0 ;
    if (legalMovest0.size() == 0){
        evalSize = 1 ;
    } else {
        evalSize = legalMovest0.size() ;
    }
    double evals[evalSize] ;
    //initialisation des
    for (int k = 0 ; k < legalMovest0.size() ; k++){
        evals[k] = (2 * (moveNb % 2 == 0) - 1) * - 9000 ;
    }
    string possibleBoard[8][8];
    double bestEval = evals[0] ;
    int bestInd = 0 ;
    if (legalMovest0.size() == 0){
        bestEval = (2 * (moveNb % 2 == 0) - 1) * - 9000 ;
        pair<int,double> bestMoveEval ;
        bestMoveEval.first = bestInd ;
        bestMoveEval.second = bestEval ;
        cout << "spotted a possible mate, returning" << (2 * (moveNb % 2 == 0) - 1) * - 9000 << endl ;
        return bestMoveEval;
    }
    for (int k = 0 ; k < legalMovest0.size() ; k++){
        for (int i=0; i < 8 ; i++){
            for (int j=0; j < 8 ; j++){
                possibleBoard[i][j] = aBoard[i][j] ;
            }
        }
        //new Board
        updateBoard2(legalMovest0[k].first,legalMovest0[k].second.first,legalMovest0[k].second.second,possibleBoard);
        //bestInd = subBestMove3(possibleBoard,moveNb+1, maxIter, iter+1) ;
        if (iter == maxIter){
            evals[k] = eval(possibleBoard,moveNb) ;
        }
        if (iter < maxIter){
            //cout << "iter = " << iter << " max iter = " << maxIter << "moveNb = " << moveNb << endl ;
            int newMoveNb = moveNb+1 ;
            int newIter = iter +1 ;
            //cout << "subBestMove3 " << "with " << "newMoveNb = " << newMoveNb << "and newIter = " << newIter << endl;
            pair<int, double> resSubBestMove3 = subBestMove3(possibleBoard, newMoveNb, maxIter,newIter) ;
            double bestEval = resSubBestMove3.second ;
            evals[k] = bestEval ;
        }
    }
    for (int k = 0 ; k < legalMovest0.size(); k++){
        //cout << "evals[k] = " << evals[k] << endl;
        //cout << "bestEval = " << bestEval << endl;
        if (isBetter(evals[k],bestEval,moveNb)){
            bestEval = evals[k] ;
            bestInd = k ;
        }
    }
    //if (moveNb % 2 == 0){cout << "White";} else {cout << "Black";} cout << " to play" << endl ;
    //cout << "I chose " << bestInd << " for eval " << bestEval << endl;
    //sleep(3);
    pair<int,double> bestMoveEval ;
    bestMoveEval.first = bestInd ;
    bestMoveEval.second = bestEval ;
    return bestMoveEval;
}
pair<int, double> subBestMove4(string aBoard[8][8],int moveNb, int maxIter, int iter = 1, int veryMaxIter = 6){
    //cout << "entering new layer with " << endl;
    //cout << "iter = " << iter << " max iter = " << maxIter << "moveNb = " << moveNb << endl ;
    //coutBoard(aBoard) ;
    //cout << endl;
    bool isWhiteTurn = (moveNb % 2 == 0) ;
    char colorEnnemy ;
    if (isWhiteTurn){
        colorEnnemy = 'b' ;
    } else {
        colorEnnemy = 'w' ;
    }
    vector<pair<string, pair<int, int>>> legalMovest0 ;
    //coups légaux et leur éval
    legalMovest0 = LegalMoves(aBoard,moveNb);
    int evalSize = 0 ;
    if (legalMovest0.size() == 0){
        evalSize = 1 ;
    } else {
        evalSize = legalMovest0.size() ;
    }
    double evals[evalSize] ;
    //initialisation des
    for (int k = 0 ; k < legalMovest0.size() ; k++){
        evals[k] = (2 * (isWhiteTurn) - 1) * - 9000 ;
    }
    string possibleBoard[8][8];
    double bestEval = evals[0] ;
    int bestInd = 0 ;
    if (legalMovest0.size() == 0){
        bestEval = (2 * (moveNb % 2 == 0) - 1) * - 9000 ;
        pair<int,double> bestMoveEval ;
        bestMoveEval.first = bestInd ;
        bestMoveEval.second = bestEval ;
        //cout << "spotted a possible mate, returning" << (2 * (moveNb % 2 == 0) - 1) * - 9000 << endl ;
        return bestMoveEval;
    }
    bool incremented ;
    for (int k = 0 ; k < legalMovest0.size() ; k++){
            incremented = false ;
        for (int i=0; i < 8 ; i++){
            for (int j=0; j < 8 ; j++){
                possibleBoard[i][j] = aBoard[i][j] ;
            }
        }
        //new Board
        if ((possibleBoard[legalMovest0[k].second.first][legalMovest0[k].second.second][0] == colorEnnemy)
            && (iter == maxIter)
            && (maxIter < veryMaxIter)){
            //cout << "last move is " << legalMovest0[k].first << legalMovest0[k].second.first << legalMovest0[k].second.second ;
            //cout << "so we increment" << endl;
            //string nothing ;
            //cin >> nothing ;
            incremented = true ;
            maxIter+=1 ;
            //cout << "maxIter +1"<< endl;
            //cout << "for " << legalMovest0[k].first << legalMovest0[k].second.first << legalMovest0[k].second.second << endl ;
            //sleep(5);
        }
        updateBoard2(legalMovest0[k].first,legalMovest0[k].second.first,legalMovest0[k].second.second,possibleBoard);
        //bestInd = subBestMove3(possibleBoard,moveNb+1, maxIter, iter+1) ;
        if (iter == maxIter){
            evals[k] = eval(possibleBoard,moveNb) ;
        }
        if (iter < maxIter){
            //cout << "iter = " << iter << " max iter = " << maxIter << "moveNb = " << moveNb << endl ;
            int newMoveNb = moveNb+1 ;
            int newIter = iter +1 ;
            //cout << "subBestMove3 " << "with " << "newMoveNb = " << newMoveNb << "and newIter = " << newIter << endl;
            pair<int, double> resSubBestMove3 = subBestMove4(possibleBoard, newMoveNb, maxIter,newIter) ;
            double bestEval = resSubBestMove3.second ;
            evals[k] = bestEval ;
        }
        if (incremented){
            maxIter-=1 ;
            //cout << "max iter -1 " << endl;
        }
    }
    for (int k = 0 ; k < legalMovest0.size(); k++){
        //cout << "evals[k] = " << evals[k] << endl;
        //cout << "bestEval = " << bestEval << endl;
        if (isBetter(evals[k],bestEval,moveNb)){
            bestEval = evals[k] ;
            bestInd = k ;
        }
    }
    //if (moveNb % 2 == 0){cout << "White";} else {cout << "Black";} cout << " to play" << endl ;
    //cout << "I chose " << bestInd << " for eval " << bestEval << endl;
    //sleep(3);
    pair<int,double> bestMoveEval ;
    bestMoveEval.first = bestInd ;
    bestMoveEval.second = bestEval ;
    return bestMoveEval;
}*/

pair<int, double> subBestMove5(string aBoard[8][8],int moveNb, bool wC1, bool wC2, bool bC1, bool bC2,
                               int maxIter, double alpha = -9999, double beta = 9999, int iter = 1, int veryMaxIter = 7){
    //cout << "entering new layer with " << endl;
    //cout << "iter = " << iter << " max iter = " << maxIter << "moveNb = " << moveNb << endl ;

    /*system("cls") ;
    coutBoard(aBoard) ;
    string nothing ;
    cin >> nothing ;*/

    //cout << endl;

    bool isWhiteTurn = (moveNb % 2 == 0) ;

    char colorEnnemy ;

    if (isWhiteTurn){
        colorEnnemy = 'b' ;
    } else {
        colorEnnemy = 'w' ;
    }

    vector<pair<string, pair<int, int>>> legalMovest0 ;

    //coups légaux et leur éval
    legalMovest0 = LegalMoves(aBoard, moveNb, wC1, wC2, bC2, bC2);

    pair<int,double> bestMoveEval ;
    int bestInd = 0 ;
    double bestEval ;

    //initialisation des
    //double dreamedEval = (2 * (isWhiteTurn) - 1) * + 7000 ;
    bestEval = (2 * (isWhiteTurn) - 1) * - 9000 ;


    string possibleBoard[8][8];



    if (legalMovest0.size() == 0){

        // ATTENTION IL NE CONSIDERE PAS LES STALEMATES

        if (isWhiteTurn){
            if(IsCheck(aBoard,moveNb)){
                bestEval = -9000 ;
            } else {
                bestEval = 0 ;
            }

        } else {
            if(IsCheck(aBoard,moveNb)){
                bestEval = 9000 ;
            } else {
                bestEval = 0 ;
            }


        }

        bestMoveEval.first = bestInd ;
        bestMoveEval.second = bestEval ;

        //cout << "spotted a possible mate, returning" << (2 * (moveNb % 2 == 0) - 1) * - 9000 << endl ;
        return bestMoveEval;
    }

    bool incremented ;
    bool isCastle ;

    double evalRN ;

    if (iter == maxIter){ // on le fait avant de rentrer dans la boucle
            evalRN = eval(aBoard,moveNb,wC1, wC2, bC1, bC2) ;
    }

    double thisEval ;



    for (int k = 0 ; k < legalMovest0.size() ; k++){

        bool evalDone = false ;

        incremented = false ;


        if ((legalMovest0[k].second.first == -1) && (legalMovest0[k].second.second == -1)){
            isCastle = true ;
        }
        //new Board
        string nothing ;

        string yourPiece = legalMovest0[k].first ;
        //cout << yourPiece ;
        //cin >> nothing ;
        //pair<int,int> whereItWas ;
        //whereItWas = findPiece(yourPiece,aBoard) ;
        string destSq  ;
        if (!isCastle){
            destSq = aBoard[legalMovest0[k].second.first][legalMovest0[k].second.second] ;
        }

        if (getPieceValue(destSq[1]) > 1000) {
            bestMoveEval.first = k ;
            bestMoveEval.second = (2 * (isWhiteTurn) - 1) * 9000 ;
            return bestMoveEval;
        }






        //bestInd = subBestMove3(possibleBoard,moveNb+1, maxIter, iter+1) ;

        //begin / middle of capture sequence
        if (!isCastle){
            if (destSq[0] == colorEnnemy){
                //cout << destSq ;
                if ((getPieceValue(yourPiece[1]) >= getPieceValue(destSq[1]))
                && (iter == maxIter) //|| ((iter ==2)&&(iter == maxIter)))
                && (maxIter < veryMaxIter)){
                    //cout << "incrementing because take smaller" ;
                    for (int i=0; i < 8 ; i++){
                        for (int j=0; j < 8 ; j++){
                            possibleBoard[i][j] = aBoard[i][j] ;
                        }
                    }

                    updateBoard2(yourPiece,legalMovest0[k].second.first,legalMovest0[k].second.second,possibleBoard);

                    incremented = true ;
                    maxIter+=1 ;
                    //cout << "now iter = " << iter << " and maxIter = " << maxIter << endl;
                    //cin >> nothing ;
                }

                //end of capture sequence
                else
                {
                    if ((getPieceValue(yourPiece[1]) < getPieceValue(destSq[1]))
                    && (iter == maxIter)) //|| ((iter ==2)&&(iter == maxIter)))
                    {
                        if (getPieceValue(destSq[1]) > 1000) {
                                bestMoveEval.first = k ;
                                bestMoveEval.second = (2 * (isWhiteTurn) - 1) * 9000 ;
                                return bestMoveEval;
                        }
                        //cout << "incrementing because take smaller" ;
                        for (int i=0; i < 8 ; i++){
                            for (int j=0; j < 8 ; j++){
                                possibleBoard[i][j] = aBoard[i][j] ;
                            }
                        }
                        updateBoard2(yourPiece,legalMovest0[k].second.first,legalMovest0[k].second.second,possibleBoard);


                        thisEval = eval(possibleBoard,moveNb,wC1, wC2, bC1, bC2) ;

                        evalDone = true ;


                        if (isBetter(thisEval,bestEval,moveNb)){
                            bestEval = thisEval ;
                            bestInd = k ;
                        }
                        if (isWhiteTurn){
                            alpha = max(alpha,thisEval) ;
                            if (beta <= alpha) {
                                break ;
                            }
                        }
                        if (!isWhiteTurn){
                            beta = min(beta,thisEval);
                        }

                        //cout << "now iter = " << iter << " and maxIter = " << maxIter << endl;
                        //cin >> nothing ;
                    }

                }
            }
        }




        if ((!incremented) && (iter == maxIter) && (!evalDone)){

            thisEval = evalRN ;
            evalDone = true ;



            if (isBetter(thisEval,bestEval,moveNb)){
                bestEval = thisEval ;
                bestInd = k ;
            }
            if (isWhiteTurn){
                alpha = max(alpha,thisEval) ;
                if (beta <= alpha) {
                    break ;
                }
            }
            if (!isWhiteTurn){
                beta = min(beta,thisEval);
            }
        }


        if ((!evalDone) && (!incremented)){
            for (int i=0; i < 8 ; i++){
                for (int j=0; j < 8 ; j++){
                    possibleBoard[i][j] = aBoard[i][j] ;
                }
            }

            updateBoard2(yourPiece,legalMovest0[k].second.first,legalMovest0[k].second.second,possibleBoard);
        }


        if (iter < maxIter){
            //cout << "iter = " << iter << " max iter = " << maxIter << "moveNb = " << moveNb << endl ;
            int newMoveNb = moveNb+1 ;
            int newIter = iter +1 ;

            //cout << "subBestMove3 " << "with " << "newMoveNb = " << newMoveNb << "and newIter = " << newIter << endl;
            //cout << "your piece : " << yourPiece ;


            pair<int, double> resSubBestMove3 = subBestMove5(possibleBoard, newMoveNb, wC1, wC2, bC2, bC2, maxIter, alpha, beta, newIter) ;

            //cout << "your piece : " << yourPiece ;

            double thisEval = resSubBestMove3.second ;

            if (isBetter(thisEval,bestEval,moveNb)){
                bestEval = thisEval ;
                bestInd = k ;
            }
            if (isWhiteTurn){
                alpha = max(alpha,thisEval) ;
                if (beta <= alpha) {
                    break ;
                }
            }
            if (!isWhiteTurn){
                beta = min(beta,thisEval);
            }

        }
        //cout << "undoing " << yourPiece << whereItWas.first << whereItWas.second ;
        //updateBoard2(yourPiece,whereItWas.first, whereItWas.second,aBoard) ;
        //aBoard[legalMovest0[k].second.first][legalMovest0[k].second.second] = destSq ;
        //cin >> nothing ;

        if (incremented){
            maxIter-=1 ;
            //cout << "max iter -1 " << endl;

        }
    }



    bestMoveEval.first = bestInd ;
    bestMoveEval.second = bestEval ;


    return bestMoveEval;
}


pair<int, double> subBestMove6(string aBoard[8][8],int moveNb, bool wC1, bool wC2, bool bC1, bool bC2,
                               int maxIter, double alpha = -9999, double beta = 9999, int iter = 1, int veryMaxIter = 7){
    //cout << "entering new layer with " << endl;
    //cout << "iter = " << iter << " max iter = " << maxIter << "moveNb = " << moveNb << endl ;

    /*system("cls") ;
    coutBoard(aBoard) ;
    string nothing ;
    cin >> nothing ;*/


    bool boardUpdated ;

    bool isWhiteTurn = (moveNb % 2 == 0) ;

    char colorEnnemy ;

    if (isWhiteTurn){
        colorEnnemy = 'b' ;
    } else {
        colorEnnemy = 'w' ;
    }

    vector<pair<string, pair<int, int>>> legalMovest0 ;

    //coups légaux et leur éval
    legalMovest0 = LegalMoves(aBoard, moveNb, wC1, wC2, bC2, bC2);

    pair<int,double> bestMoveEval ;
    int bestInd = 0 ;
    double bestEval ;

    //initialisation des
    bestEval = (2 * (isWhiteTurn) - 1) * - 9000 ;


    if (legalMovest0.size() == 0){

        if (isWhiteTurn){
            if(IsCheck(aBoard,moveNb)){
                bestEval = -9000 ;
            } else {
                bestEval = 0 ;
            }

        } else {
            if(IsCheck(aBoard,moveNb)){
                bestEval = 9000 ;
            } else {
                bestEval = 0 ;
            }


        }

        bestMoveEval.first = bestInd ;
        bestMoveEval.second = bestEval ;

        return bestMoveEval;
    }

    bool incremented ;
    bool isCastle ;

    double evalRN ;

    if (iter == maxIter){ // on le fait avant de rentrer dans la boucle
            evalRN = eval(aBoard,moveNb,wC1, wC2, bC1, bC2) ;
    }

    double thisEval ;


    pair<int, int> pieceOldLoc ;

    bool evalDone ;

    for (int k = 0 ; k < legalMovest0.size() ; k++){

         evalDone = false ;

        incremented = false ;

        boardUpdated = false ;


        if ((legalMovest0[k].second.first == -1) && (legalMovest0[k].second.second == -1)){
            isCastle = true ;
        }
        string nothing ;

        string yourPiece = legalMovest0[k].first ;
        string destSq  ;

        if (!isCastle){
            destSq = aBoard[legalMovest0[k].second.first][legalMovest0[k].second.second] ;
            pieceOldLoc = findPiece(yourPiece, aBoard) ;
        }









        //begin / middle of capture sequence
        if (!isCastle){
            if (destSq[0] == colorEnnemy){
                if ((getPieceValue(yourPiece[1]) >= getPieceValue(destSq[1]))
                && (iter == maxIter) //|| ((iter ==2)&&(iter == maxIter)))
                && (maxIter < veryMaxIter)){
                    /*for (int i=0; i < 8 ; i++){
                        for (int j=0; j < 8 ; j++){
                            possibleBoard[i][j] = aBoard[i][j] ;
                        }
                    }*/

                    updateBoard2(yourPiece,legalMovest0[k].second.first,legalMovest0[k].second.second,aBoard);

                    boardUpdated = true ;

                    incremented = true ;
                    maxIter+=1 ;
                }

                else
                {
                    if ((getPieceValue(yourPiece[1]) < getPieceValue(destSq[1]))
                    && (iter == maxIter)) //|| ((iter ==2)&&(iter == maxIter)))
                    {
                        /*for (int i=0; i < 8 ; i++){
                            for (int j=0; j < 8 ; j++){
                                possibleBoard[i][j] = aBoard[i][j] ;
                            }
                        }*/

                        updateBoard2(yourPiece,legalMovest0[k].second.first,legalMovest0[k].second.second,aBoard);

                        boardUpdated = true ;


                        thisEval = eval(aBoard,moveNb,wC1, wC2, bC1, bC2) ;
                        evalDone = true ;

                        if (isBetter(thisEval,bestEval,moveNb)){
                            bestEval = thisEval ;
                            bestInd = k ;
                        }
                        if (isWhiteTurn){
                            alpha = max(alpha,thisEval) ;
                            if (beta <= alpha) {
                                break ;
                            }
                        }
                        if (!isWhiteTurn){
                            beta = min(beta,thisEval);
                        }
                    }
                }
            }
        }

        if ((!incremented) && (iter == maxIter) && (!evalDone)){

            thisEval = evalRN ;
            evalDone = true ;

            if (isBetter(thisEval,bestEval,moveNb)){
                bestEval = thisEval ;
                bestInd = k ;
            }
            if (isWhiteTurn){
                alpha = max(alpha,thisEval) ;
                if (beta <= alpha) {
                    break ;
                }
            }
            if (!isWhiteTurn){
                beta = min(beta,thisEval);
            }
        }


        if ((!evalDone) && (!incremented)){
            /*for (int i=0; i < 8 ; i++){
                for (int j=0; j < 8 ; j++){
                    possibleBoard[i][j] = aBoard[i][j] ;
                }
            }*/

            updateBoard2(yourPiece,legalMovest0[k].second.first,legalMovest0[k].second.second,aBoard);
            boardUpdated = true ;
        }


        if (iter < maxIter){
            int newMoveNb = moveNb+1 ;
            int newIter = iter +1 ;


            pair<int, double> resSubBestMove = subBestMove6(aBoard, newMoveNb, wC1, wC2, bC2, bC2, maxIter, alpha, beta, newIter) ;

            double thisEval = resSubBestMove.second ;

            if (isBetter(thisEval,bestEval,moveNb)){
                bestEval = thisEval ;
                bestInd = k ;
            }
            if (isWhiteTurn){
                alpha = max(alpha,thisEval) ;
                if (beta <= alpha) {
                    break ;
                }
            }
            if (!isWhiteTurn){
                beta = min(beta,thisEval);
            }

        }

        if (incremented){
            maxIter-=1 ;
        }
        if (boardUpdated){
            undoMove(yourPiece,pieceOldLoc.first, pieceOldLoc.second, destSq, aBoard) ;

            /*system("cls") ;
            coutBoard(aBoard) ;
            string nothing ;
            cin >> nothing ;*/
        }
    }



    bestMoveEval.first = bestInd ;
    bestMoveEval.second = bestEval ;


    return bestMoveEval;
}


/*
pair<string, pair<int, int>> bestMove3(string aBoard[8][8],int moveNb,int maxIter){
    vector<pair<string, pair<int, int>>> legalMovest0 ;
    legalMovest0 = LegalMoves(aBoard,moveNb) ;
    pair<int, double> resSubBestMove3 = subBestMove3(aBoard, moveNb, maxIter) ;
    //cout << "end of resSubBestMove3" << endl ;
    //cout << resSubBestMove3.first << endl ;
    //cout << resSubBestMove3.second << endl ;
    int bestInd = resSubBestMove3.first ;
    //cout << "best move is " << legalMovest0[bestInd].first << legalMovest0[bestInd].second.first ;
    //cout << legalMovest0[bestInd].second.second << " for eval " << resSubBestMove3.second << endl ;
    return legalMovest0[bestInd];
}
pair<string, pair<int, int>> bestMove4(string aBoard[8][8],int moveNb,int maxIter){
    vector<pair<string, pair<int, int>>> legalMovest0 ;
    legalMovest0 = LegalMoves(aBoard,moveNb) ;
    pair<int, double> resSubBestMove3 = subBestMove4(aBoard, moveNb, maxIter) ;
    //cout << "end of resSubBestMove3" << endl ;
    //cout << resSubBestMove3.first << endl ;
    //cout << resSubBestMove3.second << endl ;
    int bestInd = resSubBestMove3.first ;
    //cout << "best move is " << legalMovest0[bestInd].first << legalMovest0[bestInd].second.first ;
    //cout << legalMovest0[bestInd].second.second << " for eval " << resSubBestMove3.second << endl ;
    return legalMovest0[bestInd];
}*/

pair<string, pair<int, int>> bestMove5(string aBoard[8][8],int moveNb,bool wC1, bool wC2, bool bC1, bool bC2, int maxIter){

    // /!\ hardcodé pour une profodeur max de 2


    if (moveNb == 0) {
        pair<string, pair<int, int>> bestmove ;
        bestmove.first = "wP5" ;
        bestmove.second.first = 4 ;
        bestmove.second.second = 4 ;
        return bestmove ;

    }

    vector<pair<string, pair<int, int>>> legalMovest0 ;
    legalMovest0 = LegalMoves(aBoard,moveNb, wC1, wC2, bC2, bC2) ;

    pair<int, double> resSubBestMove = subBestMove5(aBoard, moveNb, wC1, wC2, bC2, bC2, maxIter) ;

    int bestInd = resSubBestMove.first ;

    return legalMovest0[bestInd];

}


pair<string, pair<int, int>> bestMove6(string aBoard[8][8],int moveNb,bool wC1, bool wC2, bool bC1, bool bC2, int maxIter){

    // /!\ hardcodé pour une profodeur max de 2


    if (moveNb == 0) {
        pair<string, pair<int, int>> bestmove ;
        bestmove.first = "wP5" ;
        bestmove.second.first = 4 ;
        bestmove.second.second = 4 ;
        return bestmove ;

    } else {

        vector<pair<string, pair<int, int>>> legalMovest0 ;
        legalMovest0 = LegalMoves(aBoard,moveNb, wC1, wC2, bC2, bC2) ;

        pair<int, double> resSubBestMove = subBestMove6(aBoard, moveNb, wC1, wC2, bC2, bC2, maxIter) ;

        int bestInd = resSubBestMove.first ;

        return legalMovest0[bestInd];
    }
}
