#include<stdio.h>
#include<stdlib.h>

int binary_search(int *arr,int l,int r,int element);


int main()
{
   // int a[]={1,2,5,6,7,8,9};
    int size;
    printf("enter the length of you array \t");
    scanf("%i",&size);
    
    int *p=malloc(size*(sizeof(int)));
    
    if(p==NULL)
    {
        free(p);
        return 1;
    }

    for(int i=0;i<size;i++)
    {
        printf("plz enter the %i th element of you array\t",i+1);
        scanf("%i",&(*(p+i)));
    }


    int ele;
    printf("plz enter the num you want to find \t");
    scanf("%i",&ele);

    int index=binary_search(p,0,size-1,ele);
    if(index<0)
    {
        printf("\n########\tsorry no value found\t##########\n");
        return 2;
    }

    printf("the num is located at %i",index);
    

    free(p);
    return 0;
}


int binary_search(int *arr,int l,int r,int element)
{
    int mid=((l+r)/2);
    int guess=*(arr+mid);
    if(element==guess)
    {
        return mid;
    }
    if(l==r)
    {
        return (2-5);
    }
    if(element>guess)
    {
        binary_search(arr,(mid+1),r,element);
    }
    else
    {
        binary_search(arr,l,(mid-1),element);
    }
}