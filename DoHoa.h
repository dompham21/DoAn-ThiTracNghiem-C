#pragma once

#include <iostream>
#include <winbgim.h> 
#include <math.h>
#include <Windows.h>
#include <thread>

#include "DefineValues.h"
#include "function.h"
#include "Lop.h"
#include "MonHoc.h"
#include "CauHoiThi.h"
#include "Hour.h"
#include "DocGhi.h"
using namespace std;

bool stop_clock = true;  //Bien toan cuc de xu ly clock



/*===================Muc Luc=========================*/
void drawMainFrame(DanhSachLop dsLop, DanhSachMonHoc dsMonHoc, PTRCauHoi rootTree);

/* Reset ID */
void resetID(int arrID[]);
void resetIDDapAn(int arrID[]);
void resetIDNopBai(int arrID[]);

void reset_layout(int x1,int y1,int x2,int y2, int color);

/* Map ID */
void khoi_tao_mapID(short **mapID);
void giai_phong_mapID(short **mapID);
void setID(int x1,int y1,int x2,int y2, int ID,short **mapID);

/* Table*/
void tao_o(int x,int y,int x2,int y2);
void tao_dong(int x,int y,int chieu_cao,int slcot, int mang_do_dai[]);
void tao_title_table(int x, int y, char td[][50], int slcot, int mang_do_dai[]);
void tao_sott(int x, int y, int sldong, int chieu_cao,int page);
void tao_bang(int x, int y, int chieu_cao, int slcot, int sldong, int mang_do_dai[], char td[][50], int arrID[], short **mapID, int page);

/* Draw Common */
void tao_khung(int x1,int y1,int x2,int y2);
void taoTextInput(int x1,int y1,int x2,int y2,int id,short **mapID);
void tao_button(int x1,int y1,int x2,int y2,char* a,int color,int color_text, int ID, short **mapID);
void tao_circle(int x, int y,int radius,  int ID, short **mapID);
void tao_circle_checked(int x,int y,int radius);
void tao_circle_unchecked(int x,int y,int radius);
void reset_circle_checked();
void reset_circle_checked_CH();

/* Scan */
void nhapTextAutoBreak(int x, int y, char s[], int maxLen);
void nhapText(int x, int y,int x1, int y1, char s[], int maxLen, int space);
void nhapSo(int x, int y, char so[], int maxLen);
void nhapPassword(int x, int y, char s[], char decode[],int maxLen);

/* Clock */
void printClock(int soPhut);

/* Alert */
void thongBaoDangNhap(int x1, int y1, int x2, int y2, char s[]);
void canhBaoXoa(short **mapID);

/* Function Login */
void drawMainLogin(short **mapID, DanhSachLop dsLop, DanhSachMonHoc dsMonHoc, PTRCauHoi rootTree, int arrID[]);
void checkMouseLogin(short **mapID, DanhSachLop dsLop, DanhSachMonHoc dsMonHoc, PTRCauHoi rootTree, int arrID[]);
PTRSinhVien xuLyDangNhap(DanhSachLop dsLop, char username[], char password[], int &check);

/* Function Before Thi */
void drawBeforeThi(short **mapID, DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree, int arrID[], PTRSinhVien p);
void checkMouseBeforeThi(short **mapID, DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree, int arrID[], PTRSinhVien p);
int xuLyBeforeThi(DanhSachMonHoc dsMonHoc, PTRSinhVien p,char maMonHoc[], char soPhut[], char soCauHoi[], int maxSoCauHoi);

/* Function Thi */
void drawThi(short **mapID, int arrID[],  CauHoiThi arrayCauHoiRandom[], int soCauHoi, int soPhut, char maMonHoc[] , char *luuDapAnChon, PTRSinhVien p, DanhSachLop dsLop, PTRCauHoi rootTree, DanhSachMonHoc dsMonHoc);
void checkMouseThi(short **mapID, int arrID[], CauHoiThi arrayCauHoiRandom[], int soCauHoi,  char maMonHoc[], int &page,  char *luuDapAnChon, PTRSinhVien p,  DanhSachLop dsLop, PTRCauHoi rootTree, DanhSachMonHoc dsMonHoc);
void drawCauHoi(short **mapID, int arrID[],  CauHoiThi arrayCauHoiRandom[], int soCauHoi , int page, char *luuDapAnChon);

/* Function Cham Diem */
void drawChamDiem(short **mapID, int arrID[],  CauHoiThi arrayCauHoiRandom[], int soCauHoi, char maMonHoc[], char *luuDapAnChon, PTRSinhVien p, DanhSachLop dsLop, PTRCauHoi rootTree, DanhSachMonHoc dsMonHoc);
void checkMouseThoat(short **mapID, DanhSachMonHoc dsMonHoc,  DanhSachLop dsLop, PTRCauHoi rootTree, int arrID[]);

/* Menu GV */
void drawMainMenu(short **mapID, DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree, int arrID[]);
void checkMouseMenu(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree);
/* QL Lop Hoc */
int xuLyNhapLop( DanhSachLop dsLop, char maLop[], char tenLop[]);
void drawInputXoaLop(short **mapID, int arrID[], char maLop[], char tenLop[]);
void drawInputSuaLop(short **mapID, int arrID[], char maLop[], char tenLop[]);
void inDSLop(short **mapID,  DanhSachLop dsLop, int arrID[], int page);
void drawInputLop(short **mapID, int arrID[]);
void selectSuaLop(short **mapID, int arrID[], int state, int page, DanhSachLop dsLop, char maLopSua[], char tenLopSua[]);
void checkMouseQLLop(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree);
void drawQLLop(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree);

/* QL Sinh Vien */
int xuLyNhapSinhVien(DanhSachLop dsLop,char maSV[], char ho[], char ten[], char password[], int gioiTinh);
void drawDSSinhVien(short **mapID, int arrID[],  LopHoc *lh, int pageSV );
void drawInputSuaSV(short **mapID, int arrID[], char maSV[], char ho[], char ten[], char password[], char gioiTinh[]);
void drawInputThemSV(short **mapID, int arrID[]);
void selectSuaSinhVien(short **mapID, int arrID[], DanhSachLop dsLop,  int state, int viTri, int pageSV, int page, char maSVSua[], char hoSua[], char tenSua[], char passwordSua[], int &gioiTinhSua);
void selectXoaSinhVien(short **mapID, int arrID[], DanhSachLop dsLop,  int state, int viTri, int pageSV, int page);
void drawInputTimSV(short **mapID);
void checkMouseQLSinhVien(short **mapID, int arrID[],  DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree);
void drawQLSinhVien(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree);

/* QL Mon Hoc */
void drawDSMonHoc(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, int page);
void drawInputMonHoc(short **mapID);
void selectSuaMonHoc(short **mapID, int state, int page, DanhSachMonHoc dsMonHoc, char maMHSua[], char tenMHSua[]);
void drawInputXoaMonHoc(short **mapID, char maMH[], char tenMH[]);
void checkMouseQLMonHoc(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree);
void drawQLMonHoc(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree);

/* QL Cau Hoi Thi */
void drawInputXemTheoMon(short **mapID);
void drawDSCauHoi(short **mapID, int arrID[], PTRCauHoi rootTree, int page, CauHoiThi arr[], int soLuong);
void drawChiTietCauHoiTheoMon(short **mapID, PTRCauHoi rootTree, int page, char maMH[]);
void drawInputSuaCauHoi(short **mapID, CauHoiThi arr[], int vitri, int page, char noiDungSua[], char dapAnASua[], char dapAnBSua[], char dapAnCSua[], char dapAnDSua[], char &dapAnSua, char maMHSua[]);
void drawInputXoaCH(short **mapID, CauHoiThi arr[], int vitri, int page);
void drawChiTietCauHoi(short **mapID, CauHoiThi arr[], int vitri, int page);
void drawInputThemCauHoi(short **mapID);
void checkMouseQLCauHoi(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree, CauHoiThi arr[]);
void drawQLCauHoi(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree);

/* QL Diem Thi */
void selectLopXemDiem(short **mapID,  int arrID[], DanhSachLop dsLop, DanhSachMonHoc dsMonHoc, int vitri, int page);
void drawChiTietBaiThiSV(short **mapID, int arrID[], CauHoiThi arr[], int page, char maMH[], PTRDiemThi p);
void drawDSBaiThiSV(short **mapID, int arrID[], MonHoc mh, LopHoc *lh,  int vitri, int pageSV, int pageCH);
void drawDSDiemThi(short **mapID, int arrID[], MonHoc mh, LopHoc *lh, PTRCauHoi rootTree, int page);
void checkMouseQLDiemThi(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree);
void drawQLDiemThi(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree);
/*===================END Muc Luc=====================*/




void resetID(int arrID[]) {

	/*
		- Khoi tao array ID;
		- arrID[0] la id phan login tu 2->4
		- arrID[1] la id phan truoc khi thi tu 6->9
		- arr[2] la id phan button submit, next and prev tu 11->13
		- arr[3] la id phan chon dap an tu 15 -> 18
		- arr[4] la id phan canh bao nop bai tu 20->21, 22 check time over
		- arr[5] la id phan cham diem 24
		- arr[6] la id phan menu giao vien tu 26-31
	*/
	arrID[0] = 1;
	arrID[1] = 5; 
	arrID[2] = 10;
	arrID[5] = 23;
	arrID[6] = 25;
	arrID[7] = 101; //ds lop
	arrID[8] = 186; //ds mon hoc
	arrID[9] = 200; // ds cau hoi
	arrID[10] = 230; //ds diem thi
	arrID[11] = 158; //ds sinh vien
	
}

void resetIDDapAn(int arrID[]) {
	arrID[3] = 14;
}

void resetIDNopBai(int arrID[]) {
	arrID[4] = 19;
}
void reset_layout(int x1,int y1,int x2,int y2, int color) { //ve chong bar len ben tren 
	setfillstyle(1,color);
	bar(x1,y1,x2,y2);
}

/* ===== MAP ID ===== */
void khoi_tao_mapID(short **mapID){
	for(short i=0; i<=WIDTH; i++){
		for(short j=0; j<=HEIGHT; j++){
			mapID[i][j] = 0;
		}
	}
}

void giai_phong_mapID(short **mapID){
	for(short x = 0; x <= WIDTH; x++)  
		delete[] mapID[x];
	delete[] mapID;
}

// Set mot vung id 
void setID(int x1,int y1,int x2,int y2, int ID,short **mapID){
	for(short x=x1;x<=x2;x++){
		for(short y = y1;y<=y2;y++) {
			mapID[x][y] = ID;
		}
	}
}
/* ===== END MAP ID ===== */


void tao_o(int x,int y,int x2,int y2){
	setfillstyle(1, 15);
	bar(x, y, x + x2, y + y2);
	setcolor(0);
	rectangle(x,y,x+x2,y+y2);
}

void tao_dong(int x,int y,int chieu_cao,int slcot, int mang_do_dai[]){
	for(int i=0;i<slcot;i++){
		tao_o(x,y,mang_do_dai[i],chieu_cao);
		x += mang_do_dai[i];
	}
}

void tao_title_table(int x, int y, char td[][50], int slcot, int mang_do_dai[]){
	//1 length string = 12px
	for(int i=0;i<slcot;i++){
	
		settextstyle(10,0,2);
		setbkcolor(MAU_TRANG);
		outtextxy(x + mang_do_dai[i]/2 - strlen(td[i])*12/2,y + 10,td[i]); //can deu title cua bang 
		x += mang_do_dai[i];
	}
}

void tao_sott(int x, int y, int sldong, int chieu_cao,int page) {
	for(int i = (page*10 +1); i < 10*(page+1)+1; i++) {
		settextstyle(10,0,2);
		setbkcolor(MAU_TRANG);
		char temp[10];
		itoa(i,temp,10);
		outtextxy(x + 10,y + 10, temp);
		y += chieu_cao;
	}
}

void tao_bang(int x, int y, int chieu_cao, int slcot, int sldong, int mang_do_dai[], char td[][50], int arrID[], short **mapID, int page) {
	int vt = y;

	for(int i = 0; i < sldong; i++) {
		vt = y + chieu_cao*i;
		tao_dong(x, vt, chieu_cao, slcot, mang_do_dai);
				
	}
	
	tao_title_table(x, y, td, slcot, mang_do_dai);
	tao_sott(x, y + chieu_cao, sldong, chieu_cao, page);
}

void tao_khung(int x1,int y1,int x2,int y2){
	setcolor(0);
	rectangle(x1,y1,x2,y2);
}

void taoTextInput(int x1,int y1,int x2,int y2,int id,short **mapID) {
	setcolor(MAU_DEN);
	

	setfillstyle(1,MAU_TRANG);
	setcolor(MAU_DEN);
		
	bar(x1,y1,x2,y2); 
	tao_khung(x1,y1,x2,y2);
	//reset mau chu
	setbkcolor(MAU_TRANG);
	setcolor(MAU_DEN);
	setID(x1, y1, x2, y2, id, mapID);
}

void tao_button(int x1,int y1,int x2,int y2,char* a,int color,int color_text, int ID, short **mapID){
	setfillstyle(1,color);
	bar(x1,y1,x2, y2);
	
	settextstyle(10,0,1);
	setbkcolor(color);
	setcolor(color_text);

	outtextxy(x1+(x2-x1)/2 - strlen(a)*12/2,y1+5,a);	
	setbkcolor(MAU_NEN); //reset lai bk

	if(ID == -2) {
		return;  //Neu button la label thi khong can setID
	}
	else {
		setID(x1,y1,x2,y2,ID,mapID);
	}

}

void tao_circle(int x, int y,int radius,  int ID, short **mapID) {
	circle(x, y, radius);
	setID(x-radius,y-radius,x+radius,y+radius,ID,mapID);

}

void tao_circle_checked(int x,int y,int radius) {
	setfillstyle(1,MAU_DO);
	fillellipse(x,y,radius,radius);
}

void tao_circle_unchecked(int x,int y,int radius) {
	setcolor(MAU_NEN);
	setfillstyle(1,MAU_NEN);
	fillellipse(x,y,radius,radius);
	setcolor(MAU_DEN);

}

void reset_circle_checked() {
	tao_circle_unchecked(200,350,8);
	tao_circle_unchecked(200,450,8);

	tao_circle_unchecked(200,550,8);

	tao_circle_unchecked(200,650,8);

}


void reset_circle_checked_CH() {
	tao_circle_unchecked(130,320,8);
	tao_circle_unchecked(130,450,8);

	tao_circle_unchecked(130,580,8);

	tao_circle_unchecked(130,710,8);
}


void nhapTextAutoBreak(int x, int y, char s[], int maxLen) {
	while(kbhit())	char c= getch();   //======nuot phim khi chua click

	setcolor(MAU_DEN);
	setbkcolor(MAU_TRANG);
	settextstyle(10,0,2);

	int l = strlen(s);
	s[l+1] = '\0';
	s[l] = '|';

	
	while(true){
		delay(0.0001);
		clearmouseclick(WM_LBUTTONDOWN);

		if(kbhit()){
			char c = getch();
			if((' ' <= c && c <= '~' ) && (l < maxLen )){ //tu 33 den 125
				
				s[l] = c;
				l++;
				s[l] = ' '; //ky tu ket thuc
				s[l] = '\0';
				
				if(strlen(s) < 60) {
					outtextxy(x,y,s);
				}
				else if(strlen(s) >= 60 ) {
					char res1[126] = "";
					char res2[126] = "";
					char str_temp[126] = "";  //su dung str_temp de khong phai thay doi du lieu 
					
					xoaKhoangTrangDauVaKeNhau(s);
					
					l = strlen(s);
		    		strcpy(str_temp,s);
		    		catChuoi2Dong(str_temp,res1,res2);
		    		reset_layout(x,y,1000,y+20,MAU_TRANG);
					outtextxy(x,y,res1);
					outtextxy(x,y+30,res2);
				}
			
			}
			else if(c==8 && l!=0){ //backspace
	
				s[l-1] = '|';
				s[l] = '\0';
				
				if(strlen(s) < 60) {
					reset_layout(x,y,1000,y+20,MAU_TRANG);

					outtextxy(x,y,s);

				}
				else if(strlen(s) >= 60) {
					char res1[126] = "";
					char res2[126] = "";
					char str_temp[126] = "";  //su dung str_temp de khong phai thay doi du lieu 
					
					
		    		strcpy(str_temp,s);
		    		catChuoi2Dong(str_temp,res1,res2);	    		
		    		reset_layout(x,y,1000,y+20,MAU_TRANG);
		    		
					outtextxy(x,y,res1);
					outtextxy(x,y+30,res2);
				}
			
	
				if(strlen(s) == 61) {
					reset_layout(x,y+30,1000,y+50,MAU_TRANG);
				}
			
				l--;

						
			}
			else if(c==13){ // check enter
				s[l] = '\0';
				xoaKhoangTrangDauVaKeNhau(s);
				xoaKhoangTrangCuoi(s);
				
				if (s[0] >= 'a' && s[0] <= 'z')
                	s[0] = s[0] - 32;
               if(strlen(s) < 60) {
					outtextxy(x,y,s);
				}
				else if(strlen(s) >= 60 ) {
					char res1[126] = "";
					char res2[126] = "";
					char str_temp[126] = "";  //su dung str_temp de khong phai thay doi du lieu 
					
				
		    		strcpy(str_temp,s);
		    		catChuoi2Dong(str_temp,res1,res2);
		    		reset_layout(x,y,1000,y+20,MAU_TRANG);
					outtextxy(x,y,res1);
					outtextxy(x,y+30,res2);
				}
				break;
			}
					
		
		}
		else { //neu khong co phim nhap vao
			s[l] = '|';
			delay(100);
			
			if(strlen(s) < 60) {
				outtextxy(x,y,s);
			}
			else if(strlen(s) >= 60 ) {
				char res1[126] = "";
				char res2[126] = "";
				char str_temp[126] = "";  //su dung str_temp de khong phai thay doi du lieu 
				
		   		strcpy(str_temp,s);
		   		catChuoi2Dong(str_temp,res1,res2);
				reset_layout(x,y,1000,y+20,MAU_TRANG);
		    		
				outtextxy(x,y,res1);
				outtextxy(x,y+30,res2);
			}
		

			s[l] = ' ';
			delay(100);
			
			if(strlen(s) < 60) {
				outtextxy(x,y,s);
			}
			else if(strlen(s) >= 60 ) {
				char res1[126] = "";
				char res2[126] = "";
				char str_temp[126] = "";  //su dung str_temp de khong phai thay doi du lieu 
		   		strcpy(str_temp,s);
		   		catChuoi2Dong(str_temp,res1,res2);
		   		
		   		reset_layout(x,y,1000,y+20,MAU_TRANG);
		    		
				outtextxy(x,y,res1);
				outtextxy(x,y+30,res2);
			}
			
		}	
	}
}

// Neu space = 1 thi khong cho nhap space , neu space = 0 thi cho nhap space
void nhapText(int x, int y,int x1, int y1, char s[], int maxLen, int space){
	while(kbhit())	char c= getch();   //======nuot phim khi chua click

	setcolor(MAU_DEN);
	setbkcolor(MAU_TRANG);
	settextstyle(10,0,2);

	int l = strlen(s);
	s[l+1] = '\0';
	s[l] = '|';
	while(true){
		outtextxy(x,y,s);
		delay(0.0001);
		clearmouseclick(WM_LBUTTONDOWN);

		if(kbhit()){
			char c = getch();
				//Neu space = 1 thi khong cho nhap space, space = 0 thi cho nhap space 

			if(('a'<=c && c<='z'||'A'<=c && c<='Z'||'0'<=c && c<='9' ) && l < maxLen && space == 1){
				if('a' <= c && c<= 'z') {
					c = c - 32;
				}
				s[l] = c;
				l++;
				s[l] = '\0'; //ky tu ket thuc
			
				outtextxy(x,y,s);
			
			}
			else if(('a'<=c && c<='z'||'A'<=c && c<='Z'||'0'<=c && c<='9' || c == ' ' ) && l < maxLen && space == 0){
			
				s[l] = c;
				l++;
				s[l] = '\0'; //ky tu ket thuc
				outtextxy(x,y,s);
			}
			else if(c==8 && l!=0){ //backspace
	
				s[l-1] = '|';
				s[l] = ' ';
				outtextxy(x,y,s);
				l--;					
					
			}
			else if(c==13){ // check enter
				s[l] = '\0';
				if(space == 0) {
					reset_layout(x, y, x1 - 1, y1 - 1, MAU_TRANG);
					validateText(s);
				}
				outtextxy(x,y,s);
				break;
			}
					
		
		}
		else { //neu khong co phim nhap vao
			s[l] = '|';
			delay(100);
			outtextxy(x,y,s);
			s[l] = ' ';
			delay(100);
			outtextxy(x,y,s);
		}	
	}
}

void nhapSo(int x, int y, char so[], int maxLen) {
	while(kbhit())	char c= getch();   //======nuot phim khi chua click

	setcolor(MAU_DEN);
	setbkcolor(MAU_TRANG);
	settextstyle(10,0,2);

	int l = strlen(so);
	so[l+1] = '\0';
	so[l] = '|';

	while(true){
		outtextxy(x,y,so);
		delay(0.0001);
		clearmouseclick(WM_LBUTTONDOWN);

		if(kbhit()){
			char c = getch();
			if('0'<=c&&c<='9' && l < maxLen ){
				
				so[l] = c;
				l++;
				so[l] = '\0'; //ky tu ket thuc
				outtextxy(x,y,so);
			
			}
		
			else if(c==8 && l!=0){ //backspace
	
				so[l-1] = '|';
				so[l] = ' ';
				outtextxy(x,y,so);
				l--;					
					
			}
			else if(c==13){ // check enter
				so[l] = '\0';
				break;
			}
					
		
		}
		else { //neu khong co phim nhap vao
			so[l] = '|';
			delay(100);
			outtextxy(x,y,so);
			so[l] = ' ';
			delay(100);
			outtextxy(x,y,so);
		}	
	}
}

// Ham nhap password hien thi ra ki tu '*'

void nhapPassword(int x, int y, char s[], char decode[],int maxLen)
{
	while(kbhit())	char c= getch();   //======nuot phim khi chua click

	setcolor(MAU_DEN);
	setbkcolor(MAU_TRANG);
	settextstyle(10,0,2);
	int l = strlen(s);
	s[l+1] = '\0';
	decode[l] = '|';
	decode[l+1] = '\0';
	

	while(true){
		outtextxy(x,y,decode);
		delay(0.001);
		clearmouseclick(WM_LBUTTONDOWN);

		if(kbhit()){
			char c = getch();
			if(('a' <= c && c <= 'z' || 'A'<= c && c <= 'Z' || '0' <= c && c <= '9')&& l < maxLen ){
				if('a' <= c && c<= 'z') {
					c = c - 32;
				}
				decode[l] = '*';
				s[l] = c;
				l++;
				
				decode[l] ='\0';
				s[l] = '\0'; //ky tu ket thuc
			
				outtextxy(x,y,decode);
				
			}
			else if(c == 8 && l != 0){ //backspace
				decode[l-1] = '|';
				decode[l] = ' ';
				
				outtextxy(x,y,decode);
				l--;					
					
			}
			else if(c == 13){ // check enter
				decode[l] = '\0';
				s[l] = '\0';
				break;
			}
					
		}
		else { //neu khong co phim nhap vao
			decode[l] = '|';
			delay(100);
			outtextxy(x,y,decode);
			decode[l] = ' ';
			delay(100);
			outtextxy(x,y,decode);
		}	
	}
}

void printClock(int soPhut) {
	settextstyle(10,0,3);
	Hour h;
	chuyenSoPhut(h, soPhut);
	char a[9] = { '0','0',':','0','0',':','0','0','\0'};
		
	chenVaoMang(a, h); // ve truoc 
	outtextxy(1100,40,a);
		
	while (stop_clock) { 
		if (!thayDoiTime(h)) stop_clock = false; //het time
		chenVaoMang(a, h);
		settextstyle(10,0,3);

		if(h.minute < 1 && h.second >=0) { //neu thoi gian duoi 1 phut 
			setcolor(MAU_DO_NHAT);
			outtextxy(1100,40,a);
			setcolor(MAU_DEN);

		}
		else {
			outtextxy(1100,40,a);
		}

		Sleep(990);
	}
	
	
	if(!stop_clock) {
		reset_layout(1100,40,1300,200,MAU_NEN); //xoa clock
	}
	return;
}

void thongBaoDangNhap(int x1, int y1, int x2, int y2, char s[]){
		setbkcolor(MAU_NEN);
		setfillstyle(1,MAU_NEN);
		outtextxy(x1,y1,s);
		delay(1000);
		bar(x1-10,y1,x2,y2);
}

