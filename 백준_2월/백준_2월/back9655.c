// ������.

#include <stdio.h>

int main(void)
{
	int rock;
	int turn = 1; // 1 = ���. 2 = â��

	scanf_s("%d", &rock);

	while (0 < rock) {
		if (rock >= 3) { //����� ����
			rock -= 3;
			turn = 2;
		}
		else if (1 <= rock) {
			rock -= 1;
			turn = 2;
		}
		if (rock >= 3) { //â���� ����
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