#include <stdio.h>   // �ۡۡۡۡ�==5  �ܡܡܡܡ� == 9;
#include <windows.h>
#include <conio.h>	//console and port I/O

int arr[20][20];

void f1() // �� ù�� ���� 
{
	if (arr[0][0] == 0)
		printf("�� ");
	else if (arr[0][0] == 5)
		printf("��");
	else if (arr[0][0] == 9)
		printf("��");
}
void f2() // �� ù�� �߰� (18��)
{
	for (int i = 1; i <= 18; i++)
		if (arr[0][i] == 0)
			printf("�� ");
		else if (arr[0][i] == 5)
			printf("��");
		else if (arr[0][i] == 9)
			printf("��");
}
void f3() // �� ù�� �ݱ�
{
	if (arr[0][19] == 0)
		printf("�� ");
	else if (arr[0][19] == 5)
		printf("��");
	else if (arr[0][19] == 9)
		printf("��");
	printf("\n");
}
void middle()
{
	for (int i = 1; i < 19; i++)
	{
		if (arr[i][0] == 0) // �� 2~19��° ��  1��°ĭ ����
			printf("�� ");
		else if (arr[i][0] == 5)
			printf("��");
		else if (arr[i][0] == 9)
			printf("��");

		for (int j = 1; j < 19; j++)
		{
			if (arr[i][j] == 0) // 2~19��° �� 2~19°ĭ ���
				printf("�� ");
			else if (arr[i][j] == 5)
				printf("��");
			else if (arr[i][j] == 9)
				printf("��");

		}
		if (arr[i][19] == 0)// 2~18��°�� 20��° ĭ �ݱ�
			printf("�� ");
		else if (arr[i][19] == 5)
			printf("��");
		else if (arr[i][19] == 9)
			printf("��");

		printf("\n");
	}
}
void e1() // ������ �� ���� ��
{
	if (arr[19][0] == 0)
		printf("�� ");
	else if (arr[19][0] == 5)
		printf("��");
	else if (arr[19][0] == 9)
		printf("��");
}
void e2() // �������� �߰� �� 
{
	for (int i = 1; i <= 18; i++)
		if (arr[19][i] == 0)
			printf("�� ");
		else if (arr[19][i] == 5)
			printf("��");
		else if (arr[19][i] == 9)
			printf("��");
}
void e3() // �������� �ݱ� ��
{
	if (arr[19][19] == 0)
		printf("�� ");
	else if (arr[19][19] == 5)
		printf("��");
	else if (arr[19][19] == 9)
		printf("��");
	printf("\n");
}
void pan() // �Ʒ� �Լ����� ������ ���� �ʹ� ��⶧���� pan()�Լ��� ����
{
	f1();
	f2();
	f3();
	middle();
	e1();
	e2();
	e3();
}
int result_black() //�浹�� �¸��ߴ��� �Ǻ�
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
		{
			if (arr[i][j] == 5 && arr[i][j + 1] == 5 && arr[i][j + 2] == 5 && arr[i][j + 3] == 5 && arr[i][j + 4] == 5)
				// ���� 5�� �˻� 
			{
				pan();
				printf("�浹 �¸�!!!!\n");
				return 0;
			}
			if (arr[i][j] == 5 && arr[i + 1][j] == 5 && arr[i + 2][j] == 5 && arr[i + 3][j] == 5 && arr[i + 4][j] == 5)
				// ���� 5�� �˻�
			{
				pan();
				printf("�浹 �¸�!!!!\n");
				return 0;
			}
			if (arr[i][j] == 5 && arr[i + 1][j + 1] == 5 && arr[i + 2][j + 2] == 5 && arr[i + 3][j + 3] == 5 && arr[i + 4][j + 4] == 5)
				// ������ ���ΰ��� �밢�� (\) �˻�
			{
				pan();
				printf("�浹 �¸�!!!!\n");
				return 0;
			}
			if (arr[i][j] == 5 && arr[i - 1][j + 1] == 5 && arr[i - 2][j + 2] == 5 && arr[i - 3][j + 3] == 5 && arr[i - 4][j + 4] == 5)
				// ������ �Ʒ��� ���� �밢�� (/) �˻� 
			{
				pan();
				printf("�浹 �¸�!!!!\n");
				return 0;
			}
		}
}

