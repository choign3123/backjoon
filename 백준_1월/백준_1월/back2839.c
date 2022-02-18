#include <stdio.h>

#define THREE 3
#define FIVE 5

int main(void)
{
	int sugar;
	int num = 0;

	scanf_s("%d", &sugar);

	int temp_sugar;
	for (int i = sugar/FIVE; i >= 0; i--) {
		temp_sugar = sugar;
		num = 0;

		num += i;
		temp_sugar -= i * FIVE;
		num += temp_sugar / THREE;
		temp_sugar -= (temp_sugar / THREE) * THREE;

		if (temp_sugar == 0) {
			printf("%d", num);
			return 0;
		}
	}

	printf("-1");

}
//음. 그냥 5로 나눴을 때 떨어지면 5*몫만큼 다 빼고,
//나눠 떨어지지 않는데, 3으로 나눠떨어지면 3 한번 빼보고 다시 5빼고
//반복할걸.

main() { 
	int a = 0, i; 
	scanf("%d", &i); 
	while (1) { 
		if (i < 0) { 
			printf("-1"); break; 
		} 
		else { 
			if (i % 5 == 0) { 
				printf("%d", i / 5 + a); break; 
			} 
			else { 
				a++; i -= 3; 
			} 
		} 
	} 
}