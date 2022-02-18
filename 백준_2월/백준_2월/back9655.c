// 돌게임.

#include <stdio.h>

int main(void)
{
	int rock;
	int turn = 1; // 1 = 상근. 2 = 창영

	scanf_s("%d", &rock);

	while (0 < rock) {
		if (rock >= 3) { //상근의 차례
			rock -= 3;
			turn = 2;
		}
		else if (1 <= rock) {
			rock -= 1;
			turn = 2;
		}
		if (rock >= 3) { //창영의 차례
			rock -= 3;
			turn = 1;
		}
		else if (1 <= rock) {
			rock -= 1;
			turn = 1;
		}
	}

	if (turn == 1) {
		printf("CY");
	}
	else if (turn == 2) {
		printf("SK");
	}
}