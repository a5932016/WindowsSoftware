#include <stdio.h>

void Fun1();
void Fun2();
void Fun3();

int main()
{
	printf("Hello PE\n");

	Fun1();
	Fun2();
	Fun3();

	return 0;
}

void Fun1()
{
	printf("This is Fun1\n");
}

void Fun2()
{
	printf("This is Fun2\n");
}

void Fun3()
{
	printf("This is Fun3\n");
}