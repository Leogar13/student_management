


		//-------Set Password----------
		char setpass[20]="mta";



//--------------------------Dang nhap-------------------------------------
	bool PassWord(char mang[], int gioihan_duoi, int gioihan_tren, int dong, int cot)
	{
		bool run=false;
		int i=0;
		do
		{
			TextColor(380);
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
//				TextColor(383);
				gotoXY(cot,dong);	printf(" ");
				mang[i]=(char)0;
				gotoXY(cot,dong);
				continue;
			}
			//Xoa tai cac vi tri khac
			else if(n==(char)8 && (i>0))
			{
//				TextColor(380);
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
			else if(i<gioihan_tren)
			{
				mang[i]=n;
				printf("*");
				i++;
				if(i==gioihan_tren)
					mang[i]='\0';
			}
		}while(run!=true);
		TextColor(15);
		return true;
		fflush(stdin);
	}
	
	bool LoginBox()
	{
		system("cls");
		gotoXY(36,3);	printf("Pass: mta");
		//Box Login
		TextColor(93);
		for(int i=25; i<60; i++)
		{
			for(int j=8; j<13; j++)
			{
				gotoXY(i,j);	printf(" ");
			}
		}
		TextColor(158);
		gotoXY(35,8);	printf("Nhap Mat Khau");
		TextColor(383);
		gotoXY(30,10);	printf("                         ");
		int solannhapsai=5;
		char pw[25];
		Mangrong(pw,25);
		while(solannhapsai!=0)
		{
			TextColor(158);
			gotoXY(32,10);
			if(PassWord(pw,1,20,10,32)==true)
			{
				if(strcmp(pw,setpass)==0)
					return true;
				else
				{
					Mangrong(pw,25);
					solannhapsai--;
					TextColor(384);
					gotoXY(32,10);	printf("Khong chinh xac!!!");
					MessageBeep(MB_ICONERROR);
					TextColor(15);
					gotoXY(32,15);	printf("Ban con %d lan nhap!!!", solannhapsai);
					Sleep(1000);
					TextColor(383);
					gotoXY(30,10);	printf("                         ");
					continue;
				}					
			}
			else
			{
				TextColor(15);
				return false;
			}
		}
		if(solannhapsai==0)
		{
			TextColor(15);
			return false;
		}
			
	}
	
	bool Dangnhap()
	{
		system("cls");
		int choose=1;
		

		while(1)
		{
			TextColor(15);
			gotoXY(35,5);	printf("You are???");
			TextColor(30);
			for(int i=20; i<30; i++)
			{
				for(int j=10; j<13; j++)
				{
					gotoXY(i,j);	printf(" ");
				}
			}
			gotoXY(22,11);	printf("Teacher");
			
			for(int i=50; i<60; i++)
			{
				for(int j=10; j<13; j++)
				{
					gotoXY(i,j);	printf(" ");
				}
			}
			gotoXY(52,11);	printf("Guest");
			
			//Doi mau
			if(choose==1)
			{
				TextColor(236);
				for(int i=20; i<30; i++)
				{
					for(int j=10; j<13; j++)
					{
						gotoXY(i,j);	printf(" ");
					}
				}
				gotoXY(22,11);	printf("Teacher");
			}
			if(choose==2)
			{
				TextColor(236);
				for(int i=50; i<60; i++)
				{
					for(int j=10; j<13; j++)
					{
						gotoXY(i,j);	printf(" ");
					}
				}
				gotoXY(52,11);	printf("Guest");
			}
			system("pause>null");
			
			if(GetAsyncKeyState(VK_RETURN))
			{
				if(choose==1)
				{
					TextColor(15);
					if(LoginBox()==true)
						return true;
					else
					{
						system("cls");
						continue;
					}
						
				}
				else
				{
					return false;
					break;
				}
			}
			
			if(GetAsyncKeyState(VK_LEFT) && choose>1)
			{
				choose--;
				continue;
			}
			
			if(GetAsyncKeyState(VK_RIGHT) && choose<2)
			{	
				choose++;
				continue;
			}
			
		}
		TextColor(15);
		return false;
	}
	
	//Thong bao khi quyen truy cap khong cho phep
	
	void Denied_Access()
	{
		system("cls");
		TextColor(207);
		printf("\a");
		for(int i=30; i<50; i++)
		{
			for(int j=10; j<13; j++)
			{
				gotoXY(i,j);	printf(" ");
			}
		}
		gotoXY(33,11);	printf("Denied Access");
		system("pause>null");
		TextColor(15);
	}
