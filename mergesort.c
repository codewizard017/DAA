#include<stdio.h>
#include<time.h>

void merge(int a[], int l, int mid, int r)
{
    int i,j,k;
    int n1=mid-l+1;
    int n2=r-mid;
    int leftA[n1], rightA[n2];
    for(i=0;i<n1;i++)
    {
        leftA[i]=a[l+i];
    }
    for(j=0;j<n2;j++)
    {
        rightA[j]=a[mid+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(leftA[i]<=rightA[j])
        {
            a[k]=leftA[i];
            i++;
        }
        else{
            a[k]=rightA[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=leftA[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=rightA[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

int main()
{
    clock_t start,end;
    int i, n, a[10];
    printf("Enter the number of elements:");
    scanf("%d", &n);
    printf("Enter the numbers:");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    start=clock();
    mergesort(a,0,n-1);
    end=clock();
    double total_t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The sorted array:");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nTime taken is %f seconds", total_t);
    return 0;
}
