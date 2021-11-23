#include"SinhVien.h"
class Node{
	private:
		ThongTinSV data;
		Node *next;
	public:
		friend class ListSV;
};
class ListSV{
	private:
		Node *head;
		Node *tail;
		int size ;
	public:
		ListSV();
		~ListSV();
		
		Node *CreateNode(ThongTinSV sv);
		
		void Add();
		void CapNhat();
		Node *previous(Node *p);
		
		void removeFirst();
		void removeLast();
		void removeSV();
		
		bool check(string x);
		void SearchID();
		void SearchName();
		
		void SapXepDTB4();
		void SoSanhDTB10(Node* p, Node* q);
		//void SapXepTen();
		void SapXepMSSV();
		void DSHocBong();
		
		void XuatDS();
		void GhiFile(ofstream &f, ListSV list);
};
