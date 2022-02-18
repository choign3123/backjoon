#include <cstdio>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int tree[1025]; //�Է� ����.
int print_tree[1025]; //��°� ����.
int height, n_node;

int main(void)
{
	scanf_s("%d", &height);

	n_node = pow(2, height) - 1; //����� ����.

	for (int i = 1; i <= n_node; i++) {
		scanf_s("%d", &tree[i]);
	}
	//�Է� ó�� ��.

	queue<pair<int, int>> queue; //(���� �ε���, �� �ε���) ����.
	queue.push({ 1, n_node });

	pair<int, int> idx;
	int mid; //����idx~��idx�� �߰��� �ִ°� ���(�ڱ� �ڽ�) �����.
	for (int i = 1; i <= n_node; i++) {
		idx = queue.front();
		queue.pop();

		mid = (idx.first + idx.second) / 2;
		print_tree[i] = tree[mid];

		queue.push({ idx.first, mid - 1 }); //����
		queue.push({ mid + 1, idx.second }); //������
	}

	//Ʈ�� ���.
	int cnt = 2;
	printf("%d\n", print_tree[1]); //��Ʈ ��� ���� ���.
	for (int i = 2; i <= n_node; i++) {
		printf("%d ", print_tree[i]); //��� ���.

		if (i == (int)pow(2, cnt) - 1) { //�ٹٲ�.
			printf("\n");
			cnt++;
		}
	}
}