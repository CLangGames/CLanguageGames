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
	printf("��ǻ�͸� �̱�� �Ǵ� ������Դϴ�.\n");
	printf("���ϴ� ���� ���ڸ� �����ø� �˴ϴ�..\n");
	system("pause");
	a:
	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			system("cls");
			if(i==0) printf("��� : ����\n");
			else if(i==1) printf("��� : ����\n");
			else printf("��� : ��\n");
			printf("���� : 1	���� : 2	�� : 3\n");
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
		printf("���º�!!\n");
		Sleep(1500);
		goto a;//�ٽ� ������������ �ϱ� ���� ���ư�
	}
	else if ((myhand - ehand == -1) || (myhand - ehand == 2))
	{
		turn = 0;
		printf("�й�!!\n");
		Sleep(1500);
	}
	else
	{
		turn = 1;
		printf("�¸�!!\n");
		Sleep(1500);
	}

	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			system("cls");
			if(i==0) printf("��� : ����\n");
			else if(i==1) printf("��� : ����\n");
			else printf("��� : ��\n");
			printf("���� : 1	���� : 2	�� : 3\n");
			Sleep(15);
		}
		
		if (kbhit())
		{
			myhand = getch();
			if (myhand == '1' || myhand == '2' || myhand == '3')
			{
				after_rcp();
				if (myhand == ehand)//���� ��밡 ������ ������ ����
				{
					if (turn == 0) printf("�й�!!!\n");
					else printf("�¸�!!!\n");
					Sleep(1500);
					system("pause");
					break;
				}
				else//�ٸ��ٸ� ���� �������� ����
				{
					if ((myhand - ehand == -1) || (myhand - ehand == 2))
					{
						printf("����� ���Դϴ�.");
						turn = 0;
					}
					else
					{
						printf("����� ���Դϴ�.");
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