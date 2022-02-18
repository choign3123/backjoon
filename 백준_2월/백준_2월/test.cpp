#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int n;
int map[101][101];
int way[101][101];
void visit() {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            way[i][j] = map[i][j];
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j && (map[i][k] + map[k][j] >= 1))way[i][j] = 1;
                else if (map[i][k] + map[k][j] >= 2) {
                    way[i][j] = 1;
                }
            }
        }
    }

}
int main() {

    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    visit();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", way[i][j]);
        }
        printf("\n");
    }
    return 0;
}