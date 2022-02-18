#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define DISTANCE 1
#define INF 10000000

using namespace std;

vector<int> graph[300005];
// graph[v] = u (v -> u)
vector<int> dist(300005);

int n_v, n_edge, find_dist, start;

int main(void)
{
	scanf_s("%d %d %d %d", &n_v, &n_edge, &find_dist, &start);

	int v, u;
	for (int i = 0; i < n_edge; i++) {
		scanf_s("%d %d", &v, &u);
		graph[v].push_back(u);
	}
	//�Է� ó�� ��.

	for (int i = 1; i <= n_v; i++) { //dist(�Ÿ� �迭) �ʱ�ȭ
		dist[i] = INF;
	}
	dist[start] = 0; //�ڱ��ڽű����� �Ÿ��� 0.

	queue<pair<int, int>> queue;
	for (int i = 0; i < graph[start].size(); i++) { //start�� ����� ���� ã�� ��� ť�� �ֱ�
		queue.push({ start, graph[start][i] });
	}

	pair<int, int> node;
	while (!queue.empty()) {
		node = queue.front();
		queue.pop();

		v = node.first;
		u = node.second;
		if (dist[u] > dist[v] + DISTANCE) { //�׳� ���� �ͺ��� ��ó���°� �� �����ٸ�
			dist[u] = dist[v] + DISTANCE;
		}
		for (int i = 0; i < graph[u].size(); i++) { //���� u�� ������ִ� ���� ã�� �ֱ�
			if (dist[graph[u][i]] == INF) { //���� �Ÿ� ��� �������� (bfs�� ����� �� �ִ°Ŷ�..)
				queue.push({ u, graph[u][i] });
			}
		}
	}

	//���ϴ� �ִܰŸ��� ���� ã��.
	int cnt = 0;
	for (int i = 1; i <= n_v; i++) {
		if (find_dist == dist[i]) {
			cnt++;
			printf("%d\n", i);
		}
	}

	if (cnt <= 0) {
		printf("-1");	
	}
}