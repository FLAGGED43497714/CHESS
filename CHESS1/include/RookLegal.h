#ifndef ROOKLEGAL_H
#define ROOKLEGAL_H

#include <string>
#include <vector>

void legalRook(std::string currentPiece,std::pair<int,int> locCurrentPiece,
               std::vector<std::pair<std::string, std::pair<int, int>>>& legalMoves,std::string aBoard[8][8],
               char colorAlly, char colorEnnemy, int moveNb);

void legalRook2(std::string currentPiece,std::pair<int,int> locCurrentPiece,
               std::vector<std::pair<std::string, std::pair<int, int>>>& legalMoves,std::string aBoard[8][8],
               char colorAlly, char colorEnnemy);


#endif // ROOKLEGAL_H
