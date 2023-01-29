#include <stdio.h>

int a, b;
void print()
{
	printf("a = %d, b = %d\n", a, b);
}

void q()
{
	int b = 3; print();
}

int p(int b)
{
	int a = 1, c = b - 1;

	q();
	return c;
}

int main(void)
{
	a = p(3); b = 2;

	print();

	p(4);

	int a = 5;
	int* p = &a;

	printf("%d\n", *p);
}