void checkMouseThoat(short **mapID, DanhSachMonHoc dsMonHoc,  DanhSachLop dsLop, PTRCauHoi rootTree, int arrID[]) {
	int x = - 1, y = -1;


	while (1) {
		delay(0.001); //delay nhan click 

		int ID = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			ID = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		switch(ID) {
			case 24: {
				giai_phong_mapID(mapID);
				delay(1000);
				exit(0);
				break;
			}
			case 25: {
				drawMainMenu(mapID, dsMonHoc, dsLop, rootTree, arrID);
				break;
			}
			default:
				break;			
		}
		
	}
}
void drawChamDiem(short **mapID, int arrID[],  CauHoiThi arrayCauHoiRandom[], int soCauHoi, char maMonHoc[], char *luuDapAnChon, PTRSinhVien p, DanhSachLop dsLop, PTRCauHoi rootTree, DanhSachMonHoc dsMonHoc) {
	stop_clock = false;
	char titleTable[][50] = {
		"Diem So: ", "Ten Sinh Vien: ", "So Cau Dung: ",
	};
	resetID(arrID);
	reset_layout(0, 0, WIDTH, HEIGHT, MAU_NEN);
	
	
	setbkcolor(MAU_NEN);
	settextstyle(10,0,4);	

	char tempFloat[10];
	char tempInt[10];
	int soCauDung = 0;
	for (int i = 0;i < soCauHoi;i++)
	{	
		if (luuDapAnChon[i] == arrayCauHoiRandom[i].dapAn)
		{
			soCauDung++;
		}
	}

	float tongDiem = 0;
	tongDiem = roundf(((10/(float)soCauHoi)*soCauDung) * 100)/100; // Lam tron den so thap phan thu 2

	ftoa(tongDiem,tempFloat,2);
	tao_khung(150,200,1200,500);
	
	if(p == NULL) { // Ket qua thi thu? khong luu
		outtextxy(460,220, "Ket qua thi thu dat duoc la:");
		//So cau dung
		itoa(soCauDung, tempInt, 10);
		strcat(titleTable[2], tempInt);
		strcat(titleTable[2], "/");
		itoa(soCauHoi, tempInt, 10);
		strcat(titleTable[2], tempInt);
		//Diem so
		strcat(titleTable[0],tempFloat);
		outtextxy(220, 350, titleTable[2]);
		outtextxy(220, 400, titleTable[0]);
		
		tao_button(600,600,760,630,"Quay lai menu",MAU_HONG,MAU_DEN,25,mapID);
	}
	else {
		outtextxy(460,220,"Ket qua ban dat duoc la:");
		//Ten sinh vien
		strcat(titleTable[1], p->sv.ho); 
		strcat(titleTable[1], " ");
		strcat(titleTable[1], p->sv.ten);
		//So cau dung
		itoa(soCauDung, tempInt, 10);
		strcat(titleTable[2], tempInt);
		strcat(titleTable[2], "/");
		itoa(soCauHoi, tempInt, 10);
		strcat(titleTable[2], tempInt);
		//Diem so
		strcat(titleTable[0],tempFloat);
	
		outtextxy(220, 300, titleTable[1]);
		outtextxy(220, 350, titleTable[2]);
		outtextxy(220, 400, titleTable[0]);
		
		
		
		
		
		DiemThi dt;  
	
		strcpy(dt.maMH,maMonHoc); 
		dt.diem = tongDiem;
		dt.bt.soCauHoi = soCauHoi;
		
		dt.bt.cht = new CauHoiThi[soCauHoi];
		dt.bt.dapAnDaChon = new char[soCauHoi];
		
		for (int i = 0; i < soCauHoi; i++) {
				dt.bt.cht[i] = arrayCauHoiRandom[i];
				dt.bt.dapAnDaChon[i] = luuDapAnChon[i];
		}
	
		themMotDiemThi(p->sv.dsDiemThi,dt);	
		
		for (int i = 0; i < dsLop.soLuong; i++) {
			luuFileDSDiem(dsLop.lh[i]->dsSinhVien, dsLop.lh[i]->maLop);
		}
		
		
		giaiPhongDSLop(dsLop);
		giaiPhongCay(rootTree);
		
		tao_button(600,600,680,630,"Thoat",MAU_HONG,MAU_DEN,++arrID[5],mapID);
	}
	


	checkMouseThoat(mapID, dsMonHoc, dsLop, rootTree, arrID);
}



/*
	Nen hay khong khong cho nhap khoang trang
	Neu dang nhap thanh cong voi tu cach giao vien thi tra ve 1
	Neu dang nhap thanh cong voi tu cach sinh vien thi tra ve 0
	Neu dang nhap that bai tra ve 2
	Neu chuoi rong thi tra ve 1
	Neu dang nhap that bai voi tu cach giao vien o if dau tien thi no se chay them vong lap nua nen hay khong ?
*/


PTRSinhVien xuLyDangNhap(DanhSachLop dsLop, char username[], char password[], int &check) {
	if(kiemTraChuoiRong(username) == 1 || kiemTraChuoiRong(password) == 1) {
		check = 3;
		return NULL;
	}
	if(strcmp(username,"GV") == 0 && strcmp(password,"GV") == 0) {
		check  = 1;
		return NULL;
	} 
	else {
		// Duyet trong dssv kiem tra masv voi mat khau. neu dung thi return 0 la quyen sv
		
		for(int i = 0; i < dsLop.soLuong; i++) {
			PTRSinhVien p =  dsLop.lh[i]->dsSinhVien;
			
			while(p != NULL) {
			
				if (strcmp(p->sv.maSV, username) == 0 && strcmp(p->sv.password, password) == 0)
				{
					check = 0;
					return p;
				}
				p = p->next;
			}	
		}		
		check = 2;
		return NULL;
	}
}

int xuLyBeforeThi(DanhSachMonHoc dsMonHoc, PTRSinhVien p,char maMonHoc[], char soPhut[], char soCauHoi[], int maxSoCauHoi) {
	
	if(kiemTraChuoiRong(maMonHoc) == 1 || kiemTraChuoiRong(soCauHoi) == 1 || kiemTraChuoiRong(soPhut) == 1) {	
		return 1;
	}
	
	if(!ktTrungMaMonHoc(maMonHoc, dsMonHoc)) {
		return 2;
	}
	
	int soCauHoiInt = atoi(soCauHoi);
	int soPhutInt = atoi(soPhut);
	if(maxSoCauHoi == 0) {
		return 6;
	}
	if( 0 >= soCauHoiInt || soCauHoiInt > maxSoCauHoi) {
		return 3;
	}
	if(soPhutInt <= 0 ||soPhutInt > 1440) {  // So phut phai lon hon 0 va be hon = 1 ngay (gioi han 1 ngay)
		return 4;
	}
	
	if(p == NULL) {
		return 0;
	}
	else if(KTSinhVienDaThiChua(p,maMonHoc)){ //da thi mon nay roi
		
		return 5;	
	}

		  			


	return 0;
}


void drawCauHoi(short **mapID, int arrID[],  CauHoiThi arrayCauHoiRandom[], int soCauHoi , int page, char *luuDapAnChon) {
	reset_layout(151,201,1199,769, MAU_NEN);
	resetIDDapAn(arrID);
	
	settextstyle(10,0,3);
	setbkcolor(MAU_NEN);
	
	char temp[10];  // strcat voi mot so , in cau hoi hien tai
	char buffer[10];
	strcpy(temp,"Cau ");
	itoa(page+1,buffer,10);
	strcat(temp,buffer);
	strcat(temp, ":");
	outtextxy(180,220,temp);
	
	
	if(strlen(arrayCauHoiRandom[page].noiDung) > 60) { //auto break line, neu length noi dung hon 60 thi xuong dong`
			char res1[126];
    		char res2[126];
    		char str_temp[126];  //su dung str_temp de khong phai thay doi du lieu cua arrayCauHoiRandom khi chuyen trang
    		strcpy(str_temp,arrayCauHoiRandom[page].noiDung);
    		catChuoi2Dong(str_temp,res1,res2);

			outtextxy(280,220,res1);
			outtextxy(190,245,res2);
	}
	else {
		outtextxy(280,220,arrayCauHoiRandom[page].noiDung);
	}
	
	
	
	 //in cau hoi
	tao_circle(200,350,15, ++arrID[3], mapID);
	outtextxy(220,340,"A.");
	if(strlen(arrayCauHoiRandom[page].dapAnA) > 60) {
		char resA1[126];
		char resA2[126];
		char str_tempA[126]; 
		strcpy(str_tempA,arrayCauHoiRandom[page].dapAnA);
    	catChuoi2Dong(str_tempA,resA1,resA2);
    	
		outtextxy(250,340,resA1);
		outtextxy(230,365,resA2);
	} 
	else {
		outtextxy(250,340,arrayCauHoiRandom[page].dapAnA);
	}

	
	tao_circle(200,450,15, ++arrID[3], mapID);
	outtextxy(220,440,"B.");

	if(strlen(arrayCauHoiRandom[page].dapAnB) > 60) {
		char resB1[126];
		char resB2[126];
		char str_tempB[126]; 
		strcpy(str_tempB,arrayCauHoiRandom[page].dapAnB);
    	catChuoi2Dong(str_tempB,resB1,resB2);
    	
		outtextxy(250,440,resB1);
		outtextxy(230,465,resB2);
	} 
	else {
		outtextxy(250,440,arrayCauHoiRandom[page].dapAnB);
	}


	tao_circle(200,550,15, ++arrID[3], mapID);
	outtextxy(220,540,"C.");

	if(strlen(arrayCauHoiRandom[page].dapAnC) > 60) {
		char resC1[126];
		char resC2[126];
		char str_tempC[126]; 
		strcpy(str_tempC,arrayCauHoiRandom[page].dapAnC);
    	catChuoi2Dong(str_tempC,resC1,resC2);
    	
		outtextxy(250,540,resC1);
		outtextxy(230,565,resC2);
	} 
	else {
		outtextxy(250,540,arrayCauHoiRandom[page].dapAnC);
	}
	
	
	tao_circle(200,650,15, ++arrID[3], mapID);
	outtextxy(220,640,"D.");
	
	if(strlen(arrayCauHoiRandom[page].dapAnD) > 60) {
		char resD1[126];
		char resD2[126];
		char str_tempD[126]; 
		strcpy(str_tempD,arrayCauHoiRandom[page].dapAnD);
    	catChuoi2Dong(str_tempD, resD1, resD2);
    	
		outtextxy(250,640,resD1);
		outtextxy(230,665,resD2);
	} 
	else {
		outtextxy(250,640,arrayCauHoiRandom[page].dapAnD);
	}
	
	switch(luuDapAnChon[page]){
		case 'A': {
			tao_circle_checked(200,350,8);
			break;
		}
		case 'B': {
				tao_circle_checked(200,450,8);
			break;
		}
		case 'C': {
				tao_circle_checked(200,550,8);
			break;
		}
		case 'D': {
				tao_circle_checked(200,650,8);
			break;
		}
		default: 
			break;
	
	}
	
	int maxpage = soCauHoi;

	
	
	char page_str[10] = "";  
	char maxpage_str[10] = "";
	char res[20] = "";

	itoa(maxpage, maxpage_str, 10);
	itoa(page+1, page_str, 10);
	strcat(res,"Trang ");
	
	strcat(res,page_str);
	strcat(res,"/");
	strcat(res,maxpage_str);

	reset_layout(460,790,700,820,MAU_NEN);
	setbkcolor(MAU_NEN);
	outtextxy(670,810, res);
	

}


void canhBaoNopBai(short **mapID, int arrID[]) {
		settextstyle(10,0,3);

		tao_khung(430,90,880,180);
		setbkcolor(MAU_NEN);	
		
		outtextxy(440, 110, "Ban Co Chac Chan Muon Nop Bai ?");
		
		tao_button(570, 140, 630, 170, "Yes", MAU_HONG, MAU_DEN, ++arrID[4], mapID);
		tao_button(660, 140, 720, 170, " No", MAU_HONG, MAU_DEN, ++arrID[4], mapID);

}

void checkMouseThi(short **mapID, int arrID[], CauHoiThi arrayCauHoiRandom[], int soCauHoi,  char maMonHoc[], int &page,  char *luuDapAnChon, PTRSinhVien p,  DanhSachLop dsLop, PTRCauHoi rootTree, DanhSachMonHoc dsMonHoc) {
	int x = - 1, y = -1;
	bool checkTime = true; // Bien Kiem tra het thoi gian thi
	while (1) {
		delay(0.001); //delay nhan click 

		int ID = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			ID = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(stop_clock == false && checkTime == true) {
			ID = 22;
		}
		
		switch(ID) {
			
			//Check id chuyen page
			case 11: {  //nop bai
				canhBaoNopBai(mapID,arrID);
				break;
			}
			case 12: {  //prev
				if(page == 0) {
					page = soCauHoi - 1;
				}
				else {
					page--;
				
				}
				drawCauHoi(mapID,arrID,arrayCauHoiRandom,soCauHoi, page, luuDapAnChon);
				break;		
			}
			case 13: { //next
				if(page == soCauHoi - 1) {
					page = 0;
				}
				else {
					page++;
					
				}
				drawCauHoi(mapID,arrID,arrayCauHoiRandom,soCauHoi, page, luuDapAnChon);
				break;
			}
			//Check id dap an
			case 15: {
				luuDapAnChon[page] = 'A';
				reset_circle_checked();
				tao_circle_checked(200,350,8);

				break;
			}
			case 16: {
				luuDapAnChon[page] = 'B';
				reset_circle_checked();
				tao_circle_checked(200,450,8);
				
				break;
			}
			case 17: {
				luuDapAnChon[page] = 'C';
				reset_circle_checked();
				tao_circle_checked(200,550,8);
				break;
			}
			case 18:{
				luuDapAnChon[page] = 'D';
				reset_circle_checked();
				tao_circle_checked(200,650,8);
				break;
			}
			case 20: {  // xac nhan submit yes
				stop_clock = false; // dung` ham` 
				drawChamDiem(mapID, arrID, arrayCauHoiRandom, soCauHoi, maMonHoc, luuDapAnChon, p, dsLop, rootTree, dsMonHoc);

				break;
			}
			case 21: { //  xac nhan submit  no
				reset_layout(430,90,881,181,MAU_NEN);
				resetIDNopBai(arrID);
				break;
			}
			case 22: { //Ham neu het thoi gian se draw ra cham diem
				checkTime = false;
				drawChamDiem(mapID, arrID, arrayCauHoiRandom, soCauHoi, maMonHoc, luuDapAnChon, p, dsLop, rootTree, dsMonHoc);

				break;
			}
			default:
				break;			
		}
		
	}
}



void drawThi(short **mapID, int arrID[],  CauHoiThi arrayCauHoiRandom[], int soCauHoi, int soPhut, char maMonHoc[] , char *luuDapAnChon, PTRSinhVien p, DanhSachLop dsLop, PTRCauHoi rootTree, DanhSachMonHoc dsMonHoc) {
	stop_clock = true;



	resetID(arrID);
	reset_layout(0, 0, WIDTH, HEIGHT, MAU_NEN);
	
	setbkcolor(MAU_NEN);
	settextstyle(10,0,4);	
	
	
	tao_khung(150,200,1200,770);
	tao_button(600,40,700,70,"NOP BAI", MAU_HONG, MAU_DEN, ++arrID[2], mapID);

	
	int page = 0; //khoi tao page = 0
	drawCauHoi(mapID,arrID,arrayCauHoiRandom,soCauHoi, page,luuDapAnChon );
	
	outtextxy(300,60,p->sv.ten);
	
	tao_button(120, 800, 220, 830, "Quay lai", MAU_HONG, MAU_DEN, ++arrID[2], mapID);
	tao_button(1150, 800, 1260, 830, "Tiep theo", MAU_HONG, MAU_DEN, ++arrID[2], mapID);
	
	thread clock;
	clock = thread(printClock, soPhut);
	clock.detach();
	//ham join() thi no se cho` printclock chay xong moi chay dong` duoi
	//ham detach() se chay doc lap, khong quan tam ham main 
	
	checkMouseThi(mapID,arrID,arrayCauHoiRandom, soCauHoi, maMonHoc, page, luuDapAnChon, p, dsLop, rootTree, dsMonHoc);

	
}
void checkMouseBeforeThi(short **mapID, DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree, int arrID[], PTRSinhVien p) {
	int x = - 1, y = -1;
	char maMonHoc[18] = "";
	char soPhut[6] = "";
	char soCauHoi[6] = "";

	while (1) {
		delay(0.001); //delap nhan click 

		int ID = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			ID = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		switch(ID) {
			case 43 : {
				if(p == NULL) { //o giao dien gv cho back tro lai
					drawMainMenu(mapID, dsMonHoc, dsLop, rootTree, arrID);
				}
				break;
			}
			case 6: { // ma mon 
				nhapText(625, 375, 885, 400, maMonHoc, 16, 1);
				break;
			}
			case 7: { //so phut
				nhapSo(625, 435, soPhut, 4);
				break;
			}
			case 8: { //so cau hoi
				nhapSo(625, 495, soCauHoi, 4);
				break;
			}
			case 9: {
				int maxSoCauHoi = lengthCauHoiTheoMH(rootTree, maMonHoc);;
				


				switch(xuLyBeforeThi(dsMonHoc, p, maMonHoc, soPhut, soCauHoi, maxSoCauHoi)) {
						
					case 0: {
						//Thi
						int soCauHoiInt = atoi(soCauHoi);
						int soPhutInt = atoi(soPhut);

						CauHoiThi arrayCauHoiRandom[soCauHoiInt];
						char luuDapAnChon[soCauHoiInt] {0};
						randomCauHoi(rootTree, arrayCauHoiRandom, soCauHoiInt , maMonHoc);
						drawThi(mapID, arrID, arrayCauHoiRandom, soCauHoiInt, soPhutInt, maMonHoc, luuDapAnChon, p, dsLop, rootTree, dsMonHoc);
						
									
						break;
					}
					case 1: {
						thongBaoDangNhap(400,100,1200,130, "Ma mon hoc, so cau hoi va so phut khong duoc bo trong!");
						break;

					}
					case 2: {
						thongBaoDangNhap(460,100,1200,130, "Ma mon hoc khong ton tai. Moi ban nhap lai!");

						break;
					}
					case 3: {
						
						char title[50] = "So cau hoi trong ngan hang de khong du (0 < x <= ";
						char temp[10];
						itoa(maxSoCauHoi,temp,10); //10 is decimal

						strcat(title,temp);
						strcat(title, ").");

						thongBaoDangNhap(400,100,1200,130,title);
						break;
					}
					case 4: {
						thongBaoDangNhap(400,100,1200,130,"So phut khong hop le (0 < x < 1440). Moi ban nhap lai!");
						break;
					}
					case 5: {
						thongBaoDangNhap(470,100,1200,130,"Sinh vien da thi mon nay roi!");

						break;
					}
					case 6: {
						thongBaoDangNhap(470,100,1200,130,"So cau hoi trong ngan hang trong!");
						break;
					}
				}		
				break;
			}
			default:
				break;			
		}
		
	}
}
void drawBeforeThi(short **mapID, DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree, int arrID[], PTRSinhVien p) {
	setbkcolor(MAU_NEN);
   	cleardevice();
   	resetID(arrID);

   	setcolor(COLOR(247,145,31)); //color orange with rbg

	settextstyle(10,0,8);
	outtextxy(350,150,"THI TRAC NGHIEM");
	
	settextstyle(10,0,2);	
	outtextxy(800,750,"N19DCCN019 - Pham Dung Bac");
	outtextxy(800,780,"N19DCCN034 - Nguyen Duc Phuc Dai");
	
	setcolor(MAU_DEN);

	tao_khung(390,320,990,620); 
	char buttonBeforeThi[][50] = {
		"Ma mon thi", "So phut thi", "So cau hoi", " VAO THI"
	};
	
	
	for(int i=0;i<3;i++) {
		tao_button(470,370 + i*60,605,400 + i*60, buttonBeforeThi[i], MAU_HONG, MAU_DEN, -2, mapID);
		taoTextInput(615,370 + i*60, 885, 400 + i*60, ++arrID[1], mapID);
	}	
	
	tao_button(630, 550, 750, 580, buttonBeforeThi[3], MAU_HONG,MAU_DEN, ++arrID[1] ,mapID);
	if(p == NULL) { //o trang thai menu giao vien thi` cho back tro lai
		tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 43, mapID);	
	}

	checkMouseBeforeThi(mapID, dsMonHoc, dsLop ,rootTree, arrID, p);
}

void canhBaoXoa(short **mapID) {
	reset_layout(1046,140,1359,499, MAU_NEN);
	tao_khung(1070,140,1340,250);					
	outtextxy(1090,150, "Ban co chac chan muon");
	outtextxy(1080,170, "xoa khong?");
	
	tao_button(1130, 210, 1210, 240, "Dong y", MAU_HONG, MAU_DEN, 177, mapID );
	tao_button(1230, 210, 1290, 240, "Huy", MAU_HONG, MAU_DEN, 178, mapID );
}

int xuLyNhapLop( DanhSachLop dsLop, char maLop[], char tenLop[]) {
	if(kiemTraChuoiRong(maLop) == 1 || kiemTraChuoiRong(tenLop) == 1 ) {	//xoa khoang trang 
		return 1;
	}
	
	if(ktTrungMaLop(maLop, dsLop)) {		
		return 2;
	}
	
	
	if(isFull(dsLop)) {
		return 4;
	}
	
	return 0;
}


void drawInputXoaLop(short **mapID, int arrID[], char maLop[], char tenLop[]) {
		resetID(arrID);
		reset_layout(11,66,1029,310, MAU_NEN);
		settextstyle(10,0,3);	
	
		
		tao_button(30,100 ,150,130 , "Ma Lop", MAU_HONG, MAU_DEN, -2, mapID);
		taoTextInput(160,100 , 380,130 , -2, mapID);
		outtextxy(170,105,maLop);
		tao_button(30,140 ,150,170 , "Ten Lop", MAU_HONG, MAU_DEN, -2, mapID);
		taoTextInput(160,140 , 900,170 , -2, mapID);
		outtextxy(170,145,tenLop);
		setbkcolor(MAU_NEN);	

		tao_button(450, 250, 510, 280, "Xoa", MAU_HONG, MAU_DEN, 151, mapID );
		tao_button(530, 250, 590, 280, "Huy", MAU_HONG, MAU_DEN, 152, mapID );
}

void drawInputSuaLop(short **mapID, int arrID[], char maLop[], char tenLop[]) {
		resetID(arrID);
		reset_layout(11,66,1029,310, MAU_NEN);
	

		tao_button(30,100 ,150,130 , "Ma Lop", MAU_HONG, MAU_DEN, -2, mapID);
		taoTextInput(160,100 , 380,130 , 38, mapID);
		tao_button(30,140 ,150,170 , "Ten Lop", MAU_HONG, MAU_DEN, -2, mapID);
		taoTextInput(160,140 , 900,170 , 39, mapID);
		settextstyle(10,0,2);	

		outtextxy(170,105,maLop);

		outtextxy(170,145,tenLop);
		setbkcolor(MAU_NEN);	

		tao_button(450, 250, 510, 280, "Sua", MAU_HONG, MAU_DEN, 151, mapID );
		tao_button(530, 250, 590, 280, "Huy", MAU_HONG, MAU_DEN, 152, mapID );
}



void inDSLop(short **mapID,  DanhSachLop dsLop, int arrID[], int page) { 
	reset_layout(11, 366,1029,790, MAU_NEN);
	resetID(arrID);
	setbkcolor(MAU_NEN);
	int arrDoDaiTable[] = { 100, 250, 650}; 
	char title[][50] = { "STT", "MA LOP" , "TEN LOP"};

	tao_bang(20, 375, 35, 3, 11, arrDoDaiTable, title, arrID, mapID, page);
	
	settextstyle(10,0,2);

	for(int i = page * 10; i< (page+1)*10;i++) {
		if(dsLop.lh[i] == NULL)
		{
			break;
		}
		else {
			setID(20,410+35*(i%10),1020,445 + 35*(i%10),++arrID[7], mapID);
			outtextxy(130,420 + 35*(i%10), dsLop.lh[i]->maLop);
		
			outtextxy(380,420 + 35*(i%10), dsLop.lh[i]->tenLop);
		}
	
	}
	int maxpage;
	if(dsLop.soLuong <= 10) { // Neu so luong <= 10
		maxpage = 0;
	}
	else if(dsLop.soLuong % 10 == 0){
		maxpage = dsLop.soLuong/10 -1;
	}
	else maxpage = dsLop.soLuong/10;
	
	
	char page_str[10] = "";  
	char maxpage_str[10] = "";
	char res[20] = "";

	itoa(maxpage+1, maxpage_str, 10);
	itoa(page+1, page_str, 10);
	strcat(res,"Trang ");
	
	strcat(res,page_str);
	strcat(res,"/");
	strcat(res,maxpage_str);

	reset_layout(460,790,700,820,MAU_NEN);
	setbkcolor(MAU_NEN);
	outtextxy(490,810, res);
}

void drawInputLop(short **mapID, int arrID[]) {
		resetID(arrID);
		reset_layout(11,66,1029,310, MAU_NEN);
		settextstyle(10,0,3);		
			
		
		tao_button(30,100 ,150,130 , "Ma Lop", MAU_HONG, MAU_DEN, -2, mapID);
		taoTextInput(160,100 , 380,130 , 38, mapID);
		
		tao_button(30,140 ,150,170 , "Ten Lop", MAU_HONG, MAU_DEN, -2, mapID);
		taoTextInput(160,140 , 900,170 , 39, mapID);
		
		
		tao_button(350, 200, 410, 230, "Save", MAU_HONG, MAU_DEN, 40, mapID );
		tao_button(430, 200, 490, 230, "Huy", MAU_HONG, MAU_DEN, 41, mapID );

}

