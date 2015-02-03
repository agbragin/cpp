#include <stdio.h>

#define LOWER -20
#define UPPER 40
#define STEP 1

main()
{	
	float celsius = LOWER;
	float fahrenheit;
	
	printf("Celsius to Fahr conversion\n");
	
	while (celsius <= UPPER) {
	    fahrenheit = (celsius * 1.8) + 32;
	    printf("%6.1f%6.1f\n", celsius, fahrenheit);
	    celsius += STEP;
	}
	
	int a;
	for (a = 0; a <= 10; a++) {
	    printf("%5d\n", a);
	}
	
}
