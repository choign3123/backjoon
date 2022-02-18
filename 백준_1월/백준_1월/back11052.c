#include <stdio.h>

int main(void) 
{
	int card[1001] = { 0 };
	int num = 0;

	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf_s("%d", &card[i]);
	}

	int cost, max_cost;
	for (int i = 1; i <= num; i++) {
		max_cost = card[i];
		for (int j = 1; j <= i / 2; j++) {
			cost = card[i - j] + card[j];
			if (max_cost < cost) {
				max_cost = cost;
			}
		}
		card[i] = max_cost;
	}

	printf("%d", card[num]);
}