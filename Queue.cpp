#include<iostream>
#include<queue>

using namespace std;

main(){
	queue<int> myq;
	myq.push(5);
	myq.push(13);
	myq.push(0);
	myq.push(9);
	myq.push(4);
	while(!myq.empty()){
		cout<<"myq="<<myq.front()<<endl;
		myq.pop();
	}
	
}
