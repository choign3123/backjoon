#include <stdio.h>

int city[101][101];
int visit[101][101];
int dirc_x[] = { -1,0,1,0 };
int dirc_y[] = { 0,1,0,-1 };
int size;

void dfs(int x, int y, int h)
{
	visit[x][y] = 1;

	int next_x, next_y;

	for (int i = 0; i < 4; i++) {
		next_x = x + dirc_x[i];
		next_y = y + dirc_y[i];
		if (0 <= next_x && next_x < size && 0 <= next_y && next_y < size) {
			if (city[next_x][next_y] > h && !visit[next_x][next_y]) {
				dfs(next_x, next_y, h);
			}
		}
	}
}

int main(void)
{
	int num_of_safe = 0;

	scanf_s("%d", &size);

	int max_height = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf_s("%d", &city[i][j]);
			max_height = max_height < city[i][j] ? city[i][j] : max_height;
		}
	}
	//입력 처리 끝.

	for (int h = 0; h <= max_height; h++) {
		int cnt = 0;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (city[i][j] > h && !visit[i][j]) {
					dfs(i, j, h);
					cnt++;
				}
			}
		}

		num_of_safe = num_of_safe < cnt ? cnt : num_of_safe;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				visit[i][j] = 0;
			}
		}
	}

	printf("%d", num_of_safe);
}