#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int mtime; //momorize time
int amount; // �ܿ� ������ ����
int rprocess[2];//random process
int rnumber; //���� ���ڸ� ���ϴº���
int numbers[25] = { 0 }; // ��� ������ �Ųٷ� �ϱ� ���� ���� �迭
int correct = 0;
int wrong = 0;
float radio;//���� ����

int test; // �亯 �Է� ����

int test_order; // �亯 �Է� ����

//�Լ� ���
void start();
int scanamount();
int scantime();
void number_spin();
void memorizing();
void testing();
void ending();


int cctgame()
{
	int* win = &correct;//�������� ������ ����
	int* lose = &wrong;

	*win = 0;//0���� �ʱ�ȭ �����ν� �°� Ʋ�� ������
	*lose = 0;//������ �ǹ����� ���� ����

	start();
	amount = scanamount();
	mtime = scantime();
	number_spin();
	memorizing();
	testing();
	ending();
}

void start()
{
	srand(time(NULL));
	system("cls"); // ȭ���� ����
	printf("�Ųٷ� ���� �ܿ��!\n");
	printf("������ ������ ������ �ݴ�� �ܿ��� �մϴ�.\n");
	printf("ex : 1 3 5, answer : 5 3 1\n\n");
	printf("\n����! �޸����̳� ��Ʈ�� ���ڸ� ���ų� ȭ���� �Ͻ� �����ϸ� ȿ���� �����ϴ�.\n\n\n");
}

int scantime()
{
	int mtime;

	for (;;)
	{
		printf("���� �ϳ��� �ܿ� �ð��� �Է����ּ���.(1��~5��)");
		scanf("%d", &mtime);
		while (getchar() != '\n');

		if (mtime >= 1 && mtime <= 5)
		{
			return mtime;
		}
		else
		{
			printf("�߸��Է��ϼ̽��ϴ�.");
			continue;
		}
	}
}

int scanamount()
{
	for (;;)
	{
		printf("�ܿ� ������ ������ �Է����ּ���.(5��~25��)");
		scanf("%d", &amount);
		while (getchar() != '\n');//�Է¹��۸� ���������μ� ���ѷ��� ����

		if (amount >= 5 && amount <= 25)
		{
			return amount;
		}
		else
		{
			printf("�߸��Է��ϼ̽��ϴ�.");
			continue;
		}
	}
}

void number_spin()
{
	system("cls");
	printf("���ڸ� �̾ƿ��� ���Դϴ�....");

	for (int i = 0; i < amount; i++)
	{
		rprocess[0] = rand() % 40 + 1;//���� ����1
		rprocess[1] = rand() % 40 + 1;//���� ����2 ���� ������ ���� �ϱ� ���� ������ �ι� ����
		rnumber = (rprocess[0] + rprocess[1]) % 25 + 1; // ���

		numbers[i] = rnumber; // ����� �迭�� ����



		for (int j = 0; j < i; j++) // �ߺ��Ǵ� ���ڰ� ������ �˻��ϴ� �ݺ���
		{

			if (i == j)
				continue;//�Ȱ��� ��ġ�� �ִ� ���� ���ϴ� ���� �����ϱ� ���� ��Ƽ��

			if (numbers[i] == numbers[j]) // �ߺ��� �ִٸ�
			{
				i--;
				continue;
			}
			Sleep(10);//�ε��ΰ�ó�� ����� ���� SLeep�� ����
		}
	}

	system("cls");
	printf("�Ϸ�Ǿ����ϴ�.\n");
	system("pause");
}

void memorizing()
{
	for (int i = 0; i < amount; i++)
	{
		system("cls");
		printf("%d", numbers[i]);
		Sleep(mtime * 1000);//1000�� ���� �Է��� �ʸ�ŭ Sleep�� �ϰ� ��
	}
}

void testing()
{
	test_order = amount;
	for (int i = amount - 1; i >= 0; i--)//������ ���ں��� �Է¹���
	{
		system("cls");
		printf("%d��° ���ڸ� �Է��ϼ���.", test_order);
		scanf("%d", &test);

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
}

void ending()
{
	radio = ((float)correct / amount) * 100;//�� ��ȯ

	FILE* record;//���� ������
	record = fopen("rnm_record.txt", "a");//���� �ִ� ���� ���뿡 ������ �߰��ϴ� ����

	system("cls");

	printf("���� : %d, ���� : %d, ������ : %.2f%%\n", correct, wrong, radio);//��� ǥ��
	for (int i = test_order; i <= amount; i++)
	{
		printf("%d��° ���� : %d\n", i, numbers[i - 1]);
	}

	fprintf(record, "%d�� �� %d�� ���� ������ : %.2f%%	1���� %d��\n", amount, correct, radio, mtime);
	//���Ͽ� ���� �߰�
	fclose(record);//������ ����

	printf("�׵����� ����� ���÷��� rnm_record.txt������ ���ʽÿ�.\n");


	system("pause");
}