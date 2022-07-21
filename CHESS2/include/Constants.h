#ifndef CONSTANTS_H
#define CONSTANTS_H
/*
#include <limits>


#include <bitset>


namespace constants
{

    int GLOBALintINFINITY = std::numeric_limits<int>::max();

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




    unsigned long long int PawnSqTbW50 = RANK7 ;

    std::bitset<64> const bitsetPawnSqTbW30("0000000000000000000110000000000000000000000000000000000000000000") ;
    unsigned long long int const PawnSqTbW30 = bitsetPawnSqTbW30.to_ullong() ;

    std::bitset<64> const bitsetPawnSqTbW27("0000000000000000000000000001100000000000000000000000000000000000") ;
    unsigned long long int const PawnSqTbW27 = bitsetPawnSqTbW27.to_ullong() ;

    std::bitset<64> const bitsetPawnSqTbW25("0000000000000000000000000000000000011000000000000000000000000000") ;
    unsigned long long int const PawnSqTbW25 = bitsetPawnSqTbW25.to_ullong() ;

    std::bitset<64> const bitsetPawnSqTbW20("0000000000000000001001000000000000000000000000000000000000000000") ;
    unsigned long long int const PawnSqTbW20 = bitsetPawnSqTbW20.to_ullong() ;

    std::bitset<64> const bitsetPawnSqTbW10("0000000000000000110000110010010000000000000000000110011000000000") ;
    unsigned long long int const PawnSqTbW10 = bitsetPawnSqTbW10.to_ullong() ;

    std::bitset<64> const bitsetPawnSqTbW5("0000000000000000000000001100001100000000100000011000000100000000") ;
    unsigned long long int const PawnSqTbW5 = bitsetPawnSqTbW5.to_ullong() ;

    std::bitset<64> const bitsetPawnSqTbWm5("0000000000000000000000000000000000000000010000100000000000000000") ;
    unsigned long long int const PawnSqTbWm5 = bitsetPawnSqTbWm5.to_ullong() ;

    std::bitset<64> const bitsetPawnSqTbWm10("0000000000000000000000000000000000000000001001000000000000000000") ;
    unsigned long long int const PawnSqTbWm10 = bitsetPawnSqTbWm10.to_ullong() ;

    std::bitset<64> const bitsetPawnSqTbWm25("0000000000000000000000000000000000000000000000000001100000000000") ;
    unsigned long long int const PawnSqTbWm25 = bitsetPawnSqTbWm25.to_ullong() ;

    std::bitset<64> const bitsetN20("0000000000000000000000000001100000011000000000000000000000000000") ;
    unsigned long long int const N20 = bitsetN20.to_ullong() ;

    std::bitset<64> const bitsetN15("0000000000000000000110000010010000100100000110000000000000000000") ;
    unsigned long long int const N15 = bitsetN15.to_ullong() ;

    std::bitset<64> const bitsetN10("0000000000000000001001000000000000000000001001000000000000000000") ;
    unsigned long long int const N10 = bitsetN10.to_ullong() ;


    std::bitset<64> const bitsetN5("0000000000000000000000000100001000000000010000100000000000000000") ;
    unsigned long long int const N5 = bitsetN5.to_ullong() ;

    std::bitset<64> const bitsetNm20("0000000001000010000000000000000000000000000000000100001000100100") ;
    unsigned long long int const Nm20 = bitsetNm20.to_ullong() ;

    std::bitset<64> const bitsetNm30("0011110000000000100000011000000110000001100000010000000000011000") ;
    unsigned long long int const Nm30 = bitsetNm30.to_ullong() ;

    std::bitset<64> const bitsetNm40("0100001010000001000000000000000000000000000000001000000101000010") ;
    unsigned long long int const Nm40 = bitsetNm40.to_ullong() ;

    std::bitset<64> const bitsetNm50("1000000100000000000000000000000000000000000000000000000010000001") ;
    unsigned long long int const Nm50 = bitsetNm50.to_ullong() ;

    std::bitset<64> const bitsetB10("0000000000000000000110000001100000011000001001000110011000000000") ;
    unsigned long long int const B10 = bitsetB10.to_ullong() ;

    std::bitset<64> const bitsetB5("0000000000000000001001000110011000000000000000000100001000000000") ;
    unsigned long long int const B5 = bitsetB5.to_ullong() ;

    std::bitset<64> const bitsetBm10("0111111010000001100000011000000110000001100000011000000101011010") ;
    unsigned long long int const Bm10 = bitsetBm10.to_ullong() ;

    std::bitset<64> const bitsetBm20("1000000100000000000000000000000000000000000000000000000010000001") ;
    unsigned long long int const Bm20 = bitsetBm20.to_ullong() ;

    std::bitset<64> const bitsetBm40("0000000000000000000000000000000000000000000000000000000000100100") ;
    unsigned long long int const Bm40 = bitsetBm40.to_ullong() ;

    std::bitset<64> const bitsetK30("0000000000000000000000000000000000000000000000000000000001000010") ;
    unsigned long long int const K30 = bitsetK30.to_ullong() ;

    std::bitset<64> const bitsetK20("0000000000000000000000000000000000000000000000001100001110000001") ;
    unsigned long long int const K20 = bitsetK20.to_ullong() ;

    std::bitset<64> const bitsetK10("0000000000000000000000000000000000000000000000000000000000100100") ;
    unsigned long long int const K10 = bitsetK10.to_ullong() ;

    std::bitset<64> const bitsetKm10("0000000000000000000000000000000000000000100000010000000000000000") ;
    unsigned long long int const Km10 = bitsetKm10.to_ullong() ;

    std::bitset<64> const bitsetKm20("0000000000000000000000000000000010000001011111100000000000000000") ;
    unsigned long long int const Km20 = bitsetKm20.to_ullong() ;

    std::bitset<64> const bitsetKm30("1000000110000001100000011000000101100110000000000000000000000000") ;
    unsigned long long int const Km30 = bitsetKm30.to_ullong() ;

    std::bitset<64> const bitsetKm40("0110011001100110011001100110011000011000000000000000000000000000") ;
    unsigned long long int const Km40 = bitsetKm40.to_ullong() ;

    std::bitset<64> const bitsetKm50("0001100000011000000110000001100000000000000000000000000000000000") ;
    unsigned long long int const Km50 = bitsetKm50.to_ullong() ;

    unsigned long long int const p50 (65280) ;
    unsigned long long int const p30 (1572864) ;
    unsigned long long int const p27 (402653184) ;
    unsigned long long int const p25 (103079215104) ;
    unsigned long long int const p20 (2359296);
    unsigned long long int const p10 (28710448241246208) ;
    unsigned long long int const p5 (36452112267214848) ;
    unsigned long long int const pm5 (72567767433216) ;
    unsigned long long int const pm10 (39582418599936) ;
    unsigned long long int const pm25 (6755399441055744) ;

    unsigned long long int const n20 (103481868288) ;
    unsigned long long int const n15 (26543503441920) ;
    unsigned long long int const n10 (39582420959232) ;
    unsigned long long int const n5 (72568874729472) ;
    unsigned long long int const nm20 (2612650733828325888) ;
    unsigned long long int const nm30 (1729524650133749820) ;
    unsigned long long int const nm40 (4792111478498951490) ;
    unsigned long long int const nm50 (9295429630892703873) ;

    unsigned long long int const b10 (28750133526528000) ;
    unsigned long long int const b5 (18577350176538624) ;
    unsigned long long int const bm10 (6521636128632701310) ;
    unsigned long long int const bm20 (9295429630892703873) ;
    unsigned long long int const bm40 (2594073385365405696) ;

    unsigned long long int const k30 (4755801206503243776) ;
    unsigned long long int const k20 (9350317251351281664) ;
    unsigned long long int const k10 (2594073385365405696) ;
    unsigned long long int const km10 (141836999983104) ;
    unsigned long long int const km20 (139092515880960) ;
    unsigned long long int const km30 (440259412353) ;
    unsigned long long int const km40 (104797202022) ;
    unsigned long long int const km50 (404232216) ;





    /*
    const double PawnSqTbW[8][8] = {
        {0,  0,  0,  0,  0,  0,  0,  0},
        {50, 50, 50, 50, 50, 50, 50, 50},
        {10, 10, 20, 30, 30, 20, 10, 10},
        {5,  5, 10, 27, 27, 10,  5,  5},
        {0,  0,  0, 25, 25,  0,  0,  0},
        {5, -5, -10,  0,  0,-10, -5,  5},
        {5, 10, 10,-25,-25, 10, 10,  5},
        {0,  0,  0,  0,  0,  0,  0,  0}
        };

    const double PawnSqTbB[8][8] = {
        {0,  0,  0,  0,  0,  0,  0,  0},
        {5, 10, 10,-25,-25, 10, 10,  5},
        {5, 10, 10,  0,  0,-10, -5,  5},
        {0,  0,  0, 25, 25,  0,  0,  0},
        {5,  5, 10, 27, 27, 10,  5,  5},
        {10, 10, 20, 30, 30, 20, 10, 10},
        {50, 50, 50, 50, 50, 50, 50, 50},
        {0,  0,  0,  0,  0,  0,  0,  0},

    };

    const double KnightSqTbW[8][8] = {
        {-50,-40,-30,-30,-30,-30,-40,-50},
        {-40,-20,  0,  0,  0,  0,-20,-40},
        {-30,  0, 10, 15, 15, 10,  0,-30},
        {-30,  5, 15, 20, 20, 15,  5,-30},
        {-30,  0, 15, 20, 20, 15,  0,-30},
        {-30,  5, 10, 15, 15, 10,  5,-30},
        {-40,-20,  0,  5,  5,  0,-20,-40},
        {-50,-40,-20,-30,-30,-20,-40,-50}
    };

    const double KnightSqTbB[8][8] =
    {
        {-50,-40,-20,-30,-30,-20,-40,-50},
        {-40,-20,  0,  5,  5,  0,-20,-40},
        {-30,  5, 10, 15, 15, 10,  5,-30},
        {-30,  0, 15, 20, 20, 15,  0,-30},
        {-30,  5, 15, 20, 20, 15,  5,-30},
        {-30,  0, 10, 15, 15, 10,  0,-30},
        {-40,-20,  0,  0,  0,  0,-20,-40},
        {-50,-40,-30,-30,-30,-30,-40,-50},
    };

    const double BishopSqTbW[8][8] =
    {
        {-20,-10,-10,-10,-10,-10,-10,-20},
        {-10,  0,  0,  0,  0,  0,  0,-10},
        {-10,  0,  5, 10, 10,  5,  0,-10},
        {-10,  5,  5, 10, 10,  5,  5,-10},
        {-10,  0, 10, 10, 10, 10,  0,-10},
        {-10, 10, 10,  0,  0, 10, 10,-10},
        {-10,  5,  0,  0,  0,  0,  5,-10},
        {-20,-10,-40,-10,-10,-40,-10,-20}
    };

    const double BishopSqTbB[8][8] =
    {
        {-20,-10,-40,-10,-10,-40,-10,-20},
        {-10,  5,  0,  0,  0,  0,  5,-10},
        {-10, 10, 10,-20,-20, 10, 10,-10},
        {-10,  0, 10, 10, 10, 10,  0,-10},
        {-10,  5,  5, 10, 10,  5,  5,-10},
        {-10,  0,  5, 10, 10,  5,  0,-10},
        {-10,  0,  0,  0,  0,  0,  0,-10},
        {-20,-10,-10,-10,-10,-10,-10,-20}


    };

    const double KingSqTbW[8][8] =
    {
      {-30, -40, -40, -50, -50, -40, -40, -30},
      {-30, -40, -40, -50, -50, -40, -40, -30},
      {-30, -40, -40, -50, -50, -40, -40, -30},
      {-30, -40, -40, -50, -50, -40, -40, -30},
      {-20, -30, -30, -40, -40, -30, -30, -20},
      {-10, -20, -20, -20, -20, -20, -20, -10},
       {20,  20,   0,   0,   0,   0,  20,  20},
       {20,  30,  10,   0,   0,  10,  30,  20}
    };

    const double KingSqTbB[8][8] =
    {
    {20,  30,  10,   0,   0,  10,  30,  20},
    {20,  20,   0,   0,   0,   0,  20,  20},
    {-10, -20, -20, -20, -20, -20, -20, -10},
    {-20, -30, -30, -40, -40, -30, -30, -20},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30}
    };

    const double RookSqTbW[8][8] =
    {
    {0,  0,  0,  0,  0,  0,  0,  0},
    {5, 10, 10, 10, 10, 10, 10,  5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {0,  0,  0,  5,  5,  0,  0,  0}
    };

    const double RookSqTbB[8][8] =
    {
    {0,  0,  0,  5,  5,  0,  0,  0},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {5, 10, 10, 10, 10, 10, 10,  5},
    {0,  0,  0,  0,  0,  0,  0,  0}
    };

    const double QueenSqTbW[8][8] =
    {
    {-20,-10,-10, -5, -5,-10,-10,-20},
    {-10,  0,  0,  0,  0,  0,  0,-10},
    {-10,  0,  5,  5,  5,  5,  0,-10},
    { -5,  0,  5,  5,  5,  5,  0, 0},
    { 0,  0,  5,  5,  5,  5,  0, -5},
    {-10,  5,  5,  5,  5,  5,  0,-10},
    {-10,  0,  5,  0,  0,  0,  0,-10},
    {-20,-10,-10, -5, -5,-10,-10,-20}
    };

    const double QueenSqTbB[8][8] =
    {
    {-20,-10,-10, -5, -5,-10,-10,-20},
    {-10,  0,  5,  0,  0,  0,  0,-10},
    {-10,  5,  5,  5,  5,  5,  0,-10},
    {  0,  0,  5,  5,  5,  5,  0, -5},
    {-5,  0,  5,  5,  5,  5,  0, 0},
    {-10,  0,  5,  5,  5,  5,  0,-10},
    {-10,  0,  0,  0,  0,  0,  0,-10},
    {-20,-10,-10, -5, -5,-10,-10,-20}
    };

    */
//}

#endif // CONSTANTS_H
