#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int a[], int l, int r)
{
int piv,i,j,temp;
piv=a[r];
i=l-1;
for(j=l;j<r;j++)
{
if(a[j]<=piv){
i++;
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
temp=a[i+1];
a[i+1]=a[r];
a[r]=temp;
return (i+1);
}

void quicksort(int a[],int l,int r)
{
if(l<r)
{
int p=partition(a,l,r);
quicksort(a,l,p-1);
quicksort(a,p+1,r);
}
}

int main()
{
int n,i;
printf("Enter the number of elements:");
scanf("%d",&n);
int *a=(int*)malloc(n*sizeof(int));
printf("Enter %d elements:\n", n);
for(i=0;i<n;i++)
{
scanf("%d", &a[i]);
}
clock_t start,end;
start=clock();
quicksort(a,0,n-1);
end=clock();
double time_t=((double)(end-start))/CLOCKS_PER_SEC;
printf("Sorted Array:\n");
for(i=0;i<n;i++)
{
printf("%d\n", a[i]);
}
printf("CPU Time : %f seconds\n", time_t);
return 0;
}