void selectSuaLop(short **mapID, int arrID[], int state, int page, DanhSachLop dsLop, char maLopSua[], char tenLopSua[]) {
	drawInputSuaLop(mapID, arrID, dsLop.lh[state + page*10]->maLop, dsLop.lh[state + page*10]->tenLop);
	xoaChuoi(maLopSua);
	xoaChuoi(tenLopSua);
	strcpy(maLopSua,dsLop.lh[state + page*10]->maLop);
	strcpy(tenLopSua,dsLop.lh[state + page*10]->tenLop);
}
void checkMouseQLLop(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree) {
	int x = - 1, y = -1;
	char maLop[17] = "";
	char tenLop[52] = "";
	char maLopSua[17] = "";
	char tenLopSua[52] = "";
	int page = 0;
	while (1) {
		delay(0.001); 

		int ID = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			ID = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(x != -1 && y != -1)

		menu:
		switch(ID) {		
			case 34: {  //Them
				tao_button(450, 320, 510, 350, "Them", MAU_DO_NHAT, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);

				drawInputLop(mapID,arrID); 
				x = - 1, y = -1; 

				break;
			}
			case 35: {  //Sua
				sua_menu:

				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_DO_NHAT, MAU_DEN, 35, mapID);

				reset_layout(11,66,1029,310, MAU_NEN);
				int state;
				x = - 1, y = -1;
				while (1) {
					delay(0.001); 
					ID = 0;
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN,x,y);
						ID = mapID[x][y];
						clearmouseclick(WM_LBUTTONDOWN);
					}

					if(x != -1 && y != -1)
					switch(ID) {
						case 102: {
							state = 0;
							selectSuaLop(mapID, arrID, state, page, dsLop, maLopSua, tenLopSua);
						

							x = - 1, y = -1;

							break;
						}
						case 103: {
							state = 1;
							selectSuaLop(mapID, arrID, state, page, dsLop, maLopSua, tenLopSua);
							x = - 1, y = -1;

							break;
						}
						case 104: {
							state = 2;
							selectSuaLop(mapID, arrID, state, page, dsLop, maLopSua, tenLopSua);
							x = - 1, y = -1;

							break;
						}
						case 105: {
							state = 3;
							selectSuaLop(mapID, arrID, state, page, dsLop, maLopSua, tenLopSua);
							x = - 1, y = -1;

							break;
						}
						case 106: {
							state = 4;
							selectSuaLop(mapID, arrID, state, page, dsLop, maLopSua, tenLopSua);
							x = - 1, y = -1;

							break;
						}
						case 107: {
							state = 5;
							selectSuaLop(mapID, arrID, state, page, dsLop, maLopSua, tenLopSua);
							x = - 1, y = -1;
							break;
						}
						case 108: {
							state = 6;
							selectSuaLop(mapID, arrID, state, page, dsLop, maLopSua, tenLopSua);
							x = - 1, y = -1;
							break;
						}
						case 109: {
							state = 7;
							selectSuaLop(mapID, arrID, state, page, dsLop, maLopSua, tenLopSua);
							x = - 1, y = -1;
							break;
						}
						case 110: {
							state = 8;
							selectSuaLop(mapID, arrID, state, page, dsLop, maLopSua, tenLopSua);
							x = - 1, y = -1;

							break;
						}
						case 111: {
							state = 9;
							selectSuaLop(mapID, arrID, state, page, dsLop, maLopSua, tenLopSua);
							x = - 1, y = -1;

							break;
						}
						case 151: {  // sua
							setbkcolor(MAU_NEN);
							if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) > 0 ) {
								reset_layout(1046,140,1359,499, MAU_NEN);
								reset_layout(11,66,1029,310, MAU_NEN);

								outtextxy(1085,150, "Lop ton tai sinh");
								outtextxy(1075,170, "vien khong the sua!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
								
								x = - 1, y = -1;
								break;
							}
							else {
								if(kiemTraChuoiRong(maLopSua)  == 1 || kiemTraChuoiRong(tenLopSua) == 1 ) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Ma lop hoac ten lop");
									outtextxy(1075,170, "khong de trong!");
									
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									x = - 1, y = -1;
									break;
								}
								//Neu nhu ma lop thay doi thi kiem tra ma lop do co' trung` hay khong
								if(ktTrungMaLop(maLopSua, dsLop) && strcmp(maLopSua, dsLop.lh[state + page*10]->maLop) != 0) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Ma lop da ton tai,");
									outtextxy(1075,170, "vui long nhap lai!");
									
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									x = - 1, y = -1;
									break;
								}
						
								strcpy(dsLop.lh[state + page*10]->maLop, maLopSua);
								strcpy(dsLop.lh[state + page*10]->tenLop, tenLopSua);


								luuFileQLLop(dsLop);

								reset_layout(1046,140,1359,499, MAU_NEN); //reseet layout bang thong bao
								outtextxy(1085,150, "Sua lop thanh cong!");

								inDSLop(mapID, dsLop, arrID, page);
								reset_layout(11,66,1029,310, MAU_NEN);
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);

							}
							x = - 1, y = -1;
						
							break;
						}
						case 152: {  //Huy sua
							goto sua_menu;
							break;
						}  
						case 38: {
						
							nhapText(170, 105, 380, 130 ,maLopSua, 15, 1);
							x = - 1, y = -1;
							break;
						}
						case 39: {

							nhapText(170, 145, 900, 170, tenLopSua, 50, 0);
							x = - 1, y = -1;
							break;
						}
						case 43: { //back
							drawMainMenu(mapID, dsMonHoc, dsLop, rootTree, arrID);
							break;
						}
						case 153: { //Prev
							
							if(page > 0 ) {
								page --;
								inDSLop(mapID, dsLop, arrID, page);	
							}
							x = - 1, y = -1;
							break;
						}
						
						case 154: { //Next
							int maxpage;
							if(dsLop.soLuong <= 10) { // Neu so luong <= 10
								maxpage = 0;
							}
							else if(dsLop.soLuong % 10 == 0){
								maxpage = dsLop.soLuong/10 -1;
							}
							else maxpage = dsLop.soLuong/10;
							
							if(page < maxpage) {
								page ++;
								inDSLop(mapID, dsLop, arrID, page);	
							}
							x = - 1, y = -1;
							break;
						}
						case 33: {
							goto menu;
							break;
						}
						case 34: {
							goto menu;
							break;
						}
						case 36: {
							goto menu;
							break;
						}
						default:
							break;
						
					}
					
				}
				x = - 1, y = -1;				
				break;
			}
			case 36: {  //Xoa
				xoa_menu:

				tao_button(590, 320, 650, 350, "Xoa", MAU_DO_NHAT, MAU_DEN, 36, mapID);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);

				reset_layout(11,66,1029,310, MAU_NEN);
				int state;
				x = - 1, y = -1;
				while (1) {
					delay(0.001); 
					ID = 0;
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN,x,y);
						ID = mapID[x][y];
						clearmouseclick(WM_LBUTTONDOWN);
					}

					if(x != -1 && y != -1)
					switch(ID) {
						case 102: {
							state = 0;

							drawInputXoaLop(mapID, arrID, dsLop.lh[state + page*10]->maLop, dsLop.lh[state + page*10]->tenLop);
							x = - 1, y = -1;

							break;
						}
						case 103: {
							state = 1;
							drawInputXoaLop(mapID, arrID, dsLop.lh[state + page*10]->maLop, dsLop.lh[state + page*10]->tenLop);
							x = - 1, y = -1;

							break;
						}
						case 104: {
							state = 2;
							drawInputXoaLop(mapID, arrID, dsLop.lh[state + page*10]->maLop, dsLop.lh[state + page*10]->tenLop);
							x = - 1, y = -1;

							break;
						}
						case 105: {
							state = 3;
							drawInputXoaLop(mapID, arrID, dsLop.lh[state + page*10]->maLop, dsLop.lh[state + page*10]->tenLop);

							x = - 1, y = -1;

							break;
						}
						case 106: {
							state = 4;
							drawInputXoaLop(mapID, arrID, dsLop.lh[state + page*10]->maLop, dsLop.lh[state + page*10]->tenLop);
							x = - 1, y = -1;

							break;
						}
						case 107: {
							state = 5;
							drawInputXoaLop(mapID, arrID, dsLop.lh[state + page*10]->maLop, dsLop.lh[state + page*10]->tenLop);
							x = - 1, y = -1;
							break;
						}
						case 108: {
							state = 6;
							drawInputXoaLop(mapID, arrID, dsLop.lh[state + page*10]->maLop, dsLop.lh[state + page*10]->tenLop);
							x = - 1, y = -1;
							break;
						}
						case 109: {
							state = 7;
							drawInputXoaLop(mapID, arrID, dsLop.lh[state + page*10]->maLop, dsLop.lh[state + page*10]->tenLop);
							x = - 1, y = -1;
							break;
						}
						case 110: {
							state = 8;
							drawInputXoaLop(mapID, arrID, dsLop.lh[state + page*10]->maLop, dsLop.lh[state + page*10]->tenLop);
							x = - 1, y = -1;

							break;
						}
						case 111: {
							state = 9;
							drawInputXoaLop(mapID, arrID, dsLop.lh[state + page*10]->maLop, dsLop.lh[state + page*10]->tenLop);
							x = - 1, y = -1;

							break;
						}
						case 151: {  // dong y Xoa
							if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) > 0 ) {
								reset_layout(1046,140,1359,499, MAU_NEN);
								reset_layout(11,66,1029,310, MAU_NEN);

								outtextxy(1085,150, "Lop ton tai sinh vien,");
								outtextxy(1075,170, "khong the xoa!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
							}
							else {
								canhBaoXoa(mapID);
								x = - 1, y = -1;

								while (1) {
									delay(0.001); 
									ID = 0;
									if(ismouseclick(WM_LBUTTONDOWN)){
										getmouseclick(WM_LBUTTONDOWN,x,y);
										ID = mapID[x][y];
										clearmouseclick(WM_LBUTTONDOWN);
									}
																
									if(x != -1 && y != -1)
									switch(ID) { 
										case 177: { //dong y xoa
											for(int i = state + page*10; i < dsLop.soLuong; i++) {
												dsLop.lh[i] = dsLop.lh[i+1];
											}
											dsLop.soLuong --;
											luuFileQLLop(dsLop);
											
											reset_layout(1046,140,1359,499, MAU_NEN); //reseet layout bang thong bao
											outtextxy(1085,150, "Xoa lop thanh cong!");
											page = 0;
											inDSLop(mapID, dsLop, arrID, page);
											reset_layout(11,66,1029,310, MAU_NEN);
											
											delay(1000);
											reset_layout(1046,140,1359,499, MAU_NEN);	
											goto xoa_menu;						
										}
										case 178: { //khong dong y xoa
											reset_layout(1046,140,1359,499, MAU_NEN);
											goto xoa_menu;
											x=-1;y=-1;
											break;
										}
										default :
											break;
										
									} 
								}
								

							}
							x = - 1, y = -1;
						
							break;
						}
						case 152: {  //Huy xoa
							goto xoa_menu;
							break;
						}  
						case 43: {
							drawMainMenu(mapID, dsMonHoc, dsLop, rootTree, arrID);
							break;
						}
						case 153: { //Prev
							
							if(page > 0 ) {
								page --;
								inDSLop(mapID, dsLop, arrID, page);	
							}
							x = - 1, y = -1;
							break;
						}
						
						case 154: { //Next
							int maxpage;
							if(dsLop.soLuong <= 10) { // Neu so luong <= 10
								maxpage = 0;
							}
							else if(dsLop.soLuong % 10 == 0){
								maxpage = dsLop.soLuong/10 -1;
							}
							else maxpage = dsLop.soLuong/10;
							
							if(page < maxpage) {
								page ++;
								inDSLop(mapID, dsLop, arrID, page);	
							}
							x = - 1, y = -1;
							break;
						}
						case 33: { //find
							goto menu;
							break;
						}
						case 34: { //them
							goto menu;
							break;
						}
						case 35: { //sua
							goto menu;
							break;
						}
						default: 
							break;
						
					}
					
				}
				x = - 1, y = -1;

				break;
			}
			case 38: {
				nhapText(170, 105, 380, 170 ,maLop, 15, 1);
				x = - 1, y = -1;
				break;
			}
			case 39: {
				nhapText(170, 145, 380, 170, tenLop, 50, 0);
				x = - 1, y = -1;
				break;
			}
	
			case 40: {  //Save
				int check  = xuLyNhapLop(dsLop, maLop, tenLop);
				
				setbkcolor(MAU_NEN);
				switch(check) {
					case 1:{
						reset_layout(1046,140,1359,499, MAU_NEN); 
						outtextxy(1085,150, "Ban chua nhap ten lop");
						outtextxy(1075,170, "hoac ma lop, vui long"); 
						outtextxy(1075,190, "dien day du thong tin!");
						
						delay(1000);
						reset_layout(1046,140,1359,499, MAU_NEN);

						break;
					}
					case 2: {
						reset_layout(1046,140,1359,499, MAU_NEN); 

						outtextxy(1085,150, "Ma lop da ton tai, vui");
						outtextxy(1075,170, "long nhap lai!");
						
						delay(1000);
						reset_layout(1046,140,1359,499, MAU_NEN);

						break;
					}
					case 4: {
						reset_layout(1046,140,1359,499, MAU_NEN); 

						outtextxy(1085,150, "Khong the them lop,");
						outtextxy(1075,170, "danh sach lop da day!");
						
						delay(1000);
						reset_layout(1046,140,1359,499, MAU_NEN);

						break;
					}
					case 0: {
						LopHoc *lh = new LopHoc;
						strcpy(lh->maLop, maLop);
						strcpy(lh->tenLop, tenLop);
						lh->dsSinhVien = NULL;
						dsLop.lh[dsLop.soLuong++] = lh;
						luuFileQLLop(dsLop);

						xoaChuoi(maLop);
						xoaChuoi(tenLop);
						drawInputLop(mapID,arrID);  
	
						inDSLop(mapID, dsLop, arrID, page);
						
						
						reset_layout(1046,140,1359,499, MAU_NEN); 
						setbkcolor(MAU_NEN);

						outtextxy(1085,150, "Them lop thanh cong!");
						
						delay(1000);
						reset_layout(1046,140,1359,499, MAU_NEN);
						break;
					}
				}
				break;
			}
			case 41: {  //Huy
			
				xoaChuoi(maLop);
				xoaChuoi(tenLop);
			
				reset_layout(11, 66, 1029, 310,MAU_NEN);
				
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);

				x = - 1, y = -1;

				break;
			}
			case 43: { //back
				drawMainMenu(mapID, dsMonHoc, dsLop, rootTree, arrID);
				break;
			}
			case 153: { //Prev
				
				if(page > 0 ) {
					page --;
					inDSLop(mapID, dsLop, arrID, page);	
				}
				x = - 1, y = -1;
				break;
			}
			
			case 154: { //Next
				int maxpage;
				if(dsLop.soLuong <= 10) { // Neu so luong <= 10
					maxpage = 0;
				}
				else if(dsLop.soLuong % 10 == 0){
					maxpage = dsLop.soLuong/10 -1;
				}
				else maxpage = dsLop.soLuong/10;
				
				if(page < maxpage) {
					page ++;
					inDSLop(mapID, dsLop, arrID, page);	
				}
				x = - 1, y = -1;
				break;
			}
			default:
				break;			
		}
		
	}
}



void drawQLLop(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree) {
	int maxpage;	

	resetID(arrID);
	
   	cleardevice();
	setbkcolor(MAU_NEN);
	settextstyle(10,0,2);

	tao_khung(5,60,1035,860); 
	tao_khung(10,65,1030,355);
	tao_khung(10,365,1030,855);//800
	
	tao_khung(1045,60,1360,500); //khung canh bao
	
	settextstyle(10,0,5);
	setcolor(COLOR(247,145,31)); //color orange with rbg
	outtextxy(530,10,"Quan Ly Lop Hoc");

	settextstyle(10,0,2);
	setcolor(MAU_DO_NHAT);
	outtextxy(1120,80,"BANG THONG BAO");
	line(1120,100,1290,100);
	setcolor(MAU_DEN);
	
	if(dsLop.soLuong <= 10) { // Neu so luong <= 10
		maxpage = 0;
	}
	else if(dsLop.soLuong % 10 == 0){
		maxpage = dsLop.soLuong/10 -1;
	}
	else maxpage = dsLop.soLuong/10;
	
	
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 43, mapID);
	tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN,34, mapID);
	tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
	tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
	tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 153, mapID);
	tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 154, mapID);
	
	 //Noi chuoi
	char page_str[10] = "";  
	itoa(maxpage+1, page_str, 10);
	char res[20] = "";
	strcat(res,"Trang 1/");
	strcat(res, page_str);
	outtextxy(490,810, res);
	
	inDSLop(mapID,dsLop,arrID, 0);

	
	checkMouseQLLop(mapID, arrID, dsMonHoc, dsLop, rootTree);
}

int xuLyNhapSinhVien(DanhSachLop dsLop,char maSV[], char ho[], char ten[], char password[], int gioiTinh) {
	if(kiemTraChuoiRong(maSV) == 1 || kiemTraChuoiRong(ho) == 1 || kiemTraChuoiRong(ten) || kiemTraChuoiRong(password)){	//xoa khoang trang 
		return 1;
	}
	
	if(ktTrungMaSVSchool(dsLop, maSV)) {		
		return 2;
	}
	
	if(gioiTinh == 0) {
		return 3;
	}
	return 0;
}

void drawDSSinhVien(short **mapID, int arrID[],  LopHoc *lh, int pageSV ) {
	resetID(arrID);
	khoi_tao_mapID(mapID);	

	reset_layout(11,366,1029,854, MAU_NEN);
	setbkcolor(MAU_NEN);
	
	int soLuong = demSLSinhVien(lh->dsSinhVien); //dem so luong sv trong lop
	int maxpage;
	if(soLuong <= 10)
	{
		maxpage = 0;
	}
	else if (soLuong % 10 == 0)
	{
		maxpage = soLuong/10 - 1;
	}
	else maxpage = soLuong/10; 
	
	PTRSinhVien q;  
	q = new NodeSinhVien;
	
	if (pageSV == 0)
	{
		q = lh->dsSinhVien;  //q = first
	}
	else
	{	//Neu page > 0  thi se lay tu phan tu page *10
		q = lh->dsSinhVien;
		
		for (int i=0; i<pageSV*10; i++)
		{
			if (q->next != NULL)
			{
				q = q->next;
			}
		}	
	}
	
	int arrDoDaiTable[] = { 100, 300, 450, 150}; 
	char title[][50] = { "STT", "Ma SV" , "Ho Va Ten", "Gioi Tinh"};

	tao_bang(20, 375, 35, 4, 11, arrDoDaiTable, title, arrID, mapID, pageSV);
	
	settextstyle(10,0,2);

	for(int i = 0; i< 10;i++) {
		if(q == NULL) {	
			break;
		}
		else {
			
			setID(20,410+35*i,1020,445 + 35*i,++arrID[11], mapID);
			outtextxy(130,420 + 35*i, q->sv.maSV);
			char temp[70] ="";  //Noi chuoi Ho va ten
			strcat(temp, q->sv.ho);
			strcat(temp, " ");
			strcat(temp, q->sv.ten);
			outtextxy(430,420 + 35*i, temp);
			outtextxy(430,420 + 35*i, temp);
			outtextxy(880, 420 + 35*i, q->sv.phai);
			q = q->next;

		}
	
	}
	

	tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 182, mapID);
	tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 183, mapID);
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);


	
	 //Noi chuoi

	char page_str[10] = "";  
	char maxpage_str[10] = "";
	char res[20] = "";

	itoa(maxpage+1, maxpage_str, 10);
	itoa(pageSV+1, page_str, 10);
	strcat(res,"Trang ");
	
	strcat(res,page_str);
	strcat(res,"/");
	strcat(res,maxpage_str);

	reset_layout(460,790,700,820,MAU_NEN);
	setbkcolor(MAU_NEN);
	outtextxy(490,810, res);
	


	
	
}

