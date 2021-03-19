//Khung chuong trinh	

	
	//-------------------------Cac Menu Sap xep------------------------------
	int Menu3_Sapxep(LISTSV *x)
	{    	
    	int chon=1;
    	int vitri=9;
    	bool run=true;
    	gotoXY(58,8); 	printf("%c-------------%c",218,191);
    	gotoXY(58,9);	printf("| 1. Ma SV \t|");
		gotoXY(58,10);	printf("| 2. Ma lop \t|");
		gotoXY(58,11);	printf("| 3. Ho Ten \t|");
		gotoXY(58,12);	printf("| 4. Ngay Sinh|");
		gotoXY(58,13);	printf("| 5. DTBTL \t|");
		gotoXY(58,14);	printf("%c-------------%c",192,217);
    	while(run==true)
    	{
		    if(vitri==9)
		    {
				TextColor(31);
		    	gotoXY(58,9);	printf("| 1. Ma SV \t|");
		    	TextColor(15);
			}
			if(vitri==10)
		    {
		    	TextColor(31);
		    	gotoXY(58,10);	printf("| 2. Ma lop \t|");
		    	TextColor(15);
			}
			if(vitri==11)
		    {
		    	TextColor(31);
		    	gotoXY(58,11);	printf("| 3. Ho Ten \t|");
		    	TextColor(15);
			}
			if(vitri==12)
		    {
		    	TextColor(31);
		    	gotoXY(58,12);	printf("| 4. Ngay Sinh|");
		    	TextColor(15);
			}
			if(vitri==13)
		    {
		    	TextColor(31);
		    	gotoXY(58,13);	printf("| 5. DTBTL \t|");
		    	TextColor(15);
			}
			gotoXY(59,vitri); printf("%c",26);
			
			system("pause>nul");
			
			if(GetAsyncKeyState(27)) //esc
			{
				return 1;
				break;
			}
			
			else if(GetAsyncKeyState(VK_DOWN) && vitri<13) // down
			{
				system("color 00F");
				gotoXY(59,vitri); printf(" ");
				vitri++;
				chon++;
				continue;
				
			}
				
			else if(GetAsyncKeyState(VK_UP)&& vitri>9) //up
			{
				system("color 00F");
				gotoXY(59,vitri); printf(" ") ;
				vitri--;
				chon--;
				continue;
			}
					
			if(GetAsyncKeyState(VK_RETURN))	// Enter
		    {
		    	system("color 00F");
			    switch(chon)
			    {
			    	case 1:
			        {
			        	SSMsv(x);
			            break;
					}
					case 2:
			        {
			        	SSMalop(x);
			            break;
					}
			    	case 3:
			        {
			        	SSTen(x);
			            break;
					}
					case 4:
					{
						
			            SSNgaysinh(x);       													
						break;
					}
					case 5:
					{
						
			            SSDTBTL(x);        				
						break;
					}
				}
				
				run=false;
				return 0;
			}
		}
	}
	
	void Menu2_Sapxep(int vitri)
	{
		TextColor(15);
		gotoXY(26,8);	printf("%c-----------------------------%c",218,191);
       	gotoXY(26,9);	printf("| 1. Selection Sort\t\t|");
       	gotoXY(26,10);	printf("| 2. Insert Sort\t\t|");
		gotoXY(26,11);	printf("| 3. Quick Sort\t\t|");
        gotoXY(26,12);	printf("| 4. Bubble Sort\t\t|");
        gotoXY(26,13);	printf("%c-----------------------------%c",192,217);
    
		if(vitri==9)
		{
			TextColor(31);
			gotoXY(26,vitri);	printf("| 1. Selection Sort\t\t|");
			TextColor(15);
		}
		if(vitri==10)
		{
			TextColor(31);
	       	gotoXY(26,vitri);	printf("| 2. Insert Sort\t\t|");
	       	TextColor(15);
	 	}
	 	if(vitri==11)
	 	{
		   	TextColor(31);
			gotoXY(26,vitri);	printf("| 3. Quick Sort\t\t|");
			TextColor(15);
		}
		if(vitri==12)
		{	
			TextColor(31);
	        gotoXY(26,vitri);	printf("| 4. Bubble Sort\t\t|");
	        TextColor(15);
	    }
	}
	
	void Thanhcong()
	{
		system("cls");
		system("color 5F");
		gotoXY(25,9);	printf("--------------------------------");
		gotoXY(25,10);	printf("|\tDa sap xep xong\t\t|");
		gotoXY(25,11);	printf("--------------------------------");
		getch();
	}
	
	void Sapxep(LISTSV *x)
	{
		bool run=true;
		int chon=1;
		int vitri=9;
		system("color 00F");
		gotoXY(25,9);	printf(">");
		gotoXY(1,9); 	printf("%c",26);
		
		while(run==true)
		{
			
			Menu2_Sapxep(vitri);
			gotoXY(27,vitri); printf("%c", 26);
			system("pause>nul"); // the >nul bit causes it the print no message
			
			if(GetAsyncKeyState(27)) //esc
			{
				run=false;
				break;
			}
			
			if(GetAsyncKeyState(VK_DOWN) && vitri<12) // down
			{
				gotoXY(27,vitri); printf(" ");
				vitri++;
				gotoXY(27,vitri); printf("%c",26);
				chon++;
				continue;
				
			}
				
			if(GetAsyncKeyState(VK_UP)&& vitri>9) //up
			{
				gotoXY(27,vitri); printf(" ") ;
				vitri--;
				gotoXY(27,vitri); printf("%c",26);
				chon--;
				continue;
			}
					
			if(GetAsyncKeyState(VK_RETURN))	// Enter
			{
				system("color 00F");
				gotoXY(57,vitri);	printf(">");
				switch(chon)
				{
					case 1:
						{
							if(Menu3_Sapxep(x)==0)
							{
								SelectSort(x);							
								Thanhcong();
							}
							break;
						}
					case 2:
						{
							if(Menu3_Sapxep(x)==0)
							{								
								InsertSort(x);							
								Thanhcong();
							}
							break;
						}
					case 3:
						{
							if(Menu3_Sapxep(x)==0)
							{
								QuickSort(x);							
								Thanhcong();	
							}
							
							break;
						}
					case 4:
						{
							if(Menu3_Sapxep(x)==0)
							{
								BubbleSort(x);
								Thanhcong();
							}
							break;
						}
				}
				
				run=false;
			}
		}
	}
	
