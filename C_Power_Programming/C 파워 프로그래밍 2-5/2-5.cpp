#include <stdio.h>

int main(void) {
	double f1, f2;
	fputs("µÎ °³ÀÇ ½Ç¼ö ÀÔ·Â : ", stdout);
	scanf("%lf %lf", &f1, &f2);
	printf("µ¡¼À °á°ú : %f\n", f1 + f2);
	printf("»¬¼À °á°ú : %f\n", f1 - f2);
	printf("°ö¼À °á°ú : %f\n", f1 * f2);
	printf("³ª´°¼À °á°ú : %f\n", f1 / f2);
	fputs("¹ÝÁö¸§ ÀÔ·Â : ", stdout);
	scanf("%lf", &f1);
	printf("¿øÀÇ ³ÐÀÌ : %f", (f1*f1)*3.14);
}