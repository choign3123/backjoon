#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> graph[1001];
int visit[1001];
int vertex, edge;
int cnt = 0;

// v - u
// 기본 방식.

void dfs(int start) 
{
	visit[start] = 1;

	vector<int> v = graph[start];
	for (int i = 0; i < v.size(); i++) {
		int u = v[i];
		if (!visit[u]) {
			dfs(u);
		}
	}
}


int main(void)
{
	scanf_s("%d %d", &vertex, &edge);

	int v, u;
	for (int i = 0; i < edge; i++) {
		scanf_s("%d %d", &v, &u);
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	int cnt = 0;
	for (int i = 1; i < vertex+1; i++) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}

	printf("%d", cnt);
}