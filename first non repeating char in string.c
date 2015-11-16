#include<stdio.h>
#include<string.h>

int func(char* str)
{
    int i;
    int count[256];
    for(i=0;i<256;i++)
    count[i]=0;
    for(i=0;*(str+i);i++)
    count[*(str+i)]++;

    int index=-1;
    for(i=0;*(str+i);i++)
    {
        if(count[*(str+i)]==1)
        {
            index=i;
            break;
        }
    }
    return index;
}

void main()
{
  char str[] = "geeksforgeeks";
  int index =  func(str);
  if(index == -1)
    printf("Either all characters are repeating or string is empty");
  else
   printf("First non-repeating character is %c", str[index]);
}
