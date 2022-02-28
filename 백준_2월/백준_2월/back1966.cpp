#include <cstdio>
#include <algorithm>
#include <list>

using namespace std;

list<pair<int, bool>>::iterator itr;
int n_testcase;
int n_doc, key_idx;

int main(void)
{
	scanf_s("%d", &n_testcase);
	 
	for (int k = 0; k < n_testcase; k++) { //�׽�Ʈ ���̽��� ������ŭ.
		scanf_s("%d %d", &n_doc, &key_idx);

		list<pair<int, bool>> lst;
		int n;
		for (int i = 0; i < n_doc; i++) {
			scanf_s("%d", &n);
			if (i == key_idx) {
				lst.push_back({ n, true });
			}
			else {
				lst.push_back({ n, false });
			}
		}

		pair<int, bool> doc;
		bool isPrint; //��� ���� �ȵ���.
		int cnt = 0; //��µ� ������ ����
		while (!lst.empty()) { //�����Ϳ� ���� ������ ���� ������.
			doc = lst.front(); //ù��° ����.
			lst.pop_front();
			isPrint = true;

			itr = lst.begin(); //�ǻ� �ι�° ��������.
			while (itr != lst.end()) {
				if (doc.first < itr->first) { //�ڿ� �� �߿��� ������ �ִٸ�.
					lst.push_back(doc); //�ڷ� ��.
					isPrint = false; //��� �ȵ�. �ڷ� �и�.
					break;
				}
				itr++; //���� ���� Ȯ��.
			}

			if (isPrint) { //��� �����ϸ�
				cnt++;
				if (doc.second == true) { //key_idx�� �������ٸ�.
					printf("%d\n", cnt);
					break;
				}
			}
		}

	}
}