#include <stdio.h>

int main(void) {
	char input;
	while (1) {
		if (scanf("%c", &input) == EOF) {
			puts("프로그램을 종료합니다.");
			break;
		}
		/*if (input - 'a' >= 0 && input - 'z' <=0) {
			puts("입력하신 문자는 알파벳 소문자입니다.");
		}
		else if (input - 'A' >= 0 && input - 'Z' <= 0) {
			puts("입력하신 문자는 알파벳 대문자입니다.");
		}
		else if (input - '0' >= 0 && input - '9' <= 0) {
			puts("입력하신 문자는 아라비아숫자입니다.");
		}
		else {
			puts("특수문자를 입력하셨군요.");
		}
		*/
		if (input  >= 'a' && input <= 'z') {
			puts("입력하신 문자는 알파벳 소문자입니다.");
		}
		else if (input >= 'A' && input <= 'Z') {
			puts("입력하신 문자는 알파벳 대문자입니다.");
		}
		else if (input >= '0' && input <= '9') {
			puts("입력하신 문자는 아라비아숫자입니다.");
		}
		else {
			puts("특수문자를 입력하셨군요.");
		}
		scanf("%c", &input);
	}
	return 0;
}