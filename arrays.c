#include <stdio.h>

main() {
    int digits[10];
    int i;
    for (i = 0; i <= 10; i++) {
        digits[i] = 0;
    } 
    
    char c;
    while ((c = getchar()) != EOF) {
        if (c >= '0' || c <= '9') {
            digits[c - '0']++;
        }
    }
    
    printf("Digits histogram\n");
    
    int sum;
    for (i = 0; i < 10; i++) {
        printf("%d\t", i);
        int j;
        for (j = 0; j < digits[i]; j++) {
            putchar('*');
            sum++;
        }
        putchar('\n');
    }
    
    printf("Digit frequencies\n");
    
    float freq;
    for (i = 0; i < 10; i++) {
        freq = (1.0 * digits[i]) / sum;
        //printf("%d\t%.3f\n", i, freq);
        
        printf("%d\t", i);
        int relfreq = (int) (100 * freq);
        int j;
        for (j = 0; j < relfreq; j++) {
            putchar('*');
        }
        putchar('\n');
    }

}
