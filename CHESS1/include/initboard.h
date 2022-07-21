#ifndef INITBOARD_H
#define INITBOARD_H

#include<string>

typedef std::string (*pointer_to_arrays)[8];

void initBoard(std::string aBoard[8][8]);

void initSpeBoard(std::string aBoard[8][8]);

void initFenBoard(std::string aBoard[8][8],std::string aFen);

#endif // INITBOARD_H
