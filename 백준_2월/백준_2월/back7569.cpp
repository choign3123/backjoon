#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct Point {
	int x;
	int y;
	int z;
} typedef Point;

queue<Point> q;
int tomato[101][101][101];
int row, col, height;
int dirc_x[] = { -1, 0, 1, 0, 0, 0 };
int dirc_y[] = { 0, 1, 0, -1, 0, 0 };
int dirc_z[] = { 0, 0, 0, 0, 1, -1 };
int max_t = 1;

void bfs()
{
	while (!q.empty()) {
		Point pnt = q.front();
		q.pop();

		int xx, yy, zz;
		int x, y, z;
		x = pnt.x;
		y = pnt.y;
		z = pnt.z;

		for (int i = 0; i < 6; i++) {
			xx = x + dirc_x[i];
			yy = y + dirc_y[i];
			zz = z + dirc_z[i];

			if (0 <= xx && xx < row && 0 <= yy && yy < col && 0 <= zz && zz < height) {
				if (tomato[zz][xx][yy] == 0) {
					tomato[zz][xx][yy] = tomato[z][x][y] + 1;
					max_t = tomato[zz][xx][yy];
					pnt = { xx, yy, zz };
					q.push(pnt);
				}
			}
		}

	}
}

int main(void)
{
	scanf_s("%d %d %d", &col, &row, &height);

	Point pnt;
	int n;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				scanf_s("%d", &n);
				tomato[i][j][k] = n;

				if (tomato[i][j][k] == 1) {
					pnt.x = j;
					pnt.y = k;
					pnt.z = i;
					q.push(pnt);
				}
			}
		}
	}

	bfs();

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				if (tomato[i][j][k] == 0) {
					printf("-1");
					return 0;
				}
			}
		}
	}

	printf("%d", max_t - 1);
}