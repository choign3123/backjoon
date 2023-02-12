#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

stack<int> st;

int main(void) {

	int n;
	char comd[10] = {0};

	scanf("%d", &n);

	int arg;
	for (int i = 0; i < n; i++) {
		scanf("%s", comd);//명령 입력받기

		if (strcmp(comd, "push") == 0) {
			scanf("%d", &arg);
			st.push(arg);
		}
		else if (strcmp(comd, "pop") == 0) {
			if (st.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", st.top());
			st.pop();
		}
		else if (strcmp(comd, "size") == 0) {
			printf("%d\n", st.size());
		}
		else if (strcmp(comd, "empty") == 0) {
			printf("%d\n", st.empty());
		}
		else {
			if (st.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", st.top());
		}
	}
}