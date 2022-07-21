#ifndef CHECK_H
#define CHECK_H

#include <string>
#include <iostream>
#include <vector>

bool IsCheck(std::string aBoard[8][8], int moveNb);

bool MoveChecksAllyKing(std::string aBoard[8][8], int moveNb, std::string thePiece, std::pair<int, int> theDest);

bool IsCheck2(std::string aBoard[8][8], int moveNb, std::vector<std::pair<std::string, std::pair<int, int>>> legalOppMoves);

#endif // CHECK_H
