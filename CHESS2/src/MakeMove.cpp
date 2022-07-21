#include "MakeMove.h"
#include "coutBoard.h"
#include <iostream>
#include <unistd.h>
#include <vector>

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

void Do_move(int pos, int dest, bool & CstlL, bool & CstlS, bool & cstlL, bool & cstlS,
        bool & brokeCastleS, bool & brokeCastleL, bool & brokecastleS, bool & brokecastleL,
        unsigned long long int & r,unsigned long long int & n,unsigned long long int & b,
        unsigned long long int & q,unsigned long long int & k,unsigned long long int & p,unsigned long long int & R,
        unsigned long long int & N,unsigned long long int & B,unsigned long long int & Q,unsigned long long int & K,
        unsigned long long int & P,unsigned long long int & enPassant, unsigned long long int & forbCstlS,
        unsigned long long int & forbCstlL, unsigned long long int & forbcstlS, unsigned long long int & forbcstlL,
        bool & wasCastle, bool & wasPromote, int & pieceCaptured, unsigned long long int & positionHash){

    //piece captured : aucune - rnbqkpRNBQKP
    //int : 0 - 1-2-3-4-5-6-7-8-9-10-11-12

    enPassant = 0 ;
    forbCstlS = 0 ;
    forbCstlL = 0 ;
    forbcstlS = 0 ;
    forbcstlL = 0 ;

    unsigned long long int const cSHORTHASH = 1401845436929994442 ;
    unsigned long long int const cLONGHASH = 673442472024400627 ;
    unsigned long long int const CSHORTHASH = 1401845436929994442 ;
    unsigned long long int const CLONGHASH = 1401845436929994442 ;

    positionHash^= 891517893554500602 ; //maximizingPlayer

    std::string nothing ;


    unsigned long long int posInt (1) ;
    unsigned long long int destInt (1) ;

    posInt <<= pos ;
    destInt <<= dest ;

    //enlever la pièce sur capture

    if (r>>dest&1){
        r -= destInt ;
        positionHash ^= rZobTable[dest/8][dest%8] ;
        pieceCaptured = 1 ;

    } else {

    if (n>>dest&1){
        n -= destInt ;
        positionHash ^= nZobTable[dest/8][dest%8] ;
        pieceCaptured = 2 ;

    } else {

    if (b>>dest&1){
        b -= destInt ;
        positionHash ^= bZobTable[dest/8][dest%8] ;
        pieceCaptured = 3 ;

    } else {

    if (q>>dest&1){
        q -= destInt ;
        positionHash ^= qZobTable[dest/8][dest%8] ;
        pieceCaptured = 4 ;

    } else {

    if (k>>dest&1){
        k -= destInt ;
        positionHash ^= kZobTable[dest/8][dest%8] ;
        pieceCaptured = 5 ;

    } else {

    if (p>>dest&1){
        p -= destInt ;
        positionHash ^= pZobTable[dest/8][dest%8] ;
        pieceCaptured = 6 ;

    } else {

    if (R>>dest&1){
        R -= destInt ;
        positionHash ^= RZobTable[dest/8][dest%8] ;
        pieceCaptured = 7 ;

    } else {

    if (N>>dest&1){
        N -= destInt ;
        positionHash ^= NZobTable[dest/8][dest%8] ;
        pieceCaptured = 8 ;

    } else {

    if (B>>dest&1){
        B -= destInt ;
        positionHash ^= BZobTable[dest/8][dest%8] ;
        pieceCaptured = 9 ;

    } else {

    if (Q>>dest&1){
        Q -= destInt ;
        positionHash ^= QZobTable[dest/8][dest%8] ;
        pieceCaptured = 10 ;

    } else {

    if (K>>dest&1){
        K -= destInt ;
        positionHash ^= KZobTable[dest/8][dest%8] ;
        pieceCaptured = 11 ;

    } else {

    if (P>>dest&1){
        P -= destInt ;
        positionHash ^= PZobTable[dest/8][dest%8] ;
        pieceCaptured = 12 ;
    }

    else { //en passant  //si il y avait personne la ou tu as atterit (mais que tu fait une diag avec le pion)
        if (( dest == pos + 7 ) && (P>>pos&1)){
            destInt = 1 ;
            destInt <<= pos-1 ;
            p -= destInt ;
            positionHash ^= pZobTable[(pos-1)/8][(pos-1)%8] ;
            destInt = 1 ;
            destInt <<= dest ;
        } else {

        if (( dest == pos + 9 ) && (P>>pos&1)){
            destInt = 1 ;
            destInt <<= pos+1 ;
            p -= destInt ;
            positionHash ^= pZobTable[(pos+1)/8][(pos+1)%8] ;
            destInt = 1 ;
            destInt <<= dest ;
        } else {

        if (( dest == pos - 7 ) && (p>>pos&1)){
            destInt = 1 ;
            destInt <<= pos+1 ;
            P -= destInt ;
            positionHash ^= pZobTable[(pos+1)/8][(pos+1)%8] ;
            destInt = 1 ;
            destInt <<= dest ;
        } else {

        if (( dest == pos - 9 ) && (p>>pos&1)){
            destInt = 1 ;
            destInt <<= pos-1 ;
            positionHash ^= pZobTable[(pos-1)/8][(pos-1)%8] ;
            P -= destInt ;
            destInt = 1 ;
            destInt <<= dest ;
        }}}}
    }

    }}}}}}}}}}}

    //promotion
    if ((pos/8 == 6)&&(P>>pos&1)){
        wasPromote = true ;
        P -= posInt ;
        positionHash ^= PZobTable[pos/8][pos%8] ;
        Q += destInt ;
        positionHash ^= QZobTable[dest/8][dest%8] ;
    } else {

    if ((pos/8 == 1)&&(p>>pos&1)){
        wasPromote = true ;
        p -= posInt ;
        positionHash ^= pZobTable[pos/8][pos%8] ;
        q += destInt ;
        positionHash ^= qZobTable[dest/8][dest%8] ;
    } else {


    //castle
    if ((pos==3)&&(dest==1)&&(K>>pos&1)&&(R&1)&&CstlS){ //white short

        wasCastle = true ;
        forbCstlS = 12 ;
        K = K - posInt + destInt ;
        positionHash ^= KZobTable[pos/8][pos%8] ;
        positionHash ^= KZobTable[dest/8][dest%8] ;
        posInt = 1 ;
        destInt = 1 ;
        posInt <<= 0 ;
        destInt <<= 2 ;


        R = R - posInt + destInt ;
        positionHash ^= RZobTable[0/8][0%8] ;
        positionHash ^= RZobTable[2/8][2%8] ;




        //CstlS = false ;

    } else {

    if ((pos==3)&&(dest==5)&&(K>>pos&1)&&(R>>7&1)&&CstlL){ //white long
        wasCastle = true ;
        forbCstlL = 24 ;
        K = K - posInt + destInt ;
        positionHash ^= KZobTable[pos/8][pos%8] ;
        positionHash ^= KZobTable[dest/8][dest%8] ;
        posInt = 1 ;
        destInt = 1 ;
        posInt <<= 7 ;
        destInt <<= 4 ;
        R = R - posInt + destInt ;
        positionHash ^= RZobTable[7/8][7%8] ;
        positionHash ^= RZobTable[4/8][4%8] ;



        //CstlL = false ;

    } else {

    if ((pos==59)&&(dest==57)&&(k>>pos&1)&&(r>>56&1)&&cstlS){ //black short
        wasCastle = true ;
        forbcstlS = 864691128455135232 ;
        k = k - posInt + destInt ;
        positionHash ^= kZobTable[pos/8][pos%8] ;
        positionHash ^= kZobTable[dest/8][dest%8] ;
        posInt = 1 ;
        destInt = 1 ;
        posInt <<= 56 ;
        destInt <<= 58 ;
        r = r - posInt + destInt ;
        positionHash ^= rZobTable[56/8][56%8] ;
        positionHash ^= rZobTable[58/8][58%8] ;




        //cstlS = false ;

    } else {

    if ((pos==59)&&(dest==61)&&(k>>pos&1)&&(r>>63&1)&&cstlL){ //black long
        wasCastle = true ;
        forbcstlL = 1729382256910270464 ;
        k = k - posInt + destInt ;
        positionHash ^= kZobTable[pos/8][pos%8] ;
        positionHash ^= kZobTable[dest/8][dest%8] ;
        posInt = 1 ;
        destInt = 1 ;
        posInt <<= 63 ;
        destInt <<= 60 ;
        r = r - posInt + destInt ;
        positionHash ^= rZobTable[60/8][60%8] ;
        positionHash ^= rZobTable[63/8][63%8] ;



        //cstlL = false ;

    } else {




    if (r>>pos&1){
        if(pos == 56){
            brokecastleS = cstlS ;
            if(brokecastleS){positionHash ^= 1401845436929994442 ;}
            cstlS = false ;
        }
        if(pos == 63){
            brokecastleL = cstlL ;
            if(brokecastleL){positionHash ^= 673442472024400627 ;}
            cstlL = false ;
        }
        r -= posInt ;
        r += destInt ;
        positionHash ^= rZobTable[pos/8][pos%8] ;
        positionHash ^= rZobTable[dest/8][dest%8] ;

    } else {

    if (n>>pos&1){
        n -= posInt ;
        n += destInt ;
        positionHash ^= nZobTable[pos/8][pos%8] ;
        positionHash ^= nZobTable[dest/8][dest%8] ;

    } else {

    if (b>>pos&1){
        b -= posInt ;
        b += destInt ;
        positionHash ^= bZobTable[pos/8][pos%8] ;
        positionHash ^= bZobTable[dest/8][dest%8] ;

    } else {

    if (q>>pos&1){
        q -= posInt ;
        q += destInt ;
        positionHash ^= qZobTable[pos/8][pos%8] ;
        positionHash ^= qZobTable[dest/8][dest%8] ;

    } else {



    if (k>>pos&1){

        k -= posInt ;
        k += destInt ;
        positionHash ^= kZobTable[pos/8][pos%8] ;
        positionHash ^= kZobTable[dest/8][dest%8] ;

        brokecastleL = cstlL ;
        if(brokecastleL){positionHash ^= 673442472024400627 ;}
        brokecastleS = cstlS ;
        if(brokecastleS){positionHash ^= 1401845436929994442 ;}

        cstlL = false ;
        cstlS = false ;

    } else {

    if (p>>pos&1){
        p -= posInt ;
        p += destInt ;
        positionHash ^= pZobTable[pos/8][pos%8] ;
        positionHash ^= pZobTable[dest/8][dest%8] ;

        if (dest == pos-16){
            enPassant = 1 ;
            enPassant <<=(pos-8) ;

        }

    } else {

    if (R>>pos&1){
        R -= posInt ;
        R += destInt ;
        positionHash ^= RZobTable[pos/8][pos%8] ;
        positionHash ^= RZobTable[dest/8][dest%8] ;

        if(pos == 0){
            brokeCastleS = CstlS ;
            if (brokeCastleS){
                positionHash ^= 1615461785985833611 ;
            }
            CstlS = false ;
        }
        if(pos == 7){
            brokeCastleL = CstlL ;
            if (brokeCastleL){
                positionHash ^= 803003761016756798 ;
            }
            CstlL = false ;
        }

    } else {

    if (N>>pos&1){
        N -= posInt ;
        N += destInt ;
        positionHash ^= NZobTable[pos/8][pos%8] ;
        positionHash ^= NZobTable[dest/8][dest%8] ;

    } else {

    if (B>>pos&1){
        B -= posInt ;
        B += destInt ;
        positionHash ^= BZobTable[pos/8][pos%8] ;
        positionHash ^= BZobTable[dest/8][dest%8] ;

    } else {

    if (Q>>pos&1){
        Q -= posInt ;
        Q += destInt ;
        positionHash ^= QZobTable[pos/8][pos%8] ;
        positionHash ^= QZobTable[dest/8][dest%8] ;

    } else {

    if (K>>pos&1){
        K -= posInt ;
        K += destInt ;
        positionHash ^= KZobTable[pos/8][pos%8] ;
        positionHash ^= KZobTable[dest/8][dest%8] ;

        brokeCastleL = CstlL ;
        brokeCastleS = CstlS ;
        if (brokeCastleL){
            positionHash ^= 803003761016756798 ;
        }
        if (brokeCastleS){
            positionHash ^= 1615461785985833611 ;
        }

        /*if (brokeCastleL || brokeCastleS){
            std::cout << "castle broken" << std::endl ;
        }*/


        CstlL = false ;
        CstlS = false ;

    } else {

    if (P>>pos&1){
        P -= posInt ;
        P += destInt ;
        positionHash ^= PZobTable[pos/8][pos%8] ;
        positionHash ^= PZobTable[dest/8][dest%8] ;

        if (dest == pos+16){
            enPassant = 1 ;
            enPassant <<=(pos+8) ;
        }
    }

    }}}}}}}}}}}}}}}}}
}

