#include <stdio.h>

int main(void) {
	char input;
	while (1) {
		if (scanf("%c", &input) == EOF) {
			puts("���α׷��� �����մϴ�.");
			break;
		}
		/*if (input - 'a' >= 0 && input - 'z' <=0) {
			puts("�Է��Ͻ� ���ڴ� ���ĺ� �ҹ����Դϴ�.");
		}
		else if (input - 'A' >= 0 && input - 'Z' <= 0) {
			puts("�Է��Ͻ� ���ڴ� ���ĺ� �빮���Դϴ�.");
		}
		else if (input - '0' >= 0 && input - '9' <= 0) {
			puts("�Է��Ͻ� ���ڴ� �ƶ��Ƽ����Դϴ�.");
		}
		else {
			puts("Ư�����ڸ� �Է��ϼ̱���.");
		}
		*/
		if (input  >= 'a' && input <= 'z') {
			puts("�Է��Ͻ� ���ڴ� ���ĺ� �ҹ����Դϴ�.");
		}
		else if (input >= 'A' && input <= 'Z') {
			puts("�Է��Ͻ� ���ڴ� ���ĺ� �빮���Դϴ�.");
		}
		else if (input >= '0' && input <= '9') {
			puts("�Է��Ͻ� ���ڴ� �ƶ��Ƽ����Դϴ�.");
		}
		else {
			puts("Ư�����ڸ� �Է��ϼ̱���.");
		}
		scanf("%c", &input);
	}
	return 0;
}