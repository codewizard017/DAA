#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *board,i;

void printsol(int N)
{
    for(i=0;i<N;i++)
    {
        printf("%d", board[i]+1);
    }
    printf("\n");
}

int isSafe(int row, int col, int N)
{
    for(i=0;i<row;i++)
    {
        if(board[i]==col||board[i]-i==col-row||board[i]+i==col+row)
        {
            return 0;
        }
    }
    return 1;
}

void solveNqueen(int row, int N)
{
    int col;
    if(row==N)
    {
        printsol(N);
        return;
    }
    for(col=0;col<N;col++)
    {
        if(isSafe(row,col,N))
        {
            board[row]=col;
            solveNqueen(row+1,N);
        }
    }
}

int main()
{
    int N;
    clock_t s,e;
    printf("Enter the value of N(size of chess board):");
    scanf("%d", &N);
    if(N<4)
    {
        printf("No solutions exist for N=%d\n", N);
        return 0;
    }
    board=(int *)malloc(N *sizeof(int));
    if(board==NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Solution for %d-Queen's Probem:\n", N);
    s=clock();
    solveNqueen(0,N);
    e=clock();
    printf("\nCPU Time:%.6f seconds\n", (double)(e-s)/CLOCKS_PER_SEC);
    free(board);
    return 0;
}