#ifndef UPDATEBOARD_H
#define UPDATEBOARD_H

#include <string>


void updateBoard1(std::string nextPiece,std::string nextDest,std::string aBoard[8][8]);

void updateBoard2(std::string nextPiece, int line_index, int col_index, std::string aBoard[8][8]);

void undoMove(std::string nextPiece, int line_index, int col_index, std::string instead, std::string aBoard[8][8]);


#endif // UPDATEBOARD_H
