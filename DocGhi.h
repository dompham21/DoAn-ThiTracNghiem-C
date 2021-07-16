#pragma once

#include <iostream>
#include "Lop.h"
#include "MonHoc.h"
#include "CauHoiThi.h"
#include "DiemThi.h"
#include "SinhVien.h"


int getIDTuFile() {
	int n;
	int x;
	int soLuong; //so luong phan tu da su dung
	ifstream fileIn;
	fileIn.open("SourceRDNumber.txt", ios_base::in);

	if(fileIn.fail()) 
		cout << "Khong the doc file id";
	
	fileIn >> n; //doc so luong phan tu source
	fileIn >> soLuong;		
	
	int arr[n];
			
	for (int i = 0; i < n; i++)
		fileIn >> arr[i];
		
	x = arr[soLuong]; //lay phan tu dau tien 
	

	

	fileIn.close();
	
	ofstream fileout;
	fileout.open("SourceRDNumber.txt", ios_base::out);
	fileout << n << endl;
	fileout << soLuong+1 <<endl; 
	for (int i = 0; i < n; i++)
		fileout << arr[i] << " ";
	
	fileout.close();


	return x;
}

void luuFileDSCauHoi(PTRCauHoi root) {
 	ofstream fileOut;
 	fileOut.open("DanhSachCauHoi.txt", ios_base :: out);
    
    PTRCauHoi Stack[STACKSIZE];
	PTRCauHoi p = root;
	int sp = -1;	// Khoi tao Stack rong

	while (p!=NULL )
	{
		fileOut << p->cht.ID <<endl;
		fileOut << p->cht.maMH << endl;
		fileOut << p->cht.noiDung << endl;
		fileOut << p->cht.dapAnA <<endl;
		fileOut << p->cht.dapAnB <<endl;
		fileOut << p->cht.dapAnC <<endl;
		fileOut << p->cht.dapAnD <<endl;
		fileOut << p->cht.dapAn <<endl;
		if (p->right != NULL)
			Stack[++sp]= p->right;
		if (p->left != NULL)
			p=p->left;
		else if (sp==-1)
			break;
		else p=Stack[sp--];
	}
	
	fileOut.close();
}
void docFileDSCauHoi(PTRCauHoi &root)
{
	CauHoiThi cht;
	ifstream fileIn;
	fileIn.open("DanhSachCauHoi.txt", ios_base :: in );
	
	if(fileIn.fail()) {
	 	cout << "Khong the doc file cau hoi thi"<<endl;
	}
	else {
		while (!fileIn.eof())
		{
			fileIn >> cht.ID;
			if(cht.ID == 0) {
				break;
			}
			fileIn.ignore();
					
			fileIn.getline(cht.maMH, sizeof(cht.maMH), '\n');
			fileIn.getline(cht.noiDung, sizeof(cht.noiDung), '\n');
			fileIn.getline(cht.dapAnA, sizeof(cht.dapAnA), '\n');
			fileIn.getline(cht.dapAnB, sizeof(cht.dapAnB), '\n');
			fileIn.getline(cht.dapAnC, sizeof(cht.dapAnC), '\n');
			fileIn.getline(cht.dapAnD, sizeof(cht.dapAnD), '\n');
			
			fileIn >> cht.dapAn;
			fileIn.ignore();		
			Insert_Tree(root, cht.ID, cht);
		}
	}
	
	fileIn.close();
}


//xuat file mon hoc ra file DSmonhoc.txt
void luuFileDSMonHoc(DanhSachMonHoc dsMonHoc)
{
	ofstream fileOut;
	fileOut.open("DanhSachMonHoc.txt", ios_base :: out);
  
	fileOut << dsMonHoc.soLuong << "\n";
	for (int i = 0; i < dsMonHoc.soLuong; i++)
	{			  
    	fileOut << dsMonHoc.mh[i].maMH << endl;
    	fileOut << dsMonHoc.mh[i].tenMH << endl;
	}
    fileOut.close();
}

void docFileDSMonHoc(DanhSachMonHoc &dsMonHoc)
{ 
	int n;	
	ifstream fileIn;
	fileIn.open("DanhSachMonHoc.txt", ios::in);
    
	/* 
		Doc so luong mon hoc o dong` dau tien
		su dung >> thi file doc xong thi` dung' cuoi' dong` chu khong xuong dong`
	*/
	if(fileIn.fail()) {
	 	cout << "Khong the doc file mon hoc"<<endl;
	}
	else { 
		fileIn >> n; 
		fileIn.ignore(); //bo qua \n 
		
		for (int i = 0; i < n; i++)
		{	
			MonHoc mh;
			fileIn.getline(mh.maMH, sizeof(mh.maMH),'\n');
			fileIn.getline(mh.tenMH, sizeof(mh.tenMH), '\n');
			themMonHoc(dsMonHoc,mh);
		}
	
	}
	
	fileIn.close();
}

