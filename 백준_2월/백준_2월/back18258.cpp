#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int main(void)
{
	queue<int> queue;
	int n_inst;

	char str[10];
	int n;

	scanf_s("%d", &n_inst); //명령의 개수

	for (int i = 0; i < n_inst; i++) {
		scanf_s("%s", &str, sizeof(str)); //어떤 명령인지 입력받기

		//push
		if (strcmp(str, "push") == 0) {
			scanf_s("%d", &n);
			queue.push(n);
		}
		//pop
		else if (strcmp(str, "pop") == 0) {
			if (queue.empty()) { //큐가 비었음
				printf("-1\n");
			}
			else {
				n = queue.front();
				queue.pop();
				printf("%d\n", n);
			}
		}
		//size
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", queue.size());
		}
		//empty
		else if (strcmp(str, "empty") == 0) {
			if (queue.empty()) {
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
		//front
		else if (strcmp(str, "front") == 0) {
			if (queue.empty()) { //큐가 비었음.
				printf("-1\n");
			}
			else {
				n = queue.front();
				printf("%d\n", n);
			}
		}
		//back
		else if (strcmp(str, "back") == 0) {
			if (queue.empty()) { //큐가 비었음.
				printf("-1\n");
			}
			else {
				n = queue.back();
				printf("%d\n", n);
			}
		}
	}
}