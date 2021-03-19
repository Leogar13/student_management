#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define bool ;int
#define true 0
#define false 1
//----------------Toa do------------------------------------
    
	void gotoXY(int x, int y) 
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
		COORD CursorPosition; 
		CursorPosition.X = x; 
		CursorPosition.Y = y; 
		SetConsoleCursorPosition(console,CursorPosition); 
	};	

//--------------------Mau sac------------------------------
	    
	void TextColor(int mau)
	{
		HANDLE hConsoleColor=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleColor, mau);	
	}
//-------------------Gioi han ky tu nhap vao--------------------------------	
	int Nhap_gioihankitu(char mang[], int gioihan_duoi, int gioihan_tren, int dong, int cot)
	{
		bool run=false;
		int i=0;
		do
		{
			char n=getch();
			//Khong cho viet ngan hon gioi han duoi
			if(GetAsyncKeyState(VK_RETURN) && i<=gioihan_duoi-1)
				continue;
			//Xac nhan chuong trinh 
			else if(GetAsyncKeyState(VK_RETURN))
			{
				run=true;
			}
			//Xoa con tai vi tri dau tien
			else if(n==(char)8 && i==0)
			{
				gotoXY(cot,dong);	printf(" ");
				mang[i]=(char)0;
				gotoXY(cot,dong);
				continue;
			}
			//Xoa tai cac vi tri khac
			else if(n==(char)8 && (i>0))
			{
				gotoXY(cot+i-1,dong);	printf(" ");
				mang[i-1]='\0';
				gotoXY(cot+i-1,dong);
				i--;		
				continue;
			}
			//Khong cho save va back trong qua trinh nhap
			else if(GetAsyncKeyState(27))
				return 1;
			//luu du lieu vao mang
			else if(/*((n>='a' && n<='z') || (n>='A' && n<='Z') || n==' ' || (n>=48 && n<=57)) && */i<gioihan_tren)
			{
				mang[i]=n;
				printf("%c", mang[i]);
				i++;
				if(i==gioihan_tren)
					mang[i]='\0';
			}
		}while(run!=true);
		return 0;
		fflush(stdin);
	}
//--------------------Xoa mang tra ve NULL-------------------------
	void Mangrong(char a[], int n)
	{
		for(int i=0; i<n; i++)
			a[i]='\0';
	}
	


