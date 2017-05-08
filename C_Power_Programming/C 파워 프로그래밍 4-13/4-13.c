#include <stdio.h>

int main(void) {
	int num, save;
	while (1) {
		fputs("1 이상의 정수 입력 : ", stdout);
		if (scanf("%d", &num) == EOF) {
			puts("EOF 입력에 의해 프로그램을 종료합니다.");
			break;
		}
		else {
			if (num < 1) {
				puts("1 이상의 입력을 필요로 합니다. 다시 입력하세요.");
				continue;
			}
			else {
				printf("%d의 약수들\n", num);
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