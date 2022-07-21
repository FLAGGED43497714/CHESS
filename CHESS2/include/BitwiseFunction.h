#ifndef BITWISEFUNCTION_H
#define BITWISEFUNCTION_H

#include <vector>

void initZob(unsigned long long int rZobTable[8][8],unsigned long long int nZobTable[8][8],unsigned long long int bZobTable[8][8],
             unsigned long long int qZobTable[8][8],unsigned long long int kZobTable[8][8],unsigned long long int pZobTable[8][8],
             unsigned long long int RZobTable[8][8],unsigned long long int NZobTable[8][8],unsigned long long int BZobTable[8][8],
             unsigned long long int QZobTable[8][8],unsigned long long int KZobTable[8][8],unsigned long long int PZobTable[8][8]);

unsigned long long int ZobristHash(unsigned long long int r,unsigned long long int n,unsigned long long int b,unsigned long long int q,
                unsigned long long int k,unsigned long long int p,unsigned long long int R,unsigned long long int N,
                unsigned long long int B,unsigned long long int Q,unsigned long long int K,unsigned long long int P,
                bool CstlL, bool CstlS , bool cstlL , bool cstlS, bool maximizingPlayer);


unsigned long long int reverseULL(unsigned long long int b);

unsigned int countSetBits1(unsigned long long int n);

unsigned int countSetBits2(unsigned long long int n);

#endif // BITWISEFUNCTION_H
