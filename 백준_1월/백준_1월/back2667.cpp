#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int map_size;
int map[26][26];
int visit[26][26];

int dirc_x[] = { -1,0,1,0 };
int dirc_y[] = { 0,1,0,-1 };

int cnt = 0;

void bfs(int x, int y)
{
	visit[x][y] = 1;
	cnt++;

	int next_x, next_y;
	for (int i = 0; i < 4; i++) {
		next_x = x + dirc_x[i];
		next_y = y + dirc_y[i];

		if (0 <= next_x && next_x < map_size && 0 <= next_y && next_y < map_size) {
			if (map[next_x][next_y] && !visit[next_x][next_y]) {
				bfs(next_x, next_y);
			}
		}

	}
}

int main(void)
{
	int num_of_home = 0;
	vector<int> homes;

	scanf_s("%d", &map_size);

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			if (map[i][j] && !visit[i][j]) {
				bfs(i, j);

				homes.push_back(cnt);
				num_of_home++;
				cnt = 0;
			}
		}
	}

	printf("%d\n", num_of_home);

	sort(homes.begin(), homes.end());
	for (int i = 0; i < homes.size(); i++) {
		printf("%d\n", homes[i]);
	}
}