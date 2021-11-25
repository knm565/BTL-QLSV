#include"DSLK.h"
ListSV::ListSV(){
	head = NULL;
	tail = NULL;
	size = 0;
}
ListSV::~ListSV(){
	
}

Node* ListSV::CreateNode(ThongTinSV sv){
	Node* p = new Node;
	p->data = sv;
	p->next = NULL;
	return p;
}

/*bool ListSV::check(string x){
	for (Node*p = head; p!= NULL; p = p->next){
		if (p->data.getMSSV() == x)
		    return 1;
	}
	return 0;
}*/
void ListSV::Add(){
	ThongTinSV sv;
	cout<<endl;
	cout <<"\tNHAP THONG TIN SINH VIEN"<<endl<<endl;
	sv.Nhap();
	Node*p = CreateNode(sv);
	if(size == 0){
		head = p;
		tail = p;
	}
	else{
		tail->next = p;
		tail = p;
	}
	size++;
}
Node* ListSV::previous(Node *p) {
	Node *t = head;
	while (t->next != p)
		t = t->next;
	return t;
}
void ListSV::removeFirst(){
	if(size == 0){
		cout << "\tDANH SACH RONG!!!" << endl;
		return;
	}
	Node *p = head;
	head = head->next;
	delete p;
	size--;
}
void ListSV::removeLast(){
	if(size == 0){
		cout << "\tDANH SACH RONG!!!" << endl;
		return;
	}
	if(size == 1){
	    delete head;
	    size--;
	    return;
    }
    Node *p = previous(tail);
	Node *t = tail;	
	p->next = NULL;
	tail = p;
	delete t;
	size--;
}
void ListSV::removeSV(){
	string a;
	if(size == 0){
		cout << "\tDANH SACH RONG!!" << endl;
		return;
	}
	cout << "\tNhap MSSV cua SV can xoa: " << endl;
	getline(cin, a);
	if(head->data.getMSSV() == a){
		removeFirst();
		cout << "\t Da xoa!!" << endl;
		return;
	}
	if(tail->data.getMSSV() == a){
		removeLast();
		cout << "\t DA XOA!!" << endl;
		return;
	}
	for(Node*t = head; t != NULL; t = t->next){
		if(t->data.getMSSV() == a){
	        Node *p = t->next;
	        t->next = p->next;
	        delete p;
	        size--; 
	        cout << "\t Da xoa!!" << endl;
            return;
        }
    }
    cout << "Khong tim thay MSSV!!" << endl;
    return;
}
void ListSV::SearchID(){
	string msv;
	int i =0;
	cout << "\tTIM KIEM SINH VIEN" << endl;	
	if( size == 0 ){
		cout <<"\tDANH SACH RONG!!"<<endl;
		return;
	}
	cout <<"\tNhap ma so sinh vien can tim: ";
	getline(cin, msv);
	TenCot();
	for(Node *p = head; p != NULL; p = p->next ){
		if( p->data.getMSSV()== msv ){
			i++;
			cout << "\t" << "|" << setw(4) << left <<i;
			p->data.Xuat();
			return;
		}
	}
	cout << "Khong tim thay MSSV can tim!!" << endl;
	return;
}
void ListSV::SearchName(){
	string name;
	int i = 0;
	int dem = 0;
	cout << "\tTIM KIEM SINH VIEN" << endl;	
	if( size == 0 ){
		cout <<"\tDANH SACH RONG!!"<<endl;
		return;
	}
	cout <<"\tNhap ten sinh vien can tim: ";
	getline(cin, name);
	TenCot();
	for(Node *p = head; p != NULL; p = p->next ){
		if( p->data.getName()== name ){
			i++;
			cout << "\t" << "|" << setw(4) << left <<i;
			p->data.Xuat();
			dem++;
		}
	}
	if(dem == 0){
	        cout << "Neu khong tim ten SV can tim!!" << endl;
		return;
	}
	return;
}
void ListSV::CapNhat(){
	ThongTinSV sv;
	string id;
	Node *p;
	cout << "\tCAP NHAT SINH VIEN" << endl;		
	if ( size == 0 ){
		cout <<"\tDANH SACH RONG!!"<<endl;
		return;
	}			
	cout <<"\t\tNhap ID sinh vien can chinh sua:";
	getline(cin, id);
	for(Node *k = head; k != NULL; k = k->next){
		if( k->data.getMSSV() == id ){
			cin.ignore();
			sv.Nhap();
			k->data = sv;
			return;
		}
	}
	cout << "Khong tim thay MSSV!!" <<endl;
	return;
}
void ListSV::SapXepDTB4(){
	for(Node *k = head; k != NULL; k = k->next){
		for(Node *t = k->next; t != NULL; t = t->next){
			if( k->data.getDiem().getDTB4() < t->data.getDiem().getDTB4() ){
				swap( k->data, t->data );
			}
			else if(k->data.getDiem().getDTB4() == t->data.getDiem().getDTB4()){
				SoSanhDTB10(k,t);
			}
		}
	}
}
void ListSV::SoSanhDTB10(Node* p, Node* q){
	if(p->data.getDiem().getDTB10() < q->data.getDiem().getDTB10()){
		swap(p->data, q->data);
	}
}
void ListSV::XuatDS(){
	if(size == 0){
		cout <<"\tDANH SACH RONG"<<endl;
	}
	int i=0;
	cout << "\tDANH SACH SINH VIEN" << endl;
	TenCot();
	for(Node *p = head; p != NULL ; p = p->next){
		cout<<endl;
		i++;
		cout<<"\t" << "|" << setw(4) << left << i;
		p->data.Xuat();
	}
}
void ListSV::GhiFile(ofstream &f, ListSV list){
	f.open("SV.txt", ios::out);
	string t = "; ";
	string i = "/";
	string n = "/n";
	for (Node *k = head; k != NULL; k = k->next){
		f << k->data.getMSSV();
		f << t;
		f << k->data.getHo();
		f << t;
		f << k->data.getName();
		f << t;
		f << k->data.getGTinh();
		f << t;
		f << k->data.getNS().getNgay();
		f << i;
		f << k->data.getNS().getThang();
		f << i;
		f << k->data.getNS().getNam();
		f << t;
		f << k->data.getQueQuan();
		f << t;
		f << k->data.getLop().getNganh();
		f << t;
		f << k->data.getLop().getKhoa();
		f << t;
		f << k->data.getLop().getTLop();
		f << t;
		f << k->data.getDiem().getDTB4();
		f << t;
		f << k->data.getDiem().getDTB10();
		f << t;
		f << k->data.getDiem().getDRL();
		f << n;
	}
	f.close();
}
/*void ListSV::SapXepTen(){
	for(Node *k = head; k != NULL; k = k->next){
		for(Node *t = k->next; t != NULL; t = t->next){
			if (strcmp((k->data.getName().c_str(),t->data.getName().c_str())>0))
			    swap( k->data, t->data );

		}
		   
}*/
void ListSV::DSHocBong (){
	int n = 0;
	int x = 0;
	cout << "\tDANH SACH HOC BONG" << endl;
	if(size%10 != 0){
		n = size/10 +1;
	}
	else {
		n = size/10;
	}
	if (size / 10 == 0){
		n++;
	};
	TenCot();
	for (int i = 0; i < n; i++){
		Node *k = head;
		x++;
		cout<<"\t" << "|" << setw(4) << left << x;
		k->data.Xuat();
		k=k->next;
    }
}
