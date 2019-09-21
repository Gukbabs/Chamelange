#include <stdio.h>
#include "interfaces.h"
#include "cursor.h"
#include "fileManage.h"

//#define COLORS

int editor() //������ ���� ������ fclose()
{
	int i;
	char ch;
	char line_buffer[123]; //�Է� 120ĭ, �������� ���Ϳ� \n\n\0 or ���� ����� \n\0
	int line = 1;
	int pointer = 0;
	int t_point;
	int last_ch = -1;

	FILE* tmp = fopen("C://UDiT//temp.txt", "r+"); //�����ʹ� ������ temp ���Ͽ�����

	now_Line(line); //���� �� �� Ȯ��

	gotoxy(0, 1);

	if (file_size(tmp) != 0) //������ ���� �ִ� �����̸�
	{
		fseek(tmp, 0, SEEK_SET);
		while (1) //���� ���� //ù�� ����
		{
			ch = fgetc(tmp);
			if ((ch == '\n') || (feof(tmp) != 0)) //���� ���������� (���� ũ��� 120)
			{
				line_buffer[pointer] = '\0'; // ������ \n ���� null�� �ʱ�ȭ
				break;
			}
			line_buffer[pointer] = ch; //ù�� ���ڵ� ���۷� ����					
			pointer++; //���� ������
			last_ch++; // ���� ���� �þ

		}
		fseek(tmp, 0, SEEK_SET); //���� ������ ������ �Ѱܵ�

	//	pointer = 0;
	}
	//������
	//i = now_y();
	//gotoxy(10, 14);
	//printf("main %d = pointer, %d is last_ch", pointer, file_size(tmp));
	//gotoxy(pointer, i); //�ű�� �ܼ� Ŀ�� �ű��
	//system("pause");
	gotoxy(pointer, now_y()); //Ȯ���� �Ϸ���
	while (1) //������ ������ ����
	{
		while ((ch = getch()) != '\n')
		{
			if (key_ck(ch) != 0)  //�Է� ������ �����϶���
			{
				if ((pointer > last_ch) && (pointer != 121)) //�� �������̰ų� ���� �� ���� \n�ڸ��� �ƴҶ�, ���� ����Ű�� ���� 255�� �ƴҶ�
				{

					line_buffer[pointer] = ch;
					printf("%c", ch);
					pointer++;
					last_ch++;
				}
				else if ((last_ch != 121) && (pointer <= last_ch)) //�߰��� �����Ҷ� -> �̶� ������ ���ڰ� 255�� x
				{
					for (i = last_ch; i >= pointer; i--)
					{
						line_buffer[i + 1] = line_buffer[i]; //���������� �ű��
					}
					last_ch++;
					line_buffer[pointer] = ch; //�� �ڸ��� ���� �ְ�
					for (i = pointer; i <= last_ch; i++)
					{
						printf("%c", line_buffer[i]);
						//printf("\n%c, %d\n", line_buffer[i], i); //���� �ڸ����� ������ �ٽ� ���
					}
					pointer++;
					gotoxy(pointer, now_y());//���� �ڸ��� ���ư�
				}

			}
			if (((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(0x4C) & 0x8000))) //ctrl �̶� lŰ ������
			{
				if (pointer > 0)
				{
					pointer--; //�����͸� ��������
					i = now_y();
					gotoxy(pointer, i); //�ű�� �ܼ� Ŀ�� �ű��
				}
			}
			if (((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(0x52) & 0x8000))) //ctrl �̶� rŰ ������
			{
				if (pointer <= last_ch)
				{
					pointer++; //�����͸� ����������
					i = now_y();
					gotoxy(pointer, i); //�ű�� �ܼ� Ŀ�� �ű��
				}
			}

			if ((GetAsyncKeyState(VK_BACK) & 0x8000) && (pointer > 0))//�齺���̽� 
			{
				pointer--;
				i = now_y();
				gotoxy(10, 12);
				//printf("back %d = pointer, %d is last_ch", pointer, last_ch);
				gotoxy(pointer, i); //�ű�� �ܼ� Ŀ�� �ű��
				if (last_ch < pointer) //���� �������϶�
				{
					gotoxy(last_ch, now_y());
					printf(" ");
					gotoxy(last_ch, now_y());
					last_ch--;
					i = now_y();
					gotoxy(10, 16);
					//printf("back1 %d = pointer, %d is last_ch", pointer, last_ch);
					gotoxy(pointer, i); //�ű�� �ܼ� Ŀ�� �ű��
				}
				else
				{

					gotoxy(pointer, now_y());
					for (i = pointer; i <= last_ch; i++)
					{
						printf(" ");
					}
					for (i = pointer + 1; i <= last_ch; i++)
					{
						line_buffer[i - 1] = line_buffer[i];
					}
					last_ch--;
					gotoxy(pointer, now_y());
					for (i = pointer; i <= last_ch; i++)
					{
						printf("%c", line_buffer[i]);
					}
					gotoxy(pointer, now_y());
					i = now_y();
					gotoxy(10, 18);
					//printf("back2 %d = pointer, %d is last_ch", pointer, last_ch);
					gotoxy(pointer, i); //�ű�� �ܼ� Ŀ�� �ű��
				}
			}
			if (GetAsyncKeyState(VK_HOME) & 0x8000) //ȨŰ
			{
				getchar();

				pointer = 0;
				gotoxy(pointer, now_y());
			}
			if (GetAsyncKeyState(VK_END) & 0x8000) //����Ű
			{
				getchar();
				pointer = last_ch + 1;
				gotoxy(pointer, now_y());
			}

			//if (GetAsyncKeyState(VK_LEFT) & 0x8000)  //Ű���� ����Ű ����->��ĭ��
			//{
			//	getchar();
			//	getch();
			//	if (pointer > 0)
			//	{
			//		pointer--;
			//		gotoxy(pointer, now_y());
			//	}
			//}
			//if (GetAsyncKeyState(VK_RIGHT) & 0x8000) //Ű���� ����Ű ������ ->�� �Էµ�
			//{
			//	getchar();
			//	if ((last_ch - pointer) >= -1)
			//	{
			//		pointer++;
			//		gotoxy(pointer, now_y());
			//	}
			//}

			if ((GetAsyncKeyState(VK_RETURN) & 0x8000)) //���� �Է�
			{					//�߰��� �����ѰŴ� ���� \n \0�����ϱ� Ȯ��

				int y_point = now_y();//���� ��ǥ�� ����
				line_buffer[last_ch + 1] = '\n';
				//line_buffer[last_ch + 2] = '\n'; //���ʹϱ� ���� �� ó������ ��
				line_buffer[last_ch + 2] = '\0';
				save_Line(tmp, line_buffer); // ���� ����
				pointer = 0;
				last_ch = -1;
				line++; //���� �߰�
				print_whole_file(tmp, line);
				gotoxy(pointer, y_point + 1); //Ŀ���� ���� ù�ٷ�		 
			}
			if (((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(VK_RETURN) & 0x8000))) //�߰��� ���� �߰����ִ� ���� �Է�
			{

				int y_point = now_y();//���� ��ǥ�� ����
				line_buffer[last_ch + 1] = '\n';
				line_buffer[last_ch + 2] = '\n'; //���� �� ó������ ��
				line_buffer[last_ch + 3] = '\0';
				save_Line(tmp, line_buffer); // ���� ����
				pointer = 0;
				last_ch = -1;
				line++; //���� �߰�
				print_whole_file(tmp, line);
				gotoxy(pointer, y_point + 1); //Ŀ���� ���� ù�ٷ�		 
			}
			if (((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(0x53) & 0x8000))) //ctrl+s
			{
				char end_sel;
				int k = now_y();
				gotoxy(70, 0);
				dye(0, RED, BLUE, "�����Ͻðڽ��ϱ�? (Y/N) >>");
				getchar();
				end_sel = getchar();
				line_buffer[pointer] = '\0';
				switch (end_sel)
				{
				case 'Y': { //���� ���� �����ʹ� �� ���� ���� ��
					line_buffer[last_ch] = '\n';
					line_buffer[last_ch + 1] = '\0';

					save_Line(tmp, line_buffer);

					save_File();
				}
				case 'y': {
					line_buffer[last_ch] = '\n';
					line_buffer[last_ch + 1] = '\0';

					save_Line(tmp, line_buffer);

					save_File();
				}
				case 'N': {
					gotoxy(70, 0);
					dye(0, RED, BLUE, "�����Ͻðڽ��ϱ�? (Y/N) >>");
					getchar();
					end_sel = getchar();
					switch (end_sel)
					{
					case 'Y': {
						system("cls");
						main();
					}
					case 'y': {
						system("cls");
						main();
					}
					case 'N': {
						edit_sClr(tmp, pointer, k);
						break;
					}
					case 'n': {
						edit_sClr(tmp, pointer, k);
						break;
					}
					}
					break;
				}
				case 'n': {
					gotoxy(70, 0);
					dye(0, RED, BLUE, "�����Ͻðڽ��ϱ�? (Y/N) >>");
					getchar();
					end_sel = getchar();
					switch (end_sel)
					{
					case 'Y': {
						system("cls");
						main();
					}
					case 'y': {
						system("cls");
						main();
					}
					case 'N': {
						edit_sClr(tmp, pointer, k);
						break;
					}
					case 'n': {
						edit_sClr(tmp, pointer, k);
						break;
					}
					}
					break;
				}
				default:

					break;
				}
			}

			if (((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(0x55) & 0x8000))) //ctrl+u �� ȭ��ǥ
			{
				pointer--;
				gotoxy(pointer, now_y());
				//line--;
				//now_Line(line);
				//line_buffer[last_ch + 1] = '\n';
				//line_buffer[last_ch + 2] = '\0';
				//fputs(line_buffer, tmp); //�Է� ������ ���Ͽ� ����
				//fflush(tmp); //���� �ý��� �Է� ���� �����
				//last_ch = 0;
				//int count = 0;
				//while (i <= line) //�� ���� ã�Ƽ� ���ۿ� ����
				//{

				//	while (1)
				//	{
				//		count++; //���������� line��° ������ ��(\n ��) ������ ũ��
				//		if (ch = fgetc(tmp) == '\n')
				//		{
				//			fseek(tmp, 2, SEEK_CUR);//���� ���ܿ� \N �־ ������ ������
				//			count = count + 1;//\N �־
				//			break;
				//		}
				//		if (i == 3)
				//		{
				//			last_ch++; //���������� line��° ������ ���� ��
				//		}
				//	}
				//	i++;
				//}
				//fseek(tmp, count - (last_ch - 1), SEEK_SET); //line ��° ������ ù��° ����
				//for (i = 0; i <= last_ch - 1; i++)
				//{
				//	line_buffer[i] = fgetc(tmp); //�� ���� �޾ƿ���
				//}
				//fseek(tmp, -(last_ch - 1), SEEK_CUR); //�� ���� ù �����ͷ� �ű�� => �׷��� ���߿� ����� �� �ֵ���


				//pointer = 0;
			}
			if (GetAsyncKeyState(VK_F10) & 0x8000)
			{
				edit_menu(tmp, pointer, now_y());
			}

			if (((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(0x42) & 0x8000)))//ctrl+b
			{
				i = now_y();

				gotoxy(60, 0);
				//getch();
				dye(0, RED, BLUE, "���� ������ �ϸ�ũ�� �����Ͻðڽ��ϱ�? (Y/N) >>");

				ch = getchar();
				switch (ch)
				{
				case 'Y':
				{
					//bmkn = 1;
					FILE* bmk = fopen("C://UDiT//bookmarks.txt", "r+");
					fseek(bmk, 0, SEEK_END);
					fprintf(bmk, "%d %d\n", pointer, line);
					fflush(bmk);
					fclose(bmk);
					gotoxy(60, 0);
					dye(0, DARKGRAY, LIGHTBLUE, ' ');
					printf("                            ");
					getch();
					dye(0, LIGHTGRAY, BLACK, ' ');
					gotoxy(pointer, i);

					break;
				}
				case 'X':
				{
					gotoxy(60, 0);
					dye(0, DARKGRAY, LIGHTBLUE, ' ');
					printf("                            ");
					getch();
					dye(0, LIGHTGRAY, BLACK, ' ');
					gotoxy(pointer, i);
					break;
				}
				default: break;
				}

				gotoxy(pointer, i); //�ű�� �ܼ� Ŀ�� �ű��

			}
		}
	}
	return 0;
}