//---------------------------Menu Tim kiem-------------------------------
	//---------------------------Tim kiem tuan tu----------------------------
	void SearchTT(LISTSV x)
	{
	   	int chon=1;
	   	int vitri=10;
	   	bool run=true;
	   	system("color 00F");
	   	gotoXY(44,10); printf(">");
	   	gotoXY(45,9);	printf("%c------------------%c",218,191);
		gotoXY(45,10);	printf("| 1. Ma Sinh Vien\t|");
	    gotoXY(45,11);	printf("| 2. Ma Lop\t|");
	    gotoXY(45,12);	printf("| 3. Ho Ten\t|");
	    gotoXY(45,13);	printf("| 4. Ngay Sinh\t|");
	    gotoXY(45,14);	printf("| 5. DTBTL\t\t|");
	    gotoXY(45,15);	printf("| 6. General\t|");
	   	gotoXY(45,16);	printf("%c------------------%c",192,217);
	   	while(run==true)
	   	{	
	    	if(vitri==10)
		   	{
	    		TextColor(31);
				gotoXY(45,10);		printf("| 1. Ma Sinh Vien\t|");
				TextColor(15);
			}
			if(vitri==11)
	    	{
	    		TextColor(31);
				gotoXY(45,11);	printf("| 2. Ma Lop\t|");
				TextColor(15);
			}
			if(vitri==12)
	    	{
	    		TextColor(31);
				gotoXY(45,12);	printf("| 3. Ho Ten\t|");
				TextColor(15);
			}
			if(vitri==13)
	    	{
	    		TextColor(31);
				gotoXY(45,13);	printf("| 4. Ngay Sinh\t|");
				TextColor(15);
			}
			if(vitri==14)
	    	{
	    		TextColor(31);
				gotoXY(45,14);	printf("| 5. DTBTL\t\t|");
				TextColor(15);
			}
			if(vitri==15)
	    	{
	    		TextColor(31);
				gotoXY(45,15);	printf("| 6. General\t|");
				TextColor(15);
			}
			gotoXY(46,vitri);	printf("%c",26);
	   		system("pause>nul");
	   		
	   		if(GetAsyncKeyState(27)) //esc
			{
				run=false;
				break;
			}
	   		
	   		if(GetAsyncKeyState(VK_DOWN) && vitri!=15) // down
			{			
				system("color 00F");						
				gotoXY(46,vitri); printf(" ");
				chon++;
				vitri++;
				continue;
								
			}
								
			if(GetAsyncKeyState(VK_UP) && vitri!=10) //up
			{
				system("color 00F");
				gotoXY(46,vitri); printf(" ") ;
				chon--;
				vitri--;
				continue;
			}
	                    	
	      	if(GetAsyncKeyState(VK_RETURN))	// Enter
	      	{
	      		system("cls");
			  	system("color 00F");
			  	gotoXY(40,0);	printf("TIM KIEM");
	    		switch(chon)
	    		{
			    	case 1:
			    	{
			    		int msv;
				    	fflush(stdin);
			            printf("\nNhap Ma Sinh Vien can tim:");
			            scanf("%d",&msv);
			        	TT_MSV(x ,msv);
						break;   
			        }
			        case 2:
			        {			        
			        	char ml[8];
				    	fflush(stdin);
			            printf("\nNhap Ma Lop can tim:");
			            gets(ml);
			        	TT_ML(x ,ml);
			        	break;
					}
					case 3:
					{
						char hten[25];
				    	fflush(stdin);
			            printf("\nNhap Ho ten Sinh Vien can tim:");
			            gets(hten);
			            fflush(stdin);
			        	TT_Hoten(x ,hten);
			        	break;
					}
					case 4:
					{
						int ngay, thang, nam;
				    	fflush(stdin);
			            printf("\nNhap Ngay sinh:");
			            scanf("%d",&ngay);
			            printf("\nNhap Thang sinh:");
			            scanf("%d",&thang);
			            printf("\nNhap Nam sinh:");
			            scanf("%d",&nam);
			            fflush(stdin);
			        	TT_Ngaysinh(x,ngay,thang,nam);
			        	break;
					}
					case 5:
			        {
			        	float dtbtl;
				    	fflush(stdin);
			            printf("\nNhap DTBTL can tim:");
			            scanf("%f",&dtbtl);
			        	TT_DTBTL(x ,dtbtl);
			        	break;
					}
					case 6:
					{
						system("cls");
						TT_Non_exactly(x);
						break;
					}
				}
				getch();
				run=false;
			}
		}
	}
	
	//-----------------------Tim kiem nhi phan----------------------------------
	void SearchNP(LISTSV *x)
	{
		int chon=1;
	   	int vitri=11;
	   	bool run=true;
	   	system("color 00F");
	   	gotoXY(44,11); printf(">");
	   	gotoXY(45,10);	printf("%c------------------%c",218,191);
		gotoXY(45,11);	printf("| 1. Ma Sinh Vien\t|");
	    gotoXY(45,12);	printf("| 2. Ma Lop\t|");
	    gotoXY(45,13);	printf("| 3. Ho Ten\t|");
	    gotoXY(45,14);	printf("| 4. Ngay Sinh\t|");
	    gotoXY(45,15);	printf("| 5. DTBTL\t\t|");
	   	gotoXY(45,16);	printf("%c------------------%c",192,217);
	
	   	while(run==true)
	   	{	
	   		
	    	if(vitri==11)
	    	{
		   		TextColor(31);
				gotoXY(45,11);		printf("| 1. Ma Sinh Vien\t|");
				TextColor(15);
			}
			if(vitri==12)
		   	{
		   		TextColor(31);
				gotoXY(45,12);	printf("| 2. Ma Lop\t|");
				TextColor(15);
			}
			if(vitri==13)
		   	{
		   		TextColor(31);
				gotoXY(45,13);	printf("| 3. Ho Ten\t|");
				TextColor(15);
			}
			if(vitri==14)
		   	{
		   		TextColor(31);
				gotoXY(45,14);	printf("| 4. Ngay Sinh\t|");
				TextColor(15);
			}
			if(vitri==15)
		   	{
		   		TextColor(31);
				gotoXY(45,15);	printf("| 5. DTBTL\t\t|");
				TextColor(15);
			}
			gotoXY(46,vitri);	printf("%c",26);
	    	system("pause>nul");
	    	
	    	if(GetAsyncKeyState(27)) //esc
			{
				run=false;
				break;
			}
	    	
	    	if(GetAsyncKeyState(VK_DOWN) && vitri!=15) // down
			{			
				system("color 00F");						
				gotoXY(46,vitri); printf(" ");
				chon++;
				vitri++;
				continue;
								
			}
								
			if(GetAsyncKeyState(VK_UP) && vitri!=11) //up
			{
				system("color 00F");
				gotoXY(46,vitri); printf(" ") ;
				chon--;
				vitri--;
				continue;
			}
		                   	
		     	if(GetAsyncKeyState(VK_RETURN))	// Enter
		     	{
			  	system("color 00F");
		   		switch(chon)
		   		{
			    	case 1:
			    	{
			    		system("cls");
			    		SSMsv(x);
			    		QuickSort(x);
			    		int msv;
				    	fflush(stdin);
			            printf("\nNhap Ma Sinh Vien can tim:");
			            scanf("%d",&msv);
						if(NP_MSV(*x,msv,0,count-1)!=true)
						{
							printf("Khong tim thay!!!");
							getch();	
						}
						break;   
			        }
			        case 2:
			        {
			        	system("cls");
			        	SSMalop(x);
			        	QuickSort(x);
			        	char ml[8];
				    	fflush(stdin);
			            printf("\nNhap Ma Lop can tim:");
			            gets(ml);
			            ChuanhoaMaLop(ml);
			        	if(NP_ML(*x,ml,0,count-1)!=true)
						{
							printf("Khong tim thay!!!");
							getch();	
						}
			        	break;
					}
					case 3:
					{
						system("cls");
						SSTen(x);
						QuickSort(x);
						NODE t;
						char hten[25];
						Mangrong(hten,26);
				    	fflush(stdin);
			            printf("\nNhap Ho ten Sinh Vien can tim:");
			            gets(t.Data.Hoten);
			            ChuanhoaTen(t.Data.Hoten);
							//ten ho							
						Tachten(&t,hten);
						strlwr(hten);							
				        fflush(stdin);				        	
						if(NP_Hten(*x,hten,0,count-1)!=true)
						{
							printf("Khong tim thay!!!");
							getch();	
						}	
			        	break;
					}
					case 4:
					{
						system("cls");
						SSNgaysinh(x);
						QuickSort(x);
						int nam,ngay, thang;
				    	fflush(stdin);
			            printf("\nNhap Ngay sinh:");
			            scanf("%d",&ngay);
			            fflush(stdin);
			            printf("\nNhap Thang sinh:");
			            scanf("%d",&thang);
			            printf("\nNhap Nam sinh:");
						fflush(stdin);
						scanf("%d",&nam);
			            fflush(stdin);
			        	if(NP_Ngaysinh(*x,ngay,thang,nam,0,count-1)==false)
						{
							printf("Khong tim thay!!!");
							getch();	
						}
			        	break;
					}
					case 5:
			        {
			        	system("cls");
			        	SSDTBTL(x);
			        	QuickSort(x);
			        	float dtbtl;
				    	fflush(stdin);
			            printf("\nNhap DTBTL can tim:");
			            scanf("%f", &dtbtl);
			            fflush(stdin);
			        	if(NP_DTBTL(*x,dtbtl,0,count-1)==false)
						{
							printf("Khong tim thay!!!");
							getch();	
						}
			        	break;
					}
				}
				run=false;
			}
		}
	}
		

