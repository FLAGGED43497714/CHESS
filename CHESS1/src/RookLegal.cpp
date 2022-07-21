#include "RookLegal.h"
#include "Check.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

void legalRook(string currentPiece,pair<int,int> locCurrentPiece,
               vector<pair<string, pair<int, int>>>& legalMoves,string aBoard[8][8],
               char colorAlly, char colorEnnemy, int moveNb)
   {

        //right
        pair<int,int> locTMP ;
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        bool hasCaptured (false);
        while((locTMP.second + 1 < 8)
              && (aBoard[locTMP.first][locTMP.second+1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first][locTMP.second+1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
            locTMP.second += 1 ;
        }

        //left
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.second -1 >= 0)
              && (aBoard[locTMP.first][locTMP.second-1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while Left, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first][locTMP.second-1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
            locTMP.second -= 1 ;

        }

        //up
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.first -1 >= 0)
              && (aBoard[locTMP.first-1][locTMP.second][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while up, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first-1][locTMP.second][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
            locTMP.first -= 1 ;
        }


        //down
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.first +1 < 8)
              && (aBoard[locTMP.first+1][locTMP.second][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while down, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first+1][locTMP.second][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
            locTMP.first += 1 ;
        }


   }

void legalRook2(string currentPiece,pair<int,int> locCurrentPiece,
               vector<pair<string, pair<int, int>>>& legalMoves,string aBoard[8][8],
               char colorAlly, char colorEnnemy)
   {

        //right
        pair<int,int> locTMP ;
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        bool hasCaptured (false);
        while((locTMP.second + 1 < 8)
              && (aBoard[locTMP.first][locTMP.second+1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first][locTMP.second+1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
            locTMP.second += 1 ;
        }

        //left
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.second -1 >= 0)
              && (aBoard[locTMP.first][locTMP.second-1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while Left, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first][locTMP.second-1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
            locTMP.second -= 1 ;

        }

        //up
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.first -1 >= 0)
              && (aBoard[locTMP.first-1][locTMP.second][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while up, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first-1][locTMP.second][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
            locTMP.first -= 1 ;
        }


        //down
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.first +1 < 8)
              && (aBoard[locTMP.first+1][locTMP.second][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while down, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first+1][locTMP.second][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
            locTMP.first += 1 ;
        }
   }

