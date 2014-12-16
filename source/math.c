
#include "math.h"

/*
    Artificially cast a number with separate whole and decimal parts to a fixed type
    
    @param
        whole - whole number, no larger than 999 and no smaller than -999, can be signed or unsigned
        decimal - two-place decimal segment, no larger than 99, no smaller than 0
    
    @return
        number of the type 'fixed', signed or unsigned
*/
fixed getFixed(short whole, char decimal) {
    return whole * 100 + decimal;
}

/*
    Extract the whole number portion of a fixed-type variable
    
    @param
        x - fixed-type variable to extract from
    
    @return
        whole number portion
*/
short getWhole(fixed x) {
    return x / 100;
}

/*
    Extract the decimal portion of a fixed-type variable
    
    @param
        x - fixed-type variable to extract from
    
    @return
        decimal number portion
*/
char getDecimal(fixed x) {
    return x % 100;
}

short sin(short x) {
    asm("finit\n"       // initialize FPU
        "");
}

short cos(short x) {
    //
}