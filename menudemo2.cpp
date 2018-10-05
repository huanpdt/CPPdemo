/* Chuong trinh minh hoa mon hoc: LAP TRINH
	Noi dung demo: Menu va thao tac tren menu
	Tac gia: huanpdt
	Last updated: Oct-2018
*/
#include <iostream>
#include <windows.h>
#include "stdio.h"
#include "conio.h"
#include "time.h"
#define MAX_REF 100
#define MAX_FRAME 20
#define AAA 3
#define STRINT "%3d"
#define LEFTALIGN 12
#define OLDCOLOR 15
#define BLINKCOLOR 14
void gotoxy(short x, short y);
void clrscr(void);
void printxy_int(short x, short y, int value);
//--------------------------------------
//cac ham bo sung
void gotoxy(short x, short y)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hCon, pos);
	fflush(stdin);
}
short getCurrentY()
{
	CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;   
    HANDLE  hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
	return csbiInfo.dwCursorPosition.Y;
	
}
int getColor()
{
	CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;   
    HANDLE  hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
	return csbiInfo.wAttributes;
}
void setColor(int color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void printxy_int(short x, short y, int value)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hCon, pos);
	fflush(stdin);
	printf(STRINT, value);
}
void printxycolor_int(short x, short y, int value,int color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int oldcolor = getColor();
    pos.X = x;
    pos.Y = y;
    setColor(color);
    SetConsoleCursorPosition(hCon, pos);
	fflush(stdin);
	printf(STRINT, value);
	setColor(oldcolor);
}
void printxycolor_str(short x, short y, char *value,int color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int oldcolor = getColor();
    pos.X = x;
    pos.Y = y;
    setColor(color);
    SetConsoleCursorPosition(hCon, pos);
	fflush(stdin);
	printf("%s", value);
	setColor(oldcolor);
}

void clrscr(void)
{
    CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;   
	
    HANDLE  hConsoleOut;
    COORD   Home = {0,0};
    DWORD   dummy;
	
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

    FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
   csbiInfo.dwCursorPosition.X = 0;                        
   csbiInfo.dwCursorPosition.Y = 0;                        
   SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);   
   fflush(stdin);
}
//-------------MENU-------------
char list1[5][21]={"Phep cong","Phep tru","Phep nhan","Phep chia","Thoat"};
char list2[4][21]={"1 chu so","2 chu so","So bat ky","Thoat"};

