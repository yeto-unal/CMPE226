#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    
    void display(){
    	while(!(head->data=NULL)){
    		cout<<(int)head->data<<"->";
    		head=head->next;
		}
	}
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(5);
    a.add_node(9);
    a.add_node(7);
    a.add_node(16);
    a.add_node(11);
    a.add_node(3);
    a.add_node(8);
    a.add_node(6);
    a.display();
    return 0;
}
