#include <cstdio>

int report[101][3];
//report[�ҹ�ȣ][0] = ��ġ
//report[�ҹ�ȣ][1] = ���� �ǳ� Ƚ��.
//report[�ҹ�ȣ][2] = ��� �ƴ��� �ȵƴ���.

int main(void) {
	int n;

	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		report[i][1] = 0;
		report[i][2] = 0;
	}

	int cow, p;
	int min = 0;
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &cow, &p);

		if (report[cow][2] == 0) { //���� ��ϵ��� ���� ��
			report[cow][0] = p;
			report[cow][2] = 1;
		}
		else { //�ѹ� �̻� ��ϵ� ��
			if (p != report[cow][0]) { //���� ��ġ�� ���� ��ġ�� �ٸ��ٸ�
				report[cow][1] += 1;
				report[cow][0] = p;
				min++;
			}
		}
	}

	printf("%d", min);
}