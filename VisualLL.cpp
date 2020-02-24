#include <iostream>
#include <conio.h>

using namespace std;

struct node
{
int data;
node *next;
};

class linklist
{
 node *head;
 public:
 linklist()
 {head=NULL;}
 void create(void);
 void display(void);
};

void linklist :: create(void)
{
  node *newl=NULL,*end=newl;
  int info;
  while(1)
  {
    cout<<"\n\nenter -999 to terminate\n";
    cout<<"enter info:";
    cin>>info;
     if(info==-999)
        break;
     else
     {
        newl=new node;
        newl->data=info;
        if(head==NULL)
           head=newl;
        else
           end->next=newl;
        end=newl;
        end->next=NULL;
     }
    }
}

void linklist :: display(void)
{
  cout<<"\n\n\nDisplay Function\n";
  node *temp=head;
    while(temp!=NULL)
    {
       cout<<temp->data;
        if(temp->next!=NULL)
          cout<<"==>";
        temp=temp->next;
    }
  delete(temp);
}

main()
{

linklist o1;
o1.create();
o1.display();
getch();
}
