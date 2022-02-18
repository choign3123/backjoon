#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int mirro[101][101];
int dist[101][101];
queue<pair<int, int>> q;

int dirc_x[] = { -1,0,1,0 };
int dirc_y[] = { 0,1,0,-1 };

int bfs()
{
	q.push(make_pair(0,0));
	dist[0][0] = 1;
	int x, y;

	pair<int, int> point;
	while (!q.empty()) {
		point = q.front();
		q.pop();
		x = point.first;
		y = point.second;

		if (x == n-1 && y == m-1) {
			return dist[x][y]; //칸수 리턴해야함.
		}

		int next_x, next_y;
		for (int i = 0; i < 4; i++) {
			next_x = x + dirc_x[i];
			next_y = y + dirc_y[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
				if (!dist[next_x][next_y] && mirro[next_x][next_y]) {
					dist[next_x][next_y] = dist[x][y] + 1;
					q.push(make_pair(next_x, next_y));
				}
			}
			
		}
	}
}

int main(void)
{
	scanf_s("%d %d", &n, &m);
	
	int c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &c);
			mirro[i][j] = c;
		}
	}

	printf("%d", bfs());
}