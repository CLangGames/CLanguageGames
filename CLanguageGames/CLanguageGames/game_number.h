#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

int gnumber()
{
	char numbers[25];//�޸� �뷮�� ���̱� char���� ��
	char question;
	int amount;
	int a_amount = 0;
	int mtime;
	int answer;


	system("cls");
	printf("���� ���� �ܿ��\n");
	printf("���ڿ��� �� �� �ش� ������ ������ ������մϴ�.\n");
	printf("ex) '1234446889165'�� 4�� ���� : 4\n");
	system("pause");

	system("cls");

	srand(time(NULL));
	for (;;)
	{
		printf("�ܿ� ������ ������ �Է����ּ���.(10~40��)\n");
		scanf("%d", &amount);

		if (amount >= 10 && amount <= 40)
			break;
		else
			printf("�߸��Է��ϼ̽��ϴ�.");
		continue;
	}



	for (;;)
	{
		printf("�ܿ� ������ ������ �Է����ּ���.(1~60��)\n");
		scanf("%d", &mtime);

		if (mtime >= 1 && mtime <= 60)
			break;
		else
			printf("�߸��Է��ϼ̽��ϴ�.");
		continue;
	}

	system("cls");
	for (int i = 0; i < amount; i++)
	{
		numbers[i] = rand() % 10 + 48; // �ƽ�Ű�ڵ忡�� 48 ~ 57���� ����
		printf("%c", numbers[i]);
	}
	question = rand() % 10 + 48;


	for (int i = 0; i < amount; i++)
		if (question == numbers[i])
			a_amount++;

	Sleep(mtime * 1000);

	system("cls");
	printf("%c�� ������?\n", question);
	scanf("%d", &answer);

	if (answer == a_amount)
		printf("����!!\n");
	else
		printf("����!!\n");

	for (int i = 0; i < amount; i++)
	{
		printf("%c", numbers[i]);
	}
	printf("\n %c�� ���� : %d��", question, a_amount);

	Sleep(2000);
}