void docFileDSSinhVien( PTRSinhVien &p,char* maLop) {  
	ifstream fileIn;
	
	char src[50];
	char dest[5];
	strcpy(src,  "DSSV_");
	strcpy(dest,  ".txt");

 	strcat(src,maLop);
 	strcat(src,dest);
 	
 	fileIn.open(src, ios_base :: in);

	if(fileIn.fail()) {
	 	cout << "Khong the doc file sinh vien"<<endl;
	}
	else {
		SinhVien sv;
	
		while(!fileIn.eof()) {
			
			fileIn.getline(sv.maSV, sizeof(sv.maSV),'\n');
			
			if(strlen(sv.maSV) == 0) {  //kiem tra ky tu space cuoi cung trong file
				break;
			}
			fileIn.getline(sv.ho, sizeof(sv.ho),'\n');
			fileIn.getline(sv.ten, sizeof(sv.ten),'\n');
			fileIn.getline(sv.phai, sizeof(sv.phai), '\n');
			fileIn.getline(sv.password, sizeof(sv.password), '\n');
			
			themMotSinhVien(p, sv);

		}
	}

	fileIn.close();
}


void docFileDSDiem(PTRSinhVien FirstSV, char maLop[]) { 
	ifstream fileIn;
	char maSV[16];
	int slMonDaThi; 
	
	char src[50];
	char dest[5];
	strcpy(src,  "DIEM_");
	strcpy(dest,  ".txt");

 	strcat(src,maLop);
 	strcat(src,dest);
 


 	fileIn.open(src, ios_base :: in);

	if(fileIn.fail())  {
		cout<<"khong the doc file "<<src<<endl;
	}
	else {
		while(!fileIn.eof()) {
			fileIn.getline(maSV,sizeof(maSV),'\n');
			if(strlen(maSV) == 0) {
				break;
			}
			fileIn>>slMonDaThi;
			fileIn.ignore();
	
					
			PTRSinhVien p = searchSV(FirstSV,maSV); //Tim kiem sinh vien trong lop
		
	
			for(int i = 0; i < slMonDaThi; i++) {
				DiemThi dt;
	
				fileIn.getline(dt.maMH,sizeof(dt.maMH),'\n');
	
				fileIn>>dt.diem;
	
				fileIn.ignore();
				fileIn>> dt.bt.soCauHoi;
	
				fileIn.ignore();
				dt.bt.cht = new CauHoiThi[dt.bt.soCauHoi];
				dt.bt.dapAnDaChon = new char[dt.bt.soCauHoi];
	
				for (int i = 0; i < dt.bt.soCauHoi; i++) {
	
					fileIn >> dt.bt.cht[i].ID;
					fileIn.ignore();
					fileIn.getline(dt.bt.cht[i].noiDung, sizeof(dt.bt.cht[i].noiDung),'\n');
					fileIn.getline(dt.bt.cht[i].dapAnA, sizeof(dt.bt.cht[i].dapAnA),'\n' );
					fileIn.getline(dt.bt.cht[i].dapAnB, sizeof(dt.bt.cht[i].dapAnB) ,'\n');
					fileIn.getline(dt.bt.cht[i].dapAnC, sizeof(dt.bt.cht[i].dapAnC),'\n' );
					fileIn.getline(dt.bt.cht[i].dapAnD, sizeof(dt.bt.cht[i].dapAnD),'\n' );
					fileIn >> dt.bt.cht[i].dapAn;
					fileIn.ignore();
					fileIn >> dt.bt.dapAnDaChon[i];
					fileIn.ignore();
				}
				themMotDiemThi(p->sv.dsDiemThi, dt);
	
					
			}
	
		
		
		}
	}
	
	

	fileIn.close();


}


void luuFileDSSV(PTRSinhVien p, char* maLop) {
	ofstream fileOut;

	char src[50];
	char dest[5];
	strcpy(src,  "DSSV_");
	strcpy(dest,  ".txt");

 	strcat(src,maLop);
 	strcat(src,dest);
 	
 	fileOut.open(src, ios_base :: out);
	PTRSinhVien nodeChaySV;
	nodeChaySV = new NodeSinhVien;
	nodeChaySV = p;
	
	while( nodeChaySV != NULL) {
		fileOut << nodeChaySV->sv.maSV << endl;
		fileOut << nodeChaySV->sv.ho << endl;
		fileOut << nodeChaySV->sv.ten << endl;
		fileOut << nodeChaySV->sv.phai << endl;
		fileOut << nodeChaySV->sv.password << endl;
		nodeChaySV = nodeChaySV->next;
	}
	
	fileOut.close();

}

