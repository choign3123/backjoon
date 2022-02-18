#include <stdio.h>

int arr[101][101];
int visit[101][101];
int size;

int dirc_x[] = { -1, 0, 1, 0 };
int dirc_y[] = { 0,1,0,-1 };

void dfs(int x, int y, int color) 
{
	visit[x][y] = 1;

	int xx, yy;
	for (int i = 0; i < 4; i++) {
		xx = x + dirc_x[i];
		yy = y + dirc_y[i];

		if (0 <= xx && xx < size && 0 <= yy && yy < size) {
			if (!visit[xx][yy] && arr[xx][yy] == color) {
				dfs(xx, yy, color);
			}
		}
	}
}

int main(void)
{
	scanf_s("%d", &size);

	char c;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf_s(" %c", &c, sizeof(c));

			if (c == 'R') {
				arr[i][j] = 0;
			}
			else if (c == 'G') {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = 2;
			}
		}
	}

	int zone1 = 0, zone2 = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (!visit[i][j]) {
				dfs(i, j, arr[i][j]);
				zone1++;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			visit[i][j] = 0;
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			if (!visit[i][j]) {
				dfs(i, j, arr[i][j]);
				zone2++;
			}
		}
	}

	printf("%d %d", zone1, zone2);
}