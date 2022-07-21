#ifndef INITBOARD_H
#define INITBOARD_H

#include <bitset>
#include <string>

void initBoard(std::bitset<64> board[12]);

void initBoard2(unsigned long long int& r,unsigned long long int& n,unsigned long long int& b,unsigned long long int& q,
                unsigned long long int& k,unsigned long long int& p,
                unsigned long long int& R,unsigned long long int& N,unsigned long long int& B,unsigned long long int& Q,
                unsigned long long int& K,unsigned long long int& P);

void initFromFEN(std::string fen, unsigned long long int& r,unsigned long long int& n,unsigned long long int& b,unsigned long long int& q,
                unsigned long long int& k,unsigned long long int& p,
                unsigned long long int& R,unsigned long long int& N,unsigned long long int& B,unsigned long long int& Q,
                unsigned long long int& K,unsigned long long int& P);

#endif // INITBOARD_H
