#include"DSLK.h"
int main(){
	int n;
	ListSV DS ;
	ofstream f;
	while(true){
		system("cls");
		cout <<endl;
		cout <<"\t\t********************** QUAN LY SINH VIEN *********************"<<endl;
		cout <<setw(50) << left << "\t\t||		1. Nhap thong tin sinh vien"<< "||"<<endl;
		cout <<setw(50) << left << "\t\t||----------------------------------------------------------||"<<endl;
		cout <<setw(50) << left << "\t\t||		2. Chinh sua thong tin sinh vien"<<"||"<<endl;
		cout <<setw(50) << left << "\t\t||----------------------------------------------------------||"<<endl;
		cout <<setw(50) << left << "\t\t||		3. Xoa sinh vien"<<"||"<<endl;
		cout <<setw(50) << left << "\t\t||----------------------------------------------------------||"<<endl;
		cout <<setw(50) << left << "\t\t||		4. Tim sinh vien theo ten"<<"||"<<endl;
		cout <<setw(50) << left << "\t\t||----------------------------------------------------------||"<<endl;
		cout <<setw(50) << left << "\t\t||		5. Tim sinh vien theo ID"<<"||"<<endl;
		cout <<setw(50) << left << "\t\t||----------------------------------------------------------||"<<endl;
		cout <<setw(50) << left << "\t\t||		6. Sap xep sinh vien theo DTB"<<"||"<<endl;
		cout <<setw(50) << left << "\t\t||----------------------------------------------------------||"<<endl;
	    cout <<setw(50) << left << "\t\t||		7. Xuat danh sach hoc bong"<<"||"<<endl;
		cout <<setw(50) << left << "\t\t||----------------------------------------------------------||"<<endl;
		cout <<setw(50) << left << "\t\t||		8. Xuat thong tin sinh vien"<<"||"<<endl;
		cout <<setw(50) << left << "\t\t||----------------------------------------------------------||"<<endl;
		cout <<setw(50) << left << "\t\t||		9. Ghi du lieu vao file SV.txt"<<"||"<<endl;		
		cout <<setw(50) << left << "\t\t||----------------------------------------------------------||"<<endl;
		cout <<setw(50) << left << "\t\t||		0. THOAT!!"<<"||"<<endl;
		cout <<setw(50) << left << "\t\t**************************************************************"<<endl;
		cout <<setw(50) << left << "\t\t\t\tVui long chon: ";
		cin >>n;
		cin.ignore();
		if( n< 0 || n >9 ){
			cout <<endl;
			cout <<"\t\t\tTHONG BAO: Chon sai, vui long chon lai !!!"<<endl;
		}
		
	switch(n){
		case 1:
			DS.Add();
			system("pause");
			break;
		case 2:
			DS.CapNhat(); 
			system("pause");
			break;
		case 3:
			DS.removeSV();
			system("pause");
			break;
		case 4:
			DS.SearchName();
			system("pause");
			break;
		case 5:
			DS.SearchID();
			system("pause");
			break;
		case 6:
			DS.SapXepDTB4();
			system("pause");
			break;
		case 7:
			DS.DSHocBong();
			system("pause");
		case 8:
			DS.XuatDS();
			system("pause");
			break;
		case 9:
			DS.GhiFile(f, DS);
			system("pause");
			break;			
		case 0:
			exit(0);
			break;
	}
	}
	return 0;
}
