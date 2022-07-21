#include "SqNameToNb.h"


#include <iostream>
#include <string>

int SquareNameToNb(std::string SquareName){
    int result (0) ;

    char charNb = SquareName[1] ;

    int nb = charNb - '0' ;

    result += (nb-1) * 8 ;

    switch (SquareName[0]) {
    case 'a' :
        result += 7 ;
        break  ;

    case 'b' :
        result += 6 ;
        break  ;

    case 'c' :
        result += 5 ;
        break  ;

    case 'd' :
        result += 4 ;
        break  ;

    case 'e' :
        result += 3 ;
        break  ;

    case 'f' :
        result += 2 ;
        break  ;

    case 'g' :
        result += 1 ;
        break  ;

    case 'h' :
        break  ;
    }

    return result ;
}
