#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>

using namespace std;

void printStack(stack<int> st) {
	for (int i = 0; i < st.size(); i++) {
		//printf("%d ",)
	}
}

int main(void) {

	stack<int> st;

	st.push(1);
	st.push(2);
	printf("i push 2 number: %d(size)\n", st.size());

	st.pop();
	printf("i pop at the top: %d(size)\n", st.size());

	int n = st.top();
	printf("i get top number: %d\n", n);

	printf("is stack empty? %d\n", st.empty());

}