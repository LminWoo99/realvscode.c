#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;


int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high, k;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low]<pivot);
		do
			high--;
		while (list[high]>pivot);
		if (low<high) SWAP(list[low], list[high], temp);
	} while (low<high);

	SWAP(list[left], list[high], temp);
	for (k= 0; k < right+1; k++)
	      printf("%d  ", list[k]);
	printf("\n");
	return high;
}
void quick_sort(int list[], int left, int right)
{
	int k;
	printf("(list[], %d, %d) 호출\n", left, right);
	for (k= left; k < right+1; k++)
        printf("[%d] %d  ", k, list[k]);
	printf("\n");	
	if (left<right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
//		for (k= 0; k < right+1; k++)
//	      printf("%d  ", list[k]);
//	    printf("\n");	
	}
}

//
int main(void)
{
	int i;
	int n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i<n; i++) {     	// ≥≠ºˆ ª˝º∫ π◊ √‚∑¬ 
		list[i] = rand() % 100;
		printf("%d  ", list[i]);
    }
    printf("\n");
	quick_sort(list, 0, n-1); // ƒ¸¡§∑ƒ »£√‚ 
	for (i = 0; i<n; i++)
		printf("%d  ", list[i]);
	printf("\n");
	return 0;
}
