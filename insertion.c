#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion(int *a,int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

int main()
{
    clock_t start,end;
    double total_t;
    start=clock();

    int n,i,j;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int *a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("Error in creation\n");
        return 0;
    }
    srand(1);
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100000000;
    }
    printf("Array before sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n", a[i]);
    }

    //printf("Enter the elements:\n");
    //for(i=0;i<n;i++)
    //{
    //    scanf("%d", &a[i]);
    //}
    insertion(a,n);
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
