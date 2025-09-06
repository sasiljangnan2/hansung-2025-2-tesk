#include <stdio.h>
// 간단하게 함수를 사용해 구현해봤습니다.
void print99(int n) //구구단 출력 함수		
{
	for (int i = 1; i <= 10; i++) 
	{
		printf("%d * %d = %d\n", n, i, n * i);
	}
}

void Menu() //메뉴 출력 함수
{
	printf("1. 구구단 출력하기\n");
	printf("2. 원하는 단 출력하기\n");
	printf("3. 종료\n");
	printf("1, 2, 3중 택 1: ");
}

int main(void)
{
	int c, N;
	while (1) // 종료 전까지 반복
	{
		Menu(); //메뉴 출력
		scanf("%d", &c);
		if (c == 1) //1번 선택 시
		{
			for (int i = 1; i <= 9; i++) //1~9단 출력
			{
				print99(i);
				printf("\n");
			}
		}
		else if (c == 2) //2번 입력 시
		{
			printf("원하는 단을 입력하세요: ");
			scanf("%d", &N); //사용자 입력 받기
			if (N >= 1 && N <= 9) //1~9단만 출력
			{
				print99(N);
				printf("\n");
			}
			else //잘못 입력 시
			{
				printf("1~9 사이의 숫자를 입력하세요.\n\n");
			}
		}
		else if (c == 3) //3번 입력 시 종료
		{
			break;
		}
		else //잘못 입력 시
		{
			printf("잘못된 입력입니다.\n\n");
		}
	}
}