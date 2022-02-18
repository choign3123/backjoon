#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr1;
vector<int> arr2;
vector<int> sorted;

int main(void)
{
	int size1, size2;

	scanf_s("%d %d", &size1, &size2);

	int n;
	for (int i = 0; i < size1; i++) {
		scanf_s("%d", &n);
		arr1.push_back(n);
	}
	for (int i = 0; i < size2; i++) {
		scanf_s("%d", &n);
		arr2.push_back(n);
	}

	//�Է� ó�� �Ϸ�.

	int p1 = 0, p2 = 0;

	while (p1 < size1 && p2 < size2) {
		if (arr1[p1] < arr2[p2]) {
			sorted.push_back(arr1[p1]);
			p1++;
		}
		else {
			sorted.push_back(arr2[p2]);
			p2++;
		}
	}

	//������ ��ҵ� ó��.
	for (int i = p2; i < size2; i++) {
		sorted.push_back(arr2[p2]);
		p2++;
	}
	for (int i = p1; i < size1; i++) {
		sorted.push_back(arr1[p1]);
		p1++;
	}

	for (int i = 0; i < sorted.size(); i++) {
		printf("%d ", sorted[i]);
	}
}