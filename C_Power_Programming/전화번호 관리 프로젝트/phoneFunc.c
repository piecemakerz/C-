/*
 * Name : phoneFunc.c ver 1.6
 * Content : ��ȭ��ȣ ��Ʈ�� �Լ�
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

/* �Լ� : void InputPhoneData(void)
 * ��� : ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
 * ��ȯ : void
 *
 */

void InputPhoneData(void)
{
	// phoneData data;
	phoneData * data;

	if (numOfData >= LIST_NUM)
	{
		puts("�޸� ������ �����մϴ�.");
		return;
	}

	data = (phoneData*)malloc(sizeof(phoneData));

	fputs("�̸��� �Է��ϼ��� : ", stdout);
	//gets(data.name);
	gets(data->name);
	fputs("��ȭ��ȣ�� �Է��ϼ��� : ", stdout);
	//gets(data.phoneNum);
	gets(data->phoneNum);

	for (int i = 0; i < numOfData; i++) {
		if (!strcmp(phoneList[i]->name, data->name) && 
			!strcmp(phoneList[i]->phoneNum, data->phoneNum)) {
			free(data);
			puts("�̹� �Էµ� ������ �Դϴ�.");
			getchar();
			return;
		}
	}

	phoneList[numOfData++] = data;

	getchar();
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	StoreDataToFileInStruct();
	return;
}

/* �Լ� : void ShowAllData(void)
 * ��� : ����� ������ ��ü ���
 * ��ȯ : void
 *
 */

void ShowAllData(void) {
	for (int i = 0; i < numOfData; i++) {
		//ShowPhoneInfo(phoneList[i])
		ShowPhoneInfoByPtr(phoneList[i]);
	}
	puts("����� �Ϸ�Ǿ����ϴ�.");
	getchar();
	return;
}

void SearchPhoneData(void) {
	char name[NAME_LEN];
	int namefound = 0;
	fputs("ã�� �̸���? ", stdout);
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
		puts("�˻��� �Ϸ�Ǿ����ϴ�.");
	else
		puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
	getchar();

	return;
}

void DeletePhoneData(void) {
	char name[NAME_LEN];
	int samenameidx[LIST_NUM];
	int samecount = 0;
	int choice;
	fputs("ã�� �̸���? ", stdout);
	gets(name);

	for (int i = 0; i < numOfData; i++) {
		if (!strcmp(phoneList[i]->name, name)) {
			samenameidx[samecount++] = i;
		}
	}
	if (!samecount) {
		puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
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

		fputs("���P : ", stdout);
		scanf("%d", &choice);
		getchar();
	}
	free(phoneList[samenameidx[choice-1]]);

	for (int i = samenameidx[choice-1]; i<numOfData-1 ;i++)
		phoneList[i] = phoneList[i+1];

	numOfData--;
	puts("������ �Ϸ�Ǿ����ϴ�.");
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
				puts("������ �߻��߽��ϴ�.");
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
	fputs("���� ����� �̸���? ", stdout);
	gets(name);

	for (int i = 0; i < numOfData; i++) {
		if (!strcmp(phoneList[i]->name, name)) {
			samenameidx[samecount++] = i;
		}
	}

	if (!samecount) {
		puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
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

		fputs("���P : ", stdout);
		scanf("%d", &choice);
		getchar();
	}
	fputs("������ ��ȭ��ȣ��? ", stdout);
	gets(phoneNum);

	strcpy(phoneList[samenameidx[choice - 1]]->phoneNum, phoneNum);
	puts("������ �Ϸ�Ǿ����ϴ�.");
	getchar();
	//StoreDataToFile();
	StoreDataToFileInStruct();
	return;
}