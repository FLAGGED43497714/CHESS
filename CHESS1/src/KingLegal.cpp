#include "KingLegal.h"
#include "Check.h"
#include "UpdateBoard.h"

#include <string>
#include <vector>
#include <iostream>

#include <unistd.h>

using namespace std;



void legalKing(string currentPiece,pair<int,int> locCurrentPiece,
               vector<pair<string, pair<int, int>>>& legalMoves,string aBoard[8][8],
               char colorAlly, char colorEnnemy, int moveNb,
               bool wC1, bool wC2, bool bC1, bool bC2)
{
    if (IsCheck(aBoard,moveNb)) {
        wC1 = false ;
        wC2 = false ;
        bC1 = false ;
        bC2 = false ;
    }

    //bot right
    pair<int,int> locTMP ;
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first + 1 < 8) && (locTMP.second + 1 < 8)
          && (aBoard[locTMP.first+1][locTMP.second+1][0] != colorAlly))
    {
        //cout << "in while Right, locTMP.second = " << locTMP.second << endl;

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

    //bot 1
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first + 1 < 8)
          && (aBoard[locTMP.first+1][locTMP.second][0] != colorAlly))
    {

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

    //bot left
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first + 1 < 8) && (locTMP.second -1 >= 0)
          && (aBoard[locTMP.first+1][locTMP.second-1][0] != colorAlly))
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

    //right
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.second + 1 < 8)
          && (aBoard[locTMP.first][locTMP.second+1][0] != colorAlly))
    {

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
    }

    //left
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.second - 1 >=0)
          && (aBoard[locTMP.first][locTMP.second-1][0] != colorAlly))
    {

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
    }


    //up right
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first -1 >= 0) && (locTMP.second + 1 < 8)
          && (aBoard[locTMP.first-1][locTMP.second+1][0] != colorAlly))
    {
        //cout << "in while up, locTMP.second = " << locTMP.second << endl;

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


    //up left
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first -1 >= 0) && (locTMP.second -1 >= 0)
          && (aBoard[locTMP.first-1][locTMP.second-1][0] != colorAlly))
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

    //up
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first - 1 >=0)
          && (aBoard[locTMP.first-1][locTMP.second][0] != colorAlly))
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



    //castle short
    if (moveNb % 2 == 0) {
        if (wC2) {
            if ((aBoard[7][4] == "wK") && (aBoard[7][5] == "*") && (aBoard[7][6] == "*") &&  (aBoard[7][7] == "wR2")){
                /*cout << "In short castle";
                sleep(0.5);
                bool crossingCheck = false ;
                updateBoard2("wK", locCurrentPiece.first, locCurrentPiece.second+1, aBoard) ;
                //cout << "right" ;
                if (IsCheck(aBoard, moveNb)){
                    crossingCheck = true ;
                }
                updateBoard2("wK", locCurrentPiece.first, locCurrentPiece.second-1, aBoard) ;
                //cout << "left" ;
                if (!crossingCheck){*/
                    //new loc
                    pair<int,int> possibleNewLoc ;
                    possibleNewLoc.first = -1 ;
                    possibleNewLoc.second = -1;

                    //new move
                    pair<string, pair<int, int>> newLegalMove ;
                    newLegalMove.first = "O-O" ;
                    newLegalMove.second = possibleNewLoc ;
                    legalMoves.push_back(newLegalMove);

                //}

            }
        }
    } else {
        if (bC2) {
            if (aBoard[0][4] == "bK" && aBoard[0][5] == "*" && aBoard[0][6] == "*" &&  (aBoard[0][7] == "bR2")){
                /*cout << "In short castle black";
                sleep(3);
                //new loc
                updateBoard2("bK", locCurrentPiece.first, locCurrentPiece.second+1, aBoard) ;
                if (!IsCheck(aBoard, moveNb)){*/
                    pair<int,int> possibleNewLoc ;
                    possibleNewLoc.first = -1 ;
                    possibleNewLoc.second = -1;

                    //new move
                    pair<string, pair<int, int>> newLegalMove ;
                    newLegalMove.first = "o-o" ;
                    newLegalMove.second = possibleNewLoc ;
                    legalMoves.push_back(newLegalMove);
                /*}
                updateBoard2("bK", locCurrentPiece.first, locCurrentPiece.second-1, aBoard) ;*/
            }
        }
    }

    //castle long

    if (moveNb % 2 == 0) {
        if (wC1) {
            if ((aBoard[7][0] == "wR1") && (aBoard[7][1] == "*") && (aBoard[7][2] == "*") && (aBoard[7][3] == "*") && (aBoard[7][4] == "wK")){
                //new loc
                /*cout << "In long castle";
                sleep(3);
                updateBoard2("wK", locCurrentPiece.first, locCurrentPiece.second-1, aBoard) ;
                if (!IsCheck(aBoard, moveNb)){*/
                pair<int,int> possibleNewLoc ;
                possibleNewLoc.first = -1 ;
                possibleNewLoc.second = -1;

                //new move
                pair<string, pair<int, int>> newLegalMove ;
                newLegalMove.first = "O-O-O" ;
                newLegalMove.second = possibleNewLoc ;
                legalMoves.push_back(newLegalMove);
                /*}
                updateBoard2("wK", locCurrentPiece.first, locCurrentPiece.second+1, aBoard) ;*/


            }
        }
    } else {
        if (bC1) {
            if ((aBoard[0][0] == "bR1") && (aBoard[0][1] == "*") && (aBoard[0][2] == "*") && (aBoard[0][3] == "*") && (aBoard[0][4] == "bK")){
                /*cout << "In long castle";
                sleep(3);
                updateBoard2("bK", locCurrentPiece.first, locCurrentPiece.second-1, aBoard) ;
                if (!IsCheck(aBoard, moveNb)){*/
                //new loc
                pair<int,int> possibleNewLoc ;
                possibleNewLoc.first = -1 ;
                possibleNewLoc.second = -1;

                //new move
                pair<string, pair<int, int>> newLegalMove ;
                newLegalMove.first = "o-o-o" ;
                newLegalMove.second = possibleNewLoc ;
                legalMoves.push_back(newLegalMove);
                /*}
                updateBoard2("bK", locCurrentPiece.first, locCurrentPiece.second+1, aBoard) ;*/
            }
        }
    }


}









