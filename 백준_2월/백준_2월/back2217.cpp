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
	//�Է� ó�� ��.

	sort(rope.begin(), rope.end(), greater<int>()); //�������� ����.

	int max = rope[0]; //�Ѱ��� ������ ���� ��, ��ƿ �� �ִ� �ִ� ����.
	int w = 0; //��ƿ �� �ִ� ����.
	for (int i = size - 1; i >= 0; i--) { //�������� ������ �Ἥ ��ƿ �� �ִ� �ִ� ���� ã��.
		w = rope[i] * (i+1); //i+1���� ������ �Ἥ ��ƿ �� �ִ� �ִ� ����.

		if (w > max) {
			max = w;
		}
	}

	printf("%d", max);
}