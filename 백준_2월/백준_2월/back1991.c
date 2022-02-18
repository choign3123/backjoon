#include <stdio.h>

int tree[27][2]; 
//tree[���][0] = �����ڽ� 
//tree[���][1] = �������ڽ�

void inorder(int node) //������ȸ
{
	if (tree[node][0] != -1) {
		inorder(tree[node][0]);
	}

	printf("%c", node + 'A');

	if (tree[node][1] != -1) {
		inorder(tree[node][1]);
	}
}

void preorder(int node) //������ȸ
{
	printf("%c", node + 'A');

	if (tree[node][0] != -1) {
		preorder(tree[node][0]);
	}

	if (tree[node][1] != -1) {
		preorder(tree[node][1]);
	}
}

void postorder(int node) //������ȸ
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

		if (l_child == '.') { //'.'�̸� �ڽĳ�� ����.
			tree[node % 'A'][0] = -1; //%(���������) ���� ������, ���� 'A' -> 0 ���� �ٲ��ַ���.
			//�׷��� 'B' -> 1, 'C' -> 2 ... ���� �ٲ��ַ���.
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

	//�Է� ó����.

	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
}