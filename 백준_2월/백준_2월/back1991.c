#include <stdio.h>

int tree[27][2]; 
//tree[노드][0] = 왼쪽자식 
//tree[노드][1] = 오른쪽자식

void inorder(int node) //중위순회
{
	if (tree[node][0] != -1) {
		inorder(tree[node][0]);
	}

	printf("%c", node + 'A');

	if (tree[node][1] != -1) {
		inorder(tree[node][1]);
	}
}

void preorder(int node) //전위순회
{
	printf("%c", node + 'A');

	if (tree[node][0] != -1) {
		preorder(tree[node][0]);
	}

	if (tree[node][1] != -1) {
		preorder(tree[node][1]);
	}
}

void postorder(int node) //후위순회
{
	if (tree[node][0] != -1) {
		postorder(tree[node][0]);
	}

	if (tree[node][1] != -1) {
		postorder(tree[node][1]);
	}

	printf("%c", node + 'A');
}

int main(void)
{
	int n_node;

	char node;
	char l_child, r_chlid;

	scanf_s("%d", &n_node);

	for (int i = 0; i < n_node; i++) {
		scanf_s(" %c %c %c", &node, sizeof(node), &l_child, sizeof(l_child), &r_chlid, sizeof(r_chlid));

		if (l_child == '.') { //'.'이면 자식노드 없음.
			tree[node % 'A'][0] = -1; //%(나머지계산) 해준 이유는, 문자 'A' -> 0 으로 바꿔주려고.
			//그래서 'B' -> 1, 'C' -> 2 ... 전부 바꿔주려고.
		}
		else {
			tree[node % 'A'][0] = l_child % 'A';
		}
		if (r_chlid == '.') {
			tree[node % 'A'][1] = -1;
		}
		else {
			tree[node % 'A'][1] = r_chlid % 'A';
		}
	}

	//입력 처리끝.

	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
}