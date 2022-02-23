#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long dist[1000005]; //출발지에서부터 해당 도시가 있는 곳까지의 거리
long long price[100001]; //기름값
vector<long long> result(1000000001);
// result[남은 거리] = 비용

int n_city;

int main(void)
{
	scanf_s("%d", &n_city);

	long long sum = 0, n;
	for (int i = 1; i < n_city; i++) { //거리
		scanf_s("%lld", &n);
		sum += n;
		dist[i] = sum;
	}

	for (int i = 0; i < n_city; i++) { //기름값
		scanf_s("%lld", &n);
		price[i] = n;
	}

	for (int i = 0; i < n_city; i++) {
		long long now_l = dist[i]; //현재 위치
		for (int j = i+1; j < n_city; j++) {
			long long next_l = dist[j]; //다음 위치
			long long pre = result[next_l];
			long long post = result[now_l] + (next_l - now_l) * price[i];
			if (pre > post || result[next_l] == 0) { //값이 싸거나, 애초에 비용이 계산되지 않았었다면
				result[next_l] = post;
			}
		}
	}

	long long final_l = dist[n_city-1];
	printf("%lld", result[final_l]);
}