#ifndef binarysearch
#define binarysearch


int binary_search(int a[], int item, int len, int high=0, int low=0)
{
   
    high=len-1+low;

    int med=(low+high)/2;

    if(low>high) return -1;

    if(a[med]>item) return(binary_search(a,item,med-low,med-1,low));
    else if(a[med]<item) return(binary_search(a,item,high-med,high,med+1));
    else return med;

}


#endif