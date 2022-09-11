# ifndef stackqueue
# define stackqueue

#include<iostream>

//*******************Class Declarations************************

class stack {

    struct Node {
        int data;
        Node* next;
    };

    Node* top;

    public:

        stack() {top=NULL; }       //default constructor

        void push(int);
        void pop();

        void printstack();

};

class queue {

    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;

    public:

        queue() {head=NULL, tail=NULL; }     //default constructor
    
        void enqueue(int);
        void dequeue();
        Node* peek();

        void printqueue();

};

class heap {

    int heap_size;                      //Current size of array
    int *pq;                            //Body of priority queue/heap
    int n;                              //Location of last filled element in heap
    bool b;                             //Type of heap (b=0 for min, b=1 for max)

    protected:
        void resize();          //Resize array if overflow
        void bubble_up(int);    //Swap node with parent, if required
        void bubble_down(int);  //Swap node with youngestchild, if required

    
    public:
 
        heap(int len=10) {    heap_size=len;   n=-1;    pq=new int[heap_size];  b=0;}

        int parent (int);       //Find parent of node with key n
        int youngestchild(int);         //Find youngestchild of node with key n
        void set_heap_type(bool);    //Set as min or max heap;

        void make_heap (int[], int,bool);    //Convert regular array into heap
        void insert(int);       //Insert new element in heap

        int extract_root();     //Extract minimum or maximum element of heap

        void display()
        {
            for (int i=0;i<=n;i++)   std::cout<<pq[i]<<" ";
        }

};

//*****************Stack Function Definitions********************

void stack::pop()
{
    
    if(top==NULL)
    {
        std::cout<<"Stack is empty"<<std::endl;
        return;
    }

    Node* temp=top;
    top=top->next;

    delete temp;
    return;
}


void stack::push(int a)    
{

    Node *newnode=new Node;
    newnode->data=a;

    if(top==NULL)
    {
        top=newnode;
        top->next=NULL;
        return;
    }

    newnode->next=top;
    top=newnode;

    return;

}

void stack::printstack()
{
    Node *temp=top;

    if(top==NULL) {return;    }

    while(temp!=NULL)
    {
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }

    std::cout<<std::endl;
    return;

}


//*****************Queue Function Definitions********************


void queue::dequeue()
{

    if(head==NULL)
    {
        return;
    }

    if(head==tail)
    {
        delete head;
        head=tail=NULL;
        return;
    }

    Node* b=head;

    head->next->prev=NULL;
    head=head->next;
        
    delete b;
    return;        
}


void queue::enqueue(int a)
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

    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=NULL;
    tail=newnode;
    
    return;
}

void queue::printqueue() 
{
    if(head==NULL) {std::cout<<"Queue is empty!"; return;    }


    Node *temp=head;

    while(temp!=NULL)
    {
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
  
    std::cout<<std::endl;
    return;

}

queue::Node* queue::peek() 
{
    if(head==NULL) {return NULL;    }
  
    return head;

}


//*****************Heap Function Definitions********************


int heap::parent (int key)
{
    if(key==1) return -1;
    else return (n+1)/2-1;
}
    
int heap::youngestchild (int key)
{
    if(2*key+1>n) return -1;
    else return (2*(key+1)-1);
}

void heap::set_heap_type(bool set_type)
{
    b=set_type;
    for(int i=(n+1)/2-1; i>=0; i--)   bubble_down(i);

}

void heap::insert(int a)
{
    if(n==heap_size-1) resize();

    n++;
    pq[n]=a;
    
    bubble_up(n);

}

void heap::resize()
{
    int new_heapsize=heap_size*2;

    int* temp=new int[new_heapsize];
    
    for(int i=0;i<heap_size;i++)    temp[i]=pq[i];

    delete[] pq;

    pq=temp;
    heap_size=new_heapsize;
}


void heap::bubble_up(int key)
{
    if(parent(key)==-1) return;
    int swap=0;

    if(b==0) {  if(pq[parent(key)]>pq[key]) swap=1; }
    else     {  if(pq[parent(key)]<pq[key]) swap=1; }

    if(swap==1)
    {
        int temp=pq[parent(key)];
        pq[parent(key)]=pq[key];
        pq[key]=temp;
        bubble_up(parent(key));

    }
}

void heap::bubble_down(int key)
{
    int c=youngestchild(key);
    if(c==-1) return;
    int dominant_key=key;

    for (int i=0;(i<=1)&&(c+i)<=n;i++)
    {  
        if(b==0) {   if(pq[dominant_key]>pq[c+i])    dominant_key=c+i;   }
        else     {   if(pq[dominant_key]<pq[c+i])    dominant_key=c+i;   }
    }
        
    if(dominant_key!=key)
    {
        int temp=pq[key];
        pq[key]=pq[dominant_key];
        pq[dominant_key]=temp;
        bubble_down(dominant_key);
    }
}


void heap::make_heap (int a[], int len, bool type)
{

    for(int i=0;i<len;i++)  
    {
        if(n==heap_size-1) resize();
        n++;
        pq[i]=a[i];
    }

    set_heap_type(type);
}

int heap::extract_root()
{
    if(n<0) {std::cout<<"Warning. Empty heap!"; return -1;  }
    
    int root=pq[0];
    pq[0]=pq[n];
    n--;
    bubble_down(0);

    return root;
}

#endif