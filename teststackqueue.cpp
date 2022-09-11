#include "stackqueue.h"

int main()
{
    queue n;

    for(int i=0; i<10;i++)
    {
        n.enqueue(i*4);
    }
    
    n.printqueue();

    n.dequeue();
    n.enqueue(43);
    n.printqueue();

    n.dequeue();
    n.printqueue();
    n.peek();

    return 0;
}