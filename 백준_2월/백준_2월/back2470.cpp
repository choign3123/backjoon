#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution;

int main(void) {
	int size;
	vector<int> answer(2);

	scanf_s("%d", &size);
	
	int n;
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &n);
		solution.push_back(n);
	}

	sort(solution.begin(), solution.end());

	int zero = 1000000000;
	int temp;
	int s = 0, e = size-1;
	while (s < size || e >= 0) {

		temp = solution[s] + solution[e];
		if (temp < 0) {
			temp = -1 * temp;

		}

		if (temp < zero) {
			zero = temp;
			answer[0] = solution[s];
			answer[1] = solution[e];

		}

		if (temp < zero && !(solution[s] < 0 && solution[e] < 0)) {
			e--;
			if (s == e) {
				s++;
			}
		}
		else {
			s++;
			if (s == e) {
				e--;
			}
		}
	}

	sort(answer.begin(), answer.end());
	printf("%d %d", answer[0] , answer[1]);
}