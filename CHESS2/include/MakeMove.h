#ifndef MAKEMOVE_H
#define MAKEMOVE_H

#include <vector>


void Do_move(int pos, int dest, bool & CstlL, bool & CstlS, bool & cstlL, bool & cstlS,
        bool & brokeCastleS, bool & brokeCastleL, bool & brokecastleS, bool & brokecastleL,
        unsigned long long int & r,unsigned long long int & n,unsigned long long int & b,
        unsigned long long int & q,unsigned long long int & k,unsigned long long int & p,unsigned long long int & R,
        unsigned long long int & N,unsigned long long int & B,unsigned long long int & Q,unsigned long long int & K,
        unsigned long long int & P,unsigned long long int & enPassant, unsigned long long int & forbCstlS,
        unsigned long long int & forbCstlL, unsigned long long int & forbcstlS, unsigned long long int & forbcstlL,
        bool & wasCastle, bool & wasPromote, int & pieceCaptured, unsigned long long int & positionHash);


void Undo_move(int wasPos, int wasDest, bool brokeCastleS, bool brokeCastleL, bool brokecastleS, bool brokecastleL,
        bool wasCastle, bool wasPromote, int pieceCaptured, bool & CstlL, bool & CstlS, bool & cstlL, bool & cstlS,
        unsigned long long int & r,unsigned long long int & n,unsigned long long int & b,
        unsigned long long int & q,unsigned long long int & k,unsigned long long int & p,
        unsigned long long int & R,unsigned long long int & N,unsigned long long int & B,
        unsigned long long int & Q,unsigned long long int & K,unsigned long long int & P, unsigned long long int & positionHash);


void isEnPassant(std::pair<int,int>& lastMove, unsigned long long int & enPassant, unsigned long long int & P,
                 bool whiteJstPlayed);

#endif // MAKEMOVE_H
