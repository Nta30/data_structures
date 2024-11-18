#include<iostream>
#include<string>
 using namespace std;
 //class Node
 template<class T>
 class node{
 	private:
 		T elem;		//gia tri ma node luu tru
 		node *next;	//con tro next tro den node tiep theo
 		node *prev;	//con tro prev tro den node dang truoc
 	public:
 		//constructor
 		//ham tao khong doi
	 	node(){}
	 	//ham tao gom doi la gia tri cua node, dia chi cua node sau, dia chi cua node truoc
		node(T x, node<T> *N = NULL, node<T> *P = NULL){
			elem = x;
			next = N;
			prev = P;			
		}
		//phuong thuc lay gia tri cua node
		T &getElem(){
			return elem;
		}
		//phuong thuc lay dia chi cua node tiep theo
		node<T>* &getNext(){
			return next;
		}
		//phuong thuc lay dia chi cua node phia truoc
		node<T>* &getPrev(){
			return prev;
		}
		//phuong thuc dat gia tri cho node
		void setElem(T x){
			elem = x;
		}
		//phuong thuc gan dia chi cho con tro next 
		void setNext(node<T> *N = NULL){
			next = N;
		}
		//phuong thuc gan dia chi cho con prev
		void setPrev(node<T> *P = NULL){
			prev = P;
		}	
 };
 
 //class iterator
 template<class T>
 class db_list_iterator{
 	private:
 		node<T> *current; //con tro tro den node hien tai trong danh sach
 	public:
 		//constructor
	 	db_list_iterator(){ //constructor khong doi
	 		current = NULL;	//khi khong co doi so, iterator se tro den NULL
		}
		db_list_iterator(node<T> *c){ //constructor co doi
			current = c; //current se tro den noi ma con tro c tro toi
		}
		node<T>* getCurr(){
			return current;
		}
		db_list_iterator &operator=(db_list_iterator<T> it){
			this->current = it.getCurr();
			return *this;
		}
		bool operator!=(db_list_iterator<T> it){
			return this->current!= it.getCurr();
		}
		db_list_iterator<T> operator++(){
			current = current->getNext();
			return *this;
		}
		db_list_iterator<T> operator++(int){
			db_list_iterator<T> temp = *this;
			current = current->getNext();
			return temp;
		}
		T &operator*() {
        	return current->getElem();
    	}
			
 };
 //class reverse_iterator
 template<class T>
 class db_list_reverse_iterator{
 	private:
 		node<T> *current;
 	public:
		db_list_reverse_iterator(){
			current = NULL;
		}
		db_list_reverse_iterator(node<T> *c){
			current = c;
		}
		node<T>* getCurr(){
			return current;
		}
		db_list_reverse_iterator &operator=(db_list_reverse_iterator<T> rit){
			this->current = rit.getCurr();
			return *this;
		}
		bool operator!=(db_list_reverse_iterator<T> rit){
			return this->current!=rit.getCurr();
		}
		db_list_reverse_iterator<T> operator++(){
			current = current->getPrev();
			return *this;
		}
		db_list_reverse_iterator<T> operator++(int){
			db_list_reverse_iterator<T> temp = *this;
			current = current->getPrev();
			return temp;
		}
		T &operator*(){
			return current->getElem();
		}	
 };
 //class dblist
 template<class T>
 class dblist{
 	private:
 		node<T> *head; //con tro tro vao dau danh sach
 		node<T> *tail; //con tro tro den cuoi danh sach
 		int num; //so luong node trong danh sach
	public:
		//constructor
		dblist(){
			head = tail = NULL; //khong co phan tu nen head va tail deu tro ve null
			num = 0;
		}
		dblist(int n, T x){
			head = tail = NULL;
			for(int i=0;i<n;i++){
				pushBack(x);
			}
		}
		//method
		//phuong thuc tra ve so phan tu cua danh sach
		int size(){
			return num;
		}
		//phuong thuc kiem tra xem danh sach co rong hay khong
		bool empty(){
			return num == 0;
		}
		//phuong thuc tra ve tham chieu den node dau tien cau danh sach
		T &front(){
			return head->getElem();
		}
		//phuong thuc tra ve tham chieu den node cuoi cung cua danh sach
		T &back(){
			return tail->getElem();
		}
		//phuong thuc them node vao dau danh sach
		void pushFront(T x){
			 node<T> *newNode = new node<T>(x); //tao 1 node moi voi gia tri x
			 if(num == 0){ //neu danh sach rong thi phan tu duoc them vao la phan tu duy nhat ->  no vua la phan tu dau vua la phan tu cuoi danh sach
			 	head = newNode;
			 	tail = newNode;
			 }else{
			 	newNode->setNext(head); //next tro toi node tiep theo
			 	head->setPrev(newNode); //prev cua node dau tien trong danh dach hien tai tro toi newNode
			 	head = newNode; //dua con tro head tro ve newNode de cap nhat lai node dau tien 
			 }
			 num++; //tang so luong phan tu trong danh sach
		}
		void pushBack(T x){
			if(num == 0){ //neu danh sach rong thi goi phuong thuc pushFront de them phan tu dau tien
				pushFront(x);
				return;
			}else{
				node<T> *newNode = new node<T>(x); //tao 1 node moi voi gia tri x
				tail->setNext(newNode); //next cua node cuoi cung trong danh sach hien tai tro toi newNode
				newNode->setPrev(tail); //prev cua newNode tro toi node cuoi cung trong danh sach hien tai
				tail = newNode; //dua con tro tail tro ve newNode de cap nhat lai node cuoi cung
				num++;
			}
		}
		void popFront(){
			if(num == 0) return; //neu danh sach rong thi khong lam gi ca
			node<T> *oldHead = head; //tao con tro oldHead de luu dia chi cua node dau tien
			if(num == 1){ //neu danh sach co 1 phan tu thi khi xoa di danh sach tro thanh rong
				head = NULL;
				tail = NULL;
			}else{ //neu danh sach co nhieu hon 1 phan tu
				head = head->getNext(); //cap nhat lai node dau cua danh sach
				head->setPrev(NULL); //prev cua node dau tro ve NULL
			}
			delete oldHead; //giai phong bo nho cho node vua xoa
			num--; //giam so luong phan tu
		}
		void popBack(){
			if(num == 0) return; //neu danh sach rong thi khong lam gi ca
			node<T> *oldTail = tail; //tao con tro oldTail de luu dia chi cua node cuoi cung
			if(num == 1){ //neu danh sach co 1 phan tu thi khi xoa di, no tro thanh rong
				head = NULL;
				tail = NULL;
			}else{ //neu danh sach co nhieu hon 1 phan tu
				tail = tail->getPrev(); //cap nhat lai node cuoi cung cua danh sach
				tail->setNext(NULL); //next cua node cuoi cung tro toi NULL
			}
			delete oldTail; //giai phong bo nho cho node vua xoa
			num--; //giam so luong phan tu
		}
		void insert(int k, T x){ //chen 1 node co gia tri x vao vi tri k trong danh sach
			if(k<0 ||k>num) return; //neu vi tri can chen < 0 va > so luong phan tu trong danh sach thi khong lam gi ca
			if(k==0) pushFront(x); //neu chen vao vi tri dau tien cua danh sach thi goi phuong thuc pushFront
			else if(k == num) pushBack(x); //neu chen vao vi tri cuoi cung cua danh sach thi goi phuong thuc pushBack
			else{ //neu chen vao giua danh sach
				node<T> *newNode = new node<T>(x); //tao ra 1 node moi voi gia tri la x
				node<T> *current = head; //tao ra 1 con tro current tro vao dau danh sach
				for(int i=0;i<k-1;i++){
					current = current->getNext(); //dua con tro current toi truoc node can chen
				}
				newNode->setNext(current->getNext()); //next cua newNode se tro toi dia chi cua node phia sau current
				newNode->setPrev(current); //prev cua newNode se tro toi dia chi cua current
				(current->getNext())->setPrev(newNode); //prev cua node phia sau current se tro toi newNode
				current->setNext(newNode); //next cua current hien tai se tro toi newNode
				num++;
			}
		}
		void erase(int k){ //xoa node tai vi tri k
			if(k<0 || k>=num) return; //neu vi tri can xoa < 0 va > so luong phan tu trong danh sach thi khong lam gi ca
			if(k==0) popFront(); //neu vi tri can xoa la o dau danh sach thi goi phuong thuc popFront
			else if(k==num-1) popBack(); //neu vi tri can xoa o cuoi danh sach thi goi phuong thuc popBack
			else{ //neu xoa o giua danh sach
				node<T> *current = head; //tao ra con tro current tro vao dau danh sach
				for(int i=0;i<k;i++){
					current = current->getNext(); //dua con tro current toi vi tri can xoa
				}
				(current->getNext())->setPrev(current->getPrev()); //prev cua node phia sau current se tro ve dia chi cua node phia truoc current
				(current->getPrev())->setNext(current->getNext()); //next cua node phia truoc current se tro ve dia chi cua node phia sau current
				delete current; //giai phong bo nho cho node vua xoa
				num--; //giam so luong phan tu
			}
		}
		typedef db_list_iterator<T> iterator;
		iterator begin() {
        	return iterator(head);
    	}

    	iterator end() {
        	return iterator(NULL);
    	}
		typedef db_list_reverse_iterator<T> reverse_iterator;
    	reverse_iterator rbegin() {
        	return reverse_iterator(tail);
    	}
    	reverse_iterator rend() {
        	return reverse_iterator(NULL);
    	}
		
 };
 int main(){
 	
 }
