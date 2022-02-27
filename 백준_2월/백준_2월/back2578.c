#include <stdio.h>

int map[5][5];
int bingo[5][5];
int cnt_bingo, cnt_n;

int find_bingo(int x, int y) //���� �Ǵ��� Ȯ��.
{
	int xx, yy;

	// ����
	for (int i = 1; i < 5; i++) {
		yy = (y + i) % 5;
		if (bingo[x][yy] != 1) {
			break;
		}
		else if (i == 4) {
			cnt_bingo++;
		}
	}
	if (cnt_bingo == 3) {
		return 1;
	}

	// ����
	for (int i = 1; i < 5; i++) {
		xx = (x + i) % 5;
		if (bingo[xx][y] != 1) {
			break;
		}
		else if (i == 4) {
			cnt_bingo++;
		}
	}
	if (cnt_bingo == 3) {
		return 1;
	}

	//�밢��1
	if (x == y) {
		//for (int i = 1; i < 5; i++) {
		//	xx = (x + i) % 5;
		//	yy = (y + i) % 5;
		//	if (bingo[xx][yy] != 1 || xx < 0 || 5 <= xx || yy < 0 || 5 <= yy) {
		//		break;
		//	}
		//	else if (i == 4) {
		//		cnt_bingo++;
		//	}
		//}
		if (bingo[0][0] && bingo[1][1] && bingo[2][2] && bingo[3][3] && bingo[4][4]) {
			cnt_bingo++;
		}
		if (cnt_bingo == 3) {
			return 1;
		}
	}

	//�밢��2 (/)
	if (x + y == 4) {
		//for (int i = 1; i < 5; i++) {
		//	xx = (x + i) % 5;
		//	yy = (y - i + 5) % 5;
		//	if (bingo[xx][yy] != 1 || xx < 0 || 5 <= xx || yy < 0 || 5 <= yy) {
		//		break;
		//	}
		//	else if (i == 4) {
		//		cnt_bingo++;
		//	}
		//}
		if (bingo[0][4] && bingo[1][3] && bingo[2][2] && bingo[3][1] && bingo[4][0]) {
			cnt_bingo++;
		}
		if (cnt_bingo == 3) {
			return 1;
		}
	}

	return 0;
}

int find(int n) //���� �ִ��� ã��.
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (map[i][j] == n) {
				bingo[i][j] = 1;
				if (find_bingo(i, j)) {
					return 1; //3����.
				}
				
				return 0; //���� ã������, 3���� �ƴϸ�.
			}
		}
	}

	return 0;
}

int main(void)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}

	int num;
	for (int i = 0; i < 25; i++) {
		scanf_s("%d", &num);
		if (find(num)) {
			printf("%d", i + 1);
			return 0;
		}
	}
}