#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>

//��,��,��,
char pan[4][25][3]; // ������ �� ���ڿ� �迭
int blackcnt, whitecnt;	// �浹, �鵹 ���� Ƚ�� ����
int i, j, n, m;	// �浹, �鵹 �ε���
int sw; // ���� ���� ���� ����
int turn; // ���� �ѱ��

void pan_printf(); // �� ���
void pan_clean(); // �� �������� �ʱ�ȭ

int mal(); // ���� �������� ���� ������� �� ��ġ ����
void play(); // ���� �÷���
void gameover(); // ���� �������� �˻�

void file_save(); // �� ����
void file_load(); // �� �ҷ�����

void play_yut() {
	system("mode con:cols=80 lines=34"); // �ܼ� ũ�� ����
	pan_clean(); // �� �������� �ʱ�ȭ
	while (1) {
		if (turn) { sw = 1; turn = 0; } // ���濡�� �������� �� �ѱ��
		play();	// ���� �÷���
		sw++; // ��� ���ʷ� �ѱ��
		if (sw >= 2) sw = 0; // ��� ���ʷ� �ѱ��
		if (turn == -1) break;
	}
}
void file_save() {
	char filename[100]; // ���� �̸� ���� �迭
	FILE *f; // ���� ������
	system("cls"); // ȭ�� �����
	printf("���ϴ� ���� ���� �Է��� �ּ���>>");
	scanf("%s", filename);
	f = fopen(filename, "w"); // ������� ���� ����
	fprintf(f, "%d %d %d %d %d %d %d ", sw, i, j, n, m, blackcnt, whitecnt); // ���� ���� ���� ����
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			fprintf(f, "%s ", pan[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	system("cls");
	printf("\n���� ���� �Ϸ�!");
	Sleep(1000); // 1�ʰ� ����
}
void file_load() {
	char filename[100]; // ���� �̸� ���� �迭
	FILE *f; // ���� ������
	system("cls"); // ȭ�� �����
	printf("���ϴ� ���� ���� �Է��� �ּ���>>");
	scanf("%s", filename);
	f = fopen(filename, "r"); // �б���� ���� �ҷ�����
	fscanf(f, "%d %d %d %d %d %d %d ", &sw, &i, &j, &n, &m, &blackcnt, &whitecnt); // ���� ���� �ҷ�����
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			fscanf(f, "%s ", pan[i][j]);
		}
	}
	fclose(f);
	system("cls");
	printf("\n���� �ε� �Ϸ�!");
	Sleep(1000); // 1�ʰ� ����
}
void gameover() {
	if (blackcnt >= 3) { // ���� ���� ������ 3�̻��̸�
		system("cls");
		printf("���\n");
		system("pause"); // �ý��� �Ͻ� ����
		turn=-1; // ���α׷� ����
	}
	else if (whitecnt >= 3) {
		system("cls");
		printf("���\n");
		system("pause");
		turn=-1;
	}
}
void pan_printf() {
	system("cls");
	printf("�� �� �� ���� �� �� ���� �� �� ���� �� �� ���� �� �� ���� �� �� \n�� %s�� �� �� %s�� �� �� %s�� �� �� %s�� �� �� %s�� �� �� %s�� \n�� �� �� ���� �� ���� �� �� ���� �� �� ���� �� �� ���� �� �� �� \n������������������������������������������ �� \n�� �� �� ���� �� �������������� �������� �� ���� �� �� ��      �浹 ���� ����:%d \n�� %s�� ���� %s���������� ������������ %s���� �� %s�� \n�� �� �� ���� �� ������������������ ���� �� ���� �� �� ��      �鵹 ���� ����:%d\n  ���� ���������� �� ���� ������ �� ���� ���������� \n�� �� ���� �������� %s�������� �� %s�������� ���� �� �� \n�� %s������ ������ �� ���� ������ �� ���������� �� %s�� \n�� �� ������ ������������ �� �� ���������������� �� �� \n�������������������� �� %s���������������� ���� \n�� �� ���������� �������� �� ������������ ������ �� �� \n�� %s���� �������� �� ���� ������ �� �������� ���� %s�� \n�� �� ���� �������� %s���� ������ %s�������� ���� �� �� \n������ ���������� �� ������ ���� �� �������� ������ \n�� �� �� ���� �� �������� �������������� �� ���� �� �� �� \n�� %s���� �� %s���������� ������������ %s���� �� %s�� \n�� �� ���� �� �� ������������������ ���� �� �� ���� �� �� \n������������ �������������������������������� \n�� �� �� ���� �� �� ���� �� ���� �� �� �� ���� �� ���� �� �� �� \n�� %s�� �� �� %s�� �� �� %s�� �� �� %s�� �� �� %s�� �� �� %s�� \n�� �� �� ���� �� �� ���� �� ���� �� �� �� ���� �� ���� �� �� �� \n\n", pan[0][10], pan[0][9], pan[0][8], pan[0][7], pan[0][6], pan[0][5], 3 - blackcnt, pan[0][11], pan[2][1], pan[1][1], pan[0][4], 3 - whitecnt, pan[2][2], pan[1][2], pan[0][12], pan[0][3], strcmp(pan[2][3], pan[1][3]) > 0 ? pan[2][3] : pan[1][3], pan[0][13], pan[0][2], pan[1][4], pan[2][4], pan[0][14], pan[1][5], pan[2][5], pan[0][1], pan[0][15], pan[0][16], pan[0][17], pan[0][18], pan[0][19], pan[0][0]);
	//�� ���(������ ������ ���� printf �Լ��� �ѹ��� ������)
}
void pan_clean() {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 25; j++) strcpy(pan[i][j], "��"); // ��� ���� ������ �������� �ʱ�ȭ
}
int mal() {
	int random[4];
	char randomc[4];

	srand(time(NULL));

	while (1)
	{
		for (int i = 0; i < 4; i++){
			random[i] = rand() % 2;//���� �������� ������ �ϱ� ���� rand�Լ��� ��
			if (random[i] == 1) randomc[i] = ' ';//�� ���� ǥ��
			else randomc[i] = '+';
		}
		
		pan_printf();
		printf("�� ���� �� ���� �� ���� �� ���� \n�� %c�� �� %c�� �� %c�� �� %c�� \n�� %c�� �� %c�� �� %c�� �� %c�� \n�� %c�� �� %c�� �� %c�� �� %c�� \n�� %c�� �� %c�� �� %c�� �� %c�� \n�� ���� �� ���� �� ���� �� ���� \n", randomc[0], randomc[1], randomc[2], randomc[3], randomc[0], randomc[1], randomc[2], randomc[3], randomc[0], randomc[1], randomc[2], randomc[3], randomc[0], randomc[1], randomc[2], randomc[3]);

		Sleep(100); // 0.1�� ������
		if (kbhit()) {
			int key = getch();
			if (key == 19) {//��Ʈ��+s�� ������
				file_save();//���� �����ϴ� �Լ��� ����
				continue;//���� �� ó������ ���ư�
			}
			else if (key == 15) {//��Ʈ��+o�� ������
				file_load();//���� �ε��ϴ� �Լ��� ����
				continue;//�ε� �� ó������ ���ư�
			}
			break;
		}
	}

	switch (random[0] + random[1] + random[2] + random[3]) //���������� �����ϱ� ���� switch
	{
	case 0: {printf("��"); break; }
	case 1: {printf("��"); break; }
	case 2: {printf("��"); break; }
	case 3: {printf("��"); break; }
	case 4: {printf("��"); break; }
	}
	Sleep(500);//����� �����������°��� �����ϱ� ���� Sleep
	return random[0] + random[1] + random[2] + random[3];//��� ���� ����
}
void play() {
	gameover(); // ���� �������� Ȯ���ϴ� �Լ�
	if (turn == -1) return;
	int dol = mal(); // ������ �� �������� �����ϴ� �Լ��� ��ȯ���� ����
	if (dol == 0) dol = 5; // �� ������ 5ĭ �̵�
	if (sw == 0) { // ������ ����
		if (!strcmp(pan[0][5], "��")) //ù��° ������
		{
			strcpy(pan[0][5], "��"); // �������� �ٲ�
			i = 1; j = 0; // ��ǥ ����
		}
		else if (!strcmp(pan[1][3], "��")) { // ���
			strcpy(pan[1][3], "��"); // �������� �ٲ�
			i = 2; // ��ǥ ����
		}
		else if (!strcmp(pan[0][10], "��")) { // �ι�° ������
			strcpy(pan[0][10], "��"); // �������� �ٲ�
			i = 2; j = 0; // ��ǥ ����
		}
		else if (!strcmp(pan[i][j + dol], "��")) { // �������� Ȯ��
			strcpy(pan[i][j], "��"); // �������� �ٲ�
			strcpy(pan[i][j + dol], "��"); // �� �ٲٱ�
			n = 0; m = 0; // ������ ����
			j += dol; // �� �̵�
			turn = 1; // �ѹ� �� �ϵ��� �� �ѱ��
			system("cls");
			printf("�鵹�� �������ϴ�.\n");
			Sleep(1000);
			return; // �Լ� ����
		}
		strcpy(pan[i][j], "��"); // �������� �ʱ�ȭ
		strcpy(pan[i][j + dol], "��"); // �� ����
		for (int k = 1; k <= 5; k++)
		{
			if (!strcmp(pan[0][19 + k], "��") || !strcmp(pan[2][5 + k], "��")) { // �� �ϳ��� �ѹ��� ������ ��
				strcpy(pan[0][19 + k], "��"); strcpy(pan[2][5 + k], "��"); // �ش� ��ǥ�� �������� �ʱ�ȭ
				blackcnt++; // ���� ���� ����
				strcpy(pan[0][0], "��"); // ó�� ��ǥ�� �� ����
				pan_printf(); // �� ���
				Sleep(1000);
				strcpy(pan[0][0], "��"); // �������� �ʱ�ȭ
				i = 0; j = 0; // ��ǥ �ʱ�ȭ
				return;
			}
			else if (!strcmp(pan[1][5 + k], "��")) { // ��������
				strcpy(pan[1][5 + k], "��"); // �������� �ʱ�ȭ
				i = 0; j = 14; // 1,5���� ����ĭ�� 0,14���� ����ĭ�� �����Ƿ� �̿� ���� ��ǥ�� ����
				strcpy(pan[i][j + k], "��"); // �� ����
				j += k; // ��ǥ ����
				return;
			}
		}
		j += dol; // ��ǥ ����
	}
	else if (sw == 1) { // �� ���� ��
		if (!strcmp(pan[0][5], "��"))
		{
			strcpy(pan[0][5], "��");
			n = 1; m = 0; // ��ǥ ����
		}
		else if (!strcmp(pan[1][3], "��")) {
			strcpy(pan[1][3], "��");
			n = 2;
		}
		else if (!strcmp(pan[0][10], "��")) {
			strcpy(pan[0][10], "��");
			n = 2; m = 0;
		}
		else if (!strcmp(pan[n][m + dol], "��")) {
			strcpy(pan[n][m], "��");
			strcpy(pan[n][m + dol], "��");
			i = 0; j = 0;
			m += dol;
			turn = 1;
			system("cls");
			printf("�浹�� �������ϴ�.\n");
			Sleep(1000);
			return;
		}
		strcpy(pan[n][m], "��");
		strcpy(pan[n][m + dol], "��");
		for (int k = 1; k <= 5; k++)
		{
			if (!strcmp(pan[0][19 + k], "��") || !strcmp(pan[2][5 + k], "��")) {
				strcpy(pan[0][19 + k], "��"); strcpy(pan[2][5 + k], "��");
				whitecnt++;
				strcpy(pan[0][0], "��");
				pan_printf();
				Sleep(1000);
				strcpy(pan[0][0], "��");
				n = 0; m = 0;
				return;
			}
			else if (!strcmp(pan[1][5 + k], "��")) {
				strcpy(pan[1][5 + k], "��");
				n = 0; m = 14;
				strcpy(pan[n][m + k], "��");
				m += k;
				return;
			}
		}
		m += dol;
	}
	return;
}