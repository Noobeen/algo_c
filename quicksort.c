#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int pivot(int *a,int l,int r);
int quick_sort(int *arr,int l,int r);
int binary_search(int *arr,int l,int r,int element);




int main()
{
    char choice[1];
    char *choice_1="y";
    int size,buff,l_index,r_index;


    printf("enter the length of you list \t");
    scanf("%i",&size);

    printf("enter the left index of you list \t");
    scanf("%i",&l_index);

    printf("enter the right index of you list \t");
    scanf("%i",&r_index);
    

    int *p=malloc(size*sizeof(int));    //dynamically creating the memory for array 
    
    
    if(p==NULL)                        //checking for false memory or void memory
    {
        free(p);                      // freeing the heap memory 
        return 1;
    }




    for(int i=0;i<size;i++)          // prompts for input to user for the array
    {
        printf("enter the %i th num for you array\t",i+1);
        scanf("%i",&(*(p+i)));

    }



    quick_sort(p,l_index,r_index);  //passing the array to quciksort array for sorting
    
    
    
    for(int i=0;i<size;i++)        //for outputing the sorted array
    {
        printf("%i\t",*(p+i));
    }


    int element;
    int a=20;
    label:do{
        printf("enter the element you want to find\t");
        scanf("%i",&element);


        int index=binary_search(p,0,size-1,element);
        if(index<0)
        {
            printf("sorry you request could not be found on this array\n");
            printf("if you want to search more item plz enter y else type what ever yo like except y\t");
            scanf("%s",choice);
            if (strcmp(choice,choice_1)==0)
            {
                second:goto label;
            }
            else
            {
                free(p);
                return 2;
            }
        }

        printf("the num you searched is in %i index",index);
        printf("if you want to search more item plz enter y else type what ever yo like except y\t");
        scanf("%s",choice);
        if(strcmp(choice,choice_1)==0)
        {
            goto second;
        }    
    }while(a!=20);
    free(p);
    
    return 0;
}





int quick_sort(int* arr,int l,int r) //func to recusively quick sort
{
    if(l>r)
    {
        return 1;
    }

    int h=pivot(arr,l,r);


    quick_sort(arr,l,(h-1));

    quick_sort(arr,(h+1),r);

}






int pivot(int *a,int l,int r)  //func for pivot index 
{
    int j=l-1;
    int temp;
    int buff=*(a+r);


    for (int i =l;i<r;i++)
    {
        if(*(a+i)<buff)
        {
            j=j+1;
            temp=*(a+i);
            *(a+i)=*(a+j);
            *(a+j)=temp;
        }
    }


    temp=*(a+(j+1));
    *(a+(j+1))=*(a+r);
    *(a+r)=temp;


    
    return j+1;
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
