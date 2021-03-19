//So sanh
//------------------------So sanh---------------------------------------
	//------------------------So sanh MSV-------------------------------------
	void SSMsv(LISTSV *L)
	{
		int max=100000000;
		int STT=count;
		do
		{
			int trunggian=-1;
			NODE *p=L->Dau;
			while(p!=NULL)
			{
				int msv=p->Data.Msv;
				if(msv<max)
				{
					p->STT=STT;
					if(msv > trunggian)
						trunggian=msv;
				}
				p=p->Next;
			}
			max=trunggian;
			STT--;
		}while(STT>0);
	}
	//------------------------So sanh Malop-----------------------------------
	void SSMalop(LISTSV *L)
	{
		char max[8];
		int STT=count;
		for(int i=0; i<9; i++)
			max[i]=(char)122;
		do
		{
			char trunggian[8];
			Mangrong(trunggian,8);
			NODE *p=L->Dau;
			while(p!=NULL)
			{
				if(stricmp(p->Data.MaLop,max)<0)
				{
					if(strcmp(p->Data.MaLop,trunggian)>0)
						strcpy(trunggian,p->Data.MaLop);
					p->STT=STT;
				}
				p=p->Next; 
			}
			Mangrong(max,8);
			strcpy(max,trunggian);
			STT--;
		}while(STT>0);
	}
	//------------------------So sanh Ten-------------------------------------
	void Tachten(NODE *p, char chuoisosanh[])
	{
		char ten[25];
		Mangrong(ten,26);
		strcpy(chuoisosanh,p->Data.Hoten);
		bool ktradaucach=false;
		for(int i=strlen(p->Data.Hoten)-1; i>=0; i--)
		{
			if(chuoisosanh[i]==' ')
			{
				ktradaucach=true;
				chuoisosanh[i]='\0';
				i++;
				int j=0;
				//Tach ten
				do
				{
					ten[j]=chuoisosanh[i];
					chuoisosanh[i]='\0';
					j++;
					i++;
				}while(chuoisosanh[i]!='\0');
				ten[j]=(char)32;
				break;
			}
		}
		if(ktradaucach==true)
		{	
			//Cho chuoi so sanh vao mang
			strcat(ten,chuoisosanh);
			//Copy vao chuoi so sanh
			Mangrong(chuoisosanh,26);
			strcpy(chuoisosanh,ten);
		}
	}
	
	void SSTen(LISTSV *L)
	{
		int STT=count;
		char max[25];
		for(int i=0; i<26; i++)
			max[i]=(char)122;
		do
		{
			char trunggian[25];
			Mangrong(trunggian,26);
			char mangsosanh[25];
			NODE *p=L->Dau;
			while(p!=NULL)
			{
				Mangrong(mangsosanh,26);
				Tachten(p,mangsosanh);
				if(stricmp(mangsosanh,max)<0)
				{
					if(stricmp(trunggian,mangsosanh)<0)
						strcpy(trunggian,mangsosanh);
					p->STT=STT;
				}
				p=p->Next; 
			}
			Mangrong(max,26);
			strcpy(max,trunggian);
			STT--;
		}while(STT>0);
	}
	//------------------------So sanh Ngay sinh-------------------------------
	void SSNgaysinh(LISTSV *L)
	{
		int max=100000000;
		//so sanh va sap xep
		int STT=count;
		for(int i=0; i<count; i++)
		{
			int trunggian=0;
			NODE *p=L->Dau;
			while(p!=NULL)
			{
				//Cong thuc chuyen ngay thang nam sinh sang so tu nhien
				int ns=(p->Data.Birthday.nam *10000 + p->Data.Birthday.thang *100 +p->Data.Birthday.ngay);
				if(ns<max)
				{
					if(trunggian < ns)
						trunggian=ns;
					p->STT=STT;
				}
				p=p->Next; 
			}
			max=trunggian;
			STT--;
		}
	}
	//------------------------So sanh DTBTL-----------------------------------
	void SSDTBTL(LISTSV *L)
	{
		float max=11;
		int STT=count;
		do
		{
			float trunggian=-1;
			NODE *p=L->Dau;
			while(p!=NULL)
			{
				float dtb=p->Data.DTBTL;
				if(dtb<max)
				{
					p->STT=STT;
					if(trunggian < dtb)
						trunggian=dtb;
				}
				p=p->Next;
			}
			max=trunggian;
			STT--;
		}while(STT>0);
	}
//------------------------Sapxep----------------------------------------
	
	//------------------------Selection Sort----------------------------------
	void SelectSort(LISTSV *L)
	{	
	    NODE *p,*q,*min;
	    p=L->Dau;
	    while (p!=L->Cuoi)
	    {
	        min=p;
	        q=p->Next;
	        while (q!=NULL)
	        {
	            if(q->STT<min->STT)  
					min=q;
	            q=q->Next;
	        }
	        Swap(p,min);
	        p=p->Next;
	    }
	}
	//------------------------Insert Sort-------------------------------------
	void InsertSort(LISTSV *L)
	{
		for(NODE *check=L->Dau->Next;check!=NULL;check=check->Next)
		{
			NODE *p=L->Dau;
			do
			{
				if(p->Next==check)
				{
					if(p->STT > check->STT)
					{
						Swap(p,check);
						break;
					}
				}
				if(p->STT > check->STT)
				{
					while(p!=check)
					{
						Swap(p,check);
						p=p->Next;	
					}
					break;
				}
				p=p->Next;
			}while(p!=check);
		}
	}
	//------------------------Quick Sort--------------------------------------
	
	void QuickSort(LISTSV *L)
	{
		LISTSV l1, l2;
	    NODE *tag, *p;
	    if (L->Dau == L->Cuoi) return;
	
	    KhoitaoList(&l1);
	    KhoitaoList(&l2);
	    tag = L->Dau;
	    L->Dau = L->Dau->Next; //cap nhat lai head
	    tag->Next = NULL; //co lap tag
	
	
	    while (L->Dau != NULL) {
	        p = L->Dau; //co lap head
	        L->Dau = L->Dau->Next; //cap nhat head
	
	        p->Next = NULL;
	        if (p->STT < tag->STT) 
				Themdau(&l1, p);
	        else 
				Themdau(&l2, p);
	    }
	    QuickSort(&l1); //goi de quy sap xep  l1,l2
	    QuickSort(&l2);
	
	    //Noi l1,tag,l2
	    if (l1.Dau != NULL) {
	        L->Dau = l1.Dau;
	        l1.Cuoi->Next = tag;
	
	    } else {
	        L->Dau = tag;
	    }
	    if (l2.Dau != NULL) {
	        tag->Next = l2.Dau;
	        L->Cuoi = l2.Cuoi;
	    } else {
	        L->Cuoi = tag;
	    }
	}
		
		
	//------------------------Bubble Sort--------------------------------------
	
	/* Bubble sort the given linked lsit */
	void BubbleSort(LISTSV *L)
	{
	    int swapped, i;
	    NODE *ptr1=L->Dau;
	    NODE *lptr = NULL;
	 
	    /* Checking for empty list */
	    if (ptr1 == NULL)
	        return;
	    do
	    {
	        swapped = 0;
	        ptr1 = L->Dau;
	 
	        while (ptr1->Next != lptr)
	        {
	            if (ptr1->STT > ptr1->Next->STT)
	            { 
	                Swap(ptr1, ptr1->Next);
	                swapped = 1;
	            }
	            ptr1 = ptr1->Next;
	        }
	        lptr = ptr1;
	    }
	    while (swapped);
	}
	 

