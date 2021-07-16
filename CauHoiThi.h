#pragma once

#include "DeThi.h"
#include <time.h>
#include <cstdlib>
#include <fstream>
using namespace std;
struct CauHoiThi {
	int ID; 
	char noiDung[126];
	char dapAnA[126];
	char dapAnB[126];
	char dapAnC[126];
	char dapAnD[126];
	char dapAn;
	char maMH[16];

};


struct NodeCauHoiThi {
	int ID; // Key
	CauHoiThi cht; //info
	NodeCauHoiThi *left;
	NodeCauHoiThi *right;
};

typedef struct NodeCauHoiThi *PTRCauHoi;

//ham khoi tao cay
void InitTree(PTRCauHoi &root)
{
	root = NULL;
}

//ham kiem tra cay co bi rong khong
bool isEmpty(PTRCauHoi root)
{
	return(root == NULL);
}

void Insert_Tree(PTRCauHoi &p, int ID, CauHoiThi cht)
{ 
   if(p == NULL)    
   {
     p = new NodeCauHoiThi;
     p->ID  = ID;      p->cht = cht;
     p->left = NULL;     p->right = NULL;  
   }
   else
    if(ID < p->ID )
      Insert_Tree(p->left, ID, cht);
    else if(ID > p->ID )	    Insert_Tree(p->right, ID, cht);
}

void Intrav(PTRCauHoi root) //Left Node Right
{  
	PTRCauHoi p=root;

	if(p != NULL) {  
		Intrav(p->left);
	    cout << p->cht.ID << " "<<endl;
	    Intrav(p->right);
	}


}
bool ktTrungCauHoi(PTRCauHoi root, CauHoiThi cht) //Kiem tra cau hoi xem bi trung chua.
{

    PTRCauHoi Stack[STACKSIZE];
	PTRCauHoi p = root;
	int sp = -1;	// Khoi tao Stack rong
	do
	{
		while (p != NULL)
		{
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1)
		{
			p = Stack[sp--];
			if(strcmp(p->cht.maMH,cht.maMH) == 0 && strcmp(p->cht.dapAnA, cht.dapAnA) == 0 && strcmp(p->cht.dapAnB, cht.dapAnB) == 0 && strcmp(p->cht.dapAnC, cht.dapAnC) == 0 
				&& strcmp(p->cht.dapAnD, cht.dapAnD) == 0 && strcmp(p->cht.noiDung, cht.noiDung) == 0 &&  p->cht.dapAn == cht.dapAn) {
				return false;
			}
			p = p->right;
		}
		else
			break;
	} while (1);
	return true;
}

//Dem so luong cau hoi thi
int countNode(PTRCauHoi root) {
	PTRCauHoi Stack[STACKSIZE];
	PTRCauHoi p = root;
	int i = 0;
	int sp = -1;	// Khoi tao Stack rong
	do
	{
		while (p != NULL)
		{
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1)
		{
			p = Stack[sp--];
			++i;
			p = p->right;
		}
		else
			break;
	} while (1);
	return i;
}





// Tra ve so luong cac cau hoi theo ma mon hoc
int lengthCauHoiTheoMH(PTRCauHoi root, char maMH[]) 
{
		
	PTRCauHoi Stack[STACKSIZE];
	PTRCauHoi p = root;
	int i = 0;
	int sp = -1;	// Khoi tao Stack rong
	do
	{
		while (p != NULL)
		{
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1)
		{
			p = Stack[sp--];
			if(strcmp(p->cht.maMH, maMH) == 0) {
				i++;
			}
			
			p = p->right;
		}
		else
			break;
	} while (1);
	
	return i;

   
}

//Them vao mang cau hoi thi theo ma mon hoc
void addCHTheoMonToArray(PTRCauHoi root, CauHoiThi arr[], char maMH[]) {
	
	PTRCauHoi Stack[STACKSIZE];
	PTRCauHoi p = root;
	int i = 0;
	int sp = -1;	// Khoi tao Stack rong
	do
	{
		while (p != NULL)
		{
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1)
		{
			p = Stack[sp--];
			if(strcmp(p->cht.maMH, maMH) == 0) {
				arr[i] = p->cht;
				i++;
			}
			
			p = p->right;
		}
		else
			break;
	} while (1);

	
}


void addCHToArray(PTRCauHoi root,CauHoiThi arr[] ) {

	PTRCauHoi Stack[STACKSIZE];
	PTRCauHoi p = root;
	int i = 0;
	int sp = -1;	// Khoi tao Stack rong
	do
	{
		while (p != NULL)
		{
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1)
		{
			p = Stack[sp--];
			arr[i] = p->cht;
			i++;
			p = p->right;
		}
		else
			break;
	} while (1);
}

/*
	Ham thuc hien lay cac cau hoi cua mot mon dua theo Ma mon hoc va gan vao mang chMotMon[]
	Dong thoi lay duoc so luong cau hoi cua mot mon theo n
*/


void randomCauHoi(PTRCauHoi root, CauHoiThi arrayCauHoiRandom[], int soCauHoi, char maMH[])
{	  				

	
	int maxSoCau = lengthCauHoiTheoMH(root, maMH);
	CauHoiThi arrayCauHoi[maxSoCau];
	addCHTheoMonToArray(root,arrayCauHoi, maMH);
	
	//Random Cau Hoi
	bool* KT = new bool[maxSoCau] { false };  //tao mang va gan tat ca phan tu = false
	int a = 0;
	int i = 0;

	srand(time(NULL));
	while (i < soCauHoi)
	{
		a = rand() % + maxSoCau; //random 0-> (max cau hoi -1) cua mon
		if (!KT[a])
		{
			arrayCauHoiRandom[i++] = arrayCauHoi[a];
			KT[a] = true;
		}
	}
}


PTRCauHoi searchCauHoi(PTRCauHoi root, int id) {
	PTRCauHoi p=root;
	while (p != NULL && p->ID != id)
		if(id < p->ID)
			p = p->left;
		else
			p = p->right;
	return p;
}

//xoa nut trong truong hop 3
void remove_case_3 ( PTRCauHoi &r , PTRCauHoi &rp )
{
	if (r->left != NULL) 
	{
		remove_case_3 (r->left,rp);	
	}
	//den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
	else
	{
		rp->ID = r->ID; //rp la node the mang 
		rp->cht = r->cht; 
		rp = r;
		r = rp->right;
	}
}

//xoa nut co khoa id
void removeCauHoi (int id , PTRCauHoi &p )
{
	PTRCauHoi rp;
	if (p == NULL) {
		cout <<  "Khong tim thay";
		return;
	} 
	else {
		if (id < p->ID)  {
			removeCauHoi (id, p->left); //duyet qua trai
		} 
		
		else if (id > p->ID) {
			removeCauHoi (id, p->right); //duyet qua trai
		}
		
		else {   // p->id = id, tim duoc node can xoa 
			rp = p;
			
			if (rp->right == NULL) { 
				p = rp->left;	// duyet sang phai node can xoa
			}
			
			else if(rp->left == NULL) {
				p = rp->right; // duyet sang trai node can xoa
			}
			
			else { //Node can xoa co 2 cay con
				remove_case_3 (rp->right,rp);
			}
			
			delete rp;
		}	
		
	}
	
}

// Giai phong cay bang de quy nen xem xet lai

void giaiPhongCay(PTRCauHoi &root) 
{ 
    if (root == NULL) return; 
  
    /* first delete both subtrees */
    giaiPhongCay(root->left); 
    giaiPhongCay(root->right); 
      
    /* then delete the node */
   
    delete root;
} 
