#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int cctgame()
{
	srand(time(NULL));

	int mtime; //momorize time
	int amount; // �ܿ� ������ ����
	int rprocess[2];//random process
	int rnumber; //���� ���ڸ� ���ϴº���
	int numbers[25] = { 0 }; // ��� ������ �Ųٷ� �ϱ� ���� ���� �迭
	int current = 0;//���� �ε��� Ȯ�� ��ø�ݺ������� ����ϱ� ���� ���� ����
	int correct=0;
	int wrong=0;
	int key;

	int test; // �亯 �Է� ����

	int test_order; // �亯 �Է� ����

	system("cls"); // ȭ���� ����
	printf("�Ųٷ� ���� �ܿ��!\n");
	printf("������ ������ ������ �ݴ�� �ܿ��� �մϴ�.\n");
	printf("ex : 1 3 5, answer : 5 3 1\n\n");
	printf("\n����! �޸����̳� ��Ʈ�� ���ڸ� ���ų� ȭ���� �Ͻ� �����ϸ� ȿ���� �����ϴ�.\n\n\n");

	for (;;)
	{
		printf("�ܿ� ������ ������ �Է����ּ���.(5��~25��)");
		scanf("%d", &amount);
		while (getchar() != '\n');//�Է¹��۸� ���������μ� ���ѷ��� ����

		if (amount >= 5 && amount <= 25)
		{
			break;
		}
		else
		{
			printf("�߸��Է��ϼ̽��ϴ�.");
			continue;
		}
	}

	for (;;)
	{
		printf("���� �ϳ��� �ܿ� �ð��� �Է����ּ���.(1��~5��)");
		scanf("%d", &mtime);
		while (getchar() != '\n');//���Ͱ� �ƴҶ����� �Է��� ����

		if (mtime >= 1 && mtime <= 5)
		{
			break;
		}
		else
		{
			printf("�߸��Է��ϼ̽��ϴ�.");
			continue;
		}
	}


	system("cls");
	printf("���ڸ� �̾ƿ��� ���Դϴ�....");

	for (int i = 0; i < amount; i++)
	{
		rprocess[0] = rand() % 40 + 1;//���� ����1
		rprocess[1] = rand() % 40 + 1;//���� ����2 ���� ������ ���� �ϱ� ���� ������ �ι� ����
		rnumber = (rprocess[0]+rprocess[1])%25+1; // ���

		numbers[i] = rnumber; // ����� �迭�� ����

		

		for (int j = 0; j < i; j++) // �ߺ��Ǵ� ���ڰ� ������ �˻��ϴ� �ݺ���
		{
			
			if (i == j)
				continue;//�Ȱ��� ��ġ�� �ִ� ���� ���ϴ� ���� �����ϱ� ���� ��Ƽ��

			if (numbers[i] == numbers[j]) // �ߺ��� �ִٸ�
			{
				i--;
				break;
			}
			Sleep(10);//�ε��ΰ�ó�� ����� ���� SLeep�� ����
		}
	}

	system("cls");
	printf("�Ϸ�Ǿ����ϴ�.\n");
	system("pause");

	for (int i=0; i<amount; i++)
	{
		system("cls");
		printf("%d", numbers[i]);
		Sleep(mtime * 1000);
	}

	

	test_order = amount;
	for (int i=amount-1; i>=0; i--)
	{
		system("cls");
		printf("%d��° ���ڸ� �Է��ϼ���.",test_order);
		scanf("%d",&test);

		if (test == numbers[i])
		{
			correct += 1;
		}
		else
		{
			wrong += 1;
		}

		test_order -= 1;
	}

	test_order = 1;

	system("cls");

	printf("���� : %d, ���� : %d, ������ : %.2f%%\n",correct,wrong,((float)correct/amount)*100);//��� ǥ��, ����ȯ
	for (int i = test_order; i <= amount; i++)
	{
		printf("%d��° ���� : %d\n",i,numbers[i-1]);
	}


	system("pause");
}