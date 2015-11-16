#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<math.h>

int min(int a,int b)
{
    return (a<b)?a:b;
}
int minPalPar(char* arr)
{
    int n=strlen(arr);
    int M[n][n];
    bool P[n][n];

    for(i=0;i<n;i++)
     {
         P[i][i]=TRUE;
         M[i][i]=0;
     }

     for(L=2;L<=n;L++)
     {
         for(i=0;i<=n-L;i++)
         {
             j=i+L-1;

             if(L==2)
             P[i][j]=(arr[i]==arr[j]);
             else
             P[i][j]=(arr[i]==arr[j]) && P[i+1][j-1];

             if(P[i][j]==true)
             M[i][j]=0;
             else
             {
              M[i][j]=INT_MAX;
              for(k=i;k<j;k++)
               M[i][j]=min(M[i][j],M[i][k]+M[k+1][j]+1);
             }

         }
     }
     return M[0][n-1];
}

void main()
{
    char str[] = "ababbbabbababa";
   printf("Min cuts needed for Palindrome Partitioning is %d",minPalPar(str));
}
