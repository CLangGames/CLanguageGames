#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>

//●,○,　,
char pan[4][25][3]; // 윷놀이 판 문자열 배열
int blackcnt, whitecnt;	// 흑돌, 백돌 골인 횟수 저장
int i, j, n, m;	// 흑돌, 백돌 인덱스
int sw; // 현재 차례 정보 저장
int turn; // 차례 넘기기

void pan_printf(); // 판 출력
void pan_clean(); // 판 공백으로 초기화

int mal(); // 윷을 무작위로 던져 사용자의 말 위치 저장
void play(); // 게임 플레이
void gameover(); // 게임 종료조건 검사

void file_save(); // 판 저장
void file_load(); // 판 불러오기

void play_yut() {
	system("mode con:cols=80 lines=34"); // 콘솔 크기 설정
	pan_clean(); // 판 공백으로 초기화
	while (1) {
		if (turn) { sw = 1; turn = 0; } // 상대방에게 잡혔을때 턴 넘기기
		play();	// 게임 플레이
		sw++; // 상대 차례로 넘기기
		if (sw >= 2) sw = 0; // 상대 차례로 넘기기
		if (turn == -1) break;
	}
}
void file_save() {
	char filename[100]; // 파일 이름 저장 배열
	FILE *f; // 파일 포인터
	system("cls"); // 화면 지우기
	printf("원하는 파일 명을 입력해 주세요>>");
	scanf("%s", filename);
	f = fopen(filename, "w"); // 쓰기모드로 파일 생성
	fprintf(f, "%d %d %d %d %d %d %d ", sw, i, j, n, m, blackcnt, whitecnt); // 현재 게임 정보 저장
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
	printf("\n파일 저장 완료!");
	Sleep(1000); // 1초간 멈춤
}
void file_load() {
	char filename[100]; // 파일 이름 저장 배열
	FILE *f; // 파일 포인터
	system("cls"); // 화면 지우기
	printf("원하는 파일 명을 입력해 주세요>>");
	scanf("%s", filename);
	f = fopen(filename, "r"); // 읽기모드로 파일 불러오기
	fscanf(f, "%d %d %d %d %d %d %d ", &sw, &i, &j, &n, &m, &blackcnt, &whitecnt); // 게임 정보 불러오기
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			fscanf(f, "%s ", pan[i][j]);
		}
	}
	fclose(f);
	system("cls");
	printf("\n파일 로딩 완료!");
	Sleep(1000); // 1초간 멈춤
}
void gameover() {
	if (blackcnt >= 3) { // 흑이 들어온 개수가 3이상이면
		system("cls");
		printf("흑승\n");
		system("pause"); // 시스템 일시 정지
		turn=-1; // 프로그램 종료
	}
	else if (whitecnt >= 3) {
		system("cls");
		printf("백승\n");
		system("pause");
		turn=-1;
	}
}
void pan_printf() {
	system("cls");
	printf("┌ ─ ┐ 　┌ ─ ┐ 　┌ ─ ┐ 　┌ ─ ┐ 　┌ ─ ┐ 　┌ ─ ┐ \n│ %s│ ─ │ %s│ ─ │ %s│ ─ │ %s│ ─ │ %s│ ─ │ %s│ \n└ ─ ┘ 　└ ─ ┘　 └ ─ ┘　 └ ─ ┘　 └ ─ ┘　 └ ─ ┘ \n　│　　　　　　　　　　　　　　　　　　　 │ \n┌ ─ ┐ 　┌ ─ ┐　　　　　　 　　　┌ ─ ┐　 ┌ ─ ┐      흑돌 남은 개수:%d \n│ %s│ 　│ %s│　　　　 　　　　　│ %s│　 │ %s│ \n└ ─ ┘ 　└ ─ ┘　　　　　　　　 　└ ─ ┘　 └ ─ ┘      백돌 남은 개수:%d\n  │　 　　　　┌ ─ ┐　 　　┌ ─ ┐　 　　　　│ \n┌ ─ ┐　 　　　│ %s│　　　 │ %s│　　　 　┌ ─ ┐ \n│ %s│　　 　　└ ─ ┘　 　　└ ─ ┘　　　　 │ %s│ \n└ ─ ┘　　 　　　　　┌ ─ ┐ 　　　　　　　└ ─ ┘ \n　│　　　　　　　　 │ %s│　　　　　　　 　│ \n┌ ─ ┐　　　　 　　　└ ─ ┘　　　　　 　　┌ ─ ┐ \n│ %s│　 　　　┌ ─ ┐　 　　┌ ─ ┐　　　 　│ %s│ \n└ ─ ┘　 　　　│ %s│　 　　│ %s│　　　 　└ ─ ┘ \n　│　 　　　　└ ─ ┘　　 　└ ─ ┘　　　 　　│ \n┌ ─ ┐ 　┌ ─ ┐　　　 　　　　　　┌ ─ ┐　 ┌ ─ ┐ \n│ %s│　 │ %s│　　　　 　　　　　│ %s│　 │ %s│ \n└ ─ ┘　 └ ─ ┘　　　　　　　　 　└ ─ ┘ 　└ ─ ┘ \n　│　　　　 　　　　　　　　　　　　　　　│ \n┌ ─ ┐ 　┌ ─ ┐ 　┌ ─ ┐　 ┌ ─ ┐ 　┌ ─ ┐　 ┌ ─ ┐ \n│ %s│ ─ │ %s│ ─ │ %s│ ─ │ %s│ ─ │ %s│ ─ │ %s│ \n└ ─ ┘ 　└ ─ ┘ 　└ ─ ┘　 └ ─ ┘ 　└ ─ ┘　 └ ─ ┘ \n\n", pan[0][10], pan[0][9], pan[0][8], pan[0][7], pan[0][6], pan[0][5], 3 - blackcnt, pan[0][11], pan[2][1], pan[1][1], pan[0][4], 3 - whitecnt, pan[2][2], pan[1][2], pan[0][12], pan[0][3], strcmp(pan[2][3], pan[1][3]) > 0 ? pan[2][3] : pan[1][3], pan[0][13], pan[0][2], pan[1][4], pan[2][4], pan[0][14], pan[1][5], pan[2][5], pan[0][1], pan[0][15], pan[0][16], pan[0][17], pan[0][18], pan[0][19], pan[0][0]);
	//판 출력(딜레이 방지를 위해 printf 함수를 한번에 수행함)
}
void pan_clean() {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 25; j++) strcpy(pan[i][j], "　"); // 모든 판의 내용을 공백으로 초기화
}
int mal() {
	int random[4];
	char randomc[4];

	srand(time(NULL));

	while (1)
	{
		for (int i = 0; i < 4; i++){
			random[i] = rand() % 2;//윷을 랜덤으로 나오게 하기 위해 rand함수를 씀
			if (random[i] == 1) randomc[i] = ' ';//빈 윷을 표현
			else randomc[i] = '+';
		}
		
		pan_printf();
		printf("┌ ─┐ ┌ ─┐ ┌ ─┐ ┌ ─┐ \n│ %c│ │ %c│ │ %c│ │ %c│ \n│ %c│ │ %c│ │ %c│ │ %c│ \n│ %c│ │ %c│ │ %c│ │ %c│ \n│ %c│ │ %c│ │ %c│ │ %c│ \n└ ─┘ └ ─┘ └ ─┘ └ ─┘ \n", randomc[0], randomc[1], randomc[2], randomc[3], randomc[0], randomc[1], randomc[2], randomc[3], randomc[0], randomc[1], randomc[2], randomc[3], randomc[0], randomc[1], randomc[2], randomc[3]);

		Sleep(100); // 0.1초 딜레이
		if (kbhit()) {
			int key = getch();
			if (key == 19) {//컨트롤+s를 누르면
				file_save();//파일 저장하는 함수를 실행
				continue;//저장 후 처음으로 돌아감
			}
			else if (key == 15) {//컨트롤+o를 누르면
				file_load();//파일 로딩하는 함수를 실행
				continue;//로딩 후 처음으로 돌아감
			}
			break;
		}
	}

	switch (random[0] + random[1] + random[2] + random[3]) //도개걸윷모를 결정하기 위한 switch
	{
	case 0: {printf("모"); break; }
	case 1: {printf("도"); break; }
	case 2: {printf("개"); break; }
	case 3: {printf("걸"); break; }
	case 4: {printf("윷"); break; }
	}
	Sleep(500);//출력이 지나가버리는것을 방지하기 위해 Sleep
	return random[0] + random[1] + random[2] + random[3];//결과 값을 리턴
}
void play() {
	gameover(); // 게임 끝나는지 확인하는 함수
	if (turn == -1) return;
	int dol = mal(); // 윷놀이 말 랜덤으로 결정하는 함수의 반환값을 저장
	if (dol == 0) dol = 5; // 모가 나오면 5칸 이동
	if (sw == 0) { // 검정돌 차례
		if (!strcmp(pan[0][5], "○")) //첫번째 갈림길
		{
			strcpy(pan[0][5], "　"); // 공백으로 바꿈
			i = 1; j = 0; // 좌표 세팅
		}
		else if (!strcmp(pan[1][3], "○")) { // 가운데
			strcpy(pan[1][3], "　"); // 공백으로 바꿈
			i = 2; // 좌표 세팅
		}
		else if (!strcmp(pan[0][10], "○")) { // 두번째 갈림길
			strcpy(pan[0][10], "　"); // 공백으로 바꿈
			i = 2; j = 0; // 좌표 세팅
		}
		else if (!strcmp(pan[i][j + dol], "●")) { // 잡혔는지 확인
			strcpy(pan[i][j], "　"); // 공백으로 바꿈
			strcpy(pan[i][j + dol], "○"); // 돌 바꾸기
			n = 0; m = 0; // 잡힌돌 리셋
			j += dol; // 돌 이동
			turn = 1; // 한번 더 하도록 턴 넘기기
			system("cls");
			printf("백돌이 잡혔습니다.\n");
			Sleep(1000);
			return; // 함수 종료
		}
		strcpy(pan[i][j], "　"); // 공백으로 초기화
		strcpy(pan[i][j + dol], "○"); // 돌 놓기
		for (int k = 1; k <= 5; k++)
		{
			if (!strcmp(pan[0][19 + k], "○") || !strcmp(pan[2][5 + k], "○")) { // 돌 하나가 한바퀴 돌았을 때
				strcpy(pan[0][19 + k], "　"); strcpy(pan[2][5 + k], "　"); // 해당 좌표를 공백으로 초기화
				blackcnt++; // 들어온 개수 증가
				strcpy(pan[0][0], "○"); // 처음 좌표로 돌 놓기
				pan_printf(); // 판 출력
				Sleep(1000);
				strcpy(pan[0][0], "　"); // 공백으로 초기화
				i = 0; j = 0; // 좌표 초기화
				return;
			}
			else if (!strcmp(pan[1][5 + k], "○")) { // 마지막길
				strcpy(pan[1][5 + k], "　"); // 공백으로 초기화
				i = 0; j = 14; // 1,5에서 남은칸과 0,14에서 남은칸이 같으므로 이와 같이 좌표를 세팅
				strcpy(pan[i][j + k], "○"); // 돌 놓기
				j += k; // 좌표 세팅
				return;
			}
		}
		j += dol; // 좌표 세팅
	}
	else if (sw == 1) { // 흰 돌일 때
		if (!strcmp(pan[0][5], "●"))
		{
			strcpy(pan[0][5], "　");
			n = 1; m = 0; // 좌표 세팅
		}
		else if (!strcmp(pan[1][3], "●")) {
			strcpy(pan[1][3], "　");
			n = 2;
		}
		else if (!strcmp(pan[0][10], "●")) {
			strcpy(pan[0][10], "　");
			n = 2; m = 0;
		}
		else if (!strcmp(pan[n][m + dol], "○")) {
			strcpy(pan[n][m], "　");
			strcpy(pan[n][m + dol], "●");
			i = 0; j = 0;
			m += dol;
			turn = 1;
			system("cls");
			printf("흑돌이 잡혔습니다.\n");
			Sleep(1000);
			return;
		}
		strcpy(pan[n][m], "　");
		strcpy(pan[n][m + dol], "●");
		for (int k = 1; k <= 5; k++)
		{
			if (!strcmp(pan[0][19 + k], "●") || !strcmp(pan[2][5 + k], "●")) {
				strcpy(pan[0][19 + k], "　"); strcpy(pan[2][5 + k], "　");
				whitecnt++;
				strcpy(pan[0][0], "●");
				pan_printf();
				Sleep(1000);
				strcpy(pan[0][0], "　");
				n = 0; m = 0;
				return;
			}
			else if (!strcmp(pan[1][5 + k], "●")) {
				strcpy(pan[1][5 + k], "　");
				n = 0; m = 14;
				strcpy(pan[n][m + k], "●");
				m += k;
				return;
			}
		}
		m += dol;
	}
	return;
}