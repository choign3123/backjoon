#include <stdio.h>

long long dist[1000005]; //������������� �ش� ���ð� �ִ� �������� �Ÿ�
long long price[100001]; //�⸧��

int n_city;

int main(void)
{
	scanf_s("%d", &n_city);

	long long sum = 0, n;
	for (int i = 0; i < n_city-1; i++) { //�Ÿ�
		scanf_s("%lld", &n);
		dist[i] = n;
	}

	for (int i = 0; i < n_city; i++) { //�⸧��
		scanf_s("%lld", &n);
		price[i] = n;
	}

	long long result = 0;
	long long min_pri = 1000000001;
	for (int i = 0; i < n_city-1; i++) {
		if (min_pri > price[i]) { //�⸧���� �Ѱɷ� �� ������. �װ� ������ �̵�.
			min_pri = price[i];
		}
		result += min_pri * dist[i];
	}

	printf("%lld", result);
}