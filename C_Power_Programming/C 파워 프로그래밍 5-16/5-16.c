#include <stdio.h>
#include <string.h>

int main(void) {
	char array[256];
	int length;
	int difference = 'a' - 'A';
	char input;
	fputs("���ڿ� �Է� : ", stdout);
	gets(array);
	length = strlen(array);
	for (int i = 0; i < length; i++) {
		if (array[i] >= 'a' && array[i] <= 'z')
			array[i] -= difference;
		else if (array[i] >= 'A' && array[i] <= 'Z')
			array[i] += difference;
	}
	puts(array);

	fputs("���ڿ� �Է� : ", stdout);
	do {
		input = getchar();
		if (input >= 'a' && input <= 'z')
			input -= difference;
		else if (input >= 'A' && input <= 'Z')
			input += difference;
		putchar(input);
	} while (input != '\n');

	return 0;
}