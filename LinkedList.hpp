#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cassert>

template <typename T>
struct Node
{
	T data;
	Node<T> *next;
};

template <typename T>
class LinkedList
{
public:
	void initialize();
	bool is_empty();
	int length();
	void destroy();
	T front();
	T back();
	const Node<T>* search(T& search_item);
	void prioritized_insert(T& new_item);
	void insert_head(T& new_item);
    void insert_last(T& new_item);
	void delete_node(T& delete_item);
	LinkedList();
	~LinkedList();
	
	template <typename S>
	friend std::ostream& operator<<(std::ostream &os,LinkedList<S> &list)
	{
		Node<S> *p = new Node<S>;
		p=list.head;
		while (p != NULL)
		{
			os<<p->data<<" ";
			p=p->next;
		}
		return os;
	}
protected:
	int count;
	Node<T> *head;
	Node<T> *last;
};

template <typename T>
const Node<T>* LinkedList<T>::search(T& search_item)
{
	Node<T> *temp = head;

	for (int i = 0; i < count; i++)
	{
		if (temp->data == search_item)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

template <typename T>
void LinkedList<T>::insert_head(T& new_item){
	Node<T> *newNode = new Node<T>;
	newNode->data = new_item;
	newNode->next = head;
	head = newNode;

	if (last == NULL)
		last = head;

	count++;
}

template <typename T>
void LinkedList<T>::insert_last(T& new_item)
{
	Node<T> *newNode = new Node<T>;
	newNode->data = new_item;
	newNode->next = NULL;

	last->next = newNode;
	last = newNode;

	if (head == NULL)
		head = last;

	count++;
}

template <typename T>
void LinkedList<T>::delete_node(T& delete_item)
{
	Node<T> *current, *trailCurrent;
	bool found;

	if (head == NULL)
		std::cout << "Cannot delete from empty list." << std::endl;
	else
	{
		if (head->data == delete_item)
		{
			current = head;
			head = head->next;
			count--;
			if (head == NULL)
				last = NULL;
			delete current;
		}
		else
		{
			found = false;
			trailCurrent = head;
			current = head->next;

			while (current != NULL && !found)
			{
				if (current->data != delete_item)
				{
					trailCurrent = current;
					current = current->next;
				}
				else
				{
					found = true;
				}
			}
			if (found)
			{
				trailCurrent->next = current->next;
				count--;
				if (last == current)
					last = trailCurrent;
				delete current;
			}
			else
			{
				std::cout << "Item to be deleted is not in the list." << std::endl;
			}
		}
	}
}

template <typename T>
bool LinkedList<T>::is_empty()
{
	return (head == NULL);
}

template <typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	last = NULL;
	count = 0;
}

template <typename T>
void LinkedList<T>::destroy()
{
	Node<T> *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}

	last = NULL;
	count = 0;
}

template <typename T>
void LinkedList<T>::initialize()
{
	destroy();
}

template <typename T>
int LinkedList<T>::length()
{
	return count;
}

template <typename T>
T LinkedList<T>::front()
{
	assert(head != NULL);
	return head->data;
}

template <typename T>
T LinkedList<T>::back()
{
	assert(last != NULL);
	return last->data;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	destroy();
}
template<typename T>
void LinkedList<T>::prioritized_insert(T& new_item){
	Node<T> *p= new Node<T>;
	Node<T> *q= new Node<T>;
	Node<T> *s= new Node<T>;
	p=head;
	std::cout<<"Inserting->"<<std::endl<<new_item<<std::endl;
	for(int i=0;i<length();i++)
	{		
		for(int j=i+1;j<length();j++)
		{
			if((p!=NULL)&&(new_item)<p->data)
			{
				q=p;
				p=p->next;
			}
		}
	}
	s->data=new_item;
	s->next=p;
	if(p==head)
		head=s;
	else
		q->next=s;
	count++;	
}
/*template <typename T>
void LinkedList<T>::prioritized_insert(T& new_item){

    if (head == NULL)
    { 
    insert_head(new_item);
    }
    else{

    Node<T> *add = new Node<T>;
    add->data= new_item;

    if(add->data > head->data)
        insert_head(add->data);
    else{

    if(head->next!=NULL){
        Node<T> q,w;
        q=head->next;
        w=head;

        while(1){

            if(q == NULL){
                insert_last(add->data);
                break;
            }
            else if(add->data > q->data){
                w->next=add;
                add->next=q;
                break;
            }
            else{
                w=q;
                q=q->next;
            }

        }



    }


    else
    insert_last(add->data);





}
}


}*/

#endif
