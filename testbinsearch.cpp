#include<iostream>

#include "binarysearch.h"
#include "efficientsorts.h"

int main()
{
    int a[]={3,5,76,3,1,3,6,7,8,5,3,2,4,6,7,8};
    
    int len = sizeof(a)/sizeof(a[0]);

    quicksort(a,len,0);

    for(int i=0;i<len;i++) std::cout<<a[i]<<" ";

    int key=binary_search(a,8,len);

    std::cout<<key;

    return 0;
}