#include <stdio.h>

#define THREE 3
#define FIVE 5

int main(void)
{
	int sugar;
	int num = 0;

	scanf_s("%d", &sugar);

	int temp_sugar;
	for (int i = sugar/FIVE; i >= 0; i--) {
		temp_sugar = sugar;
		num = 0;

		num += i;
		temp_sugar -= i * FIVE;
		num += temp_sugar / THREE;
		temp_sugar -= (temp_sugar / THREE) * THREE;

		if (temp_sugar == 0) {
			printf("%d", num);
			return 0;
		}
	}

	printf("-1");

}
//��. �׳� 5�� ������ �� �������� 5*��ŭ �� ����,
//���� �������� �ʴµ�, 3���� ������������ 3 �ѹ� ������ �ٽ� 5����
//�ݺ��Ұ�.

main() { 
	int a = 0, i; 
	scanf("%d", &i); 
	while (1) { 
		if (i < 0) { 
			printf("-1"); break; 
		} 
		else { 
			if (i % 5 == 0) { 
				printf("%d", i / 5 + a); break; 
			} 
			else { 
				a++; i -= 3; 
			} 
		} 
	} 
}