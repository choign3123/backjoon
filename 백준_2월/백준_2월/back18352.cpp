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
	//입력 처리 끝.

	for (int i = 1; i <= n_v; i++) { //dist(거리 배열) 초기화
		dist[i] = INF;
	}
	dist[start] = 0; //자기자신까지의 거리는 0.

	queue<pair<int, int>> queue;
	for (int i = 0; i < graph[start].size(); i++) { //start와 연결된 정점 찾아 모두 큐에 넣기
		queue.push({ start, graph[start][i] });
	}

	pair<int, int> node;
	while (!queue.empty()) {
		node = queue.front();
		queue.pop();

		v = node.first;
		u = node.second;
		if (dist[u] > dist[v] + DISTANCE) { //그냥 가는 것보다 거처가는게 더 빠르다면
			dist[u] = dist[v] + DISTANCE;
		}
		for (int i = 0; i < graph[u].size(); i++) { //정점 u에 연결되있는 간선 찾아 넣기
			if (dist[graph[u][i]] == INF) { //아직 거리 계산 안했으면 (bfs로 계산할 수 있는거라..)
				queue.push({ u, graph[u][i] });
			}
		}
	}

	//원하는 최단거리의 개수 찾기.
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