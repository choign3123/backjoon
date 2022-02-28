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
	 
	for (int k = 0; k < n_testcase; k++) { //테스트 케이스의 개수만큼.
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
		bool isPrint; //출력 될지 안될지.
		int cnt = 0; //출력된 문서의 개수
		while (!lst.empty()) { //프린터에 남은 문서가 없을 때까지.
			doc = lst.front(); //첫번째 문서.
			lst.pop_front();
			isPrint = true;

			itr = lst.begin(); //실상 두번째 문서부터.
			while (itr != lst.end()) {
				if (doc.first < itr->first) { //뒤에 더 중요한 문서가 있다면.
					lst.push_back(doc); //뒤로 밂.
					isPrint = false; //출력 안됨. 뒤로 밀림.
					break;
				}
				itr++; //다음 문서 확인.
			}

			if (isPrint) { //출력 가능하면
				cnt++;
				if (doc.second == true) { //key_idx의 문서였다면.
					printf("%d\n", cnt);
					break;
				}
			}
		}

	}
}