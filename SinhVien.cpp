#include"SinhVien.h"
DIEM::DIEM(){
	DTB4 = 0;
	DTB10 = 0;
	DRL = 0;
}
DIEM::~DIEM(){
	
}
int DIEM::getDRL(){
	return DRL;
}
float DIEM::getDTB4(){
	return DTB4;
}
float DIEM::getDTB10(){
	return DTB10;
}
void DIEM::Nhap(){
	do{
	cout <<"\tDiem trung binh he 4: ";
	cin >> DTB4;
	cout <<"\tDiem trung binh he 10: ";
	cin >> DTB10;
	cout <<"\tDiem ren luyen: ";
	cin >> DRL;
	cin.ignore();
    }
    while(DTB4 < 0 or DTB4 >4 or DTB10 <0 or DTB10 >10 or DRL <0 or DRL> 100);
	
}
void DIEM::Xuat(){
	cout <<"\t" << "|"<<setw(10) <<left <<DTB4;
	cout <<"\t" << "|"<<setw(10) <<left <<DTB10;	
	cout <<"\t" << "|"<<setw(10) <<left <<DRL;	
}
//-----------------------------------------------------------------------
LOP::LOP(){
	tenlop = "";
	nganh = "";
	khoa = 0;
}
LOP::~LOP(){
	
}
void LOP::Nhap(){
	cout << "\tNhap ten lop: ";
	getline(cin, tenlop);
	cout << "\tNhap nganh hoc: ";
	getline(cin, nganh);
	cout <<"\tKhoa hoc: ";
	cin >> khoa;
	
}
void LOP::Xuat(){
    cout << "\t" << "|" << setw(10) << left << tenlop;
	cout << "\t" << "|" << setw(4) << left << khoa;
}
int LOP::getKhoa(){
	return khoa;
}
string LOP::getTLop(){
	return tenlop;
}
string LOP::getNganh(){
	return nganh;
}
//--------------------------------------------------------------------------
NTN::NTN(){
	ngay = 0;
	thang = 0;
	nam = 0;
}
NTN::~NTN(){
	
}
bool NTN::checkNTN(){
	if (nam % 100 == 0){
		int x = nam / 100;
		if (x % 4 == 0){
			if(thang < 1 or thang >12 )
			    return 0;
			else {
				if(thang == 2){
					if (ngay > 29 or ngay < 1){
				        return 0;
					}
				}
				else if (thang == 4 or thang == 6 or thang == 9 or thang == 11){
					if (ngay > 30 or ngay < 1){
						return 0;
					}			
				}
				else if (thang == 1 or thang == 3 or thang == 5 or thang == 7 or thang == 8 or thang == 10 or thang == 12){
					if (ngay > 31 or ngay < 1){
						return 0;
					}			
			   }
		    }
		}
	}
	else if (nam % 4 == 0){
		if(thang < 1 or thang >12 )
			    return 0;
		else {
			if(thang == 2){
				if (ngay > 29 or ngay < 1){
				    return 0;
				}
			}
			else if (thang == 4 or thang == 6 or thang == 9 or thang == 11){
				if (ngay > 30 or ngay < 1){
					return 0;
				}			
			}
			else if (thang == 1 or thang == 3 or thang == 5 or thang == 7 or thang == 8 or thang == 10 or thang == 12){
				if (ngay > 31 or ngay < 1){
					return 0;
				}			
			}
		}
	}
	else {
	    if(thang < 1 or thang >12 )
			return 0;
		else {
			if(thang == 2){
				if (ngay > 28 or ngay < 1){
				    return 0;
				}
			}
			else if (thang == 4 or thang == 6 or thang == 9 or thang == 11){
				if (ngay > 30 or ngay < 1){
					return 0;
				}			
			}
			else if (thang == 1 or thang == 3 or thang == 5 or thang == 7 or thang == 8 or thang == 10 or thang == 12){
				if (ngay > 31 or ngay < 1){
					return 0;
				}			
			}
		}	
	}
	return 1;
}
void NTN::Nhap(){
	do{
		cout << "\t\tNgay: ";
	    cin >> ngay;
	    cout << "\t\tThang: ";
	    cin >> thang;
	    cout << "\t\tNam: ";
	    cin >> nam;
	}
	while(checkNTN() == 0);
}
void NTN::Xuat(){
	cout << "\t" << "|" << ngay << "/" << thang << "/" << nam << "  ";
}
int NTN::getNam(){
	return nam;
}
int NTN::getNgay(){
	return ngay;
}
int NTN::getThang(){
	return thang;
}
//---------------------------------------------------------------------------
ThongTinSV::ThongTinSV(){
	MSSV = "";
	ho = "";
	ten = "";
	gtinh = "";
	quequan = "";
}
ThongTinSV::~ThongTinSV(){
	
}
void ThongTinSV::Nhap(){
	cout <<"\tNhap Ho: ";
	getline(cin, ho);
	cout <<"\tNhap Ten: ";
	getline(cin, ten);
	cout <<"\tMa so sinh vien: ";
	getline(cin, MSSV);
	cout <<"\tGioi tinh: ";
	getline(cin, gtinh);
	cout <<"\tQue quan: ";
	getline(cin, quequan);
	cout <<"\tNhap ngay thang nam sinh: "<<endl;
    ns.Nhap();
	diem.Nhap();
	lop.Nhap();
}
void ThongTinSV::Xuat(){
	cout << "\t" << "|" << setw(11) << left << MSSV;
	cout << "\t" << "|" << setw(20) << left << ho;
	cout << "\t" << "|" << setw(8) << left << ten;
	cout << "\t" << "|" << setw(9) << left << gtinh;
    ns.Xuat();
	cout << "\t" << "|" << setw(20) << left << quequan;
	lop.Xuat();
    diem.Xuat();
	cout << "|"	<< endl;	
	cout<<"\t--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"<<endl;

}
string ThongTinSV::getMSSV(){
	return MSSV;
}
string ThongTinSV::getHo(){
	return ho;
}
string ThongTinSV::getName(){
	return ten;
}
string ThongTinSV::getGTinh(){
	return gtinh;
}
string ThongTinSV::getQueQuan(){
	return quequan;
}
LOP ThongTinSV::getLop(){
	return lop;
}
NTN ThongTinSV::getNS(){
	return ns;
}
DIEM ThongTinSV::getDiem(){
	return diem;
}
//------------------------------------------------------------------------------------------------
void TenCot(){
	cout << endl;
	cout << "\t--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "\t" << "|" << setw(4) << left << "STT";
	cout << "\t" << "|" << setw(11) << left << "MSSV";
	cout << "\t" << "|" << setw(20) << left << "Ho";
	cout << "\t" << "|" << setw(8) << left << "Ten";
	cout << "\t" << "|" << setw(9) << left << "Gioi Tinh";
	cout << "\t" << "|" << setw(12) << left << "Nam Sinh";
	cout << "\t" << "|" << setw(20) << left << "Que Quan";
	cout << "\t" << "|" << setw(10) << left << "Lop";
	cout << "\t" << "|" << setw(4) << left << "Khoa";
	cout << "\t" << "|" << setw(10) << left << "DTB he 4";
	cout << "\t" << "|" << setw(10) << left << "DTB he 10";
	cout << "\t" << "|" << setw(10) << left << "DRL";
	cout << "|"	<< endl;
	cout << "\t--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}
//---------------------------------------------------------------------------
