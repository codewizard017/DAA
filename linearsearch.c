#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void linsearch(int a[], int n, int val)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==val)
        {
            printf("The element is available at index %d.\n",i);
            return;
        }
    }
    printf("The element is not available.\n");
}

int main()
{
    clock_t start,end;
    double total_t;
    start=clock();

    int n,i,val,a[20];
    printf("Enter the size of the array:");
    scanf("%d", &n);
    srand(1);
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    printf("The elements of the array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n", a[i]);
    }

    //printf("Enter the elements:\n");
    //for(i=0;i<n;i++)
    //{
    //    scanf("%d", &a[i]);
    //}
    printf("Enter the element to search for:");
    scanf("%d", &val);
    linsearch(a,n,val);    
    end=clock();
    total_t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The program took %f seconds to execute.\n", total_t);
    return 0;
}