void drawInputSuaSV(short **mapID, int arrID[], char maSV[], char ho[], char ten[], char password[], char gioiTinh[]) {

	reset_layout(11,66,1029,310,MAU_NEN);  //ID 169-> 175
	settextstyle(10,0,3);	
	tao_button(30, 100, 150, 130 , "Ma SV", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160, 100 , 380, 130, 169, mapID);
		
	tao_button(30, 140, 150, 170 , "Ho SV", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160, 140 , 380, 170, 170, mapID);
	
	tao_button(450, 140, 570, 170 , "Ten SV", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(580, 140, 800, 170 , 171, mapID);	
	
	tao_button(450, 100, 570, 130 , "Password", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(580, 100, 800, 130 , 172, mapID);
	
	settextstyle(10,0,2);	

	outtextxy(170, 105, maSV);
	outtextxy(170, 145, ho);
	outtextxy(590, 145, ten);
	outtextxy(590, 105, password);
	if(strcmp(gioiTinh, "Nam") == 0) {
		tao_button(30, 180, 150, 210, "NAM" , MAU_DO_NHAT, MAU_TRANG, 173, mapID);
		tao_button(170, 180, 290, 210, "NU", MAU_XANH_DUONG, MAU_DEN, 174, mapID);
	}
	else {
		tao_button(30, 180, 150, 210, "NAM" , MAU_XANH_DUONG, MAU_DEN, 173, mapID);
		tao_button(170, 180, 290, 210, "NU", MAU_DO_NHAT, MAU_TRANG, 174, mapID);
	}	
	
	tao_button(410, 250, 470, 280, "Sua", MAU_HONG, MAU_DEN, 175, mapID );
	tao_button(490, 250, 550, 280, "Huy", MAU_HONG, MAU_DEN, 176, mapID );
	
}
void drawInputThemSV(short **mapID, int arrID[]) {
	reset_layout(11,66,1029,310,MAU_NEN);  //ID 169-> 175
	settextstyle(10,0,3);	
	tao_button(30, 100, 150, 130 , "Ma SV", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160, 100 , 425, 130, 169, mapID);
		
	tao_button(30, 140, 150, 170 , "Ho SV", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160, 140 , 425, 170, 170, mapID);
	
	tao_button(450, 140, 570, 170 , "Ten SV", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(580, 140, 800, 170 , 171, mapID);	
	
	tao_button(450, 100, 570, 130 , "Password", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(580, 100, 800, 130 , 172, mapID);
	
	tao_button(30, 180, 150, 210, "NAM" , MAU_XANH_DUONG, MAU_DEN, 173, mapID);
	tao_button(170, 180, 290, 210, "NU", MAU_XANH_DUONG, MAU_DEN, 174, mapID);
		
	tao_button(410, 250, 470, 280, "Save", MAU_HONG, MAU_DEN, 175, mapID );
	tao_button(490, 250, 550, 280, "Huy", MAU_HONG, MAU_DEN, 176, mapID );
}

void selectSuaSinhVien(short **mapID, int arrID[], DanhSachLop dsLop,  int state, int viTri, int pageSV, int page, char maSVSua[], char hoSua[], char tenSua[], char passwordSua[], int &gioiTinhSua){

	PTRSinhVien p = timKiemSVTheoVT(dsLop.lh[state + page*10]->dsSinhVien, viTri + pageSV*10); 

	drawInputSuaSV(mapID, arrID, p->sv.maSV, p->sv.ho, p->sv.ten, p->sv.password, p->sv.phai);
	xoaChuoi(maSVSua);
	xoaChuoi(hoSua);
	xoaChuoi(tenSua);
	xoaChuoi(passwordSua);
	gioiTinhSua = 0;
													
	strcpy(maSVSua, p->sv.maSV);
	strcpy(hoSua, p->sv.ho);
	strcpy(tenSua, p->sv.ten);
	strcpy(passwordSua, p->sv.password);
	if(strcmp(p->sv.phai, "Nu") == 0) 
		gioiTinhSua = 2;
	else if(strcmp(p->sv.phai, "Nam") == 0) 
		gioiTinhSua = 1; //nam
}

void selectXoaSinhVien(short **mapID, int arrID[], DanhSachLop dsLop,  int state, int viTri, int pageSV, int page) {
	PTRSinhVien p = timKiemSVTheoVT(dsLop.lh[state + page*10]->dsSinhVien, viTri + pageSV*10);
	
	reset_layout(11,66,1029,310,MAU_NEN);  //ID 169-> 175
	settextstyle(10,0,3);	
	tao_button(30, 100, 150, 130 , "Ma SV", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160, 100 , 380, 130, -2, mapID);
		
	tao_button(30, 140, 150, 170 , "Ho SV", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160, 140 , 380, 170, -2, mapID);
	
	tao_button(450, 140, 570, 170 , "Ten SV", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(580, 140, 800, 170 , -2, mapID);	
	
	tao_button(450, 100, 570, 130 , "Password", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(580, 100, 800, 130 , -2, mapID);
	
	settextstyle(10,0,2);	

	outtextxy(170, 105, p->sv.maSV);
	outtextxy(170, 145, p->sv.ho);
	outtextxy(590, 145, p->sv.ten);
	outtextxy(590, 105, p->sv.password);
	if(strcmp(p->sv.phai, "Nam") == 0) {
		tao_button(30, 180, 150, 210, "NAM" , MAU_DO_NHAT, MAU_TRANG, -2, mapID);
		tao_button(170, 180, 290, 210, "NU", MAU_XANH_DUONG, MAU_DEN, -2, mapID);
	}
	else if(strcmp(p->sv.phai, "Nu") == 0){
		tao_button(30, 180, 150, 210, "NAM" , MAU_XANH_DUONG, MAU_DEN, -2, mapID);
		tao_button(170, 180, 290, 210, "NU", MAU_DO_NHAT, MAU_TRANG, -2, mapID);
	}	
	
	tao_button(410, 250, 470, 280, "Xoa", MAU_HONG, MAU_DEN, 175, mapID );
	tao_button(490, 250, 550, 280, "Huy", MAU_HONG, MAU_DEN, 176, mapID );
}

void drawInputTimSV(short **mapID) {
	reset_layout(11,66,1029,310,MAU_NEN);
	settextstyle(10,0,3);
	tao_button(30,150 ,150,180 , "Ma Lop", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160,150 , 380,180 , 179, mapID);
	tao_button(410, 250, 470, 280, "Find", MAU_HONG, MAU_DEN, 180, mapID );
}
void checkMouseQLSinhVien(short **mapID, int arrID[],  DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree) {
	int x = - 1, y = -1;
	char maSV[17] = "";
	char ho[22] = "";
	char ten[12] = "";
	char password[18] = "";
	int gioiTinh  = 0;
	char maLop[17] = "";
	
	char maSVSua[17] = "";
	char hoSua[22] = "";
	char tenSua[12] = "";
	char passwordSua[18] = "";
	int gioiTinhSua  = 0;
	int pageSV = 0;
	int page = 0; //page lop
	int state;
	while (1) {
		delay(0.001); 

		int ID = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			ID = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		
		if(x != -1 && y != -1)
		menu:
		switch(ID) {		
			
			case 179: { //nhap ma lop
				nhapText(170, 155, 380, 180, maLop, 15, 1);
				x = - 1, y = -1;
				break;
			}
			case 180: { //find
				setbkcolor(MAU_NEN);
				if(kiemTraChuoiRong(maLop) == 1 ){	//xoa khoang trang 
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Ma lop khong de trong!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
					x = - 1, y = -1;
					break;
				}
				LopHoc *lht = timLopTheoMaLop(dsLop, maLop);
				if(lht == NULL) {
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Ma lop khong ton tai!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
					x = - 1, y = -1;
					break;
				}
				else {
					int vtLop = viTriLop(dsLop, maLop);
					state = vtLop%10;	//tim vi tri lop trong ds lop
					page = vtLop/10;    
				
					xoaChuoi(maLop);
					drawDSSinhVien(mapID, arrID, lht, 0);
					reset_layout(11,66,1029,354,MAU_NEN);
					tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
					tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
					tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
						
					
					x = - 1, y = -1;
				}
				break;
			}
					

			case 102: {
				state = 0;
				
				drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], 0);
				reset_layout(11,66,1029,354,MAU_NEN);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				
				if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) == 0) {
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Danh sach sinh vien");
					outtextxy(1075,170, "trong!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
				}
				
				
				x = - 1, y = -1;

				break;
			}
			case 103: {
				state = 1;
				
				drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], 0);
				reset_layout(11,66,1029,354,MAU_NEN);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				
				if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) == 0) {
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Danh sach sinh vien");
					outtextxy(1075,170, "trong!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
				}
				
				x = - 1, y = -1;

				break;
			}
			case 104: {
				state = 2;
				drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], 0);
				reset_layout(11,66,1029,354,MAU_NEN);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				
				if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) == 0) {
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Danh sach sinh vien");
					outtextxy(1075,170, "trong!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
				}
				x = - 1, y = -1;

				break;
			}
			case 105: {
				state = 3;
				drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], 0);
				reset_layout(11,66,1029,354,MAU_NEN);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				
				if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) == 0) {
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Danh sach sinh vien");
					outtextxy(1075,170, "trong!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
				}	
				x = - 1, y = -1;

				break;
			}
			case 106: {
				state = 4;
				drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], 0);
				reset_layout(11,66,1029,354,MAU_NEN);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				
				if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) == 0) {
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Danh sach sinh vien");
					outtextxy(1075,170, "trong!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
				}
				x = - 1, y = -1;

				break;
			}
			case 107: {
				state = 5;
				drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], 0);
				reset_layout(11,66,1029,354,MAU_NEN);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				
				if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) == 0) {
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Danh sach sinh vien");
					outtextxy(1075,170, "trong!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
				}
				x = - 1, y = -1;
				break;
			}
			case 108: {
				state = 6;
				drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], 0);
				reset_layout(11,66,1029,354,MAU_NEN);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				
				if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) == 0) {
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Danh sach sinh vien");
					outtextxy(1075,170, "trong!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
				}
				x = - 1, y = -1;
				break;
			}
			case 109: {
				state = 7;
				drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], 0);
				reset_layout(11,66,1029,354,MAU_NEN);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				
				if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) == 0) {
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Danh sach sinh vien");
					outtextxy(1075,170, "trong!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
				}
				x = - 1, y = -1;
				break;
			}
			case 110: {
				state = 8;
				drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], 0);
				reset_layout(11,66,1029,354,MAU_NEN);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				
				if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) == 0) {
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Danh sach sinh vien");
					outtextxy(1075,170, "trong!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
				}
				x = - 1, y = -1;

				break;
			}
			case 111: {
				state = 9;
				drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], 0);
				reset_layout(11,66,1029,354,MAU_NEN);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				
				if(demSLSinhVien(dsLop.lh[state + page * 10]->dsSinhVien) == 0) {
					reset_layout(1046,140,1359,499, MAU_NEN);						
					outtextxy(1085,150, "Danh sach sinh vien");
					outtextxy(1075,170, "trong!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
				}
				x = - 1, y = -1;
				break;
			}

			case 182: { //prev page sv
														
				if(pageSV > 0 ) {
					pageSV --;
					drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], pageSV);
					reset_layout(11,66,1029,310, MAU_NEN);
					gioiTinh = 0;
					xoaChuoi(maSV);
					xoaChuoi(ho);
					xoaChuoi(ten);
					xoaChuoi(password);

					tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
					tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
					tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);	
				}
			
				x = - 1, y = -1;
				break;
			} 
			case 183: { //next page sv
				int soLuong = demSLSinhVien(dsLop.lh[state + page*10]->dsSinhVien); //dem so luong sv trong lop
				int maxpage;
				if(soLuong <= 10) {
					maxpage = 0;
				}
				else if (soLuong % 10 == 0)
				{
					maxpage = soLuong/10 - 1;
				}
				else maxpage = soLuong/10; 
								
				if(pageSV < maxpage) {
					pageSV ++;
					drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], pageSV);
					reset_layout(11,66,1029,310, MAU_NEN);
					gioiTinh = 0;
					xoaChuoi(maSV);
					xoaChuoi(ho);
					xoaChuoi(ten);
					xoaChuoi(password);

					tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
					tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
					tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				}
				x = - 1, y = -1;
				break;
			}
			case 34: { // Them
				tao_button(450, 320, 510, 350, "Them", MAU_DO_NHAT, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				drawInputThemSV(mapID, arrID);
				break;
			}
			case 44: {
				pageSV = 0;
				reset_layout(11,66,1029,354, MAU_NEN);
				tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 43, mapID);
				tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 153, mapID);
	            tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 154, mapID);
				drawInputTimSV(mapID);
				inDSLop(mapID,dsLop,arrID, page);
				break;
			}
			case 35: { //sua
				sua_menu:
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_DO_NHAT, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
										
				reset_layout(11,66,1029,310, MAU_NEN);
				int viTri;
				x = - 1, y = -1;
				while (1) {
					delay(0.001); 
					ID = 0;
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN,x,y);
						ID = mapID[x][y];
						clearmouseclick(WM_LBUTTONDOWN);
					}
						
					if(x != -1 && y != -1)
					switch(ID) {
							
						case 159: {
							viTri = 0;
							selectSuaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page, maSVSua, hoSua, tenSua, passwordSua, gioiTinhSua);
							x = - 1, y = -1;
							
							break;
						}
						case 160: {
							viTri = 1;
							selectSuaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page, maSVSua, hoSua, tenSua, passwordSua, gioiTinhSua);
							x = - 1, y = -1;
						
							break;
						}
						case 161: {
							viTri = 2;
							selectSuaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page, maSVSua, hoSua, tenSua, passwordSua, gioiTinhSua);
							x = - 1, y = -1;
						
							break;
						}
						case 162: {
							viTri = 3;
							selectSuaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page, maSVSua, hoSua, tenSua, passwordSua, gioiTinhSua);
							x = - 1, y = -1;
						
							break;
						}
						case 163: {
							viTri = 4;
							selectSuaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page, maSVSua, hoSua, tenSua, passwordSua, gioiTinhSua);
							x = - 1, y = -1;
						
							break;
						}
						case 164: {
							viTri = 5;
							selectSuaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page, maSVSua, hoSua, tenSua, passwordSua, gioiTinhSua);
							x = - 1, y = -1;
							break;
						}
						case 165: {
							viTri = 6;
							selectSuaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page, maSVSua, hoSua, tenSua, passwordSua, gioiTinhSua);
							x = - 1, y = -1;
							break;
						}
						case 166: {
							viTri = 7;
							selectSuaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page, maSVSua, hoSua, tenSua, passwordSua, gioiTinhSua);
							x = - 1, y = -1;
							break;
						}
						case 167: {
							viTri = 8;
							selectSuaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page, maSVSua, hoSua, tenSua, passwordSua, gioiTinhSua);
							x = - 1, y = -1;
						
							break;
						}
						case 168: {
							viTri = 9;
							selectSuaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page, maSVSua, hoSua, tenSua, passwordSua, gioiTinhSua);
							x = - 1, y = -1;
						
							break;
						}
						case 169: { //ma sv
							nhapText(170, 105, 380, 130, maSVSua, 15, 1);
							x = - 1, y = -1;
							break;
						}
						case 170: { //ho
							nhapText(170, 145, 380, 170, hoSua, 20, 0);
							x = - 1, y = -1;
							break;
						}
						case 171: { //ten
							nhapText(590, 145, 800, 170, tenSua, 10, 0);
							x = - 1, y = -1;
							break;
						}
						case 172: { //password
							nhapText(590, 105, 800, 130, passwordSua, 16, 1);
							x = - 1, y = -1;
							break;
						}
						case 173: { 
							gioiTinhSua = 1;
							tao_button(30, 180, 150, 210, "NAM" , MAU_DO_NHAT, MAU_TRANG, 173, mapID);
							tao_button(170, 180, 290, 210, "NU", MAU_XANH_DUONG, MAU_DEN, 174, mapID);
							break;
						}
						case 174: { //nu
							gioiTinhSua = 2;
							tao_button(30, 180, 150, 210, "NAM" , MAU_XANH_DUONG, MAU_DEN, 173, mapID);
							tao_button(170, 180, 290, 210, "NU", MAU_DO_NHAT, MAU_TRANG, 174, mapID);
							break;
						}
						case 175: { // dong y sua
							PTRSinhVien p = timKiemSVTheoVT(dsLop.lh[state + page*10]->dsSinhVien, viTri + pageSV*10); 
							setbkcolor(MAU_NEN);

							if(demMonDaThi(p->sv.dsDiemThi) > 0) {
								reset_layout(1046,140,1359,499, MAU_NEN);
								reset_layout(11,66,1029,310, MAU_NEN);
						
								outtextxy(1085,150, "Sinh vien da thi,");
								outtextxy(1075,170, "khong the sua!");
										
								delay(1000);
								
								reset_layout(1046,140,1359,499, MAU_NEN);
								goto sua_menu;
								x = - 1, y = -1;
								break;
							}
							else {
								if(kiemTraChuoiRong(maSVSua) == 1 || kiemTraChuoiRong(hoSua) == 1 || kiemTraChuoiRong(tenSua) || kiemTraChuoiRong(passwordSua)){	//xoa khoang trang 
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Vui long dien day du");
									outtextxy(1075,170, "thong tin sinh vien!");
									
									delay(1000);
									
									reset_layout(1046,140,1359,499, MAU_NEN);
									goto sua_menu;
									x = - 1, y = -1;
 
									break;
								}
									// Neu nhu ten lop thay doi thi kiemm tra ten lop do co trung` hay khong	
								if(ktTrungMaSVSchool(dsLop, maSVSua) && strcmp(maSVSua, p->sv.maSV) != 0) {		
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Ma SV da ton tai,");
									outtextxy(1075,170, "vui long nhap lai!");
									
									delay(1000);
									
									reset_layout(1046,140,1359,499, MAU_NEN);
									goto sua_menu;
									x = - 1, y = -1;
 
									break;
								}
								strcpy(p->sv.maSV, maSVSua);
								strcpy(p->sv.ho, hoSua);
								strcpy(p->sv.ten, tenSua);
								strcpy(p->sv.password, passwordSua);

								if(gioiTinhSua == 1) 
									strcpy(p->sv.phai, "Nam");
								else if(gioiTinhSua == 2)
									strcpy(p->sv.phai, "Nu");
														
								luuFileDSSV(dsLop.lh[state + page*10]->dsSinhVien, dsLop.lh[state + page*10]->maLop);
												
								reset_layout(1046,140,1359,499, MAU_NEN);
								outtextxy(1085,150, "Sua thong tin sinh");
								outtextxy(1075,170, "vien thanh cong!");
								drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], pageSV);
								tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN,34, mapID);
								tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
								tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
								
								reset_layout(11,66,1029,310, MAU_NEN);
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
								goto sua_menu;
							}

							break;
						}
						case 176: { // Huy sua
							x=-1;y=-1;
							goto sua_menu;
							break;
						}
						case 36: {
							goto menu;
							break;
						}
						case 34: {
							goto menu;
							break;
						}
						case 44: { //back
						pageSV = 0;
							reset_layout(11,66,1029,354, MAU_NEN);
							tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 43, mapID);
							tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 153, mapID);
	                        tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 154, mapID);
							drawInputTimSV(mapID);
							inDSLop(mapID,dsLop,arrID, page);
							goto menu;
							break;
						}
						case 182: { //prev
														
							if(pageSV > 0 ) {
								pageSV --;
								drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], pageSV);
								tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);
								tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 182, mapID);
								tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 183, mapID);
								tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
								tao_button(520, 320, 580, 350, "Sua", MAU_DO_NHAT, MAU_DEN, 35, mapID);
								tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
								goto sua_menu;
							}
							x = - 1, y = -1;
							break;
						} 
						case 183: { //next
							int soLuong = demSLSinhVien(dsLop.lh[state + page*10]->dsSinhVien); //dem so luong sv trong lop
							int maxpage;
							if(soLuong <= 10)
							{
								maxpage = 0;
							}
							else if (soLuong % 10 == 0)
							{
								maxpage = soLuong/10 - 1;
							}
							else maxpage = soLuong/10; 
													
							if(pageSV < maxpage) {
								pageSV ++;
								drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], pageSV);
								tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);
								tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 182, mapID);
								tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 183, mapID);
								tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
								tao_button(520, 320, 580, 350, "Sua", MAU_DO_NHAT, MAU_DEN, 35, mapID);
								tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
								goto sua_menu;
							}
							x = - 1, y = -1;
							break;
						}
					}
				}
				break;
			}
			case 36: { //xoa
				xoa_menu:
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_DO_NHAT, MAU_DEN, 36, mapID);
										
				reset_layout(11,66,1029,310, MAU_NEN);
				int viTri;
				x = - 1, y = -1;
				while (1) {
					delay(0.001); 
					ID = 0;
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN,x,y);
						ID = mapID[x][y];
						clearmouseclick(WM_LBUTTONDOWN);
					}
						
					if(x != -1 && y != -1)
					switch(ID) {
						case 159: {
							viTri = 0;
							selectXoaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page);
							x = - 1, y = -1;
						
							break;
						}
						case 160: {
							viTri = 1;
							selectXoaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page);
							x = - 1, y = -1;
						
							break;
						}
						case 161: {
							viTri = 2;
							selectXoaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page);
							x = - 1, y = -1;
						
							break;
						}
						case 162: {
							viTri = 3;
							selectXoaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page);
							x = - 1, y = -1;
						
							break;
						}
						case 163: {
							viTri = 4;
							selectXoaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page);
							x = - 1, y = -1;
						
							break;
						}
						case 164: {
							viTri = 5;
							selectXoaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page);
							x = - 1, y = -1;
						
							break;
						}
						case 165: {
							viTri = 6;
							selectXoaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page);
							x = - 1, y = -1;
						
							break;
						}
						case 166: {
							viTri = 7;
							selectXoaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page);
							x = - 1, y = -1;
						
							break;
						}
						case 167: {
							viTri = 8;
							selectXoaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page);
							x = - 1, y = -1;
						
							break;
						}
						case 168: {
							viTri = 9;
							selectXoaSinhVien(mapID, arrID, dsLop, state, viTri, pageSV, page);
							x = - 1, y = -1;
						
							break;
						}
												
											
						case 175: { // dong y sua
							PTRSinhVien p = timKiemSVTheoVT(dsLop.lh[state + page*10]->dsSinhVien, viTri + pageSV*10); 
							setbkcolor(MAU_NEN);

							if(demMonDaThi(p->sv.dsDiemThi) > 0) {
								reset_layout(1046,140,1359,499, MAU_NEN);
								reset_layout(11,66,1029,310, MAU_NEN);
						
								outtextxy(1085,150, "Sinh vien da thi,");
								outtextxy(1075,170, "khong the xoa!");
								
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
								goto xoa_menu;						
								x = - 1, y = -1;
								break;
							}
							else {
								canhBaoXoa(mapID);

								x = - 1, y = -1;

								while (1) {
									delay(0.001); 
									ID = 0;
									if(ismouseclick(WM_LBUTTONDOWN)){
										getmouseclick(WM_LBUTTONDOWN,x,y);
										ID = mapID[x][y];
										clearmouseclick(WM_LBUTTONDOWN);
									}
															
									if(x != -1 && y != -1)
									switch(ID) { 
										case 177: { //dong y xoa
											Delete_SV(p, dsLop.lh[state + page*10]->dsSinhVien);
													
											luuFileDSSV(dsLop.lh[state + page*10]->dsSinhVien, dsLop.lh[state + page*10]->maLop);
															
											reset_layout(1046,140,1359,499, MAU_NEN);
											outtextxy(1085,150, "Xoa thong tin sinh");
											outtextxy(1075,170, "vien thanh cong!");
											drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], 0);
											reset_layout(11,66,1029,310, MAU_NEN);
											delay(1000);
											reset_layout(1046,140,1359,499, MAU_NEN);
											goto xoa_menu;

											x=-1;y=-1;
											break;
										}
										case 178: { //khong dong y xoa
											reset_layout(1046,140,1359,499, MAU_NEN);
											goto xoa_menu;
											x=-1;y=-1;
											break;
										}
										default :
											break;
									} 
								}
							}

							break;
						}
						case 176: { // Huy xoa
							goto xoa_menu;
							x=-1;y=-1;
							break;
						}
						case 44: { //back 
						pageSV = 0;
							reset_layout(11,66,1029,354, MAU_NEN);
							tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 43, mapID);
							tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 153, mapID);
							tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 154, mapID);
							drawInputTimSV(mapID);
							inDSLop(mapID,dsLop,arrID, page);
							goto menu;
							break;
						}
						case 35: {
							goto menu;
							break;
						}
						case 34: {
							goto menu;
							break;
						}
						case 182: { //prev
														
							if(pageSV > 0 ) {
								pageSV --;
								drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], pageSV);
								tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);
								tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 182, mapID);
								tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 183, mapID);
								tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
								tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
								tao_button(590, 320, 650, 350, "Xoa", MAU_DO_NHAT, MAU_DEN, 36, mapID);
								goto xoa_menu;
							}
							x = - 1, y = -1;
							break;
						} 
						case 183: { //next
							int soLuong = demSLSinhVien(dsLop.lh[state + page*10]->dsSinhVien); //dem so luong sv trong lop
							int maxpage;
							if(soLuong <= 10)
							{
								maxpage = 0;
							}
							else if (soLuong % 10 == 0)
							{
								maxpage = soLuong/10 - 1;
							}
							else maxpage = soLuong/10; 
													
							if(pageSV < maxpage) {
								pageSV ++;
								drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], pageSV);
								tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);
								tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 182, mapID);
								tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 183, mapID);
								tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
								tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
								tao_button(590, 320, 650, 350, "Xoa", MAU_DO_NHAT, MAU_DEN, 36, mapID);
								goto xoa_menu;
							}
							x = - 1, y = -1;
							break;
						}
					}
				}
				break;
										
			}
			case 169: { //ma sv
				nhapText(170, 105, 380, 130,maSV, 15, 1);
				x = - 1, y = -1;
				break;
			}
			case 170: { //ho
				nhapText(170, 145, 380, 170, ho, 20, 0);
				x = - 1, y = -1;
				break;
			}
			case 171: { //ten
				nhapText(590, 145, 800, 170, ten, 10, 0);
				x = - 1, y = -1;
				break;
			}
			case 172: { //password
				nhapText(590, 105, 800, 130, password, 16, 1);
				x = - 1, y = -1;
				break;
			}
			case 173: { 
				gioiTinh = 1;
				tao_button(30, 180, 150, 210, "NAM" , MAU_DO_NHAT, MAU_TRANG, 173, mapID);
				tao_button(170, 180, 290, 210, "NU", MAU_XANH_DUONG, MAU_DEN, 174, mapID);
				break;
			}
			case 174: { //nu
				gioiTinh = 2;
				tao_button(30, 180, 150, 210, "NAM" , MAU_XANH_DUONG, MAU_DEN, 173, mapID);
				tao_button(170, 180, 290, 210, "NU", MAU_DO_NHAT, MAU_TRANG, 174, mapID);
				break;
			}
			case 175: {  //save
				int kt = xuLyNhapSinhVien(dsLop, maSV, ho, ten, password, gioiTinh);
				setbkcolor(MAU_NEN);
				setcolor(MAU_DEN);
				switch(kt) {
					case 1: {
						reset_layout(1046,140,1359,499, MAU_NEN); 
						outtextxy(1085,150, "Vui long dien day du");
						outtextxy(1075,170, "thong tin sinh vien!"); 
						delay(1000);
						reset_layout(1046,140,1359,499, MAU_NEN);
						break;
					}
					case 2: {
						reset_layout(1046,140,1359,499, MAU_NEN); 

						outtextxy(1085,150, "Ma SV da ton tai, vui");
						outtextxy(1075,170, "long nhap lai!");
						delay(1000);
						reset_layout(1046,140,1359,499, MAU_NEN);
						break;
					}
					case 3: {
						reset_layout(1046,140,1359,499, MAU_NEN); 

						outtextxy(1085,150, "Vui long chon gioi");
						outtextxy(1075,170, "tinh!");
						delay(1000);
						reset_layout(1046,140,1359,499, MAU_NEN);
						break;
					}
					case 0: {
						SinhVien sv;
						strcpy(sv.maSV, maSV);
						strcpy(sv.ho, ho);
						strcpy(sv.ten, ten);
						strcpy(sv.password, password);
											
						if(gioiTinh == 1) strcpy(sv.phai,"Nam");
						else if(gioiTinh == 2) strcpy(sv.phai, "Nu");
						sv.dsDiemThi = NULL;
						themMotSinhVien(dsLop.lh[state + page*10]->dsSinhVien, sv);
						luuFileDSSV(dsLop.lh[state + page*10]->dsSinhVien, dsLop.lh[state + page*10]->maLop);
												
						reset_layout(1046,140,1359,499, MAU_NEN); 
												
						gioiTinh = 0;
						xoaChuoi(maSV);
						xoaChuoi(ho);
						xoaChuoi(ten);
						xoaChuoi(password);
						drawInputThemSV(mapID, arrID);

						outtextxy(1085,150, "Them sinh vien thanh");
						outtextxy(1075,170, "cong!");
						drawDSSinhVien(mapID, arrID, dsLop.lh[state + page*10], pageSV);
						reset_layout(11,66,1029,310, MAU_NEN);
						tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
						tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
						tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
						drawInputThemSV(mapID, arrID);
						delay(1000);
						reset_layout(1046,140,1359,499, MAU_NEN);
						break;
					} 
					default: 
						break;
				}
				break;
			}
			case 176: { //huy
				gioiTinh = 0;
				xoaChuoi(maSV);
				xoaChuoi(ho);
				xoaChuoi(ten);
				xoaChuoi(password);
				
				reset_layout(11,66,1029,310, MAU_NEN);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				
				break;
			}
			case 43: { //back
				drawMainMenu(mapID, dsMonHoc, dsLop, rootTree, arrID);
				break;
			}
			case 153: { //Prev page lop
				int maxpage;
				if(dsLop.soLuong <= 10) { // Neu so luong <= 10
					maxpage = 0;
				}
				else if(dsLop.soLuong % 10 == 0){
					maxpage = dsLop.soLuong/10 -1;
				}
				else maxpage = dsLop.soLuong/10;
				
				if(page > 0 ) {
					page --;
					inDSLop(mapID, dsLop, arrID, page);	
				}
				x = - 1, y = -1;
				break;
			}
			
			case 154: { //Next page lop
				int maxpage;
				if(dsLop.soLuong <= 10) { // Neu so luong <= 10
					maxpage = 0;
				}
				else if(dsLop.soLuong % 10 == 0){
					maxpage = dsLop.soLuong/10 -1;
				}
				else maxpage = dsLop.soLuong/10;
				
				if(page < maxpage) {
					page ++;
					inDSLop(mapID, dsLop, arrID, page);	
				}
				x = - 1, y = -1;
				break;
			}
			default:
				break;			
		}
		
	}
}


void drawQLSinhVien(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree) {
	int maxpage;	

	resetID(arrID);
	setbkcolor(MAU_NEN);

   	cleardevice();
	settextstyle(10,0,2);

	tao_khung(5,60,1035,860); 
	tao_khung(10,65,1030,355);
	tao_khung(10,365,1030,855);
	
	tao_khung(1045,60,1360,500); //khung canh bao
	
	settextstyle(10,0,5);
	setcolor(COLOR(247,145,31)); //color orange with rbg
	outtextxy(530,10,"Quan Ly Sinh Vien");

	settextstyle(10,0,2);
	setcolor(MAU_DO_NHAT);
	outtextxy(1120,80,"BANG THONG BAO");
	line(1120,100,1290,100);
	setcolor(MAU_DEN);
	
	if(dsLop.soLuong <= 10) { // Neu so luong <= 10
		maxpage = 0;
	}
	else if(dsLop.soLuong % 10 == 0){
		maxpage = dsLop.soLuong/10 -1;
	}
	else maxpage = dsLop.soLuong/10;
	
	
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 43, mapID);

	tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 153, mapID);
	tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 154, mapID);
	
	drawInputTimSV(mapID);


	
	 //Noi chuoi
	char page_str[10] = "";  
	itoa(maxpage+1, page_str, 10);
	char res[20] = "";
	strcat(res,"Trang 1/");
	strcat(res, page_str);
	outtextxy(490,810, res);
	
	inDSLop(mapID,dsLop,arrID, 0);
	
	checkMouseQLSinhVien(mapID, arrID, dsMonHoc, dsLop, rootTree);
	
}


void drawDSMonHoc(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, int page) {
	
	reset_layout(11, 366, 1029, 790, MAU_NEN);
	resetID(arrID);
	setbkcolor(MAU_NEN);
	int arrDoDaiTable[] = { 100, 250, 650}; 
	char title[][50] = { "STT", "Ma Mon Hoc" , "Ten Mon Hoc"};

	tao_bang(20, 375, 35, 3, 11, arrDoDaiTable, title, arrID, mapID, page);
	
	settextstyle(10,0,2);

	for(int i = page * 10; i< (page+1)*10;i++) {
		if(strcmp(dsMonHoc.mh[i].maMH, "") == 0) {
			break;
		}
		else {
			setID(20,410+35*(i%10),1020,445 + 35*(i%10),++arrID[8], mapID);
			outtextxy(130,420 + 35*(i%10), dsMonHoc.mh[i].maMH);
			outtextxy(380,420 + 35*(i%10), dsMonHoc.mh[i].tenMH);
		}
	
	}
	int maxpage;
	if(dsMonHoc.soLuong <= 10) { // Neu so luong <= 10
		maxpage = 0;
	}
	else if(dsMonHoc.soLuong % 10 == 0){
		maxpage = dsMonHoc.soLuong/10 -1;
	}
	else maxpage = dsMonHoc.soLuong/10;
	
	
	char page_str[10] = "";  
	char maxpage_str[10] = "";
	char res[20] = "";

	itoa(maxpage+1, maxpage_str, 10);
	itoa(page+1, page_str, 10);
	strcat(res,"Trang ");
	
	strcat(res,page_str);
	strcat(res,"/");
	strcat(res,maxpage_str);

	reset_layout(460,790,700,820,MAU_NEN);
	setbkcolor(MAU_NEN);
	outtextxy(490,810, res);
}

void drawInputMonHoc(short **mapID) {
	reset_layout(11,66,1029,310, MAU_NEN);
	settextstyle(10,0,3);		
			
		
	tao_button(30,100 ,150,130 , "Ma MH", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160,100 , 380,130 , 38, mapID);
		
	tao_button(30,140 ,150,170 , "Ten MH", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160,140 , 900,170 , 39, mapID);
		
		
	tao_button(350, 200, 410, 230, "Save", MAU_HONG, MAU_DEN, 40, mapID );
	tao_button(430, 200, 490, 230, "Huy", MAU_HONG, MAU_DEN, 41, mapID );
}

