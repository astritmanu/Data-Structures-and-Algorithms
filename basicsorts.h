#ifndef basicsorts
#define basicsorts

void bubblesort(int [],int,bool);
void selectionsort(int [],int,bool);
void insertionsort(int [],int,bool);

void bubblesort(int a[],int len, bool b=0)       //b=0 for asc, b=1 for desc
{
    int swap=1;

    for(int i=1; swap!=0; i++)
    {
        swap=0;

        for(int j=0;j<len-i;j++)
        {
            if(b==0) {  if(a[j]>a[j+1]) swap=1; }
            else     {  if(a[j]<a[j+1]) swap=1; }
               
            if(swap==1)
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }          
            
        }
    }
}
    

void selectionsort(int a[],int len, bool b=0)       //b=0 for asc, b=1 for desc
{
    for(int i=0; i<len-1; i++)
    {
        int minmax=a[i];
        int k=i;

        for(int j=i;j<len;j++)
        {
            if(b==0) {if(a[j]<minmax)    minmax=a[j], k=j;}
            else {if(a[j]>minmax)    minmax=a[j], k=j; }            
        }
        
        int temp=a[k];
        a[k]=a[i];
        a[i]=temp;
    }
}

void insertionsort(int a[],int len, bool b=0)       //b=0 for asc, b=1 for desc
{
    for(int i=1; i<len; i++)
    {
        int temp=a[i];
        int swap=0;
        
        for(int j=i-1;swap==0&&j>=0;j--)
        {
            if(b==0)
            {
                if(a[j+1]<a[j])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }

                else swap=1;      
            }
            
            else
            {
                if(a[j+1]>a[j])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }

                else swap=1;      
            }
                    
        }

    }
}


#endif