#include "LegalMoves.h"
#include "coutBoard.h"
#include "BitwiseFunction.h"
//#include "Constants.h"

#include <vector>
#include <bitset>
#include <string>
#include <iostream>
#include <unistd.h>

std::bitset<64> const bitsetFILEA("1000000010000000100000001000000010000000100000001000000010000000") ;
unsigned long long int const FILEA = bitsetFILEA.to_ullong() ;

std::bitset<64> const bitsetFILEB("0100000001000000010000000100000001000000010000000100000001000000") ;
unsigned long long int const FILEB = bitsetFILEB.to_ullong() ;

std::bitset<64> const bitsetFILEC("0010000000100000001000000010000000100000001000000010000000100000") ;
unsigned long long int const FILEC = bitsetFILEC.to_ullong() ;

std::bitset<64> const bitsetFILED("0001000000010000000100000001000000010000000100000001000000010000") ;
unsigned long long int const FILED = bitsetFILED.to_ullong() ;

std::bitset<64> const bitsetFILEE("0000100000001000000010000000100000001000000010000000100000001000") ;
unsigned long long int const FILEE = bitsetFILEE.to_ullong() ;

std::bitset<64> const bitsetFILEF("0000010000000100000001000000010000000100000001000000010000000100") ;
unsigned long long int const FILEF = bitsetFILEF.to_ullong() ;

std::bitset<64> const bitsetFILEG("0000001000000010000000100000001000000010000000100000001000000010") ;
unsigned long long int const FILEG = bitsetFILEG.to_ullong() ;

std::bitset<64> const bitsetFILEH("0000000100000001000000010000000100000001000000010000000100000001") ;
unsigned long long int const FILEH = bitsetFILEH.to_ullong() ;

unsigned long long int const FILES [8] = {FILEA, FILEB, FILEC, FILED, FILEE, FILEF, FILEG, FILEH} ;


std::bitset<64> const bitsetRANK1("0000000000000000000000000000000000000000000000000000000011111111") ;
unsigned long long int const RANK1 = bitsetRANK1.to_ullong() ;

std::bitset<64> const bitsetRANK2("0000000000000000000000000000000000000000000000001111111100000000") ;
unsigned long long int const RANK2 = bitsetRANK2.to_ullong() ;

std::bitset<64> const bitsetRANK3("0000000000000000000000000000000000000000111111110000000000000000") ;
unsigned long long int const RANK3 = bitsetRANK3.to_ullong() ;

std::bitset<64> const bitsetRANK4("0000000000000000000000000000000011111111000000000000000000000000") ;
unsigned long long int const RANK4 = bitsetRANK4.to_ullong() ;

std::bitset<64> const bitsetRANK5("0000000000000000000000001111111100000000000000000000000000000000") ;
unsigned long long int const RANK5 = bitsetRANK5.to_ullong() ;

std::bitset<64> const bitsetRANK6("0000000000000000111111110000000000000000000000000000000000000000") ;
unsigned long long int const RANK6 = bitsetRANK6.to_ullong() ;

std::bitset<64> const bitsetRANK7("0000000011111111000000000000000000000000000000000000000000000000") ;
unsigned long long int const RANK7 = bitsetRANK7.to_ullong() ;

std::bitset<64> const bitsetRANK8("1111111100000000000000000000000000000000000000000000000000000000") ;
unsigned long long int const RANK8 = bitsetRANK8.to_ullong() ;

unsigned long long int const RANKS [8] = {RANK1, RANK2, RANK3, RANK4, RANK5, RANK6, RANK7, RANK8} ;


std::bitset<64> const bitsetDIAG1("1000000000000000000000000000000000000000000000000000000000000000") ;
unsigned long long int const DIAG1 = bitsetDIAG1.to_ullong() ;

std::bitset<64> const bitsetDIAG2("0100000010000000000000000000000000000000000000000000000000000000") ;
unsigned long long int const DIAG2 = bitsetDIAG2.to_ullong() ;

std::bitset<64> const bitsetDIAG3("0010000001000000100000000000000000000000000000000000000000000000") ;
unsigned long long int const DIAG3 = bitsetDIAG3.to_ullong() ;

std::bitset<64> const bitsetDIAG4("0001000000100000010000001000000000000000000000000000000000000000") ;
unsigned long long int const DIAG4 = bitsetDIAG4.to_ullong() ;

std::bitset<64> const bitsetDIAG5("0000100000010000001000000100000010000000000000000000000000000000") ;
unsigned long long int const DIAG5 = bitsetDIAG5.to_ullong() ;

std::bitset<64> const bitsetDIAG6("0000010000001000000100000010000001000000100000000000000000000000") ;
unsigned long long int const DIAG6 = bitsetDIAG6.to_ullong() ;

