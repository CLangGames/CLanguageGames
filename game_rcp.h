#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

void rcsgame()
{
	srand(time(NULL));
	// 0 ���� 1 ���� 2 ��
	// 0 < 1	1 < 2	2 < 0

	int myhand;
	int ehand;

	system("cls");
	printf("��ǻ�͸� �̱�� �Ǵ� �����������Դϴ�.\n");
	printf("���ϴ� ���� ������ �� Ű�� ������ �˴ϴ�.\n");
	system("pause");

	while (1)//���ϴ� ���� �����ϱ� ���� ���� �ݺ����� ��
	{
		system("cls");
		myhand = 0;
		printf("����\n");
		Sleep(700);
		if (kbhit()) break;

		system("cls");
		myhand = 1;
		printf("����\n");
		Sleep(700);
		if (kbhit()) break;

		system("cls");
		myhand = 2;
		printf("��\n");
		Sleep(700);
		if (kbhit()) break;

		
	}

	ehand = rand() % 3;

	
	if (ehand == 0)
	{
		printf("��� : ����\n");
	}
	else if (ehand == 1)
	{
		printf("��� : ����\n");
	}
	else
	{
		printf("��� : ��\n");
	}

	if (ehand == myhand)
	{
		printf("���º�!!\n");
	}
	else if ((myhand-ehand==-1)|| (myhand - ehand == 2))
	{
		printf("�й�!!\n");
	}
	else
	{
		printf("�¸�!!\n");
	}


	system("pause");
}