//--------MENU------------------
//char runmenu(char list[][21],int x, int y);
void swapbetter(int &a,int &b)
{
	if(a>=b) return;
	int tam = a;
	a = b;
	b = tam;
}
void generate_problem(char ops, char scope,int &a, int &b, int &kq)
{
	int lowbound, highbound; //scope
	switch(scope)
	{
		case 0: //1 chu so
			lowbound = 1;
			highbound = 9;
			a = rand()%9 + 1;
			b = rand()%9 + 1;
			break;
		case 1: //2 chu so
			lowbound = 10;
			highbound = 99;
			a = rand()%90 + 10;
			b = rand()%90 + 10;
			
			break;
		case 2: //bat ky 1..1000
			lowbound = 1;
			highbound = 999;
			a = rand()%999 + 1;
			b = rand()%999 + 1;
	}
	swapbetter(a,b);
	switch(ops)
	{
		case 0://cong
			kq = a + b;
			break;
		case 1://tru
			kq = a - b;
			break;
		case 2://nhan
			kq = a * b;
			break;
		case 3://chia
			kq = a/b;
	}
}
//--------WINDOW----------------
void draw_window(int x1,int y1, int x2, int y2)
{
	char leftop = 0xc9;
	char leftbottom = 0xc8;
	char righttop = 0xbb;
	char rightbottom = 0xbc;
	char left = 0xba;
	char top = 0xcd;
	int i;
	for(i=x1; i<=x2; i++)
	{
		gotoxy(i,y1);
		putchar(top);
	}
	for(i=x1; i<=x2; i++)
	{
		gotoxy(i,y2);
		putchar(top);
	}
	for(i=y1; i<=y2; i++)
	{
		gotoxy(x1,i);
		putchar(left);
	}
	for(i=y1; i<=y2; i++)
	{
		gotoxy(x2,i);
		putchar(left);
	}
	
}
void clear_window(int x1, int y1, int x2, int y2)
{
	int i=0,j;
	for (;i<y2-y1-1;i++)
	{
		gotoxy(x1+1,y1+1+i);
		for(j=1;j<x2-x1;j++)
			putchar(' ');
	}
}
void showlist(int x1, int y1, char s[5][21], int count)
{
	int i;
	for(i=0; i<count; i++)
	{
		gotoxy(x1+1,y1+1+i);
		printf("%s",s[i]);
	}
}
char runmenu1(int x1, int y1, char s[5][21], int count, int oldchoice=0)
{
	char c, choice;
	int i;
	draw_window(x1,y1,x1+25,y1+6);
	showlist(x1,y1,s,count);
	i = oldchoice;
	do
	{
		printxycolor_str(x1+1,y1+1+i,s[i],BLINKCOLOR);
		c=getch();
		if(c==0) c=getch();
		switch(c)
		{
			case 72: //up
				printxycolor_str(x1+1,y1+1+i,s[i],OLDCOLOR);
				i = (i + count - 1)	% count;
				break;
			case 80: //down
				printxycolor_str(x1+1,y1+1+i,s[i],OLDCOLOR);
				i = (i + 1)	% count;
				break;
			case 13:
				if(i==(count-1))
					choice = -1;
				else
				 	choice = i;
				break;
		}
	}while(c!=13);
	return choice;
}
//--------MAIN------------------
int main(int argc, char** argv) {
	char ops, scope, choice1=0, choice2=0;
	int numproblem=0, score=0;
	char s[30];
	int a,b,kq,answer;
	int x = 10;
	int y = 5;
	time_t t;
	//Gioi thieu chuong trinh
	sprintf(s,"Chuong trinh minh hoa MENU - huanpdt");
	printxycolor_str(x,y-2,s,13);	
	do
	{
		choice1 = runmenu1(x,y,list1,5,choice1);
		choice2 = 0;
		while(choice1!=-1 && choice2!=-1)
		{
			srand((unsigned) time(&t));
			choice2 = runmenu1(x+26,y,list2,4,choice2);
			if(choice2!=-1)
			{
				generate_problem(choice1,choice2,a,b,kq);
				numproblem ++;
				draw_window(x,y+8,75,y+15);
				clear_window(x,y+8,75,y+15);
				//show problem
				ops = choice1;
				switch(ops)
				{
					case 0://cong
						sprintf(s,"%4d + %4d =   ?",a,b);
						break;
					case 1://tru
						sprintf(s,"%4d - %4d =   ?",a,b);
						break;
					case 2://nhan
						sprintf(s,"%4d * %4d =   ?",a,b);
						break;
					case 3://chia
						sprintf(s,"%4d / %4d =   ?",a,b);
						break;
				}
				printxycolor_str(x+1,y+9,s,BLINKCOLOR);
				gotoxy(x+2,y+11);
				printf("Nhap ket qua= ");
				scanf("%d",&answer);
				if(answer==kq)
				{
					sprintf(s,"DUNG ROI!");
					score++;
				}
				else
					sprintf(s,"SAI!");
				printxycolor_str(x+2,y+13,s,BLINKCOLOR);
				//show score
				sprintf(s,"Scores: %3d/%3d",score,numproblem);
				printxycolor_str(x+2,y+16,s,BLINKCOLOR);
			}
		}
	}while(choice1!=-1);
	y = 1;
	gotoxy(x+1,y);
	printf("Chuong trinh ket thuc!");
	system("pause");
	return 0;
}