int result_white()// �鵹�� �¸��ߴ��� �Ǻ�
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
		{
			if (arr[i][j] == 9 && arr[i][j + 1] == 9 && arr[i][j + 2] == 9 && arr[i][j + 3] == 9 && arr[i][j + 4] == 9)
				// ���� 5�� �˻�
			{
				pan();
				printf("�鵹 �¸�!!!!\n");
				return 0;
			}

			if (arr[i][j] == 9 && arr[i + 1][j] == 9 && arr[i + 2][j] == 9 && arr[i + 3][j] == 9 && arr[i + 4][j] == 9)
				// ���� 5�� �˻�
			{
				pan();
				printf("�鵹 �¸�!!!!\n");
				return 0;
			}

			if (arr[i][j] == 9 && arr[i + 1][j + 1] == 9 && arr[i + 2][j + 2] == 9 && arr[i + 3][j + 3] == 9 && arr[i + 4][j + 4] == 9)
				// ������ ���ΰ��� �밢�� (/) �˻�
			{
				pan();
				printf("�鵹 �¸�!!!!\n");
				return 0;
			}
			if (arr[i][j] == 9 && arr[i - 1][j + 1] == 9 && arr[i - 2][j + 2] == 9 && arr[i - 3][j + 3] == 9 && arr[i - 4][j + 4] == 9)
				// ������ �Ʒ��� ���� �밢�� (\) �˻� 
			{
				pan();
				printf("�鵹 �¸�!!!!\n");
				return 0;
			}
		}
}
void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 }; // coord ����ü ���� Pos ����� ���ÿ� �ʱ�ȭ
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); // �ֿܼ��� Pos�� ����� ��ǥ�� ��ġ �ٲٱ�
}
void key_move(int sw)
{
	static int x = 19; //���� ���� (ó�� 1���� �ʱ�ȭ)
	static int y = 10; //���� ���� (ó�� 1���� �ʱ�ȭ)
	int chr;
	gotoxy(x, y); // �ֿܼ��� Ŀ�� ��ġ �ٲٴ� �Լ�
	while (1) {
	rescan:
		chr = getch();
		if (kbhit()) {
			gotoxy(x, y);
			system("cls");
			pan();
			chr = getch();
			if (chr == 72) { //��
				y--;
				if (y < 1) y = 1;
			}
			else if (chr == 80) { //��
				y++;
				if (y > 20) y = 20;
			}
			else if (chr == 75) { //��
				x -= 2;
				if (x < 1) x = 1;
			}
			else if (chr == 77) { //��
				x += 2;
				if (x > 39) x = 39;
			}
			gotoxy(x, y);// �ֿܼ��� Ŀ�� ��ġ �ٲٴ� �Լ�
			if (sw == 0) printf("��");
			else printf("��");
		}
		else if (getch() == 32 || getch() == 13)
		{
			if (arr[y - 1][x / 2] == 5 || arr[y - 1][x / 2] == 9)
			{
				system("cls");
				pan();
				printf("\n�̹� ���õ� ĭ�Դϴ�.\n�ٽ� �������ּ���.\n");
				goto rescan;
			}
			else
			{
				if (sw == 0) arr[y - 1][x / 2] = 5; //�浹���� Ȯ�� �� �� ����
				if (samsam() == 1 && sw == 0) { //�浹�̸鼭 ����̸�
					arr[y - 1][x / 2] = 0; //���� ������
					system("cls");
					pan();
					printf("\n��� �Դϴ�.\n�ٽ� �Է��� �ּ���");
					goto rescan;
				}
				if(sw==1) arr[y - 1][x / 2] = 9;
				system("cls");
				break;
			}
		}
	}
}

int samsam() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++)
		{
			if (arr[i - 1][j - 1] == 5 && arr[i - 1][j + 1] == 5 && arr[i + 1][j - 1] == 5 && arr[i + 1][j + 1] == 5 && arr[i][j]) // O
			{
				return 1;
			}
			else if (arr[i][j + 1] == 5 && arr[i][j + 2] == 5 && arr[i + 1][j] == 5 && arr[i + 2][j] == 5 && arr[i][j]) // O
			{
				return 1;
			}
			else if (arr[i][j]==5&&arr[i+1][j]==5&&arr[i+2][j]==5&&arr[i+1][j+1]==5&&arr[i+1][j+2]==5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i][j+1] == 5 && arr[i][j+2] == 5 && arr[i + 1][j + 1] == 5 && arr[i + 2][j + 1] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j]==5 && arr[i-1][j]==5&&arr[i+1][j]==5&&arr[i][j-1]==5&&arr[i][j+1]==5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i + 1][j] == 5 && arr[i + 2][j] == 5 && arr[i + 2][j-1] == 5 && arr[i+2][j + 1] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j-1] == 5 && arr[i + 1][j] == 5 && arr[i + 2][j] == 5 && arr[i + 2][j - 1] == 5 && arr[i + 2][j + 1] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j + 2] == 5 && arr[i + 1][j+2] == 5 && arr[i + 2][j+2] == 5 && arr[i + 2][j +1] == 5 && arr[i + 2][j] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i + 1][j] == 5 && arr[i + 2][j] == 5 && arr[i + 2][j + 1] == 5 && arr[i + 2][j + 2] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i][j + 1] == 5 && arr[i][j + 2] == 5 && arr[i + 1][j + 2] == 5 && arr[i + 2][j + 2] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i+1][j -1] == 5 && arr[i+1][j] == 5 && arr[i + 1][j + 1] == 5 && arr[i + 2][j + 2] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i][j + 1] == 5 && arr[i][j + 2] == 5 && arr[i + 1][j + 2] == 5 && arr[i - 1][j + 2] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i+1][j] == 5 && arr[i+1][j + 1] == 5 && arr[i + 1][j + 2] == 5 && arr[i + 2][j + 2] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i][j+1] == 5 && arr[i+1][j - 1] == 5 && arr[i + 2][j - 2] == 5 && arr[i][j + 2] == 5) // O
			{
				return 1;
			}
		}
	}
	return 0;
}

void reset()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			arr[i][j] = 0;
		}
	}
}

void ohmok()
{
	while (1)
	{

		//�浹 ����
		pan();  // �ٵ��� ���

		key_move(0);  // Ű����� �浹 ����
		if (result_black() == 0)
		{
			reset();
			break;
		}//�浹 �¸����� �Ǻ�

		//�鵹 ����
		pan(); // �ٵ��� ���

		key_move(1);  // Ű����� �鵹 ����

		if (result_white() == 0)
		{
			reset();
			break;	//�鵹 �¸����� �Ǻ�
		}

	}
		system("pause"); // .exe���Ϸ� ��������� ������ �¸��ϸ� �ٷ� ���������°� �����ϱ� ���� 
}