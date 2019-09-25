#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#include "interfaces.h"

int dye(int n, int f_color, int b_color, char* ch) // ���� �� �������� ����!!
{													//n=0�̸� ����, ���ڿ� ��� n>0�̸� �׸�ŭ �ݺ� ���
	int i = 0;
	int color = f_color + b_color * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			printf("%c", ch);
		}
		return 0;
	}
	else if ((n == 0) && (sizeof(ch) == sizeof(char)))
	{
		printf("%c", ch);
		return 0;
	}
	else if ((n == 0) && (sizeof(ch) != sizeof(char)))
	{
		printf("%s", ch);
		return 0;
	}
	return 0;
}

void edit_Interface()
{
	gotoxy(1, 29); //UI
	dye(0, LIGHTGRAY, BLACK, "UDiT");
	gotoxy(97, 29);
	dye(0, LIGHTGRAY, BLACK, "ESC or crtl + @: Menu"); //��Ʈ�� Ű ������ ���� �ߵ���
	gotoxy(0, 0);
	dye(120, DARKGRAY, LIGHTBLUE, ' ');
	gotoxy(7, 0);
	dye(0, YELLOW, LIGHTBLUE, "F");
	dye(0, LIGHTGRAY, LIGHTBLUE, "ile");
	gotoxy(now_x() + 4, 0);
	dye(0, YELLOW, LIGHTBLUE, "E");
	dye(0, LIGHTGRAY, LIGHTBLUE, "dit");
	gotoxy(now_x() + 4, 0);
	dye(0, YELLOW, LIGHTBLUE, "S");
	dye(0, LIGHTGRAY, LIGHTBLUE, "earch");
	gotoxy(now_x() + 4, 0);
	dye(0, YELLOW, LIGHTBLUE, "O");
	dye(0, LIGHTGRAY, LIGHTBLUE, "ptions");
	gotoxy(now_x() + 4, 0);
	dye(0, YELLOW, LIGHTBLUE, "H");
	dye(0, LIGHTGRAY, LIGHTBLUE, "elp");
	dye(0, LIGHTGRAY, BLACK, ""); //�� �ٲ���
}

int cur_Line(int n, int ft_color, int bg_color) //���� �� �� Ȯ��
{
	int cur_x_point, cur_y_point; //���� Ŀ�� ��ġ ����
	cur_x_point = now_x();
	cur_y_point = now_y();
	
	//�̰� cur_Line�Լ� �θ��� ������ ȣ���ؾ� �� ��
	gotoxy(53, 29);
	
	//dye(0, LIGHTGRAY, BLACK, "");
	printf("[%d]", n); //���� ��ġ �ٲ���
	
	dye(0, ft_color, bg_color, " Line");
	gotoxy(cur_x_point, cur_y_point); //���� ��ġ�� �ٽ� ���ư�
	return 0;
}

