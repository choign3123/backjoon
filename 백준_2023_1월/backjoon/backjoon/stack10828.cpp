#include <stdio.h>
#include <string.h>

int main(void) {

	int n;
	char comd[10];

	scanf_s("%d", &n);

	int arg;
	for (int i = 0; i < n; i++) {
		scanf_s("%s", comd, sizeof(comd));
		if (strcmp(comd, "push") == 0) {
			scanf_s("%d", &arg);
			printf("%d\n", arg);
		}
	}
}