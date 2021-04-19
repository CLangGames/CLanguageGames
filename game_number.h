#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

int gnumber()
{
	char numbers[25];//메모리 용량을 줄이기 char형을 씀
	char question;
	int amount;
	int a_amount=0;
	int mtime;
	int answer;

	system("cls");
	printf("숫자 개수 외우기\n");
	printf("숫자열을 본 후 해당 숫자의 개수를 맞춰야합니다.\n");
	printf("ex) '1234446889165'의 4의 갯수 : 4\n");
	system("pause");
	
	system("cls");

	srand(time(NULL));
	for (;;)
	{
		printf("외울 숫자의 갯수를 입력해주세요.(최대 25개)\n");
		scanf("%d", &amount);
		
		if (amount >= 1 && amount <= 25)
			break;
		else
			printf("잘못입력하셨습니다.");
			continue;
	}
	


	printf("외울 시간을 입력하세요.\n");
	scanf("%d", &mtime);
	
	system("cls");
	for (int i=0;i<amount;i++)
	{
		numbers[i] = rand() % 10 + 48; // 아스키코드에서 48 ~ 57번이 숫자
		printf("%c",numbers[i]);
	}
	question = rand() % 10 + 48;


	for (int i = 0; i < amount; i++)
		if (question == numbers[i])
			a_amount++;

	Sleep(mtime*1000);

	system("cls");
	printf("%c의 개수는?\n",question);
	scanf("%d",&answer);
	
	if (answer == a_amount)
		printf("성공!!\n");
	else
		printf("실패!!\n");

	for (int i = 0; i < amount; i++)
	{
		printf("%c", numbers[i]);
	}
	printf("\n %c의 숫자 : %d개",question,a_amount);

	Sleep(2000);
}