#ifndef LEGAL_H
#define LEGAL_H

#include <string>
#include <vector>

bool IsLegal(std::string nextPiece, std::string nextDest, std::string aBoard[8][8], int moveNb,
             bool wC1, bool wC2, bool bC1, bool bC2);

std::vector<std::pair<std::string, std::pair<int, int>>> LegalMoves(std::string aBoard[8][8], int moveNb,
                                                                    bool wC1= false, bool wC2= false,
                                                                    bool bC1= false, bool bC2= false);

std::vector<std::pair<std::string, std::pair<int, int>>> unSortedLegalMoves(std::string aBoard[8][8], int moveNb,
                                                                            bool wC1= false, bool wC2= false,
                                                                            bool bC1= false, bool bC2= false);

std::vector<std::pair<std::string, std::pair<int, int>>> RawLegalMoves(std::string aBoard[8][8], int moveNb);

#endif // LEGAL_H
