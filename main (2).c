#include <stdio.h>
int max(int,int);
int knapsack(int,int [],int [],int);
int main()
{
    int n,wt[20],v[20],C,i;
    printf("\n Enter the no of items: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n Enter the weigth: ");
        scanf("%d",&wt[i]);
        printf("\n Enter the value: ");
        scanf("%d",&v[i]);
    }
    printf("\n Enter the capacity: ");
    scanf("%d",&C);
    printf("\n The maximum profit is = %d",knapsack(C,v,wt,n));
    return 0;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
int knapsack(int C,int v[],int wt[],int n)
{
    int i,w;
    int k[n+1][C+1];
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=C;w++)
        {
            if(i==0||w==0)
                k[i][w]=0;
            else if(wt[i-1]<=w)
                k[i][w]=max(k[i-1][w-wt[i-1]]+v[i-1],k[i-1][w]);
            else
                k[i][w]=k[i-1][w];
        }
    }
    return k[n][C];
}
