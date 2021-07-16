#pragma once
#include <fstream>

#include "SinhVien.h"
#include "DiemThi.h"
struct LopHoc {
	char maLop[16];
	char tenLop[51];
	PTRSinhVien dsSinhVien = NULL;
};

struct DanhSachLop {
	LopHoc *lh[MAXLOP];
	int soLuong;
};

bool isFull(DanhSachLop dsLop)
{
	return(dsLop.soLuong == MAXLOP);
}

//kiem tra ds lop rong hay khong
bool isEmpty(DanhSachLop &dsLop)
{
	return (dsLop.soLuong == 0);
}



//Ham kiem tra xem ma mon hoc co bi trung trong danh sach, da co san hay chua, co tra ve true
bool ktTrungMaLop(char maLop[], DanhSachLop dsLop)
{ 
	
	for (int i = 0; i < dsLop.soLuong; i++) { 

		if (strcmp(maLop,dsLop.lh[i]->maLop) == 0) {
			return true;
		}
	}
	return false;
}


//Kiem tra trung sinh vien trong tat ca cac lop true la trung, false la khong trung`
bool ktTrungMaSVSchool(DanhSachLop dsLop, char maSV[]) {
	
	for (int i = 0; i < dsLop.soLuong; i++)
	{	
		PTRSinhVien nodeChay;
		nodeChay = new NodeSinhVien;
		nodeChay = dsLop.lh[i]->dsSinhVien;
	    while(nodeChay != NULL){
	       if (strcmp(nodeChay->sv.maSV,maSV) == 0)
			{
				return true;
		    }
	        nodeChay = nodeChay->next;
	    }
	}

	return false;

}

//Duyet tat ca diem thi trong danh sach lop, kiem tra ID co trung voi ID Cau hoi da thi khong, neu co return true, neu khong return false
bool checkCHDaThi(DanhSachLop dsLop, int id) {

	for (int i = 0; i < dsLop.soLuong; i++)
	{
		PTRSinhVien nodeChaySV;
		nodeChaySV = new NodeSinhVien;
		nodeChaySV = dsLop.lh[i]->dsSinhVien;
		  //Lay danh sach sinh vien cua tung lop
		while (nodeChaySV!= NULL)
		{	
			PTRDiemThi nodeChayDT;
			nodeChayDT = new NodeDiemThi;
			nodeChayDT = nodeChaySV->sv.dsDiemThi;
			//lay danh sach diem thi cua tung sinh vien
			while (nodeChayDT != NULL)
			{
				for(int j = 0; j < nodeChayDT->dt.bt.soCauHoi; j++) {
					if(nodeChayDT->dt.bt.cht[j].ID == id) {
						return true;
					}
				}
				nodeChayDT = nodeChayDT->next;
			}
			nodeChaySV = nodeChaySV->next;
		}
	}
	
	return false;
}

int themLopHoc( DanhSachLop &dsLop, LopHoc lh)
{

	if(isFull(dsLop)) {
		cout<<"DS lop bi day!"<<endl;
		return 0;
	}
	if(ktTrungMaLop(lh.maLop,dsLop)) {
		cout<<"MA lop hoc bi trung"<<endl;
		return 0;
	}

	dsLop.lh[dsLop.soLuong] = new LopHoc; //Khoi tao vung nho cho con tro
	*dsLop.lh[dsLop.soLuong] = lh; //Them mon hoc vao vung nho cua con tro, sau khi them vao thi tang so luong phan tu cua danh sach len 1
	dsLop.soLuong ++;

	return 1;
}




LopHoc *timLopTheoMaLop( DanhSachLop dsLop, char maLop[]) {
 	for (int i = 0; i < dsLop.soLuong; i++) { 
																																																										
		if (strcmp(maLop,dsLop.lh[i]->maLop) == 0) {
			return dsLop.lh[i];
		}
	}
	return NULL;
}

// Tim vi tri cua lop trong ds lop ( return index)
int viTriLop( DanhSachLop dsLop, char maLop[]) {
	for (int i = 0; i < dsLop.soLuong; i++) { 
																																																										
		if (strcmp(maLop,dsLop.lh[i]->maLop) == 0) {
			return i; 
		}
	}
	return -1;
}

//giai phong lop

void giaiPhongDSLop(DanhSachLop &dsLop) {
	
	for (int i = 0; i < dsLop.soLuong; i++)
	{
		  //Lay danh sach sinh vien cua tung lop
		while (dsLop.lh[i]->dsSinhVien != NULL)
		{
			  //lay danh sach diem thi cua tung sinh vien
			while (dsLop.lh[i]->dsSinhVien->sv.dsDiemThi != NULL)
			{
				delete[] dsLop.lh[i]->dsSinhVien->sv.dsDiemThi->dt.bt.cht;
				delete[] dsLop.lh[i]->dsSinhVien->sv.dsDiemThi->dt.bt.dapAnDaChon;
				giaiPhongDSDT(dsLop.lh[i]->dsSinhVien->sv.dsDiemThi);
			}
			giaiPhongDSSV(dsLop.lh[i]->dsSinhVien);
		}
		delete dsLop.lh[i];
	}
}
