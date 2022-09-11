# ifndef linkedlist
# define linkedlist

#include<iostream>

//*******************Class Declarations************************

class singlylinkedlist {

    protected:
        struct Node {
            int data;
            Node* next;
        };

        Node* head;

    public:

        singlylinkedlist() {head=NULL; }       //default constructor

        Node* search_list(int);
        Node* predecessor_list(int);

        void insert_node(int);
        void insert_node(int, int);
        void delete_node(int);

        void printlist();

};

class doublylinkedlist {

    
    protected:
        struct Node {
            int data;
            Node* next;
            Node* prev;
        };

        Node* head;
        Node* tail;

    public:

        doublylinkedlist() {head=NULL, tail=NULL; }     //default constructor

        Node* search_list(int,bool);
        
        void insert_node(int);
        void insert_node(int, int, bool);
        void delete_node(int);

        void printlist(bool);

};

//*****************Single Linked List Function Definitions********************

singlylinkedlist::Node* singlylinkedlist::search_list(int a)
{
    if(head==NULL) { std::cout<<"List is empty!"<<std::endl; return NULL; }

    Node* n=head;

    while (n!=NULL)
    {
        if(n->data==a) return n;
        n=n->next;
    }

        std::cout<<"Element "<<a<<" not found!"<<std::endl;
        return NULL;
}

singlylinkedlist::Node* singlylinkedlist::predecessor_list(int a)
{
    if(head==NULL) { std::cout<<"List is empty!"<<std::endl; return NULL; }
    

    Node* temp=head;

    while(temp->next!=NULL)
    {
        if(temp->next->data==a) return temp;
        temp=temp->next;
    }

    
    std::cout<<"Predecessor to "<<a<<" not found!"<<std::endl;
    return NULL;

}


void singlylinkedlist::delete_node(int a)
{
    
    if(head==NULL)
    {
        std::cout<<"List is empty"<<std::endl;
        return;
    }

    Node* n=search_list(a);

    if(n==head)
    {
        head=head->next;
    }

    else
    {
        Node* temp=predecessor_list(a);
        if(temp!=NULL)  temp->next=n->next;
    }

    delete n;
    return;
}


void singlylinkedlist::insert_node(int a)     //at head if no place specified
{

    Node *newnode=new Node;
    newnode->data=a;

    if(head==NULL)
    {
        head=newnode;
        head->next=NULL;
        return;
    }

    newnode->next=head;
    head=newnode;

    return;

}

void singlylinkedlist::insert_node(int a, int b)     //at specified place if given
{

    Node *newnode=new Node;
    newnode->data=a;

    Node* n=search_list(b);

    if(n==NULL)
    {
        std::cout<<"Element "<<a<<" not added."<<std::endl;
        return;
    }
    
    newnode->next=n->next;
    n->next=newnode;

    return;

}

void singlylinkedlist::printlist()
{
    Node *temp=head;

    if(head==NULL) {std::cout<<"List is empty!"; return;    }

    while(temp!=NULL)
    {
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }

    std::cout<<std::endl;
    return;

}



//*****************Double Linked List Function Definitions********************

doublylinkedlist::Node* doublylinkedlist::search_list(int a, bool b=0)  //b=0 for searching from head, b=1 for searching from tail
{
    if(head==NULL) { std::cout<<"List is empty!"<<std::endl; return NULL; }

    if(b==0)
    {
        Node* n=head;

        while (n!=NULL)
        {
            if(n->data==a) return n;
            n=n->next;
        }

        std::cout<<"Element "<<a<<" not found!"<<std::endl;
        return NULL;
    }

    else if (b==1)
    {
        Node* n=tail;
        while (n!=NULL)
        {
            if(n->data==a) return n;
            n=n->prev;
        }

        std::cout<<"Element "<<a<<" not found!"<<std::endl;
        return NULL;
    }
}


void doublylinkedlist::delete_node(int a)
{

    if(head==NULL)
    {
        std::cout<<"List is empty"<<std::endl;
        return;
    }

    Node* b=search_list(a);
  
    if(b==NULL)
    {
        return;
    }

    if(b==head)
    {
        head->next->prev=NULL;
        head=head->next;
    }

    else if(b==tail)
    {
        tail->prev->next=NULL;
        tail=tail->prev;
    }

    else
    {
        b->prev->next=b->next;
        b->next->prev=b->prev;
    }

    delete b;
    return;        
}


void doublylinkedlist::insert_node(int a)
{

    Node *newnode=new Node;
    newnode->data=a;

    if(head==NULL)
    {
        head=tail=newnode;
        head->next=tail->next=NULL;
        head->prev=tail->prev=NULL;
        return;
    }

    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    
    return;
}

void doublylinkedlist::insert_node(int a, int b, bool c=0) //c=0 for insert after, c=1 for insert before
{

    Node *newnode=new Node;
    newnode->data=a;

    Node* n=search_list(b);

    if(n==NULL)
    {
        std::cout<<"Element "<<a<<" not added."<<std::endl;
        return;
    }

    if(c==0)
    {
        newnode->next=n->next;
        n->next->prev=newnode;
        n->next=newnode;
        newnode->prev=n;
    }

    else if(c==1)
    {
        newnode->prev=n->prev;
        n->prev->next=newnode;
        n->prev=newnode;
        newnode->next=n;
    }

    return;
}

void doublylinkedlist::printlist(bool c=0)  //c=0 for forward print, c=1 for reverse print
{
    if(head==NULL) {std::cout<<"List is empty!"; return;    }

    if(c==0)
    {
        Node *temp=head;

        while(temp!=NULL)
        {
            std::cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    else if(c==1)
    {
        Node *temp=tail;

        while(temp!=NULL)
        {
            std::cout<<temp->data<<" ";
            temp=temp->prev;
        }
    }
    
    std::cout<<std::endl;
    return;

}


#endif