
//Input and fix
void ChuanhoaMaLop(char ml[])
	{
		strupr(ml);
    	for(int i=0; i<strlen(ml); i++)
    	{
    		ktralai:;
    		if(ml[0]=='\0')
    			break;
    		if((ml[i] >= 'A' && ml[i] <= 'Z') || (ml[i] >= '0' && ml[i] <='9'))
    			continue;
    		else
    		{
    			for(int j=i; j<strlen(ml); j++)
					ml[j]=ml[j+1];
				goto ktralai;	
			}	
		}
    	
	} 
    //Nhap thong tin sinh vien
    bool ChuanhoaTen(char hoten[])
    {
    	strlwr(hoten);
    	//Chinh sua ki tu dau
    	while(hoten[0]<'a' || hoten[0]>'z')
    	{
    		if(hoten[0]=='\0')
    			return false;
    		for(int j=0; j<strlen(hoten); j++)
					hoten[j]=hoten[j+1];
		}
		hoten[0]=hoten[0]-32;
    	//Xoa ki tu khac chu cai va space
    	int xoa=1;
    	while(xoa<strlen(hoten))
    	{
    		if(hoten[xoa]>='a' && hoten[xoa]<='z' || hoten[xoa]==' ')
    		{
				xoa++;
    			continue;
    		}
    		else
    		{
    			for(int j=xoa; j<strlen(hoten); j++)
						hoten[j]=hoten[j+1];
			}
			
		}
		if(strlen(hoten)==0)
			return false;
		//Doi chu cai dau thanh viet hoa va xoa space (neu thua)
		for(int i=1; i<strlen(hoten); i++)
		{
			if(hoten[i]==' ')
			{
				while(hoten[i+1]==' ')
				{
					for(int j=i; j<strlen(hoten); j++)
						hoten[j]=hoten[j+1];
				}
				hoten[i+1]=hoten[i+1]-32;
			}
		}	
		return true;
	}
	
    bool KiemtraNgaySinh(int d, int m, int y)
    {
        if((y%400 == 0) || (y%4 == 0 && y%100 != 0))
        {
        	if(m==2)
        	{
        		if(d>0 && d<=29)
        			return true;
        		else 
        			return false;
			}
			else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
			{
				if(d>0 && d<32)
					return true;
				else
					return false;
			}
			else if(m==4 ||m==6 ||m==9 ||m==11)
			{
				if(d>0 && d<31)
					return true;
				else
					return false;
			}
			else
				return false;
	    }
	    else
	    {
	    	if(m==2)
        	{
        		if(d>0 && d<=28)
        			return true;
        		else 
        			return false;
			}
			else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
			{
				if(d>0 && d<32)
					return true;
				else
					return false;
			}
			else if(m==4 ||m==6 ||m==9 ||m==11)
			{
				if(d>0 && d<31)
					return true;
				else
					return false;
			}
			else
				return false;
		}
	}
	
	void TextBox(int hang)
	{
		TextColor(63);
		if(hang==5)
		{		
			gotoXY(35,hang);		printf("     Dung 8 ky tu(0-9)        ");
		}
		if(hang==8)
		{		
			gotoXY(35,hang);		printf("       1~8 ky tu(0-9)         ");
		}
		if(hang==11)
		{		
			gotoXY(35,hang);		printf("    1~25 gom chu va dau cach  ");
		}
		if(hang==14)
		{		
			gotoXY(35,hang);		printf("                              ");
			gotoXY(45,14); printf("/     /");
		}
		if(hang==17)
		{		
			gotoXY(35,hang);		printf("       1~5 ky tu chi so,'.'    ");
		}
		TextColor(15);
	}
    
    void BorderNhap()
    {
    	int j=3;
    	TextColor(30);
    	//height
    	for(j;j<23;j++)
    	{
    		//Width
	    	for(int i=10; i<70; i++)
	    	{
	    			gotoXY(i,j);  printf(" ");
			}
		}
		//Danh muc can nhap(khong duoc dien thieu)
		gotoXY(15,5);	printf("Nhap Ma Sinh Vien: ");
		gotoXY(15,8); 	printf("Nhap Ma Lop: ");
		gotoXY(15,11);	printf("Nhap Ten Sinh Vien: ");
		gotoXY(15,14);	printf("Nhap Ngay Sinh: ");
		gotoXY(15,17);	printf("Nhap DTBTL: ");
		gotoXY(30,19);	printf("Save (press key 'F1')");
		gotoXY(30,21);	printf("Back (press key 'ESC')");
		//Khung nhap
		for(int i=5; i<=17; i=i+3)
			TextBox(i);
		
	}
	
    int Nhap (NODE *x, LISTSV L, listlop l)
    {
    	BorderNhap();
    	//Kiem tra luong thong tin nhap vao
    	int kiemduyet[4];
    	for(int i=0; i<5; i++)
    		kiemduyet[i]=0;
    	//Chuong trinh chay
    	bool ktra=false;
    	bool run=true;
    	int menu=1;
    	int hang=5;
    	//Cac thong tin sinh vien
        Date Ngaysinh;
        int masv;
        float diem;
        for(int i=5; i<=17; i=i+3)
        {
        	gotoXY(13,i);	printf(" ");
		}
        do
    	{
    		TextColor(15);
	        gotoXY(13,hang);	printf("%c",15);	
	        system("pause>nul"); // the >nul bit causes it the print no message
		
			if(GetAsyncKeyState(VK_DOWN) && hang<17) // down
			{
				gotoXY(13,hang); printf(" ");
				hang=hang+3;
				menu++;
				continue;
				
			}
				
			if(GetAsyncKeyState(VK_UP)&& hang>5) //up
			{
				gotoXY(13,hang); printf(" ") ;
				hang=hang-3;
				menu--;
				continue;
			}
			
			//Save(press F1)
			if(GetAsyncKeyState(112))
			{
				for(int i=0; i<5; i++)
				{
					if(kiemduyet[i]==1)
						continue;
					else
						return 1;
				}
				return 0;
				
			}
			
			//Back(press ESC) and Don't Save
			if(GetAsyncKeyState(27))
			{
				return 1;
				break;
			}
			
			//Chi cho phep an Enter de chay chuong trinh thay vi nut len va xuong
			if(GetAsyncKeyState(VK_RETURN))
			{
				TextColor(63);
				gotoXY(35,hang);		printf("                              ");
				if(hang==14)
				{
					gotoXY(45,14);		printf("/     /");
				}
				ktra=true;
			}
				
			if(GetAsyncKeyState(VK_RETURN) && ktra==true)	// Enter
			{
				switch(menu)
				{
					case 1:
						{
					        //nhap msv (Dung 8 so)
					        fflush(stdin);
					        char so[8];
					        Mangrong(so,8);
					        TextColor(62);
					        gotoXY(45,5);	
							if(Nhap_gioihankitu(so,1,8,5,45)==0)
							{
							    //Dam bao chuoi chi gom so
							    bool sosanh=true;
							    for(int i=0; i<8; i++)
							    {
							      	if(so[i] <(char)48 || so[i]>(char)57)
							      	{
							       		sosanh=false;
							       		break;
									}	
								}
								masv=atoi(so);
								//kiem tra da ton tai MSV
								NODE *p=L.Dau;
								while(p!=NULL)
								{
									if(p->Data.Msv==masv)
									{
										TextColor(284);
										gotoXY(67,5);	printf("%c", 173);									
										sosanh=false;
										break;
									}
									else
									{
										TextColor(284);
										gotoXY(67,5);	printf(" ");									
									}
									p=p->Next;
								}
								
								if(sosanh==true)
								{								
							       	x->Data.Msv=masv;
									kiemduyet[0]=1;
							    }
							    else
							    {
							    	kiemduyet[0]=0;
							        x->Data.Msv='\0';
									TextColor(60);
							    	gotoXY(40,5);	printf("Khong hop le!!!");
							    	Sleep(1000);
							    	TextBox(5);
								}
								
							}
							else
							{
								TextBox(5);
							}
							TextColor(15);
							break;
						}
					case 2:
						{
							//Nhap malop (Toi da 8 so)
					        fflush(stdin);
					        char classroom[8];
					        TextColor(62);
					        Mangrong(classroom,8);
					        gotoXY(45,8);	
							if(Nhap_gioihankitu(classroom, 1, 8,8,45)==0)
							{						
							    ChuanhoaMaLop(classroom);
							    //Kiem tra ma lop hop le
							    bool tontai=false;
							    node *t=l.Dau;
							    while(t!=NULL)
							    {
							    	if(strcmp(t->lop.ten, classroom)== 0)
							    	{
							    		tontai=true;
							    		break;
							    	}
							    	t=t->Next;
								}
								
								if(strlen(classroom)!=0 && tontai==true)
								{
									gotoXY(35,8);	printf("                              ");
							    	gotoXY(45,8);	puts(classroom);	
								    strcpy(x->Data.MaLop,classroom);
								    fflush(stdin);
								    kiemduyet[1]=1;
								}
								else
								{
									kiemduyet[1]=0;
								   	Mangrong(x->Data.MaLop,8);
								   	TextColor(60);
							       	gotoXY(40,8);	printf("Khong hop le!!!");
							       	Sleep(1000);
							       	TextBox(8);
								}
							}
							else
								TextBox(8);
							TextColor(15);
					        break;
					    }
					case 3:
						{
					        //Nhap Hoten
					        fflush(stdin);	
							char tg[25];
							TextColor(62);
							Mangrong(tg,25);				        
					        gotoXY(38,11);	
							if(Nhap_gioihankitu(tg,1,25,11,38)==0)
							{								
						        TextColor(63);
						        gotoXY(35,11);		printf("                              ");
						        if(ChuanhoaTen(tg)==true)
						        {
							        TextColor(62);
							        gotoXY(38,11); 	puts(tg);
							        strcpy(x->Data.Hoten,tg);
							        fflush(stdin);
							        TextColor(15);
							        kiemduyet[2]=1;
							    }
								else
								{
									kiemduyet[2]=0;
							    	Mangrong(x->Data.Hoten,26);
							    	TextColor(60);
						        	gotoXY(40,11);	printf("Khong hop le!!!");
						        	Sleep(1000);
						        	TextBox(11);
								}
							}
							else
								TextBox(11);
							TextColor(15);
					        break;
					 	}
					    //----------------------Nhap ngaysinh---------------------------------
					case 4:
						{
					    	char d[2], m[2], y[4];
					    	char ktrakytu[10];
					    	TextColor(62);
					    	Mangrong(d,2);	Mangrong(m,2);	Mangrong(y,4);
					    	Mangrong(ktrakytu,10);
							gotoXY(43,14);	
							if(Nhap_gioihankitu(d,1,2,14,43)==0)
							{
								gotoXY(47,14);	
								if(Nhap_gioihankitu(m,1,2,14,47)==0)
								{
								
									gotoXY(53,14);	
									if(Nhap_gioihankitu(y,1,4,14,53)==0)
									{								
										strcpy(ktrakytu, d);
										strcat(ktrakytu, m);
										strcat(ktrakytu, y);
										//Kiem tra khong co ki tu khac so
										bool kytuso=true;
										for(int i=0; i<strlen(ktrakytu); i++)
										{
											if(ktrakytu[i] <(char)48 || ktrakytu[i]>(char)57)
											{
												kytuso=false;
												break;
											}
										}
										if(kytuso==true)
										{
											Ngaysinh.ngay=atoi(d);
											Ngaysinh.thang=atoi(m);
											Ngaysinh.nam=atoi(y);
											bool date=KiemtraNgaySinh(Ngaysinh.ngay, Ngaysinh.thang, Ngaysinh.nam);
											if(date==true)
											{
												x->Data.Birthday.ngay=Ngaysinh.ngay;
												x->Data.Birthday.thang=Ngaysinh.thang;
												x->Data.Birthday.nam=Ngaysinh.nam;
												kiemduyet[3]=1;
											}
											else
											{
												x->Data.Birthday.ngay='\0';
												x->Data.Birthday.thang='\0';
												x->Data.Birthday.nam='\0';
												kiemduyet[3]=0;
												TextColor(60);	
												gotoXY(35,14);	printf("                              ");
												gotoXY(40,14);	printf("Khong hop le!!!");
												Sleep(1000);
												TextBox(14);
											}
										}
										else
										{
											x->Data.Birthday.ngay='\0';
											x->Data.Birthday.thang='\0';
											x->Data.Birthday.nam='\0';
											kiemduyet[3]=0;
											TextColor(60);
											gotoXY(35,14);printf("                              ");	
											gotoXY(40,14);	printf("Khong hop le!!!");
											Sleep(1000);
											TextBox(14);
										}
									}
									else
										TextBox(14);
								}
								else
									TextBox(14);
							}
							else
								TextBox(14);
							TextColor(15);	
					        fflush(stdin);
					        break;
					    }
					    //-----------------Nhap diem TB----------------------------
					case 5:
						{
							fflush(stdin);
							char DTB[5];
							bool kytuso;
							TextColor(62);
							Mangrong(DTB,5);
							gotoXY(45,17);
							if(Nhap_gioihankitu(DTB,1,5,17,45)==0)
							{
								
								int tongkitucham=0;
								for(int i=0; i<strlen(DTB); i++)
								{
									if(DTB[i]=='.')
									{
										tongkitucham++;
									}
									if((DTB[i] >=(char)48 && DTB[i]<=(char)57) || DTB[i]=='.')
									{
										kytuso=true;
										continue;
									}
									else
									{
										kytuso=false;
										break;
									}
									
								}
								//Dam bao khong thua ki tu cham
								if(tongkitucham>1)
									kytuso=false;
									
								if(kytuso==true)
								{
									float diem=atof(DTB);
									if(diem>=0 && diem<=10)
									{
						        		x->Data.DTBTL=diem;
						        		kiemduyet[4]=1;
						        	}
						        	else
						        	{
						        		kiemduyet[4]=0;
						        		x->Data.DTBTL='\0';
						    	    	TextColor(60);
										gotoXY(35,17);printf("                              ");	
										gotoXY(40,17);	printf("Khong hop le!!!");
										Sleep(1000);
										TextBox(17);
										
									}
						        }
						        else
						        {
						        	kiemduyet[4]=0;
						        	x->Data.DTBTL='\0';
						        	TextColor(60);
									gotoXY(35,17);printf("                              ");	
									gotoXY(40,17);	printf("Khong hop le!!!");
									Sleep(1000);
									TextBox(17);
								}
							}
							else
								TextBox(17);
							
							fflush(stdin);
							TextColor(15);
					        break;
					    }
			    }
		    }
		}while(run!=false);
    }
    
        //Them vao dau danh sach
    void Themdau(LISTSV *x, NODE *p)
    {
    	//them dau
    	if(x->Dau == NULL)
        {
            x->Dau = p;
            x->Cuoi = p;
        }
        else //them cuoi
        {
			p->Next =x->Dau;
			x->Dau= p;
		}
	}
    //Them vao cuoi danh sach
    void Them(LISTSV *x, NODE *p, int *tongsv)
    {
    	//them dau
    	if(x->Dau == NULL)
        {
            x->Dau = p;
            x->Cuoi = p;
        }
        else //them cuoi
        {
			x->Cuoi->Next = p;
			x->Cuoi = p;
		}
		int t= *tongsv;
		t++;
		*tongsv=t;
	}
     
    void Output(char *fileName, NODE *p); 
    // Them mot sinh vien vao cuoi danh sach
    int NhapSV(LISTSV *x, listlop danhsachlophoc)
    {
        NODE *a = KhoitaoNode();
        if(Nhap(a,*x,danhsachlophoc)==0)
        {
        	Them(x,a,&count);
        	Output(file,a);
        	TextColor(14);
        	gotoXY(30,19);	printf("                      ");
        	gotoXY(38,19);	printf("Saved!!!");
        	TextColor(15);
        	
        }
        else
        {
        	TextColor(14);
        	gotoXY(30,19);	printf("  Khong luu vao bo nho ");  	
        	TextColor(15);
        }
        getch();
        return 0;
    }  

