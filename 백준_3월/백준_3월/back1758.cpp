#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n_person;
vector<int> person;

int main(void)
{
	long long tip = 0;

	scanf_s("%d", &n_person);
	
	int n;
	for (int i = 0; i < n_person; i++) {
		scanf_s("%d", &n);
		person.push_back(n);
	}
	//�Է� ó�� ��

	sort(person.begin(), person.end(), greater<int>()); //������������ ��������. 
	//������ ���� �������� ���� ���� ���ִ� ���� �̵��̱⿡.

	for (int i = 0; i < n_person; i++) {
		if (person[i] - i > 0) {
			tip += person[i] - i;
		}
	}

	printf("%lld", tip);
}