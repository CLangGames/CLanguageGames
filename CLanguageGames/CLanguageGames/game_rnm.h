#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int mtime; //momorize time
int amount; // 외울 숫자의 개수
int rprocess[2];//random process
int rnumber; //랜덤 숫자를 정하는변수
int numbers[25] = { 0 }; // 출력 순서를 거꾸로 하기 위해 만든 배열
int correct = 0;
int wrong = 0;
float radio;//정답 비율

int test; // 답변 입력 변수

int test_order; // 답변 입력 순서

//함수 목록
void start();
int scanamount();
int scantime();
void number_spin();
void memorizing();
void testing();
void ending();


int cctgame()
{
	int* win = &correct;//전역변수 포인터 선언
	int* lose = &wrong;

	*win = 0;//0으로 초기화 함으로써 맞고 틀린 갯수가
	*lose = 0;//누적이 되버리는 것을 방지

	start();
	amount = scanamount();
	mtime = scantime();
	number_spin();
	memorizing();
	testing();
	ending();
}

void start()
{
	srand(time(NULL));
	system("cls"); // 화면을 지움
	printf("거꾸로 숫자 외우기!\n");
	printf("나오는 숫자의 순서의 반대로 외워야 합니다.\n");
	printf("ex : 1 3 5, answer : 5 3 1\n\n");
	printf("\n주의! 메모장이나 노트에 숫자를 쓰거나 화면을 일시 정지하면 효과가 없습니다.\n\n\n");
}

int scantime()
{
	int mtime;

	for (;;)
	{
		printf("숫자 하나당 외울 시간을 입력해주세요.(1초~5초)");
		scanf("%d", &mtime);
		while (getchar() != '\n');

		if (mtime >= 1 && mtime <= 5)
		{
			return mtime;
		}
		else
		{
			printf("잘못입력하셨습니다.");
			continue;
		}
	}
}

int scanamount()
{
	for (;;)
	{
		printf("외울 숫자의 개수를 입력해주세요.(5개~25개)");
		scanf("%d", &amount);
		while (getchar() != '\n');//입력버퍼를 지워줌으로서 무한루프 방지

		if (amount >= 5 && amount <= 25)
		{
			return amount;
		}
		else
		{
			printf("잘못입력하셨습니다.");
			continue;
		}
	}
}

void number_spin()
{
	system("cls");
	printf("숫자를 뽑아오는 중입니다....");

	for (int i = 0; i < amount; i++)
	{
		rprocess[0] = rand() % 40 + 1;//랜덤 과정1
		rprocess[1] = rand() % 40 + 1;//랜덤 과정2 숫자 분포를 골고루 하기 위해 랜덤을 두번 돌림
		rnumber = (rprocess[0] + rprocess[1]) % 25 + 1; // 결과

		numbers[i] = rnumber; // 결과를 배열에 저장



		for (int j = 0; j < i; j++) // 중복되는 숫자가 없는지 검사하는 반복문
		{

			if (i == j)
				continue;//똑같은 위치에 있는 수를 비교하는 것을 방지하기 위해 콘티뉴

			if (numbers[i] == numbers[j]) // 중복이 있다면
			{
				i--;
				continue;
			}
			Sleep(10);//로딩인것처럼 만들기 위해 SLeep를 넣음
		}
	}

	system("cls");
	printf("완료되었습니다.\n");
	system("pause");
}

void memorizing()
{
	for (int i = 0; i < amount; i++)
	{
		system("cls");
		printf("%d", numbers[i]);
		Sleep(mtime * 1000);//1000을 곱해 입력한 초만큼 Sleep을 하게 함
	}
}

void testing()
{
	test_order = amount;
	for (int i = amount - 1; i >= 0; i--)//마지막 숫자부터 입력받음
	{
		system("cls");
		printf("%d번째 숫자를 입력하세요.", test_order);
		scanf("%d", &test);

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
}

void ending()
{
	radio = ((float)correct / amount) * 100;//형 변환

	FILE* record;//파일 포인터
	record = fopen("rnm_record.txt", "a");//원래 있던 파일 내용에 내용을 추가하는 권한

	system("cls");

	printf("정답 : %d, 오답 : %d, 정답율 : %.2f%%\n", correct, wrong, radio);//결과 표시
	for (int i = test_order; i <= amount; i++)
	{
		printf("%d번째 정답 : %d\n", i, numbers[i - 1]);
	}

	fprintf(record, "%d개 중 %d개 맞음 정답율 : %.2f%%	1개당 %d초\n", amount, correct, radio, mtime);
	//파일에 내용 추가
	fclose(record);//파일을 닫음

	printf("그동안의 기록을 보시려면 rnm_record.txt파일을 여십시오.\n");


	system("pause");
}