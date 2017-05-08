#include <stdio.h>
#define FACTOR_ONEUNDER_ERROR -100
int Factorial(int num);

int main(void) {
	int num, result;
	fputs("숫자 입력(1이상) : ", stdout);
	scanf("%d", &num);
	/*if (num < 1) 
		puts("입력이 잘못되어 예상치 못한 결과를 얻었습니다.");
	else
		printf("%d! = %d\n", num, Factorial(num));
	*/
	result = Factorial(num);
	if(result == FACTOR_ONEUNDER_ERROR)
		puts("입력이 잘못되어 예상치 못한 결과를 얻었습니다.");
	else
		printf("%d! = %d\n", num, result);

	return 0;
}

int Factorial(int num) {
	int fact=1;

	if (num < 1)
		return FACTOR_ONEUNDER_ERROR;
	
	for (int i = 1; i <= num; i++)
		fact *= i;
	return fact;
}