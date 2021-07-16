#include <iostream>
#include <winbgim.h> 
#include "DefineValues.h"
#include "SinhVien.h"
#include "DoHoa.h"
#include "function.h"
#include "Lop.h"
#include "MonHoc.h"
#include "CauHoiThi.h"
#include "DocGhi.h"
#include <thread>

int main(int argc, char *argv[])
{


	DanhSachLop dsLop;
	dsLop.soLuong = 0;
	DanhSachMonHoc dsMonHoc;
	dsMonHoc.soLuong = 0;
	
	PTRCauHoi rootTree;
	
	InitTree(rootTree);  //khoi tao cay nhi phan 
	/*===Doc du lieu===*/
	docFileDSMonHoc(dsMonHoc);
	docFileDSLop(dsLop);
	docFileDSCauHoi(rootTree);
	

	
	drawMainFrame(dsLop, dsMonHoc, rootTree);
	
	
	return 0;
}
