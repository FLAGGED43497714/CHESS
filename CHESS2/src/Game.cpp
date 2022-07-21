#include "Game.h"

#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <limits>
#include <unistd.h>
#include <unordered_map>

#include "coutBoard.h"
#include "initBoard.h"
#include "LegalMoves.h"
#include "MakeMove.h"
#include "ChoseMove.h"
#include "SqNameToNb.h"
#include "BitwiseFunction.h"


int GAMEintINFINITY = std::numeric_limits<int>::max() ;


void Game(int depth1, int depth2){
    std::string nothing ;
    //std::cin >> nothing ;

    bool verbose = false ;

    bool whiteHuman = true  ;
    bool blackHuman = 1 - whiteHuman;

    unsigned long long int r,n,b,q,k,p,R,N,B,Q,K,P;

    std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR" ;

    //std::string fen = "r2qkb1r/ppp2ppp/2np1n2/4p3/2B1P1b1/2P1QP2/PP1P2PP/RNB1K1NR" ; //bug sur 2 moves d'affilé


    bool wantEval (false) ;

    initFromFEN(fen,r,n,b,q,k,p,R,N,B,Q,K,P) ;

    std::vector<int> moves ;

    int moveNb = 0 ;

    unsigned long long int occupied ;
    unsigned long long int blackPieces ;
    unsigned long long int whitePieces ;

    unsigned long long int enPassant (0);
    unsigned long long int tempEnPassant ;

    std::string strPosition ;
    int position ;
    std::string strDestination ;
    int destination ;

    bool CstlL = true;
    bool CstlS = true;
    bool cstlL = true;
    bool cstlS = true;

    bool brokeCastleS = false;
    bool brokeCastleL = false;
    bool brokecastleS = false;
    bool brokecastleL = false;

    int pieceCaptured (0);
    bool wasCastle (false);
    bool wasPromote (false);


    bool legal = false ;

    int bestInd ;
    int thisEval ;
    int bestEval ;

    //move ordering
    int captInd ; //p
    int captInd2 ; // n b
    int captInd3 ; // r
    int captInd4 ; // q
    int captInd5 ; // k
    int dest ;
    unsigned long long int destInt ;
    int temp1 ;
    int temp2 ;

    int alpha ;
    int beta ;

    unsigned long long int forbCstlS (0) ; //12
    unsigned long long int tempForbCstlS ;
    unsigned long long int forbCstlL (0) ; //24
    unsigned long long int tempForbCstlL ;
    unsigned long long int forbcstlS (0) ; //864691128455135232
    unsigned long long int tempForbcstlS ;
    unsigned long long int forbcstlL (0) ; //1729382256910270464
    unsigned long long int tempForbcstlL ;

    extern std::unordered_map<unsigned long long int, std::pair<int,int>> ump ;
    extern std::unordered_map<unsigned long long int, std::pair<int,int>>::iterator it ;

    extern unsigned long long int rZobTable[8][8] ;
    extern unsigned long long int nZobTable[8][8] ;
    extern unsigned long long int bZobTable[8][8] ;
    extern unsigned long long int qZobTable[8][8] ;
    extern unsigned long long int kZobTable[8][8] ;
    extern unsigned long long int pZobTable[8][8] ;

    extern unsigned long long int RZobTable[8][8] ;
    extern unsigned long long int NZobTable[8][8] ;
    extern unsigned long long int BZobTable[8][8] ;
    extern unsigned long long int QZobTable[8][8] ;
    extern unsigned long long int KZobTable[8][8] ;
    extern unsigned long long int PZobTable[8][8] ;

    int bestMove1 ;
    int bestMove2 ;

    int depthInit ;


    unsigned long long int positionHash ;

    initZob(rZobTable,nZobTable,bZobTable,qZobTable,kZobTable,pZobTable,RZobTable,NZobTable,BZobTable,QZobTable,KZobTable,PZobTable) ;

    while(true){
        //std::cout << enPassant ;

        depthInit = depth1 ;
        pieceCaptured = 0 ;
        wasCastle = false ;
        wasPromote = false ;
        brokeCastleS = false ;
        brokeCastleL = false ;
        brokecastleS = false ;
        brokecastleL = false ;




        //std::cin >> nothing ;
        system("cls");
        std::cout << "CstlS " << CstlS << " CstlL "<< CstlL << " cstlS "<< cstlS <<" cstlL "<< cstlL << std::endl ;
        std::cout << "eval : "<< (double)bestEval/100 << std::endl ;

        coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;

        /*std::cout << std::endl ;
        std::cout << "  1> " <<bestMove1 << "   2> "<<bestMove2 <<std::endl ;
        std::cout << std::endl ;*/


        if (verbose){
            std::cin >> nothing ;
        }
        if (!(moveNb%2)){std::cout << "white " ;} else {std::cout << "black " ;}std::cout << "to play" << std::endl;



        moves.clear();
        occupied = r | n | b | q | k | p | R | N | B | Q | K | P ;
        blackPieces = r | n | b | q | k | p ;
        whitePieces = R | N | B | Q | K | P ;




        if (!(moveNb%2)){

            if (whiteHuman){
                legal = false ;

                legPaW(moves, P, whitePieces, blackPieces, occupied, enPassant) ;
                sliderHV(moves, R, whitePieces, occupied) ;
                sliderHV(moves, Q, whitePieces, occupied) ;
                sliderD(moves, B, whitePieces, occupied) ;
                sliderCD(moves, B, whitePieces, occupied) ;
                sliderD(moves, Q, whitePieces, occupied) ;
                sliderCD(moves, Q, whitePieces, occupied) ;
                KnightMoves(moves, N, whitePieces) ;
                KingMoves(moves, K, R, whitePieces, occupied, CstlL, CstlS, cstlL, cstlS) ;



                while (!legal){
                    std::cout << "position ?" << std::endl;
                    std::cin >> strPosition ;
                    std::cin.ignore() ;

                    position = SquareNameToNb(strPosition) ;


                    std::cout << "destination ?" << std::endl;
                    std::cin >> strDestination ;
                    std::cin.ignore() ;

                    destination = SquareNameToNb(strDestination) ;

                    for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                        if ((moves[2*semIdx] == position) && (moves[2*semIdx+1] == destination)) {
                            Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle,wasPromote,pieceCaptured,positionHash);
                            //isEnPassant(lastMove, enPassant, P, true) ;
                            legal = true ;


                        }
                    }
                    if (!legal){
                        system("cls");
                        coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                        std::cout << "illegal" << std::endl;
                        if (!(moveNb%2)){std::cout << "white " ;} else {std::cout << "black " ;}std::cout << "to play" << std::endl;
                    }
                }
            } else { // white not human
                legPaW(moves, P, whitePieces, blackPieces, occupied, enPassant) ;
                sliderD(moves, B, whitePieces, occupied) ;
                sliderCD(moves, B, whitePieces, occupied) ;
                KnightMoves(moves, N, whitePieces) ;
                sliderHV(moves, Q, whitePieces, occupied) ;
                sliderD(moves, Q, whitePieces, occupied) ;
                sliderCD(moves, Q, whitePieces, occupied) ;
                sliderHV(moves, R, whitePieces, occupied) ;
                KingMoves(moves, K, R, whitePieces, occupied, CstlL, CstlS, cstlL, cstlS) ;



                captInd = 0 ;
                captInd2 = 0 ;
                captInd3 = 0 ;
                captInd4 = 0 ;

                for (int semInd = 1 ; semInd < moves.size()/2 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&blackPieces){
                        temp1 = moves[2*captInd] ;
                        temp2 = moves[2*captInd+1] ;
                        moves[2*captInd] = moves[2*semInd] ;
                        moves[2*captInd+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(q|r|n|b)){
                        temp1 = moves[2*captInd2] ;
                        temp2 = moves[2*captInd2+1] ;
                        moves[2*captInd2] = moves[2*semInd] ;
                        moves[2*captInd2+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd2 +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd2 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(q|r)){
                        temp1 = moves[2*captInd3] ;
                        temp2 = moves[2*captInd3+1] ;
                        moves[2*captInd3] = moves[2*semInd] ;
                        moves[2*captInd3+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd3 +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd3 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(q)){
                        temp1 = moves[2*captInd4] ;
                        temp2 = moves[2*captInd4+1] ;
                        moves[2*captInd4] = moves[2*semInd] ;
                        moves[2*captInd4+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd4 +=1 ;
                    }
                }



                bestInd = 0 ;
                thisEval = -GAMEintINFINITY ;
                bestEval = -GAMEintINFINITY ;

                ump.clear() ;
                positionHash = ZobristHash(r,n,b,q,k,p,R,N,B,Q,K,P, CstlS,CstlL,cstlS,cstlL, true) ;

                alpha = -GAMEintINFINITY;
                beta = GAMEintINFINITY;

                tempEnPassant = enPassant ;
                tempForbCstlS = forbCstlS ;
                tempForbCstlL = forbCstlL ;
                tempForbcstlS = forbcstlS ;
                tempForbcstlL = forbcstlL ;



                for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                    thisEval = -GAMEintINFINITY ;
                    position = moves[2*semIdx] ;
                    destination = moves[2*semIdx+1] ;
                    //std::cout << position << std::endl ;
                    //std::cout << destination << std::endl ;
                    pieceCaptured = 0 ;
                    wasCastle = false ;
                    wasPromote = false ;
                    brokeCastleS = false ;
                    brokeCastleL = false ;
                    brokecastleS = false ;
                    brokecastleL = false ;
                    //std::cout << "position = " << position << std::endl ;
                    //std::cout << "destination = " << destination << std::endl ;
                    //std::cout << "wasCastle = " << wasCastle << std::endl ;
                    //std::cout << "pieceCaptured = " << pieceCaptured << std::endl ;

                    //std::cout << "before do move : " << pieceCaptured << wasCastle << wasPromote << std::endl;

                    Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle,wasPromote,pieceCaptured,positionHash);
                    //std::cout << "after do move : " << pieceCaptured << wasCastle << wasPromote << std::endl;
                    if (verbose){
                        std::cout << "board before minimax " << std::endl ;
                        coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                        std::cin >> nothing ;
                    }


                    //sleep(2) ;
                    thisEval = minimax(r,n,b,q,k,p,R,N,B,Q,K,P,CstlL,CstlS,cstlL,cstlS,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,depthInit,depth1,depth2,alpha,beta,false,positionHash) ;


                    alpha = std::max(alpha, thisEval) ;
                    if (beta <= alpha){
                        break ;
                        std::cout << "break in game "<< std::endl ;
                    }
                    if (wantEval){
                        std::cout << position << "->" <<destination << std::endl ;
                        std::cout << thisEval << std::endl ;
                    }
                    if (verbose){
                            std::cout << "eval = " << thisEval << std::endl ;
                    }
                    if (thisEval > bestEval){
                        bestInd = 2*semIdx ;
                        bestEval = thisEval ;
                    }
                    //if (verbose){std::cin >> nothing ;}

                    enPassant = tempEnPassant ;
                    forbCstlS = tempForbCstlS ;
                    forbCstlL = tempForbCstlL ;
                    forbcstlS = tempForbcstlS ;
                    forbcstlL = tempForbcstlL ;



                    Undo_move(position,destination,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,wasCastle,wasPromote,pieceCaptured,CstlL,CstlS,cstlL,cstlS,r,n,b,q,k,p,R,N,B,Q,K,P,positionHash) ;

                    if (verbose){
                        std::cout << "undone move in game() " << std::endl;
                        coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P);
                        std::cin >> nothing ;}
                }


                /*for (auto x : ump){
                    std::cout << x.first << " " << x.second << std::endl;
                    std::cin >> nothing ;}*/

                if(wantEval){std::cin >> nothing ;}

                for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                    if (2*semIdx == bestInd) {
                        position = moves[2*semIdx] ;
                        bestMove1 = position ;
                        destination = moves[2*semIdx+1] ;
                        bestMove2 = destination ;
                        Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle,wasPromote,pieceCaptured,positionHash);
                        //isEnPassant(lastMove, enPassant, P, true) ;
                        legal = true ;
                    }
                }

            }















        } else {
            if (blackHuman){
            legal = false ;

            legPaB(moves, p, whitePieces, blackPieces, occupied, enPassant) ;
            KnightMoves(moves, n, blackPieces) ;
            sliderD(moves, b, blackPieces, occupied) ;
            sliderCD(moves, b, blackPieces, occupied) ;
            sliderHV(moves, q, blackPieces, occupied) ;
            sliderD(moves, q, blackPieces, occupied) ;
            sliderCD(moves, q, blackPieces, occupied) ;
            sliderHV(moves, r, blackPieces, occupied) ;
            KingMoves(moves, k, r, blackPieces, occupied, CstlL, CstlS, cstlL, cstlS) ;





            while (!legal){

                std::cout << "position ?" << std::endl;
                std::cin >> strPosition ;
                std::cin.ignore() ;

                position = SquareNameToNb(strPosition) ;


                std::cout << "destination ?" << std::endl;
                std::cin >> strDestination ;
                std::cin.ignore() ;

                destination = SquareNameToNb(strDestination) ;





            for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                if ((moves[2*semIdx] == position) && (moves[2*semIdx+1] == destination)) {
                    Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle, wasPromote, pieceCaptured,positionHash);
                    legal = true ;
                    //isEnPassant(lastMove, enPassant, p, false) ;
                }
            }
            if (!legal){
                    system("cls");
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    std::cout << "illegal" << std::endl;
                    if (!(moveNb%2)){std::cout << "white " ;} else {std::cout << "black " ;}std::cout << "to play" << std::endl;
            }
            }
            } else { //black not human
                legPaB(moves, p, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves(moves, n, blackPieces) ;
                sliderD(moves, b, blackPieces, occupied) ;
                sliderCD(moves, b, blackPieces, occupied) ;
                sliderHV(moves, q, blackPieces, occupied) ;
                sliderD(moves, q, blackPieces, occupied) ;
                sliderCD(moves, q, blackPieces, occupied) ;
                sliderHV(moves, r, blackPieces, occupied) ;
                KingMoves(moves, k, r, blackPieces, occupied, CstlL, CstlS, cstlL, cstlS) ;



                captInd = 0 ;
                captInd2 = 0 ;
                captInd3 = 0 ;
                captInd4 = 0 ;

                for (int semInd = 0 ; semInd < moves.size()/2 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&whitePieces){
                        temp1 = moves[2*captInd] ;
                        temp2 = moves[2*captInd+1] ;
                        moves[2*captInd] = moves[2*semInd] ;
                        moves[2*captInd+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(Q|R|N|B)){
                        temp1 = moves[2*captInd2] ;
                        temp2 = moves[2*captInd2+1] ;
                        moves[2*captInd2] = moves[2*semInd] ;
                        moves[2*captInd2+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd2 +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd2 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(Q|R)){
                        temp1 = moves[2*captInd3] ;
                        temp2 = moves[2*captInd3+1] ;
                        moves[2*captInd3] = moves[2*semInd] ;
                        moves[2*captInd3+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd3 +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd3 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(Q)){
                        temp1 = moves[2*captInd4] ;
                        temp2 = moves[2*captInd4+1] ;
                        moves[2*captInd4] = moves[2*semInd] ;
                        moves[2*captInd4+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd4 +=1 ;
                    }
                }


                bestInd = 0 ;
                thisEval = GAMEintINFINITY ;
                bestEval = GAMEintINFINITY ;


                alpha = -GAMEintINFINITY;
                beta = GAMEintINFINITY;
                ump.clear() ;
                positionHash = ZobristHash(r,n,b,q,k,p,R,N,B,Q,K,P, CstlS,CstlL,cstlS,cstlL, false) ;

                tempEnPassant = enPassant ;
                tempForbcstlS = forbcstlS ;
                tempForbcstlL = forbcstlL ;
                tempForbCstlS = forbCstlS ;
                tempForbCstlL = forbCstlL ;
                for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                    thisEval = GAMEintINFINITY ;
                    position = moves[2*semIdx] ;
                    destination = moves[2*semIdx+1] ;
                    //std::cout << position << std::endl ;
                    //std::cout << destination << std::endl ;
                    pieceCaptured = 0 ;
                    wasCastle = false ;
                    wasPromote = false ;
                    brokeCastleS = false ;
                    brokeCastleL = false ;
                    brokecastleS = false ;
                    brokecastleL = false ;


                    Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle,wasPromote,pieceCaptured,positionHash);
                    if (verbose){
                        std::cout << "board before minimax " << std::endl ;
                        coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                        std::cin >> nothing ;
                    }

                    //std::cout << pieceCaptured << wasCastle << wasPromote << std::endl;
                    //sleep(2) ;

                    thisEval = minimax(r,n,b,q,k,p,R,N,B,Q,K,P,CstlL,CstlS,cstlL,cstlS,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,depthInit,depth1,depth2,alpha,beta,true,positionHash) ;
                    beta = std::min(beta,thisEval) ;

                    if(beta <= alpha){
                        std::cout << "break in game "<< std::endl ;
                        break ;
                    }

                    //std::cout << thisEval << std::endl ;
                    if (verbose){
                            std::cout << "eval = " << thisEval << std::endl ;
                    }
                    if (thisEval < bestEval){
                        bestInd = 2*semIdx ;
                        bestEval = thisEval ;
                    }
                    if (verbose){std::cin >> nothing ;}
                    /*
                    std::cout << "about to undo " << std::endl;
                    std::cout << "board after minimax " << std::endl ;
                    std::cout << "position = " << position << std::endl ;
                    std::cout << "destination = " << destination << std::endl ;
                    std::cout << "wasCastle = " << wasCastle << std::endl ;
                    std::cout << "pieceCaptured = " << pieceCaptured << std::endl ;
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    */
                    //sleep(2);


                    enPassant = tempEnPassant ;
                    forbcstlS = tempForbcstlS ;
                    forbcstlL = tempForbcstlL ;
                    forbCstlS = tempForbCstlS ;
                    forbCstlL = tempForbCstlL ;
                    Undo_move(position,destination,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,wasCastle,wasPromote,pieceCaptured,CstlL,CstlS,cstlL,cstlS,r,n,b,q,k,p,R,N,B,Q,K,P,positionHash) ;
                    if (verbose){
                        std::cout << "undone move in game() " << std::endl;
                        coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P);
                        std::cin >> nothing ;}
                }

                //for (auto x : ump)
                //    std::cout << x.first << " " << x.second << std::endl;

                for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                    if (2*semIdx == bestInd) {
                        position = moves[2*semIdx] ;
                        bestMove1 = position ;
                        destination = moves[2*semIdx+1] ;
                        bestMove2 = destination ;
                        Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle,wasPromote,pieceCaptured,positionHash);
                        //isEnPassant(lastMove, enPassant, P, true) ;
                        legal = true ;
                    }
                }
            }
        }


        moveNb += 1 ;
    }
}

