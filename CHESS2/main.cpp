#include "Game.h"
#include "initBoard.h"
#include "MakeMove.h"
#include "LegalMoves.h"
#include "coutBoard.h"
#include "BitwiseFunction.h"
#include "SqNameToNb.h"
#include "Eval.h"

#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>





int main()
{



    /*for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            std::cout << 8*line + col << std::endl;
            std::cout << rZobTable[line][col] << std::endl ;
        }
    }*/

    /*std::unordered_map<unsigned long long int, int> ump ;
    std::unordered_map<unsigned long long int, int>::iterator it ;

    ump.insert(std::pair<unsigned long long int, int>(1, 100));
    ump.insert(std::pair<unsigned long long int, int>(1, 22));

    it = ump.find(1); //Finding an element

    if(it == ump.end())
        std::cout <<std::endl<< "Key-value pair not present in hash map" ;
    else
        std::cout <<std::endl<< "Key-value pair present : "
          << it->first << "->" << it->second ;*/

    /*std::string nothing ;

    unsigned long long int r,n,b,q,k,p,R,N,B,Q,K,P;

    std::string zero = "8/8/8/8/8/8/8/8" ;
    std::string fen = "rr3k3/pQp1np2/8/3Pn3/8/5qr1/5N1P/6KR" ;

    initFromFEN(zero,r,n,b,q,k,p,R,N,B,Q,K,P);
    initFromFEN(fen,r,n,b,q,k,p,R,N,B,Q,K,P);


    bool CstlL = true;
    bool CstlS = true;
    bool cstlL = true;
    bool cstlS = true;

    bool brokeCastleS = false;
    bool brokeCastleL = false;
    bool brokecastleS = false;
    bool brokecastleL = false;

    int pieceCaptured = 0 ;
    bool wasCastle = false ;
    bool wasPromote = false ;






    /*coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
    std::cin >> nothing ;


    Do_move(3,1,CstlL,CstlS,cstlL,cstlL,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P,wasCastle, wasPromote, pieceCaptured) ;

    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
    std::cin >> nothing ;

    Undo_move(3,1,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,wasCastle, wasPromote, pieceCaptured,CstlL,CstlS,cstlL,cstlS,r,n,b,q,k,p,R,N,B,Q,K,P);
    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
    std::cin >> nothing ;*/



    Game(4,10) ;


    return 0;
}
