#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int main(void)
{
	int n_inst;
	scanf_s("%d", &n_inst);

	char str[10];
	int n;
	stack<int> stk;

	for (int i = 0; i < n_inst; i++) {
		scanf_s("%s", str, sizeof(str));
		
		if (strcmp(str, "push") == 0) {
			scanf_s("%d", &n);
			stk.push(n);
		}
		else if (strcmp(str, "pop") == 0) {
			if (!stk.empty()) {
				n = stk.top();
				stk.pop();
				printf("%d\n", n);
			}
			else {
				printf("-1\n");
			}
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", stk.size());
		}
		else if (strcmp(str, "empty") == 0) {
			if (stk.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (strcmp(str, "top") == 0) {
			if (!stk.empty()) {
				n = stk.top();
				printf("%d\n", n);
			}
			else {
				printf("-1\n");
			}
		}
	}
}