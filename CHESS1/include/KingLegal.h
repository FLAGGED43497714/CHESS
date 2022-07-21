#ifndef KINGLEGAL_H
#define KINGLEGAL_H

#include <string>
#include <vector>


void legalKing(std::string currentPiece,std::pair<int,int> locCurrentPiece,
               std::vector<std::pair<std::string, std::pair<int, int>>>& legalMoves,std::string aBoard[8][8],
               char colorAlly, char colorEnnemy, int moveNb, bool wC1, bool wC2, bool bC1, bool bC2);

void legalKing2(std::string currentPiece,std::pair<int,int> locCurrentPiece,
               std::vector<std::pair<std::string, std::pair<int, int>>>& legalMoves,std::string aBoard[8][8],
               char colorAlly, char colorEnnemy);


#endif // KINGLEGAL_H
