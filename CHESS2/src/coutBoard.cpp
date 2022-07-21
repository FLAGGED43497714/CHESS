#include "coutBoard.h"

#include <bitset>
#include <iostream>

void coutBoard(std::bitset<64> r, std::bitset<64> n, std::bitset<64> b, std::bitset<64> q, std::bitset<64> k, std::bitset<64> p,
          std::bitset<64> R, std::bitset<64> N, std::bitset<64> B, std::bitset<64> Q, std::bitset<64> K, std::bitset<64> P)
{
    for (int i = 63 ; i >= 0 ; i--){
        if(r[i]){
            std::cout << "r" ;
        } else {
            if(b[i]){
            std::cout << "b" ;
        } else {
            if(n[i]){
            std::cout << "n" ;
        } else {
            if(q[i]){
            std::cout << "q" ;
        } else {
            if(k[i]){
            std::cout << "k" ;
        } else {
            if(p[i]){
            std::cout << "p" ;
        } else {


            if(R[i]){
            std::cout << "R" ;
        } else {
            if(B[i]){
            std::cout << "B" ;
        } else {
            if(N[i]){
            std::cout << "N" ;
        } else {
            if(Q[i]){
            std::cout << "Q" ;
        } else {
            if(K[i]){
            std::cout << "K" ;
        } else {
            if(P[i]){
            std::cout << "P" ;

        }else {
            std::cout << "*" ;

        }}}}}}}}}}}}

        if (i%8 == 0){
            std::cout << "\n" ;
            std::cout << "\n" ;
            std::cout << "\n" ;
        } else {
            std::cout << "\t" ;
        }
    }
    std::cout << "\n" ;
}


void coutBitSet(std::bitset<64> b)
{
    for (int i = 63 ; i >= 0 ; i--){
        if(b[i]){
            std::cout << "1" ;

        }else {
            std::cout << "0" ;

        }

        if (i%8 == 0){
            std::cout << "\n" ;
            std::cout << "\n" ;
            std::cout << "\n" ;
        } else {
            std::cout << "\t" ;
        }
    }
    std::cout << "\n" ;
    std::cout << "\n" ;
}
