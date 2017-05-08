#include <stdio.h>
// 주의해야할 문제
int Dim1ArrSum(int*, int);
int SumOfArrayBy2(int(*arrPtr)[2], int column);
int SumOfArrayBy3(int(*aarrPtr)[3], int column);

int main(void) {
	int arr1[3] = { 5,10,15 };
	int arr2[5] = { 1,2,3,4,5 };
	int arr3[2][2] = { 1,3,5,7 };
	int arr4[2][3] = { 1,2,3,4,5,6 };

	printf("5, 10, 15의 합 : %d\n", Dim1ArrSum(arr1, sizeof(arr1) / sizeof(arr1[0])));
	printf("1, 2, 3, 4, 5의 합 : %d\n", Dim1ArrSum(arr2, sizeof(arr2) / sizeof(arr2[0])));
	puts("");
	printf("1, 3, 5, 7의 합 : %d\n", SumOfArrayBy2(arr3, sizeof(arr3)/sizeof(arr3[0])));
	printf("1, 2, 3, 4, 5, 6의 합 : %d\n", SumOfArrayBy3(arr4, sizeof(arr4)/sizeof(arr4[0])));

}

int Dim1ArrSum(int* arr, int length) {
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	return sum;
}

int SumOfArrayBy2(int(*arrPtr)[2], int column){
	int total = 0;
	for (int i = 0; i < column; i++)
		total += Dim1ArrSum(arrPtr[i], 2);
		
	return total;
}

int SumOfArrayBy3(int(*arrPtr)[3], int column) {
	int total = 0;
	for (int i = 0; i < column; i++)
		total += Dim1ArrSum(arrPtr[i], 3);

	return total;

}