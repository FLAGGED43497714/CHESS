#include "BishopLegal.h"
#include "Check.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;



void legalBishop(string currentPiece,pair<int,int> locCurrentPiece,
               vector<pair<string, pair<int, int>>>& legalMoves,string aBoard[8][8],
               char colorAlly, char colorEnnemy,int moveNb)
{

        //bot right
        pair<int,int> locTMP ;
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        bool hasCaptured (false);
        while((locTMP.second + 1 < 8) && (locTMP.first + 1 < 8)
              && (aBoard[locTMP.first+1][locTMP.second+1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first+1][locTMP.second+1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;

            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
            locTMP.second += 1 ;
            locTMP.first +=1 ;
        }

        //bot left
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.second -1 >= 0) && (locTMP.first + 1 < 8)
              && (aBoard[locTMP.first+1][locTMP.second-1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while Left, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first+1][locTMP.second-1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;

            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
            locTMP.second -= 1 ;
            locTMP.first += 1 ;

        }

        //up right
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.first -1 >= 0) && (locTMP.second + 1 < 8)
              && (aBoard[locTMP.first-1][locTMP.second+1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while up, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first-1][locTMP.second+1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
            locTMP.first -= 1 ;
            locTMP.second += 1 ;
        }


        //up left
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.first -1 >= 0) && (locTMP.second -1 >= 0)
              && (aBoard[locTMP.first-1][locTMP.second-1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while down, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first-1][locTMP.second-1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
            locTMP.first -= 1 ;
            locTMP.second -= 1 ;
        }


}

void legalBishop2(string currentPiece,pair<int,int> locCurrentPiece,
               vector<pair<string, pair<int, int>>>& legalMoves,string aBoard[8][8],
               char colorAlly, char colorEnnemy)
{

        //bot right
        pair<int,int> locTMP ;
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        bool hasCaptured (false);
        while((locTMP.second + 1 < 8) && (locTMP.first + 1 < 8)
              && (aBoard[locTMP.first+1][locTMP.second+1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first+1][locTMP.second+1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;

            legalMoves.push_back(newLegalMove);
            locTMP.second += 1 ;
            locTMP.first +=1 ;
        }

        //bot left
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.second -1 >= 0) && (locTMP.first + 1 < 8)
              && (aBoard[locTMP.first+1][locTMP.second-1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while Left, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first+1][locTMP.second-1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;

            legalMoves.push_back(newLegalMove);
            locTMP.second -= 1 ;
            locTMP.first += 1 ;

        }

        //up right
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.first -1 >= 0) && (locTMP.second + 1 < 8)
              && (aBoard[locTMP.first-1][locTMP.second+1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while up, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first-1][locTMP.second+1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
            locTMP.first -= 1 ;
            locTMP.second += 1 ;
        }


        //up left
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        hasCaptured = false;
        while((locTMP.first -1 >= 0) && (locTMP.second -1 >= 0)
              && (aBoard[locTMP.first-1][locTMP.second-1][0] != colorAlly)
              && (!hasCaptured))
        {
            //cout << "in while down, locTMP.second = " << locTMP.second << endl;
            if (aBoard[locTMP.first-1][locTMP.second-1][0] == colorEnnemy){
                hasCaptured = true;
            }

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
            locTMP.first -= 1 ;
            locTMP.second -= 1 ;
        }


}
