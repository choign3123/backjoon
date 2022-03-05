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
	//입력 처리 끝

	sort(person.begin(), person.end(), greater<int>()); //오름차순으로 정렬해줌. 
	//무조건 팁이 높을수록 먼저 서비스 해주는 것이 이들이기에.

	for (int i = 0; i < n_person; i++) {
		if (person[i] - i > 0) {
			tip += person[i] - i;
		}
	}

	printf("%lld", tip);
}