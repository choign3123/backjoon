#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define BOOM 3

int row, col;
int out_time;


int map[201][201];
int dirc_x[] = { -1,0,1,0 };
int dirc_y[] = { 0 , 1 , 0 , -1 };

void boom(int x, int y) //������� ��ź ��Ʈ����
{
	int xx, yy;

	map[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		xx = x + dirc_x[i];
		yy = y + dirc_y[i];
		if (0 <= xx && xx < row && 0 <= yy && yy < col) {
			map[xx][yy] = 0;
		}
	}
}

int main(void)
{
	scanf_s("%d %d %d", &row, &col, &out_time);

	char c;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf_s(" %c", &c, sizeof(c));
			if (c == '.') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = BOOM;
			}
		}
	}
	//�Է� ó����.

	// 2�ʺ���~
	for (int time = 2; time <= out_time; time++) {
		
		queue<pair<int, int>> queue;
		for (int t = 0; t < row; t++) {
			for (int s = 0; s < col; s++) {
				if (map[t][s] == 0) { //�� �� ä���
					map[t][s] = BOOM + time;
				}
				else if (map[t][s] == time) { //�ش� �ʿ� ��Ʈ���� �� �� ã��.
					queue.push({ t,s });
				}
			}

		}
		//��ź ��Ʈ����.
		pair<int, int> p;
		while (!queue.empty()) {
			p = queue.front();
			queue.pop();

			boom(p.first, p.second);
		}
	}

	//��� ���
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 0) {
				printf(".");
			}
			else {
				printf("O");
			}
		}
		printf("\n");
	}
}