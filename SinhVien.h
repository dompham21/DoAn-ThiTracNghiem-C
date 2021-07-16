#pragma once
#include <fstream>
#include "DiemThi.h"
using namespace std;

struct SinhVien {
	char maSV[16];
	char ho[21];
	char ten[11];
	char phai[5];
	char password[17];
	PTRDiemThi dsDiemThi = NULL;
};

struct NodeSinhVien {
	SinhVien sv;
	NodeSinhVien *next;
};


typedef struct NodeSinhVien *PTRSinhVien;


int Empty(PTRSinhVien FirstSV)
{
   return(FirstSV == NULL ? TRUE : FALSE);
}

//nhap vao ma sinh vien theo danh sach sinh vien->tra ve sinh vien theo ma do, neu khong co tra ve NULL 
PTRSinhVien searchSV(PTRSinhVien FirstSV, char maSV[]) {
	PTRSinhVien nodeChay;
	nodeChay = new NodeSinhVien;
	nodeChay = FirstSV;
	
    while(nodeChay != NULL){
       if (strcmp(nodeChay->sv.maSV,maSV) == 0)
		{
			return nodeChay;
	    }
        nodeChay = nodeChay->next;
    }

	return NULL;

}

//Nhap vao vi tri tra ve sinhvien 
PTRSinhVien timKiemSVTheoVT(PTRSinhVien FirstSV, int vitri) {
	PTRSinhVien nodeChay;
	nodeChay = new NodeSinhVien;
	nodeChay = FirstSV;
	for (int i = 0; i < vitri; i++) {
		nodeChay = nodeChay->next;
	}
	return nodeChay;
}


// Tao mot ham tao node moi Ptr p; p=new Node
void Insert_First_SV(PTRSinhVien &FirstSV, SinhVien sv)
{
   PTRSinhVien p;
   p = new NodeSinhVien;
   p->sv = sv;
   p->next = FirstSV;
   FirstSV = p;
}

//thêm mot sinh vien vào sau mot nut dia chi p
void Insert_after_SV( PTRSinhVien p, SinhVien sv)
{
   PTRSinhVien q;
   if(p == NULL)
		cout<<"khong them phan tu vao danh sach duoc"<<endl;
   else
   { 
   		q = new NodeSinhVien;
    	q->sv = sv;
      	q->next = p->next;
      	p->next = q;
   }
}




//them sinh vien vao cuoi danh sach
void themMotSinhVien(PTRSinhVien &FirstSV, SinhVien sv)
{

	if(FirstSV == NULL)
	{
		Insert_First_SV(FirstSV, sv);

	}
	else 
	{

		PTRSinhVien nodeChay;
		nodeChay = new NodeSinhVien;
		nodeChay = FirstSV;
		
		while( nodeChay->next != NULL){
	        nodeChay = nodeChay->next;
		}
		Insert_after_SV(nodeChay, sv);	
		
	}

}



void xuatDsSV(PTRSinhVien FirstSV) {
    PTRSinhVien nodeChay;
	nodeChay = new NodeSinhVien;
	nodeChay = FirstSV;
	
    while(nodeChay != NULL){
        cout<<"Hoten: "<<nodeChay->sv.ten<<", Maso: "<<nodeChay->sv.maSV<<endl;
        nodeChay = nodeChay->next;
    }
   

}

int demSLSinhVien(PTRSinhVien FirstSV) {
	int dem = 0;
	
	PTRSinhVien nodeChay;
	nodeChay = new NodeSinhVien;
	nodeChay = FirstSV;
	
	while(nodeChay != NULL){
       	dem++;
        nodeChay = nodeChay->next;
    }

	return dem;
}

//kiem tra sinh vien da thi mon nay chua
bool KTSinhVienDaThiChua(PTRSinhVien p, char maMH[]) {
	

	PTRDiemThi nodeChay;
	nodeChay = new NodeDiemThi;
	nodeChay = 	p->sv.dsDiemThi;

	while( nodeChay != NULL){
		if(strcmp(nodeChay->dt.maMH, maMH) == 0) {
			return true;
		}
	    nodeChay = nodeChay->next;
	}
	
	return false;
}


void Delete_firstSV(PTRSinhVien &FirstSV)
{
   
	PTRSinhVien p;
	p = new NodeSinhVien;
   	if(Empty(FirstSV))
		return;
  	else{
      p = FirstSV;    // nut can xoa la nut dau
      FirstSV = p->next;
      delete p;
   }
}
// Tac vu Delete_after: xoa nut sau nut p
void Delete_SV(PTRSinhVien p, PTRSinhVien &FirstSV){
   	
	if(p == NULL)
		return;	
	if(p == FirstSV) {
		Delete_firstSV(FirstSV);
	}
	else{
	    PTRSinhVien nodeChay;
		nodeChay = new NodeSinhVien;
		PTRSinhVien nodeTruoc;
		nodeTruoc = new NodeSinhVien;
		nodeChay = FirstSV;
		nodeTruoc = FirstSV;  
		
		while(nodeChay  != p && nodeChay->next!=NULL){
			nodeTruoc = nodeChay;
			nodeChay = nodeChay->next;
		}
		
		if(nodeChay == p){
			//thuc hien xoa
			nodeTruoc->next = nodeChay->next; //nodeChay->next; //nodetruoc->next->next;
			delete nodeChay;
		}
		else{
			return;
		}
	}
}


//giai phong danh sach sinh vien
void giaiPhongDSSV(PTRSinhVien &FirstSV)
{
	PTRSinhVien p;
	if (FirstSV == NULL)
	{
		return;
	}
	p = FirstSV;
	FirstSV = p->next;
	delete p;
}
