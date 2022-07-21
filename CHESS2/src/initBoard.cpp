#include "initBoard.h"

#include <vector>
#include <bitset>
#include <string>
#include <iostream>

void initFromFEN(std::string fen, unsigned long long int& r,unsigned long long int& n,unsigned long long int& b,unsigned long long int& q,
                unsigned long long int& k,unsigned long long int& p,
                unsigned long long int& R,unsigned long long int& N,unsigned long long int& B,unsigned long long int& Q,
                unsigned long long int& K,unsigned long long int& P)
{

    std::string r1String ("0000000000000000000000000000000000000000000000000000000000000000");
    std::string n1String ("0000000000000000000000000000000000000000000000000000000000000000");
    std::string b1String ("0000000000000000000000000000000000000000000000000000000000000000");
    std::string q1String ("0000000000000000000000000000000000000000000000000000000000000000");
    std::string k1String ("0000000000000000000000000000000000000000000000000000000000000000");
    std::string p1String ("0000000000000000000000000000000000000000000000000000000000000000");
    std::string R1String ("0000000000000000000000000000000000000000000000000000000000000000");
    std::string N1String ("0000000000000000000000000000000000000000000000000000000000000000");
    std::string B1String ("0000000000000000000000000000000000000000000000000000000000000000");
    std::string Q1String ("0000000000000000000000000000000000000000000000000000000000000000");
    std::string K1String ("0000000000000000000000000000000000000000000000000000000000000000");
    std::string P1String ("0000000000000000000000000000000000000000000000000000000000000000");

    int i = 0 ;
    for (int k = 0 ; k < fen.size() ; k++){
        //std::cout << fen[k] ;
        switch(fen[k]){
            case 'r' :
                r1String[i] = '1' ;
                break ;
            case 'n' :
                n1String[i] = '1' ;
                break ;
            case 'b' :
                b1String[i] = '1' ;
                break ;
            case 'q' :
                q1String[i] = '1' ;
                break ;
            case 'k' :
                k1String[i] = '1' ;
                break ;
            case 'p' :
                p1String[i] = '1' ;
                break ;

            case 'R' :
                R1String[i] = '1' ;
                break ;
            case 'N' :
                N1String[i] = '1' ;
                break ;
            case 'B' :
                B1String[i] = '1' ;
                break ;
            case 'Q' :
                Q1String[i] = '1' ;
                break ;
            case 'K' :
                K1String[i] = '1' ;
                break ;
            case 'P' :
                P1String[i] = '1' ;
                break ;

            case '/' :
                i -= 1 ; // pour ignorer parce qu'on va faire +1 à la fin du switch
                break;
            case '1' :
                i+=0;
                break;
            case '2' :
                i+=1;
                break;
            case '3' :
                i+=2;
                break;
            case '4' :
                i+=3;
                break;
            case '5' :
                i+=4;
                break;
            case '6' :
                i+=5;
                break;
            case '7' :
                i+=6;
                break;
            case '8' :
                i+=7;
                break;
        }
        i+=1 ;
    }


    //std::cout << r1String<< std::endl;
    //std::cout << n1String.size() << std::endl;
    //std::cout << b1String.size() << std::endl;
    //std::cout << q1String.size()<< std::endl ;
    //std::cout << k1String.size() << std::endl;
    //std::cout << p1String << std::endl;
    //std::cout << R1String.size() << std::endl;
    //std::cout << N1String.size() << std::endl;
    //std::cout << B1String.size() << std::endl;
    //std::cout << Q1String.size() << std::endl;
    //std::cout << K1String.size() << std::endl;
    //std::cout << P1String << std::endl;




    std::bitset<64> r1(r1String);
    std::bitset<64> n1(n1String);
    std::bitset<64> b1(b1String);
    std::bitset<64> q1(q1String);
    std::bitset<64> k1(k1String);
    std::bitset<64> p1(p1String);
    std::bitset<64> R1(R1String);
    std::bitset<64> N1(N1String);
    std::bitset<64> B1(B1String);
    std::bitset<64> Q1(Q1String);
    std::bitset<64> K1(K1String);
    std::bitset<64> P1(P1String);

    r = r1.to_ullong();
    n = n1.to_ullong();
    b = b1.to_ullong();
    q = q1.to_ullong();
    k = k1.to_ullong();
    p = p1.to_ullong();
    R = R1.to_ullong();
    N = N1.to_ullong();
    B = B1.to_ullong();
    Q = Q1.to_ullong();
    K = K1.to_ullong();
    P = P1.to_ullong();

}