////------------------------------------FIX-----------------------------
	void FixFile(char *fileName, LISTSV *x);
	/* function to swap data of two nodes a and b*/
	void Swap(NODE *a, NODE *b)
	{
		//Thay doi thong tin sinh vien
	    SINHVIEN temp = a->Data;
	    a->Data = b->Data;
	    b->Data = temp;
	    //Thay doi STT
	    int c=a->STT;
	    a->STT=b->STT;
	    b->STT=c;
	}
	
	void Delete(LISTSV *x, int vitri)
	{
		//Xoa nguoi dau tien
		if(vitri==1)
		{
			x->Dau=x->Dau->Next;
		}	
		else if(vitri==count)		//Xoa nguoi cuoi cung
		{
			NODE *p=x->Dau;
			for(int i=0; i<count-2; i++)
			{
				p=p->Next;
			}
			p->Next=NULL;
			x->Cuoi=p;
		}
		else						//Xoa nguoi o giua
		{
			NODE *previos=x->Dau;
	    	NODE *del=x->Dau->Next;
	    	for(int i=0; i<(vitri-2); i++)
	    	{
				del=del->Next;
	    		previos=previos->Next;
	    	}
	    	previos->Next=del->Next;
	    	del->Next=NULL;
	    }
	    
	    
		count--;
		FixFile(file,x);	
	}
	
	void Change(LISTSV *x, NODE *thay, int vitri)
	{
		NODE *p=x->Dau;
		for(int i=0; i<(vitri-1); i++)
    		p=p->Next;
    	Swap(thay,p);
    	
	}
	
	void TextBoxFix(NODE *p,int hang)
	{
		TextColor(63);
			
		if(hang==14)
		{
			gotoXY(45,hang);		printf("/     /");			}
		else
		{
			gotoXY(35,hang);		printf("                              ");
		}
		
		TextColor(62);
		if(hang==5)
		{
			gotoXY(45,5);	printf("%d", p->Data.Msv);
		}
		else if(hang==8)
		{
			gotoXY(45,8);	printf("%s", p->Data.MaLop);
		}
		else if(hang==11)
		{
			gotoXY(45,11);	printf("%s", p->Data.Hoten);
		}
		else if(hang==14)
		{
			gotoXY(43,14);	printf("%d", p->Data.Birthday.ngay);
			gotoXY(47,14);	printf("%d", p->Data.Birthday.thang);
			gotoXY(53,14);	printf("%d", p->Data.Birthday.nam);
		}
		else if(hang==17)
		{
			gotoXY(45,17);	printf("%0.2f", p->Data.DTBTL);
		}
	}
	
	void TakeData(NODE *sv1, NODE *sv2)
	{
		sv1->Data=sv2->Data;
		sv1->STT = sv2->STT;
	}
	
    int Fix(LISTSV *L, listlop l, int vitri)
    {
    	system("cls");
    	//dua toi nguoi can thay
    	NODE *x=KhoitaoNode();
    	NODE *p=L->Dau;
		for(int i=0; i<(vitri-1); i++)
    		p=p->Next;
    	
    	//Lay data
    	TakeData(x,p);
    	//In ra sinh vien
    	BorderNhap();
    	for(int i=5;i<18; i=i+3)
    	{
	    	TextBoxFix(p,i);
		}
		TextColor(15);
		bool run=true;
		int kiemduyet[4];
    	for(int i=0; i<5; i++)
    		kiemduyet[i]=0;
    	//Chuong trinh chay
    	bool ktra=false;
    	int menu=1;
    	int hang=5;
    	//Cac thong tin sinh vien
        Date Ngaysinh;
        int masv;
        float diem;
        for(int i=5; i<=17; i=i+3)
        {
        	gotoXY(13,i);	printf(" ");
		}
        do
    	{
	        gotoXY(13,hang);	printf("%c",15);	
	        system("pause>nul"); // the >nul bit causes it the print no message
		
			if(GetAsyncKeyState(VK_DOWN) && hang<17) // down
			{
				gotoXY(13,hang); printf(" ");
				hang=hang+3;
				menu++;
				continue;
				
			}
				
			if(GetAsyncKeyState(VK_UP)&& hang>5) //up
			{
				gotoXY(13,hang); printf(" ") ;
				hang=hang-3;
				menu--;
				continue;
			}
			
			//Save(press F1)
			if(GetAsyncKeyState(112))
			{
				bool thaydoi=false;
				for(int i=0; i<5; i++)
				{
					if(kiemduyet[i]==1)
						thaydoi=true;
				}
				if(thaydoi==true)
				{
					Swap(x,p);
					return 0;
				}
				else
					return 1;
				break;
			}
			
			//Back(press ESC) and Don't Save
			if(GetAsyncKeyState(27))
			{
				return 1;
				break;
			}
			
			//Chi cho phep an Enter de chay chuong trinh thay vi nut len va xuong
			if(GetAsyncKeyState(VK_RETURN))
			{
				TextColor(63);
				gotoXY(35,hang);		printf("                              ");
				if(hang==14)
				{
					gotoXY(45,14);		printf("/     /");
				}
				ktra=true;
			}
				
			if(GetAsyncKeyState(VK_RETURN) && ktra==true)	// Enter
			{
				switch(menu)
				{
					case 1:
						{
					        //nhap msv (Dung 8 so)
					        fflush(stdin);
					        char so[8];
					        Mangrong(so,8);
					        TextColor(62);
					        gotoXY(45,5);	
							if(Nhap_gioihankitu(so,1,8,5,45)==0)
							{
							    //Dam bao chuoi chi gom so
							    bool sosanh=true;
							    for(int i=0; i<8; i++)
							    {
							      	if(so[i] <(char)48 || so[i]>(char)57)
							      	{
							       		sosanh=false;
							       		break;
									}	
								}
								masv=atoi(so);
								//kiem tra da ton tai MSV
								NODE *ptr=L->Dau;
								while(ptr!=NULL)
								{
									if(ptr->Data.Msv==masv)
									{
										TextColor(284);
										gotoXY(68,5);	printf("%c", 173);									
										sosanh=false;
										break;
									}
									else
									{
										TextColor(284);
										gotoXY(68,5);	printf(" ");									
									}
									ptr=ptr->Next;
								}
								
								if(sosanh==true)
								{								
							       	x->Data.Msv=masv;
									kiemduyet[0]=1;
							    }
							    else
							    {
							    	kiemduyet[0]=0;
							        x->Data.Msv=p->Data.Msv;
									TextColor(60);
							    	gotoXY(40,5);	printf("Khong hop le!!!");
							    	Sleep(1000);
							    	TextBoxFix(p,5);
								}
								
							}
							else
							{
								TextBoxFix(p,5);
							}
							TextColor(15);
							break;
						}
					case 2:
						{
							//Nhap malop (Toi da 8 so)
					        fflush(stdin);
					        char classroom[8];
					        TextColor(62);
					        Mangrong(classroom,8);
					        gotoXY(45,8);	
							if(Nhap_gioihankitu(classroom, 1, 8,8,45)==0)
							{						
							    ChuanhoaMaLop(classroom);
							    //Kiem tra ma lop hop le
							    bool tontai=false;
							    node *t=l.Dau;
							    while(t!=NULL)
							    {
							    	if(strcmp(t->lop.ten, classroom)== 0)
							    	{
							    		tontai=true;
							    		break;
							    	}
							    	t=t->Next;
								}
								
								if(strlen(classroom)!=0 && tontai==true)
								{
									gotoXY(35,8);	printf("                              ");
							    	gotoXY(45,8);	puts(classroom);	
								    strcpy(x->Data.MaLop,classroom);
								    fflush(stdin);
								    kiemduyet[1]=1;
								}
								else
								{
									kiemduyet[1]=0;
								   	Mangrong(x->Data.MaLop,9);
								   	strcpy(x->Data.MaLop,p->Data.MaLop);
								   	TextColor(60);
							       	gotoXY(40,8);	printf("Khong hop le!!!");
							       	Sleep(1000);
							       	TextBoxFix(p,8);
								}
							}
							else
								TextBoxFix(p,8);
							TextColor(15);
					        break;
					    }
					case 3:
						{
					        //Nhap Hoten
					        fflush(stdin);	
							char tg[25];
							TextColor(62);
							Mangrong(tg,25);				        
					        gotoXY(38,11);	
							if(Nhap_gioihankitu(tg,1,25,11,38)==0)
							{								
						        TextColor(63);
						        gotoXY(35,11);		printf("                              ");
						        if(ChuanhoaTen(tg)==true)
						        {
							        TextColor(62);
							        gotoXY(38,11); 	puts(tg);
							        strcpy(x->Data.Hoten,tg);
							        fflush(stdin);
							        TextColor(15);
							        kiemduyet[2]=1;
							    }
								else
								{
									kiemduyet[2]=0;
							    	Mangrong(x->Data.Hoten,26);
							    	strcpy(x->Data.Hoten, p->Data.Hoten);
							    	TextColor(60);
						        	gotoXY(40,11);	printf("Khong hop le!!!");
						        	Sleep(1000);
						        	TextBoxFix(p,11);
								}
							}
							else
								TextBoxFix(p,11);
							TextColor(15);
					        break;
					 	}
					    //----------------------Nhap ngaysinh---------------------------------
					case 4:
						{
					    	char d[2], m[2], y[4];
					    	char ktrakytu[10];
					    	TextColor(62);
					    	Mangrong(d,2);	Mangrong(m,2);	Mangrong(y,4);
					    	Mangrong(ktrakytu,10);
							gotoXY(43,14);	
							if(Nhap_gioihankitu(d,1,2,14,43)==0)
							{
								gotoXY(47,14);	
								if(Nhap_gioihankitu(m,1,2,14,47)==0)
								{
								
									gotoXY(53,14);	
									if(Nhap_gioihankitu(y,1,4,14,53)==0)
									{								
										strcpy(ktrakytu, d);
										strcat(ktrakytu, m);
										strcat(ktrakytu, y);
										//Kiem tra khong co ki tu khac so
										bool kytuso=true;
										for(int i=0; i<strlen(ktrakytu); i++)
										{
											if(ktrakytu[i] <(char)48 || ktrakytu[i]>(char)57)
											{
												kytuso=false;
												break;
											}
										}
										if(kytuso==true)
										{
											Ngaysinh.ngay=atoi(d);
											Ngaysinh.thang=atoi(m);
											Ngaysinh.nam=atoi(y);
											bool date=KiemtraNgaySinh(Ngaysinh.ngay, Ngaysinh.thang, Ngaysinh.nam);
											if(date==true)
											{
												x->Data.Birthday.ngay=Ngaysinh.ngay;
												x->Data.Birthday.thang=Ngaysinh.thang;
												x->Data.Birthday.nam=Ngaysinh.nam;
												kiemduyet[3]=1;
											}
											else
											{
												x->Data.Birthday.ngay=p->Data.Birthday.ngay;
												x->Data.Birthday.thang=p->Data.Birthday.thang;
												x->Data.Birthday.nam=p->Data.Birthday.nam;
												kiemduyet[3]=0;
												TextColor(60);	
												gotoXY(35,14);	printf("                              ");
												gotoXY(40,14);	printf("Khong hop le!!!");
												Sleep(1000);
												TextBoxFix(p,14);
											}
										}
										else
										{
											x->Data.Birthday.ngay=p->Data.Birthday.ngay;
											x->Data.Birthday.thang=p->Data.Birthday.thang;
											x->Data.Birthday.nam=p->Data.Birthday.nam;
											kiemduyet[3]=0;
											TextColor(60);
											gotoXY(35,14);printf("                              ");	
											gotoXY(40,14);	printf("Khong hop le!!!");
											Sleep(1000);
											TextBoxFix(p,14);
										}
									}
									else
										TextBoxFix(p,14);
								}
								else
									TextBoxFix(p,14);
							}
							else
								TextBoxFix(p,14);
							TextColor(15);	
					        fflush(stdin);
					        break;
					    }
					    //-----------------Nhap diem TB----------------------------
					case 5:
						{
							fflush(stdin);
							char DTB[5];
							bool kytuso;
							TextColor(62);
							Mangrong(DTB,5);
							gotoXY(45,17);
							if(Nhap_gioihankitu(DTB,1,5,17,45)==0)
							{
								
								int tongkitucham=0;
								for(int i=0; i<strlen(DTB); i++)
								{
									if(DTB[i]=='.')
									{
										tongkitucham++;
									}
									if((DTB[i] >=(char)48 && DTB[i]<=(char)57) || DTB[i]=='.')
									{
										kytuso=true;
										continue;
									}
									else
									{
										kytuso=false;
										break;
									}
									
								}
								//Dam bao khong thua ki tu cham
								if(tongkitucham>1)
									kytuso=false;
									
								if(kytuso==true)
								{
									float diem=atof(DTB);
									if(diem>=0 && diem<=10)
									{
						        		x->Data.DTBTL=diem;
						        		kiemduyet[4]=1;
						        	}
						        	else
						        	{
						        		kiemduyet[4]=0;
						        		x->Data.DTBTL=p->Data.DTBTL;
						    	    	TextColor(60);
										gotoXY(35,17);printf("                              ");	
										gotoXY(40,17);	printf("Khong hop le!!!");
										Sleep(1000);
										TextBoxFix(p,17);
										
									}
						        }
						        else
						        {
						        	kiemduyet[4]=0;
						        	x->Data.DTBTL=p->Data.DTBTL;
						        	TextColor(60);
									gotoXY(35,17);printf("                              ");	
									gotoXY(40,17);	printf("Khong hop le!!!");
									Sleep(1000);
									TextBoxFix(p,17);
								}
							}
							else
								TextBoxFix(p,17);
							
							fflush(stdin);
							TextColor(15);
					        break;
					    }
			    }
		    }
		}while(run!=false);
	}
	
	int Edit(LISTSV *x, listlop danhsachlophoc, int first, int end)
	{
		bool run = true;
		int hang=2;
		int check=first+1;
		
		do
		{
			gotoXY(77,hang);	printf("%c", 174);
			system("pause>nul");
			// Thoat khong lam j ca
			if(GetAsyncKeyState(27))
			{
				run=false;
				break;
			}
			
			//Sua
			if(GetAsyncKeyState(VK_RETURN))
			{
				if(Fix(x,danhsachlophoc,check)==0)
				{
					FixFile(file,x);
					gotoXY(30,19);	printf("                      ");
					gotoXY(31,19);	printf("Thay doi thanh cong");
				}
				else
				{
					gotoXY(30,19);	printf("                      ");									
					gotoXY(35,19);	printf("Khong luu!!!");
				}
					
				getch();
				run=false;
				return 1;
				break;
			}
			
			//Delete			
			if(GetAsyncKeyState(46))
			{
				Delete(x, check);
				run=false;
				return 1;
				break;
			}
			
			if(GetAsyncKeyState(VK_DOWN) && check<count)
			{
				gotoXY(77,hang);	printf(" ");
				hang=hang+2;
				check++;				
				if(check>end)
					return 2;
			}
			
			if(GetAsyncKeyState(VK_UP) && check!=1)
			{	
				gotoXY(77,hang);	printf(" ");				
				hang=hang-2;
				check--;				
				if(check<first+1)
					return 3;
			}
		}while(run!=false);
		return 0;
	}

	
