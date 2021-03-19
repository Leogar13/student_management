/*
	Name: Chuong trinh quan ly sinh vien
	Copyright: Nguyen Anh Tung- HTTT 15
	Author: Nguyen Anh Tung
	Date: 05/03/18 15:24
	Description: Chuong trinh quan ly sinh vien va luu du lieu duoc luu vao file *.txt
*/

#include "Congcu.h"
#include "Login.h"
#include "Sinhvien.h"
#include "Menu.h"


int main()
{
  	Intro();
  	teacher=Dangnhap();
  	TextColor(15);
    Menu();
    return 0;
}
