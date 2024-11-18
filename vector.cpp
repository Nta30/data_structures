#include<iostream>
 using namespace std;
 
 template<class T>
 class my_vector_reverse_iterator{
 	private:
 		T* curr;
 	public:
 		//constructor
	 	my_vector_reverse_iterator(T* c = 0){
	 		curr = c;	
		}
		//method
		my_vector_reverse_iterator<T> &operator=(my_vector_reverse_iterator<T> &it){
			this->curr = it.curr;
			return *this;
		}
		my_vector_reverse_iterator<T> &operator++(){
			curr--;
			return *this;
		}
		my_vector_reverse_iterator<T> operator++(int){
			my_vector_reverse_iterator<T> temp = *this;
			curr--;
			return temp;
		}
		T &operator*(){
			return *curr;
		}
		bool operator!=(my_vector_reverse_iterator<T> it){
			return this->curr!=it.curr;
		}
 };
 
 template<class T>
 class my_vector{
 	private:
 		T *buff;
 		int num,cap;
 	public:
	 	//constructor
		my_vector(){
			num = 0;
			cap = 1;
			buff = new T[cap];
		}
		my_vector(int n){
			num = cap = n;
			buff = new T[n];
		}
		my_vector(int n, T x){
			num = cap = n;
			buff = new T[n];
			for(int i=0;i<num;i++){
				buff[i] = x;
			}
		}
		//deconstructor
		~my_vector(){
			if(buff){
				delete []buff;
			}
		}
		//method
		int capacity(){
			return cap;
		}
		int size(){
			return num;
		}
		bool empty(){
			return num==0;
		}
		void pop_back(){
			if(num>0) num--;
		}
		void extend(int new_cap){
			if(new_cap < cap){
				return;
			}
			cap = new_cap;
			T *temp = new T[cap];
			for(int i=0;i<num;i++){
				temp[i] = buff[i];
			}
			if(buff){
				delete []buff;
			}
			buff = temp;
		}
		void push_back(T x){
			if(num == cap){
				extend(cap*2);
			}
			buff[num] = x;
			num++;
		}
		void insert(int k, T x){
			if(num == cap){
				extend(cap*2);
			}
			for(int i=num-1; i>=k; i--){
				buff[i+1] = buff[i];
			}
			buff[k] = x;
			num++;
 		}
		void erase(int k){
		 	if(k<0 ||k>=num){
		 		return;
			}
			for(;k<num;k++){
				buff[k] = buff[k+1];
			}
			num--; 
		}
		T &back(){ //tra ve tham chieu den phan tu cuoi de co the thay doi //vd: v.back() = x;
			return buff[num-1];
		}
		T &operator[](int k){
			return buff[k];
		}
		typedef T* iterator; //dinh nghia lai iterator la T*
		iterator begin(){ // tra ve 1 con tro co kieu du lieu la T 
			return buff; // tra ve con tro tro den phan tu dau tien cua vector
		}
		iterator end(){
			return buff+num;
		}
		typedef my_vector_reverse_iterator<T> reverse_iterator; //dinh nghia lai reverse_iterator la my_vector_reverse_iterator
		reverse_iterator rbegin(){ //tra ve 1 con tro co kieu du lieu la my_vector_reverse_iterator
			return reverse_iterator(buff + num - 1);
		}
		reverse_iterator rend(){
			return reverse_iterator(buff - 1);
		}		 	
 };
 
int main(){

}

