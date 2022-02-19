#include <stdio.h>

int n, m; // 1~n까지. m개의 숫자로 이뤄진 수열 찾기.
int arr[9];

void get(int num, int k) {
	arr[k] = num;

	if (k == m) { //m개만큼 배열이 채워졌으면, 출력.
		for (int i = 1; i <= m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

	for (int i = num + 1; i <= n; i++) {
		get(i, k + 1);
	}
}

int main(void)
{
	scanf_s("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		if (n - i >= m - 1) {
			get(i, 1);
		}
	}
}