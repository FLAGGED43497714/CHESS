#include <iostream>
#include <string>
#include <coutBoard.h>
#include <initboard.h>
#include <UpdateBoard.h>
#include <legal.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <chrono>


//pour test
#include "boardEval.h"
#include "Check.h"
#include <MoveInstructions.h>

//using namespace std::chrono ;

using namespace std;

/*void ajouteDeuxRef(bool &a){
    a = false ;
}*/

int main()
{
    bool whiteHuman (false);
    bool blackHuman = true;

    int moveNb = 0 ;
    string board[8][8] ;

    //string fen = "r4r2/ppp2pk1/8/8/P3q3/1P3nPP/2p2bR1/7K" ; //mat en 3 avec échec sur le 1e move
    //string fen = "8/1P4k1/8/8/8/4K3/8/8" ; //promotion
    //string fen = "3k4/2R5/3P1N2/B7/8/p6P/PP3PP1/6KR" ; //stalemates

    //string fen = "8/3r4/8/8/7k/3Q4/2P4K/8" ;
    //string fen = "r1bqk1nr/pppp1ppp/2n5/2bPp3/4P3/2P5/PP3PPP/RNBQKBNR" ; //position buggé pour legalmove2

    //string fen = "r2qk2r/ppp1bppp/2b1p3/4P3/3Pp3/P3B3/1PP1NPPP/R2QK2R" ;

    string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR" ;


    initFenBoard(board, fen);
    coutBoard(board);

    bool wC1 = true ;
    bool wC2 = true ;
    bool bC1 = true ;
    bool bC2 = true ;

    string nextPiece ;
    string nextDest ;

    int nextLine ;
    int nextCol ;

    //bool isWhiteTurn(moveNb % 2 == 0) ;

    string possibleBoard[8][8];
    vector<pair<string, pair<int, int>>> legalMoves;
    pair<string, pair<int, int>> theBestMove ;

    while(true){
        //string nothing ;
        //cin >> nothing ;
        bool isLegal (false);

        //bool isCheck = IsCheck(board,moveNb) ;
        //cout << "Is check : " << isCheck << endl ;
        //sleep(0.5) ;

        while(!isLegal){
            //update board on console
            system("cls");
            coutBoard(board);

            double boardEval = eval(board,moveNb-1, wC1, wC2, bC1, bC2);
            cout << "eval t0 : " << boardEval/100 << endl;

            //turn
            if (moveNb % 2 == 0){cout << "White";} else {cout << "Black";} cout << " to play" << endl ;

            if (moveNb % 2 == 0){
                //theBestMove = bestMove(legalMoves,board,moveNb);

                if(!whiteHuman){
                //auto start = high_resolution_clock::now();
                theBestMove = bestMove5(board,moveNb,wC1, wC2, bC1, bC2,3);
                //auto stop = high_resolution_clock::now();
                //auto duration = duration_cast<milliseconds>(stop - start);
                //cout << duration.count() << endl;
                //sleep(3);

                nextPiece = theBestMove.first ;
                nextLine = theBestMove.second.first;
                nextCol = theBestMove.second.second;

                isLegal = true ;
                } else {





                //next move

                cout << "next piece ? " ;
                cin >> nextPiece;
                cin.ignore();

                //pos of next piece
                pair<int,int> pLoc ;
                pLoc = findPiece(nextPiece,board);
                cout << pLoc.first << endl;
                cout << pLoc.second << endl;

                //ask dest
                cout << "Destination ? " ;
                cin >> nextDest;
                cin.ignore();

                isLegal = IsLegal(nextPiece, nextDest, board, moveNb, wC1, wC2, bC2, bC2) ;
                }






            } else {
                //black turn, computer plays
                //legalMoves = LegalMoves(board, moveNb) ;
                /*int randint = rand() % legalMoves.size();
                nextPiece = legalMoves[randint].first ;
                nextLine = legalMoves[randint].second.first ;
                nextCol = legalMoves[randint].second.second ;
                */
                //theBestMove = bestMove(legalMoves,board,moveNb);


                if (!blackHuman){
                //auto start = high_resolution_clock::now();
                theBestMove = bestMove5(board, moveNb, wC1, wC2, bC1, bC2, 3);
                //auto stop = high_resolution_clock::now();
                //auto duration = duration_cast<milliseconds>(stop - start);
                //cout << duration.count() << endl;
                //sleep(3);
                nextPiece = theBestMove.first ;
                nextLine = theBestMove.second.first;
                nextCol = theBestMove.second.second;

                isLegal = true;
                }
                else {

                //next move

                cout << "next piece ? " ;
                cin >> nextPiece;
                cin.ignore();

                //pos of next piece
                pair<int,int> pLoc ;
                pLoc = findPiece(nextPiece,board);
                cout << pLoc.first << endl;
                cout << pLoc.second << endl;

                //ask dest
                cout << "Destination ? " ;
                cin >> nextDest;
                cin.ignore();

                isLegal = IsLegal(nextPiece, nextDest, board, moveNb,wC1, wC2, bC1, bC2) ;
                }







            }


        }
        if (moveNb % 2 == 0) {
            if (whiteHuman){
                updateBoard1(nextPiece,nextDest, board);
            } else {
                updateBoard2(nextPiece, nextLine, nextCol, board) ;
            }
        } else {
            if (blackHuman){
                updateBoard1(nextPiece,nextDest, board);
            } else {
                updateBoard2(nextPiece, nextLine, nextCol, board) ;
            }
        }
        system("cls");
        coutBoard(board);
        //sleep(10);
        moveNb++;

        }

 return 0;
}
