/*************************************************************************
	> File Name: fen.cpp
	> Author: FuQiang
	> Mail: fq@neusoft.com 
	> Created Time: 2018年11月03日 星期六 16时42分10秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
class Alloc{
public:
	Alloc(int mylen){
		index = 0;
		len = mylen;
	}
	void findEmpty(int *arry){
		for(int i =0 ; i<len ; i++){
			if(arry[i] == -1){
				index = i;
				break;
			}
		}
	}
	
	void insertVal(int *arry,int val){
		findEmpty(arry);
		arry[index] = val;
		index++;
	}
	
	void deleteVal(int *arry,int val){
		for(int i =0 ; i< len ; i++){
			if(arry[i] == val){
				arry[i] = -1;
			}
		}
	}
public:
	int index;
	int len;
};


int main(int argc, char *argv[])
{
	int myArry[10] = {0};
	
	Alloc *alloc = new Alloc(10);
	memset(myArry,-1,alloc->len*sizeof(int));
	
	alloc->insertVal(myArry,0);
	alloc->insertVal(myArry,1);
	alloc->insertVal(myArry,2);
	alloc->insertVal(myArry,3);
	
	cout<<"注册0,1,2,3通道号"<<endl;
	
	for(int i = 0; i< 10; i++){
		cout<< myArry[i]<< "	";
	}
	
	cout<<endl;
	
	cout<<"注销2号通道" << endl;
	
	alloc->deleteVal(myArry,2);
		for(int i = 0; i< 10; i++){
		cout<< myArry[i]<< "	";
	}
	
	cout<<endl;
	
	cout<<"重新分配666号通道，插入到以前2号通道的位置" <<endl;
	
	alloc->insertVal(myArry,666);
		
	for(int i = 0; i< 10; i++){
		cout<< myArry[i]<< "	";
	}
	
	cout<<endl;
	
	delete alloc;

	return 0;
}

