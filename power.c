#include <stdio.h>

int mypow(int x, int y) {
    int i;
    int pow = 1;
    
    if (y < 0) {
        printf("ERROR");
    }
    
    for (i = 0; i < y; i++) {
        pow *= x;
    }
    
    return pow;
}

main() {
    printf("%d\n", mypow(2, 0));
    return 0;
}
