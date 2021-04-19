#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void timergame()
{
	static int win = 0;
	static int lose = 0;
	int k = 0;
	int timer;
	int random;

	system("cls");
	printf("숫자가 0일 때 누르면 성공하는 게임!\n");
	printf("시작하려면 아무키나 누르세요.\n");
	printf("성공 : %d", win);
	printf("실패 : %d\n", lose);
	getch();

	//0이 나왔을때 아무키나 눌러서 타이밍 맞추는 게임
	srand(time(NULL));
	getch();
	for (timer = 10; timer >= -1; timer--)
	{

		system("cls");
		printf("%d", timer);

		random = rand() % 50 + 1;
		Sleep(random);

		if (kbhit())
		{
			break;
		}
	}

	if (timer==0)
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