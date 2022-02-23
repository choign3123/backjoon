#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long dist[1000005]; //������������� �ش� ���ð� �ִ� �������� �Ÿ�
long long price[100001]; //�⸧��
vector<long long> result(1000000001);
// result[���� �Ÿ�] = ���

int n_city;

int main(void)
{
	scanf_s("%d", &n_city);

	long long sum = 0, n;
	for (int i = 1; i < n_city; i++) { //�Ÿ�
		scanf_s("%lld", &n);
		sum += n;
		dist[i] = sum;
	}

	for (int i = 0; i < n_city; i++) { //�⸧��
		scanf_s("%lld", &n);
		price[i] = n;
	}

	for (int i = 0; i < n_city; i++) {
		long long now_l = dist[i]; //���� ��ġ
		for (int j = i+1; j < n_city; j++) {
			long long next_l = dist[j]; //���� ��ġ
			long long pre = result[next_l];
			long long post = result[now_l] + (next_l - now_l) * price[i];
			if (pre > post || result[next_l] == 0) { //���� �ΰų�, ���ʿ� ����� ������ �ʾҾ��ٸ�
				result[next_l] = post;
			}
		}
	}

	long long final_l = dist[n_city-1];
	printf("%lld", result[final_l]);
}