void selectSuaMonHoc(short **mapID, int state, int page, DanhSachMonHoc dsMonHoc, char maMHSua[], char tenMHSua[]) {
		reset_layout(11,66,1029,310, MAU_NEN);
	
		tao_button(30,100 ,150,130 , "Ma MH", MAU_HONG, MAU_DEN, -2, mapID);
		taoTextInput(160,100 , 380,130 , 38, mapID);
		tao_button(30,140 ,150,170 , "Ten MH", MAU_HONG, MAU_DEN, -2, mapID);
		taoTextInput(160,140 , 900,170 , 39, mapID);
		settextstyle(10,0,2);	

		outtextxy(170,105, dsMonHoc.mh[state + page*10].maMH);

		outtextxy(170,145, dsMonHoc.mh[state + page*10].tenMH);
		setbkcolor(MAU_NEN);	

		tao_button(450, 250, 510, 280, "Sua", MAU_HONG, MAU_DEN, 151, mapID );
		tao_button(530, 250, 590, 280, "Huy", MAU_HONG, MAU_DEN, 152, mapID );
		
		xoaChuoi(maMHSua);
		xoaChuoi(tenMHSua);
		strcpy(maMHSua, dsMonHoc.mh[state + page*10].maMH);
		strcpy(tenMHSua, dsMonHoc.mh[state + page*10].tenMH);
}

void drawInputXoaMonHoc(short **mapID, char maMH[], char tenMH[]) {
	reset_layout(11,66,1029,310, MAU_NEN);
	settextstyle(10,0,3);	
	
		
	tao_button(30,100 ,150,130 , "Ma MH", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160,100 , 380,130 , -2, mapID);
	outtextxy(170,105,maMH);
	tao_button(30,140 ,150,170 , "Ten MH", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160,140 , 900,170 , -2, mapID);
	outtextxy(170,145,tenMH);
	setbkcolor(MAU_NEN);	

	tao_button(450, 250, 510, 280, "Xoa", MAU_HONG, MAU_DEN, 151, mapID );
	tao_button(530, 250, 590, 280, "Huy", MAU_HONG, MAU_DEN, 152, mapID );
}

void checkMouseQLMonHoc(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree) {
	int x = - 1, y = -1;
	char maMH[17] = "";
	char tenMH[52] = "";
	char maMHSua[17] = "";
	char tenMHSua[52] = "";
	int page = 0;
	while (1) {
		delay(0.001); 

		int ID = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			ID = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(x != -1 && y != -1)

		menu:
		switch(ID) {		
			case 34: {  //Them
				tao_button(450, 320, 510, 350, "Them", MAU_DO_NHAT, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);

				drawInputMonHoc(mapID); 
				x = - 1, y = -1; 

				break;
			}
			case 35: {  //Sua
				sua_menu:

				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_DO_NHAT, MAU_DEN, 35, mapID);

				reset_layout(11,66,1029,310, MAU_NEN);
				int state;
				x = - 1, y = -1;
				while (1) {
					delay(0.001); 
					ID = 0;
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN,x,y);
						ID = mapID[x][y];
						clearmouseclick(WM_LBUTTONDOWN);
					}

					if(x != -1 && y != -1)
					switch(ID) {
						case 187: {
							state = 0;
							selectSuaMonHoc(mapID, state, page, dsMonHoc, maMHSua, tenMHSua);
	
							x = - 1, y = -1;

							break;
						}
						case 188: {
							state = 1;
							selectSuaMonHoc(mapID, state, page, dsMonHoc, maMHSua, tenMHSua);
							x = - 1, y = -1;

							break;
						}
						case 189: {
							state = 2;
							selectSuaMonHoc(mapID, state, page, dsMonHoc, maMHSua, tenMHSua);
							x = - 1, y = -1;

							break;
						}
						case 190: {
							state = 3;
							selectSuaMonHoc(mapID, state, page, dsMonHoc, maMHSua, tenMHSua);
							x = - 1, y = -1;

							break;
						}
						case 191: {
							state = 4;
							selectSuaMonHoc(mapID, state, page, dsMonHoc, maMHSua, tenMHSua);
							x = - 1, y = -1;

							break;
						}
						case 192: {
							state = 5;
							selectSuaMonHoc(mapID, state, page, dsMonHoc, maMHSua, tenMHSua);
							x = - 1, y = -1;
							break;
						}
						case 193: {
							state = 6;
							selectSuaMonHoc(mapID, state, page, dsMonHoc, maMHSua, tenMHSua);
							x = - 1, y = -1;
							break;
						}
						case 194: {
							state = 7;
							selectSuaMonHoc(mapID, state, page, dsMonHoc, maMHSua, tenMHSua);
							x = - 1, y = -1;
							break;
						}
						case 195: {
							state = 8;
							selectSuaMonHoc(mapID, state, page, dsMonHoc, maMHSua, tenMHSua);
							x = - 1, y = -1;

							break;
						}
						case 196: {
							state = 9;
							selectSuaMonHoc(mapID, state, page, dsMonHoc, maMHSua, tenMHSua);
							x = - 1, y = -1;

							break;
						}
						case 151: {  // sua
							setbkcolor(MAU_NEN);
							if(checkMHDaThi(maMHSua, dsLop)) {
								reset_layout(1046,140,1359,499, MAU_NEN);
								reset_layout(11,66,1029,310, MAU_NEN);

								outtextxy(1080,150, "Mon hoc da co sinh vien");
								outtextxy(1075,170, "da thi khong the sua!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
								x = - 1, y = -1;
								break;
							}
							else if(lengthCauHoiTheoMH(rootTree, maMHSua) > 0) { //Mon Hoc co ds cau hoi
								reset_layout(1046,140,1359,499, MAU_NEN);
								reset_layout(11,66,1029,310, MAU_NEN);

								outtextxy(1080,150, "Mon hoc da co cau hoi");
								outtextxy(1075,170, "khong the sua!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
								
								x = - 1, y = -1;
								break;
							}
							else {
								if(kiemTraChuoiRong(maMHSua)  == 1 || kiemTraChuoiRong(tenMHSua) == 1 ) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Ma mon hoc hoac ten");
									outtextxy(1075,170, "mon hoc khong de trong!");
									
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									x = - 1, y = -1;
									break;
								}
								//Neu nhu ma lop thay doi thi kiem tra ma lop do co' trung` hay khong
								if(ktTrungMaMonHoc(maMHSua, dsMonHoc) && strcmp(maMHSua, dsMonHoc.mh[state + page*10].maMH) != 0) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Ma mon hoc da ton tai,");
									outtextxy(1075,170, "vui long nhap lai!");
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);

									x = - 1, y = -1;
									break;
								}
							
								strcpy(dsMonHoc.mh[state + page*10].maMH, maMHSua);
								strcpy(dsMonHoc.mh[state + page*10].tenMH, tenMHSua);


								luuFileDSMonHoc(dsMonHoc);
								drawDSMonHoc(mapID, arrID, dsMonHoc, page);
								reset_layout(1046,140,1359,499, MAU_NEN); //reseet layout bang thong bao
								outtextxy(1080,150, "Sua mon hoc thanh cong!");
								
								reset_layout(11,66,1029,310, MAU_NEN);
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);

							}
							x = - 1, y = -1;
						
							break;
						}
						case 152: {  //Huy sua
							goto sua_menu;
							break;
						}  
						case 38: {
						
							nhapText(170, 105, 380, 130, maMHSua, 15, 1);
							x = - 1, y = -1;
							break;
						}
						case 39: {

							nhapText(170, 145, 900, 170, tenMHSua, 50, 0);
							x = - 1, y = -1;
							break;
						}
						case 43: { //back
							drawMainMenu(mapID, dsMonHoc, dsLop, rootTree, arrID);
							break;
						}
						case 153: { //Prev
				
							if(page > 0 ) {
								page --;
								drawDSMonHoc(mapID, arrID, dsMonHoc, page);
							}
							x = - 1, y = -1;
							break;
						}
						
						case 154: { //Next
							int maxpage;
							if(dsMonHoc.soLuong <= 10) { // Neu so luong <= 10
								maxpage = 0;
							}
							else if(dsMonHoc.soLuong % 10 == 0){
								maxpage = dsMonHoc.soLuong/10 -1;
							}
							else maxpage = dsMonHoc.soLuong/10;
							
							if(page < maxpage) {
								page ++;
								drawDSMonHoc(mapID, arrID, dsMonHoc, page);
							}
							x = - 1, y = -1;
							break;
						}
						case 33: {
							goto menu;
							break;
						}
						case 34: {
							goto menu;
							break;
						}
						case 36: {
							goto menu;
							break;
						}
						default:
							break;
						
					}
					
				}
				x = - 1, y = -1;				
				break;
			}
			case 36: {  //Xoa
				xoa_menu:

				tao_button(590, 320, 650, 350, "Xoa", MAU_DO_NHAT, MAU_DEN, 36, mapID);
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);

				reset_layout(11,66,1029,310, MAU_NEN);
				int state;
				x = - 1, y = -1;
				while (1) {
					delay(0.001); 
					ID = 0;
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN,x,y);
						ID = mapID[x][y];
						clearmouseclick(WM_LBUTTONDOWN);
					}

					if(x != -1 && y != -1)
					switch(ID) {
						case 187: {
							state = 0;

							drawInputXoaMonHoc(mapID, dsMonHoc.mh[state + page*10].maMH, dsMonHoc.mh[state + page*10].tenMH);
							x = - 1, y = -1;

							break;
						}
						case 188: {
							state = 1;
							drawInputXoaMonHoc(mapID, dsMonHoc.mh[state + page*10].maMH, dsMonHoc.mh[state + page*10].tenMH);
							x = - 1, y = -1;

							break;
						}
						case 189: {
							state = 2;
							drawInputXoaMonHoc(mapID, dsMonHoc.mh[state + page*10].maMH, dsMonHoc.mh[state + page*10].tenMH);
							x = - 1, y = -1;

							break;
						}
						case 190: {
							state = 3;
							drawInputXoaMonHoc(mapID, dsMonHoc.mh[state + page*10].maMH, dsMonHoc.mh[state + page*10].tenMH);

							x = - 1, y = -1;

							break;
						}
						case 191: {
							state = 4;
							drawInputXoaMonHoc(mapID, dsMonHoc.mh[state + page*10].maMH, dsMonHoc.mh[state + page*10].tenMH);
							x = - 1, y = -1;

							break;
						}
						case 192: {
							state = 5;
							drawInputXoaMonHoc(mapID, dsMonHoc.mh[state + page*10].maMH, dsMonHoc.mh[state + page*10].tenMH);
							x = - 1, y = -1;
							break;
						}
						case 193: {
							state = 6;
							drawInputXoaMonHoc(mapID, dsMonHoc.mh[state + page*10].maMH, dsMonHoc.mh[state + page*10].tenMH);
							x = - 1, y = -1;
							break;
						}
						case 194: {
							state = 7;
							drawInputXoaMonHoc(mapID, dsMonHoc.mh[state + page*10].maMH, dsMonHoc.mh[state + page*10].tenMH);
							x = - 1, y = -1;
							break;
						}
						case 195: {
							state = 8;
							drawInputXoaMonHoc(mapID, dsMonHoc.mh[state + page*10].maMH, dsMonHoc.mh[state + page*10].tenMH);
							x = - 1, y = -1;

							break;
						}
						case 196: {
							state = 9;
							drawInputXoaMonHoc(mapID, dsMonHoc.mh[state + page*10].maMH, dsMonHoc.mh[state + page*10].tenMH);
							x = - 1, y = -1;

							break;
						}
						case 151: {  //click Xoa
						
							if(checkMHDaThi(dsMonHoc.mh[state + page*10].maMH, dsLop)) {
								reset_layout(1046,140,1359,499, MAU_NEN);
								reset_layout(11,66,1029,310, MAU_NEN);

								outtextxy(1080,150, "Mon hoc da co sinh vien");
								outtextxy(1075,170, "thi the xoa!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
								
								x = - 1, y = -1;
								break;
							}
							
							else if(lengthCauHoiTheoMH(rootTree, dsMonHoc.mh[state + page*10].maMH) > 0) { //Mon Hoc co ds cau hoi
								reset_layout(1046,140,1359,499, MAU_NEN);
								reset_layout(11,66,1029,310, MAU_NEN);
						
								outtextxy(1080,150, "Mon hoc da co cau hoi");
								outtextxy(1075,170, "khong the xoa!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
								
								x = - 1, y = -1;
								break;
							}
							else {
								canhBaoXoa(mapID);
								x = - 1, y = -1;

								while (1) {
									delay(0.001); 
									ID = 0;
									if(ismouseclick(WM_LBUTTONDOWN)){
										getmouseclick(WM_LBUTTONDOWN,x,y);
										ID = mapID[x][y];
										clearmouseclick(WM_LBUTTONDOWN);
									}
																
									if(x != -1 && y != -1)
									switch(ID) { 
										case 177: { //dong y xoa
											for(int i = state + page*10; i < dsMonHoc.soLuong; i++) {
												dsMonHoc.mh[i] = dsMonHoc.mh[i+1];
											}
											dsMonHoc.soLuong --;
											luuFileDSMonHoc(dsMonHoc);
											
											reset_layout(1046,140,1359,499, MAU_NEN); //reset layout bang thong bao
											outtextxy(1080,150, "Xoa mon hoc thanh cong!");
											page = 0;
											drawDSMonHoc(mapID, arrID, dsMonHoc, page);

											reset_layout(11,66,1029,310, MAU_NEN);
											delay(1000);
											reset_layout(1046,140,1359,499, MAU_NEN);	
											goto xoa_menu;						
										}
										case 178: { //khong dong y xoa
											reset_layout(1046,140,1359,499, MAU_NEN);
											goto xoa_menu;
											x=-1;y=-1;
											break;
										}
										default :
											break;
										
									} 
								}
								

							}
							x = - 1, y = -1;
						
							break;
						}
						case 152: {  //Huy xoa
							goto xoa_menu;
							break;
						}  
						case 43: {
							drawMainMenu(mapID, dsMonHoc, dsLop, rootTree, arrID);
							break;
						}
						case 153: { //Prev
				
							if(page > 0 ) {
								page --;
								drawDSMonHoc(mapID, arrID, dsMonHoc, page);
							}
							x = - 1, y = -1;
							break;
						}
						
						case 154: { //Next
							int maxpage;
							if(dsMonHoc.soLuong <= 10) { // Neu so luong <= 10
								maxpage = 0;
							}
							else if(dsMonHoc.soLuong % 10 == 0){
								maxpage = dsMonHoc.soLuong/10 -1;
							}
							else maxpage = dsMonHoc.soLuong/10;
							
							if(page < maxpage) {
								page ++;
								drawDSMonHoc(mapID, arrID, dsMonHoc, page);
							}
							x = - 1, y = -1;
							break;
						}
						case 33: { //find
							goto menu;
							break;
						}
						case 34: { //them
							goto menu;
							break;
						}
						case 35: { //sua
							goto menu;
							break;
						}
						default: 
							break;
						
					}
					
				}
				x = - 1, y = -1;

				break;
			}
			case 38: {
				nhapText(170, 105, 380, 130, maMH, 15, 1);
				x = - 1, y = -1;
				break;
			}
			case 39: {
				nhapText(170, 145, 900, 170, tenMH, 50, 0);
				x = - 1, y = -1;
				break;
			}
	
			case 40: {  //Save
				setbkcolor(MAU_NEN);

				if(dsMonHoc.soLuong == MAXMONHOC) {
					reset_layout(1046,140,1359,499, MAU_NEN); 
					outtextxy(1085,150, "Khong the them mon");
					outtextxy(1075,170, "hoc danh sach da day!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
					break;
				}
				if(kiemTraChuoiRong(maMH) == 1 || kiemTraChuoiRong(tenMH) == 1 ) {	//xoa khoang trang 
					reset_layout(1046,140,1359,499, MAU_NEN); 
					outtextxy(1085,150, "Vui long dien day du");
					outtextxy(1075,170, "thong tin!"); 
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);
					break;
				}
				if(ktTrungMaMonHoc(maMH, dsMonHoc)) {
					reset_layout(1046,140,1359,499, MAU_NEN); 

					outtextxy(1085,150, "Ma mon hoc da ton tai");
					outtextxy(1075,170, "vui long nhap lai!");
					delay(1000);
					reset_layout(1046,140,1359,499, MAU_NEN);

					break;
				}
			
				MonHoc mh;
				strcpy(mh.maMH, maMH);
				strcpy(mh.tenMH, tenMH);

				dsMonHoc.mh[dsMonHoc.soLuong] = mh;
				dsMonHoc.soLuong++;

				luuFileDSMonHoc(dsMonHoc);
				
				xoaChuoi(maMH);
				xoaChuoi(tenMH);
				drawDSMonHoc(mapID, arrID, dsMonHoc, page);
				drawInputMonHoc(mapID); 
				reset_layout(1046,140,1359,499, MAU_NEN); 
				setbkcolor(MAU_NEN);

				outtextxy(1085,150, "Them mon hoc thanh cong!");
				delay(1000);
				reset_layout(1046,140,1359,499, MAU_NEN);
				break;
			
	
			}
			case 41: {  //Huy
			
				xoaChuoi(maMH);
				xoaChuoi(tenMH);
			
				reset_layout(11, 66, 1029, 310,MAU_NEN);
				
				tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN, 34, mapID);
				tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
				tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);

				x = - 1, y = -1;

				break;
			}
			case 43: { //back
				drawMainMenu(mapID, dsMonHoc, dsLop, rootTree, arrID);
				break;
			}
			case 153: { //Prev
				
				if(page > 0 ) {
					page --;
					drawDSMonHoc(mapID, arrID, dsMonHoc, page);
				}
				x = - 1, y = -1;
				break;
			}
			
			case 154: { //Next
				int maxpage;
				if(dsMonHoc.soLuong <= 10) { // Neu so luong <= 10
					maxpage = 0;
				}
				else if(dsMonHoc.soLuong % 10 == 0){
					maxpage = dsMonHoc.soLuong/10 -1;
				}
				else maxpage = dsMonHoc.soLuong/10;
				
				if(page < maxpage) {
					page ++;
					drawDSMonHoc(mapID, arrID, dsMonHoc, page);
				}
				x = - 1, y = -1;
				break;
			}
			default:
				break;			
		}
		
	}
}


void drawQLMonHoc(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree) {

	resetID(arrID);
	
   	cleardevice();
	setbkcolor(MAU_NEN);
	settextstyle(10,0,2);

	tao_khung(5,60,1035,860); 
	tao_khung(10,65,1030,355);
	tao_khung(10,365,1030,855);//800
	
	tao_khung(1045,60,1360,500); //khung canh bao
	
	settextstyle(10,0,5);
	setcolor(COLOR(247,145,31)); //color orange with rbg
	outtextxy(530,10,"Quan Ly Mon Hoc");

	settextstyle(10,0,2);
	setcolor(MAU_DO_NHAT);
	outtextxy(1120,80,"BANG THONG BAO");
	line(1120,100,1290,100);
	setcolor(MAU_DEN);
	
	
	
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 43, mapID);
	tao_button(450, 320, 510, 350, "Them", MAU_XANH_LA, MAU_DEN,34, mapID);
	tao_button(520, 320, 580, 350, "Sua", MAU_XANH_LA, MAU_DEN, 35, mapID);
	tao_button(590, 320, 650, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 36, mapID);
	tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 153, mapID);
	tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 154, mapID);
	
	drawDSMonHoc(mapID, arrID, dsMonHoc, 0);
	checkMouseQLMonHoc(mapID, arrID, dsMonHoc, dsLop, rootTree);
}


