//Search
//-------------------------Tim kiem--------------------------------------
    //--------------------------Timkiem tuan tu-----------------------------
		//Tim kiem theo Ma sinh vien
	    
	    void TT_MSV(LISTSV x , int n)
	    {
			NODE *p;
	        p = x.Dau;
	        bool ktra=false;
	        printf("\n\n");
        	printf("****-------------------------Danh sach sinh vien--------------------------****");
        	printf("\n%-8s %-10s %-30s %-20s %-5s", "MSV", "MaLop", "Ho ten", "Namsinh", "DTBTL");
	        while(p != NULL)
	        {
	            if(p->Data.Msv == n)
	            {
	            	ktra=true;	            	
	                InSV(p);
	            }
	            p = p->Next;
	        }
	        if(ktra==false)
	        	printf("\nKhong co nguoi nay!!!");
	    }
	    
	    void TT_ML(LISTSV x , char n[])
	    {
			NODE *p;
	        p = x.Dau;
	        bool ktra=false;
	        printf("\n\n");
     		printf("****-------------------------Danh sach sinh vien--------------------------****");
        	printf("\n%-8s %-10s %-30s %-20s %-5s", "MSV", "MaLop", "Ho ten", "Namsinh", "DTBTL");
	        while(p != NULL)
	        {	        	
	        	strupr(n);
	            if(strstr(p->Data.MaLop,n)!=NULL)
	            {
	            	ktra=true;
	                InSV(p);
	            }
	            p = p->Next;
	        }
	        if(ktra==false)
	        	printf("\nKhong co nguoi nay!!!");
	    }
	    
	    void TT_Hoten(LISTSV x , char hten[])
	    {
			NODE *p;
	        p = x.Dau;
	        strlwr(hten);
	        bool ktra=false;
	        printf("\n\n");
       		printf("****-------------------------Danh sach sinh vien--------------------------****");
        	printf("\n%-8s %-10s %-30s %-20s %-5s", "MSV", "MaLop", "Ho ten", "Namsinh", "DTBTL");
	        while(p != NULL)
	        {
	        	char s[25];
				strcpy(s,p->Data.Hoten);
	        	strlwr(s);
				char *check=strstr(s, hten);
	            if(check!=NULL)
	            {
	            	ktra=true;
	                InSV(p);    
	            }
	            p = p->Next;
	        }
	        if(ktra==false)
	        	printf("\nKhong co nguoi nay!!!");
	    }
	    
	     void TT_Ngaysinh(LISTSV x , int ngay, int thang, int nam)
	    {
			NODE *p;
	        p = x.Dau;
	        bool ktra=false;
			printf("\n\n");
        	printf("****-------------------------Danh sach sinh vien--------------------------****");
        	printf("\n%-8s %-10s %-30s %-20s %-5s", "MSV", "MaLop", "Ho ten", "Namsinh", "DTBTL");
	        while(p != NULL)
	        {
	            if((p->Data.Birthday.ngay == ngay) && (p->Data.Birthday.thang == thang) && (p->Data.Birthday.nam == nam))
	            {
	            	ktra=true;	            	
	                InSV(p);
	            }
	            p = p->Next;
	        }
	        if(ktra==false)
	        	printf("\nKhong co nguoi nay!!!");
	    }
	    
	    void TT_DTBTL(LISTSV x , float n)
	    {
			NODE *p;
	        p = x.Dau;
	        bool ktra=false;
			printf("\n\n");
    		printf("****-------------------------Danh sach sinh vien--------------------------****");
        	printf("\n%-8s %-10s %-30s %-20s %-5s", "MSV", "MaLop", "Ho ten", "Namsinh", "DTBTL");
	        while(p != NULL)
	        {
	            if(p->Data.DTBTL == n)
	            {	
					ktra=true;	            	
	                InSV(p);
	            }
	            p = p->Next;
	        }
	        if(ktra==false)
	        	printf("\nKhong co nguoi nay!!!");
	    }
	    
	    void TextBoxSearchGeneral()
	    {
	    	
	    	TextColor(13);
			gotoXY(65,0);	printf("ESC: Thoat");
	    	gotoXY(15,1);	printf("Search: ");
	    	TextColor(15);
	    	
		}
		
		void printFinder(LISTSV x, char mang[])
		{
			printf("\n");
			strlwr(mang);
			int tongsv=0;

			NODE *p=x.Dau;
				
			while(p!=NULL)
			{
				//Ma sinh vien
				char msv[8];
				Mangrong(msv,9);
				sprintf(msv,"%08d",p->Data.Msv);
				if(strstr(msv,mang)!=NULL)
				{
					InSV(p);
					printf("\n");
					p=p->Next;
					tongsv++;
					continue;
				}
					
				//Ma lop
				char malop[8];
				Mangrong(malop,9);
				strcpy(malop,p->Data.MaLop);
				strlwr(malop);
				if(strstr(malop,mang)!=NULL)
				{
					InSV(p);
					printf("\n");
					p=p->Next;
					tongsv++;
					continue;
				}
				
				//Ho ten
				char hoten[25];
				Mangrong(hoten,26);
				strcpy(hoten,p->Data.Hoten);
				strlwr(hoten);
				if(strstr(hoten,mang)!=NULL)
				{
					InSV(p);
					printf("\n");
					p=p->Next;
					tongsv++;
					continue;
				}
				
				//Ngay sinh
				char ngaysinh[10];
				Mangrong(ngaysinh,11);
				char ngay[2], thang[2], nam[4];
				sprintf(ngay,"%d",p->Data.Birthday.ngay);
				sprintf(thang,"%d",p->Data.Birthday.thang);
				sprintf(nam,"%d",p->Data.Birthday.nam);
				strcat(ngaysinh,ngay);
				strcat(ngaysinh,"/");
				strcat(ngaysinh,thang);
				strcat(ngaysinh,"/");
				strcat(ngaysinh,nam);
				if(strstr(ngaysinh,mang)!=NULL)
				{
					InSV(p);
					printf("\n");
					p=p->Next;
					tongsv++;
					continue;
				}
				
				//DTBTL
				char dtbtl[5];
				sprintf(dtbtl,"%2.2f",p->Data.DTBTL);
				if(strstr(dtbtl,mang)!=NULL)
				{
					InSV(p);
					printf("\n");
					p=p->Next;
					tongsv++;
					continue;
				}
				p=p->Next;
			}
		}
		
	    void TT_Non_exactly(LISTSV x)
	    {
	    	int sokitu=0;
	    	int search=0;
	    	bool find=false;
	    	char mang[30];
	    	char n;
	    	while(1)
	    	{
	    		system("cls");
	    		TextBoxSearchGeneral();
	    		puts(mang);
	    		printf("\n");
				printf("****-------------------------Danh sach sinh vien--------------------------****");
        		printf("\n%-8s %-10s %-30s %-20s %-5s", "MSV", "MaLop", "Ho ten", "Namsinh", "DTBTL");
	    		if(sokitu==0)
	    			find=false;
	    		if(find!=false)
	    			printFinder(x,mang);
	    		gotoXY(sokitu+23,0);
				gotoXY(sokitu+23,1);
	    		n=getch();	
	    		//Thoat
	    		if(GetAsyncKeyState(27))
	    			break;
	    		//Backspace
	    		if(GetAsyncKeyState(8) && sokitu>0)
	    		{
	    			sokitu--;
	    			mang[sokitu]='\0';
	    			gotoXY(sokitu+23,1);	printf(" ");	    			
	    			continue;
				}
				if(((n>=(char)48 && n<=(char)57) || (n>=(char)65 && n<=(char)90) || (n>=(char)97 && n<=(char)122) || n==(char)47 || n==(char)46 || n==(char)32) && sokitu<=30)
				{
					find=true;
					mang[sokitu]=n;
					sokitu++;
					continue;
				}
			}
		}
	//----------------------------Tim kiem nhi phan-----------------------------  
	
		void Display_binarysearch(LISTSV L, int vitri)
		{
			NODE *p=L.Dau;
			for(int i=0; i<vitri; i++)
				p=p->Next;
			
			printf("\n\n");
			printf("****---------------------Danh sach sinh vien---------------------****");
		    printf("\n%-8s %-10s %-20s %-20s %-10s", "MSV", "MaLop", "Ho ten", "Namsinh", "DTBTL");
			int so=p->STT;
			while(p->STT == so)
			{
				InSV(p);
				printf("\n");
				p=p->Next;
			}
		}
		
		int Findfirst(LISTSV L, int STT, int first , int last)
		{
			if(last < first)
				return first;
				
				
			int mid=(first+last)/2;
			NODE *p=L.Dau;
			for(int i=0; i<mid; i++)
				p=p->Next;
		
			if(p->STT >= STT)
				return(Findfirst(L,STT,first,mid-1));
			else
				return(Findfirst(L,STT,mid+1,last));
			
		}
		  
		bool NP_MSV(LISTSV x, int msv, int nguoidau, int nguoicuoi)
		{
			if (nguoicuoi >= nguoidau)
			{
				NODE *m=x.Dau;
				//Tim mid
				int mid = (nguoidau+nguoicuoi)/2;
				for(int i=0; i<mid; i++)
					m=m->Next;
		        if (m->Data.Msv == msv)
				{
					printf("\n\n");
					printf("****---------------------Danh sach sinh vien---------------------****");
	        		printf("\n%-8s %-10s %-20s %-20s %-10s", "MSV", "MaLop", "Ho ten", "Namsinh", "DTBTL");
	        		InSV(m);        		
	        		getch();
					return true;
				}  
		        if (m->Data.Msv > msv) 
		            return NP_MSV(x, msv, nguoidau, mid-1);
		        else
		        	return NP_MSV(x, msv, mid+1, nguoicuoi);
			}
		 	else
				return false;
		}
		
		bool NP_ML(LISTSV x, char dulieu[], int nguoidau, int nguoicuoi)
		{
			if (nguoicuoi >= nguoidau)
			{
				NODE *m=x.Dau;
				//Tim mid
				int mid = (nguoidau+nguoicuoi)/2;
				for(int i=0; i<mid; i++)
					m=m->Next;
					
		        if (stricmp(m->Data.MaLop,dulieu)==0)
				{
					int vtri=Findfirst(x,m->STT,0,mid-1);
					Display_binarysearch(x,vtri);        		
	        		getch();
					return true;
				}  
		        if (strcmp(m->Data.MaLop,dulieu)>0)
		            return NP_ML(x, dulieu, nguoidau, mid-1);
		        else
		        	return NP_ML(x, dulieu, mid+1, nguoicuoi);
			}
		 	else
				return false;
		}
		
		void Tachten(NODE *p, char chuoisosanh[]);
		
		bool NP_Hten(LISTSV x, char dulieu[], int nguoidau, int nguoicuoi)
		{
			if (nguoicuoi >= nguoidau)
			{
				
				NODE *L=x.Dau;
				NODE *R=x.Dau;
				NODE *m=x.Dau;
				for(int i=0; i<nguoicuoi; i++)
					R=R->Next;	
				for(int i=0; i<nguoidau; i++)
					L=L->Next;
				//Tim mid
				int mid = (nguoidau+nguoicuoi)/2;
				for(int i=0; i<mid; i++)
					m=m->Next;
				char tenho[25];
				Mangrong(tenho,26);
				Tachten(m,tenho);
				strlwr(tenho);
		        if (stricmp(tenho,dulieu)==0)
				{
					int vtri=Findfirst(x,m->STT,0,mid-1);
					Display_binarysearch(x,vtri);        		
	        		getch();
					return true;
				}  
		        if (stricmp(tenho,dulieu)>0)
		            return NP_Hten(x, dulieu, nguoidau, mid-1);
		        else
		        	return NP_Hten(x, dulieu, mid+1, nguoicuoi);
			}
		 	else
				return false;
		}
				
		bool NP_Ngaysinh(LISTSV x, int day, int month, int year, int nguoidau, int nguoicuoi)
		{
			if (nguoicuoi >= nguoidau)
			{
				
				NODE *L=x.Dau;
				NODE *R=x.Dau;
				NODE *m=x.Dau;
				for(int i=0; i<nguoicuoi; i++)
					R=R->Next;	
				for(int i=0; i<nguoidau; i++)
					L=L->Next;
				//Tim mid
				int mid = (nguoidau+nguoicuoi)/2;
				for(int i=0; i<mid; i++)
					m=m->Next;
				int sosanh1=year*10000+month*100+day;	
				int sosanh2=m->Data.Birthday.nam*10000 + m->Data.Birthday.thang*100 + m->Data.Birthday.ngay;
				
		        if ((m->Data.Birthday.ngay == day) && (m->Data.Birthday.thang == month) && (m->Data.Birthday.nam == year))
				{
					int vtri=Findfirst(x,m->STT,0,mid-1);
					Display_binarysearch(x,vtri);        		        		
	        		getch();
					return true;
				}  
		        if (sosanh1 < sosanh2) 
		            return NP_Ngaysinh(x, day, month, year, nguoidau, mid-1);
		        else
		        	return NP_Ngaysinh(x, day, month, year, mid+1, nguoicuoi);
			}
		 	else
				return false;
		}
		
		bool NP_DTBTL(LISTSV x, float dtbtl, int nguoidau, int nguoicuoi)
		{
			if (nguoicuoi >= nguoidau)
			{
				NODE *L=x.Dau;
				NODE *R=x.Dau;
				NODE *m=x.Dau;
				for(int i=0; i<nguoicuoi; i++)
					R=R->Next;	
				for(int i=0; i<nguoidau; i++)
					L=L->Next;
				//Tim mid
				int mid = (nguoidau+nguoicuoi)/2;
				for(int i=0; i<mid; i++)
					m=m->Next;

		        if (m->Data.DTBTL == dtbtl)
				{
					int vtri=Findfirst(x,m->STT,0,mid-1);
					Display_binarysearch(x,vtri);        		
	        		getch();
					return true;
				}  
		        if (m->Data.DTBTL > dtbtl) 
		            return NP_DTBTL(x, dtbtl, nguoidau, mid-1);
		        else
		        	return NP_DTBTL(x, dtbtl, mid+1, nguoicuoi);
			}
		 	else
				return false;
		}
