#include <stdio.h>

int main(void) {
	int num, start;
	while (1) {
		fputs("Ȧ�� ��(1), ¦�� ��(2) : ", stdout);
		scanf("%d", &num);
		if (num != 1 && num != 2) {
			puts("�߸��� �Է��Դϴ�. 1 �Ǵ� 2�� �Է��ϼ���.");
		}
		else
			break;
	}
	/* if (num == 1) {
		for (int i = 3; i <= 9; i += 2) {
			for (int j = 1; j <= 9; j++) {
				printf("%d X %d = %d\n", i, j, i*j);
			}
		}
	}
	else {
		for (int i = 2; i <= 8; i += 2) {
			for (int j = 1; j <= 9; j++) {
				printf("%d X %d = %d\n", i, j, i*j);
			}
		}
	}
	*/
	for ((start = (num == 2) ? 2 : 3); start <= 9; start += 2) {
		for(int i=1; i<=9; i++)
			printf("%d X %d = %d\n", start, i, start*i);
	}

	fputs("���� �Է� : ", stdout);
	scanf("%d", &num);
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 100; k++) {
				if ((i*j - k) == num) {
					printf("(%d) X (%d) - (%d) = (%d)\n", i, j, k, num);
				}
			}
		}
	}
	return 0;
}