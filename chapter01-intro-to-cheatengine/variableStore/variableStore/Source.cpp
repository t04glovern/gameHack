#include <stdio.h>
#include <conio.h>

void main()
{
	int a, b, c;

	while (true) {

		printf("\nEnter any two number: \n");
		scanf("%d%d", &a, &b);

		c = a + b;

		printf("\nSum is: %d", c);
		getch();
	}
}