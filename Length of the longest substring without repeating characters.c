#include<stdio.h>
#include<limits.h>
#include<string.h>

void length(char* arr,int n)
{
    int visited[256]={-1};
    int cur_len=1,max_len=1;
    int prev_index;

    visited[arr[0]]=0;
    int i;

    for(i=1;i<n;i++)
    {
        prev_index=visited[arr[i]];

        if(prev_index==-1 || i-cur_len>prev_index)
        cur_len++;
        else
        {
            if(cur_len>max_len)
            max_len=cur_len;

            cur_len=i-prev_index;
        }
        visited[arr[i]]=i;
    }

    if(cur_len>max_len)
    max_len=cur_len;

    printf("max length is %d",max_len);

}

int main()
{
    char arr[]="geeksforgeeks";
    int n=strlen(arr);
    length(arr,n);
    return 0;
}
