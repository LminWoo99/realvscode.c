#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}confer;

int compare_x(const confer* x1, const confer* x2) {
	if (x1->y == x2->y) {
		if (x1->x < x2->x)
			return -1;
		else if (x1->x > x2->x)
			return 1;
		else
			return 0;
	}
	return 0;
}

int compare_y(const confer* x1, const confer* x2) {
	if (x1->y < x2->y)
		return -1;
	else if (x1->y > x2->y)
		return 1;
	else
		return 0;
}

int main() {
	int n; 
	scanf("%d", &n);
	confer* arr;
	arr = calloc(n, sizeof(confer));
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	qsort(arr, n, sizeof(confer), (int(*)(const void*, const void*))compare_y);
	qsort(arr, n, sizeof(confer), (int(*)(const void*, const void*))compare_x);
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].x < a) continue;
		a = arr[i].y;
		b++;
	}
	printf("%d\n", b);
	free(arr);
}


