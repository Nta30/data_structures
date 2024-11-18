#include<iostream>
 using namespace std;
 
 template<class T>
 class stack{
 	private:
 		int num,cap;
 		T *buff;
 	public:
	 	stack(){
	 		num = cap = 0;
			buff = NULL;	
		}
		~stack(){
			if(buff){
				delete []buff;
			}
		}
		int size(){
			return num;
		}
		bool empty(){
			return num==0;
		}
		T &top(){
			return buff[num-1];
		}
		void pop(){
			if(num > 0){
				num--;
			}
		}
		void push(T x){
			if(num == cap){
				if(cap == 0){
					cap = 1;
				}else{
					cap = cap*2;
				}
				T *temp = new T[cap];
				for(int i=0;i<num;i++){
					temp[i] = buff[i];
				}
				if(buff){
					delete []buff;
				}
				buff = temp;
			}
			buff[num++] = x;
		}
		void clear(){
			num = cap = 0;
			delete []buff;
			buff = NULL;
		}		
 };
 int main() {

}
