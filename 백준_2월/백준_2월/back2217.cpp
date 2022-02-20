#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> rope;

int main(void)
{
	int size;
	scanf_s("%d", &size);

	int n;
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &n);
		rope.push_back(n);
	}
	//입력 처리 끝.

	sort(rope.begin(), rope.end(), greater<int>()); //내림차순 정렬.

	int max = rope[0]; //한개의 로프만 썼을 때, 버틸 수 있는 최대 무게.
	int w = 0; //버틸 수 있는 무게.
	for (int i = size - 1; i >= 0; i--) { //여래개의 로프를 써서 버틸 수 있는 최대 무게 찾기.
		w = rope[i] * (i+1); //i+1개의 로프를 써서 버틸 수 있는 최대 무게.

		if (w > max) {
			max = w;
		}
	}

	printf("%d", max);
}