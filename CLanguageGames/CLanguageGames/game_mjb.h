#include <stdio.h>
#include <conio.h>
#include <windows.h>
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
	a:
	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			system("cls");
			if(i==0) printf("상대 : 가위\n");
			else if(i==1) printf("상대 : 바위\n");
			else printf("상대 : 보\n");
			printf("가위 : 1	바위 : 2	보 : 3\n");
			Sleep(15);
		}

		if (kbhit())
		{
			myhand = getch();
			if (myhand == '1' || myhand == '2' || myhand == '3')
			{
				after_rcp();
				Sleep(1000);
				break;
			}
			else continue;
		}
	}

	if (ehand == myhand)
	{
		printf("무승부!!\n");
		Sleep(1500);
		goto a;//다시 가위바위보를 하기 위해 돌아감
	}
	else if ((myhand - ehand == -1) || (myhand - ehand == 2))
	{
		turn = 0;
		printf("패배!!\n");
		Sleep(1500);
	}
	else
	{
		turn = 1;
		printf("승리!!\n");
		Sleep(1500);
	}

	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			system("cls");
			if(i==0) printf("상대 : 가위\n");
			else if(i==1) printf("상대 : 바위\n");
			else printf("상대 : 보\n");
			printf("가위 : 1	바위 : 2	보 : 3\n");
			Sleep(15);
		}
		
		if (kbhit())
		{
			myhand = getch();
			if (myhand == '1' || myhand == '2' || myhand == '3')
			{
				after_rcp();
				if (myhand == ehand)//나와 상대가 같으면 게임을 끝냄
				{
					if (turn == 0) printf("패배!!!\n");
					else printf("승리!!!\n");
					Sleep(1500);
					system("pause");
					break;
				}
				else//다르다면 누가 공격인지 판정
				{
					if ((myhand - ehand == -1) || (myhand - ehand == 2))
					{
						printf("상대의 턴입니다.");
						turn = 0;
					}
					else
					{
						printf("당신의 턴입니다.");
						turn = 1;
					}
					Sleep(1000);
					continue;
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