std::bitset<64> const bitsetDIAG7("0000001000000100000010000001000000100000010000001000000000000000") ;
unsigned long long int const DIAG7 = bitsetDIAG7.to_ullong() ;

std::bitset<64> const bitsetDIAG8("0000000100000010000001000000100000010000001000000100000010000000") ;
unsigned long long int const DIAG8 = bitsetDIAG8.to_ullong() ;

std::bitset<64> const bitsetDIAG9("0000000000000001000000100000010000001000000100000010000001000000") ;
unsigned long long int const DIAG9 = bitsetDIAG9.to_ullong() ;

std::bitset<64> const bitsetDIAG10("0000000000000000000000010000001000000100000010000001000000100000") ;
unsigned long long int const DIAG10 = bitsetDIAG10.to_ullong() ;

std::bitset<64> const bitsetDIAG11("0000000000000000000000000000000100000010000001000000100000010000") ;
unsigned long long int const DIAG11 = bitsetDIAG11.to_ullong() ;

std::bitset<64> const bitsetDIAG12("0000000000000000000000000000000000000001000000100000010000001000") ;
unsigned long long int const DIAG12 = bitsetDIAG12.to_ullong() ;

std::bitset<64> const bitsetDIAG13("0000000000000000000000000000000000000000000000010000001000000100") ;
unsigned long long int const DIAG13 = bitsetDIAG13.to_ullong() ;

std::bitset<64> const bitsetDIAG14("0000000000000000000000000000000000000000000000000000000100000010") ;
unsigned long long int const DIAG14 = bitsetDIAG14.to_ullong() ;

std::bitset<64> const bitsetDIAG15("0000000000000000000000000000000000000000000000000000000000000001") ;
unsigned long long int const DIAG15 = bitsetDIAG15.to_ullong() ;

unsigned long long int const bDIAGS [7] = {DIAG8, DIAG14, DIAG6, DIAG12, DIAG4, DIAG10, DIAG2} ;
unsigned long long int const wDIAGS [7] = {0, DIAG7, DIAG13, DIAG5, DIAG11, DIAG3, DIAG9} ;


std::bitset<64> const bitsetCDIAG1("0000000000000000000000000000000000000000000000000000000010000000") ;
unsigned long long int const CDIAG1 = bitsetCDIAG1.to_ullong() ;

std::bitset<64> const bitsetCDIAG2("0000000000000000000000000000000000000000000000001000000001000000") ;
unsigned long long int const CDIAG2 = bitsetCDIAG2.to_ullong() ;

std::bitset<64> const bitsetCDIAG3("0000000000000000000000000000000000000000100000000100000000100000") ;
unsigned long long int const CDIAG3 = bitsetCDIAG3.to_ullong() ;

std::bitset<64> const bitsetCDIAG4("0000000000000000000000000000000010000000010000000010000000010000") ;
unsigned long long int const CDIAG4 = bitsetCDIAG4.to_ullong() ;

std::bitset<64> const bitsetCDIAG5("0000000000000000000000001000000001000000001000000001000000001000") ;
unsigned long long int const CDIAG5 = bitsetCDIAG5.to_ullong() ;

std::bitset<64> const bitsetCDIAG6("0000000000000000100000000100000000100000000100000000100000000100") ;
unsigned long long int const CDIAG6 = bitsetCDIAG6.to_ullong() ;

std::bitset<64> const bitsetCDIAG7("0000000010000000010000000010000000010000000010000000010000000010") ;
unsigned long long int const CDIAG7 = bitsetCDIAG7.to_ullong() ;

std::bitset<64> const bitsetCDIAG8("1000000001000000001000000001000000001000000001000000001000000001") ;
unsigned long long int const CDIAG8 = bitsetCDIAG8.to_ullong() ;

std::bitset<64> const bitsetCDIAG9("0100000000100000000100000000100000000100000000100000000100000000") ;
unsigned long long int const CDIAG9 = bitsetCDIAG9.to_ullong() ;

std::bitset<64> const bitsetCDIAG10("0010000000010000000010000000010000000010000000010000000000000000") ;
unsigned long long int const CDIAG10 = bitsetCDIAG10.to_ullong() ;

std::bitset<64> const bitsetCDIAG11("0001000000001000000001000000001000000001000000000000000000000000") ;
unsigned long long int const CDIAG11 = bitsetCDIAG11.to_ullong() ;

std::bitset<64> const bitsetCDIAG12("0000100000000100000000100000000100000000000000000000000000000000") ;
unsigned long long int const CDIAG12 = bitsetCDIAG12.to_ullong() ;

std::bitset<64> const bitsetCDIAG13("0000010000000010000000010000000000000000000000000000000000000000") ;
unsigned long long int const CDIAG13 = bitsetCDIAG13.to_ullong() ;

