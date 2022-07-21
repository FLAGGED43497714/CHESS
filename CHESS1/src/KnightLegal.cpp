#include "KnightLegal.h"
#include "Check.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;



void legalKnight(string currentPiece,pair<int,int> locCurrentPiece,
               vector<pair<string, pair<int, int>>>& legalMoves,string aBoard[8][8],
               char colorAlly, char colorEnnemy, int moveNb)
   {

        //bot 2 right 1
        pair<int,int> locTMP ;
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first + 2 < 8) && (locTMP.second + 1 < 8)
              && (aBoard[locTMP.first+2][locTMP.second+1][0] != colorAlly))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+2 ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
        }

        //bot 1 right 2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first + 1 < 8) && (locTMP.second + 2 < 8)
              && (aBoard[locTMP.first+1][locTMP.second+2][0] != colorAlly))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second+2;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
        }

        //bot +2 left -1
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first + 2 < 8) && (locTMP.second -1 >= 0)
              && (aBoard[locTMP.first+2][locTMP.second-1][0] != colorAlly))
        {
            //cout << "in while Left, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+2 ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
        }

        //bot +1 left -2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first + 1 < 8) && (locTMP.second -2 >= 0)
              && (aBoard[locTMP.first+1][locTMP.second-2][0] != colorAlly))
        {
            //cout << "in while Left, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second-2;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
        }


        //up 2 right 1
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -2 >= 0) && (locTMP.second + 1 < 8)
              && (aBoard[locTMP.first-2][locTMP.second+1][0] != colorAlly))
        {
            //cout << "in while up, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-2 ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
        }

        //up 1 right 2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -1 >= 0) && (locTMP.second + 2 < 8)
              && (aBoard[locTMP.first-1][locTMP.second+2][0] != colorAlly))
        {
            //cout << "in while up, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second+2;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
        }


        //up 2 left 1
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -2 >= 0) && (locTMP.second -1 >= 0)
              && (aBoard[locTMP.first-2][locTMP.second-1][0] != colorAlly))
        {
            //cout << "in while down, locTMP.second = " << locTMP.second << endl;
            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-2 ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
        }

        //up 1 left 2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -1 >= 0) && (locTMP.second -2 >= 0)
              && (aBoard[locTMP.first-1][locTMP.second-2][0] != colorAlly))
        {
            //cout << "in while down, locTMP.second = " << locTMP.second << endl;
            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second-2;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }

        }



   }

void legalKnight2(string currentPiece,pair<int,int> locCurrentPiece,
               vector<pair<string, pair<int, int>>>& legalMoves,string aBoard[8][8],
               char colorAlly, char colorEnnemy)
   {

        //bot 2 right 1
        pair<int,int> locTMP ;
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first + 2 < 8) && (locTMP.second + 1 < 8)
              && (aBoard[locTMP.first+2][locTMP.second+1][0] != colorAlly))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+2 ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }

        //bot 1 right 2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first + 1 < 8) && (locTMP.second + 2 < 8)
              && (aBoard[locTMP.first+1][locTMP.second+2][0] != colorAlly))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second+2;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }

        //bot +2 left -1
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first + 2 < 8) && (locTMP.second -1 >= 0)
              && (aBoard[locTMP.first+2][locTMP.second-1][0] != colorAlly))
        {
            //cout << "in while Left, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+2 ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }

        //bot +1 left -2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first + 1 < 8) && (locTMP.second -2 >= 0)
              && (aBoard[locTMP.first+1][locTMP.second-2][0] != colorAlly))
        {
            //cout << "in while Left, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second-2;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }


        //up 2 right 1
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -2 >= 0) && (locTMP.second + 1 < 8)
              && (aBoard[locTMP.first-2][locTMP.second+1][0] != colorAlly))
        {
            //cout << "in while up, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-2 ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }

        //up 1 right 2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -1 >= 0) && (locTMP.second + 2 < 8)
              && (aBoard[locTMP.first-1][locTMP.second+2][0] != colorAlly))
        {
            //cout << "in while up, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second+2;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }


        //up 2 left 1
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -2 >= 0) && (locTMP.second -1 >= 0)
              && (aBoard[locTMP.first-2][locTMP.second-1][0] != colorAlly))
        {
            //cout << "in while down, locTMP.second = " << locTMP.second << endl;
            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-2 ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }

        //up 1 left 2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -1 >= 0) && (locTMP.second -2 >= 0)
              && (aBoard[locTMP.first-1][locTMP.second-2][0] != colorAlly))
        {
            //cout << "in while down, locTMP.second = " << locTMP.second << endl;
            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second-2;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);

        }



   }


