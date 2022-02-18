#include <cstdio>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int tree[1025]; //입력 저장.
int print_tree[1025]; //출력값 저장.
int height, n_node;

int main(void)
{
	scanf_s("%d", &height);

	n_node = pow(2, height) - 1; //노드의 개수.

	for (int i = 1; i <= n_node; i++) {
		scanf_s("%d", &tree[i]);
	}
	//입력 처리 끝.

	queue<pair<int, int>> queue; //(시작 인덱스, 끝 인덱스) 저장.
	queue.push({ 1, n_node });

	pair<int, int> idx;
	int mid; //시작idx~끝idx의 중간에 있는게 가운데(자기 자신) 노드임.
	for (int i = 1; i <= n_node; i++) {
		idx = queue.front();
		queue.pop();

		mid = (idx.first + idx.second) / 2;
		print_tree[i] = tree[mid];

		queue.push({ idx.first, mid - 1 }); //왼쪽
		queue.push({ mid + 1, idx.second }); //오른쪽
	}

	//트리 출력.
	int cnt = 2;
	printf("%d\n", print_tree[1]); //루트 노드 먼저 출력.
	for (int i = 2; i <= n_node; i++) {
		printf("%d ", print_tree[i]); //노드 출력.

		if (i == (int)pow(2, cnt) - 1) { //줄바꿈.
			printf("\n");
			cnt++;
		}
	}
}