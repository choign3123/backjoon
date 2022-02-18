#include <stdio.h>

int house[1001][3];
int dp[1001][3];
int min_cost = 1000 * 1000;
int row;

int main(void)
{
	scanf_s("%d", &row);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 3; j++) {
			scanf_s("%d", &house[i][j]);
		}
	}

	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];

	int rgb2, rgb3;
	int cost;
	for (int n = 1; n < row; n++) {
		for (int rgb = 0; rgb < 3; rgb++) {
			rgb2 = (rgb + 1) % 3;
			rgb3 = (rgb + 2) % 3;
			cost = dp[n-1][rgb2] < dp[n-1][rgb3] ? dp[n-1][rgb2] : dp[n-1][rgb3];
			dp[n][rgb] = house[n][rgb] + cost;
		}
	}

	min_cost = dp[row - 1][0] < dp[row - 1][1] ? dp[row - 1][0] : dp[row - 1][1];
	min_cost = min_cost < dp[row - 1][2] ? min_cost : dp[row - 1][2];
	printf("%d", min_cost);
}