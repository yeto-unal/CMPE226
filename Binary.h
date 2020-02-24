#include<iostream>
#include<cassert>
#include<string>
#include<cctype>
#include"Student.h"

using namespace std;

struct Node{
	string number;
	string fname;
	string sname;
	int gr;
	Node *llink;
	Node *rlink;
};

class Binary{
	protected:
		Node *root;
	public:
		Binary(){
			root = NULL;
		}
		
		bool search(Student stu){
			
			Node *p;
    		bool found = false;
        		p = root;
        		while(!found && p != NULL){
            		if(p->gr == stu.getGrade())
            			found = true;
        			else if(stu.getGrade() < p->gr)
        				p = p->llink;
        			else
        			{
            			p = p->rlink;
        			}
        		}
    		return found;
    		
		}
		
	void insert(Student stu){
			if(root == NULL){
				Node *r = new Node;
				r->number = stu.getNumber();
				r->fname = stu.getName();
				r->sname = stu.getSname();
				r->gr = stu.getGrade();
				r->llink = r->rlink = NULL;
				root = r;
			}
			else if(search(stu)){
				cout << "The insert item is already in the list, duplicates are not allowed.";
				stu.printStudent();
			}
			else{
				Node *r = new Node;
				r->number = stu.getNumber();
				r->fname = stu.getName();
				r->sname = stu.getSname();
				r->gr = stu.getGrade();
				r->llink = r->rlink = NULL;
				insertNode(r);
			}
			
		}
	
	void insertNode(Node* newnode){
   		Node *p,*q,*r;
        r = new Node;
    	r = newnode;
    	if(root==NULL)
    		root=r;
    	else{
        	p = root;
        	while(p != NULL){
            	q = p;
            	if(r->gr < p->gr)
            		p = p->llink;
            	else
            		p = p->rlink;
        	}
        	if(r->gr < q->gr)
        		q->llink = r;
        	else 
        		q->rlink = r;
    	}
	}
	
	void postordert(Node *p){
    	if(p != NULL){
        	postordert(p->llink);
        	postordert(p->rlink);
        	
        	cout << p->number << "  ";
			cout << p->fname << "  ";
			cout << p->sname << "  ";
			cout << p->gr << endl;
			}
	}
	
	void postOrder(){
		postordert(root);
	}
};
