
#include "math.h"
#include "fixed.h"

short sin(short x) {
    asm("finit\n"       // initialize FPU
        "");
}

short cos(short x) {
    //
}