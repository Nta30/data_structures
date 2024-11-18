#include<iostream>
#include<string>
#include<fstream>
 using namespace std;
 
 template<class T>
 class node{
 	private:
 		node *next;
 		T elem;
 	public:
 		//constructor
	 	node(){}
		node(T x, node<T> *N = NULL){
			elem = x;
			next = N;
		}
		//method
		T &getElem(){
			return elem;	
		}
		node<T>* &getNext(){
			return next;
		}
		void setElem(T x){
			elem = x;
		}
		void setNext(node<T> *N){
			next = N;
		}	
 };
 
 template<class T>
 class list_iterator{
 	private:
 		node<T> *current;
 	public:
 		list_iterator(){
 			current = NULL;	
		}
		list_iterator(node<T> *c = NULL){
			current = c;
		}
		node<T>* getCurr(){
			return current;
		}
		list_iterator<T> &operator=(list_iterator<T> it){
			this->current = it.getCurr();
			return *this;
		}
		bool operator!=(list_iterator<T> it){
			return this->current!=it.getCurr();
		}
	 	list_iterator &operator++(){
	 		current = current->getNext();
			return *this;	
		}
		list_iterator operator++(int){
			list_iterator<T> temp = *this;
			current = current->getNext();
			return temp;
		}
		T &operator*(){
			return current->getElem();
		}	
 };
 
 
 template<class T>
 class list{
 	private:
 		node<T> *head;
 		node<T> *tail;
 		int num;
 	public:
 		//constructor
	 	list(){
	 		head = tail = NULL;
	 		num = 0;
		}
		list(int n, T x){
			head = tail = NULL;
			num = n;
			for(int i=0;i<num;i++){
				push_back(x);
			}
		}
		//method
		int size(){
			return num;
		}
		bool empty(){
			return num==0;
		}
		T &front(){
			return head->getElem();
		}
		T &back(){
			return tail->getElem();
		}
		void push_front(T x){
			node<T> *new_node = new node<T>(x);
			new_node->setNext(head);
			head = new_node;
			if(num==0) tail = head;
			num++;
		}
		void push_back(T x){
			if(num == 0) push_front(x);
			else{
				node<T> *new_node = new node<T>(x);
				tail->setNext(new_node);
				tail = new_node;
				num++;
			}	
		}
		void pop_front(){
			if(num==0) return;
			node<T> *old_head = head;
			if(num == 1){
				head = NULL;
				tail = NULL;
			}else{
				head = head->getNext();
			}
			delete old_head;
				num--;
		}
		void pop_back(){
			if(num==0) return;
			node<T> *old_tail = tail;
			if(num == 1){
				head = NULL;
				tail = NULL;
			}else{
				node<T> *current = head;
				while(current->getNext() != tail){
					current = current->getNext();
				}
				current->setNext(NULL);
				tail = current;	
			}
			delete old_tail;
			num--;
		}
		void insert(int k, T x){
			if(k<0 ||k>num) return;
			if(k==0) push_front(x);
			else if(k == num){
				push_back(x);
			}else{
				node<T> *new_node = new node<T>(x);
				node<T> *current = head;
				for(int i=0;i<k-1;i++){
					current = current->getNext();
				}
				new_node->setNext(current->getNext());
				current->setNext(new_node);
				num++;
			}
		}
		void erase(int k){
			if(k<0 || k>=num) return;
			if(k==0){
				pop_front();
			}else if(k == num - 1){
				pop_back();
			}else{
				node<T> *current = head;
				for(int i=0;i < k-1; i++){
					current = current->getNext();
				}
				node<T>	*old_node = current->getNext();
				current->setNext(old_node->getNext());
				delete old_node;
				num--;
			}
		}
		typedef list_iterator<T> iterator;
		iterator begin(){
			return iterator(head);
		}
		iterator end(){
			return iterator(NULL);
		}	
 };
 int main(){
 	
 }
 
