//Data
	bool teacher;
	int count=0;
	char file[30];
	bool New=false;
    //-----------------Sinh Vien va danh sach-------------------
    
    typedef struct Date
    {
    	unsigned int ngay, thang, nam;
	}Date;
    
    typedef struct tagSINHVIEN {
        int Msv;
        char MaLop[8];
        char Hoten[25];
        Date Birthday;
        float DTBTL;
    }SINHVIEN;
     
    typedef struct tagNODE {
        SINHVIEN Data;
        int STT;
        struct tagNODE* Next;
    }NODE;
     
    typedef struct tagLIST {
        NODE* Dau;
        NODE* Cuoi;
    }LISTSV;
     
    //Khoi tao NODE
    NODE *KhoitaoNode()
    {
        NODE *x = (NODE*)malloc(sizeof(NODE));
        if(x == NULL)
        {
            printf("\n Bo nho khong du ");
            return 0;
        }
        x->Next = NULL;
        return x;
    }
     
    //Khoi tao danh sach LISTSV
    void KhoitaoList(LISTSV *x)
    {
        x->Dau = NULL;
        x->Cuoi	= NULL;
    }
	
//---------------------------Danh sach lop-------------------------
	     
    typedef struct Tenlop
	{
		char ten[8];
	}Tenlop;
	
	typedef struct tagnode {
        Tenlop lop;
        struct tagnode* Next;
    }node;
 
 	typedef struct taglistlop {
        node* Dau;
        node* Cuoi;
    }listlop;
     
    //Khoi tao NODE
    node *Khoitaonode()
    {
        node *x = (node*)malloc(sizeof(node));
        if(x == NULL)
        {
            printf("\n Bo nho khong du ");
            return 0;
        }
        x->Next = NULL;
        return x;
    }
     
    //Khoi tao danh sach LISTSV
    void Khoitaolist(listlop *x)
    {
        x->Dau = NULL;
        x->Cuoi	= NULL;
    }
       
//-------------------------Giai phong------------------------------------    

    //Giai phong bo nho
    void giaiphong(LISTSV *x, listlop *l)
    {
		NODE *p = x->Dau;
        NODE *a;
  	    while( p != NULL)
        {
            a = p;
            p = p->Next;
            free(a);
        }
        
        node *p1 = l->Dau;
        node *a1;
  	    while( p1 != NULL)
        {
            a1 = p1;
            p1 = p1->Next;
            free(a1);
        }
	}
	
