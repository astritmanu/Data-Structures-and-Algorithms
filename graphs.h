# ifndef graphs
# define graphs

#include<iostream>
#include<fstream>

class graph
{
    struct edgenode
    {
        int y;
        int weight;
        edgenode* next;
    };

    int list_size;
    int nvertices;
    int nedges;
    edgenode** edges;
    int* degree;

    bool directed;      //0 for undirected, 1 for directed

    void resize(int);

    public:
        graph() 
        {   
            list_size=10;
            nvertices=nedges=directed=0; 
            edges=new edgenode*[list_size];
            degree=new int[list_size];

            for(int i=0;i<list_size;i++) {  degree[i]=0;    edges[i]=NULL;  }

        }

        void read_graph();
        void insert_edge(int, int, bool);
        void print_graph();

        void bfs();
        void dfs();

};


void graph::read_graph()
{
    std::fstream fs;
    fs.open("graphinput.dat",std::ios::in);
    
    int numedges;

    fs>>directed;
    
    int x,y;
    fs>>x;

    while(fs)
    {
        fs>>y;

        insert_edge(x,y,directed);
        fs>>x;
    }

    fs.close();
}

void graph::insert_edge(int x, int y, bool b)
{
    if(x>=list_size)    resize(x);
    
    edgenode* newnode=new edgenode;

    if(x>nvertices)  nvertices=x;

    newnode->weight=0;
    newnode->y=y;
    newnode->next=edges[x];

    edges[x]=newnode;
    degree[x]++;

    if(b==0) insert_edge(y,x,1);
    else nedges++;

}


void graph::print_graph()
{
    for(int i=1;i<=nvertices;i++)
    {
        edgenode* p=edges[i];
        std::cout<<i<<": ";

        while(p)
        {
            std::cout<<p->y<<" ";
            p=p->next;

        }
        std::cout<<std::endl;

    }

}

void graph::resize(int x)
{
    int new_listsize=2*x;

    edgenode** temp1=new edgenode*[new_listsize];
    int* temp2=new int[new_listsize];

    for(int i=0;i<list_size;i++) {  temp1[i]=edges[i];    temp2[i]=degree[i];  }
    for(int i=list_size;i<new_listsize;i++) {temp1[i]=NULL;   temp2[i]=0;  }

    delete[] *edges;
    delete[] degree;

    edges=temp1;
    degree=temp2;
    list_size=new_listsize;
}

#endif