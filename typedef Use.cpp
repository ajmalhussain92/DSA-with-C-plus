#include <stdio.h>

typedef float Temperature;

int main() {
	Temperature today = 25.5;
	Temperature tomorrow = 18.6;
	
	printf("Today: %.1f C\n", today);
	printf("Tomorrow: %.1f C\n", tomorrow);

  	return 0;
} 