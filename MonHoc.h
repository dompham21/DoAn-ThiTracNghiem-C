#pragma once
#include "function.h"
#include "Lop.h"
#include <fstream>

using namespace std;
struct MonHoc {
	char maMH[16];
	char tenMH[51];
	
};

struct DanhSachMonHoc {
	// Mang tuyen tinh	
	MonHoc mh[MAXMONHOC];
	unsigned int soLuong ;
};

bool isEmpty(DanhSachMonHoc dsMonHoc)
{
	return(dsMonHoc.soLuong == 0);
}

bool isFull(DanhSachMonHoc dsMonHoc)
{
	return(dsMonHoc.soLuong == MAXMONHOC);
}

void create(DanhSachMonHoc & dsMonHoc)
{
	dsMonHoc.soLuong = 0;
}



void xuatMonHoc(DanhSachMonHoc dsMonHoc)
{
	for(int i= 0 ; i< dsMonHoc.soLuong;i++) {
		cout << "maMH: " << dsMonHoc.mh[i].maMH << endl;
		cout << "tenMH: " << dsMonHoc.mh[i].tenMH << endl;
	}

}

//Ham kiem tra xem ma mon hoc hoac ten co bi trung trong danh sach, da co san hay chua, co tra ve "false"
bool ktTrungMaMonHoc(char maMH[], DanhSachMonHoc dsMonHoc) { 

	for (int i = 0; i < dsMonHoc.soLuong; i++)
	{ 
		if (strcmp(maMH,dsMonHoc.mh[i].maMH) == 0 )
		{
			return true;
		}
	}
	return false;
}




int themMonHoc( DanhSachMonHoc &dsMonHoc, MonHoc mh) {

	if(isFull(dsMonHoc)) {
		return 0;
	}
	if(ktTrungMaMonHoc(mh.maMH,dsMonHoc)) {
		return 0;
	}
	
	
	dsMonHoc.mh[dsMonHoc.soLuong] = mh;

	dsMonHoc.soLuong++;
	return 1;
}

//Kiem tra mon hoc nay co ai thi chua trong tat ca cac lop
bool checkMHDaThi(char maMH[], DanhSachLop dsLop) {
	
	for(int i = 0; i < dsLop.soLuong; i++) {
	
		PTRSinhVien nodeChay;
		nodeChay = new NodeSinhVien;
		nodeChay = dsLop.lh[i]->dsSinhVien;
	    
		while(nodeChay != NULL) {
	       	if(KTSinhVienDaThiChua(nodeChay, maMH)) {
	       		return true;	
			}
	        nodeChay = nodeChay->next;
	    }
		
	}
	return false;
}





