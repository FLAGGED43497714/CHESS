#ifndef MOVEINSTRUCTIONS_H
#define MOVEINSTRUCTIONS_H
#include <string>

std::pair<int, int> dest_conv(std::string nextDest);

std::pair<int, int> findPiece(std::string nextPiece, std::string aBoard[8][8]);

#endif // MOVEINSTRUCTIONS_H
