
#pragma once 
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <cstdlib> 
#include <cmath>
using namespace std;

/*
	=====Cac ham ve chuoi====
		strlen -> length
		strcmp -> so sanh  == 0 la trung nhau
		strcat -> ham noi chuoi
		strcpy -> copy
		strupr -> uppercase
		strstr -> tim chuoi con
		strchr ->  tra ve vi tri dau tien cua ky tu can tim
		====End=====
		
*/
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b= temp;
}


void ftoa(float n, char res[], int afterpoint) //afterpoint lay bao nhieu so phan thap phan
{
    
    int phan_nguyen = (int)n; //lay phan nguyen
  
    float thap_phan = n - (float)phan_nguyen; // Lay phan thap phan
    itoa(phan_nguyen, res,10);  //chuyen phan nguyen sang string
  	int i = strlen(res);
    if (afterpoint != 0) {
        res[i] = '.'; // add dot
  
        thap_phan = thap_phan * pow(10, afterpoint); 
  
        itoa((int)thap_phan, res + i + 1,10); //truyen dia chi tiep theo
    }
}

int randomNumber(int minN, int maxN){
	// initialize random seed, hai seed giong nhau se tao ra mot ket qua nen can random seed 
	srand(time(NULL));  // set initial seed value to system clock
    return minN + rand() % (maxN + 1 - minN);
}


//xoa toan bo chuoi ki tu
void xoaChuoi(char s[]) {
	int i = 0;
    while(s[i] != '\0') {
        s[i] = '\0';
        i++;
    }
}

//Xoa ki tu trong chuoi theo vi tri
void xoaKiTu(char s[90],int vitrixoa)
{
	int n=strlen(s);
    for(int i=vitrixoa; i<n; i++)
     s[i]=s[i+1];
	s[n-1]='\0'; //giam di do dai chuoi
}

//xoa khoang trang cuoi chuoi
void xoaKhoangTrangCuoi(char *str) {
	if(str[strlen(str)-1]==' ') //xoa khoang trang cuoi chuoi
		xoaKiTu(str,strlen(str)-1);
}

//xoa khoang trang dau chuoi va ke nhau
void xoaKhoangTrangDauVaKeNhau(char *str) {
	for(int i=0;i<strlen(str);i++)  
		if(str[i]==' '&& str[i+1]==' ')  //Neu cac khoang trang ke nhau
		{
			xoaKiTu(str,i);
			i--;
		}
    if(str[0]==' ') //xoa khoang trang dau chuoi
		xoaKiTu(str,0);
}

/*
	Cat nho chuoi VD: "Every day, my mother ___________ the washing up with the help of the washing machine."
	 begin= 0, end=5 =>  "Every day, my mother ___________"
*/

void catChuoi2Dong(char *str,char res1[],char res2[]) {
    xoaChuoi(res1);
	xoaChuoi(res2);
		
   
    char res[1000][20]; 
    int index = 0;
    

    
    char *p;
    for(p = strtok(str," ");p!=NULL;p=strtok(NULL," ")) {
        strcpy(res[index],p);
        index++;
    }
    
  	int i= 0;

    while(strlen(res1) < 60) {
	    strcat(res1, res[i]);
        strcat(res1, " ");
	    i++;
	}
	
	for(int j=i;j<index;j++) {
	 	strcat(res2, res[j]);
        strcat(res2, " ");
	}	
    

}





/* 
	Kiem tra chuoi 
	1 la chuoi rong 
	0 la chuoi binh thuong
*/


int kiemTraChuoiRong(char s[]) {
	
	return strcmp(s,"") == 0 ? 1 : 0; 
	
}


/*
	Xoa khoang trang 
	In hoa ky tu dau 
*/
void validateText(char s[]) {
	xoaKhoangTrangDauVaKeNhau(s);
    xoaKhoangTrangCuoi(s);
	
	for (int i = 0; s[i] != '\0'; i++)  //in hoa chu cai dau cua tung tu`
    {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        if (s[i - 1] == ' ' || i == 0)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 32;
        }
    }
}