void drawInputXemTheoMon(short **mapID) {
	reset_layout(11,66,1029,310,MAU_NEN);
	settextstyle(10,0,3);
	tao_button(30,150 ,150,180 , "Ma MH", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(160,150 , 380, 180 , 179, mapID);
	tao_button(410, 250, 470, 280, "Find", MAU_HONG, MAU_DEN, 180, mapID );
}

void drawDSCauHoi(short **mapID, int arrID[], PTRCauHoi rootTree, int page, CauHoiThi arr[], int soLuong) {
	reset_layout(11, 366, 1029, 790, MAU_NEN);
	setbkcolor(MAU_NEN);
	resetID(arrID);
	int arrDoDaiTable[] = { 100, 100, 200, 600}; 
	char title[][50] = { "STT","ID","Ma Mon Hoc" , "Noi Dung"};

	tao_bang(20, 375, 35, 4, 11, arrDoDaiTable, title, arrID, mapID, page);
	
	settextstyle(10,0,2);

	for(int i = page * 10; i< (page+1)*10 ; i++) {
		if(i>= soLuong) {
			setID(20,410+35*(i%10),1020,445 + 35*(i%10), -2, mapID);

		}
		else {
			setID(20,410+35*(i%10),1020,445 + 35*(i%10),++arrID[9], mapID);
			char temp[10] = "";
			itoa(arr[i].ID, temp, 10);
			outtextxy(130,420 + 35*(i%10), temp);
			outtextxy(230,420 + 35*(i%10), arr[i].maMH);
			if(strlen(arr[i].noiDung) > 48) {
				char dest[60] = "";
				strncpy(dest, arr[i].noiDung, 46);
				strcat(dest, "...");
				outtextxy(430, 420 + 35*(i%10), dest);
			
			}
			else {
				outtextxy(430, 420 + 35*(i%10), arr[i].noiDung);
			}	
		}
		
		
	}

	int maxpage;
	if(soLuong <= 10) { // Neu so luong <= 10
		maxpage = 0;
	}
	else if(soLuong % 10 == 0){
		maxpage = soLuong/10 -1;
	}
	else maxpage = soLuong/10;
	
	
	char page_str[10] = "";  
	char maxpage_str[10] = "";
	char res[20] = "";

	itoa(maxpage+1, maxpage_str, 10);
	itoa(page+1, page_str, 10);
	strcat(res,"Trang ");
	
	strcat(res,page_str);
	strcat(res,"/");
	strcat(res,maxpage_str);

	reset_layout(460,790,700,820,MAU_NEN);
	setbkcolor(MAU_NEN);
	outtextxy(490,810, res);
}


void drawChiTietCauHoiTheoMon(short **mapID, PTRCauHoi rootTree, int page, char maMH[]) {
	int soLuongCau = lengthCauHoiTheoMH(rootTree, maMH);
	setbkcolor(MAU_NEN);						
	if(soLuongCau  == 0) {
		reset_layout(1046,140,1359,499, MAU_NEN); 
		outtextxy(1085,150, "Danh sach cau hoi");
		outtextxy(1075,170, "trong!");
		delay(1000);
		reset_layout(1046,140,1359,499, MAU_NEN);
		return;
	}
	settextstyle(10,0,3);
	
   	cleardevice();
	khoi_tao_mapID(mapID);	
	tao_khung(150,200,1250,770);

	
							
	CauHoiThi arrCHTheoMon[soLuongCau];
	addCHTheoMonToArray(rootTree, arrCHTheoMon, maMH);
							
	
	
	
	outtextxy(160,220,"Noi Dung:");
	line(160,243,283,243);
	if(strlen(arrCHTheoMon[page].noiDung) > 55) { //auto break line, neu length noi dung hon 60 thi xuong dong`
			char res1[126];
    		char res2[126];
    		char str_temp[126];  //su dung str_temp de khong phai thay doi du lieu cua arrayCauHoiRandom khi chuyen trang
    		strcpy(str_temp,arrCHTheoMon[page].noiDung);
    		catChuoi2Dong(str_temp,res1,res2);

			outtextxy(290,220,res1);
			outtextxy(190,245,res2);
	}
	else {
		outtextxy(290,220,arrCHTheoMon[page].noiDung);
	}
	
	
	
	 //in cau hoi
	tao_circle(200,350,15, -2, mapID);
	outtextxy(220,340,"A.");
	if(strlen(arrCHTheoMon[page].dapAnA) > 60) {
		char resA1[126];
		char resA2[126];
		char str_tempA[126]; 
		strcpy(str_tempA,arrCHTheoMon[page].dapAnA);
    	catChuoi2Dong(str_tempA,resA1,resA2);
    	
		outtextxy(250,340,resA1);
		outtextxy(230,365,resA2);
	} 
	else {
		outtextxy(250,340,arrCHTheoMon[page].dapAnA);
	}

	
	tao_circle(200,450,15, -2, mapID);
	outtextxy(220,440,"B.");

	if(strlen(arrCHTheoMon[page].dapAnB) > 60) {
		char resB1[126];
		char resB2[126];
		char str_tempB[126]; 
		strcpy(str_tempB,arrCHTheoMon[page].dapAnB);
    	catChuoi2Dong(str_tempB,resB1,resB2);
    	
		outtextxy(250,440,resB1);
		outtextxy(230,465,resB2);
	} 
	else {
		outtextxy(250,440,arrCHTheoMon[page].dapAnB);
	}


	tao_circle(200,550,15, -2, mapID);
	outtextxy(220,540,"C.");

	if(strlen(arrCHTheoMon[page].dapAnC) > 60) {
		char resC1[126];
		char resC2[126];
		char str_tempC[126]; 
		strcpy(str_tempC,arrCHTheoMon[page].dapAnC);
    	catChuoi2Dong(str_tempC,resC1,resC2);
    	
		outtextxy(250,540,resC1);
		outtextxy(230,565,resC2);
	} 
	else {
		outtextxy(250,540,arrCHTheoMon[page].dapAnC);
	}
	
	
	tao_circle(200,650,15, -2, mapID);
	outtextxy(220,640,"D.");
	
	if(strlen(arrCHTheoMon[page].dapAnD) > 60) {
		char resD1[126];
		char resD2[126];
		char str_tempD[126]; 
		strcpy(str_tempD,arrCHTheoMon[page].dapAnD);
    	catChuoi2Dong(str_tempD, resD1, resD2);
    	
		outtextxy(250,640,resD1);
		outtextxy(230,665,resD2);
	} 
	else {
		outtextxy(250,640,arrCHTheoMon[page].dapAnD);
	}
	
	
	tao_button(200,100 ,320,130 , "Ma MH", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(330,100 , 550,130 , -2, mapID);
	
	tao_button(600,100 ,660,130 , "ID", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(670,100 , 770, 130 , -2, mapID);
	
	outtextxy(340,105, arrCHTheoMon[page].maMH);
	char tempID[10];
	itoa(arrCHTheoMon[page].ID, tempID, 10);
	outtextxy(680,105, tempID);
	
	switch(arrCHTheoMon[page].dapAn){
		case 'A': {
			tao_circle_checked(200,350,8);
			break;
		}
		case 'B': {
				tao_circle_checked(200,450,8);
			break;
		}
		case 'C': {
				tao_circle_checked(200,550,8);
			break;
		}
		case 'D': {
				tao_circle_checked(200,650,8);
			break;
		}
		default: 
			break;
	
	}
	
	int soLuong  = sizeof(arrCHTheoMon) / sizeof(arrCHTheoMon[0]);
	int maxpage = soLuong;
	
	char page_str[10] = "";  
	char maxpage_str[10] = "";
	char res[20] = "";

	itoa(maxpage, maxpage_str, 10);
	itoa(page+1, page_str, 10);
	strcat(res,"Trang ");
	
	strcat(res,page_str);
	strcat(res,"/");
	strcat(res,maxpage_str);
	
	
	reset_layout(460,790,700,820,MAU_NEN);
	setbkcolor(MAU_NEN);
	outtextxy(670,810, res);
	
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);

	tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 290, mapID);
	tao_button(1260,800,1320,830,"Next", MAU_XANH_LA, MAU_DEN, 291, mapID);
	
	
	
	
}

void drawInputSuaCauHoi(short **mapID, CauHoiThi arr[], int vitri, int page, char noiDungSua[], char dapAnASua[], char dapAnBSua[], char dapAnCSua[], char dapAnDSua[], char &dapAnSua, char maMHSua[]) {
	settextstyle(10,0,3);
	setbkcolor(MAU_NEN);
   	cleardevice();
	khoi_tao_mapID(mapID);	
	tao_khung(30,60,1030,800);
	tao_khung(1045,60,1360,500); //khung canh bao
	
	settextstyle(10,0,5);
	setcolor(COLOR(247,145,31)); //color orange with rbg
	outtextxy(900,10,"Sua Cau Hoi");
	
	settextstyle(10,0,2);
	setcolor(MAU_DO_NHAT);
	outtextxy(1120,80,"BANG THONG BAO");
	line(1120,100,1290,100);

	
	tao_button(1150,530,1270,560,"Sua", MAU_DO_NHAT, MAU_TRANG, 221, mapID);


	
	setcolor(MAU_DEN);
	setbkcolor(MAU_NEN);
	settextstyle(10,0,3);

	
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);
	tao_button(200,20 ,320,50 , "Ma MH", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(330,20 , 550,50 , 220, mapID);
	
	tao_button(600,20 ,660,50 , "ID", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(670,20 , 770, 50 , -2, mapID);
	
	//Noi Dung
	taoTextInput(200,70,1020,200, 215, mapID);
	
	//Cau a
	tao_circle(130,320,15, 222, mapID);

	taoTextInput(200,290,1020,390, 216, mapID);
	
	//Cau b
	tao_circle(130,450,15, 223, mapID);

	taoTextInput(200,420,1020,520, 217, mapID);
	
	//Cau c
	tao_circle(130,580,15, 224, mapID);

	taoTextInput(200,550,1020,650, 218, mapID);
	
	//Cau D
	tao_circle(130,710,15, 225, mapID);
	
	taoTextInput(200,680,1020,780, 219, mapID);

	setbkcolor(MAU_NEN);
	settextstyle(10,0,3);
	
	outtextxy(60,100,"Noi Dung:");
	outtextxy(150,310,"A.");

	outtextxy(150,440,"B.");
	outtextxy(150,570,"C.");
	outtextxy(150,700,"D.");


	setbkcolor(MAU_TRANG);
	settextstyle(10,0,2);
	
	outtextxy(340,25, arr[vitri + page*10].maMH);
	char tempID[10];
	itoa(arr[vitri + page*10].ID, tempID, 10);
	outtextxy(680,25, tempID);


	if(strlen(arr[vitri + page*10 ].noiDung) > 55) { //auto break line, neu length noi dung hon 60 thi xuong dong`
			char res1[126];
    		char res2[126];
    		char str_temp[126];  //su dung str_temp de khong phai thay doi du lieu cua arrayCauHoiRandom khi chuyen trang
    		strcpy(str_temp,arr[vitri + page*10].noiDung);
    		catChuoi2Dong(str_temp,res1,res2);

			outtextxy(210,90,res1);
			outtextxy(210,120,res2);
	}
	else {
		outtextxy(210,90,arr[vitri + page*10].noiDung);
	}
	
	
	
	 //in cau hoi
	if(strlen(arr[vitri + page*10].dapAnA) > 60) {
		char resA1[126];
		char resA2[126];
		char str_tempA[126]; 
		strcpy(str_tempA,arr[vitri + page*10].dapAnA);
    	catChuoi2Dong(str_tempA,resA1,resA2);
    	
		outtextxy(210,300,resA1);
		outtextxy(210,330,resA2);
	} 
	else {
		outtextxy(210,300,arr[vitri + page*10].dapAnA);
	}

	


	if(strlen(arr[vitri + page*10].dapAnB) > 60) {
		char resB1[126];
		char resB2[126];
		char str_tempB[126]; 
		strcpy(str_tempB,arr[vitri + page*10].dapAnB);
    	catChuoi2Dong(str_tempB,resB1,resB2);
    	
		outtextxy(210,430,resB1);
		outtextxy(210,460,resB2);
	} 
	else {
		outtextxy(210,430,arr[vitri + page*10].dapAnB);
	}



	if(strlen(arr[vitri + page*10].dapAnC) > 60) {
		char resC1[126];
		char resC2[126];
		char str_tempC[126]; 
		strcpy(str_tempC,arr[vitri + page*10].dapAnC);
    	catChuoi2Dong(str_tempC,resC1,resC2);
    	
		outtextxy(210,560,resC1);
		outtextxy(210,590,resC2);
	} 
	else {
		outtextxy(210,560,arr[vitri + page*10].dapAnC);
	}
	

	
	if(strlen(arr[vitri + page*10].dapAnD) > 60) {
		char resD1[126];
		char resD2[126];
		char str_tempD[126]; 
		strcpy(str_tempD,arr[vitri + page*10].dapAnD);
    	catChuoi2Dong(str_tempD, resD1, resD2);
    	
		outtextxy(210,690,resD1);
		outtextxy(210,720,resD2);
	} 
	else {
		outtextxy(210,690,arr[vitri + page*10].dapAnD);
	}
	
	


	switch(arr[vitri + page*10].dapAn){
		case 'A': {
			tao_circle_checked(130,320,8);			
			break;
		}
		case 'B': {
			tao_circle_checked(130,450,8);
			break;
		}
		case 'C': {
			tao_circle_checked(130,580,8);
			break;
		}
		case 'D': {
			tao_circle_checked(130,710,8);
			break;
		}
		default: 
			break;
	
	}

	
	strcpy(noiDungSua, arr[vitri + page*10].noiDung);
	strcpy(dapAnASua, arr[vitri + page*10].dapAnA);
	strcpy(dapAnBSua, arr[vitri + page*10].dapAnB);
	strcpy(dapAnCSua, arr[vitri + page*10].dapAnC);
	strcpy(dapAnDSua, arr[vitri + page*10].dapAnD);
	strcpy(maMHSua, arr[vitri + page*10].maMH);
	dapAnSua = arr[vitri + page*10].dapAn;
	
}

void drawInputXoaCH(short **mapID, CauHoiThi arr[], int vitri, int page) {
	settextstyle(10,0,3);
	setbkcolor(MAU_NEN);
   	cleardevice();
	khoi_tao_mapID(mapID);	
	tao_khung(30,60,1030,800);
	tao_khung(1045,60,1360,500); //khung canh bao
	
	settextstyle(10,0,5);
	setcolor(COLOR(247,145,31)); //color orange with rbg
	outtextxy(900,10,"Xoa Cau Hoi");
	
	settextstyle(10,0,2);
	setcolor(MAU_DO_NHAT);
	outtextxy(1120,80,"BANG THONG BAO");
	line(1120,100,1290,100);
	
	setcolor(MAU_DEN);
	setbkcolor(MAU_NEN);
	settextstyle(10,0,3);
	
	
	outtextxy(70,90,"Noi Dung:");
	line(63,113,193,113);
	settextstyle(10,0,2);

	if(strlen(arr[vitri + page*10 ].noiDung) > 55) { //auto break line, neu length noi dung hon 60 thi xuong dong`
			char res1[126];
    		char res2[126];
    		char str_temp[126];  //su dung str_temp de khong phai thay doi du lieu cua arrayCauHoiRandom khi chuyen trang
    		strcpy(str_temp,arr[vitri + page*10].noiDung);
    		catChuoi2Dong(str_temp,res1,res2);

			outtextxy(210,90,res1);
			outtextxy(210,120,res2);
	}
	else {
		outtextxy(210,90,arr[vitri + page*10].noiDung);
	}
	
	
	
	 //in cau hoi
	tao_circle(150,310,15, -2, mapID);
	outtextxy(170,300,"A.");
	if(strlen(arr[vitri + page*10].dapAnA) > 60) {
		char resA1[126];
		char resA2[126];
		char str_tempA[126]; 
		strcpy(str_tempA,arr[vitri + page*10].dapAnA);
    	catChuoi2Dong(str_tempA,resA1,resA2);
    	
		outtextxy(210,300,resA1);
		outtextxy(210,330,resA2);
	} 
	else {
		outtextxy(210,300,arr[vitri + page*10].dapAnA);
	}

	
	tao_circle(150,440,15, -2, mapID);
	outtextxy(170,430,"B.");

	if(strlen(arr[vitri + page*10].dapAnB) > 60) {
		char resB1[126];
		char resB2[126];
		char str_tempB[126]; 
		strcpy(str_tempB,arr[vitri + page*10].dapAnB);
    	catChuoi2Dong(str_tempB,resB1,resB2);
    	
		outtextxy(210,430,resB1);
		outtextxy(210,460,resB2);
	} 
	else {
		outtextxy(210,430,arr[vitri + page*10].dapAnB);
	}


	tao_circle(150,570,15, -2, mapID);
	outtextxy(170,560,"C.");

	if(strlen(arr[vitri + page*10].dapAnC) > 60) {
		char resC1[126];
		char resC2[126];
		char str_tempC[126]; 
		strcpy(str_tempC,arr[vitri + page*10].dapAnC);
    	catChuoi2Dong(str_tempC,resC1,resC2);
    	
		outtextxy(210,560,resC1);
		outtextxy(210,590,resC2);
	} 
	else {
		outtextxy(210,560,arr[vitri + page*10].dapAnC);
	}
	
	
	tao_circle(150,700,15, -2, mapID);
	outtextxy(170,690,"D.");
	
	if(strlen(arr[vitri + page*10].dapAnD) > 60) {
		char resD1[126];
		char resD2[126];
		char str_tempD[126]; 
		strcpy(str_tempD,arr[vitri + page*10].dapAnD);
    	catChuoi2Dong(str_tempD, resD1, resD2);
    	
		outtextxy(210,690,resD1);
		outtextxy(210,720,resD2);
	} 
	else {
		outtextxy(210,690,arr[vitri + page*10].dapAnD);
	}
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);
	tao_button(200,20 ,320,50 , "Ma MH", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(330,20 , 550,50 , -2, mapID);
	
	tao_button(600,20 ,660,50 , "ID", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(670,20 , 770, 50 , -2, mapID);
	
	outtextxy(340,25, arr[vitri + page*10].maMH);
	char tempID[10];
	itoa(arr[vitri + page*10].ID, tempID, 10);
	outtextxy(680,25, tempID);
	
	switch(arr[vitri + page*10].dapAn){
		case 'A': {
			tao_circle_checked(150,310,8);
			break;
		}
		case 'B': {
				tao_circle_checked(150,440,8);
			break;
		}
		case 'C': {
				tao_circle_checked(150,570,8);
			break;
		}
		case 'D': {
				tao_circle_checked(150,700,8);
			break;
		}
		default: 
			break;
	
	}
	tao_button(1150,530,1270,560,"Xoa", MAU_DO_NHAT, MAU_TRANG, 215, mapID);

}

void drawChiTietCauHoi(short **mapID, CauHoiThi arr[], int vitri, int page) {

	settextstyle(10,0,3);
	setbkcolor(MAU_NEN);
   	cleardevice();
	khoi_tao_mapID(mapID);	

	tao_khung(150,200,1250,770);


	
	
	outtextxy(160,220,"Noi Dung:");
	line(160,243,283,243);
	if(strlen(arr[vitri + page*10 ].noiDung) > 55) { //auto break line, neu length noi dung hon 60 thi xuong dong`
			char res1[126];
    		char res2[126];
    		char str_temp[126];  //su dung str_temp de khong phai thay doi du lieu cua arrayCauHoiRandom khi chuyen trang
    		strcpy(str_temp,arr[vitri + page*10].noiDung);
    		catChuoi2Dong(str_temp,res1,res2);

			outtextxy(290,220,res1);
			outtextxy(190,245,res2);
	}
	else {
		outtextxy(290,220,arr[vitri + page*10].noiDung);
	}
	
	
	
	 //in cau hoi
	tao_circle(200,350,15, -2, mapID);
	outtextxy(220,340,"A.");
	if(strlen(arr[vitri + page*10].dapAnA) > 60) {
		char resA1[126];
		char resA2[126];
		char str_tempA[126]; 
		strcpy(str_tempA,arr[vitri + page*10].dapAnA);
    	catChuoi2Dong(str_tempA,resA1,resA2);
    	
		outtextxy(250,340,resA1);
		outtextxy(230,365,resA2);
	} 
	else {
		outtextxy(250,340,arr[vitri + page*10].dapAnA);
	}

	
	tao_circle(200,450,15, -2, mapID);
	outtextxy(220,440,"B.");

	if(strlen(arr[vitri + page*10].dapAnB) > 60) {
		char resB1[126];
		char resB2[126];
		char str_tempB[126]; 
		strcpy(str_tempB,arr[vitri + page*10].dapAnB);
    	catChuoi2Dong(str_tempB,resB1,resB2);
    	
		outtextxy(250,440,resB1);
		outtextxy(230,465,resB2);
	} 
	else {
		outtextxy(250,440,arr[vitri + page*10].dapAnB);
	}


	tao_circle(200,550,15, -2, mapID);
	outtextxy(220,540,"C.");

	if(strlen(arr[vitri + page*10].dapAnC) > 60) {
		char resC1[126];
		char resC2[126];
		char str_tempC[126]; 
		strcpy(str_tempC,arr[vitri + page*10].dapAnC);
    	catChuoi2Dong(str_tempC,resC1,resC2);
    	
		outtextxy(250,540,resC1);
		outtextxy(230,565,resC2);
	} 
	else {
		outtextxy(250,540,arr[vitri + page*10].dapAnC);
	}
	
	
	tao_circle(200,650,15, -2, mapID);
	outtextxy(220,640,"D.");
	
	if(strlen(arr[vitri + page*10].dapAnD) > 60) {
		char resD1[126];
		char resD2[126];
		char str_tempD[126]; 
		strcpy(str_tempD,arr[vitri + page*10].dapAnD);
    	catChuoi2Dong(str_tempD, resD1, resD2);
    	
		outtextxy(250,640,resD1);
		outtextxy(230,665,resD2);
	} 
	else {
		outtextxy(250,640,arr[vitri + page*10].dapAnD);
	}
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);
	tao_button(200,100 ,320,130 , "Ma MH", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(330,100 , 550,130 , -2, mapID);
	
	tao_button(600,100 ,660,130 , "ID", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(670,100 , 770, 130 , -2, mapID);
	
	outtextxy(340,105, arr[vitri + page*10].maMH);
	char tempID[10];
	itoa(arr[vitri + page*10].ID, tempID, 10);
	outtextxy(680,105, tempID);
	
	switch(arr[vitri + page*10].dapAn){
		case 'A': {
			tao_circle_checked(200,350,8);
			break;
		}
		case 'B': {
				tao_circle_checked(200,450,8);
			break;
		}
		case 'C': {
				tao_circle_checked(200,550,8);
			break;
		}
		case 'D': {
				tao_circle_checked(200,650,8);
			break;
		}
		default: 
			break;
	
	}
}

void drawInputThemCauHoi(short **mapID) {
	
	setbkcolor(MAU_NEN);
   	cleardevice();
   	
   	settextstyle(10,0,5);
	setcolor(COLOR(247,145,31)); //color orange with rbg
	outtextxy(600,10,"Them Cau Hoi");
	
	settextstyle(10,0,3);
	tao_khung(30,60,1030,800);
	
	outtextxy(60,100,"Noi Dung:");
	outtextxy(150,310,"A.");

	outtextxy(150,440,"B.");
	outtextxy(150,570,"C.");
	outtextxy(150,700,"D.");


	//Noi Dung
	taoTextInput(200,70,1020,200, 215, mapID);
	
	//Cau a
	tao_circle(130,320,15, 222, mapID);

	taoTextInput(200,290,1020,390, 216, mapID);
	
	//Cau b
	tao_circle(130,450,15, 223, mapID);

	taoTextInput(200,420,1020,520, 217, mapID);
	
	//Cau c
	tao_circle(130,580,15, 224, mapID);

	taoTextInput(200,550,1020,650, 218, mapID);
	
	//Cau D
	tao_circle(130,710,15, 225, mapID);
	
	taoTextInput(200,680,1020,780, 219, mapID);


	tao_button(200,20 ,320,50 , "Ma MH", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(330,20 , 550,50 , 220, mapID);


	
	
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);
	
	tao_khung(1045,60,1360,500); //khung canh bao

	settextstyle(10,0,2);
	setcolor(MAU_DO_NHAT);
	outtextxy(1120,80,"BANG THONG BAO");
	line(1120,100,1290,100);
	tao_button(1150,530,1270,560,"Them", MAU_DO_NHAT, MAU_TRANG, 221, mapID);

	setcolor(MAU_DEN);

}

void checkMouseQLCauHoi(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree, CauHoiThi arr[]) {
	int page = 0;
	int pageMH = 0;
	int pageThem = 0;
	int pageCauHoi = 0;
	char maMH[17] = "";
	int x = - 1, y = -1;
	int state;
	int stateMH;
	
	int ID;
	char noiDung[127] = "";
	char dapAnA[127] = "";
	char dapAnB[127] = "";
	char dapAnC[127] = "";
	char dapAnD[127] = "";
	char dapAn;
	
	char noiDungSua[127] = "";
	char dapAnASua[127] = "";
	char dapAnBSua[127] = "";
	char dapAnCSua[127] = "";
	char dapAnDSua[127] = "";
	char dapAnSua;
	char maMHSua[17] = "";
	
	
	while (1) {
		delay(0.001); 

		int ID = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			ID = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(x != -1 && y != -1 )
		switch(ID) {
			case 211: { //xem theo mon
				mon_menu:
				setbkcolor(MAU_NEN);
				cleardevice();
				tao_khung(5,60,1035,860); 
				tao_khung(10,65,1030,355);
				tao_khung(10,365,1030,855);//800
				
				tao_khung(1045,60,1360,500); //khung canh bao
				
				settextstyle(10,0,5);
				setcolor(COLOR(247,145,31)); //color orange with rbg
				outtextxy(530,10,"Quan Ly Cau Hoi");
			
				settextstyle(10,0,2);
				setcolor(MAU_DO_NHAT);
				outtextxy(1120,80,"BANG THONG BAO");
				line(1120,100,1290,100);
				drawDSMonHoc(mapID, arrID, dsMonHoc, pageMH);
				tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 43, mapID);
				tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 153, mapID);
				tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 154, mapID);
				drawInputXemTheoMon(mapID);

				x = - 1, y = -1;
				while (1) {
					delay(0.001); 
			
					ID = 0;
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN,x,y);
						ID = mapID[x][y];
						clearmouseclick(WM_LBUTTONDOWN);
					}
					if(x != -1 && y != -1 )
					switch(ID) {
						case 187: {
							stateMH = 0;						
							drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);
							x = - 1, y = -1;
							break;
						}
						case 188: {
							stateMH = 1;	

							drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);
							x = - 1, y = -1;
							break;
						}
						case 189: {
							stateMH = 2;	

							drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);
							x = - 1, y = -1;
							break;
						}
						case 190: {
							stateMH = 3;	

							drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);
							x = - 1, y = -1;
							break;
						}
						case 191: {
							stateMH = 4;	

							drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);
							x = - 1, y = -1;
							break;
						}
						case 192: {
							stateMH = 5;	

							drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);
							x = - 1, y = -1;
							break;
						}
						case 193: {
							stateMH = 6;	

							drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);
							x = - 1, y = -1;
							break;
						}
						case 194: {
							stateMH = 7;	

							drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);
							x = - 1, y = -1;
							break;
						}
						case 195: {
							stateMH = 8;	

							drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);
							x = - 1, y = -1;
							break;
						}
						case 196: {
							stateMH = 9;	

							drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);
							x = - 1, y = -1;
							break;
						}
						case 290: { //prev
							if(pageCauHoi > 0 ) {
								pageCauHoi --;
								drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);

							}
							x = - 1, y = -1;
							break;
						}
						case 291: { //next
							int soLuongCau = lengthCauHoiTheoMH(rootTree, dsMonHoc.mh[stateMH + pageMH*10].maMH);			
							if(pageCauHoi < soLuongCau - 1) {
								pageCauHoi ++;
								drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, dsMonHoc.mh[stateMH + pageMH*10].maMH);
							}
							x = - 1, y = -1;
							break;
						}
						case 44: { //back
							pageMH = 0;
							pageCauHoi = 0;
							xoaChuoi(maMH);


							goto mon_menu;
							break;
						}
						case 179: { //Nhap ma mon hoc
							nhapText(170, 155, 320, 130, maMH, 15, 1);

							break;
						}
						case 180: {// Tim
							setbkcolor(MAU_NEN);
							if(kiemTraChuoiRong(maMH)  == 1) {
								reset_layout(1046,140,1359,499, MAU_NEN); 
								reset_layout(161,151,379,179,MAU_TRANG);
								xoaChuoi(maMH);

								outtextxy(1085,150, "Ma mon hoc khong de");
								outtextxy(1075,170, "trong!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
										
								x = - 1, y = -1;
								break;
							}
							if(!ktTrungMaMonHoc(maMH, dsMonHoc)) {
								reset_layout(1046,140,1359,499, MAU_NEN); 
								reset_layout(161,151,379,179,MAU_TRANG);
								xoaChuoi(maMH);
								outtextxy(1085,150, "Ma mon hoc khong ton");
								outtextxy(1075,170, "tai!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);

	
								x = - 1, y = -1;
								break;
							}
							
							
							drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, maMH);
							x = - 1, y = -1;
							while (1) {
								delay(0.001); 
									
								ID = 0;
								
								if(ismouseclick(WM_LBUTTONDOWN)){
									getmouseclick(WM_LBUTTONDOWN,x,y);
									ID = mapID[x][y];
									clearmouseclick(WM_LBUTTONDOWN);
								}
								if(x != -1 && y != -1 )
								switch(ID) { 
									case 290: { //prev
										if(pageCauHoi > 0 ) {
											pageCauHoi --;
											drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, maMH);
				
										}
										x = - 1, y = -1;
										break;
									}
									case 291: { //next
										int soLuongCau = lengthCauHoiTheoMH(rootTree, maMH);			
										if(pageCauHoi < soLuongCau - 1) {
											pageCauHoi ++;
											drawChiTietCauHoiTheoMon(mapID, rootTree, pageCauHoi, maMH);
										}
										x = - 1, y = -1;
										break;
									}
									case 44: { //back
										pageMH = 0;
										pageCauHoi = 0;
										xoaChuoi(maMH);
		
										goto mon_menu;
										break;
									}
								}
							}
							
							break;
						}
						case 43: { //back lai
							drawQLCauHoi(mapID, arrID, dsMonHoc, dsLop, rootTree);
							xoaChuoi(maMH);
							break;
						}
						case 153: { //Prev
				
							if(pageMH > 0 ) {
								pageMH --;
								drawDSMonHoc(mapID, arrID, dsMonHoc, pageMH);
							}
							x = - 1, y = -1;
							break;
						}
						
						case 154: { //Next
							int maxpage;
							if(dsMonHoc.soLuong <= 10) { // Neu so luong <= 10
								maxpage = 0;
							}
							else if(dsMonHoc.soLuong % 10 == 0){
								maxpage = dsMonHoc.soLuong/10 -1;
							}
							else maxpage = dsMonHoc.soLuong/10;
							
							if(pageMH < maxpage) {
								pageMH ++;
								drawDSMonHoc(mapID, arrID, dsMonHoc, pageMH);
							}
							x = - 1, y = -1;
							break;
						}
						
					}
				}
				break;
			}	
			case 212: { //them cau hoi
				them_cau:
				tao_button(340,320,490,350,"Xem theo mon", MAU_XANH_LA, MAU_DEN, 211, mapID);
				tao_button(500, 320, 560, 350, "Them", MAU_DO_NHAT, MAU_DEN,212, mapID);
				tao_button(570, 320, 630, 350, "Sua", MAU_XANH_LA, MAU_DEN, 213, mapID);
				tao_button(640, 320, 700, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 214, mapID);
				reset_layout(11,66,1029,310,MAU_NEN);
				drawInputThemCauHoi(mapID);
				x = - 1, y = -1;
			
			
				while (1) {
					delay(0.001); 
			
					ID = 0;
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN,x,y);
						ID = mapID[x][y];
						clearmouseclick(WM_LBUTTONDOWN);
					}
					if(x != -1 && y != -1 )
					switch(ID) {
						case 215: { //nhap noi dung
							nhapTextAutoBreak(210, 90 ,noiDung, 125);

							break;
						}
						case 216: { //nhap cau a
							nhapTextAutoBreak(210, 300 ,dapAnA, 125);

							break;
						}
						case 217: { //nhap cau b
							nhapTextAutoBreak(210, 430 ,dapAnB, 125);
							break;
						}
						case 218: { //nhap cau c
							nhapTextAutoBreak(210, 560 ,dapAnC, 125);
							break;
						}
						case 219: {  //nhap cau d
							nhapTextAutoBreak(210, 690 ,dapAnD, 125);
							break;
						}
						case 220: { //ma mon hoc
							nhapText(340, 25, 320, 130, maMH, 15, 1);
							break;
						}

						case 221: { // THem vao
							setbkcolor(MAU_NEN);
							int soLuong = countNode(rootTree);
							
							if(soLuong == 10000) { //full
								reset_layout(1046,140,1359,499, MAU_NEN); 
								outtextxy(1085,150, "Danh sach cau hoi");
								outtextxy(1075,170, "da day!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
								break;
							}
							else {
								
								if(kiemTraChuoiRong(noiDung) == 1 ||  kiemTraChuoiRong(dapAnA) == 1 || kiemTraChuoiRong(dapAnB) == 1 || kiemTraChuoiRong(dapAnC) == 1 || kiemTraChuoiRong(dapAnD) == 1|| kiemTraChuoiRong(maMH) == 1) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Vui long dien day");
									outtextxy(1075,170, "du thong tin!");
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									break;
								}
								if(strcmp(dapAnA, dapAnB) == 0 || strcmp(dapAnB, dapAnC) == 0 || strcmp(dapAnC, dapAnD) == 0 ) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Dap an khong duoc");
									outtextxy(1075,170, "trung nhau!");
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									break;
								}
								if(!ktTrungMaMonHoc(maMH, dsMonHoc)) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Ma mon hoc khong");
									outtextxy(1075,170, "ton tai!");
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									break;
								}
								if(dapAn == NULL) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Vui long chon dap");
									outtextxy(1075,170, "an cho cau hoi!");
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									break;
								}
								
								CauHoiThi cht;
								cht.dapAn = dapAn;
								strcpy(cht.dapAnA, dapAnA);
								strcpy(cht.dapAnB, dapAnB);
								strcpy(cht.dapAnC, dapAnC);
								strcpy(cht.dapAnD, dapAnD);
								strcpy(cht.noiDung, noiDung);
								strcpy(cht.maMH, maMH);
								
								cht.ID = getIDTuFile();

								if(!ktTrungCauHoi(rootTree, cht)) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Cau hoi da ton");
									outtextxy(1075,170, "tai trong danh sach!");
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									break;
								}
								Insert_Tree(rootTree, cht.ID, cht);
								reset_layout(1046,140,1359,499, MAU_NEN);
								 
								outtextxy(1085,150, "Them cau hoi thanh");
								outtextxy(1075,170, "cong!");
								luuFileDSCauHoi(rootTree);
								reset_circle_checked_CH();
								reset_layout(201, 71, 1019, 199, MAU_TRANG);
								reset_layout(201, 291, 1019, 389, MAU_TRANG);
								reset_layout(201, 421, 1019, 519, MAU_TRANG);
								reset_layout(201, 551, 1019, 649, MAU_TRANG);
								reset_layout(201, 681, 1019, 779, MAU_TRANG);
								reset_layout(331, 21, 549, 49, MAU_TRANG);
							
								xoaChuoi(dapAnA);
								xoaChuoi(dapAnB);
								xoaChuoi(dapAnC);
								xoaChuoi(dapAnD);
								xoaChuoi(noiDung);
								xoaChuoi(maMH);
								
								dapAn = NULL;
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
					
							
							}
							break;
						}
						case 222: {//chon dap an a
							dapAn = 'A';
							reset_circle_checked_CH();
							tao_circle_checked(130,320,8);
							break;
						}
						case 223: {//chon dap an b
							dapAn = 'B';
							reset_circle_checked_CH();
							tao_circle_checked(130,450,8);

							break;
						}
						case 224: {//chon dap an c
							dapAn = 'C';
							reset_circle_checked_CH();
							tao_circle_checked(130,580,8);
							break;
						}
						case 225: { //chon dap an d
							dapAn = 'D';
							reset_circle_checked_CH();
							tao_circle_checked(130,710,8);
 							break;
						}
						case 44: { //back
							drawQLCauHoi(mapID, arrID, dsMonHoc, dsLop, rootTree);

							break;
						}
					}
				}
				break;
			}	
			case 213: { //sua
				sua_cau:
				tao_button(340,320,490,350,"Xem theo mon", MAU_XANH_LA, MAU_DEN, 211, mapID);
				tao_button(500, 320, 560, 350, "Them", MAU_XANH_LA, MAU_DEN,212, mapID);
				tao_button(570, 320, 630, 350, "Sua", MAU_DO_NHAT, MAU_DEN, 213, mapID);
				tao_button(640, 320, 700, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 214, mapID);
				x = - 1, y = -1;
				while (1) {
					delay(0.001); 
						
					ID = 0;
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN,x,y);
						ID = mapID[x][y];
						clearmouseclick(WM_LBUTTONDOWN);
					}
					if(x != -1 && y != -1 )
					switch(ID) {
						case 211: { //click xem theo mon
							goto mon_menu;
							x = - 1, y = -1;
							break;
						}
						case 212: { //click them cau hoi
							goto them_cau;
							x = - 1, y = -1;
			
							break; 
						}
						case 214: { //click xoa cau hoi
							goto xoa_cau;
							x = -1, y = -1;
							break;
						}
						case 201: { //xem chi tiet 
							state = 0;


							drawInputSuaCauHoi(mapID, arr, state, page, noiDungSua, dapAnASua, dapAnBSua, dapAnCSua, dapAnDSua, dapAnSua, maMHSua);
							break;
						}
						case 202: {
							state = 1;
							drawInputSuaCauHoi(mapID, arr, state, page, noiDungSua, dapAnASua, dapAnBSua, dapAnCSua, dapAnDSua, dapAnSua, maMHSua);
			
							break;
						}
						case 203: {
							state = 2;
							drawInputSuaCauHoi(mapID, arr, state, page, noiDungSua, dapAnASua, dapAnBSua, dapAnCSua, dapAnDSua, dapAnSua, maMHSua);
							break;
						}
						case 204: {
							state = 3;
							drawInputSuaCauHoi(mapID, arr, state, page, noiDungSua, dapAnASua, dapAnBSua, dapAnCSua, dapAnDSua, dapAnSua, maMHSua);
							break;
						}
						case 205: {
							state = 4;
							drawInputSuaCauHoi(mapID, arr, state, page, noiDungSua, dapAnASua, dapAnBSua, dapAnCSua, dapAnDSua, dapAnSua, maMHSua);
							break;
						}
						case 206: {
							state = 5;
							drawInputSuaCauHoi(mapID, arr, state, page, noiDungSua, dapAnASua, dapAnBSua, dapAnCSua, dapAnDSua, dapAnSua, maMHSua);
							break;
						}
						case 207: {
							state = 6;
							drawInputSuaCauHoi(mapID, arr, state, page, noiDungSua, dapAnASua, dapAnBSua, dapAnCSua, dapAnDSua, dapAnSua, maMHSua);
							break;
						}
						case 208: {
							state = 7;
							drawInputSuaCauHoi(mapID, arr, state, page, noiDungSua, dapAnASua, dapAnBSua, dapAnCSua, dapAnDSua, dapAnSua, maMHSua);
							break;
						}
						case 209: {
							state = 8;
							drawInputSuaCauHoi(mapID, arr, state, page, noiDungSua, dapAnASua, dapAnBSua, dapAnCSua, dapAnDSua, dapAnSua, maMHSua);
							break;
						}
						case 210: {
							state = 9;
							drawInputSuaCauHoi(mapID, arr, state, page, noiDungSua, dapAnASua, dapAnBSua, dapAnCSua, dapAnDSua, dapAnSua, maMHSua);
							break;
						}
						case 215: { //nhap noi dung
							nhapTextAutoBreak(210, 90 ,noiDungSua, 125);

							break;
						}
						case 216: { //nhap cau a
							nhapTextAutoBreak(210, 300 ,dapAnASua, 125);

							break;
						}
						case 217: { //nhap cau b
							nhapTextAutoBreak(210, 430 ,dapAnBSua, 125);
							break;
						}
						case 218: { //nhap cau c
							nhapTextAutoBreak(210, 560 ,dapAnCSua, 125);
							break;
						}
						case 219: {  //nhap cau d
							nhapTextAutoBreak(210, 690 ,dapAnDSua, 125);
							break;
						}
						case 220: { //ma mon hoc
							nhapText(340, 25, 320, 130,maMHSua, 15, 1);
							break;
						}
						case 221: { //Dong y sua
							//tim kiem
							PTRCauHoi p = searchCauHoi(rootTree, arr[state + page*10].ID);
							setbkcolor(MAU_NEN);
							setcolor(MAU_DEN);
							if(checkCHDaThi(dsLop, p->ID)) {
								reset_layout(1046,140,1359,499, MAU_NEN); 
								outtextxy(1085,150, "Cau hoi da thi khong");
								outtextxy(1075,170, "the sua!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
								break;
							}
							else {

								if(kiemTraChuoiRong(noiDungSua) == 1 || kiemTraChuoiRong(dapAnASua) == 1 || kiemTraChuoiRong(dapAnBSua) == 1 || 
								kiemTraChuoiRong(dapAnCSua) == 1 || kiemTraChuoiRong(dapAnDSua) == 1|| kiemTraChuoiRong(maMHSua) == 1) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Vui long dien day");
									outtextxy(1075,170, "du thong tin!");
									break;
								}
								if(strcmp(dapAnASua, dapAnBSua) == 0 || strcmp(dapAnBSua, dapAnCSua) == 0 || strcmp(dapAnCSua, dapAnDSua) == 0 ) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Dap an khong duoc");
									outtextxy(1075,170, "trung nhau!");
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									break;
								}
								if(!ktTrungMaMonHoc(maMHSua, dsMonHoc)) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Ma mon hoc khong");
									outtextxy(1075,170, "ton tai!");
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									break;
								}
								if(dapAnSua == NULL) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Vui long chon dap");
									outtextxy(1075,170, "an cho cau hoi!");
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									break;
								}
								CauHoiThi temp;
								temp.dapAn = dapAnSua;
								strcpy(temp.dapAnA, dapAnASua);
								strcpy(temp.dapAnB, dapAnBSua);
								strcpy(temp.dapAnC, dapAnCSua);
								strcpy(temp.dapAnD, dapAnDSua);
								strcpy(temp.noiDung, noiDungSua);
								strcpy(temp.maMH, maMHSua);
								
								// Kiem tra cau hoi co bi trung hay khong, neu da thay doi du lieu 
								if(!ktTrungCauHoi(rootTree, temp) && (strcmp(dapAnASua, p->cht.dapAnA) != 0 || strcmp(dapAnASua, p->cht.dapAnA) != 0 || strcmp(dapAnBSua, p->cht.dapAnB) != 0 || 
								strcmp(dapAnCSua, p->cht.dapAnC) != 0 || strcmp(dapAnDSua, p->cht.dapAnD) != 0 || strcmp(noiDung, p->cht.noiDung) != 0 || strcmp(maMHSua, p->cht.maMH) != 0 || dapAnSua == p->cht.dapAn)) {
									reset_layout(1046,140,1359,499, MAU_NEN); 
									outtextxy(1085,150, "Cau hoi da ton");
									outtextxy(1075,170, "tai trong danh sach!");
									delay(1000);
									reset_layout(1046,140,1359,499, MAU_NEN);
									break;
								}

								p->cht.dapAn = dapAnSua;
								strcpy(p->cht.dapAnA, dapAnASua);
								strcpy(p->cht.dapAnB, dapAnBSua);
								strcpy(p->cht.dapAnC, dapAnCSua);
								strcpy(p->cht.dapAnD, dapAnDSua);
								strcpy(p->cht.noiDung, noiDungSua);
								strcpy(p->cht.maMH, maMHSua);
								
								
								luuFileDSCauHoi(rootTree);
								reset_layout(1046,140,1359,499, MAU_NEN); 
								outtextxy(1085,150, "Sua cau hoi thanh");
								outtextxy(1075,170, "cong!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);	
								drawQLCauHoi(mapID, arrID, dsMonHoc, dsLop, rootTree);
														
										

								
							}
							break;
						}
						case 222: {//chon dap an a
							dapAnSua = 'A';
							reset_circle_checked_CH();
							tao_circle_checked(130,320,8);
							break;
						}
						case 223: {//chon dap an b
							dapAnSua = 'B';
							reset_circle_checked_CH();
							tao_circle_checked(130,450,8);

							break;
						}
						case 224: {//chon dap an c
							dapAnSua = 'C';
							reset_circle_checked_CH();
							tao_circle_checked(130,580,8);
							break;
						}
						case 225: { //chon dap an d
							dapAnSua = 'D';
							reset_circle_checked_CH();
							tao_circle_checked(130,710,8);
 							break;
						}
						case 44: { //back tro lai 
							drawQLCauHoi(mapID, arrID, dsMonHoc, dsLop, rootTree);
							break;
						}
						
					} 
				}
				break;
			}
			case 214: { //xoa
				xoa_cau:
				tao_button(340,320,490,350,"Xem theo mon", MAU_XANH_LA, MAU_DEN, 211, mapID);
				tao_button(500, 320, 560, 350, "Them", MAU_XANH_LA, MAU_DEN,212, mapID);
				tao_button(570, 320, 630, 350, "Sua", MAU_XANH_LA, MAU_DEN, 213, mapID);
				tao_button(640, 320, 700, 350, "Xoa", MAU_DO_NHAT, MAU_DEN, 214, mapID);
				xoa_menu:
				x = - 1, y = -1;
				while (1) {
					delay(0.001); 
						
					ID = 0;
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN,x,y);
						ID = mapID[x][y];
						clearmouseclick(WM_LBUTTONDOWN);
					}
					if(x != -1 && y != -1 )
					switch(ID) {
						case 211: { //click xem theo mon
							goto mon_menu;
							x = - 1, y = -1;
							break;
						}
						case 212: { //click them cau hoi
							goto them_cau;
							x = - 1, y = -1;
			
							break; 
						}
						case 213: { //click xoa cau hoi
							goto sua_cau;
							x = -1, y = -1;
							break;
						}
						case 201: { //xem chi tiet 
							state = 0;

							drawInputXoaCH(mapID, arr, state, page);
							break;
						}
						case 202: {
							state = 1;
							drawInputXoaCH(mapID, arr, state, page);
			
							break;
						}
						case 203: {
							state = 2;
							drawInputXoaCH(mapID, arr, state, page);
							break;
						}
						case 204: {
							state = 3;
							drawInputXoaCH(mapID, arr, state, page);
							break;
						}
						case 205: {
							state = 4;
							drawInputXoaCH(mapID, arr, state, page);
							break;
						}
						case 206: {
							state = 5;
							drawInputXoaCH(mapID, arr, state, page);
							break;
						}
						case 207: {
							state = 6;
							drawInputXoaCH(mapID, arr, state, page);
							break;
						}
						case 208: {
							state = 7;
							drawInputXoaCH(mapID, arr, state, page);
							break;
						}
						case 209: {
							state = 8;
							drawInputXoaCH(mapID, arr, state, page);
							break;
						}
						case 210: {
							state = 9;
							drawInputXoaCH(mapID, arr, state, page);
							break;
						}
						case 215: { //xoa
							PTRCauHoi p = searchCauHoi(rootTree, arr[state + page*10].ID);
							setbkcolor(MAU_NEN);
							setcolor(MAU_DEN);
							if(checkCHDaThi(dsLop, p->ID)) {
								reset_layout(1046,140,1359,499, MAU_NEN); 
								outtextxy(1085,150, "Cau hoi da thi khong");
								outtextxy(1075,170,  "the xoa!");
								delay(1000);
								reset_layout(1046,140,1359,499, MAU_NEN);
								break;
							}
							else {
								canhBaoXoa(mapID);
								x = - 1, y = -1;
	
								while (1) {
									delay(0.001); 
									ID = 0;
									if(ismouseclick(WM_LBUTTONDOWN)){
										getmouseclick(WM_LBUTTONDOWN,x,y);
										ID = mapID[x][y];
										clearmouseclick(WM_LBUTTONDOWN);
									}
																	
									if(x != -1 && y != -1)
									switch(ID) { 
										case 177: { //dong y xoa
											removeCauHoi(p->ID, rootTree);
											
											luuFileDSCauHoi(rootTree);		
											reset_layout(1046,140,1359,499, MAU_NEN); 
											outtextxy(1085,150, "Xoa cau hoi thanh");
											outtextxy(1075,170, "cong!");
											delay(1000);
											reset_layout(1046,140,1359,499, MAU_NEN);							
											drawQLCauHoi(mapID, arrID, dsMonHoc, dsLop, rootTree);
											
										}
										case 178: { //khong dong y xoa
											goto xoa_menu;
											x=-1;y=-1;
											break;
										}
										default :
											break;
									} 
								}
							}
							
							break;
						}
						
						case 44: { //back tro lai tu xem chi tiet 1 cau
							drawQLCauHoi(mapID, arrID, dsMonHoc, dsLop, rootTree);
			
							break;
						}
					}
				}
				break;
			}
			case 201: { //xem chi tiet 
				state = 0;
				drawChiTietCauHoi(mapID, arr, state, page);
				break;
			}
			case 202: {
				state = 1;
				drawChiTietCauHoi(mapID, arr, state, page);

				break;
			}
			case 203: {
				state = 2;
				drawChiTietCauHoi(mapID, arr, state, page);
				break;
			}
			case 204: {
				state = 3;
				drawChiTietCauHoi(mapID, arr, state, page);
				break;
			}
			case 205: {
				state = 4;
				drawChiTietCauHoi(mapID, arr, state, page);
				break;
			}
			case 206: {
				state = 5;
				drawChiTietCauHoi(mapID, arr, state, page);
				break;
			}
			case 207: {
				state = 6;
				drawChiTietCauHoi(mapID, arr, state, page);
				break;
			}
			case 208: {
				state = 7;
				drawChiTietCauHoi(mapID, arr, state, page);
				break;
			}
			case 209: {
				state = 8;
				drawChiTietCauHoi(mapID, arr, state, page);
				break;
			}
			case 210: {
				state = 9;
				drawChiTietCauHoi(mapID, arr, state, page);
				break;
			}
			case 44: { //back tro lai tu xem chi tiet 1 cau
				drawQLCauHoi(mapID, arrID, dsMonHoc, dsLop, rootTree);

				break;
			}
			case 43: { //back
				drawMainMenu(mapID, dsMonHoc, dsLop, rootTree, arrID);
				break;
			}
			case 153: { //Prev
				int soLuong = countNode(rootTree);
				
				if(page > 0 ) {
					page --;
					drawDSCauHoi(mapID, arrID, rootTree, page, arr, soLuong);
				}
				x = - 1, y = -1;
				break;
			}
			
			case 154: { //Next
				int maxpage;
				int soLuong = countNode(rootTree);

				if(soLuong <= 10) { // Neu so luong <= 10
					maxpage = 0;
				}
				else if(soLuong % 10 == 0){
					maxpage = soLuong/10 -1;
				}
				else maxpage = soLuong/10;
				
				if(page < maxpage) {
					page ++;
					drawDSCauHoi(mapID, arrID, rootTree, page, arr, soLuong);
				}
				x = - 1, y = -1;
				break;
			}
			default:
				break;			
		}
		
	}
}