std::bitset<64> const bitsetCDIAG14("0000001000000001000000000000000000000000000000000000000000000000") ;
unsigned long long int const CDIAG14 = bitsetCDIAG14.to_ullong() ;

std::bitset<64> const bitsetCDIAG15("0000000100000000000000000000000000000000000000000000000000000000") ;
unsigned long long int const CDIAG15 = bitsetCDIAG15.to_ullong() ;

unsigned long long int const bCDIAGS [9] = {0, CDIAG7, CDIAG15, CDIAG5, CDIAG13, CDIAG3, CDIAG11, CDIAG1, CDIAG9} ;
unsigned long long int const wCDIAGS [9] = {CDIAG8, 0, CDIAG6, CDIAG14, CDIAG4, CDIAG12, CDIAG2, CDIAG10, 0} ;

/*
unsigned long long int FILEA = constants::FILEA ;
unsigned long long int FILEB = constants::FILEB ;
unsigned long long int FILEC = constants::FILEC ;
unsigned long long int FILED = constants::FILED ;
unsigned long long int FILEE = constants::FILEE ;
unsigned long long int FILEF = constants::FILEF ;
unsigned long long int FILEG = constants::FILEG ;
unsigned long long int FILEH = constants::FILEH ;

unsigned long long int RANK1 = constants::RANK1 ;
unsigned long long int RANK2 = constants::RANK2 ;
unsigned long long int RANK3 = constants::RANK3 ;
unsigned long long int RANK4 = constants::RANK4 ;
unsigned long long int RANK5 = constants::RANK5 ;
unsigned long long int RANK6 = constants::RANK6 ;
unsigned long long int RANK7 = constants::RANK7 ;
unsigned long long int RANK8 = constants::RANK8 ;


unsigned long long int DIAG1= constants::DIAG1 ;
unsigned long long int DIAG2= constants::DIAG2 ;
unsigned long long int DIAG3= constants::DIAG3 ;
unsigned long long int DIAG4= constants::DIAG4 ;
unsigned long long int DIAG5= constants::DIAG5 ;
unsigned long long int DIAG6= constants::DIAG6 ;
unsigned long long int DIAG7= constants::DIAG7 ;
unsigned long long int DIAG8= constants::DIAG8 ;
unsigned long long int DIAG9= constants::DIAG9 ;
unsigned long long int DIAG10= constants::DIAG10 ;
unsigned long long int DIAG11= constants::DIAG11 ;
unsigned long long int DIAG12= constants::DIAG12 ;
unsigned long long int DIAG13= constants::DIAG13 ;
unsigned long long int DIAG14= constants::DIAG14 ;
unsigned long long int DIAG15= constants::DIAG15 ;


unsigned long long int CDIAG1= constants::CDIAG1 ;
unsigned long long int CDIAG2= constants::CDIAG2 ;
unsigned long long int CDIAG3= constants::CDIAG3 ;
unsigned long long int CDIAG4= constants::CDIAG4 ;
unsigned long long int CDIAG5= constants::CDIAG5 ;
unsigned long long int CDIAG6= constants::CDIAG6 ;
unsigned long long int CDIAG7= constants::CDIAG7 ;
unsigned long long int CDIAG8= constants::CDIAG8 ;
unsigned long long int CDIAG9= constants::CDIAG9 ;
unsigned long long int CDIAG10= constants::CDIAG10 ;
unsigned long long int CDIAG11= constants::CDIAG11 ;
unsigned long long int CDIAG12= constants::CDIAG12 ;
unsigned long long int CDIAG13= constants::CDIAG13 ;
unsigned long long int CDIAG14= constants::CDIAG14 ;
unsigned long long int CDIAG15= constants::CDIAG15 ;


unsigned long long int const RANKS [8] = {RANK1, RANK2, RANK3, RANK4, RANK5, RANK6, RANK7, RANK8} ;
unsigned long long int const FILES [8] = {FILEA, FILEB, FILEC, FILED, FILEE, FILEF, FILEG, FILEH} ;
unsigned long long int const bDIAGS [7] = {DIAG8, DIAG14, DIAG6, DIAG12, DIAG4, DIAG10, DIAG2} ;
unsigned long long int const wDIAGS [7] = {0, DIAG7, DIAG13, DIAG5, DIAG11, DIAG3, DIAG9} ;

unsigned long long int const bCDIAGS [9] = {0, CDIAG7, CDIAG15, CDIAG5, CDIAG13, CDIAG3, CDIAG11, CDIAG1, CDIAG9} ;
unsigned long long int const wCDIAGS [9] = {CDIAG8, 0, CDIAG6, CDIAG14, CDIAG4, CDIAG12, CDIAG2, CDIAG10, 0} ;
*/


