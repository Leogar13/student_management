//Thong ke
//-------------------------Thong ke--------------------------------------	

void TinhtoanThongke(LISTSV *x,Tenlop Lop[], int TongSV[], float Xuatsac[], float Gioi[], float Kha[], float TB_Kha[], float TB[], float Yeu[], int *tongsolop)
{
		int solop=count;
		//--------------------------------Tim cac ten lop--------------------------
		NODE *tonglop=x->Dau;
		for(int i=0; i<count; i++)
		{
			strcpy(Lop[i].ten,tonglop->Data.MaLop);
			tonglop=tonglop->Next;
		}
		
		//Xoa trung lap
		for(int i=0;i<solop-1;i++)
		{
			for(int j=i+1; j<solop; j++)
			{
				if(strcmp(Lop[i].ten,Lop[j].ten)==0)
				{
					for(int k=j; k<solop-1; k++)
					{
//						Mangrong(Lop[k].ten,9);
						strcpy(Lop[k].ten,Lop[k+1].ten);
					}
					solop--;
					i--;
				}
			}
		}
		
		*tongsolop=solop;
			
		//--------------------------------Thong ke va tinh %--------------------------------
		float Xs[count], G[count], K[count], Tb[count], Tbk[count], y[count];
		for(int i=0; i<solop; i++)
		{
			TongSV[i]=0;
			Xs[i]=0; 
			G[i]=0; 
			K[i]=0; 
			Tb[i]=0; 
			Tbk[i]=0; 
			y[i]=0;
		}
		
		NODE *math=x->Dau;
		for(int i=0; i<count; i++)
		{
			int l;	
			for(int j=0; j<solop; j++)
			{
				if(strcmp(math->Data.MaLop,Lop[j].ten)==0)
				{
					TongSV[j]++;
					l=j;
					break;
				}
			}
			float diem = math->Data.DTBTL;
		//------------------------------------Bang diem--------------------------------------
			//----------------------------Xuat sac(3.6-4.0)-------------------------------
			if(diem >= 9.01 && diem <= 10.00)
				Xs[l]++;
			//----------------------------Gioi(3.2-3.59)----------------------------------
			else if(diem >= 8.01 && diem <= 9.00)
				G[l]++;
			//----------------------------Kha(2.5-3.19)-----------------------------------
			else if(diem >= 7.01 && diem <= 8.00)
				K[l]++;
			//----------------------------(2.3-2.49)--------------------------------------
			else if(diem >= 6.01 && diem <= 7.00)
				Tbk[l]++;
			//----------------------------(2.0-2.29)--------------------------------------
			else if(diem >= 5.00 && diem <= 6.00)
				Tb[l]++;
			//----------------------------(duoi 2.0)--------------------------------------
			else if(diem <= 4.99)
				y[l]++;
				
				math= math->Next;
		}	

		
		//----------------------------------Tinh %-----------------------------------------
		for(int i=0; i<solop; i++)
		{
			Xuatsac[i]=(Xs[i]/TongSV[i])*100;
			Gioi[i]=(G[i]/TongSV[i])*100;
			Kha[i]=(K[i]/TongSV[i])*100;
			TB[i]=(Tb[i]/TongSV[i])*100;
			TB_Kha[i]=(Tbk[i]/TongSV[i])*100;
			Yeu[i]=(y[i]/TongSV[i])*100;	
		}
}

void Thongke_Siso(Tenlop Lop[], int TongSV[], int solop)
{
	system("cls");
	printf("%-10s %-10s","Lop", "TongSV");
	printf ("\n");
	int mau=58;
	for(int i=0; i<solop; i++)
	{
		if(mau==58)
			mau=10;
		else 
			mau=58;
		TextColor(mau);
		printf("%-10s %-10d", Lop[i].ten, TongSV[i]);
		printf("\n");
	}
}

void Thongke_diem(Tenlop Lop[], float Xuatsac[], float Gioi[], float Kha[], float TB_Kha[], float TB[], float Yeu[], int solop)
{
	system("cls");
	printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s ","Lop", "Xuatsac", "Gioi", "Kha", "TB_Kha", "TB", "Yeu");
	printf ("\n");
	int mau=14;
	for(int i=0; i<solop; i++)
	{
		if(mau==14)
			mau=10;
		else 
			mau=14;
		TextColor(mau);
		printf("%-10s %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f", Lop[i].ten, Xuatsac[i], Gioi[i], Kha[i], TB_Kha[i], TB[i], Yeu[i]);
		printf("\n");
	}
}

