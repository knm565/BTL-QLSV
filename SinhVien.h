#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class SinhVien{
	public:
		virtual void Nhap() = 0;
		virtual void Xuat() = 0;
};
//--------------------------------------------------------

//----------------------------------------------------------------
class DIEM:public SinhVien{
	private:
		float DTB4;
		float DTB10;
		int DRL;
	public:
		DIEM();
		~DIEM();
		
		float getDTB4();
		float getDTB10();
		int getDRL();
		
		void Nhap();
		void Xuat();
		
		
};
class LOP: public SinhVien{
	private:
		string nganh;
		string tenlop;
		unsigned int khoa;
	public:
		LOP();
		~LOP();
		
		void Nhap();
		void Xuat();
		
        string getNganh();
        string getTLop();
        int getKhoa();
};
class NTN:public SinhVien{
	private:
		unsigned int ngay;
		unsigned int thang;
		unsigned int nam;
	public:
		NTN();
		~NTN();
		
		bool checkNTN();		
		void Nhap();
		void Xuat();
		
		int getNgay();
		int getThang();
		int getNam();
};
class ThongTinSV:public SinhVien{
	private:
		string MSSV;
		string ho;
		string ten;
		string gtinh;
		string quequan;
		LOP lop;
		DIEM diem;
		NTN ns;
	public:
		ThongTinSV();
		~ThongTinSV();
		
		string getMSSV();
		string getHo();
		string getName();
		string getGTinh();
		string getQueQuan();
		DIEM getDiem();
		LOP getLop();
		NTN getNS();
		
		void Nhap();
		void Xuat();
		
};
void TenCot(); 