void luuFileDSDiem( PTRSinhVien FirstSV, char* maLop) {
 	ofstream fileOut;
 		
	char src[50];
	char dest[5];
	strcpy(src,  "DIEM_");
	strcpy(dest,  ".txt");

 	strcat(src,maLop);
 	strcat(src,dest);
 	
	fileOut.open(src, ios_base::out);

	//Duyet qua danh sach sinh vien cua lop 
	PTRSinhVien nodeChaySV;
	nodeChaySV = new NodeSinhVien;
	nodeChaySV = FirstSV;
		
	while(nodeChaySV != NULL){
	    fileOut<< nodeChaySV->sv.maSV << endl;
	    fileOut<< demMonDaThi(nodeChaySV->sv.dsDiemThi) << endl; //dem so mon da thi (1 mon duoc thi 1 lan)
	       	
	    if(demMonDaThi(nodeChaySV->sv.dsDiemThi) != 0) { 
				   
		    //duyet danh sach diem thi cua sv
			   	
		    PTRDiemThi nodeChayDT;
			nodeChayDT = new NodeDiemThi;
			nodeChayDT = nodeChaySV->sv.dsDiemThi;
		
		   	while(nodeChayDT != NULL){
		   		fileOut<< nodeChayDT->dt.maMH<<endl;
		   		fileOut<< nodeChayDT->dt.diem<<endl;
				fileOut<< nodeChayDT->dt.bt.soCauHoi<<endl;
				for(int i=0;i< nodeChayDT->dt.bt.soCauHoi; i++) { //duyet danh sach cau hoi da thi cua sinh vien
					// Luu thong tin cau hoi
					fileOut << nodeChayDT->dt.bt.cht[i].ID << endl;  
					fileOut << nodeChayDT->dt.bt.cht[i].noiDung << endl;
					fileOut << nodeChayDT->dt.bt.cht[i].dapAnA << endl;
					fileOut << nodeChayDT->dt.bt.cht[i].dapAnB << endl;
					fileOut << nodeChayDT->dt.bt.cht[i].dapAnC << endl;
					fileOut << nodeChayDT->dt.bt.cht[i].dapAnD << endl;
					fileOut << nodeChayDT->dt.bt.cht[i].dapAn << endl;
					//Luu dap an da chon
					fileOut << nodeChayDT->dt.bt.dapAnDaChon[i] << endl;
				}
		   			
		   			
		      	nodeChayDT = nodeChayDT->next;
		    }	
		}
		
	    
	    nodeChaySV = nodeChaySV->next;
	}
		
	
	
	fileOut.close();

 }
 
void docFileDSLop (DanhSachLop &dsLop)
{
	ifstream fileIn;
	fileIn.open("DanhSachLop.txt", ios_base :: in );
	
	if(fileIn.fail()) {
		cout << "Khong the doc file lop";
	}
	else {
		fileIn >> dsLop.soLuong;
		fileIn.ignore();
		for(int i = 0; i < dsLop.soLuong; i++)
		{
			dsLop.lh[i] = new LopHoc;
			fileIn.getline(dsLop.lh[i]->maLop, sizeof(dsLop.lh[i]->maLop),'\n');
			
			if(strlen(dsLop.lh[i]->maLop) == 0) {  //kiem tra ky tu space cuoi cung trong file
				break;
			}
		
			fileIn.getline(dsLop.lh[i]->tenLop, sizeof(dsLop.lh[i]->tenLop),'\n');
			
			docFileDSSinhVien(dsLop.lh[i]->dsSinhVien,dsLop.lh[i]->maLop);

			docFileDSDiem(dsLop.lh[i]->dsSinhVien,dsLop.lh[i]->maLop);
		}

	}
	

	fileIn.close();
}

void luuFileDSlop(DanhSachLop dsLop)
{
	ofstream fileOut;
	fileOut.open("DanhSachLop.txt", ios_base::out);

	fileOut << dsLop.soLuong << endl;
	for (int i = 0; i < dsLop.soLuong; i++) 
	{
		fileOut << dsLop.lh[i]->maLop << endl;
		fileOut << dsLop.lh[i]->tenLop << endl;
		luuFileDSSV(dsLop.lh[i]->dsSinhVien,dsLop.lh[i]->maLop);
		luuFileDSDiem(dsLop.lh[i]->dsSinhVien, dsLop.lh[i]->maLop);
	}
	fileOut.close();
}

void luuFileQLLop(DanhSachLop dsLop)
{
	ofstream fileOut;
	fileOut.open("DanhSachLop.txt", ios_base::out);

	fileOut << dsLop.soLuong << endl;
	for (int i = 0; i < dsLop.soLuong; i++) 
	{
		fileOut << dsLop.lh[i]->maLop << endl;
		fileOut << dsLop.lh[i]->tenLop << endl;

	}
	fileOut.close();
}


