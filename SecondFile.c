#include <stdio.h>

int func() {
    int A = 3;
    int B = 4;
    A = A << 3;
    B = B >> 5;
    int C = A | B;
    C = C >> 2;
    printf(C);
return 0;
}

