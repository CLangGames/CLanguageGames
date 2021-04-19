#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int cctgame()
{
	srand(time(NULL));

	int mtime; //momorize time
	int amount; // 외울 숫자의 개수
	int rprocess[2];//random process
	int rnumber; //랜덤 숫자를 정하는변수
	int numbers[25] = { 0 }; // 출력 순서를 거꾸로 하기 위해 만든 배열
	int current = 0;//현재 인덱스 확인 중첩반복문에서 사용하기 위해 만든 변수
	int correct=0;
	int wrong=0;
	int key;

	int test; // 답변 입력 변수

	int test_order; // 답변 입력 순서

	system("cls"); // 화면을 지움
	printf("거꾸로 숫자 외우기!\n");
	printf("나오는 숫자의 순서의 반대로 외워야 합니다.\n");
	printf("ex : 1 3 5, answer : 5 3 1\n\n");
	printf("\n주의! 메모장이나 노트에 숫자를 쓰거나 화면을 일시 정지하면 효과가 없습니다.\n\n\n");

	for (;;)
	{
		printf("외울 숫자의 개수를 입력해주세요.(5개~25개)");
		scanf("%d", &amount);
		while (getchar() != '\n');//입력버퍼를 지워줌으로서 무한루프 방지

		if (amount >= 5 && amount <= 25)
		{
			break;
		}
		else
		{
			printf("잘못입력하셨습니다.");
			continue;
		}
	}

	for (;;)
	{
		printf("숫자 하나당 외울 시간을 입력해주세요.(1초~5초)");
		scanf("%d", &mtime);
		while (getchar() != '\n');//엔터가 아닐때까지 입력을 받음

		if (mtime >= 1 && mtime <= 5)
		{
			break;
		}
		else
		{
			printf("잘못입력하셨습니다.");
			continue;
		}
	}


	system("cls");
	printf("숫자를 뽑아오는 중입니다....");

	for (int i = 0; i < amount; i++)
	{
		rprocess[0] = rand() % 40 + 1;//랜덤 과정1
		rprocess[1] = rand() % 40 + 1;//랜덤 과정2 숫자 분포를 골고루 하기 위해 랜덤을 두번 돌림
		rnumber = (rprocess[0]+rprocess[1])%25+1; // 결과

		numbers[i] = rnumber; // 결과를 배열에 저장

		

		for (int j = 0; j < i; j++) // 중복되는 숫자가 없는지 검사하는 반복문
		{
			
			if (i == j)
				continue;//똑같은 위치에 있는 수를 비교하는 것을 방지하기 위해 콘티뉴

			if (numbers[i] == numbers[j]) // 중복이 있다면
			{
				i--;
				break;
			}
			Sleep(10);//로딩인것처럼 만들기 위해 SLeep를 넣음
		}
	}

	system("cls");
	printf("완료되었습니다.\n");
	system("pause");

	for (int i=0; i<amount; i++)
	{
		system("cls");
		printf("%d", numbers[i]);
		Sleep(mtime * 1000);
	}

	

	test_order = amount;
	for (int i=amount-1; i>=0; i--)
	{
		system("cls");
		printf("%d번째 숫자를 입력하세요.",test_order);
		scanf("%d",&test);

		if (test == numbers[i])
		{
			correct += 1;
		}
		else
		{
			wrong += 1;
		}

		test_order -= 1;
	}

	test_order = 1;

	system("cls");

	printf("정답 : %d, 오답 : %d, 정답율 : %.2f%%\n",correct,wrong,((float)correct/amount)*100);//결과 표시, 형변환
	for (int i = test_order; i <= amount; i++)
	{
		printf("%d번째 정답 : %d\n",i,numbers[i-1]);
	}


	system("pause");
}