#include <stdio.h>
#include <conio.h>
#include <time.h>

void rcsgame()
{
	srand(time(NULL));
	// 0 ���� 1 ���� 2 ��

	int myhand, ehand;

	system("cls");
	printf("��ǻ�͸� �̱�� �Ǵ� �����������Դϴ�.\n");
	printf("���ϴ� ���� ������ �� Ű�� ������ �˴ϴ�.\n");
	system("pause");

	while (1)//���ϴ� ���� �����ϱ� ���� ���� �ݺ����� ��
	{
		for (int i = 0; i < 3; i++)
		{
			system("cls");
			myhand = i;
			if(i==0) printf("����\n");
			else if(i==1)printf("����\n");
			else printf("��\n");
			Sleep(700);	
			if (kbhit()) break;
		}
		if (kbhit()) break;
	}

	ehand = rand() % 3;

	if (ehand == 0) printf("��� : ����\n");
	else if (ehand == 1) printf("��� : ����\n");
	else printf("��� : ��\n");

	if (ehand == myhand) printf("���º�!!\n");
	else if ((myhand-ehand==-1)|| (myhand - ehand == 2)) printf("�й�!!\n");
	else printf("�¸�!!\n");

	system("pause");
}
