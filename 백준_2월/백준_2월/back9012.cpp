#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	int n;

	scanf_s("%d", &n);
	getchar();

	vector<char> str_arr[100];
	char c;
	for (int i = 0; i < n; i++) {
		while (1) {
			scanf_s("%c", &c, sizeof(c));
			if (c == '\n') {
				break;
			}
			str_arr[i].push_back(c);
		}
	}

	for (int i = 0; i < n; i++) {
		stack<char> stk;
		for (int j = 0; j < str_arr[i].size(); j++) {
			char c = str_arr[i][j];
			if (c == '(') {
				stk.push(c);
			}
			else {
				if (!stk.empty() && stk.top() == '(') {
					stk.pop();
				}
				else {
					stk.push(c);
				}
			}
		}

		if (stk.empty()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}