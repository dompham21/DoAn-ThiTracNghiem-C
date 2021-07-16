//#pragma once
//
//
//
//struct DeThi {
//	char maLop[16];
//	
//};
//
//struct DanhSachDeThi {
//	DeThi *dt[MAXLOP];
//	int soLuong;
//};
//
//void Insert_First_DeThi(PTRDeThi &FirstDeThi, DeThi ctdt)
//{
//	cout<<ctdt.idcauthi<<endl;
//   PTRDeThi p;
//   p = new NodeDeThi;
//   p->ctdt = ctdt;
//   p->next = FirstDeThi;
//   FirstDeThi = p;
//}
//
////thêm mot sinh vien vào sau mot nut dia chi p
//void Insert_after_DeThi( PTRDeThi p, DeThi ctdt)
//{
//   PTRDeThi q;
//   if(p == NULL)
//		cout<<"khong them phan tu vao danh sach duoc"<<endl;
//   else
//   { 
//   		q = new NodeDeThi;
//    	q->ctdt = ctdt;
//      	q->next = p->next;
//      	p->next = q;
//   }
//}
//
//
//
//
//void themMotDeThi(PTRDeThi &FirstDeThi, DeThi ctdt)
//{
//
//	if(FirstDeThi == NULL)
//	{
//		cout<<"B"<<endl;
//		Insert_First_DeThi(FirstDeThi, ctdt);
//
//	}
//	else 
//	{
//		cout<<"C"<<endl;
//		PTRDeThi nodeChay;
//		nodeChay = new NodeDeThi;
//		nodeChay = FirstDeThi;
//		while( nodeChay->next != NULL){
//	        nodeChay = nodeChay->next;
//		}
//		Insert_after_DeThi(nodeChay,ctdt);	
//		
//	}
//
//}
//
//
//void xuatDsDeThi(PTRDeThi FirstDeThi) {
//    PTRDeThi nodeChay;
//	nodeChay = new NodeDeThi;
//	nodeChay = FirstDeThi;
//	
//    while(nodeChay != NULL){
//        cout<<"Hoten: "<<nodeChay->ctdt.idcauthi<<", Maso: "<<nodeChay->ctdt.maMH<<endl;
//        nodeChay = nodeChay->next;
//    }
//   
//
//}
