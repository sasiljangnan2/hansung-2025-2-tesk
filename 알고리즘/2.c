#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time() 함수 사용 위해 필요
#include <cstdlib> // system() 함수 사용 위해 필요
#define MAX_ELEMENT 200

typedef struct
{
	int key;
} element;
typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h)
{
	h->heap_size = 0;
}
// 하프 생성 함수
void random(int* n) // 난수 생성 함수, 포인터 변수이므로 리턴값 없음
{
	srand((unsigned int)time(NULL)); // 무작위 시드
	printf("생성된 난수: ");
	for (int i = 0; i < 5; i++)
	{
		n[i] = rand() % 100 + 1;
		printf("%d ", n[i]);
	}
	printf("\n\n");
}

void print_heap(HeapType* h) //배열 출력 함수
{
	for (int i = 1; i <= h->heap_size; i++) printf(" %d", h->heap[i].key);
	printf("\n");
}

void insert_max_heap(HeapType* h, element item) //하프 삽입 함수
{
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
	printf("%d 삽입:", item.key);
	print_heap(h); // 순차적으로 배열을 출력
}
void Menu() //메뉴 출력 함수
{
	printf("1. 난수 생성하기\n");
	printf("2. 배열 생성하기\n");
	printf("3. 배열 출력하기\n");
	printf("4. 종료\n");
	printf("1, 2, 3, 4중 택 1: ");
}
int main(void)
{
	system("COLOR F0"); // 흰바탕 검은 글씨
	int* n = (int*)malloc(sizeof(int) * 5); // 동적 할당을 통한 난수 저장할 포인터변수 생성
	int c, isrand = 0; // 난수 생성 여부 확인
	element e;
	HeapType* heap;
	heap = create(); // 히프 생성
	init(heap); // 초기화
	while (1) // 종료 전까지 반복
	{
		Menu();
		scanf("%d", &c);
		switch (c)
		{
		case 1:
		{
			random(n);
			isrand = 1; // 난수 생성됨
			break;
		}
		case 2:
		{
			if (isrand != 1) // 난수 생성 안됐으면
			{
				printf("난수를 먼저 생성하세요.\n\n");
			}
			else
			{
				for (int i = 0; i < 5; i++)
				{
					e.key = n[i];
					insert_max_heap(heap, e); // 히프에 삽입
				}
				printf("\n");
			}
			break;
		}
		case 3:
		{
			if (isrand != 1) // 난수 생성 안됐으면
			{
				printf("난수를 먼저 생성하세요.\n\n");
				break;
			}
			else
			{
				printf("배열 출력: ");
				print_heap(heap);
				printf("\n");
				break;
			}
		}
		case 4: exit(0); // 종료
		default: printf("잘못된 입력입니다.\n\n"); // 잘못 입력 시

		}
	}
	free(heap);
	free(n); // 동적할당 해제
	return 0;
}
