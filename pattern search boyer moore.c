#include<stdio.h>
#include<string.h>

void search(char* txt, char* pat)
{

    int a=strlen(txt);
    int b=strlen(pat);
    int i;
    int badChar[256];
    for(i=0;i<256;i++)
        badChar[i]=b;
    for(i=b-1;i>=0;i--)
        badChar[*(pat+i)]=i-b+1;
    int s=0;
    for(i=b-1;i<a;i=i+s)
    {
        int j=i,count=b;
        while((*(txt+j)==*(pat+(count-1))) && count>0)
        {
            j--;
            count--;
        }
        if(count==0)
        {
            printf("found at %d\n",i-b+2);
            return;
        }
        else
        s=badChar[*(txt+j)];
    }

}



int main()
{
    char txt[] = "ttstisatesttext";
    char pat[] = "test";
    search(txt,pat);
    return 0;
}