void drawQLCauHoi(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree) {
	resetID(arrID);
	setbkcolor(MAU_NEN);

   	cleardevice();
	settextstyle(10,0,2);
	
	tao_khung(5,60,1035,860); 
	tao_khung(10,65,1030,355);
	tao_khung(10,365,1030,855);//800
	
	tao_khung(1045,60,1360,500); //khung canh bao
	
	settextstyle(10,0,5);
	setcolor(COLOR(247,145,31)); //color orange with rbg
	outtextxy(530,10,"Quan Ly Cau Hoi");

	settextstyle(10,0,2);
	setcolor(MAU_DO_NHAT);
	outtextxy(1120,80,"BANG THONG BAO");
	line(1120,100,1290,100);
	setcolor(MAU_DEN);
	

	
	
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 43, mapID);
	
	tao_button(340,320,490,350,"Xem theo mon", MAU_XANH_LA, MAU_DEN, 211, mapID);
	tao_button(500, 320, 560, 350, "Them", MAU_XANH_LA, MAU_DEN,212, mapID);
	tao_button(570, 320, 630, 350, "Sua", MAU_XANH_LA, MAU_DEN, 213, mapID);
	tao_button(640, 320, 700, 350, "Xoa", MAU_XANH_LA, MAU_DEN, 214, mapID);
	
	tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 153, mapID);
	tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 154, mapID);
	
	
	int soLuong = countNode(rootTree);
	CauHoiThi arr[soLuong]; //tao array luu cau hoi thi
	addCHToArray(rootTree, arr);

	
	drawDSCauHoi(mapID, arrID, rootTree, 0, arr, soLuong);
	
	checkMouseQLCauHoi(mapID, arrID, dsMonHoc, dsLop, rootTree, arr);
}


void selectLopXemDiem(short **mapID,  int arrID[], DanhSachLop dsLop, DanhSachMonHoc dsMonHoc, int vitri, int page) {
	if(dsLop.lh[vitri + page*10]->dsSinhVien == NULL) {
		reset_layout(1046,140,1359,499, MAU_NEN);

		outtextxy(1080,150, "Lop khong co sinh vien");
		outtextxy(1075,170, "khong the xem diem!");
		delay(1000);
		reset_layout(1046,140,1359,499, MAU_NEN);

	}
	else {
		tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);
		tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 197, mapID);
		tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 198, mapID);
					
		drawDSMonHoc(mapID, arrID, dsMonHoc, 0);	
	}
	
}

void drawChiTietBaiThiSV(short **mapID, int arrID[], CauHoiThi arr[], int page, char maMH[], PTRDiemThi p) {
	settextstyle(10,0,3);
	setbkcolor(MAU_NEN);
   	cleardevice();
	khoi_tao_mapID(mapID);	
	tao_khung(150,200,1250,770);


	
	
	outtextxy(160,220,"Noi Dung:");
	line(160,243,283,243);
	if(strlen(arr[page].noiDung) > 55) { //auto break line, neu length noi dung hon 60 thi xuong dong`
			char res1[126];
    		char res2[126];
    		char str_temp[126];  //su dung str_temp de khong phai thay doi du lieu cua arrayCauHoiRandom khi chuyen trang
    		strcpy(str_temp,arr[page].noiDung);
    		catChuoi2Dong(str_temp,res1,res2);

			outtextxy(290,220,res1);
			outtextxy(190,245,res2);
	}
	else {
		outtextxy(290,220,arr[page].noiDung);
	}
	
	
	
	 //in cau hoi
	tao_circle(200,350,15, -2, mapID);
	outtextxy(220,340,"A.");
	if(strlen(arr[page].dapAnA) > 60) {
		char resA1[126];
		char resA2[126];
		char str_tempA[126]; 
		strcpy(str_tempA,arr[page].dapAnA);
    	catChuoi2Dong(str_tempA,resA1,resA2);
    	
		outtextxy(250,340,resA1);
		outtextxy(230,365,resA2);
	} 
	else {
		outtextxy(250,340,arr[page].dapAnA);
	}

	
	tao_circle(200,450,15, -2, mapID);
	outtextxy(220,440,"B.");

	if(strlen(arr[page].dapAnB) > 60) {
		char resB1[126];
		char resB2[126];
		char str_tempB[126]; 
		strcpy(str_tempB,arr[page].dapAnB);
    	catChuoi2Dong(str_tempB,resB1,resB2);
    	
		outtextxy(250,440,resB1);
		outtextxy(230,465,resB2);
	} 
	else {
		outtextxy(250,440,arr[page].dapAnB);
	}


	tao_circle(200,550,15, -2, mapID);
	outtextxy(220,540,"C.");

	if(strlen(arr[page].dapAnC) > 60) {
		char resC1[126];
		char resC2[126];
		char str_tempC[126]; 
		strcpy(str_tempC,arr[page].dapAnC);
    	catChuoi2Dong(str_tempC,resC1,resC2);
    	
		outtextxy(250,540,resC1);
		outtextxy(230,565,resC2);
	} 
	else {
		outtextxy(250,540,arr[page].dapAnC);
	}
	
	
	tao_circle(200,650,15, -2, mapID);
	outtextxy(220,640,"D.");
	
	if(strlen(arr[page].dapAnD) > 60) {
		char resD1[126];
		char resD2[126];
		char str_tempD[126]; 
		strcpy(str_tempD,arr[page].dapAnD);
    	catChuoi2Dong(str_tempD, resD1, resD2);
    	
		outtextxy(250,640,resD1);
		outtextxy(230,665,resD2);
	} 
	else {
		outtextxy(250,640,arr[page].dapAnD);
	}
	
	tao_circle(860, 80, 15, -2, mapID);
	tao_circle_checked(860,80,8);
	outtextxy(900,70, "Dap an cua cau hoi");

	
	tao_circle(860, 130, 15, -2, mapID);
	setfillstyle(1,MAU_XANH_LA);
	fillellipse(860,130,8,8);
	outtextxy(900,120, "Dap an cua ban tra loi");
	
	tao_circle(860, 180, 15, -2, mapID);
	setfillstyle(1,MAU_XANH_DUONG);
	fillellipse(860,180,8,8);
	outtextxy(900,170, "Dap an cua ban dung");
	
	tao_button(200,100 ,320,130 , "Ma MH", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(330,100 , 550,130 , -2, mapID);
	
	tao_button(600,100 ,660,130 , "ID", MAU_HONG, MAU_DEN, -2, mapID);
	taoTextInput(670,100 , 770, 130 , -2, mapID);
	

	
	outtextxy(340,105, maMH);
	char tempID[10];
	itoa(arr[page].ID, tempID, 10);
	outtextxy(680,105, tempID);

	if(arr[page].dapAn == p->dt.bt.dapAnDaChon[page]) {

		switch(arr[page].dapAn){

			case 'A': {
				setfillstyle(1,MAU_XANH_DUONG);

				fillellipse(200,350,8,8);
				break;
			}
			case 'B': {
				setfillstyle(1,MAU_XANH_DUONG);

				fillellipse(200,450,8,8);
				break;
			}
			case 'C': {
				setfillstyle(1,MAU_XANH_DUONG);
				fillellipse(200,550,8,8);
				break;
			}
			case 'D': {
				setfillstyle(1,MAU_XANH_DUONG);
				fillellipse(200,650,8, 8);
				break;
			}
			default: 
				break;
		
		}
	}
	else {
		switch(p->dt.bt.dapAnDaChon[page]){
			
	
			case 'A': {
				setfillstyle(1,MAU_XANH_LA);
				fillellipse(200,350,8,8);
				break;
			}
			case 'B': {
				setfillstyle(1,MAU_XANH_LA);
				fillellipse(200,450,8, 8);
				break;
			}
			case 'C': {
				setfillstyle(1,MAU_XANH_LA);
				fillellipse(200,550,8, 8);
				break;
			}
			case 'D': {
				setfillstyle(1,MAU_XANH_LA);
				fillellipse(200,650,8, 8);
				break;
			}
			default: 
				break;
		
		}
		
		switch(arr[page].dapAn){
			case 'A': {
				tao_circle_checked(200,350,8);
				break;
			}
			case 'B': {
				tao_circle_checked(200,450,8);
				break;
			}
			case 'C': {
				tao_circle_checked(200,550,8);
				break;
			}
			case 'D': {
				tao_circle_checked(200,650,8);
				break;
			}
			default: 
				break;
		
		}
	}
	
	
	int soLuong  = p->dt.bt.soCauHoi;
	int maxpage = soLuong;
	
	
	
	char page_str[10] = "";  
	char maxpage_str[10] = "";
	char res[20] = "";

	itoa(maxpage, maxpage_str, 10);
	itoa(page+1, page_str, 10);
	strcat(res,"Trang ");
	
	strcat(res,page_str);
	strcat(res,"/");
	strcat(res,maxpage_str);

	reset_layout(460,790,700,820,MAU_NEN);
	setbkcolor(MAU_NEN);
	outtextxy(670,810, res);
	
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 46, mapID);

	tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 241, mapID);
	tao_button(1260,800,1320,830,"Next", MAU_XANH_LA, MAU_DEN, 242, mapID);
	
}

