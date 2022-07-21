#include "ChoseMove.h"
#include "Eval.h"
#include "MakeMove.h"
#include "LegalMoves.h"
//#include "Constants.h"
#include "coutBoard.h"
#include "BitwiseFunction.h"
#include "initBoard.h"

#include <unistd.h>
#include <limits>
#include <iostream>
#include <vector>
#include <unordered_map>

int intINFINITY = std::numeric_limits<int>::max() ;


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


int minimax(unsigned long long int & r,unsigned long long int & n,unsigned long long int & b,
        unsigned long long int & q,unsigned long long int & k,unsigned long long int & p,
        unsigned long long int & R,unsigned long long int & N,unsigned long long int & B,
        unsigned long long int & Q,unsigned long long int & K,unsigned long long int & P,
        bool & CstlL, bool & CstlS , bool & cstlL , bool & cstlS, unsigned long long int & enPassant,
        unsigned long long int & forbCstlS, unsigned long long int & forbCstlL,
        unsigned long long int & forbcstlS, unsigned long long int & forbcstlL,
        int depthInit, int depth, int veryMaxDepth, int alpha, int beta, bool maximizingPlayer,
        unsigned long long int & positionHash)



{

        it = ump.begin() ;
        it = ump.find(positionHash);

        std::string nothing ;
        unsigned long long int tempEnPassant;
        unsigned long long int tempForbCstlS;
        unsigned long long int tempForbCstlL;
        unsigned long long int tempForbcstlS;
        unsigned long long int tempForbcstlL;

        bool evaluated (false);
        bool found (false);


        //unsigned long long int zobKey ;




        bool brokeCastleL = false ;
        bool brokeCastleS = false ;
        bool brokecastleL = false ;
        bool brokecastleS = false ;


        bool verbose = false ;
        /*unsigned long long int r2,n2,b2,q2,k2,p2,R2,N2,B2,Q2,K2,P2;
        std::string fen = "r1b1kb1r/ppp2ppp/2p2n2/4q3/4P3/2N5/PPPP1PPP/R1BQK2R" ;
        initFromFEN(fen,r2,n2,b2,q2,k2,p2,R2,N2,B2,Q2,K2,P2) ;
        if((r2==r)&&(n2==n)&&(b2==b)&&(q2==q)&&(k2==k)&&(p2==p)&&(R2==R)&&(N2==N)&&(B2==B)&&(Q2==Q)&&(K2==K)&&(P2==P)){
            verbose = true ;
        }*/

        //std::cout << "in minimax " << std::endl ;
        //std::cout << "maximizingPlayer = " << maximizingPlayer << std::endl ;
        //std::cin >> nothing ;
        unsigned long long int whitePieces = R | N | B | Q | K | P ;
        unsigned long long int blackPieces = r | n | b | q | k | p ;
        unsigned long long int occupied = whitePieces | blackPieces ;

        int pieceCaptured  ;
        bool wasCastle  ;
        bool wasPromote  ;

        int position ;
        int destination ;


        int maxEval (0) ;
        int minEval (0) ;
        int eval (0) ;

        bool depthIncreased ;

        //move ordering
        int captInd ;
        int captInd2 ;
        int captInd3 ;
        int captInd4 ;
        int captInd5 ;
        int dest = 0 ;
        unsigned long long int destInt  = 1;
        int temp1 = 0;
        int temp2 = 0;


        if ( ( depth == 0 ) || ( veryMaxDepth == 0 ) ){

            it = ump.begin() ;
            it = ump.find(positionHash); //Finding an element

            if(it != ump.end()){
                //std::cout<<"*";
                if(verbose){std::cout<<"found and evaluated";}

                if(verbose){std::cout<<it->second.first;}
                return it->second.first ;
            }

            else{
                eval = EvalFunction(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                ump.insert({positionHash,{eval,veryMaxDepth}});
                if(verbose){std::cout<<eval;}
                return eval ;
            }



        }


        if (k==0){
            eval = 10000 + depth ;
            ump.insert({positionHash,{eval,veryMaxDepth}});
            return eval ;
        }
        if (K==0){
            eval = -10000 - depth ;
            ump.insert({positionHash,{eval,veryMaxDepth}});
            return eval ;
        }


        std::vector<int> moves ;
        //std::vector<int> moves2 ;


        if (maximizingPlayer){
            //std::cout << "in minimax with maximizing player = false" << std::endl ;
            //std::cin >> nothing ;

            /* compute legal moves */
            if(depthInit <= 0){
                legPaW2(moves, P, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves2(moves, N, occupied, whitePieces) ;
                sliderD2(moves, B, whitePieces, occupied) ;
                sliderCD2(moves, B, whitePieces, occupied) ;
                sliderHV2(moves, Q, whitePieces, occupied) ;
                sliderD2(moves, Q, whitePieces, occupied) ;
                sliderCD2(moves, Q, whitePieces, occupied) ;
                sliderHV2(moves, R, whitePieces, occupied) ;
                KingMoves2(moves, K, R, whitePieces, occupied, CstlL, CstlS, cstlL, cstlS) ;
            } else {
                legPaW(moves, P, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves(moves, N, whitePieces) ;
                sliderD(moves, B, whitePieces, occupied) ;
                sliderCD(moves, B, whitePieces, occupied) ;
                sliderHV(moves, Q, whitePieces, occupied) ;
                sliderD(moves, Q, whitePieces, occupied) ;
                sliderCD(moves, Q, whitePieces, occupied) ;
                sliderHV(moves, R, whitePieces, occupied) ;
                KingMoves(moves, K, R, whitePieces, occupied, CstlL, CstlS, cstlL, cstlS) ;
            }

            /*______________________*/


            captInd = 0 ;
            captInd2 = 0 ;
            captInd3 = 0 ;
            captInd4 = 0 ;
            captInd5 = 0 ;
            for (int semInd = 0 ; semInd < moves.size()/2 ; semInd ++){
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
                    if (destInt&(k|q|r|n|b)){
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
                    if (destInt&(k|q|r)){
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
                    if (destInt&(k|q)){
                        temp1 = moves[2*captInd4] ;
                        temp2 = moves[2*captInd4+1] ;
                        moves[2*captInd4] = moves[2*semInd] ;
                        moves[2*captInd4+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd4 +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd4 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(k)){
                        temp1 = moves[2*captInd5] ;
                        temp2 = moves[2*captInd5+1] ;
                        moves[2*captInd5] = moves[2*semInd] ;
                        moves[2*captInd5+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd5 +=1 ;
                    }
                }



            maxEval = - intINFINITY ;
            tempEnPassant = enPassant ;
            tempForbCstlS = forbCstlS ;
            tempForbCstlL = forbCstlL ;
            tempForbcstlS = forbcstlS ;
            tempForbcstlL = forbcstlL ;
            for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                pieceCaptured = 0 ;
                wasCastle = false ;
                wasPromote = false ;
                depthIncreased = false ;
                brokeCastleL = false ;
                brokeCastleS = false ;
                brokecastleL = false ;
                brokecastleS = false ;

                position = moves[2*semIdx] ;
                destination = moves[2*semIdx+1] ;



                Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle, wasPromote, pieceCaptured,positionHash) ;
                if(verbose){std::cout << "do move in minimax() " << std::endl;
                coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P);
                //std::cin >> nothing ;
                }

                /*it = ump.begin() ;
                it = ump.find(positionHash); //Finding an element

                if(it != ump.end()){
                    found = true ;
                    //std::cout<<"*";
                    if(it->second.second >= veryMaxDepth){ // si il me reste plus de profondeur que vous, je vous fait pas confiance
                        if (verbose){std::cout<<"found and evaluated";}
                        evaluated = true ;
                        eval = it->second.first ;
                    }

                }*/


                if (/*(!evaluated)&&*/(depth == 1) && (pieceCaptured != 0)){
                    depth += 1 ;
                    depthIncreased = true ;
                }


                if (/*(!evaluated)&&*/((R|N|B|Q|K|P)&(tempForbcstlS|tempForbcstlL))){
                    eval = 10000 ;
                    evaluated = true ;
                }
                if (!evaluated){
                eval = minimax(r,n,b,q,k,p,R,N,B,Q,K,P,CstlL,CstlS,cstlL,cstlS,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,depthInit-1,depth-1,veryMaxDepth-1,alpha,beta,false,positionHash) ;
                /*if (!found){ump.insert({positionHash,{eval,veryMaxDepth}});}
                else {ump[positionHash] = {eval,veryMaxDepth} ;}*/
                }


                /*if (verbose && (eval > maxEval)){
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    std::cout << "eval = " << eval << std::endl ;
                    std::cout << "pieceCaptured = " << pieceCaptured << std::endl ;
                    std::cin >> nothing ;}*/

                if (depthIncreased){
                    depth -= 1 ;
                }


                enPassant = tempEnPassant ;
                forbCstlS = tempForbCstlS ;
                forbCstlL = tempForbCstlL ;
                forbcstlS = tempForbcstlS ;
                forbcstlL = tempForbcstlL ;


                Undo_move(position,destination,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,wasCastle, wasPromote,pieceCaptured,CstlL,CstlS,cstlL,cstlS,r,n,b,q,k,p,R,N,B,Q,K,P,positionHash) ;
                if (verbose){
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    std::cout << "undone move in minimax" << std::endl ;
                    //std::cin >> nothing ;
                    }

                maxEval = std::max(maxEval,eval) ;
                alpha = std::max(alpha, eval) ;
                if (beta <= alpha) {
                    /*if (verbose){
                    std::cout << "Beta <= alpha : break" << std::endl ;
                    std::cin >> nothing ;
                    }*/

                    break ;
                }
            }
            return maxEval ;

            }







        else {
            //std::cout << "in minimax with maximizing player = false" << std::endl ;
            //std::cin >> nothing ;

            /* compute legal moves */
            if (depthInit <=0){
                legPaB2(moves, p, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves2(moves, n, occupied, blackPieces) ;
                sliderD2(moves, b, blackPieces, occupied) ;
                sliderCD2(moves, b, blackPieces, occupied) ;
                sliderHV2(moves, q, blackPieces, occupied) ;
                sliderD2(moves, q, blackPieces, occupied) ;
                sliderCD2(moves, q, blackPieces, occupied) ;
                sliderHV2(moves, r, blackPieces, occupied) ;
                KingMoves2(moves, k, r,  blackPieces, occupied, CstlL, CstlS, cstlL, cstlS) ;
            }
            else {
                legPaB(moves, p, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves(moves, n, blackPieces) ;
                sliderD(moves, b, blackPieces, occupied) ;
                sliderCD(moves, b, blackPieces, occupied) ;
                sliderHV(moves, q, blackPieces, occupied) ;
                sliderD(moves, q, blackPieces, occupied) ;
                sliderCD(moves, q, blackPieces, occupied) ;
                sliderHV(moves, r, blackPieces, occupied) ;
                KingMoves(moves, k, r,  blackPieces, occupied, CstlL, CstlS, cstlL, cstlS) ;
            }



            /*______________________*/


            captInd = 0 ;
            captInd2 = 0 ;
            captInd3 = 0 ;
            captInd4 = 0 ;
            captInd5 = 0 ;
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
                    if (destInt&(K|Q|R|N|B)){
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
                    if (destInt&(K|Q|R)){
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
                    if (destInt&(K|Q)){
                        temp1 = moves[2*captInd4] ;
                        temp2 = moves[2*captInd4+1] ;
                        moves[2*captInd4] = moves[2*semInd] ;
                        moves[2*captInd4+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd4 +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd4 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(K)){
                        temp1 = moves[2*captInd5] ;
                        temp2 = moves[2*captInd5+1] ;
                        moves[2*captInd5] = moves[2*semInd] ;
                        moves[2*captInd5+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd5 +=1 ;
                    }
                }




            minEval = intINFINITY ;
            tempEnPassant = enPassant ;
            tempForbcstlS = forbcstlS ;
            tempForbcstlL = forbcstlL ;
            tempForbCstlS = forbCstlS ;
            tempForbCstlL = forbCstlL ;
            for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                pieceCaptured = 0 ;
                wasCastle = false ;
                wasPromote = false ;
                depthIncreased = false ;
                brokeCastleL = false ;
                brokeCastleS = false ;
                brokecastleL = false ;
                brokecastleS = false ;

                position = moves[2*semIdx] ;
                destination = moves[2*semIdx+1] ;



                Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle, wasPromote,pieceCaptured,positionHash) ;
                if (verbose){
                    std::cout << "done move" << std::endl ;
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    //std::cin >> nothing ;
                    }

                //std::cout << "key is " << zobKey << std::endl ;
                //std::cin >> nothing ;

                /*if(it != ump.end()){
                    found = true ;
                    //std::cout<<"*";
                    if(it->second.second >= veryMaxDepth){// si il me reste plus de profondeur que vous, je vous fait pas confiance
                        if(verbose){std::cout<<"found and evaluated";}
                        evaluated = true ;
                        eval = it->second.first ;
                    }

                }*/



                if (/*(!evaluated)&&*/(depth == 1) && (pieceCaptured != 0)){
                    depth += 1 ;
                    depthIncreased = true ;
                }

                if (/*(!evaluated)&&*/((r|n|b|q|k|p)&(tempForbCstlS|tempForbCstlL))){
                    eval = -10000 ;
                    evaluated = true ;

                }
                if (!evaluated){
                eval = minimax(r,n,b,q,k,p,R,N,B,Q,K,P,CstlL,CstlS,cstlL,cstlS,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,depthInit-1,depth-1,veryMaxDepth-1,alpha,beta,true,positionHash) ;
                /*if (!found){ump.insert({positionHash,{eval,veryMaxDepth}});}
                else {ump[positionHash] = {eval,veryMaxDepth} ;}*/
                }


                /*if (verbose && (eval < minEval)){
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    std::cout << "eval = " << eval << std::endl ;
                    std::cout << "pieceCaptured = " << pieceCaptured << std::endl ;
                    std::cin >> nothing ;}*/
                if (depthIncreased){
                    depth -= 1 ;
                }

                enPassant = tempEnPassant ;
                forbcstlS = tempForbcstlS ;
                forbcstlL = tempForbcstlL ;
                forbCstlS = tempForbCstlS ;
                forbCstlL = tempForbCstlL ;
                Undo_move(position,destination,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,wasCastle, wasPromote,pieceCaptured,CstlL,CstlS,cstlL,cstlS,r,n,b,q,k,p,R,N,B,Q,K,P,positionHash) ;
                if (verbose){
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    std::cout << "undone move in minimax" << std::endl ;
                    //std::cin >> nothing ;
                    }

                minEval =  std::min(minEval,eval) ;
                beta = std::min(beta,eval) ;
                if ( beta <= alpha ){
                    /*if (verbose){
                    std::cout << "Beta <= alpha : break" << std::endl ;
                    std::cin >> nothing ;
                    }*/
                    break ;
                }
            }
            return minEval ;
   }
}


