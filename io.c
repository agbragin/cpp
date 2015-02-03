#include <stdio.h>

main() {
    
    printf("EOF: %d\n", EOF);
    
    int c;
    int symbols = 0;
    int lines = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\n') {
            printf("\\n\n");
        } else {
            putchar(c);
        }
        if (c == '\n') {
            lines++;
        }
        symbols++;  
    }
    printf("Lines read: %d\n", lines);
    printf("Symbols read: %d\n", symbols);
    
    int a;
    //Note that there are no compile-time warnings
    if (a = 0) {
        printf("if\n");
    } else {
        printf("else\n");
    }
}
