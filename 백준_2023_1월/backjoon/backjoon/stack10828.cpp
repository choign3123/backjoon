#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {

	int n;
	char comd[10] = {0};

	scanf("%d", &n);

	int arg;
	for (int i = 0; i < n; i++) {
		scanf("%s", comd);
		if (strcmp(comd, "push") == 0) {
			scanf("%d", &arg);
			printf("%d\n", arg);
		}
	}
}