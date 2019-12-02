#include <stdio.h>
#include <string.h>

int c[20][20],m,n,i,j;
char x[20],y[20],b[20][20];

void print(int i,int j)
{
    if(i==0||j==0)
        return;
    if(b[i][j]=='c')
    {
        print(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='u')
        print(i-1,j);
    else
        print(i,j-1);
}

void lcs()
{
    m=strlen(x);
    n=strlen(y);

    for(i=0;i<=m;i++)
        c[i][0]=0;
    for(j=0;j<=n;j++)
        c[0][i]=0;

   for(i=1;i<=m;i++)
   {
       for(j=1;j<=n;j++)
       {
           if(x[i-1]==y[j-1])
           {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
           }
           else if(c[i-1][j]>=c[i][j-1])
           {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
           }
           else
           {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
           }
       }
   }
}

int main()
{
    printf("\n Enter first sequence:");
    scanf("%s",x);
    printf("\n Enter second sequence:");
    scanf("%s",y);
    printf("\n THE LONGEST COMMON SUBSEQENCE IS:");
    lcs();
    print(m,n);
    return 0;
}