void Undo_move(int wasPos, int wasDest, bool brokeCastleS, bool brokeCastleL, bool brokecastleS, bool brokecastleL,
        bool wasCastle, bool wasPromote, int pieceCaptured,
        bool & CstlL, bool & CstlS, bool & cstlL, bool & cstlS,
        unsigned long long int & r,unsigned long long int & n,unsigned long long int & b,
        unsigned long long int & q,unsigned long long int & k,unsigned long long int & p,
        unsigned long long int & R,unsigned long long int & N,unsigned long long int & B,
        unsigned long long int & Q,unsigned long long int & K,unsigned long long int & P,
        unsigned long long int & positionHash){

    positionHash^= 891517893554500602 ; //maximizingPlayer
    //std::string nothing ;

    //std::cout << "in undo move" << std::endl ;
    //std::cin >> nothing ;

    //std::cout << "entering undo move with pieceCaptured = " << pieceCaptured << std::endl ;

    //std::cout << "wasDest = " << wasDest << std::endl;
    //std::cout << "wasPos = " << wasPos << std::endl;

    //piece captured : aucune - rnbqkpRNBQKP
    //int : 0 - 1-2-3-4-5-6-7-8-9-10-11-12

    if (brokeCastleL){
        positionHash ^= 803003761016756798 ;

        CstlL = true ;
        //std::cout << "CL" << std::endl ;

    }

    if (brokecastleL){
        cstlL = true ;
        positionHash ^= 673442472024400627 ;

        //std::cout << "cL" << std::endl ;


    }

    if (brokeCastleS){
        positionHash ^= 1615461785985833611 ;

        CstlS = true ;
        //std::cout << "CS" << std::endl ;

    }

    if (brokecastleS){
        cstlS = true ;
        positionHash ^= 1401845436929994442 ;
        //std::cout << "cS" << std::endl ;

    }

    unsigned long long int wasDestInt (1) ;
    unsigned long long int wasPosInt (1) ;
    unsigned long long int temPassant (1) ;


    if (wasPromote){

        //std::cout << "in promote, " << std::endl ;
        //std::cin >> nothing ;

        wasDestInt = wasDestInt <<= wasDest ;
        wasPosInt = wasPosInt <<= wasPos ;

        if (wasDest/8 == 7){
            Q -= wasDestInt ;
            P += wasPosInt ;
            positionHash ^= QZobTable[wasDest/8][wasDest%8] ;
            positionHash ^= PZobTable[wasPos/8][wasPos%8] ;
        } else {

        if (wasDest/8 == 0){
            q -= wasDestInt ;
            p += wasPosInt ;
            positionHash ^= qZobTable[wasDest/8][wasDest%8] ;
            positionHash ^= pZobTable[wasPos/8][wasPos%8] ;
        }}

    } else {

    if (wasCastle){

        if (wasDest == 1){

            wasDestInt <<= 1;
            wasPosInt <<= 3;



            K = K - wasDestInt + wasPosInt ;
            positionHash ^= KZobTable[wasPos/8][wasPos%8] ;
            positionHash ^= KZobTable[wasDest/8][wasDest%8] ;

            wasDestInt = 1 ;
            wasPosInt = 1 ;

            wasDestInt <<= 2;
            //wasPosInt <<= 0;



            R = R - wasDestInt + wasPosInt ;
            positionHash ^= RZobTable[0/8][0%8] ;
            positionHash ^= RZobTable[2/8][2%8] ;


        } else {
        if (wasDest == 5){

            wasDestInt <<= 5;
            wasPosInt <<= 3;

            K = K - wasDestInt + wasPosInt ;
            positionHash ^= KZobTable[wasPos/8][wasPos%8] ;
            positionHash ^= KZobTable[wasDest/8][wasDest%8] ;

            wasDestInt = 1 ;
            wasPosInt = 1 ;

            wasDestInt <<= 4;
            wasPosInt <<= 7;

            R = R - wasDestInt + wasPosInt ;
            positionHash ^= RZobTable[7/8][7%8] ;
            positionHash ^= RZobTable[4/8][4%8] ;

        } else {

        if (wasDest == 57){

            wasDestInt <<= 57;
            wasPosInt <<= 59;

            k = k - wasDestInt + wasPosInt ;
            positionHash ^= kZobTable[wasPos/8][wasPos%8] ;
            positionHash ^= kZobTable[wasDest/8][wasDest%8] ;


            wasDestInt = 1 ;
            wasPosInt = 1 ;

            wasDestInt <<= 58;
            wasPosInt <<= 56;

            r = r - wasDestInt + wasPosInt ;
            positionHash ^= rZobTable[56/8][56%8] ;
            positionHash ^= rZobTable[58/8][58%8] ;

        } else {
        if (wasDest == 61){

            wasDestInt <<= 61;
            wasPosInt <<= 59;

            k = k - wasDestInt + wasPosInt ;
            positionHash ^= kZobTable[wasPos/8][wasPos%8] ;
            positionHash ^= kZobTable[wasDest/8][wasDest%8] ;

            wasDestInt = 1 ;
            wasPosInt = 1 ;

            wasDestInt <<= 60;
            wasPosInt <<= 63;

            r = r - wasDestInt + wasPosInt ;
            positionHash ^= rZobTable[63/8][63%8] ;
            positionHash ^= rZobTable[60/8][60%8] ;


        }}}}}

        else {


    wasDestInt = wasDestInt <<= wasDest ;
    wasPosInt = wasPosInt <<= wasPos ;

    //std::cout << "destint = " << std::endl ;
    //coutBitSet(wasDestInt) ;

    //std::cout << "posint = " << std::endl ;
    //coutBitSet(wasPosInt) ;



    /*std::cout << "wasDestInt = " << std::endl;
    coutBitSet(wasDestInt) ;
    std::cout << "wasPosInt = " << std::endl;
    coutBitSet(wasPosInt) ;*/

    if (r>>wasDest&1){
        r = r - wasDestInt + wasPosInt ;
        positionHash ^= rZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= rZobTable[wasDest/8][wasDest%8] ;
    } else {

    if (n>>wasDest&1){
        n = n - wasDestInt + wasPosInt ;
        positionHash ^= nZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= nZobTable[wasDest/8][wasDest%8] ;
    } else {

    if (b>>wasDest&1){
        b = b - wasDestInt + wasPosInt ;
        positionHash ^= bZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= bZobTable[wasDest/8][wasDest%8] ;
    } else {

    if (q>>wasDest&1){
        q = q - wasDestInt + wasPosInt ;
        positionHash ^= qZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= qZobTable[wasDest/8][wasDest%8] ;
    } else {

    if (k>>wasDest&1){
        k = k - wasDestInt + wasPosInt ;
        positionHash ^= kZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= kZobTable[wasDest/8][wasDest%8] ;
    } else {

    if (p>>wasDest&1){
        if ((wasDest == wasPos-7) && (pieceCaptured == 0)){ // enPassant
            temPassant <<= (wasPos+1) ;
            P+=temPassant ;
            positionHash ^= PZobTable[(wasPos+1)/8][(wasPos+1)%8] ;

        }
        if ((wasDest == wasPos-9) && (pieceCaptured == 0)){ // enPassant
            temPassant <<= (wasPos-1) ;
            P+=temPassant ;
            positionHash ^= PZobTable[(wasPos-1)/8][(wasPos-1)%8] ;
        }

        p = p - wasDestInt + wasPosInt ;
        positionHash ^= pZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= pZobTable[wasDest/8][wasDest%8] ;
    } else {

    if (R>>wasDest&1){
        R = R - wasDestInt + wasPosInt ;
        positionHash ^= RZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= RZobTable[wasDest/8][wasDest%8] ;
    } else {

    if (N>>wasDest&1){
        N = N - wasDestInt + wasPosInt ;
        positionHash ^= NZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= NZobTable[wasDest/8][wasDest%8] ;
    } else {

    if (B>>wasDest&1){
        B = B - wasDestInt + wasPosInt ;
        positionHash ^= BZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= BZobTable[wasDest/8][wasDest%8] ;
    } else {

    if (Q>>wasDest&1){
        //std::cout << "queen in dest " << std::endl ;
        //std::cin >> nothing ;
        Q = Q - wasDestInt + wasPosInt ;
        positionHash ^= QZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= QZobTable[wasDest/8][wasDest%8] ;
    } else {

    if (K>>wasDest&1){
        K = K - wasDestInt + wasPosInt ;
        positionHash ^= KZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= KZobTable[wasDest/8][wasDest%8] ;
    } else {

    if (P>>wasDest&1){
        if ((wasDest == wasPos+7) && (pieceCaptured == 0)){ // enPassant
            temPassant <<= (wasPos-1) ;
            p+=temPassant ;
            positionHash ^= pZobTable[(wasPos-1)/8][(wasPos-1)%8] ;
        }
        if ((wasDest == wasPos+9) && (pieceCaptured == 0)){ // enPassant
            temPassant <<= (wasPos+1) ;
            p+=temPassant ;
            positionHash ^= pZobTable[(wasPos+1)/8][(wasPos+1)%8] ;
        }
        P = P - wasDestInt + wasPosInt ;
        positionHash ^= PZobTable[wasPos/8][wasPos%8] ;
        positionHash ^= PZobTable[wasDest/8][wasDest%8] ;
    }


    }}}}}}}}}}}}}

    if (pieceCaptured != 0){
        //std::cout << "In Undo_move, pieceCaptured = " << pieceCaptured << std::endl ;
        switch(pieceCaptured){
            case 1 :
                r += wasDestInt ;
                positionHash ^= rZobTable[wasDest/8][wasDest%8] ;
                break ;
            case 2 :
                n += wasDestInt ;
                positionHash ^= nZobTable[wasDest/8][wasDest%8] ;
                break ;
            case 3 :
                b += wasDestInt ;
                positionHash ^= bZobTable[wasDest/8][wasDest%8] ;
                break ;
            case 4 :
                q += wasDestInt ;
                positionHash ^= qZobTable[wasDest/8][wasDest%8] ;
                break ;
            case 5 :
                k += wasDestInt ;
                positionHash ^= kZobTable[wasDest/8][wasDest%8] ;
                break ;
            case 6 :
                p += wasDestInt ;
                positionHash ^= pZobTable[wasDest/8][wasDest%8] ;
                break ;
            case 7 :
                R += wasDestInt ;
                positionHash ^= RZobTable[wasDest/8][wasDest%8] ;
                break ;
            case 8 :
                N += wasDestInt ;
                positionHash ^= NZobTable[wasDest/8][wasDest%8] ;
                break ;
            case 9 :
                B += wasDestInt ;
                positionHash ^= BZobTable[wasDest/8][wasDest%8] ;
                break ;
            case 10 :
                Q += wasDestInt ;
                positionHash ^= QZobTable[wasDest/8][wasDest%8] ;
                break ;
            case 11 :
                K += wasDestInt ;
                positionHash ^= KZobTable[wasDest/8][wasDest%8] ;
                break ;
            case 12 :
                P += wasDestInt ;
                positionHash ^= PZobTable[wasDest/8][wasDest%8] ;
                break ;
        }
    }
}
