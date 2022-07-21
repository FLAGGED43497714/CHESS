#ifndef PAWNLEGAL_H
#define PAWNLEGAL_H

#include <string>
#include <vector>
#include <iostream>

void legalPawn(std::string currentPiece,std::pair<int,int> locCurrentPiece,
               std::vector<std::pair<std::string, std::pair<int, int>>>& legalMoves,std::string aBoard[8][8],
               char colorAlly, char colorEnnemy, int moveNb);

void legalPawn2(std::string currentPiece,std::pair<int,int> locCurrentPiece,
               std::vector<std::pair<std::string, std::pair<int, int>>>& legalMoves,std::string aBoard[8][8],
               char colorAlly, char colorEnnemy);

#endif // PAWNLEGAL_H
