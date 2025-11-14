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
void selection(int list[], int n)
{
	int least, temp;
	for (int i = 0; i < n ; i++)
	{
		least = i;
		for (int j = i + 1; j < n; j++)
		{
			if (list[j] < list[least]) least = j;
		}
		SWAP(list[i], list[least], temp);
		print_sort(list, n);
	}
}


int main(void)
{
	n = MAX_SIZE;
	selection(list, n);
	print_sort(list, n);
}
