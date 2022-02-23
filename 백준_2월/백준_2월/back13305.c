#include <stdio.h>

long long dist[1000005]; //출발지에서부터 해당 도시가 있는 곳까지의 거리
long long price[100001]; //기름값

int n_city;

int main(void)
{
	scanf_s("%d", &n_city);

	long long sum = 0, n;
	for (int i = 0; i < n_city-1; i++) { //거리
		scanf_s("%lld", &n);
		dist[i] = n;
	}

	for (int i = 0; i < n_city; i++) { //기름값
		scanf_s("%lld", &n);
		price[i] = n;
	}

	long long result = 0;
	long long min_pri = 1000000001;
	for (int i = 0; i < n_city-1; i++) {
		if (min_pri > price[i]) { //기름값이 싼걸로 더 갈거임. 그게 무조건 이득.
			min_pri = price[i];
		}
		result += min_pri * dist[i];
	}

	printf("%lld", result);
}