//--------------------------Menu chinh----------------------------------------------
	//-------------------------LIST Chuc nang Menu--------------------------------
	void Chucnang(int hang)
	{
		gotoXY(25,0); printf("Chuong trinh quan ly SINH VIEN                    ");	
		
		gotoXY(0,4);	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c", 201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187,186);		
	    gotoXY(10,5);	printf("Menu:\t\t%c",186);
	    gotoXY(0,6);	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
	        		
		gotoXY(0,7);	printf("%c 1. Them moi ho so.\t%c",186,186);
		gotoXY(0,8);	printf("%c 2. In danh sach.\t%c",186,186);			
		gotoXY(0,9);	printf("%c 3. Sap xep.\t\t%c",186,186);				
		gotoXY(0,10);	printf("%c 4. Tim kiem.\t\t%c",186,186);			
		gotoXY(0,11);	printf("%c 5. Thong ke.\t\t%c",186,186);			
		gotoXY(0,12);	printf("%c 6. Thoat!!!\t\t%c",186,186);
		gotoXY(0,13);	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		gotoXY(0,14); 	printf("~~~~~~~~~~~~~~~~~~~~~");
		gotoXY(20,15);	printf("|");
		gotoXY(20,16);	printf("|");
		gotoXY(20,17);	printf("|");
		gotoXY(0,15);	printf("FILE");
		gotoXY(0,16); puts(file);
		if(New==true)
		{
			printf("( New )");
		}
		gotoXY(0,18); 	printf("~~~~~~~~~~~~~~~~~~~~~");
		//--------------------Doi mau---------------------
		
		if(hang==7)
		{
			TextColor(31);
			gotoXY(0,hang);	printf("%c 1. Them moi ho so.\t%c",186,186);
			TextColor(15);
		}
		if(hang==8)
		{
			TextColor(31);
			gotoXY(0,hang);	printf("%c 2. In danh sach.\t%c",186,186);
			TextColor(15);
		}
		if(hang==9)
		{
			TextColor(31);
			gotoXY(0,hang);	printf("%c 3. Sap xep.\t\t%c",186,186);
			TextColor(15);
		}
		if(hang==10)
		{
			TextColor(31);
			gotoXY(0,hang);	printf("%c 4. Tim kiem.\t\t%c",186,186);
			TextColor(15);
		}
		if(hang==11)
		{
			TextColor(31);
			gotoXY(0,hang);	printf("%c 5. Thong ke.\t\t%c",186,186);			
			TextColor(15);
		}
		if(hang==12)
		{
			TextColor(31);
			gotoXY(0,hang);	printf("%c 6. Thoat!!!\t\t%c",186,186);
			TextColor(15);
		}
	}

