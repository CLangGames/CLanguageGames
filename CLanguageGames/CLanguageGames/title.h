#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include "games.h"

void menu() {
	system("cls");
	printf("1.Ÿ�̹� ���߱�\n2.����������\n3.�����\n4.�Ųٷ� ���� �ܿ��\n5.���ڿ� ����ϱ�\n6.������");
}

void title()
{
	while (1)
	{
		system("cls");
		printf("�����������������\n"); //������
		printf("----------C��� ���ӵ�----------\n");
		printf("�����������������\n");
		printf("�����Ϸ��� �ƹ�Ű�� �����ʽÿ�.");
		Sleep(100);
		system("cls");
		printf("�����������������\n"); //���ٰ� �Ʒ����� �ٲ�
		printf("----------C��� ���ӵ�----------\n"); // �������� ��ó�� ���̰� ��
		printf("�����������������\n");
		printf("�����Ϸ��� �ƹ�Ű�� �����ʽÿ�.");
		Sleep(100);
		if (kbhit())
		{
			menu();//����� ����ϴ� �Լ�
			getch();//pause�� ���� Ÿ��Ʋ ȿ���� ����Ÿ���� ������ getch�� ��
			int a = getch();
			if (a == '1') timergame();// ���� ����Ű�� ���� ���ڿ� �ش��ϴ� ���ӿ� ����
			else if (a == '2')rcsgame();
			else if (a == '3')mjb();
			else if (a == '4')cctgame();
			else if (a == '5')gnumber();
			else if (a == '6') play_yut();
			else continue;//�� ���� Ű�� ������ ��� ó������ ���ư�
		}

	}
}