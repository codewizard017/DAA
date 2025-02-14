#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection(int *a,int n)
{
    int i,j,min,flag,temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        flag = 0;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
            flag = 1;
        }
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
    selection(a,n);
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
