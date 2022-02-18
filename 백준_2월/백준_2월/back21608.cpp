#include <cstdio>

int report[101][3];
//report[소번호][0] = 위치
//report[소번호][1] = 길을 건넌 횟수.
//report[소번호][2] = 기록 됐는지 안됐는지.

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

		if (report[cow][2] == 0) { //아직 기록되지 않은 소
			report[cow][0] = p;
			report[cow][2] = 1;
		}
		else { //한번 이상 기록된 소
			if (p != report[cow][0]) { //지금 위치와 이전 위치가 다르다면
				report[cow][1] += 1;
				report[cow][0] = p;
				min++;
			}
		}
	}

	printf("%d", min);
}