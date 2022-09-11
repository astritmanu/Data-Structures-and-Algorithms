# ifndef trees
# define trees

#include<iostream>

class binarysearchtree
{
   protected:
        struct Node {
            int data;
            Node* parent;
            Node* left;
            Node* right;
        };

        Node* root;

    public:

        binarysearchtree() {root=NULL; }

        void insert_tree_element(int, Node*, Node*);
        void delete_tree_element(int,Node*);        
        Node* search_tree(int, Node*);
        void ascending_display(Node*);
        void descending_display(Node*);
        Node* findmin(Node*);
        Node* findmax(Node*);
        Node* getroot();
        void display_element(Node*);

        void visualize_tree(Node*);

};

void binarysearchtree::insert_tree_element(int a, Node* l, Node* p=NULL)
{
    if(root==NULL)
    {
        Node* newnode=new Node;
        newnode->data=a;
        newnode->parent=newnode->left=newnode->right=NULL;
        root=newnode;

        return;
    }

    if(l==NULL)
    {
        Node* newnode=new Node;  
        newnode->data=a;
        newnode->left=newnode->right=NULL;
        newnode->parent=p;
     
        if(p->data<a) p->right=newnode;
        else p->left=newnode;
        
        return;
    }

    if(a<l->data)   insert_tree_element(a,l->left,l);
    else            insert_tree_element(a,l->right,l);

}

void binarysearchtree::ascending_display(Node *l)
{
    if(l->left!=NULL) ascending_display(l->left);
    std::cout<<l->data<<" ";
    if(l->right!=NULL) ascending_display(l->right);
    
}

void binarysearchtree::descending_display(Node *l)
{
    if(l->right!=NULL) descending_display(l->right);
    std::cout<<l->data<<" ";
    if(l->left!=NULL) descending_display(l->left);

}

binarysearchtree::Node* binarysearchtree::getroot()
{
    return root;
}


void binarysearchtree::visualize_tree(Node *l)
{
    static int offset=0;

    for (int i = 0; i < offset; ++i)
    {
        std::cout<<" ";
    }

    if(l==NULL) {   std::cout<<"-\n"; return;   }
    
    std::cout<<l->data<<"\n";

    offset+=3;
    visualize_tree(l->left);
    visualize_tree(l->right);
    offset-=3;
}

binarysearchtree::Node* binarysearchtree::search_tree(int a, Node *l)
{
    if(l==NULL) return NULL;

    if(l->data==a) return l;

    if(l->data<a) return search_tree(a,l->right);
    else          return search_tree(a,l->left);
}

void binarysearchtree::delete_tree_element(int a,Node* l)      
{
    if (l==NULL) return;

    if(l->data==a)  
    {
        if((l->left==NULL)&&(l->right==NULL))   
        {
            if(l->parent==NULL) root=NULL;
            else if(l==l->parent->right) l->parent->right=NULL;
            else if(l==l->parent->left) l->parent->left=NULL;
           
            l->parent=NULL;
            delete l; 
            return;   
        }
        
        else if((l->left!=NULL)&&(l->right!=NULL))
        {
            Node *temp=findmin(l->right);
            l->data=temp->data;

            delete_tree_element(temp->data,temp);
            return;
        }

        else
        {
            Node *temp;

            if(l->left!=NULL) temp=l->left;
            else temp=l->right;

            if(l->parent==NULL) {   root=temp; delete l; return; }
            else if(l==l->parent->left) l->parent->left=temp;           
            else if(l==l->parent->right) l->parent->right=temp;           

            temp->parent=l->parent;
            delete l; 
            return;
        }



    }

    else if(l->data<a)  delete_tree_element(a,l->right);
    else           delete_tree_element(a,l->left);
}

binarysearchtree::Node* binarysearchtree::findmin(Node* l)
{
    if(l==NULL) return NULL;

    if(l->left!=NULL) return (findmin(l->left));
    else return l;

}

binarysearchtree::Node* binarysearchtree::findmax(Node* l)
{
    if(l==NULL) return NULL;

    if(l->right!=NULL) return (findmax(l->right));
    else return l;

}

void binarysearchtree::display_element(Node* l)
{
    if(l==NULL) std::cout<<"Incorrect element. Cannot display!";
    else std::cout<<l->data;
}


#endif