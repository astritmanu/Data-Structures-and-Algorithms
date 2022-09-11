#ifndef efficientsorts
#define efficientsorts

#include "stackqueue.h"
#include<cstdlib>


void merge(int [], int, int, int, bool);
void mergesort(int [], int, int, bool);

void heapsort(int [], int, bool);
void quicksort(int [], int, int, bool);
int partition(int [],int,int,int,bool);




void mergesort(int a[], int high, bool b=0, int low=1)      //b=0 for asc, b=1 for desc
{
    int med=(high+low)/2;

    if(low<high)
    {
        mergesort(a,med,b, low);
        mergesort(a,high,b,med+1);
        merge(a,high,med,low,b);

    }
    
}

void merge(int a[], int high, int med, int low, bool b)
{
    queue buffer1, buffer2;
    for(int i=low-1; i<med;i++)  {   buffer1.enqueue(a[i]);    }
    for(int i=med; i<high;i++)   {   buffer2.enqueue(a[i]);    }

    int i=low-1;

    while(buffer1.peek()!=NULL&&buffer2.peek()!=NULL)
    {
        if(b==0)
        {
            if(buffer1.peek()->data<=buffer2.peek()->data)  {  a[i]=buffer1.peek()->data; buffer1.dequeue();   }
            else {   a[i]=buffer2.peek()->data; buffer2.dequeue();   }
        }

        else
        {
            if(buffer1.peek()->data>=buffer2.peek()->data)  {  a[i]=buffer1.peek()->data; buffer1.dequeue();   }
            else {   a[i]=buffer2.peek()->data; buffer2.dequeue();  }
        }
        i++;
        
    }

    while(buffer1.peek()!=NULL) {a[i]=buffer1.peek()->data; buffer1.dequeue(); i++;}
    while(buffer2.peek()!=NULL) { a[i]=buffer2.peek()->data; buffer2.dequeue(); i++;}

    
}


void heapsort(int a[], int len, bool b)
{
    heap q;

    q.make_heap(a,len,b);

    for(int i=0;i<len;i++)  a[i]=q.extract_root();

}


void quicksort(int a[], int len, bool b=0, int low=0, int high=0)
{
    high=len-1+low;
    
    if(high>low)
    {
        int pivot=rand()%len+low;

        pivot=partition(a,pivot,low,high,b);

        int len1=pivot-low;
        int len2=high-pivot;

        int high1=pivot-1;
        int low2=pivot+1;

        quicksort(a,len1,b,low,high1);
        quicksort(a,len2, b, low2,high);
    }

}

int partition(int a[],int originalpivot,int low,int high,bool b)
{
    int findpivotlocation=low;

    for(int i=low;i<=high;i++)
    {
        int swap=0;
        if(b==0)    {if(a[i]<a[originalpivot]) swap=1;  }
        else        {if(a[i]>a[originalpivot]) swap=1;  }

        if(swap==1)
        {
            int temp=a[findpivotlocation];
            a[findpivotlocation]=a[i];
            a[i]=temp;

            if(findpivotlocation==originalpivot) originalpivot=i;
            findpivotlocation++;
        }
    }

    int temp=a[originalpivot];
    a[originalpivot]=a[findpivotlocation];
    a[findpivotlocation]=temp;

    return findpivotlocation;
}


#endif