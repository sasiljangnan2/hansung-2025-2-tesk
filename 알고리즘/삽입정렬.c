#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE  6
#define SWAP(x, y, t) (t = x, x = y, y = t)

int list[] = { 5,3,8,1,2,7 };
int n;
void print_sort(int list[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}

void insertion(int list[], int n)
{
	int key, j;
	for (int i = 1; i < n; i++)
	{
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
			
		}
		list[j + 1] = key;
		print_sort(list, n);
	}
}

int main(void)
{
	n = MAX_SIZE;
	insertion(list, n);
	//print_sort(list, n);
}
