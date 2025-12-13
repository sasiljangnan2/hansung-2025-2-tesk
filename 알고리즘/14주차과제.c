#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define MAX_LEN 50
#define SWAP(a, b, temp) ((temp) = (a), (a)= (b), (b) = (temp))

typedef struct Dic
{
	char key[MAX_LEN];
	char value[MAX_LEN];
} Dic;

Dic dic[MAX], temp;

void read_file(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("실패\n");
		exit(1);
	}
	for (int i = 0; i < MAX; i++) {
		fscanf(fp, "%s %s", dic[i].key, dic[i].value);
	}
	fclose(fp);
}
void print_sort(Dic list[], int n)
{
	for (int i = 0; i < n; i++) 
	{
		printf("%s %s ", list[i].key, list[i].value);
	}
	printf("\n\n");
}

void insertion(Dic list[], int n)
{
	char key[MAX_LEN], value[MAX_LEN];
	int i, j;
	for (int i = 1; i < n; i++)
	{
		strcpy(key, list[i].key);
		strcpy(value, list[i].value);
		for (j = i - 1; j >= 0 && _stricmp(key, list[j].key) < 0; j--)
		{
			list[j + 1] = list[j];
		}
		strcpy(list[j + 1].key, key);
		strcpy(list[j + 1].value, value);
	}
}

void buble_sort(Dic list[], int n) // 버블 정렬
{
	int i, j;
	Dic temp;
	for (i = 0; i < n - 1; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (_stricmp(list[i].key, list[j].key) > 0) // 오름차순 정렬 (왼쪽에 있는 값이 더 크면 교환)
			{
				SWAP(list[i], list[j], temp);
			}
		}
	}
}

void menu()
{
	printf("-------------------\n");
	printf("1. 삽입 정렬\n");
	printf("2. 버블 정렬\n");
	printf("3. 퀵 정렬\n");
	printf("4. 종료\n");
	printf("-------------------\n");
	printf("선택: ");
}

int compare(const void* a, const void* b) // 퀵정렬을 위한 compare 함수
{
	Dic num1 = *(Dic*)a;
	Dic num2 = *(Dic*)b;
	return _stricmp(num1.key, num2.key); // 오름차순 정렬 (음수, 0, 양수 반환)
}
int main(void)
{
	int choice;
	while (1) 
	{
		menu();
		scanf("%d", &choice);
		clock_t start = clock();
		read_file("pluginfile.txt");
		switch (choice) {
		case 1: // 삽입 정렬
		{
			insertion(dic, MAX);
			break;
		}
		case 2: // 버블 정렬
		{
			buble_sort(dic, MAX);
			break;
		}
		case 3: // 퀵 정렬
		{
			qsort(dic, MAX, sizeof(Dic), compare);
			break;
		}
		case 4:
		{
			printf("종료.\n");
			return 0;
		}
		default:
		{
			printf("잘못된 선택입니다. 다시 선택하세요.\n");
			continue;
		}
	}
		print_sort(dic, MAX);
		clock_t end = clock();
		printf("소요 시간: %.3lf 초\n\n", (double)(end - start) / CLOCKS_PER_SEC);
	}
}