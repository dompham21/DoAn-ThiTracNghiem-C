#include <stdio.h>
#include <iostream>
#include <time.h>
#include <cstdlib> 
#include <fstream>

using namespace std;

#define STACKSIZE 100000
#define MAX 100000
struct node
{
   int id;	
   struct node *left;
   struct node *right;
};
typedef struct node *NODEPTR;
NODEPTR tree=NULL;


node* newNode(int id)
{
    node* p = new node;
    p->id = id;
    p->left = p->right = NULL;
 
    return p;
}


struct nodeDS {
	NODEPTR diachi ;
	struct nodeDS *next;
};
typedef nodeDS *Node_queue;

struct Queue {
	Node_queue Front, Rear;
} q;

void Insert_queue(Queue &q, NODEPTR x) {
     Node_queue p;
     p = new nodeDS;
     p->diachi = x;  p->next=NULL;
     if (q.Front==NULL)
		q.Front=p;
     else q.Rear->next=p; //chen cuoi
		q.Rear=p;
}

NODEPTR Delete_queue(Queue &q) {
   Node_queue p;
   NODEPTR x;
   if(q.Front==NULL)
   {
      printf("\nHang doi rong");
      
   }
   else
   {
      p = q.Front;    // nut can xoa la nut dau
      x = p->diachi;
      q.Front = p->next;
      delete p;
      return x;
   }
}



int countNode(NODEPTR root)
{
	NODEPTR Stack[STACKSIZE];
	NODEPTR p = root;
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


void swap(int &a, int &b) {
	int temp  = a;
	a = b;
	b = temp;
	
}

int Random( int minN, int maxN)
{
	return minN + rand()%(maxN + 1-minN);
}

int rdMang (int arr[], int sch)
{
	int x = Random(0,49998-sch); //random tu 0 -> n-1
	swap(arr[x],arr[49998-sch]);

	return arr[49998-sch];
}

void taoMangRd (int arr[], int min, int max)
{
	for(int i = min; i <= max ; i++)
	{
		if(min == 1 )
		{
			arr[i-1] = i;	
		}
		else if (min == 50001)
		{
			arr[i-50000-1] = i;
		}
	}
}




void Insert_node(NODEPTR &p, int x)
{ 
   if(p == NULL)    // nút p hi?n t?i s? là nút lá
   {
     p = new node;
     p->id  = x;     
     p->left = NULL;     p->right = NULL;  
   }
   else
    if(x < p->id )
      Insert_node(p->left, x);
    else if(x > p->id )	    Insert_node(p->right, x);
}
// Tao cay voi so node cay con ben trai = ben phai 
void Create_Tree(NODEPTR &root, int arr1[], int arr2[])
{ 
	int khoa;
	if(root == NULL) {
	    khoa = MAX/2;
	  	Insert_node(root,khoa);
	}
	
	for(int i=0;i<10000;i++) {
		if (countNode(root->left) < countNode(root->right))
		{
			int nt = countNode(root->left);
			khoa =	rdMang(arr1,nt);
		}
		else 
		{
			int np = countNode(root->right);
			khoa =	rdMang(arr2,np);
		
		}
	 	Insert_node(root,khoa);
	}

}

void Ghi_File(NODEPTR root) {
	ofstream fileOut;
 	
 	fileOut.open("SourceRDNumber.txt", ios_base :: out);
 	
 	fileOut << 10000 <<endl; // so luong number cua source
 	fileOut << 0 << endl; //ghi so luong phan tu da su dung
 	//duyet theo muc 
	NODEPTR p;
	q.Front=NULL; 
	q.Rear = NULL;
	
 	if (root!=NULL)	     Insert_queue(q, root); //chen nut goc vao hang doi
	  
	while (q.Front != NULL) {
	    p=Delete_queue(q);     	
		fileOut<<p->id<< " ";
	
	    if (p->left !=NULL)
	       Insert_queue(q,p->left);
    
	    if (p->right !=NULL)
	       Insert_queue(q,p->right);
	
	}
 
	fileOut.close();
}
void AddTreeToArray(NODEPTR root, int arr[], int size) {

	NODEPTR Stack[STACKSIZE];
	NODEPTR p = root;
	int sp = -1;	// Khoi tao Stack rong
	int i=0;
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
			arr[i] = p->id;
			i++;
			p = p->right;
		}
		else
			break;
	} while (1);
	
}

void convert(int arr[], int low, int high, NODEPTR &root) {
	if (low > high) {
        return;
    }	
    int mid = (low + high) / 2;

    root = newNode(arr[mid]);
    
    convert(arr, low, mid - 1, root->left);
 
    convert(arr, mid + 1, high, root->right);
}

 /*
 	 - Tao mang? ngau nhien tang dan` ( so 50000 o giua, so luong ben trai = ben phai ) 
 	 - Tu mang sorted ngau nhien o tren thuc hien convert sang BST balance
 	 - Duyet cay balance theo muc (dung` queue to chuc theo ds lien ket don)
 	 - Ghi file 
 */
int main() {	
	srand(time(NULL)); 

  	int arr1[49999]; //Tao mang 50000 phan tu ben trai tu 1 -> 49999
	int arr2[49999]; // Tao mang 50000 phan tu ben phai tu 50001 -> 99999
	taoMangRd(arr1,1,49999);  //Thuc hien random
	taoMangRd(arr2,50001,99999);
	Create_Tree(tree, arr1, arr2);
	
	int arr[10000]; //Day la mang source  
	AddTreeToArray(tree, arr, 10000); // add cay vay mang tao thanh mang sorted ( duyet cay theo LNR) 

	convert(arr,0,10000,tree); // Chuyen tu array to BST balance 
	Ghi_File(tree);

  return 0;
}

