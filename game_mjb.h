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
	printf("��ǻ�͸� �̱�� �Ǵ� ������Դϴ�.\n");
	printf("���ϴ� ���� ���ڸ� �����ø� �˴ϴ�..\n");
	system("pause");


	while (1)
	{
		myhand = '5';
		system("cls");
		printf("��� : ����\n");
		printf("���� : 1	���� : 2	�� : 3\n");
		Sleep(15);
		system("cls");
		printf("��� : ����\n");
		printf("���� : 1	���� : 2	�� : 3\n");
		Sleep(15);
		system("cls");
		printf("��� : ��\n");
		printf("���� : 1	���� : 2	�� : 3\n");
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
		printf("���º�!!\n");
		Sleep(2000);
	}
	else if ((myhand - ehand == -1) || (myhand - ehand == 2))
	{
		turn = 0;
		printf("�й�!!\n");
	}
	else
	{
		turn = 1;
		printf("�¸�!!\n");
	}

	while (1)
	{
		myhand = '\0';
		system("cls");
		if (ehand == 1)
		{
			ehand = '1';
			printf("��� : ����\n");
		}
		else if (ehand == 2)
		{
			ehand = '2';
			printf("��� : ����\n");
		}
		else
		{
			ehand = '3';
			printf("��� : ��\n");
		}

		printf("���� : 1	���� : 2	�� : 3\n");
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
						printf("�й�!!!");
					}
					else
					{
						printf("�¸�!!!");
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

		printf("�� : ����\n");
	}
	else if (myhand == '2')
	{
		printf("�� : ����\n");
	}
	else
	{
		printf("�� : ��\n");
	}

	ehand = rand() % 3 + 1;

	if (ehand == 1)
	{
		ehand = '1';
		printf("��� : ����\n");
	}
	else if (ehand == 2)
	{
		ehand = '2';
		printf("��� : ����\n");
	}
	else
	{
		ehand = '3';
		printf("��� : ��\n");
	}
}