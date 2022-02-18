#include <stdio.h>

int main(void)
{
	int n_test;
	int n_west, n_east;

	scanf_s("%d", &n_test);


	for (int i = 0; i < n_test; i++) {
		scanf_s("%d %d", &n_west, &n_east);

		if (n_west > n_east / 2) {
			n_west = n_east - n_west; // nCr = nCn-r = east C west
		}

		int n = n_east;
		int r = 1;
		long long result = 1;
		int cnt = 0;
		//근데 굳이 이렇게 안하고 그냥 for 반복문 해서 구해도 되네..
		while (cnt < n_west || r <= n_west) { //nCr 구하기. 
			if (cnt <= n_west) { //n * (n-1) * (n-2) * ... 를 n_west개 만큼.
				result *= n;
				n--;
				cnt++;
			}
			if (result % r == 0 && r <= n_west) { //1 * 2 * 3 ... 를 n_west개만큼.
				result /= r;
				r++;
			}
		}

		printf("%lld\n", result);
	}
}