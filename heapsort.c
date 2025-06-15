#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void maxheapify(int *a, int n, int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest=i,temp;
    if(l<n && a[l]>a[i])
    {
        largest=l;
    }
    if(r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        maxheapify(a,n,largest);
    }
}

void buildmaxheap(int *a, int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        maxheapify(a,n,i);
    }
}

void heapsort(int *a, int n)
{
    buildmaxheap(a,n);
    int i, temp;
    for(i=n-1;i>0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        n=n-1;
        maxheapify(a,n,0);
    }
}

int main()
{
    int n, i;
    printf("Enter the limit of the array:");
    scanf("%d", &n);
    int *a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("Error in creation");
        return 0;
    }
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    clock_t start,end;
    double total_t;
    start=clock();
    heapsort(a,n);
    printf("Array after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n", a[i]);
    }
    end=clock();
    total_t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The program took %f seconds to execute\n", total_t);
    return 0;
}
