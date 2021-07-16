struct Hour {
	int hour;
	int minute;
	int second;
};

char inToA(int k) {
	switch (k)
	{
	case 0:return '0';
	case 1:return '1';
	case 2:return '2';
	case 3:return '3';
	case 4:return '4';
	case 5:return '5';
	case 6:return '6';
	case 7:return '7';
	case 8:return '8';
	case 9:return '9';
	default:
		break;
	}
}

void chuyenSoPhut(Hour &h, int soPhut) {
	int giay = soPhut *60;
	if(giay < 60) {
		h.hour = 0;
		h.minute = 0;
		h.second = giay;
	}
	else if(giay >=60 && giay<3600 ) { // 59 phut
		h.minute = (giay-giay%60)/60;
        giay %= 60;
        h.second = giay;
        h.hour = 0;
	}
	else {
		h.hour = (giay-giay%3600)/3600;
        h.minute =((giay%3600)-(giay%3600)%60)/60;
        h.second = giay- h.minute*60-h.hour*3600;
	}
}

void chenVaoMang(char *h, Hour &j) {
	int temp = 0;
	temp = j.second;
	
	h[7] = inToA(temp % 10);
	h[6] = inToA(temp /= 10);

	temp = j.minute;
	h[4] = inToA(temp % 10);
	h[3] = inToA(temp /= 10);

	temp = j.hour;
	h[1] = inToA(temp % 10);
	h[0] = inToA(temp /= 10);

}

bool thayDoiTime(Hour &h) {
	
	if (h.second > 0) --h.second; //giam di 1 giay
	else if (h.minute > 0) {          //giay = 0 => giay = 59, giam di 1 phut
		h.second = 59;
		--h.minute;
	}
	else if (h.hour > 0)  
	{
		--h.hour;
		h.minute = 59;
		h.second = 59;
	}
	else return 0; // Neu khong thay doi gi thi tra ve false
	return 1; // Thay doi xong tra ve true
}
