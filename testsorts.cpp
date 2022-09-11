#include<iostream>
#include<cstdlib>
#include "basicsorts.h"
#include "efficientsorts.h"

int main()
{
    int arr[100000]={};
    int arr2[100000]={};
    int arr3[100000]={};
    int arr4[100000]={};
    int arr5[100000]={};
    int arr6[100000]={};

    for(int i=0;i<100000;i++)
    {
        arr[i]=arr2[i]=arr3[i]=arr4[i]=arr5[i]=arr6[i]=rand()%1000;
    }

    int len = sizeof(arr6)/sizeof(arr6[0]);

    // for (int i=0;i<len;i++) 
    // {
    //     std::cout<<arr[i]<<" ";
    // }
    
    std::cout<<std::endl;

    double begin1=clock();
    insertionsort(arr,len,0);
    double end1=clock();


    double begin2=clock();
    selectionsort(arr2,len,0);
    double end2=clock();


    double begin3=clock();
    bubblesort(arr3,len,0);
    double end3=clock();

    double begin4=clock();
    mergesort(arr4,len,0);
    double end4=clock();

    double begin5=clock();
    heapsort(arr5,len,0);
    double end5=clock();

    double begin6=clock();
    quicksort(arr6,len,0);
    double end6=clock();

    // for (int i=0;i<len;i++) 
    // {
    //     std::cout<<arr6[i]<<" ";
    // }

    std::cout<<std::endl<<"Time taken by insertion sort: "<< (end1 - begin1) / CLOCKS_PER_SEC <<" sec";
    std::cout<<std::endl<<"Time taken by selection sort: "<< (end2 - begin2) / CLOCKS_PER_SEC <<" sec";
    std::cout<<std::endl<<"Time taken by bubble sort: "<< (end3 - begin3) / CLOCKS_PER_SEC <<" sec";
    std::cout<<std::endl<<"Time taken by merge sort: "<< (end4 - begin4) / CLOCKS_PER_SEC <<" sec";
    std::cout<<std::endl<<"Time taken by heap sort: "<< (end5 - begin5) / CLOCKS_PER_SEC <<" sec";
    std::cout<<std::endl<<"Time taken by quicksort: "<< (end6 - begin6) / CLOCKS_PER_SEC <<" sec";

    return 0;
}