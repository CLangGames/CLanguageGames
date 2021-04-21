#include <stdio.h>
#include <conio.h>
#include <windows.h>

void timergame()
{
	static int win=0; // 정적변수를 사용하여 다시 들어가도 성공 실패 횟수가 그대로 됨
	static int lose=0;
	int k = 0;
	int timer;
	int random;


	system("cls");//화면을 지워줌
	printf("숫자가 0일 때 누르면 성공하는 게임!\n");
	printf("성공 : %d", win);
	printf("\t실패 : %d\n", lose);
	system("pause");

	//0이 나왔을때 아무키나 눌러서 타이밍 맞추는 게임
	srand(time(NULL));
	for (timer = 10; timer >= -1; timer--) // 카운트다운
	{
		system("cls");
		printf("%d", timer);

		random = rand() % 50 + 1;
		Sleep(random);

		if (kbhit()) break; //키를 누른것이 인식되면 반복문을 벗어남
	}

	if (timer == 0) // 성공 실패 판정
	{
		printf("성공!\n");
		win++;
	}
	else
	{
		printf("실패!\n");
		lose++;
	}
	system("pause");
}