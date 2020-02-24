#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;

template <class T>
struct node{
    T info;
    node <T> *llink,*rlink;
};

template <class T>
class BinaryTree{
    protected:
        node<T> *root;
    private:
        void destroy(node<T> *&);
        void inordert(node<T> *);
        void preordert(node<T> *);
        void postordert(node<T> *);
        int _height(node<T> *);
        int max(int x, int y){ return (x>y)? x: y;};
        int nodecount(node<T> *);
        int leafcount(node<T> *);
    public:
        BinaryTree(){root=NULL;}
        ~BinaryTree(){destroy(root);}
        bool isEmpty(){return root=NULL;}
        void inorder(){inordert(root);}
        void preorder(){preordert(root);}
        void postorder(){postordert(root);}
        int height(){return _height(root);}
        int countnodes(){return nodecount(root);}
        int countleaf(){return leafcount(root);}
        void display();
};
template <class T>
void BinaryTree<T>::inordert(node<T> *p){
if(p!=NULL){
    inordert(p->llink);
    cout<<p->info<<"\t";
    inordert(p->rlink);}}
template <class T>
void BinaryTree<T>::preordert(node<T> *p) {
    if(p!=NULL){
        cout<<p->info<<"\t";
        preordert(p->llink);
        preordert(p->rlink);}}
template <class T>
void BinaryTree<T>::postordert(node<T> *p){
    if(p!=NULL){
        postordert(p->llink);
        postordert(p->rlink);
        cout<<p->info<<"\t";}}   
template <class T>
int BinaryTree<T>::nodecount(node<T> *p){
    if(p!=NULL)
        return 0;
    else
        return 1+nodecount(p->llink)+nodecount(p->rlink);}
template <class T>
int BinaryTree<T>::leafcount(node<T> *p){
    if(p==NULL)
    return 0;
    else if((p->llink==NULL)&&(p->rlink==NULL))
    return 1;
    else return leafcount(p->link)+leafcount(p->rlink);}                      

template <class T>
int BinaryTree<T>::_height(node<T> *p){
    if(p==NULL)
        return 0;
    else 
        return 1+max(_height(p->llink) , _height(p->rlink));}

template <class T>
void BinaryTree<T>::destroy(node<T> *&p){
if(p!=NULL){
    destroy(p->llink);
    destroy(p->rlink);
    delete p;
    p=NULL;}}
template<class T>
void BinaryTree<T>::display(){
	inorder();
	cout<<endl;
	}

template <class T>
class BST:public BinaryTree<T>{
    public:
    node<T> * search (const T&);
    void insert (const T&);
    void deletenode(T&);
    private:
    void deletefromTree(node <T> *&);
};
template <class T>
    node<T>* BST<T>::search(const T &item){
    node<T> *p;
    bool found=false;
    if(BinaryTree<T>::root==NULL) 
    cerr<<"No tree";
    else{
        p=BinaryTree<T>::root;
        while(!found && p!=NULL){
            if(p->info==item)
            found=true;
        else if(item<p->info)
        p=p->llink;
        else
        {
            p=p->rlink;
        }
            
        }
    }
    return p;
}
template <class T>
void BST<T>::insert (const T &item){
    node<T> *p,*q,*r;
    r=new node<T>;
    r->info=item;
    r->llink=r->rlink=NULL;
    if(BinaryTree<T>::root==NULL)
    BinaryTree<T>::root=r;
    else {
        p=BinaryTree<T>::root;
        while(p!=NULL){
            q=p;
            if(item<p->info)
            p=p->llink;
            else
            p=p->rlink;
        }
        if(item<q->info)
        q->llink=r;
        else 
        q->rlink=r;
    }
}

#endif
