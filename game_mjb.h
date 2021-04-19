#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
char myhand;
char ehand2;
int ehand;
void after_rcp();
int turn=0;

void mjb()
{
	srand(time(NULL));

	system("cls");
	printf("컴퓨터를 이기면 되는 묵찌빠입니다.\n");
	printf("원하는 것의 숫자를 누르시면 됩니다..\n");
	system("pause");


	while (1)
	{
		myhand = '5';
		system("cls");
		printf("상대 : 가위\n");
		printf("가위 : 1	바위 : 2	보 : 3\n");
		Sleep(15);
		system("cls");
		printf("상대 : 바위\n");
		printf("가위 : 1	바위 : 2	보 : 3\n");
		Sleep(15);
		system("cls");
		printf("상대 : 보\n");
		printf("가위 : 1	바위 : 2	보 : 3\n");
		Sleep(15);


		if (kbhit())
		{
			myhand = getch();
			if (myhand == '1' || myhand == '2' || myhand == '3')
				after_rcp();
				Sleep(3000);
				break;
		}
	}


	if (ehand == myhand)
	{
		printf("무승부!!\n");
		Sleep(2000);
	}
	else if ((myhand - ehand == -1) || (myhand - ehand == 2))
	{
		turn = 0;
		printf("패배!!\n");
	}
	else
	{
		turn = 1;
		printf("승리!!\n");
	}

	while (1)
	{
		myhand = '\0';
		system("cls");
		if (ehand == 1)
		{
			ehand = '1';
			printf("상대 : 가위\n");
		}
		else if (ehand == 2)
		{
			ehand = '2';
			printf("상대 : 바위\n");
		}
		else
		{
			ehand = '3';
			printf("상대 : 보\n");
		}

		printf("가위 : 1	바위 : 2	보 : 3\n");
		if (kbhit())
		{
			ehand = rand() % 3 + 1;
			myhand = getch();
			if (myhand == '1' || myhand == '2' || myhand == '3')
			{
				after_rcp();
				if (myhand == ehand)
				{
					if (turn == 0)
					{
						printf("패배!!!");
					}
					else
					{
						printf("승리!!!");
					}
					break;
					system("pause");
				}
				else
				{
					if ((myhand - ehand == -1) || (myhand - ehand == 2))
					{
						turn = 0;
						Sleep(1000);
						continue;
					}
					else
					{
						turn = 1;
						Sleep(1000);
						continue;
					}
				}

			}
		}
	}
}

void after_rcp()
{
	system("cls");
	if (myhand == '1')
	{

		printf("나 : 가위\n");
	}
	else if (myhand == '2')
	{
		printf("나 : 바위\n");
	}
	else
	{
		printf("나 : 보\n");
	}

	ehand = rand() % 3 + 1;

	if (ehand == 1)
	{
		ehand = '1';
		printf("상대 : 가위\n");
	}
	else if (ehand == 2)
	{
		ehand = '2';
		printf("상대 : 바위\n");
	}
	else
	{
		ehand = '3';
		printf("상대 : 보\n");
	}
}