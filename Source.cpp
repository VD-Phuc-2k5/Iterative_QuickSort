#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Itemtype int
#define MAX 10000
// khai bao cac macro
#define swap(type, a, b) do { \
	type temp = a; \
	a = b; \
	b = temp; \
} while(0)

#define xuatMang(format, arr, length) do \
{ \
	{ \
		int i = 0; \
		for (i; i < length; i++) \
			printf(format, arr[i]); \
		printf("\n"); \
	} \
} while(0)
// ham
int randomInRange(int min, int max);
Itemtype* tao_mang_tu_dong(int len);
int phanHoach(Itemtype* arr, int left_pointer, int right_pointer);
void quick_sort(Itemtype* arr, int left_pointer, int right_pointer);
void giaiPhongBoNho(Itemtype** arr);
/*==================================================*/
int main()
{
	srand((Itemtype)time(NULL));
	Itemtype *arr = tao_mang_tu_dong(10);
	xuatMang("%d ", arr, 10);
	quick_sort(arr, 0, 9);
	xuatMang("%d ", arr, 10);
	giaiPhongBoNho(&arr);
	system("pause>0");
	return 0;
}
/*==================================================*/
int randomInRange(int min, int max) {
    return min + rand() % (max - min + 1);
}
Itemtype* tao_mang_tu_dong(int len)
{
	Itemtype* arr = new Itemtype[len];
	while(len--)
		arr[len] = randomInRange(-100, 100);
	return arr;
}
int phanHoach(Itemtype* arr, int left_pointer, int right_pointer)
{
	Itemtype pivot = arr[right_pointer]; 
    int i = left_pointer - 1, j;
    for (j = left_pointer; j < right_pointer; j++) 
	{
        if (arr[j] < pivot) {
            i++;
            swap(Itemtype, arr[i], arr[j]);
        }
    }
    swap(Itemtype, arr[i + 1], arr[right_pointer]);
    return i + 1;
}
void quick_sort(Itemtype* arr, int left_pointer, int right_pointer)
{
	int stack[MAX];
    int top = -1;
	int pivotIndex;

    stack[++top] = left_pointer;
    stack[++top] = right_pointer;

    while (top >= 0) {
        right_pointer = stack[top--];
        left_pointer = stack[top--];

        pivotIndex = phanHoach(arr, left_pointer, right_pointer);

        if (pivotIndex - 1 > left_pointer) 
		{
            stack[++top] = left_pointer;
            stack[++top] = pivotIndex - 1;
        }

        if (pivotIndex + 1 < right_pointer) 
		{
            stack[++top] = pivotIndex + 1;
            stack[++top] = right_pointer;
        }
    }
}
void giaiPhongBoNho(Itemtype **arr)
{
    if (*arr != NULL) {
        delete[] *arr;
        *arr = NULL;
    }
}