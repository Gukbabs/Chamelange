#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <io.h>
#include <conio.h>


#include "interfaces.h"
#include "cursor.h"
#include "interrupts.h"
#include "fileManage.h"
#include "textEditor.h"

//int main(int argc, char* argv[])
int main()
{
	int i, x = 0, y = 0;
	int today_notice = 0;
	char command;
	struct tm* t;
	time_t timer; //�ð� ����
	timer = time(NULL); // ���� �ð��� �ʴ����� ���
	t = localtime(&timer); //�� ������ �ð� �и��ؼ� ����ü��
	char loc[60];

	gotoxy(47, 3);
	dye(0, LIGHTBLUE, BLACK, "UDiT - Ultra eDiTor");
	gotoxy(108, 1);
	dye(0, WHITE, BLACK, "");
	printf("%d-%d-%d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday); // ù�� ������ ��� ��¥-��-��
	gotoxy(75, 29);
	dye(0, WHITE, BLACK, "Copyright �� 2018 RuBi. All Rights Reserved.");	//�ؿ� �ִ� �͵��� ���߿� ��ġ ��������
	gotoxy(28, 6);
	dye(0, LIGHTGRAY, BLACK, "type   : ");
	gotoxy(40, 6);
	dye(0, LIGHTCYAN, BLACK, "N");
	gotoxy(now_x() + 3, 6);
	dye(0, LIGHTBLUE, BLACK, "<Enter>");
	gotoxy(58, 6);
	dye(0, LIGHTGRAY, BLACK, "for  �� ���� �����");
	gotoxy(28, 7);
	dye(0, LIGHTGRAY, BLACK, "type   : ");
	gotoxy(40, 7);
	dye(0, LIGHTCYAN, BLACK, "O");
	gotoxy(now_x() + 3, 7);
	dye(0, LIGHTBLUE, BLACK, "<Enter>");
	gotoxy(58, 7);
	dye(0, LIGHTGRAY, BLACK, "for  ���� ����");
	gotoxy(28, 8);
	dye(0, LIGHTGRAY, BLACK, "type   : ");
	gotoxy(40, 8);
	dye(0, LIGHTCYAN, BLACK, "F");
	gotoxy(now_x() + 3, 8);
	dye(0, LIGHTBLUE, BLACK, "<Enter>");
	gotoxy(58, 8);
	dye(0, LIGHTGRAY, BLACK, "for  ���� ã��");
	gotoxy(28, 9);
	dye(0, LIGHTGRAY, BLACK, "type   : ");
	gotoxy(40, 9);
	dye(0, LIGHTCYAN, BLACK, "M");
	gotoxy(now_x() + 3, 9);
	dye(0, LIGHTBLUE, BLACK, "<Enter>");
	gotoxy(58, 9);
	dye(0, LIGHTGRAY, BLACK, "for  ���� ������");
	gotoxy(28, 10);
	dye(0, LIGHTGRAY, BLACK, "type   : ");
	gotoxy(40, 10);
	dye(0, LIGHTCYAN, BLACK, "E");
	gotoxy(now_x() + 3, 10);
	dye(0, LIGHTBLUE, BLACK, "<Enter>");
	gotoxy(58, 10);
	dye(0, LIGHTGRAY, BLACK, "for  ���α׷� ����");
	FILE* bmk = fopen("./bookmarks.txt", "a");
	FILE* ref = fopen("./recentfiles.txt", "a");
	gotoxy(17, 12);
	dye(0, LIGHTGRAY, BLACK, "Recent Files");
	gotoxy(7, 14);
	fseek(ref, 0, SEEK_SET);
	while (fscanf(ref, "%s", loc) != EOF)
	{

		printf("%s\n", loc);
		gotoxy(7, now_y() + 1);

	}
	fclose(ref);
	//fflush(ref);
	gotoxy(74, 12);
	dye(0, LIGHTGRAY, BLACK, "Recent Bookmarks");
	gotoxy(64, 14);
	fseek(bmk, 0, SEEK_CUR);
	while (fscanf(bmk, "%d %d", &x, &y) != EOF)
	{
		printf("%d, %d", x, y);
		gotoxy(64, now_y() + 1);
	}
	//fflush(bmk);
	for (i = 0; i < 12; i++)
	{
		gotoxy(1, i + 12);
		dye(0, LIGHTGRAY, BLACK, "~//");
		gotoxy(57, i + 12);
		dye(0, LIGHTGRAY, BLACK, "~//");
	}

	gotoxy(23, 27);
	dye(0, LIGHTCYAN, BLACK, "* Main * ");
	dye(0, CYAN, BLACK, "");
	printf("[%d] ", today_notice);
	dye(0, LIGHTCYAN, BLACK, "Notices >>  ");
	gotoxy(now_x() + 4, 27);

	command = getchar();
	switch (command)
	{
	case 'N':
		system("cls");
		new_File();

		break;
	case 'O':
		system("cls");
		open_File();
		break;
	case 'F':
		system("cls");
		find_File();
		break;
	case 'M':
		system("cls");
		file_Manager();
		break;
	case 'E':
		printf("\n");
		getchar();
		printf("�����Ͻðڽ��ϱ�? (Y/N)"); //�߰��� �˾�âó�� �س���
		command = getchar();
		switch (command)
		{
		case 'Y': {
			exit(0);
		}
		case 'N': {
			system("cls");
			getchar();
			main();
			break;
		}
		default:
			break;
		}
		break;
	default:
		gotoxy(50, 26);
		dye(0, LIGHTCYAN, BLACK, "�߸� �Է��ϼ̽��ϴ�.");
		_sleep(500);
		system("cls");
		main();
	}
	return 0;
}