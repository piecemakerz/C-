/*
 * Name : phoneFunc.c ver 1.1
 * Content : 전화번호 컨트롤 함수
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.18
 */

#include "common.h"
#include "phoneData.h"
#include "ScreenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData phoneList[LIST_NUM];

/* 함수 : void InputPhoneData(void)
 * 기능 : 전화번호 관련 데이터 입력 받아서 저장
 * 반환 : void
 *
 */

void InputPhoneData(void)
{
	phoneData data;
	if (numOfData >= LIST_NUM)
	{
		puts("메모리 공간이 부족합니다.");
		return;
	}
	fputs("이름을 입력하세요 : ", stdout);
	gets(data.name);
	fputs("전화번호를 입력하세요 : ", stdout);
	gets(data.phoneNum);

	phoneList[numOfData++] = data;

	getchar();
	puts("입력이 완료되었습니다.");

	return;
}

/* 함수 : void ShowAllData(void)
 * 기능 : 저장된 데이터 전체 출력
 * 반환 : void
 *
 */

void ShowAllData(void) {
	for (int i = 0; i < numOfData; i++) {
		ShowPhoneInfo(phoneList[i]);
	}
	puts("출력이 완료되었습니다.");
	getchar();
	return;
}
