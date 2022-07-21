#ifndef KNIGHTLEGAL_H
#define KNIGHTLEGAL_H
#include <string>
#include <vector>


void legalKnight(std::string currentPiece,std::pair<int,int> locCurrentPiece,
               std::vector<std::pair<std::string, std::pair<int, int>>>& legalMoves,std::string aBoard[8][8],
               char colorAlly, char colorEnnemy, int moveNb);

void legalKnight2(std::string currentPiece,std::pair<int,int> locCurrentPiece,
               std::vector<std::pair<std::string, std::pair<int, int>>>& legalMoves,std::string aBoard[8][8],
               char colorAlly, char colorEnnemy);

#endif // KNIGHTLEGAL_H
