#include <stdio.h>

int main(void) {
	int sum = 0;
	while (true) {
		fputs("Data input (Ctrl+Z to exit) : ", stdout);
		if (getchar() == EOF)
			break;
		sum++;
		getchar();
	}
	printf("�Էµ� ������ �� : %d\n", sum);
	return 0;
}