//File
//-----------------------Danh sach lop mac dinh-------------------------
	void Themcuoi(listlop *x, node *p)
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
	}
	
	void dsMalop(listlop *x)
	{
		char data[30]="Data\\MaLop.txt";
		FILE *f = fopen (data, "r");
		int tongsolop;
		if(f == NULL)
			printf("Khong ton tai file lop");
		else 
		{
			while(1)
			{
				if(feof(f))
					break;
				node *p=Khoitaonode();
				fgets(p->lop.ten,8,f);
				for(int i=0; i<8; i++)
				{
					if((p->lop.ten[i] >='A' && p->lop.ten[i] <='Z') || (p->lop.ten[i] >=(char)48 && p->lop.ten[i]<=57))
						continue;
					else
						p->lop.ten[i]='\0';
				}
				Themcuoi(x,p);
			}
		}
		fclose(f);
	}
//-----------------------FILE-------------------------------------------
	void Input(char *fileName,LISTSV *x)
	{
		char data[30]="Data\\";
		strcat(data,fileName);
		FILE *f = fopen (data, "rb");
		
		if(f == NULL)
			New=true;
		else 
		{
			while(1)
			{
				SINHVIEN sv;
				fread(&sv,sizeof(sv),1,f);
				if(feof(f))
					break;
				NODE *p=KhoitaoNode();
				p->Data=sv;
				Them(x,p,&count);
			}
		}
		fclose(f);
	}
	
	void FixFile(char *fileName, LISTSV *x)
	{
		char data[30]="Data\\";
		strcat(data,fileName);
		FILE *f = fopen (data, "wb+");
		NODE *p=x->Dau;
		while(p!=NULL)
		{
			SINHVIEN sv;
			sv=p->Data;
			fwrite(&sv,sizeof(sv),1,f);
			p=p->Next;
		}
		fclose(f);
	}
	
	void Output(char *fileName, NODE *p) 
	{
		char data[30]="Data\\";
		strcat(data,fileName);
		FILE *f = fopen (data, "ab+");
		if(p!=NULL)
		{
			SINHVIEN sv;
			sv=p->Data;
			fwrite(&sv,sizeof(sv),1,f);
		}
		fclose(f);
	}
	//--------------------ten File---------------------------------
	
	void TenFile(char file[])
	{
		system("cls");
		TextColor(63);
		for(int i=25; i<60; i++)
		{
			for(int j=8; j<13; j++)
			{
				gotoXY(i,j); printf(" ");
			}
		}
		TextColor(158);
		gotoXY(35,8);	printf("Nhap ten FILE");
		TextColor(59);
		gotoXY(26,12);	printf("Default: SinhVien.bin (press ESC)")
		
		bool run=true;
		do
		{
			Mangrong(file,30);
			TextColor(383);
			gotoXY(30,10);	printf("                     .bin");
			TextColor(380);
			gotoXY(32,10);	
			if(Nhap_gioihankitu(file,1,15,10,32)==0)
			{
				for(int i=0; i<strlen(file); i++)
				{
					char n=file[i];
					if((n>='a' && n<='z') || (n>='A' && n<='Z') || n==' ' || (n>=48 && n<=57) || n=='.' || n=='_')
					{
						run=true;
						continue;
					}
					else
					{
						gotoXY(32,10);	printf("  Khong hop le!!!  ");
						getch();
						run=false;
						break;
					}
				}
				if(run==true)
				{
					char *m=strstr(file,".bin");
					if(m==NULL)
					{
						strcat(file,".bin");
						gotoXY(32,10);	
						puts(file);
					}
					getch();
				}
			}
			else
			{
				Mangrong(file,30);
				char *defaultfile="SinhVien.bin";
				strcpy(file,defaultfile);
				run=true;
			}
		}while(run!=true);
		TextColor(15);
	}
