#include "BitwiseFunction.h"
#include <bitset>
#include <iostream>
#include <string>

#include "coutBoard.h"

unsigned long long int rZobTable[8][8] ;
unsigned long long int nZobTable[8][8] ;
unsigned long long int bZobTable[8][8] ;
unsigned long long int qZobTable[8][8] ;
unsigned long long int kZobTable[8][8] ;
unsigned long long int pZobTable[8][8] ;

unsigned long long int RZobTable[8][8] ;
unsigned long long int NZobTable[8][8] ;
unsigned long long int BZobTable[8][8] ;
unsigned long long int QZobTable[8][8] ;
unsigned long long int KZobTable[8][8] ;
unsigned long long int PZobTable[8][8] ;

unsigned long long int EnPassantZobTable[8][8] ;

/*unsigned long long int rZobTable2[8][8] ;
unsigned long long int nZobTable2[8][8] ;
unsigned long long int bZobTable2[8][8] ;
unsigned long long int qZobTable2[8][8] ;
unsigned long long int kZobTable2[8][8] ;
unsigned long long int pZobTable2[8][8] ;

unsigned long long int RZobTable2[8][8] ;
unsigned long long int NZobTable2[8][8] ;
unsigned long long int BZobTable2[8][8] ;
unsigned long long int QZobTable2[8][8] ;
unsigned long long int KZobTable2[8][8] ;
unsigned long long int PZobTable2[8][8] ;*/

/*
unsigned long long int rZobTable3[8][8] ;
unsigned long long int nZobTable3[8][8] ;
unsigned long long int bZobTable3[8][8] ;
unsigned long long int qZobTable3[8][8] ;
unsigned long long int kZobTable3[8][8] ;
unsigned long long int pZobTable3[8][8] ;

unsigned long long int RZobTable3[8][8] ;
unsigned long long int NZobTable3[8][8] ;
unsigned long long int BZobTable3[8][8] ;
unsigned long long int QZobTable3[8][8] ;
unsigned long long int KZobTable3[8][8] ;
unsigned long long int PZobTable3[8][8] ;*/

void initZob(unsigned long long int rZobTable[8][8],unsigned long long int nZobTable[8][8],unsigned long long int bZobTable[8][8],
             unsigned long long int qZobTable[8][8],unsigned long long int kZobTable[8][8],unsigned long long int pZobTable[8][8],
             unsigned long long int RZobTable[8][8],unsigned long long int NZobTable[8][8],unsigned long long int BZobTable[8][8],
             unsigned long long int QZobTable[8][8],unsigned long long int KZobTable[8][8],unsigned long long int PZobTable[8][8]/*,
             unsigned long long int rZobTable2[8][8],unsigned long long int nZobTable2[8][8],unsigned long long int bZobTable2[8][8],
             unsigned long long int qZobTable2[8][8],unsigned long long int kZobTable2[8][8],unsigned long long int pZobTable2[8][8],
             unsigned long long int RZobTable2[8][8],unsigned long long int NZobTable2[8][8],unsigned long long int BZobTable2[8][8],
             unsigned long long int QZobTable2[8][8],unsigned long long int KZobTable2[8][8],unsigned long long int PZobTable2[8][8]*/){


    std::string nothing ;
    unsigned long long int r30 ;
    unsigned long long int s30 ;
    unsigned long long int t4 ;

    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            rZobTable[line][col] = (s30 << 32) + r30 ;
            //coutBitSet(rZobTable[line][col]) ;
            //std::cin>>nothing;
        }
    }

    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            nZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }

    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            bZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }

    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            qZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            kZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;


            pZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            RZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;


            NZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;


            BZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;


            QZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;


            KZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            PZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }

    /*for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            EnPassantZobTable[line][col] = (s30 << 32) + r30 ;
        }
    }*/
    /*for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            rZobTable2[line][col] = (s30 << 32) + r30 ;
            //coutBitSet(rZobTable[line][col]) ;
            //std::cin>>nothing;
        }
    }

    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            nZobTable2[line][col] = (s30 << 32) + r30 ;
        }
    }

    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            bZobTable2[line][col] = (s30 << 32) + r30 ;
        }
    }

    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            qZobTable2[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            kZobTable2[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;


            pZobTable2[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            RZobTable2[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;


            NZobTable2[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;


            BZobTable2[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;


            QZobTable2[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;


            KZobTable2[line][col] = (s30 << 32) + r30 ;
        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;

            PZobTable2[line][col] = (s30 << 32) + r30 ;
        }
    }*/



    /*for (int ind = 0 ; ind < 64 ; ind ++){

        /*std::cout << rZobTable[ind/8][ind%8] << std::endl;
        std::cout << nZobTable[ind/8][ind%8] << std::endl;
        std::cout << bZobTable[ind/8][ind%8] << std::endl;
        std::cout << qZobTable[ind/8][ind%8] << std::endl;
        std::cout << kZobTable[ind/8][ind%8] << std::endl;
        std::cout << pZobTable[ind/8][ind%8] << std::endl;
        std::cout << RZobTable[ind/8][ind%8] << std::endl;
        std::cout << NZobTable[ind/8][ind%8] << std::endl;
        std::cout << BZobTable[ind/8][ind%8] << std::endl;
        std::cout << QZobTable[ind/8][ind%8] << std::endl;
        std::cout << KZobTable[ind/8][ind%8] << std::endl;
        std::cout << PZobTable[ind/8][ind%8] << std::endl;*/
        /*coutBitSet(rZobTable[ind/8][ind%8]) ;
        std::cin >> nothing ;
        coutBitSet(nZobTable[ind/8][ind%8]) ;
        std::cin >> nothing ;
        coutBitSet(bZobTable[ind/8][ind%8]) ;
        std::cin >> nothing ;
        coutBitSet(qZobTable[ind/8][ind%8]) ;
        std::cin >> nothing ;
        coutBitSet(kZobTable[ind/8][ind%8]) ;
        std::cin >> nothing ;
        coutBitSet(pZobTable[ind/8][ind%8]) ;
        std::cin >> nothing ;
        coutBitSet(RZobTable[ind/8][ind%8]) ;
        std::cin >> nothing ;
        coutBitSet(NZobTable[ind/8][ind%8]) ;
        std::cin >> nothing ;
        coutBitSet(BZobTable[ind/8][ind%8]) ;
        std::cin >> nothing ;
        coutBitSet(QZobTable[ind/8][ind%8]) ;
        std::cin >> nothing ;
        coutBitSet(KZobTable[ind/8][ind%8]) ;std::cin >> nothing ;
        coutBitSet(PZobTable[ind/8][ind%8]) ;std::cin >> nothing ;
    }
    std::cin >> nothing ;*/



}

