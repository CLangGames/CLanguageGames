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
	printf("���ڰ� 0�� �� ������ �����ϴ� ����!\n");
	printf("�����Ϸ��� �ƹ�Ű�� ��������.\n");
	printf("���� : %d", win);
	printf("���� : %d\n", lose);
	getch();

	//0�� �������� �ƹ�Ű�� ������ Ÿ�̹� ���ߴ� ����
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
		printf("����!\n");
		win++;
	}
	else
	{
		printf("����!\n");
		lose++;
	}

	system("pause");
}