void drawDSBaiThiSV(short **mapID, int arrID[], MonHoc mh, LopHoc *lh,  int vitri, int pageSV, int pageCH) {
	resetID(arrID);
	setbkcolor(MAU_NEN);
	
	bool flagCheckThi = false; // flag kiem tra thi cua sinh vien

	PTRSinhVien ptrSV;  
	ptrSV = new NodeSinhVien;
	
	ptrSV = lh->dsSinhVien;
		
	for (int i=0; i < vitri + pageSV*10; i++) {  //Duyet tim vi tri sinh vien select
		if (ptrSV->next != NULL)	{

			ptrSV = ptrSV->next;
		}
	}	
	
	PTRDiemThi ptrDT;
   	ptrDT = new NodeDiemThi;
	ptrDT = ptrSV->sv.dsDiemThi;
	
	if(ptrDT == NULL) { //chua thi
		reset_layout(1046,140,1359,499, MAU_NEN);

		outtextxy(1080,150, "Sinh vien chua thi,");
		outtextxy(1075,170, "khong the xem bai thi!");
		delay(1000);
		reset_layout(1046,140,1359,499, MAU_NEN);
	}
	else {  //co thi
		
		while(ptrDT != NULL) { //duyet ds tim ptr diem 
			if(strcmp(ptrDT->dt.maMH, mh.maMH) == 0) { //neu co thi mon	

								
				drawChiTietBaiThiSV(mapID, arrID, ptrDT->dt.bt.cht, pageCH, ptrDT->dt.maMH, ptrDT);
				flagCheckThi = true;
			}
			ptrDT = ptrDT->next;
		}
		
		if(!flagCheckThi) { //sau khi duyet neu van khong trung ma mon hoc thi sinh vien van chua thi mon nay`
			reset_layout(1046,140,1359,499, MAU_NEN);
	
			outtextxy(1080,150, "Sinh vien chua thi,");
			outtextxy(1075,170, "khong the xem bai thi!");
			delay(1000);
			reset_layout(1046,140,1359,499, MAU_NEN);
		}	
		
				
	}
	
}

void drawDSDiemThi(short **mapID, int arrID[], MonHoc mh, LopHoc *lh, PTRCauHoi rootTree, int page) {
	reset_layout(11, 366, 1029, 790, MAU_NEN);
	resetID(arrID);
	setbkcolor(MAU_NEN);
	int arrDoDaiTable[] = { 100, 300, 450, 150}; 
	char title[][50] = { "STT","Ma SV","Ho Va Ten" , "Diem Thi"};
	
	bool flagCheckThi = false; // flag kiem tra thi cua sinh vien
	
	tao_bang(20, 375, 35, 4, 11, arrDoDaiTable, title, arrID, mapID, page);
	
	settextstyle(10,0,2);
	
	int soLuong = demSLSinhVien(lh->dsSinhVien);
	
	PTRSinhVien ptrSV;  
	ptrSV = new NodeSinhVien;
	
	if (page == 0)
	{
		ptrSV = lh->dsSinhVien;  //q = first
	}
	else
	{	//Neu page > 0  thi se lay tu phan tu page *10
		ptrSV = lh->dsSinhVien;
		
		for (int i=0; i<page*10; i++)
		{
			if (ptrSV->next != NULL)
			{
				ptrSV = ptrSV->next;
			}
		}	
	}
	
	
	PTRDiemThi ptrDT;
   	ptrDT = new NodeDiemThi;
	
	for(int i = 0; i< 10;i++) {
		if(ptrSV == NULL) {	
			break;
		}
		else {
			ptrDT = ptrSV->sv.dsDiemThi;

			if(ptrDT == NULL) { //chua thi mon nao` ca
				outtextxy(880, 420 + 35*i, "Chua Thi");
			}
			else {  //co thi mot mon nao` do'
			
				while(ptrDT != NULL) { //duyet ds tim ptr diem
					if(strcmp(ptrDT->dt.maMH, mh.maMH) == 0) { 
						char diemThiStr[10] = "";
						ftoa(ptrDT->dt.diem, diemThiStr, 2);
						outtextxy(880, 420 + 35*i, diemThiStr);
						flagCheckThi = true;
					}
					ptrDT = ptrDT->next;
				}
				if(!flagCheckThi) { //sau khi duyet neu van khong trung ma mon hoc thi sinh vien van chua thi mon nay`
					outtextxy(880, 420 + 35*i, "Chua Thi");
				}
				
			}
			
			setID(20,410+35*i,1020,445 + 35*i,++arrID[10], mapID);
			outtextxy(130,420 + 35*i, ptrSV->sv.maSV);
			char temp[70] ="";  //Noi chuoi Ho va ten
			strcat(temp, ptrSV->sv.ho);
			strcat(temp, " ");
			strcat(temp, ptrSV->sv.ten);
			outtextxy(430,420 + 35*i, temp);
			outtextxy(430,420 + 35*i, temp);
			ptrSV = ptrSV->next;

		}
	
	}

	int maxpage;
	if(soLuong <= 10) { // Neu so luong <= 10
		maxpage = 0;
	}
	else if(soLuong % 10 == 0){
		maxpage = soLuong/10 -1;
	}
	else maxpage = soLuong/10;
	
	
	char page_str[10] = "";  
	char maxpage_str[10] = "";
	char res[20] = "";

	itoa(maxpage+1, maxpage_str, 10);
	itoa(page+1, page_str, 10);
	strcat(res,"Trang ");
	
	strcat(res,page_str);
	strcat(res,"/");
	strcat(res,maxpage_str);

	reset_layout(460,790,700,820,MAU_NEN);
	setbkcolor(MAU_NEN);
	outtextxy(490,810, res);
	
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 45, mapID);
	
	
	tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 199, mapID);
	tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 200, mapID);
}

void checkMouseQLDiemThi(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree) {
	int stateLop;
	int stateMonHoc;
	int stateDiemThi;
	
	int pageLop = 0;
	int pageMonHoc = 0;
	int pageDiem = 0;
	int pageCH = 0;
	
	
	int x = - 1, y = -1;
	setbkcolor(MAU_NEN);
	while (1) {
		delay(0.001); 

		int ID = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			ID = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(x != -1 && y != -1 )
		switch(ID) {
			/* Select lop */
			case 102: {
				stateLop = 0;	
				selectLopXemDiem(mapID, arrID, dsLop, dsMonHoc, stateLop, pageLop);
				x = - 1, y = -1;
				break;
			}
			case 103: {
				stateLop = 1;
				selectLopXemDiem(mapID, arrID, dsLop, dsMonHoc, stateLop, pageLop);

				x = - 1, y = -1;
				break;
			}
			case 104: {
				stateLop = 2;
				selectLopXemDiem(mapID, arrID, dsLop, dsMonHoc, stateLop, pageLop);

				x = - 1, y = -1;
				break;
			}
			case 105: {
							
				stateLop = 3;
				selectLopXemDiem(mapID, arrID, dsLop, dsMonHoc, stateLop, pageLop);
				x = - 1, y = -1;

				break;
			}
			case 106: {
				stateLop = 4;
				selectLopXemDiem(mapID, arrID, dsLop, dsMonHoc, stateLop, pageLop);
				x = - 1, y = -1;

				break;
			}
			case 107: {
				stateLop = 5;
				selectLopXemDiem(mapID, arrID, dsLop, dsMonHoc, stateLop, pageLop);
				x = - 1, y = -1;
				break;
			}
			case 108: {
				stateLop = 6;
				selectLopXemDiem(mapID, arrID, dsLop, dsMonHoc, stateLop, pageLop);
				x = - 1, y = -1;
				break;
			}
			case 109: {
				stateLop = 7;
				selectLopXemDiem(mapID, arrID, dsLop, dsMonHoc, stateLop, pageLop);
				x = - 1, y = -1;

				break;
			}
			case 110: {
				stateLop = 8;
				selectLopXemDiem(mapID, arrID, dsLop, dsMonHoc, stateLop, pageLop);
				x = - 1, y = -1;

				break;
			}
			case 111: {
				stateLop = 9;
				selectLopXemDiem(mapID, arrID, dsLop, dsMonHoc, stateLop, pageLop);
				x = - 1, y = -1;

				break;
			}
			/* End Select lop */
			
			/* Select Mon Hoc*/
			case 187: {
				stateMonHoc = 0;
				drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, 0);
				x = - 1, y = -1;

				break;
			}
			case 188: {
				stateMonHoc = 1;
				drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, 0);

				x = - 1, y = -1;

				break;
			}
			case 189: {
				stateMonHoc = 2;
				drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, 0);
				x = - 1, y = -1;

				break;
			}
			case 190: {
				stateMonHoc = 3;
				drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, 0);
				x = - 1, y = -1;

				break;
			}
			case 191: {
				stateMonHoc = 4;
				drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, 0);
				x = - 1, y = -1;

				break;
			}
			case 192: {
				stateMonHoc = 5;
				drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, 0);
				x = - 1, y = -1;
						
				break;
			}
			case 193: {
				stateMonHoc = 6;
				drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, 0);
				x = - 1, y = -1;
						
				break;
			}
			case 194: {
				stateMonHoc = 7;
				drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, 0);
				x = - 1, y = -1;
						
				break;
			}
			case 195: {
				stateMonHoc = 8;
				drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, 0);
				x = - 1, y = -1;

				break;
			}
			case 196: {
				stateMonHoc = 9;
				drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, 0);
				x = - 1, y = -1;

				break;
			}
			
			/* End select Mon Hoc*/
			
			/* Select diem thi */
			case 231: {
				stateDiemThi = 0;
				pageCH = 0;
				drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, 0 );
				x = - 1, y = -1;
				break;
			}
			case 232: {
				stateDiemThi = 1;
				pageCH = 0;
				drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, 0 );

				x = - 1, y = -1;
				break;
			}
			case 233: {
				stateDiemThi = 2;
				pageCH = 0;
				drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, 0 );
				x = - 1, y = -1;
				break;
			}
			case 234: {
				stateDiemThi = 3;
				pageCH = 0;
				drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, 0 );
				x = - 1, y = -1;
				break;
			}
			case 235: {
				stateDiemThi = 4;
				pageCH = 0;
				drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, 0 );
				x = - 1, y = -1;
				break;
			}
			case 236: {
				stateDiemThi = 5;
				pageCH = 0;
				drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, 0 );
				x = - 1, y = -1;
				break;
			}
			case 237: {
				stateDiemThi = 6;
				pageCH = 0;
				drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, 0 );
				x = - 1, y = -1;
				break;
			}
			case 238: {
				stateDiemThi = 7;
				pageCH = 0;
				drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, 0 );
				x = - 1, y = -1;
				break;
			}
			case 239: {
				stateDiemThi = 8;
				pageCH = 0;
				drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, 0 );
				x = - 1, y = -1;
				break;
			}
			case 240: {
				stateDiemThi = 9;
				pageCH = 0;
				drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, 0 );
				x = - 1, y = -1;
				break;
			}
			case 46: { //back tro lai chon bai thi
				setbkcolor(MAU_NEN);
			
			   	cleardevice();
				settextstyle(10,0,2);
				
				tao_khung(5,60,1035,860); 
				tao_khung(10,65,1030,355);
				tao_khung(10,365,1030,855);//800
				
				tao_khung(1045,60,1360,500); //khung canh bao
				
				settextstyle(10,0,5);
				setcolor(COLOR(247,145,31)); //color orange with rbg
				outtextxy(530,10,"Quan Ly Diem Thi");
			
				settextstyle(10,0,2);
				setcolor(MAU_DO_NHAT);
				outtextxy(1120,80,"BANG THONG BAO");
				line(1120,100,1290,100);
				setcolor(MAU_DEN);
				drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, pageDiem);

				break;
			}
			case 45: { //back tro lai chon mon
				tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 44, mapID);
				tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 197, mapID);
				tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 198, mapID);
							
				drawDSMonHoc(mapID, arrID, dsMonHoc, pageMonHoc);
				break;
			}
			case 44: { //back tro lai chon lop
				drawQLDiemThi(mapID, arrID, dsMonHoc, dsLop, rootTree);
				break;
			}
			case 43: { //back
				drawMainMenu(mapID, dsMonHoc, dsLop, rootTree, arrID);
				break;
			}
			case 241: { //prev page chi tiet bai thi
				if(pageCH > 0 ) {
					pageCH --;
					drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, pageCH );
				}
				x = - 1, y = -1;
				break;
			
			}
			case 242: { //next page chi tiet bai thi
				PTRSinhVien ptrSV;  
				ptrSV = new NodeSinhVien;
				

				ptrSV = dsLop.lh[stateLop + pageLop*10]->dsSinhVien;
					
				for (int i=0; i < stateDiemThi + pageDiem*10; i++)  //Duyet tim vi tri sinh vien select
				{
					if (ptrSV->next != NULL)
					{
						ptrSV = ptrSV->next;
					}
				}	
			
			
				PTRDiemThi ptrDT;
			   	ptrDT = new NodeDiemThi;
				ptrDT = ptrSV->sv.dsDiemThi;
				
				while(strcmp(ptrDT->dt.maMH, dsMonHoc.mh[stateMonHoc + pageMonHoc*10].maMH) != 0) { //duyet ds tim ptr diem 
					ptrDT = ptrDT->next;
				}
				int soLuong = ptrDT->dt.bt.soCauHoi;

				if(pageCH < soLuong - 1) {
					pageCH ++;
					drawDSBaiThiSV(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], stateDiemThi, pageDiem, pageCH );
				}
				x = - 1, y = -1;
				
				break;
			}
			case 197: { //Prev page mon hoc
				
				if(pageMonHoc > 0 ) {
					pageMonHoc --;
					drawDSMonHoc(mapID, arrID, dsMonHoc, pageMonHoc);
				}
				x = - 1, y = -1;
				break;
			}
			
			case 198: { //Next page mon hoc
				int maxpage;
				if(dsMonHoc.soLuong <= 10) { // Neu so luong <= 10
					maxpage = 0;
				}
				else if(dsMonHoc.soLuong % 10 == 0){
					maxpage = dsMonHoc.soLuong/10 -1;
				}
				else maxpage = dsMonHoc.soLuong/10;
							
				if(pageMonHoc < maxpage) {
					pageMonHoc ++;
					drawDSMonHoc(mapID, arrID, dsMonHoc, pageMonHoc);
				}
				x = - 1, y = -1;
				break;
					
			}
			case 199 : {  //Prev page diem
				if(pageDiem > 0 ) {
					pageDiem --;
					drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, pageDiem);
				}
				break;
			}
			case 200 : {  //Next page diem
				int maxpage;
				int soLuong = demSLSinhVien(dsLop.lh[stateLop + pageLop*10]->dsSinhVien);
				if(soLuong <= 10) { // Neu so luong <= 10
					maxpage = 0;
				}
				else if(soLuong % 10 == 0){
					maxpage = soLuong/10 -1;
				}
				else maxpage = soLuong/10;
							
				if(pageDiem < maxpage) {
					pageDiem ++;
					drawDSDiemThi(mapID, arrID, dsMonHoc.mh[stateMonHoc + pageMonHoc*10], dsLop.lh[stateLop + pageLop*10], rootTree, pageDiem);
				}
				break;
			}
			case 153: { //Prev page lop
				
				if(pageLop > 0 ) {
					pageLop --;
					inDSLop(mapID, dsLop, arrID, pageLop);	
				}
				x = - 1, y = -1;
				break;
			}
			
			case 154: { //Next page lop
				int maxpage;
				if(dsLop.soLuong <= 10) { // Neu so luong <= 10
					maxpage = 0;
				}
				else if(dsLop.soLuong % 10 == 0){
					maxpage = dsLop.soLuong/10 -1;
				}
				else maxpage = dsLop.soLuong/10;
				
				if(pageLop < maxpage) {
					pageLop ++;
					inDSLop(mapID, dsLop, arrID, pageLop);	
				}
				x = - 1, y = -1;
				break;
			}
			default:
				break;			
		}
		
	}
}
void drawQLDiemThi(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree) {
	resetID(arrID);
	setbkcolor(MAU_NEN);

   	cleardevice();
	settextstyle(10,0,2);
	
	tao_khung(5,60,1035,860); 
	tao_khung(10,65,1030,355);
	tao_khung(10,365,1030,855);//800
	
	tao_khung(1045,60,1360,500); //khung canh bao
	
	settextstyle(10,0,5);
	setcolor(COLOR(247,145,31)); //color orange with rbg
	outtextxy(530,10,"Quan Ly Diem Thi");

	settextstyle(10,0,2);
	setcolor(MAU_DO_NHAT);
	outtextxy(1120,80,"BANG THONG BAO");
	line(1120,100,1290,100);
	setcolor(MAU_DEN);
	

	
	
	tao_button(20,20,80,50,"Back", MAU_HONG, MAU_DEN, 43, mapID);
	
	
	tao_button(60,800,120,830,"Prev", MAU_XANH_LA, MAU_DEN, 153, mapID);
	tao_button(910,800,970,830,"Next", MAU_XANH_LA, MAU_DEN, 154, mapID);
	
	int maxpage;
	if(dsLop.soLuong <= 10) { // Neu so luong <= 10
		maxpage = 0;
	}
	else if(dsLop.soLuong % 10 == 0){
		maxpage = dsLop.soLuong/10 -1;
	}
	else maxpage = dsLop.soLuong/10;
	
	char page_str[10] = "";  
	itoa(maxpage+1, page_str, 10);
	char res[20] = "";
	strcat(res,"Trang 1/");
	strcat(res, page_str);
	outtextxy(490,810, res);
	
	inDSLop(mapID,dsLop,arrID, 0);
	
	checkMouseQLDiemThi(mapID, arrID, dsMonHoc, dsLop, rootTree);	
}

void checkMouseMenu(short **mapID, int arrID[], DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree) {
	int x = - 1, y = -1;

	while (1) {
		delay(0.001); 

		int ID = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			ID = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(x != -1 && y != -1 )
		switch(ID) {
			case 26: {
				drawQLLop(mapID, arrID, dsMonHoc, dsLop, rootTree);
				break;
			}
			case 27: {
				drawQLSinhVien(mapID, arrID, dsMonHoc, dsLop, rootTree);
				break;
			}
			case 28: {
				drawQLMonHoc(mapID, arrID, dsMonHoc, dsLop, rootTree);
				break;
			}
			case 29: {
				drawQLCauHoi(mapID, arrID, dsMonHoc, dsLop, rootTree);
				break;
			}
			case 30: {
				drawQLDiemThi(mapID, arrID, dsMonHoc, dsLop, rootTree);
				break;
			}
			case 31: {
				drawBeforeThi(mapID, dsMonHoc, dsLop, rootTree, arrID, NULL);
				break;
			}
			case 32: { //thoat
				giai_phong_mapID(mapID);
				giaiPhongDSLop(dsLop);
				giaiPhongCay(rootTree);
				delay(1000);
				exit(0);
				break;
			}
			default:
				break;			
		}
		
	}
}




//Ve menu giao vien
void drawMainMenu(short **mapID, DanhSachMonHoc dsMonHoc, DanhSachLop dsLop, PTRCauHoi rootTree, int arrID[]) {
	
	char titleMenu[][50] = {
		"Quan ly Lop", //2
		"Quan Ly Sinh Vien", //3
		"Quan Ly Mon Hoc", //4
		"Quan Ly Cau Hoi Thi", //7
		"Quan Ly Diem Thi", //10
		"Thi Trac Nghiem", //8
		"Thoat"  //0
	};
	resetID(arrID);
	setbkcolor(MAU_NEN);

   	cleardevice();
	settextstyle(10,0,8);
	

	setcolor(COLOR(247,145,31)); //color orange with rbg

	settextstyle(10,0,8);
	outtextxy(350,150,"THI TRAC NGHIEM");
	
	settextstyle(10,0,2);	
	outtextxy(800,750,"N19DCCN019 - Pham Dung Bac");
	outtextxy(800,780,"N19DCCN034 - Nguyen Duc Phuc Dai");
	setcolor(MAU_DEN);
	
	for(int i=0;i<7;i++) {
		tao_button(530,270 + i*60,840,320 + i*60,titleMenu[i],MAU_XANH_DUONG, MAU_TRANG, ++arrID[6],mapID);
	}
	
	checkMouseMenu(mapID, arrID, dsMonHoc, dsLop, rootTree);

}
	
void checkMouseLogin(short **mapID, DanhSachLop dsLop, DanhSachMonHoc dsMonHoc, PTRCauHoi rootTree, int arrID[]){
	int x = - 1, y = -1;
	char username[18] = "";
	char password[18] = "";
	char decode[18]= "";

	while (1) {
		delay(0.001); //delay nhan click 

		int ID = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			ID = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(x != -1 && y != -1) {
			switch(ID) {
				case 2: {
					nhapText(610, 405, 870, 430, username, 16, 1);
					x = -1;
					y = -1;
					break;
				}
				case 3: {
					nhapPassword(610, 465, password, decode, 16);
					x = -1;
					y = -1;
					break;
				}
				case 4: {
					int check = 0;
					PTRSinhVien p = xuLyDangNhap(dsLop, username, password, check);
					
					switch(check) {
						case 0: {
							drawBeforeThi(mapID, dsMonHoc, dsLop, rootTree, arrID, p);
							break;
						}
						case 1: { //menu gv					
							drawMainMenu(mapID,dsMonHoc, dsLop, rootTree, arrID);
							break;
	
						}
						case 2: {
							thongBaoDangNhap(560,100,1200,130,"Sai tai khoan hoac mat khau!");
							break;
						}
						case 3: {
							thongBaoDangNhap(450,100,1200,130,"Tai khoan hoac mat khau khong duoc de trong!");
							break;
						}
					}			
					x = -1;
					y = -1;
					break;
				}
				default:
					break;			
			}
		}
	
		
	}
}


void drawMainLogin(short **mapID, DanhSachLop dsLop, DanhSachMonHoc dsMonHoc, PTRCauHoi rootTree, int arrID[]){
	char buttonDangNhap[][50] = {
		"Tai khoan", "Mat khau", "DANG NHAP",
	};
	setcolor(COLOR(247,145,31)); //color orange with rbg

	settextstyle(10,0,8);
	outtextxy(350,150,"THI TRAC NGHIEM");
	
	settextstyle(10,0,2);	
	outtextxy(800,750,"N19DCCN019 - Pham Dung Bac");
	outtextxy(800,780,"N19DCCN034 - Nguyen Duc Phuc Dai");
	
	setcolor(MAU_DEN);

	tao_khung(390,320,990,620); 
	
	for(int i=0;i<2;i++) {
		tao_button(470,400 + i*60,590,430 + i*60, buttonDangNhap[i], MAU_HONG, MAU_DEN, -2, mapID);
		taoTextInput(600,400 + i*60,870,430 + i *60, ++arrID[0], mapID);
	}
	
	
	tao_button(630, 520, 750, 550, buttonDangNhap[2], MAU_HONG,MAU_DEN, ++arrID[0] ,mapID);
	
	
	/* =====END DRAW==== */

	checkMouseLogin(mapID, dsLop, dsMonHoc, rootTree, arrID);

}

void drawMainFrame(DanhSachLop dsLop, DanhSachMonHoc dsMonHoc, PTRCauHoi rootTree){
	initwindow(WIDTH,HEIGHT);		
	setbkcolor(MAU_NEN);
   	cleardevice();
   	
   	/*========MapID=========*/
   	short **mapID = new short*[WIDTH+1]; 
	
	for(int x = 0;x <= WIDTH;x++) {
		mapID[x] = new short[HEIGHT+1];
	} 
	

	/*
		- Khoi tao array ID;
		- arrID[0] la id phan login tu 2->4
		- arrID[1] la id phan truoc khi thi tu 6->9
		- arrID[2] la id phan button submit, next and prev tu 11->13
		- arrID[3] la id phan chon dap an tu 15 -> 18
		- arrID[4] la id phan canh bao nop bai tu 20->21, 22 check time over
		- arrID[5] la id phan cham diem 24
		- arrID[6] la id phan menu giao vien tu 26-31
		- arrID[7] la 101 id dong` table Lop
		- arrID[8] 186; table monhoc
		- arrID[9] table cau hoi thi
		- arrID[10] table diem thi
		- arrID[11] table sinh vien
	*/
	int arrID[] = {1, 5, 10, 14, 19, 23, 25, 101 , 186, 200, 230, 158};  

	drawMainLogin(mapID, dsLop, dsMonHoc, rootTree, arrID);
	
}


