#include<stdio.h>
#include<limits.h>

int min_mul(int p[],int n)
{
    int L,i,j,k,q;
    int m[n][n];
    for(i=1;i<n;i++)
      m[i][i]=0;
    for(L=2;L<n;L++)
    {
        for(i=1;i<=n-L;i++)
        {
            j=i+L-1;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                m[i][j]=q;
            }
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        printf("%d\t",m[i][j]);
        printf("\n");
    }
    return m[1][n-1];
}

void main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Minimum number of multiplications is %d ",min_mul(arr,size));

}
