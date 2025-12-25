#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define MAX_LEN 50
#define SWAP(a, b, temp) ((temp) = (a), (a)= (b), (b) = (temp)) // 매크로 함수로 교환

typedef struct Dic // 단어장 구조체
{
	char key[MAX_LEN];
	char value[MAX_LEN];
} Dic;

Dic dic[MAX], temp; // 단어장 구조체 배열과 임시 구조체 변수 

void read_file(const char* filename) // 파일 읽기 함수
{
	FILE* fp = fopen(filename, "r"); // 파일 열기
	if (fp == NULL) // 파일 실패시
	{
		printf("실패\n");
		exit(1);
	}
	for (int i = 0; i < MAX; i++)
	{
		fscanf(fp, "%s %s", dic[i].key, dic[i].value); // 단어장 구조체 배열에 단어와 뜻 저장
	}
	fclose(fp);
}
void print_sort(Dic list[], int n) // 정렬된 결과 출력 함수
{
	for (int i = 0; i < n; i++)
	{
		printf("%s %s ", list[i].key, list[i].value);
	}
	printf("\n\n");
}

void insertion(Dic list[], int n) // 삽입 정렬
{
	int i, j;
	Dic temp;
	for (int i = 1; i < n; i++)
	{
		temp = list[i]; // 현재 삽입할 원소를 temp에 저장
		for (j = i - 1; j >= 0 && _stricmp(temp.key, list[j].key) < 0; j--) // list[j].key가 key보다 클때까지 반복
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = temp; // temp를 올바른 위치에 삽입
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

int compare(const void* a, const void* b) // 퀵정렬을 위한 compare 함수
{
	Dic num1 = *(Dic*)a;
	Dic num2 = *(Dic*)b;
	return _stricmp(num1.key, num2.key); // 오름차순 정렬 (음수, 0, 양수 반환)
}

void menu() // 메뉴 출력 함수
{
	printf("-------------------\n");
	printf("1. 삽입 정렬\n");
	printf("2. 버블 정렬\n");
	printf("3. 퀵 정렬\n");
	printf("4. 종료\n");
	printf("-------------------\n");
	printf("선택: ");
}

int main(void)
{
	system("COLOR F0"); // 흰바탕 검은 글씨
	int choice;
	while (1)
	{
		menu();
		scanf("%d", &choice);
		
		read_file("pluginfile.txt"); // 파일 읽어서 단어장 구조체 배열에 저장
		clock_t start = clock(); // 시간 측정 시작
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
		case 4: // 종료
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
		clock_t end = clock(); // 시간 측정 종료
		printf("소요 시간: %.3lf 초\n\n", (double)(end - start) / CLOCKS_PER_SEC);
	}
}