void legalKing2(string currentPiece,pair<int,int> locCurrentPiece,
               vector<pair<string, pair<int, int>>>& legalMoves,string aBoard[8][8],
               char colorAlly, char colorEnnemy)
{

    //bot right
    pair<int,int> locTMP ;
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first + 1 < 8) && (locTMP.second + 1 < 8)
          && (aBoard[locTMP.first+1][locTMP.second+1][0] != colorAlly))
    {
        //cout << "in while Right, locTMP.second = " << locTMP.second << endl;

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

    //bot 1
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first + 1 < 8)
          && (aBoard[locTMP.first+1][locTMP.second][0] != colorAlly))
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

    //bot left
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first + 1 < 8) && (locTMP.second -1 >= 0)
          && (aBoard[locTMP.first+1][locTMP.second-1][0] != colorAlly))
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

    //right
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.second + 1 < 8)
          && (aBoard[locTMP.first][locTMP.second+1][0] != colorAlly))
    {

        //new loc
        pair<int,int> possibleNewLoc ;
        possibleNewLoc.first = locTMP.first ;
        possibleNewLoc.second = locTMP.second+1;

        //new move
        pair<string, pair<int, int>> newLegalMove ;
        newLegalMove.first = currentPiece ;
        newLegalMove.second = possibleNewLoc ;
        legalMoves.push_back(newLegalMove);
    }

    //left
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.second - 1 >=0)
          && (aBoard[locTMP.first][locTMP.second-1][0] != colorAlly))
    {

        //new loc
        pair<int,int> possibleNewLoc ;
        possibleNewLoc.first = locTMP.first ;
        possibleNewLoc.second = locTMP.second-1;

        //new move
        pair<string, pair<int, int>> newLegalMove ;
        newLegalMove.first = currentPiece ;
        newLegalMove.second = possibleNewLoc ;
        legalMoves.push_back(newLegalMove);
    }


    //up right
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first -1 >= 0) && (locTMP.second + 1 < 8)
          && (aBoard[locTMP.first-1][locTMP.second+1][0] != colorAlly))
    {
        //cout << "in while up, locTMP.second = " << locTMP.second << endl;

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


    //up left
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first -1 >= 0) && (locTMP.second -1 >= 0)
          && (aBoard[locTMP.first-1][locTMP.second-1][0] != colorAlly))
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

    //up
    locTMP.first = locCurrentPiece.first ;
    locTMP.second = locCurrentPiece.second ;
    if((locTMP.first - 1 >=0)
          && (aBoard[locTMP.first-1][locTMP.second][0] != colorAlly))
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


        //castle short
    if (colorAlly == 'w') {

            if ((aBoard[7][4] == "wK") && (aBoard[7][5] == "*") && (aBoard[7][6] == "*") &&  (aBoard[7][7] == "wR2")){
                /*cout << "In short castle";
                sleep(0.5);
                bool crossingCheck = false ;
                updateBoard2("wK", locCurrentPiece.first, locCurrentPiece.second+1, aBoard) ;
                //cout << "right" ;
                if (IsCheck(aBoard, moveNb)){
                    crossingCheck = true ;
                }
                updateBoard2("wK", locCurrentPiece.first, locCurrentPiece.second-1, aBoard) ;
                //cout << "left" ;
                if (!crossingCheck){*/
                    //new loc
                    pair<int,int> possibleNewLoc ;
                    possibleNewLoc.first = -1 ;
                    possibleNewLoc.second = -1;

                    //new move
                    pair<string, pair<int, int>> newLegalMove ;
                    newLegalMove.first = "O-O" ;
                    newLegalMove.second = possibleNewLoc ;
                    legalMoves.push_back(newLegalMove);

                //}

            }
        } else {

            if (aBoard[0][4] == "bK" && aBoard[0][5] == "*" && aBoard[0][6] == "*" &&  (aBoard[0][7] == "bR2")){
                /*cout << "In short castle black";
                sleep(3);
                //new loc
                updateBoard2("bK", locCurrentPiece.first, locCurrentPiece.second+1, aBoard) ;
                if (!IsCheck(aBoard, moveNb)){*/
                    pair<int,int> possibleNewLoc ;
                    possibleNewLoc.first = -1 ;
                    possibleNewLoc.second = -1;

                    //new move
                    pair<string, pair<int, int>> newLegalMove ;
                    newLegalMove.first = "o-o" ;
                    newLegalMove.second = possibleNewLoc ;
                    legalMoves.push_back(newLegalMove);
                /*}
                updateBoard2("bK", locCurrentPiece.first, locCurrentPiece.second-1, aBoard) ;*/
            }
        }


    //castle long

    if (colorAlly = 'w') {
            if ((aBoard[7][0] == "wR1") && (aBoard[7][1] == "*") && (aBoard[7][2] == "*") && (aBoard[7][3] == "*") && (aBoard[7][4] == "wK")){
                //new loc
                /*cout << "In long castle";
                sleep(3);
                updateBoard2("wK", locCurrentPiece.first, locCurrentPiece.second-1, aBoard) ;
                if (!IsCheck(aBoard, moveNb)){*/
                pair<int,int> possibleNewLoc ;
                possibleNewLoc.first = -1 ;
                possibleNewLoc.second = -1;

                //new move
                pair<string, pair<int, int>> newLegalMove ;
                newLegalMove.first = "O-O-O" ;
                newLegalMove.second = possibleNewLoc ;
                legalMoves.push_back(newLegalMove);
                /*}
                updateBoard2("wK", locCurrentPiece.first, locCurrentPiece.second+1, aBoard) ;*/


            }
    } else {
            if ((aBoard[0][0] == "bR1") && (aBoard[0][1] == "*") && (aBoard[0][2] == "*") && (aBoard[0][3] == "*") && (aBoard[0][4] == "bK")){

                //new loc
                pair<int,int> possibleNewLoc ;
                possibleNewLoc.first = -1 ;
                possibleNewLoc.second = -1;

                //new move
                pair<string, pair<int, int>> newLegalMove ;
                newLegalMove.first = "o-o-o" ;
                newLegalMove.second = possibleNewLoc ;
                legalMoves.push_back(newLegalMove);
                /*}
                updateBoard2("bK", locCurrentPiece.first, locCurrentPiece.second+1, aBoard) ;*/
            }
        }
}


