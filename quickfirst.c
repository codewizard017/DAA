#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int a[], int l, int r)
{
int piv,i,j,temp;
piv=a[l];
i=l+1;
for(j=l+1;j<r;j++)
{
if(a[j]<=a[l]){
temp=a[j];
a[j]=a[i];
a[i]=temp;
i++;
}
}
temp=a[i-1];
a[i-1]=a[l];
a[l]=temp;
return i;
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
quicksort(a,0,n);
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