unsigned long long int ZobristHash(unsigned long long int r,unsigned long long int n,unsigned long long int b,unsigned long long int q,
                unsigned long long int k,unsigned long long int p,unsigned long long int R,unsigned long long int N,
                unsigned long long int B,unsigned long long int Q,unsigned long long int K,unsigned long long int P,
                bool CstlL, bool CstlS , bool cstlL , bool cstlS, bool maximizingPlayer)
       {//, unsigned long long int previousZobristHash)

            unsigned long long int hashRes = 0 ;



            for(int ind = 0 ; ind < 64 ; ind ++){

                if(P>>ind&1){
                    hashRes ^= PZobTable[ind/8][ind%8] ;
                }
                else if(p>>ind&1){
                    hashRes ^= pZobTable[ind/8][ind%8] ;
                }
                else if(r>>ind&1){
                    hashRes ^= rZobTable[ind/8][ind%8] ;
                }
                else if(R>>ind&1){
                    hashRes ^= RZobTable[ind/8][ind%8] ;
                }
                else if(n>>ind&1){
                    hashRes ^= nZobTable[ind/8][ind%8] ;
                }
                else if(N>>ind&1){
                    hashRes ^= NZobTable[ind/8][ind%8] ;
                }
                else if(b>>ind&1){
                    hashRes ^= bZobTable[ind/8][ind%8] ;
                }
                else if(B>>ind&1){
                    hashRes ^= BZobTable[ind/8][ind%8] ;
                }
                else if(k>>ind&1){
                    hashRes ^= kZobTable[ind/8][ind%8] ;
                }
                else if(K>>ind&1){
                    hashRes ^= KZobTable[ind/8][ind%8] ;
                }
                else if(q>>ind&1){
                    hashRes ^= qZobTable[ind/8][ind%8] ;
                }
                else if(Q>>ind&1){
                    hashRes ^= QZobTable[ind/8][ind%8] ;
                }
            }


            if (maximizingPlayer){
                hashRes ^= 891517893554500602 ;
            }
            if (CstlS){
                hashRes ^= 1615461785985833611 ;
            }
            if (CstlL){
                hashRes ^= 803003761016756798 ;
            }
            if (cstlS){
                hashRes ^= 1401845436929994442 ;
            }
            if (cstlL){
                hashRes ^= 673442472024400627 ;
            }

        return hashRes ;


       }




unsigned long long int reverseULL(unsigned long long int b) {
    b = (b & 0xFFFFFFFF00000000) >> 32 | (b & 0x00000000FFFFFFFF) << 32 ;
    b = (b & 0xFFFF0000FFFF0000) >> 16 | (b & 0x0000FFFF0000FFFF) << 16 ;
    b = (b & 0xFF00FF00FF00FF00) >> 8  | (b & 0x00FF00FF00FF00FF) << 8 ;
    b = (b & 0xF0F0F0F0F0F0F0F0) >> 4  | (b & 0x0F0F0F0F0F0F0F0F) << 4 ;
    b = (b & 0xCCCCCCCCCCCCCCCC) >> 2  | (b & 0x3333333333333333) << 2 ;
    b = (b & 0xAAAAAAAAAAAAAAAA) >> 1  | (b & 0x5555555555555555) << 1 ;

    return b ;
}

unsigned int countSetBits1(unsigned long long int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

unsigned int countSetBits2(unsigned long long int n)
{
    std::bitset<64> nBit (n) ;
    unsigned int count = nBit.count() ;
    return count ;
}
