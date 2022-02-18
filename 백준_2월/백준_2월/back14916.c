#include <stdio.h>

int main(void)
{
	int change;
	int n_coin = 0;

	scanf_s("%d", &change);

	int coins[] = { -1,-1,1,-1,2,1,3,2,4,3,2,4,3,5 };

	if (change <= 13) {
		printf("%d", coins[change]);
		return 0;
	}

	int temp1, temp2;
	temp1 = 5 * (change / 5);
	while (1) {
		temp2 = change - temp1;
		if (coins[temp2] != -1) {
			n_coin = (temp1 / 5) + coins[temp2];
			break;
		}
		else {
			temp1 -= 5;
		}
	}

	printf("%d", n_coin);
}