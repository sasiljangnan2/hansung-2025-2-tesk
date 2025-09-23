#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct 
{
	int avail; 
	int id;   
} element;

typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_size;
}Heaptype;

Heaptype *create()
{
	return (Heaptype*)malloc(sizeof(Heaptype));
}
void init(Heaptype* h)
{
	h->heap_size = 0;
}

void insert_min_heap(Heaptype* h, element item)
{
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item.avail < h->heap[i/2].avail))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
element delete_min_heap(Heaptype* h)
{
	element item, temp;
	int parent, child;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		if (child < h->heap_size && h->heap[child].avail > h->heap[child  + 1].avail )
		{
			child++;
		}
		if (temp.avail < h->heap[child].avail)
		{
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
int main(void)
{
	element m = { 0,0 };
	Heaptype* h;
	h = create();
	init(h);

	int jobs[] = { 8,7,6,5,3,2,1 };
	for (int i = 0; i < 3; i++)
	{
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	for (int i = 0; i < 7; i++)
	{
		m = delete_min_heap(h);
		printf("job %d을 시간=%d부터 시간=%d까지 머신 %d번에 배치함. \n", i, m.avail, m.avail + jobs[i] - 1, m.id);
		m.avail += jobs[i];
		insert_min_heap(h, m);
	}

}