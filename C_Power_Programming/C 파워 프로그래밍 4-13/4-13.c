#include <stdio.h>

int main(void) {
	int num, save;
	while (1) {
		fputs("1 �̻��� ���� �Է� : ", stdout);
		if (scanf("%d", &num) == EOF) {
			puts("EOF �Է¿� ���� ���α׷��� �����մϴ�.");
			break;
		}
		else {
			if (num < 1) {
				puts("1 �̻��� �Է��� �ʿ�� �մϴ�. �ٽ� �Է��ϼ���.");
				continue;
			}
			else {
				printf("%d�� �����\n", num);
				save = num;
				for (int i = 1; i <= num; i++) {
					if (!(num%i)) {
						printf("%d ", i);
					}
				}
				puts("\n");
			}
		}
	}
	return 0;
}