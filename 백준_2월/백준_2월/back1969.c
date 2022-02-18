#include <stdio.h>

char dna[1001][51];
int gataca[4];
char acgt[] = { 'A', 'C', 'G', 'T' };
char result[51];

int n, m;
int test(int a, int b) {
	return 0;
}
int main(void)
{
	scanf_s("%d %d", &n, &m);

	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s(" %c", &c, sizeof(c));
			dna[i][j] = c;
		}
	}

	for (int i = 0; i < m; i++) {
		// dna ���� ����.
		for (int j = 0; j < n; j++) {
			if (dna[j][i] == 'A') {
				gataca[0] += 1;
			}
			else if (dna[j][i] == 'C') {
				gataca[1] += 1;
			}
			else if (dna[j][i] == 'G') {
				gataca[2] += 1;
			}
			else if (dna[j][i] == 'T') {
				gataca[3] += 1;
			}
		}

		// ���� ���� �����ϴ� dna ã��
		int max_idx = 0;
		int max = 0;
		for (int k = 0; k < 4; k++) {
			if (max < gataca[k]) {
				max = gataca[k];
				max_idx = k;
			}
			gataca[k] = 0; //�ʱ�ȭ.
		}

		result[i] = acgt[max_idx];
	}
	result[m] = '\0';

	//�ع� �Ÿ� ã��.
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (result[j] != dna[i][j]) {
				cnt++;
			}
		}
	}

	printf("%s\n", result);
	printf("%d", cnt);
}