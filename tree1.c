/*Given Preorder traversal of a BST, check if each non-leaf node has only one child. Assume that the BST contains unique entries.
Input: pre[] = {20, 10, 11, 13, 12}
Output: Yes
The give array represents following BST. In the following BST, every internal
node has exactly 1 child. Therefor, the output is true.
        20
       /
      10
       \
        11
          \
           13
           /
         12
*/

#include<stdio.h>
#include<stdlib.h>

int check(int pre[],int n)
{
   int nextDiff,lastDiff;
   int i;
   for(i=0;i<n;i++)
   {
       nextDiff=pre[i]-pre[i+1];
       lastDiff=pre[i]-pre[n-1];
       if(nextDiff*lastDiff<0)
       return 0;
   }
   return 1;
}

int main()
{
int pre[] = {8, 3, 5, 7, 6};
    int size = sizeof(pre)/sizeof(pre[0]);
    if (check(pre, size) == 1 )
        printf("Yes");
    else
        printf("No");
    return 0;
}