//-------------------------Thong ke--------------------------------------

	
	void Thongke(LISTSV *x)
	{
		//Phan tinh toan
		Tenlop Lop[count]; 
		int solop;
		int TongSV[count];
		float Xuatsac[count], Gioi[count], Kha[count], TB_Kha[count], TB[count], Yeu[count]; 
		TinhtoanThongke( x, Lop, TongSV, Xuatsac, Gioi, Kha, TB_Kha, TB, Yeu, &solop);
		//Chuong trinh chay
		bool run=true;
		int vitri=11;
		int chon=1;
		system("color 00F");
		gotoXY(25,11); 	printf(">");
		gotoXY(26,10); 	printf("%c---------------------------------%c",218,191);
		gotoXY(26,11);	printf("| 1. Tong Sinh vien theo lop      |");
		gotoXY(26,12);	printf("| 2. Phan tram xep loai theo lop  |");
		gotoXY(26,13); 	printf("%c---------------------------------%c",192,217);
		while(run==true)
		{
			
			
			if(vitri==11)
			{
				TextColor(31);
				gotoXY(26,11);	printf("| 1. Tong Sinh vien theo lop      |");
				TextColor(15);
				
			}
			if(vitri==12)
			{
				TextColor(31);
				gotoXY(26,12);		printf("| 2. Phan tram xep loai theo lop  |");
				TextColor(15);
				
			}
			gotoXY(27,vitri);printf("%c",26);
			system("pause>nul"); 
			
			if(GetAsyncKeyState(27)) //esc
			{
				run=false;
				break;
			}
			
			if(GetAsyncKeyState(VK_DOWN) && vitri!=12) // down
			{
				system("color 00F");
				gotoXY(27,vitri); printf(" ");
				vitri++;
				chon++;
				continue;
							
			}
							
			if(GetAsyncKeyState(VK_UP)&& vitri!=11) //up
			{
				system("color 00F");
				gotoXY(27,vitri); printf(" ") ;
				vitri--;
				chon--;
				continue;
			}
										
			if(GetAsyncKeyState(VK_RETURN))	// Enter
			{
				system("color 00F");
				switch(chon)
				{
					case 1:
						{
							Thongke_Siso(Lop, TongSV, solop);
							break;
						}
					case 2:
						{
							Thongke_diem(Lop, Xuatsac, Gioi, Kha, TB_Kha, TB, Yeu, solop);
							break;
						}
				}
				getch();
				run=false;
			}
		}
			
	}

	void Intro()
	{
		TextColor(10);
		printf("                 _________ .__                                 \n");
		printf("                 \\_   ___ \\|  |__  __ __  ____   ____    ____  \n");
		printf("                 /    \\  \\/|  |  \\|  |  \\/  _ \\ /    \\  / ___\\ \n");
		printf("                 \\     \\___|   Y  \\  |  (  <_> )   |  \\/ /_/  > \n");
		printf("                  \\______  /___|  /____/ \\____/|___|  /\\___  / \n");
		printf("                         \\/     \\/                  \\//_____/  \n");
		TextColor(14);
		printf("      ___________      .__       .__      ________                       \n");
		printf("      \\__    ___/______|__| ____ |  |__   \\_____  \\  __ _______    ____  \n");
		printf("        |    |  \\_  __ \\  |/    \\|  |  \\   /  / \\  \\|  |  \\__  \\  /    \\ \n");
		printf("        |    |   |  | \\/  |   |  \\   Y  \\ /   \\_/.  \\  |  // __ \\|   |  \\  \n");
		printf("        |____|   |__|  |__|___|  /___|  / \\_____\\ \\_/____/(____  /___|  /  \n");
		printf("                               \\/     \\/         \\__>          \\/     \\/ \n");
		TextColor(12);
		printf(" .____               _________.__       .__      ____   ____.__               \n");
		printf(" |    |    ___.__.  /   _____/|__| ____ |  |__   \\   \\ /   /|__| ____   ____  \n");
		printf(" |    |   <   |  |  \\_____  \\ |  |/    \\|  |  \\   \\   Y   / |  |/ __ \\ /    \\ \n");
		printf(" |    |___ \\___  |  /        \\|  |   |  \\   Y  \\   \\     /  |  \\  ___/|   |  \\ \n");
		printf(" |_______ \\/ ____| /_______  /|__|___|  /___|  /    \\___/   |__|\\___  >___|  / \n");
		printf("         \\/\\/              \\/         \\/     \\/                     \\/     \\/ \n");
		TextColor(13);
		gotoXY(45,20);	printf("Made by Nguyen Anh Tung - HTTT15");
		TextColor(15);
		gotoXY(25,22);
		//begin
    	Beep(781,200);
    	Beep(1047,200);
    	Beep(1319,200);
    	Beep(1568,200);	
		system("pause");
		GetAsyncKeyState(VK_RETURN);
		
	}
	
	void Endless()
	{
			printf("\n    ,---,.                     ");
			printf("\n  ,'  .'  \\                    ");
			printf("\n,---.' .' |                    ");
			printf("\n|   |  |: |                    		    ,---,.                     ");
			printf("\n:   :  :  /     .--,   ,---.   		  ,'  .'  \\                    ");
			printf("\n:   |    ;    /_ ./|  /     \\ 	 	,---.' .' |                    ");
			printf("\n|   :     \\, ' , ' : /    /  | 		|   |  |: |                    ");
			printf("\n|   |   . /___/ \\: |.    ' / | 		:   :  :  /     .--,   ,---.   ");
			printf("\n'   :  '; |.  \\  ' |'   ;   /| 		:   |    ;    /_ ./|  /     \\  ");
			printf("\n|   |  | ;  \\  ;   :'   |  / | 		|   :     \\, ' , ' : /    /  | ");
			printf("\n|   :   /    \\  \\  ;|   :    | 		|   |   . /___/ \\: |.    ' / | ");
			printf("\n|   | ,'      :  \\  \\   \\  /  		'   :  '; |.  \\  ' |'   ;   /| ");
			printf("\n`----'         \\  ' ; `----'   		|   |  | ;  \\  ;   :'   |  / | ");
			printf("\n                `--`           		|   :   /    \\  \\  ;|   :    | ");
			printf("\n                               		|   | ,'      :  \\  \\   \\  /  ");
			printf("\n                               	   	`----'         \\  ' ; `----'   ");
			printf("\n                                        	         `--`           ");
			//end
	    	Beep(2093,200);
	    	Beep(1568,200);
	    	Beep(1319,200);
	    	Beep(1047,200);
	}
      
    //Ham Tao Danh Sach Tuy chon
    int Menu()
    {
		TenFile(file);
        int hang=7, menu=1;
        bool running=true;
        bool ktra=true;
        
        //Tao danh sach sinh vien va cho vao chuong trinh(Neuco)
        LISTSV x;
        KhoitaoList(&x);
        Input(file,&x);
        
        //Lay danh sach lop mac dinh
        listlop danhsachlophoc;
        Khoitaolist(&danhsachlophoc);
        dsMalop(&danhsachlophoc);
        
        system("cls");
        system("color 00F");
        do
        {
			//-------------Chuc nang------------
				
			Chucnang(hang);
       		gotoXY(1,hang);	printf("%c",26);
			
           	system("pause>nul"); // the >nul bit causes it the print no message
	
			if(GetAsyncKeyState(VK_DOWN) && hang<12) // down
			{
				gotoXY(1,hang); printf(" ");
				hang++;
				menu++;
				continue;
				
			}
				
			if(GetAsyncKeyState(VK_UP)&& hang>7) //up
			{
				gotoXY(1,hang); printf(" ") ;
				hang--;
				menu--;
				continue;
			}
			//Chi cho phep an Enter de chay chuong trinh thay vi nut len va xuong
			if(GetAsyncKeyState(VK_RETURN))
				ktra=true;
				
			if(GetAsyncKeyState(VK_RETURN) && ktra==true)	// Enter
			{ 
				switch(menu)
				{
	                case 1:
	                    {
	                    	//Chi giao vien duoc quyen them sinh vien
	                    	if(teacher==true)
	                    	{
		    					//--------------------Nhap thong tin sinh vien------------------------
		                        int n;
		                        system("cls");
		                        gotoXY(25,0); printf("Nhap Thong Tin SINH VIEN");
		                        NhapSV(&x,danhsachlophoc);
			                    fflush(stdin);
			                }
			                else
			                	Denied_Access();
			                	
		                    break;
	                    }
	                case 2:
	                    {

	        //---------------------------In ra danh sach sinh vien----------------------
	                    	bool run=true;
	                    	int chon=8;
	                    	int click=1;
	                    	system("color 00F");
	                    	gotoXY(25,8);	printf(">");			
	                    	gotoXY(26,7); 	printf("%c-----------------------------%c",218,191);
	                    	gotoXY(26,8);	printf("| 1. In toan bo SV (FULL)\t|");
	                    	gotoXY(26,9);	printf("| 2. In SV theo Lop (Class)\t|");
	                    	gotoXY(26,10); 	printf("%c-----------------------------%c",192,217);
	                    	while(run==true)
	                    	{
	                  			
	                    		if(chon==8)
	                    		{
	                    			TextColor(31);
									gotoXY(26,8);	printf("| 1. In toan bo SV (FULL)\t|");
									TextColor(15);
								}
								if(chon==9)
								{
									TextColor(31);
									gotoXY(26,9);	printf("| 2. In SV theo Lop (Class)\t|");									
									TextColor(15);
								}
								gotoXY(27,chon); printf("%c",26);
								system("pause>nul");
								
								if(GetAsyncKeyState(27)) //esc
								{
									run=false;
									break;
								}
		                    	if(GetAsyncKeyState(VK_DOWN) && chon!=9) // down
								{			
									system("color 00F");						
									gotoXY(27,chon); printf(" ");
									chon++;
									click++;
									continue;
									
								}
									
								if(GetAsyncKeyState(VK_UP) && chon!=8) //up
								{
									system("color 00F");
									gotoXY(27,chon); printf(" ") ;
									chon--;
									click--;
									continue;
								}
		                    	
		                    	if(GetAsyncKeyState(VK_RETURN))	// Enter
		                    	{
		                    		system("color 00F");
			                    	switch(click)
			                    	{
			                    		case 1:
			                    			{
											   	InDanhSach(&x, danhsachlophoc);
			                        			break;
			                        		}
			                        	case 2:
			                        		{
			                        			InDanhSachTheoLop(x);
			                        			break;
											}
			                        }
			                        run=false;									
			                	}
			            	}
		                    break;    
		                }
		                    
	                    
	                case 3:
	                    {
	                    	Sapxep(&x);
	                        break;
	                    }  
	                case 4:
	                    {
	                    	bool run=true;
	                    	int chon=1;
	                    	int vitri=10;
	                    	system("color 00F");
	                    	gotoXY(25,hang);	printf(">");
	                    	gotoXY(26,9);	printf("%c----------------%c",218,191);
							gotoXY(26,10);	printf("| 1.Tim tuan tu  |");
							gotoXY(26,11);	printf("| 2.Tim Nhi phan |");	
							gotoXY(26,12);	printf("%c----------------%c",192,217);
							
							while(run==true)
							{
								
								if(vitri==10)
								{
									TextColor(31);
									gotoXY(26,10);	printf("| 1.Tim tuan tu  |");
									TextColor(15);
								}
								if(vitri==11)
								{
									TextColor(31);
									gotoXY(26,11);	printf("| 2.Tim Nhi phan |");
									TextColor(15);
								}
								gotoXY(27,vitri);	printf("%c", 26);
								system("pause>nul");
								
								if(GetAsyncKeyState(27)) //esc
								{
									run=false;
									break;
								}
								
								if(GetAsyncKeyState(VK_DOWN) && vitri!=11) // down
								{
									system("color 00F");
									gotoXY(27,vitri); printf(" ");
									vitri++;
									chon++;
									continue;
									
								}
									
								if(GetAsyncKeyState(VK_UP)&& vitri!=10) //up
								{
									system("color 00F");
									gotoXY(27,vitri); printf(" ") ;
									vitri--;
									chon--;
									continue;
								}
										
								if(GetAsyncKeyState(VK_RETURN))	// Enter
								{
									switch(chon)
									{
										case 1:
											{
												SearchTT(x);	
												break;
											}
										case 2:
											{
												SearchNP(&x);
												break;
											}	
									}
									run=false;
								}
		                	}
		                	break;
	                    }
	                case 5:
	                    {
	                    	Thongke(&x);
	                        break;
	                    }
	                case 6: 
					{
						running=false;
						break;
					}				
	            }
	            
	            hang=7;
	            menu=1;
	            ktra=false;
	            system("color 00F");
				system("cls");
            }
            
        }while(running!=false);
        system("color 02E");
        Endless();
        giaiphong(&x,&danhsachlophoc);
        return 1;
    }
