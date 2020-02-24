#include<iostream>
#include<stack>

using namespace std;

main(){
	stack<int> mystack,ostack;
	mystack.push(0);
	mystack.push(1);
	mystack.push(2);
	mystack.push(3);
	mystack.push(4);
	mystack.push(5);
	mystack.push(6);
	mystack.push(7);
	mystack.push(8);
	mystack.push(9);
	mystack.push(10);
	mystack.push(11);
	mystack.push(12);
											
	
	while(!mystack.empty()){
		cout<<"mystack="<<mystack.top()<<endl;
		ostack.push(mystack.top());
		mystack.pop();
	}
	cout<<"------------------"<<endl;
	while(!ostack.empty()){
		cout<<"ostack="<<ostack.top()<<endl;
		ostack.pop();
	}
}
