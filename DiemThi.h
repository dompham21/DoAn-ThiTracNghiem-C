#pragma once

#include "BaiThi.h"
#include "SinhVien.h"
using namespace std;
struct DiemThi {
	char maMH[16];
	float diem;
	BaiThi bt;
};

struct NodeDiemThi {
	DiemThi dt;
	NodeDiemThi *next;
};


typedef struct NodeDiemThi *PTRDiemThi;


//Nen bo
void InitDiemThi(PTRDiemThi &FirstDT)
{
   FirstDT = NULL;
}

//them diem thi vao dau danh sach
void Insert_First_DT(PTRDiemThi &FirstDT, DiemThi dt)
{
   PTRDiemThi p;
   p = new NodeDiemThi;
   p->dt = dt;
   p->next = FirstDT;
   FirstDT = p;
}


bool ktDaThiMonHoc(PTRDiemThi p, char maMH[]) {
	PTRDiemThi nodeChay;
	nodeChay = new NodeDiemThi;
	nodeChay = p;
	
	while(nodeChay != NULL) { //tim so luong thi
		if(strcmp(nodeChay->dt.maMH, maMH) == 0) {
			return true;
		}	
		nodeChay = nodeChay->next;
	}
	return false;
}

//thêm mot sinh vien vào sau mot nut dia chi p
void Insert_after_DT( PTRDiemThi p, DiemThi dt)
{
   PTRDiemThi q;
   if(p == NULL)
		cout<<"khong them phan tu vao danh sach duoc"<<endl;
   else
   { 
   		q = new NodeDiemThi;
    	q->dt = dt;
      	q->next = p->next;
      	p->next = q;
   }
}



void themMotDiemThi(PTRDiemThi &FirstDT, DiemThi dt)
{
	if(FirstDT == NULL)
	{
		Insert_First_DT(FirstDT, dt);

	}
	else 
	{

		PTRDiemThi nodeChay;
		nodeChay = new NodeDiemThi;
		nodeChay = FirstDT;
		while( nodeChay->next != NULL){
	        nodeChay = nodeChay->next;
		}
		Insert_after_DT(nodeChay, dt);	
		
	}


}
int demMonDaThi(PTRDiemThi FirstDT) {
	int dem = 0;
	PTRDiemThi nodeChay;
	nodeChay = new NodeDiemThi;
	nodeChay = FirstDT;
	
	  while(nodeChay != NULL){
        dem++;
        nodeChay = nodeChay->next;
    }
    
    return dem;

}



void xuatDsDT(PTRDiemThi FirstDT) {
    PTRDiemThi nodeChay;
	nodeChay = new NodeDiemThi;
	nodeChay = FirstDT;

    while(nodeChay != NULL){
        cout<<"Ma mon hoc: "<<nodeChay->dt.maMH<<", Diem: "<<nodeChay->dt.diem<<endl;
        nodeChay = nodeChay->next;
    }
}

void giaiPhongDSDT(PTRDiemThi &FirstDT)
{
	PTRDiemThi p;
	if (FirstDT == NULL)
	{
		return;
	}
	p = FirstDT;
	FirstDT = p->next;
	delete p;
}


 



