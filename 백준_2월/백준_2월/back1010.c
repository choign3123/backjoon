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
		//�ٵ� ���� �̷��� ���ϰ� �׳� for �ݺ��� �ؼ� ���ص� �ǳ�..
		while (cnt < n_west || r <= n_west) { //nCr ���ϱ�. 
			if (cnt <= n_west) { //n * (n-1) * (n-2) * ... �� n_west�� ��ŭ.
				result *= n;
				n--;
				cnt++;
			}
			if (result % r == 0 && r <= n_west) { //1 * 2 * 3 ... �� n_west����ŭ.
				result /= r;
				r++;
			}
		}

		printf("%lld\n", result);
	}
}