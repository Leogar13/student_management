//Output
//----------------------Xuat ra man hinh------------------------------------
    //in sinh vien
    void InSV(NODE* p)
    {       
		printf("\n%08d %-10s %-30s %-d/%d/%d\t\t%-0.2f", p->Data.Msv, p->Data.MaLop, p->Data.Hoten, p->Data.Birthday.ngay, p->Data.Birthday.thang, p->Data.Birthday.nam, p->Data.DTBTL);
    }
    
    void TrangSV(LISTSV L, int firstperson, int finalperson)
    {
    	TextColor(15);
    	system("cls");
   		printf("****-------------------------Danh sach sinh vien--------------------------****");
        printf("\n%-8s %-10s %-30s %-20s %-5s", "MSV", "MaLop", "Ho ten", "Namsinh", "DTBTL");
    	NODE *q=L.Dau;
        //Xac dinh phan tu dau tien
        for(int i=0; i<firstperson; i++)
        	q=q->Next;
        //in trang
 		gotoXY(0,1);
   		int mau=14;
   		for(int i=firstperson; i<finalperson; i++)
        {
	    	if(q!=NULL)
	    	{
			    TextColor(mau);
			    InSV(q);
				q=q->Next;
			    printf("\n");
			    if(mau==14)
			       	mau=10;
			    else if(mau==10)
			       	mau=14;							            
			}
			else
			  	break;
		}
	}
     
    // in FULL danh sach SINHVIEN
    void InDanhSach(LISTSV *x, listlop danhsachlophoc)
    {
        bool Editcheck=false;
        
        int sotrang=1;
        int firstperson=0;
        int finalperson=10;
        TrangSV(*x,0,10);
        //in danh sach Sinh vien
        while(1)
        {
        	TrangSV(*x,firstperson, finalperson);
        	TextColor(480);
        	gotoXY(40,22);	printf("%d",sotrang);
        	TextColor(15);
        	if(sotrang <= (count-1)/10)
        	{			
				gotoXY(43,22);	printf("%d", sotrang+1);
			}
        	if(sotrang!=1)
        	{
        		gotoXY(37,22);	printf("%d",sotrang-1);
			}
			
			gotoXY(0,23);	printf("ESC:(Exit)			F1->Enter:Edit			F1->Del:Delete");
			
			if(Editcheck==true)
				goto tieptuc;
				
			
        	system("pause>nul");
        	//Fix
        	if(GetAsyncKeyState(112))
        	{
        		if(teacher==true)
	        	{
	        		tieptuc:;
	        		int Kquaedit=Edit(x,danhsachlophoc,firstperson, finalperson);
	        		if(Kquaedit==0)
	        			break;
	        		else if(Kquaedit==2)
	        		{	
	        			sotrang++;
	        			firstperson=finalperson;
	        			finalperson=finalperson+10;
						TrangSV(*x,firstperson,finalperson);	
						Editcheck=true;							        			
	        			continue;
					}
					else if(Kquaedit==3)
	        		{
	        			if(firstperson!=0)
	        			{
		        			sotrang--;
		        			finalperson=firstperson;
		        			firstperson=firstperson-10;
		        		}
						TrangSV(*x,firstperson,finalperson);
						Editcheck=true;
	        			continue;
					}	
					else if(Kquaedit==1)
					{
						//Delete
						TrangSV(*x,firstperson,finalperson);
						continue;
					}
				}
				else
				{
					Denied_Access();
					continue;
				}
			}
			//End
			if(GetAsyncKeyState(27))
        		break;
        	//control
        	if(GetAsyncKeyState(VK_RIGHT) && finalperson<count)
        	{
        		sotrang++;
        		firstperson=finalperson;
        		finalperson=finalperson+10;
        		        		
			}
        	if(GetAsyncKeyState(VK_LEFT) && firstperson!=0)
        	{
        		sotrang--;
        		finalperson=firstperson;
		        firstperson=firstperson-10;
		        
			}
        	
        }
    }
    
    //in Danh sach theo Lop
    void InDanhSachTheoLop(LISTSV L)
    {
    	char lop[8];
    	Mangrong(lop, 9);
    	int mau=14;
    	NODE *p=L.Dau;
    	system("cls");
    	printf("Tim theo ma lop nao: ");
    	gets(lop);
    	strupr(lop);
    	
    	SINHVIEN Classmate[count];
    	int Siso=0;
    	while(p!=NULL)
    	{
    		if(strstr(p->Data.MaLop,lop)!=NULL)
    		{
    			Classmate[Siso]=p->Data;
    			Siso++;
			}
			p=p->Next;
		}
		
		printf("****-------------------------Danh sach sinh vien--------------------------****");
        printf("\n%-8s %-10s %-30s %-20s %-5s", "MSV", "MaLop", "Ho ten", "Namsinh", "DTBTL");
		for(int i=0; i<10; i++)
		{
			if(mau==14)
        		mau=10;
       		else
        		mau=14;
       		TextColor(mau);
			if(i<Siso)
       		{					
	       		printf("\n%08d %-10s %-30s %-d/%d/%d\t\t%-0.2f",Classmate[i].Msv, Classmate[i].MaLop, Classmate[i].Hoten, Classmate[i].Birthday.ngay, Classmate[i].Birthday.thang, Classmate[i].Birthday.nam, Classmate[i].DTBTL);
	       		printf("\n");
	       	}
	       	else
	       		break;
		}
    	int sotrang=1;
        int firstperson=0;
        int finalperson=10;
        //in danh sach Sinh vien
        while(1)
        {
        	system("cls");
        	TextColor(15);
        	printf("****-------------------------Danh sach sinh vien--------------------------****");
        	printf("\n%-8s %-10s %-30s %-20s %-5s", "MSV", "MaLop", "Ho ten", "Namsinh", "DTBTL");
        	mau=14;
        	for(int i=firstperson; i<finalperson; i++)
        	{
        		if(mau==14)
        			mau=10;
       		 	else
        			mau=14;
        		TextColor(mau);
        		if(i<Siso)
        		{					
	        		printf("\n%08d %-10s %-30s %-d/%d/%d\t\t%-0.2f",Classmate[i].Msv, Classmate[i].MaLop, Classmate[i].Hoten, Classmate[i].Birthday.ngay, Classmate[i].Birthday.thang, Classmate[i].Birthday.nam, Classmate[i].DTBTL);
	        		printf("\n");
	        	}
	        	else
	        		break;
	        	
			}
        	TextColor(480);
        	gotoXY(40,22);	printf("%d",sotrang);
        	TextColor(15);
        	if(sotrang <= (Siso-1)/10)
        	{			
				gotoXY(43,22);	printf("%d", sotrang+1);
			}
        	if(sotrang!=1)
        	{
        		gotoXY(37,22);	printf("%d",sotrang-1);
			}
			
			gotoXY(0,23);	printf("ESC:(Exit)");	
			
        	system("pause>nul");
			//End
			if(GetAsyncKeyState(27))
        		break;
        	//control
        	if(GetAsyncKeyState(VK_RIGHT) && finalperson<Siso)
        	{
        		sotrang++;
        		firstperson=finalperson;
        		finalperson=finalperson+10;
        		        		
			}
        	if(GetAsyncKeyState(VK_LEFT) && firstperson!=0)
        	{
        		sotrang--;
        		finalperson=firstperson;
		        firstperson=firstperson-10;
		        
			}
        	
        }
	}
	
