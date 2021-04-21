#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include "games.h"

void menu() {
	system("cls");
	printf("1.타이밍 맞추기\n2.가위바위보\n3.묵찌빠\n4.거꾸로 숫자 외우기\n5.숫자열 기억하기\n6.윷놀이");
}

void title()
{
	while (1)
	{
		system("cls");
		printf("■■■■■■■■■■■■■■■■\n"); //디자인
		printf("----------C언어 게임들----------\n");
		printf("□□□□□□□□□□□□□□□□\n");
		printf("시작하려면 아무키나 누르십시오.");
		Sleep(100);
		system("cls");
		printf("□□□□□□□□□□□□□□□□\n"); //윗줄과 아랫줄을 바꿔
		printf("----------C언어 게임들----------\n"); // 역동적인 것처럼 보이게 함
		printf("■■■■■■■■■■■■■■■■\n");
		printf("시작하려면 아무키나 누르십시오.");
		Sleep(100);
		if (kbhit())
		{
			menu();//목록을 출력하는 함수
			getch();//pause를 쓰면 타이틀 효과를 못나타내기 때문에 getch를 씀
			int a = getch();
			if (a == '1') timergame();// 누른 숫자키에 따라서 숫자에 해당하는 게임에 들어가짐
			else if (a == '2')rcsgame();
			else if (a == '3')mjb();
			else if (a == '4')cctgame();
			else if (a == '5')gnumber();
			else if (a == '6') play_yut();
			else continue;//그 외의 키를 눌렀을 경우 처음으로 돌아감
		}

	}
}