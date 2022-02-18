#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[100001];
int parent[100001];

int main(void)
{
	int num;

	scanf_s("%d", &num);

	int v, u;
	for (int i = 0; i < num - 1; i++) {
		scanf_s("%d %d", &v, &u);
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	queue<int> q;

	q.push(1);
	int p = 0;

	while (!q.empty()) {
		int v = q.front();
		p = q.front();
		q.pop();

		int u;
		for (int i = 0; i < graph[v].size(); i++) {
			u = graph[v][i];
			if (!parent[u]) {
				parent[u] = p;
				q.push(u);
			}
		}
	}

	for (int i = 2; i <= num; i++) {
		printf("%d\n", parent[i]);

	}
}