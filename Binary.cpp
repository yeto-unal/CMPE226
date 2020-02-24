#include<iostream>
#include<cassert>
#include<string>
#include<cctype>
#include"Student.h"

using namespace std;

struct Node{
	Student info;
	Node *llink;
	Node *rlink;
};

class Binary{
	protected:
		Node *root;
	public:
		Node* search(Student stu){
			Node *p;
    		bool found = false;
    		if(root == NULL) 
    			cerr << "No tree";
    		else{
        		p = root;
        		while(!found && p != NULL){
            		if(p->info.getNumber() == stu.getNumber())
            			found=true;
        			else if(stu.getNumber() < p->info.getNumber())
        				p = p->llink;
        			else
        			{
            		p = p->rlink;
        			}
        		}
    		}
    		return p;
		}
		
		void insert(Student stu){
			if(search(stu) == stu){
				cout << "The insert item is already in the list, duplicates are not allowed.";
				stu.printStudent();
			}
			else{
				Node *p,*q,*r;
    			r = new Node;
    			r->info = stu;
    			r->llink = r->rlink = NULL;
    			if(root==NULL)
    				root = r;
    			else {
        			p = root;
        			while(p != NULL){
            			q = p;
            			if(stu.getNumber() < p->info.getNumber())
            				p = p->llink;
            			else
            				p = p->rlink;
        			}
        			if(stu.getNumber() < q->info.getNumber())
        				q->llink = r;
        			else 
        				q->rlink = r;
    			}
			}
		}
};
