#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include "games.h"

void menu() {
	system("cls");
	printf("1.����\n2.Ÿ�ָ̹��߱�\n3.����������\n4.�����\n5.�Ųٷ� ���� �ܿ��\n6.���ڿ� �ܿ��");
}
void title()
{
	static char title[40];

	while (1)
	{
		system("cls");
		printf("�����������������\n");
		printf("----------C��� ���ӵ�----------\n");
		printf("�����������������\n");
		printf("�����Ϸ��� �ƹ�Ű�� �����ʽÿ�.");
		Sleep(100);
		system("cls");
		printf("�����������������\n");
		printf("----------C��� ���ӵ�----------\n");
		printf("�����������������\n");
		printf("�����Ϸ��� �ƹ�Ű�� �����ʽÿ�.");
		Sleep(100);

		if (kbhit())
		{
			
			menu();
			getch();
			int a = getch();
			if (a == '1') {
				system("cls");
			}
			else if (a == '2') timergame();
			else if (a == '3')rcsgame();
			else if (a == '4')mjb();
			else if (a == '5')cctgame();
			else if (a == '6')gnumber();
			else continue;
		}

	}
}