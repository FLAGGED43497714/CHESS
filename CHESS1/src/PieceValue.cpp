#include "PieceValue.h"

int getPieceValue(char label){
    switch (label)
    {

    case 'Q' :
        return 900 ;
        break ;

    case 'R' :
        return 500 ;
        break ;

    case 'B' :
        return 300 ;
        break ;

    case 'N' :
        return 300 ;
        break ;

    case 'P' :
        return 100 ;
        break ;

    case 'K' :
        return 2000 ;
        break ;
    }
}


