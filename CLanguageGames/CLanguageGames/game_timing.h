#include <stdio.h>
#include <conio.h>
#include <windows.h>

void timergame()
{
	static int win=0; // ���������� ����Ͽ� �ٽ� ���� ���� ���� Ƚ���� �״�� ��
	static int lose=0;
	int k = 0;
	int timer;
	int random;


	system("cls");//ȭ���� ������
	printf("���ڰ� 0�� �� ������ �����ϴ� ����!\n");
	printf("���� : %d", win);
	printf("\t���� : %d\n", lose);
	system("pause");

	//0�� �������� �ƹ�Ű�� ������ Ÿ�̹� ���ߴ� ����
	srand(time(NULL));
	for (timer = 10; timer >= -1; timer--) // ī��Ʈ�ٿ�
	{
		system("cls");
		printf("%d", timer);

		random = rand() % 50 + 1;
		Sleep(random);

		if (kbhit()) break; //Ű�� �������� �νĵǸ� �ݺ����� ���
	}

	if (timer == 0) // ���� ���� ����
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