/*unsigned long long int reverseULL(unsigned long long int b) {
    b = (b & 0xFFFFFFFF00000000) >> 32 | (b & 0x00000000FFFFFFFF) << 32 ;
    b = (b & 0xFFFF0000FFFF0000) >> 16 | (b & 0x0000FFFF0000FFFF) << 16 ;
    b = (b & 0xFF00FF00FF00FF00) >> 8  | (b & 0x00FF00FF00FF00FF) << 8 ;
    b = (b & 0xF0F0F0F0F0F0F0F0) >> 4  | (b & 0x0F0F0F0F0F0F0F0F) << 4 ;
    b = (b & 0xCCCCCCCCCCCCCCCC) >> 2  | (b & 0x3333333333333333) << 2 ;
    b = (b & 0xAAAAAAAAAAAAAAAA) >> 1  | (b & 0x5555555555555555) << 1 ;

    return b ;
}
*/

void legPaW (std::vector<int>& moves, unsigned long long int P,
             unsigned long long int whitePieces, unsigned long long int blackPieces,
             unsigned long long int occupied, unsigned long long int enPassant){

     //std::string nothing ;

    unsigned long long int attackRight, attackLeft, advance1, advance2 ;

    attackRight = P ;
    attackLeft = P ;
    advance1 = P ;
    advance2 = P ;

    attackRight <<= 7 ;
    attackLeft <<= 9 ;
    advance1 <<= 8 ;
    advance2 <<= 16 ;

    attackRight = attackRight & ~FILEA & (blackPieces | enPassant) ;
    attackLeft = attackLeft & ~FILEH & (blackPieces | enPassant) ;
    advance1 = advance1 &~occupied;
    advance2 = advance2 &RANK4 &~occupied &~(occupied<<8);

    //coutBitSet(attackLeft) ;
    //std::cin >> nothing ;

    for (int k = 16 ; k < 63 ; k++ ){
        if ((attackRight>>k)&1) {
            int dest = k ;
            int pos = k - 7 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }
    for (int k = 17 ; k < 64 ; k++ ){
        if ((attackLeft>>k)&1) {
            int dest = k ;
            int pos = k - 9 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }
    for (int k = 16 ; k < 64 ; k++ ){
        if ((advance1>>k)&1) {
            int dest = k ;
            int pos = k - 8 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }

    for (int k = 24 ; k < 32 ; k++ ){
        if ((advance2>>k)&1) {
            int dest = k ;
            int pos = k - 16 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }
}


void legPaB (std::vector<int>& moves, unsigned long long int p,
             unsigned long long int whitePieces, unsigned long long int blackPieces,
             unsigned long long int occupied, unsigned long long int enPassant){

    unsigned long long int attackRight, attackLeft, advance1, advance2 ;

    attackRight = p ;
    attackLeft = p ;
    advance1 = p ;
    advance2 = p ;

    attackRight >>= 9 ;
    attackLeft >>= 7 ;
    advance1 >>= 8 ;
    advance2 >>= 16 ;

    attackRight = attackRight & ~FILEA & (whitePieces | enPassant) ;
    attackLeft = attackLeft & ~FILEH & (whitePieces | enPassant) ;
    advance1 = advance1 &~occupied ;
    advance2 = advance2 &RANK5 &~occupied &~(occupied>>8);

    //coutBitSet(pAttackRight) ;

    for (int k = 0 ; k < 47 ; k++ ){
        if ((attackRight>>k)&1) {
            int dest = k ;
            int pos = k + 9 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }
    for (int k = 1 ; k < 48 ; k++ ){
        if ((attackLeft>>k)&1) {
            int dest = k ;
            int pos = k + 7 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }
    for (int k = 0 ; k < 48 ; k++ ){
        if ((advance1>>k)&1) {
            int dest = k ;
            int pos = k + 8 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }

    for (int k = 32 ; k < 40 ; k++ ){
        if ((advance2>>k)&1) {
            int dest = k ;
            int pos = k + 16 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }
}


void sliderHV (std::vector<int>& moves, unsigned long long int piece,
            unsigned long long int allyPieces,
             unsigned long long int occupied){

    unsigned long long int slider ;
    unsigned long long int sliderReverse ;
    unsigned long long int lineAttack ;

    for (int k = 0 ; k < 64 ; k++ ){
        if ((piece>>k)&1){

            slider = 1 ;
            slider <<= k ;

            sliderReverse = reverseULL(slider) ;

            lineAttack = (((occupied&RANKS[k/8]) - 2*slider) ^ reverseULL(reverseULL((occupied&RANKS[k/8])) - 2*sliderReverse))&RANKS[k/8] ;

            lineAttack |= (((occupied&FILES[7-k%8]) - 2*slider) ^ reverseULL(reverseULL((occupied&FILES[7-k%8])) - 2*sliderReverse))&FILES[7-k%8] ;

            lineAttack &= ~allyPieces;

            //coutBitSet(lineAttack) ;

            for (int i = 0 ; i < 64 ; i++ ){
                if ((lineAttack>>i)&1){
                        moves.push_back(k) ;
                        moves.push_back(i) ;
                }
            }
        }
    }
 }


void sliderD (std::vector<int>& moves, unsigned long long int piece,
         unsigned long long int allyPieces,
         unsigned long long int occupied){

    //std::string nothing ;

    unsigned long long int slider ;
    unsigned long long int sliderReverse ;
    unsigned long long int lineAttack ;
    unsigned long long int maskDiag ;

    for (int k = 0 ; k < 64 ; k++ ){
        if ((piece>>k)&1){

            slider = 1 ;
            slider <<= k ;

            sliderReverse = reverseULL(slider) ;

            //std::cout << "noir = " << (k/8 + k%8)%2 << "\tblanc = " << !((k/8 + k%8)%2) << "\tk%7 = " << k%7 << std::endl ;

            if ((k/8 + k%8)%2){
                maskDiag = bDIAGS[k%7] ;
            } else {
                maskDiag = wDIAGS[k%7] ;
            }


            //coutBitSet(maskDiag) ;

            lineAttack = (((occupied&maskDiag) - 2*slider) ^ reverseULL(reverseULL((occupied&maskDiag)) - 2*sliderReverse))&maskDiag ;

            //lineAttack |= (((occupied&FILES[k/8]) - 2*slider) ^ reverseULL(reverseULL((occupied&FILES[k/8])) - 2*sliderReverse))&FILES[k/8] ;

            lineAttack &= ~allyPieces;

            //std::cout << "attack bit is :" << std::endl ;
            //coutBitSet(lineAttack) ;
            //std::cin >> nothing ;

            for (int i = 0 ; i < 64 ; i++ ){
                if ((lineAttack>>i)&1){
                        moves.push_back(k) ;
                        moves.push_back(i) ;
                }
            }
        }
    }
}


void sliderCD (std::vector<int>& moves, unsigned long long int piece,
         unsigned long long int allyPieces,
         unsigned long long int occupied){

    //std::string nothing ;
    unsigned long long int slider ;
    unsigned long long int sliderReverse ;
    unsigned long long int lineAttack ;
    unsigned long long int maskDiag ;

    for (int k = 0 ; k < 64 ; k++ ){
        if ((piece>>k)&1){

            slider = 1 ;
            slider <<= k ;

            sliderReverse = reverseULL(slider) ;

            //std::cout << "noir = " << (k/8 + k%8)%2 << "\tblanc = " << !((k/8 + k%8)%2) << "\tk%9 = " << k%9 << std::endl ;

            if ((k/8 + k%8)%2){
                maskDiag = bCDIAGS[k%9] ;
            } else {
                maskDiag = wCDIAGS[k%9] ;
            }


            //coutBitSet(maskDiag) ;

            lineAttack = (((occupied&maskDiag) - 2*slider) ^ reverseULL(reverseULL((occupied&maskDiag)) - 2*sliderReverse))&maskDiag ;

            //lineAttack |= (((occupied&FILES[k/8]) - 2*slider) ^ reverseULL(reverseULL((occupied&FILES[k/8])) - 2*sliderReverse))&FILES[k/8] ;

            lineAttack &= ~allyPieces;

            //std::cout << "attack bit is :" << std::endl ;
            //coutBitSet(lineAttack) ;
            //std::cin >> nothing ;


            for (int i = 0 ; i < 64 ; i++ ){
                if ((lineAttack>>i)&1){
                        moves.push_back(k) ;
                        moves.push_back(i) ;
                }
            }
        }
    }
}


void KnightMoves(std::vector<int>& moves, unsigned long long int piece,
         unsigned long long int allyPieces){

    //std::string nothing ;
    unsigned long long int knight ;
    unsigned long long int Nmove ;
    unsigned long long int Nmoves ;

    for (int k = 0 ; k < 64 ; k++ ){
        Nmoves = 0 ;
        if ((piece>>k)&1){

            knight = 1 ;
            knight <<= k ;

            Nmove = knight ; // //>
            Nmove <<= 15  ;
            Nmove &= ~(RANK1 | RANK2 | FILEA) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // //<
            Nmove <<= 17  ;
            Nmove &= ~(RANK1 | RANK2 | FILEH) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // \\>
            Nmove >>= 17  ;
            Nmove &= ~(RANK8 | RANK7 | FILEA) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // \\<
            Nmove >>= 15  ;
            Nmove &= ~(RANK8 | RANK7 | FILEH) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // />>
            Nmove <<= 6  ;
            Nmove &= ~(RANK1 | FILEA | FILEB) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // /<<
            Nmove <<= 10  ;
            Nmove &= ~(RANK1 | FILEG | FILEH) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // \>>
            Nmove >>= 10  ;
            Nmove &= ~(RANK8 | FILEA | FILEB) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // \<<
            Nmove >>= 6  ;
            Nmove &= ~(RANK8 | FILEG | FILEH) ;
            Nmoves |= Nmove ;

            Nmoves &= ~allyPieces ;

            //coutBitSet(Nmoves|knight) ;
            //std::cin >> nothing ;

            for (int i = 0 ; i < 64 ; i++ ){
                if ((Nmoves>>i)&1){
                        moves.push_back(k) ;
                        moves.push_back(i) ;
                }
            }
        }
    }
}


void KingMoves(std::vector<int>& moves, unsigned long long int piece,unsigned long long int rook,
         unsigned long long int allyPieces, unsigned long long int occupied,
         bool CstlL, bool CstlS, bool cstlL, bool cstlS){

    unsigned long long int king ;
    unsigned long long int Nmove ;
    unsigned long long int Nmoves (0);

    for (int k = 0 ; k < 64 ; k++ ){ // optimisable
        if ((piece>>k)&1){

            if (k==3){

                if ((CstlS)&& (!((occupied>>2)&1)) && (!((occupied>>1)&1)) && (rook&1) ){
                    moves.push_back(3) ;
                    moves.push_back(1) ;
                }
                if ((CstlL) && (!((occupied>>6)&1)) && (!((occupied>>5)&1)) && (!((occupied>>4)&1))&&(rook>>7&1)){
                    moves.push_back(3) ;
                    moves.push_back(5) ;
                }
            }

            if (k==59){
                if ((cstlS) && (!((occupied>>58)&1)) && (!((occupied>>57)&1))&&(rook>>56&1)){
                    moves.push_back(59) ;
                    moves.push_back(57) ;
                }
                if ((cstlL) && (!((occupied>>60)&1)) && (!((occupied>>61)&1)) && (!((occupied>>62)&1))&&(rook>>63&1)){
                    moves.push_back(59) ;
                    moves.push_back(61) ;
                }
            }


            king = 1 ;
            king <<= k ;

            Nmove = king ; // />
            Nmove <<= 7  ;
            Nmove &= ~(RANK1 | FILEA) ;
            Nmoves |= Nmove ;

            Nmove = king ; // >
            Nmove >>= 1  ;
            Nmove &= ~(FILEA) ;
            Nmoves |= Nmove ;

            Nmove = king ; // \>
            Nmove >>= 9  ;
            Nmove &= ~(RANK8 | FILEA) ;
            Nmoves |= Nmove ;

            Nmove = king ; // /<
            Nmove <<= 9  ;
            Nmove &= ~(RANK1 | FILEH) ;
            Nmoves |= Nmove ;

            Nmove = king ; // <
            Nmove <<= 1  ;
            Nmove &= ~(FILEH) ;
            Nmoves |= Nmove ;

            Nmove = king ; // \<
            Nmove >>= 7  ;
            Nmove &= ~(RANK8 | FILEH) ;
            Nmoves |= Nmove ;

            Nmove = king ; // /
            Nmove <<= 8  ;
            Nmove &= ~(RANK1) ;
            Nmoves |= Nmove ;

            Nmove = king ; // \.
            Nmove >>= 8  ;
            Nmove &= ~(RANK8) ;
            Nmoves |= Nmove ;

            Nmoves &= ~allyPieces ;

            for (int i = 0 ; i < 64 ; i++ ){
                if ((Nmoves>>i)&1){
                        moves.push_back(k) ;
                        moves.push_back(i) ;
                }
            }
            break ;
        }
    }
}


void legPaW2 (std::vector<int>& moves, unsigned long long int P,
             unsigned long long int whitePieces, unsigned long long int blackPieces,
             unsigned long long int occupied, unsigned long long int enPassant){

     //std::string nothing ;

    unsigned long long int attackRight, attackLeft;

    attackRight = P ;
    attackLeft = P ;

    attackRight <<= 7 ;
    attackLeft <<= 9 ;

    attackRight = attackRight & ~FILEA & (blackPieces | enPassant) ;
    attackLeft = attackLeft & ~FILEH & (blackPieces | enPassant) ;

    //coutBitSet(attackLeft) ;
    //std::cin >> nothing ;

    for (int k = 16 ; k < 63 ; k++ ){
        if ((attackRight>>k)&1) {
            int dest = k ;
            int pos = k - 7 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }
    for (int k = 17 ; k < 64 ; k++ ){
        if ((attackLeft>>k)&1) {
            int dest = k ;
            int pos = k - 9 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }
}

void legPaB2 (std::vector<int>& moves, unsigned long long int p,
             unsigned long long int whitePieces, unsigned long long int blackPieces,
             unsigned long long int occupied, unsigned long long int enPassant){

    unsigned long long int attackRight, attackLeft;

    attackRight = p ;
    attackLeft = p ;

    attackRight >>= 9 ;
    attackLeft >>= 7 ;

    attackRight = attackRight & ~FILEA & (whitePieces | enPassant) ;
    attackLeft = attackLeft & ~FILEH & (whitePieces | enPassant) ;

    //coutBitSet(pAttackRight) ;

    for (int k = 0 ; k < 47 ; k++ ){
        if ((attackRight>>k)&1) {
            int dest = k ;
            int pos = k + 9 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }
    for (int k = 1 ; k < 48 ; k++ ){
        if ((attackLeft>>k)&1) {
            int dest = k ;
            int pos = k + 7 ;
            moves.push_back(pos);
            moves.push_back(dest);
        }
    }

}


void sliderHV2(std::vector<int>& moves, unsigned long long int piece,
            unsigned long long int allyPieces,
             unsigned long long int occupied){

    unsigned long long int slider ;
    unsigned long long int sliderReverse ;
    unsigned long long int lineAttack ;

    for (int k = 0 ; k < 64 ; k++ ){
        if ((piece>>k)&1){

            slider = 1 ;
            slider <<= k ;

            sliderReverse = reverseULL(slider) ;

            lineAttack = (((occupied&RANKS[k/8]) - 2*slider) ^ reverseULL(reverseULL((occupied&RANKS[k/8])) - 2*sliderReverse))&RANKS[k/8] ;

            lineAttack |= (((occupied&FILES[7-k%8]) - 2*slider) ^ reverseULL(reverseULL((occupied&FILES[7-k%8])) - 2*sliderReverse))&FILES[7-k%8] ;

            lineAttack &= occupied&(~allyPieces) ;

            //coutBitSet(lineAttack) ;

            for (int i = 0 ; i < 64 ; i++ ){
                if ((lineAttack>>i)&1){
                        moves.push_back(k) ;
                        moves.push_back(i) ;
                }
            }
        }
    }
 }


void sliderD2(std::vector<int>& moves, unsigned long long int piece,
         unsigned long long int allyPieces,
         unsigned long long int occupied){

    //std::string nothing ;

    unsigned long long int slider ;
    unsigned long long int sliderReverse ;
    unsigned long long int lineAttack ;
    unsigned long long int maskDiag ;

    for (int k = 0 ; k < 64 ; k++ ){
        if ((piece>>k)&1){

            slider = 1 ;
            slider <<= k ;

            sliderReverse = reverseULL(slider) ;

            //std::cout << "noir = " << (k/8 + k%8)%2 << "\tblanc = " << !((k/8 + k%8)%2) << "\tk%7 = " << k%7 << std::endl ;

            if ((k/8 + k%8)%2){
                maskDiag = bDIAGS[k%7] ;
            } else {
                maskDiag = wDIAGS[k%7] ;
            }


            //coutBitSet(maskDiag) ;

            lineAttack = (((occupied&maskDiag) - 2*slider) ^ reverseULL(reverseULL((occupied&maskDiag)) - 2*sliderReverse))&maskDiag ;

            //lineAttack |= (((occupied&FILES[k/8]) - 2*slider) ^ reverseULL(reverseULL((occupied&FILES[k/8])) - 2*sliderReverse))&FILES[k/8] ;

            lineAttack &= occupied&(~allyPieces) ;

            //std::cout << "attack bit is :" << std::endl ;
            //coutBitSet(lineAttack) ;
            //std::cin >> nothing ;

            for (int i = 0 ; i < 64 ; i++ ){
                if ((lineAttack>>i)&1){
                        moves.push_back(k) ;
                        moves.push_back(i) ;
                }
            }
        }
    }
}


void sliderCD2(std::vector<int>& moves, unsigned long long int piece,
         unsigned long long int allyPieces,
         unsigned long long int occupied){

    //std::string nothing ;
    unsigned long long int slider ;
    unsigned long long int sliderReverse ;
    unsigned long long int lineAttack ;
    unsigned long long int maskDiag ;

    for (int k = 0 ; k < 64 ; k++ ){
        if ((piece>>k)&1){

            slider = 1 ;
            slider <<= k ;

            sliderReverse = reverseULL(slider) ;

            //std::cout << "noir = " << (k/8 + k%8)%2 << "\tblanc = " << !((k/8 + k%8)%2) << "\tk%9 = " << k%9 << std::endl ;

            if ((k/8 + k%8)%2){
                maskDiag = bCDIAGS[k%9] ;
            } else {
                maskDiag = wCDIAGS[k%9] ;
            }


            //coutBitSet(maskDiag) ;

            lineAttack = (((occupied&maskDiag) - 2*slider) ^ reverseULL(reverseULL((occupied&maskDiag)) - 2*sliderReverse))&maskDiag ;

            //lineAttack |= (((occupied&FILES[k/8]) - 2*slider) ^ reverseULL(reverseULL((occupied&FILES[k/8])) - 2*sliderReverse))&FILES[k/8] ;

            lineAttack &= occupied&(~allyPieces) ;

            //std::cout << "attack bit is :" << std::endl ;
            //coutBitSet(lineAttack) ;
            //std::cin >> nothing ;


            for (int i = 0 ; i < 64 ; i++ ){
                if ((lineAttack>>i)&1){
                        moves.push_back(k) ;
                        moves.push_back(i) ;
                }
            }
        }
    }
}


void KnightMoves2(std::vector<int>& moves, unsigned long long int piece, unsigned long long int occupied,
         unsigned long long int allyPieces){

    //std::string nothing ;
    unsigned long long int knight ;
    unsigned long long int Nmove ;
    unsigned long long int Nmoves ;

    for (int k = 0 ; k < 64 ; k++ ){
        Nmoves = 0 ;
        if ((piece>>k)&1){

            knight = 1 ;
            knight <<= k ;

            Nmove = knight ; // //>
            Nmove <<= 15  ;
            Nmove &= ~(RANK1 | RANK2 | FILEA) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // //<
            Nmove <<= 17  ;
            Nmove &= ~(RANK1 | RANK2 | FILEH) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // \\>
            Nmove >>= 17  ;
            Nmove &= ~(RANK8 | RANK7 | FILEA) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // \\<
            Nmove >>= 15  ;
            Nmove &= ~(RANK8 | RANK7 | FILEH) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // />>
            Nmove <<= 6  ;
            Nmove &= ~(RANK1 | FILEA | FILEB) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // /<<
            Nmove <<= 10  ;
            Nmove &= ~(RANK1 | FILEG | FILEH) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // \>>
            Nmove >>= 10  ;
            Nmove &= ~(RANK8 | FILEA | FILEB) ;
            Nmoves |= Nmove ;

            Nmove = knight ; // \<<
            Nmove >>= 6  ;
            Nmove &= ~(RANK8 | FILEG | FILEH) ;
            Nmoves |= Nmove ;

            Nmoves &= occupied&(~allyPieces) ;

            //coutBitSet(Nmoves|knight) ;
            //std::cin >> nothing ;

            for (int i = 0 ; i < 64 ; i++ ){
                if ((Nmoves>>i)&1){
                        moves.push_back(k) ;
                        moves.push_back(i) ;
                }
            }
        }
    }
}


void KingMoves2(std::vector<int>& moves, unsigned long long int piece,unsigned long long int rook,
         unsigned long long int allyPieces, unsigned long long int occupied,
         bool CstlL, bool CstlS, bool cstlL, bool cstlS){

    unsigned long long int king ;
    unsigned long long int Nmove ;
    unsigned long long int Nmoves (0);

    for (int k = 0 ; k < 64 ; k++ ){ // optimisable
        if ((piece>>k)&1){

            king = 1 ;
            king <<= k ;

            Nmove = king ; // />
            Nmove <<= 7  ;
            Nmove &= ~(RANK1 | FILEA) ;
            Nmoves |= Nmove ;

            Nmove = king ; // >
            Nmove >>= 1  ;
            Nmove &= ~(FILEA) ;
            Nmoves |= Nmove ;

            Nmove = king ; // \>
            Nmove >>= 9  ;
            Nmove &= ~(RANK8 | FILEA) ;
            Nmoves |= Nmove ;

            Nmove = king ; // /<
            Nmove <<= 9  ;
            Nmove &= ~(RANK1 | FILEH) ;
            Nmoves |= Nmove ;

            Nmove = king ; // <
            Nmove <<= 1  ;
            Nmove &= ~(FILEH) ;
            Nmoves |= Nmove ;

            Nmove = king ; // \<
            Nmove >>= 7  ;
            Nmove &= ~(RANK8 | FILEH) ;
            Nmoves |= Nmove ;

            Nmove = king ; // /
            Nmove <<= 8  ;
            Nmove &= ~(RANK1) ;
            Nmoves |= Nmove ;

            Nmove = king ; // \.
            Nmove >>= 8  ;
            Nmove &= ~(RANK8) ;
            Nmoves |= Nmove ;

            Nmoves &= occupied&(~allyPieces) ;

            for (int i = 0 ; i < 64 ; i++ ){
                if ((Nmoves>>i)&1){

                        moves.push_back(k) ;
                        moves.push_back(i) ;
                }
            }
            break ;
        }
    }
}
