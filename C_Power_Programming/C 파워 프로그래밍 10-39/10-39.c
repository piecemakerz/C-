#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 100

int main(void) {
	int num;
	char str[MAX_STR_LEN];
	char ch;
	FILE * fp;
	fp = fopen("weather_info.txt", "wt");
	if (fp == NULL) {
		puts("파일 'weather_info.txt'가 열리지 않았습니다.");
		return -1;
	}

	while (1) {
		puts("**날씨 정보 입력******");
		fputs("날짜 : ", stdout);

		if(scanf("%d", &num)==EOF){
			puts("입력이 완료되었습니다.");
			puts("\n");
			fclose(fp);
			break;
		}

		fwrite(&num, sizeof(int), 1, fp);
		getchar();

		fputs("지역 : ", stdout);
		fgets(str, MAX_STR_LEN, stdin);
		fputs(str, fp);

		fputs("오전(A)/오후(P) : ", stdout);
		ch = fgetc(stdin);
		fputc(ch, fp);
		getchar();

		fputs("날씨 : ", stdout);
		fgets(str, MAX_STR_LEN, stdin);
		fputs(str, fp);

		puts("\n");
	}
	// 여기까지 문제 39-1

	fp = fopen("weather_info.txt", "rt");
	if (fp == NULL) {
		puts("파일 'weather_info.txt'가 열리지 않았습니다.");
		return -1;
	}

	while(1){
		fread(&num, sizeof(int), 1, fp);
		if (feof(fp) != 0)
			break;
		printf("날짜 : %d\n", num);

		fgets(str, MAX_STR_LEN, fp);
		printf("지역 : %s", str);

		ch = fgetc(fp);
		printf("오전(A)/오후(P) : %c\n", ch);

		fgets(str, MAX_STR_LEN, fp);
		printf("날씨 : %s\n", str);
	}

	puts("출력이 완료되었습니다.\n");
	fclose(fp);

	// 여기까지 문제 39-2

	int day, day_f;
	char strRegion[MAX_STR_LEN], strRegion_f[MAX_STR_LEN];
	char ap, ap_f;
	char strWeather_f[MAX_STR_LEN];

	fp = fopen("weather_info.txt", "rt");
	if (fp == NULL) {
		puts("파일 'weather_info.txt'가 열리지 않았습니다.");
		return -1;
	}

	fputs("검색할 날짜 및 지역 정보 입력 : ", stdout);
	scanf("%d %s %c", &day, strRegion, &ap);

	sprintf(strRegion, "%s\n", strRegion);

	while (1)
	{
		fread(&day_f, sizeof(int), 1, fp);
		if (feof(fp) != 0) 
			break;

		fgets(strRegion_f, MAX_STR_LEN, fp);
		ap_f = fgetc(fp);
		fgets(strWeather_f, MAX_STR_LEN, fp);

		if (day == day_f && !strcmp(strRegion, strRegion_f) && ap == ap_f) {
			printf("날짜 : %d\n", day_f);
			printf("지역 : %s", strRegion_f);
			printf("오전(A)/오후(P) : %c\n", ap_f);
			printf("날씨 : %s\n", strWeather_f);
			fclose(fp);
			puts("검색이 완료되었습니다.");
			return 0;
		}
	}

	fclose(fp);
	puts("해당 날짜 및 지역의 데이터가 존재하지 않습니다.");
	return 0;
	// 여기까지 문제 39-3
}