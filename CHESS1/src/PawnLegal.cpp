#include "PawnLegal.h"
#include "Check.h"

#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>

using namespace std;

void legalPawn(string currentPiece,pair<int,int> locCurrentPiece,
               vector<pair<string, pair<int, int>>>& legalMoves,string aBoard[8][8],
               char colorAlly, char colorEnnemy, int moveNb)
{

    pair<int,int> locTMP ;
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;

    if (colorAlly == 'w') {
        //advance 1
        if((locTMP.first -1 >= 0 ) // >= 1 parce qu'après c'est les promotions
        && (aBoard[locTMP.first-1][locTMP.second][0] == '*'))
        {
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
        }




        //advance 2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first == 6)
        && (aBoard[locTMP.first-2][locTMP.second][0] == '*')
        && (aBoard[locTMP.first-1][locTMP.second][0] == '*'))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-2 ;
            possibleNewLoc.second = locTMP.second;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
        }

        //take right
        //cout << "treating : " << currentPiece << "  " ;
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -1 >= 0 ) && (locTMP.second +1 < 8)
        && (aBoard[locTMP.first-1][locTMP.second+1][0] == colorEnnemy))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;

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
        }

        //take left
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -1 >= 0 ) && (locTMP.second -1 >= 0)
        && (aBoard[locTMP.first-1][locTMP.second-1][0] == colorEnnemy))
        {
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
        }
    }


    if (colorAlly == 'b') {
        //advance 1
        if((locTMP.first +1 < 8)
        && (aBoard[locTMP.first+1][locTMP.second][0] == '*'))
        {
            //cout << "got here" << endl;
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
        }

        //advance 2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first == 1)
        && (aBoard[locTMP.first+2][locTMP.second][0] == '*')
        && (aBoard[locTMP.first+1][locTMP.second][0] == '*'))
        {
            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+2 ;
            possibleNewLoc.second = locTMP.second;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            if (!MoveChecksAllyKing(aBoard,moveNb,currentPiece,possibleNewLoc)){
                legalMoves.push_back(newLegalMove);
            }
        }

        //take right
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first +1 < 8) && (locTMP.second +1 < 8)
        && (aBoard[locTMP.first+1][locTMP.second+1][0] == colorEnnemy))
        {

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

        }

        //take left
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first +1 < 8) && (locTMP.second -1 >= 0)
        && (aBoard[locTMP.first+1][locTMP.second-1][0] == colorEnnemy))
        {
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
        }
    }



}

void legalPawn2(string currentPiece,pair<int,int> locCurrentPiece,
               vector<pair<string, pair<int, int>>>& legalMoves,string aBoard[8][8],
               char colorAlly, char colorEnnemy)
{

    pair<int,int> locTMP ;
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;

    if (colorAlly == 'w') {
        //advance 1
        if((locTMP.first -1 >= 0 )
        && (aBoard[locTMP.first-1][locTMP.second][0] == '*'))
        {
            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }

        //advance 2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first == 6)
        && (aBoard[locTMP.first-2][locTMP.second][0] == '*')
        && (aBoard[locTMP.first-1][locTMP.second][0] == '*'))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-2 ;
            possibleNewLoc.second = locTMP.second;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }

        //take right
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -1 >= 0 ) && (locTMP.second +1 < 8)
        && (aBoard[locTMP.first-1][locTMP.second+1][0] == colorEnnemy))
        {
            //cout << "in while Right, locTMP.second = " << locTMP.second << endl;

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }

        //take left
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first -1 >= 0 ) && (locTMP.second -1 >= 0)
        && (aBoard[locTMP.first-1][locTMP.second-1][0] == colorEnnemy))
        {
            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first-1 ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }
    }


    if (colorAlly == 'b') {
        //advance 1
        if((locTMP.first +1 < 8)
        && (aBoard[locTMP.first+1][locTMP.second][0] == '*'))
        {
            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }

        //advance 2
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first == 1)
        && (aBoard[locTMP.first+2][locTMP.second][0] == '*')
        && (aBoard[locTMP.first+1][locTMP.second][0] == '*'))
        {
            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+2 ;
            possibleNewLoc.second = locTMP.second;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }

        //take right
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first +1 < 8) && (locTMP.second +1 < 8)
        && (aBoard[locTMP.first+1][locTMP.second+1][0] == colorEnnemy))
        {

            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second+1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }

        //take left
        locTMP.first = locCurrentPiece.first ;
        locTMP.second = locCurrentPiece.second ;
        if((locTMP.first +1 < 8) && (locTMP.second -1 >= 0)
        && (aBoard[locTMP.first+1][locTMP.second-1][0] == colorEnnemy))
        {
            //new loc
            pair<int,int> possibleNewLoc ;
            possibleNewLoc.first = locTMP.first+1 ;
            possibleNewLoc.second = locTMP.second-1;

            //new move
            pair<string, pair<int, int>> newLegalMove ;
            newLegalMove.first = currentPiece ;
            newLegalMove.second = possibleNewLoc ;
            legalMoves.push_back(newLegalMove);
        }
    }
}

