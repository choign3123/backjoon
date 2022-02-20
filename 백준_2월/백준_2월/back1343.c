#include <stdio.h>

int main(void)
{
	char c;
	char pre_c = 'N';
	int arr[50] = { 0 };
	char result[50];

	int size = 0;
	while (1) {
		scanf_s("%c", &c, sizeof(c));
		if (c == '\n') {
			break;
		}
		
		if (pre_c != c) { //이전과 문자가 같지 않다면.
			size++;
		}

		if (c == 'X') {
			arr[size] += 1;
		}
		else if (c == '.') {
			arr[size] -= 1;
		}

		pre_c = c;
	}


	int idx = 0;
	for (int i = 1; i <= size; i++) {
		if (arr[i] < 0) { // .의 개수.
			result[idx] = -1 * arr[i];
			idx++;
			continue;
		}
		if (arr[i] % 2 != 0) { //홀수라면 A와 B로 만들 수 없음.
			printf("-1");
			return 0;
		}

		while (arr[i] != 0) { //A나 B로 만들 수 있다면,
			if (arr[i] >= 4) { // A
				arr[i] -= 4;
				result[idx] = 'A';
				idx++;
			}
			else if (arr[i] >= 2) { // B
				arr[i] -= 2;
				result[idx] = 'B';
				idx++;
			}
		}
	}

	for (int i = 0; i < idx; i++) {
		if (result[i] == 'A') {
			printf("AAAA");
		}
		else if (result[i] == 'B') {
			printf("BB");
		}
		else {
			for (int j = 0; j < result[i]; j++) {
				printf(".");
			}
		}
	}
}