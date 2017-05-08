#include <stdio.h>

int main(void) {
	int num;
	int odd = 0, even = 0, count=1;
	int sum = 0;
	fputs("자연수 입력 : ", stdout);
	scanf("%d", &num);
	while (num<=0) {
		puts("0보다 큰 정수를 입력해 주세요");
		fputs("자연수 입력 : ", stdout);
		scanf("%d", &num);
	}
	for (int i = num; i >= 1; i--) {
		if (i % 2)
			odd += i;
		else
			even += i;
	}
	printf("%d 이하 홀수 합 : %d\n", num, odd);
	printf("%d 이하 짝수 합 : %d\n", num, even);
	puts("");
	fputs("2 이상 입력 : ", stdout);
	scanf("%d", &num);
	while (num <= 1) {
		puts("2이상의 정수를 입력해 주세요");
		fputs("자연수 입력 : ", stdout);
		scanf("%d", &num);
	}
	while ((sum+count) <= num) {
		sum += count++;
	}
	printf("%d를 더할 때 처음 %d를 넘기 시작한다.\n", count, num);
	printf("%d를 넘기 이전의 합 : %d\n", num, sum);
	printf("%d를 넘은 이후의 합 : %d\n", num, sum+count);
}