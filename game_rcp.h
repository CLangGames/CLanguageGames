#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

void rcsgame()
{
	srand(time(NULL));
	// 0 가위 1 바위 2 보
	// 0 < 1	1 < 2	2 < 0

	int myhand;
	int ehand;

	system("cls");
	printf("컴퓨터를 이기면 되는 가위바위보입니다.\n");
	printf("원하는 것이 나왔을 때 키를 누르면 됩니다.\n");
	system("pause");

	while (1)//원하는 것을 선택하기 위해 무한 반복문을 씀
	{
		system("cls");
		myhand = 0;
		printf("가위\n");
		Sleep(700);
		if (kbhit()) break;

		system("cls");
		myhand = 1;
		printf("바위\n");
		Sleep(700);
		if (kbhit()) break;

		system("cls");
		myhand = 2;
		printf("보\n");
		Sleep(700);
		if (kbhit()) break;

		
	}

	ehand = rand() % 3;

	
	if (ehand == 0)
	{
		printf("상대 : 가위\n");
	}
	else if (ehand == 1)
	{
		printf("상대 : 바위\n");
	}
	else
	{
		printf("상대 : 보\n");
	}

	if (ehand == myhand)
	{
		printf("무승부!!\n");
	}
	else if ((myhand-ehand==-1)|| (myhand - ehand == 2))
	{
		printf("패배!!\n");
	}
	else
	{
		printf("승리!!\n");
	}


	system("pause");
}
