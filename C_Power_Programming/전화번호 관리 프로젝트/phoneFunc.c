/*
 * Name : phoneFunc.c ver 1.6
 * Content : 전화번호 컨트롤 함수
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.19
 */

#include "common.h"
#include "phoneData.h"
#include "ScreenOut.h"

#define LIST_NUM 100

int numOfData = 0;

// phoneData phoneList[LIST_NUM];
phoneData * phoneList[LIST_NUM];

/* 함수 : void InputPhoneData(void)
 * 기능 : 전화번호 관련 데이터 입력 받아서 저장
 * 반환 : void
 *
 */

void InputPhoneData(void)
{
	// phoneData data;
	phoneData * data;

	if (numOfData >= LIST_NUM)
	{
		puts("메모리 공간이 부족합니다.");
		return;
	}

	data = (phoneData*)malloc(sizeof(phoneData));

	fputs("이름을 입력하세요 : ", stdout);
	//gets(data.name);
	gets(data->name);
	fputs("전화번호를 입력하세요 : ", stdout);
	//gets(data.phoneNum);
	gets(data->phoneNum);

	for (int i = 0; i < numOfData; i++) {
		if (!strcmp(phoneList[i]->name, data->name) && 
			!strcmp(phoneList[i]->phoneNum, data->phoneNum)) {
			free(data);
			puts("이미 입력된 데이터 입니다.");
			getchar();
			return;
		}
	}

	phoneList[numOfData++] = data;

	getchar();
	puts("입력이 완료되었습니다.");
	StoreDataToFileInStruct();
	return;
}

/* 함수 : void ShowAllData(void)
 * 기능 : 저장된 데이터 전체 출력
 * 반환 : void
 *
 */

void ShowAllData(void) {
	for (int i = 0; i < numOfData; i++) {
		//ShowPhoneInfo(phoneList[i])
		ShowPhoneInfoByPtr(phoneList[i]);
	}
	puts("출력이 완료되었습니다.");
	getchar();
	return;
}

void SearchPhoneData(void) {
	char name[NAME_LEN];
	int namefound = 0;
	fputs("찾는 이름은? ", stdout);
	gets(name);

	for (int i = 0; i < numOfData; i++) {
		//if(!strcmp(phoneList[i].name, name))
		if (!strcmp(phoneList[i]->name, name)) {
			//ShowPhoneInfo(phoneList[i]);
			ShowPhoneInfoByPtr(phoneList[i]);

			//getchar();
			//return;

			namefound++;
		}
	}
	
	if (namefound)
		puts("검색이 완료되었습니다.");
	else
		puts("찾는 이름의 데이터가 존재하지 않습니다.");
	getchar();

	return;
}

void DeletePhoneData(void) {
	char name[NAME_LEN];
	int samenameidx[LIST_NUM];
	int samecount = 0;
	int choice;
	fputs("찾는 이름은? ", stdout);
	gets(name);

	for (int i = 0; i < numOfData; i++) {
		if (!strcmp(phoneList[i]->name, name)) {
			samenameidx[samecount++] = i;
		}
	}
	if (!samecount) {
		puts("찾는 이름의 데이터가 존재하지 않습니다.");
		getchar();
		return;
	}
	else if (samecount == 1) {
		choice = 1;
	}
	else {
		for (int i = 0; i < samecount; i++) {
			printf("NUM. %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[samenameidx[i]]);
			puts("");
		}

		fputs("선턕 : ", stdout);
		scanf("%d", &choice);
		getchar();
	}
	free(phoneList[samenameidx[choice-1]]);

	for (int i = samenameidx[choice-1]; i<numOfData-1 ;i++)
		phoneList[i] = phoneList[i+1];

	numOfData--;
	puts("삭제가 완료되었습니다.");
	StoreDataToFileInStruct();
	getchar();
	return;
}

void StoreDataToFileInStruct(void) {
	FILE * fp = fopen("phoneData.dat", "wb");
	for (int i = 0; i<numOfData; i++) {
		fwrite(phoneList[i], sizeof(phoneData), 1, fp);
	}
	fclose(fp);
	return;
}

void StoreDataToFile(void) {
	FILE * fp = fopen("phoneData.txt", "wt");
	for(int i=0; i<numOfData; i++){
		fputs(phoneList[i]->name, fp);
		fputc('\n', fp);
		fputs(phoneList[i]->phoneNum, fp);
		fputc('\n', fp);
	}
	fclose(fp);
	return;
}


void LoadDataFromFile(void) {
	FILE * fp = fopen("phoneData.txt", "rt");
	if (fp == NULL)
		return;

	while (1) {
		phoneData * save = (phoneData*)malloc(sizeof(phoneData));
		fgets(save->name, NAME_LEN, fp);
		save->name[strlen(save->name) - 1] = 0;
		if (feof(fp)) {
			free(save);
			break;
		}
		fgets(save->phoneNum, PHONE_LEN, fp);
		save->phoneNum[strlen(save->phoneNum) - 1] = 0;
		phoneList[numOfData++] = save;
	}
	fclose(fp);
	return;
}

void LoadDataFromFileInStruct(void) {
	int count;
	FILE * fp = fopen("phoneData.dat", "rb");
	if (fp == NULL)
		return;
	phoneData * save;

	while (1) {
		save = (phoneData*)malloc(sizeof(phoneData));
		count = fread(save, sizeof(phoneData), 1, fp);
		if (count < sizeof(phoneData)) {
			if (feof(fp))
				puts("오류가 발생했습니다.");
			free(save);
			break;
		}
	}
	fclose(fp);
	return;
}

void ChangePhoneData(void) {
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];
	int samenameidx[LIST_NUM];
	int samecount = 0;
	int choice;
	fputs("변경 대상의 이름은? ", stdout);
	gets(name);

	for (int i = 0; i < numOfData; i++) {
		if (!strcmp(phoneList[i]->name, name)) {
			samenameidx[samecount++] = i;
		}
	}

	if (!samecount) {
		puts("찾는 이름의 데이터가 존재하지 않습니다.");
		getchar();
		return;
	}

	else if (samecount == 1) {
		choice = 1;
	}
	else {
		for (int i = 0; i < samecount; i++) {
			printf("NUM. %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[samenameidx[i]]);
			puts("");
		}

		fputs("선턕 : ", stdout);
		scanf("%d", &choice);
		getchar();
	}
	fputs("변경할 전화번호는? ", stdout);
	gets(phoneNum);

	strcpy(phoneList[samenameidx[choice - 1]]->phoneNum, phoneNum);
	puts("변경이 완료되었습니다.");
	getchar();
	//StoreDataToFile();
	StoreDataToFileInStruct();
	return;
}