void main_Screen()
{
	int today_notice = 0;
	///////////////�ð�
	struct tm* t;
	time_t timer; //�ð� ����
	timer = time(NULL); // ���� �ð��� �ʴ����� ���
	t = localtime(&timer); //�� ������ �ð� �и��ؼ� ����ü��
	////////////////////

	/*gotoxy(56, 3);
	dye(0, LIGHTBLUE, BLACK, " ��  UDiT - Ultra eDiTor ������������������������������������������������������������");
	for (int i = 4; i < 11; i++)
	{
		gotoxy(57, i);
		dye(0, LIGHTBLUE, BLACK, "��");
		gotoxy(109, i);
		dye(0, LIGHTBLUE, BLACK, "��");
	}
	gotoxy(56, 11);
	dye(0, LIGHTBLUE, BLACK, " ����������������������������������������������������������������������������������������������������������");*/
	
	gotoxy(108, 1);
	dye(0, WHITE, BLACK, "");

	////////////�ǽð����� ���� �� �ִ� �������� main���� ������
	printf("%d-%d-%d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday); // ù�� ������ ��� ��¥-��-��
	
	
	gotoxy(31, 3);
	dye(0, GREEN, BLACK, "                     _.....---..._\n");
	gotoxy(31, 4);
	dye(0, GREEN, BLACK, "      _..-'-.   _.--'             '--.._\n");
	gotoxy(31, 5);
	dye(0, GREEN, BLACK, "  _.-' (  0) Y''  C h a m e l a n g e   ''-.._\n");
	gotoxy(31, 6);
	dye(0, GREEN, BLACK, " (---.._,                                     '-._\n");
	gotoxy(31, 7);
	dye(0, GREEN, BLACK, "  `---.,___.-\  \----......./  /..------...____   '-.\n");
	gotoxy(31, 8);
	dye(0, GREEN, BLACK, "     _/  /  _/  /       __\\  \\   __\\  \\      `-.   \\\n");
	gotoxy(31, 9);
	dye(0, GREEN, BLACK, "    (((-'  (((-'        (((---'  (((---`        )  /\n");
	gotoxy(31, 10);
	dye(0, GREEN, BLACK, "                                              .-'.-'\n");
	gotoxy(31, 11);
	dye(0, GREEN, BLACK, "                                              (__`-,\n");
	gotoxy(31, 12);
	dye(0, GREEN, BLACK, "                                                 ``");

	gotoxy(70, 29);
	//dye(0, WHITE, BLACK, "Copyright �� 2018-2019 RuBi. All Rights Reserved.");	//�ؿ� �ִ� �͵��� ���߿� ��ġ ��������
	dye(0, WHITE, BLACK, "Copyright �� 2019 Chamelange. All Rights Reserved.");
	/*gotoxy(59, 6);
	dye(0, LIGHTGRAY, BLACK, "type   : ");
	gotoxy(71, 6);
	dye(0, LIGHTCYAN, BLACK, "N");
	gotoxy(now_x() + 3, 6);
	dye(0, LIGHTBLUE, BLACK, "<Enter>");
	gotoxy(89, 6);
	dye(0, LIGHTGRAY, BLACK, "for  �� ���� �����");
	gotoxy(59, 7);
	dye(0, LIGHTGRAY, BLACK, "type   : ");
	gotoxy(71, 7);
	dye(0, LIGHTCYAN, BLACK, "O");
	gotoxy(now_x() + 3, 7);
	dye(0, LIGHTBLUE, BLACK, "<Enter>");
	gotoxy(89, 7);
	dye(0, LIGHTGRAY, BLACK, "for  ���� ����");
	gotoxy(59, 8);
	dye(0, LIGHTGRAY, BLACK, "type   : ");
	gotoxy(71, 8);
	dye(0, LIGHTCYAN, BLACK, "F");
	gotoxy(now_x() + 3, 8);
	dye(0, LIGHTBLUE, BLACK, "<Enter>");
	gotoxy(89, 8);
	dye(0, LIGHTGRAY, BLACK, "for  ���� ã��");
	gotoxy(59, 9);
	dye(0, LIGHTGRAY, BLACK, "type   : ");
	gotoxy(71, 9);
	dye(0, LIGHTCYAN, BLACK, "M");
	gotoxy(now_x() + 3, 9);
	dye(0, LIGHTBLUE, BLACK, "<Enter>");
	gotoxy(89, 9);
	dye(0, LIGHTGRAY, BLACK, "for  ���� ������");
	gotoxy(59, 10);
	dye(0, LIGHTGRAY, BLACK, "type   : ");
	gotoxy(71, 10);
	dye(0, LIGHTCYAN, BLACK, "E");
	gotoxy(now_x() + 3, 10);
	dye(0, LIGHTBLUE, BLACK, "<Enter>");
	gotoxy(89, 10);
	dye(0, LIGHTGRAY, BLACK, "for  ���α׷� ����");*/

	gotoxy(10, 14);
	dye(0, YELLOW, BLACK, "##########\n"
		"          #  #######\n"
		"          #   ######\n"
		"          #  #######\n"
		"          #  #######\n"
		"          #  ########\n"
		"          #  ########\n"
		"          #  ########\n"
		"          ###");
	gotoxy(14, 23);
	dye(0, LIGHTGRAY, BLACK, "NEW");

	gotoxy(31, 14);
	dye(0, DARKGRAY, BLACK, "############\n");
	gotoxy(31, 15);
	dye(0, LIGHTGRAY, BLACK, "#          #\n");
	gotoxy(31, 16);
	dye(0, LIGHTGRAY, BLACK, "#          #\n");
	gotoxy(31, 17);
	dye(0, LIGHTGRAY, BLACK, "#          #\n");
	gotoxy(31, 18);
	dye(0, LIGHTGRAY, BLACK, "#          #\n");
	gotoxy(31, 19);
	dye(0, LIGHTGRAY, BLACK, "#          #\n");
	gotoxy(31, 20);
	dye(0, LIGHTGRAY, BLACK, "#          #\n");
	gotoxy(31, 21);
	dye(0, LIGHTGRAY, BLACK, "############\n");
	gotoxy(34, 15);
	dye(0, CYAN, BLACK, "#####\n");
	gotoxy(34, 16);
	dye(0, CYAN, BLACK, "#####\n");
	gotoxy(34, 17);
	dye(0, CYAN, BLACK, "#####\n");
	gotoxy(34, 18);
	dye(0, CYAN, BLACK, "#####\n");
	gotoxy(34, 19);
	dye(0, CYAN, BLACK, "#####\n");

	gotoxy(35, 23);
	dye(0, LIGHTGRAY, BLACK, "OPEN");

	gotoxy(52, 14);
	dye(0, LIGHTGRAY, BLACK, "  #####\n");
	gotoxy(52, 15);
	dye(0, LIGHTGRAY, BLACK, " #     #\n");
	gotoxy(52, 16);
	dye(0, LIGHTGRAY, BLACK, "#       #\n");
	gotoxy(52, 17);
	dye(0, LIGHTGRAY, BLACK, " #     #\n");
	gotoxy(52, 18);
	dye(0, LIGHTGRAY, BLACK, "  ######\n");
	gotoxy(52, 19);
	dye(0, LIGHTGRAY, BLACK, "       ##\n");
	gotoxy(52, 20);
	dye(0, LIGHTGRAY, BLACK, "         ##\n");
	gotoxy(52, 21);
	dye(0, LIGHTGRAY, BLACK, "          ##\n");

	gotoxy(56, 23);
	dye(0, LIGHTGRAY, BLACK, "FIND");

	gotoxy(73, 14);
	dye(0, YELLOW, BLACK, "#####      \n");
	gotoxy(73, 15);
	dye(0, YELLOW, BLACK, "############\n");
	gotoxy(73, 16);
	dye(0, YELLOW, BLACK, "############\n");
	gotoxy(73, 17);
	dye(0, YELLOW, BLACK, "##        ##\n");
	gotoxy(73, 18);
	dye(0, YELLOW, BLACK, "##  ####  ##\n");
	gotoxy(73, 19);
	dye(0, YELLOW, BLACK, "##  ####  ##\n");
	gotoxy(73, 20);
	dye(0, YELLOW, BLACK, "##  ####  ##\n");

	gotoxy(73, 23);
	dye(0, LIGHTGRAY, BLACK, "FILE MANAGER");

	gotoxy(95, 14);
	dye(0, GREEN, BLACK, "############\n");
	gotoxy(95, 15);
	dye(0, GREEN, BLACK, "##  ##    ##\n");
	gotoxy(95, 16);
	dye(0, GREEN, BLACK, "##  ####  ##\n");
	gotoxy(95, 17);
	dye(0, GREEN, BLACK, "#### ## # ##\n");
	gotoxy(95, 18);
	dye(0, GREEN, BLACK, "##   ##   ##\n");
	gotoxy(95, 19);
	dye(0, GREEN, BLACK, "##  #  #####\n");
	gotoxy(95, 20);
	dye(0, GREEN, BLACK, "## #      ##\n");

	gotoxy(99, 23);
	dye(0, LIGHTGRAY, BLACK, "EXIT");



	/*gotoxy(1, 13);
	dye(0, LIGHTGRAY, BLACK, "������������������������������������������Recent Files������������������������������������������");
	gotoxy(7, 14);
	gotoxy(60, 13);
	dye(0, LIGHTGRAY, BLACK, "��������������������������������������Recent Bookmarks��������������������������������������");
	gotoxy(64, 14);

	for (int i = 0; i < 12; i++)
	{
		gotoxy(1, i + 14);
		dye(0, LIGHTGRAY, BLACK, "~//");
		gotoxy(60, i + 14);
		dye(0, LIGHTGRAY, BLACK, "~//");
	}*/
	gotoxy(54, 27);
	dye(0, LIGHTGRAY, BLACK, ">>");
	/*gotoxy(23, 27);
	dye(0, LIGHTCYAN, BLACK, "* Main * ");
	dye(0, CYAN, BLACK, "");
	printf("[%d] ", today_notice);
	dye(0, LIGHTCYAN, BLACK, "Notices >>  ");
	gotoxy(now_x() + 4, 27);*/
}