#include <cstdio>
#include <utility>
#include <algorithm>

//#define max(x, y) ( ((x) > (y))? (x) : (y) )

using namespace std;

int map[8][8];
int visit[8][8];
pair<int, int> virus[10];
pair<int, int> safe_point[64];
int dirc_x[] = { -1,0,1,0 };
int dirc_y[] = { 0,1,0,-1 };
int row, col;
int cnt_virus;

void dfs(int x, int y) 
{
	visit[x][y] = 1;

	int xx, yy;
	for (int i = 0; i < 4; i++) {
		xx = x + dirc_x[i];
		yy = y + dirc_y[i];

		if (0 <= xx && xx < row && 0 <= yy && yy < col) {
			if (!visit[xx][yy] && map[xx][yy] == 0) {
				cnt_virus++;
				dfs(xx, yy);
			}
		}
	}
}

void init_visit()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			visit[i][j] = 0;
		}
	}
}

int main(void)
{
	int total_virus = 0;
	int total_safe = 0;
	int total_wall = 3;
	int max_safe = 0;

	scanf_s("%d %d", &row, &col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf_s("%d", &map[i][j]);

			if (map[i][j] == 2) {
				virus[total_virus] = { i, j };
				total_virus++;
			}
			else if (map[i][j] == 0) {
				safe_point[total_safe] = { i, j };
				total_safe++;
			}
			else {
				total_wall++;
			}
		}
	}

	for (int x = 0; x < total_safe; x++) {
		for (int y = 0; y < total_safe; y++) {
			if (x == y) {
				continue;
			}

			for (int z = 0; z < total_safe; z++) {
				if (z == y || z == x) {
					continue;
				}

				map[safe_point[x].first][safe_point[x].second] = 1;
				map[safe_point[y].first][safe_point[y].second] = 1;
				map[safe_point[z].first][safe_point[z].second] = 1;

				cnt_virus = 0;
				for (int i = 0; i < total_virus; i++) {
					dfs(virus[i].first, virus[i].second);
				}

				int temp = col * row - cnt_virus - total_virus - total_wall;
				max_safe = max(max_safe, temp);
				init_visit();

				map[safe_point[x].first][safe_point[x].second] = 0;
				map[safe_point[y].first][safe_point[y].second] = 0;
				map[safe_point[z].first][safe_point[z].second] = 0;
			}

		}

		
	}

	printf("%d", max_safe);
}