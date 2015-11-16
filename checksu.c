#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int data[10][4],i,j=0,len,rem,que,integerdata[10],binary[50],binary1[50],ans;

printf("Enter the lengh of data\n");
scanf("%d",&len);
rem = len %4;

if(rem > 0)
{
  que = (len/4) +1;
}
else
que = que/4;

for(i = 0;i<4-rem;i++)
{
  data[0][i] = 0;
}
printf("enter the data to be entered\n");

for(j = 4-rem;j<4;j++)
scanf("%d",&data[0][j]);

for(i = 1;i<que;i++)
{
  for(j = 0;j<4;j++)
  {
      scanf("%d",&data[i][j]);
  }
  rem = 0;
}

for(i =0;i<que;i++)
{
  for(j = 0;j<4;j++)
  printf("%d ",data[i][j]);
  printf("\n");
}

//convert all the binary data to integer
for(i =0;i<que;i++)
{
 ans = 0;
  for(j = 0;j<4;j++)
  {
    switch(j)
    {
      case 0:
        if(data[i][j] == 1)
        {
          ans = ans + pow(2,3);
        }
        break;
      case 1:
        if(data[i][j] == 1)
        {
          ans = ans + pow(2,2);
        }
        break;
      case 2:
        if(data[i][j] == 1)
        {
          ans = ans + pow(2,1);
        }
        break;
      case 3:
        if(data[i][j] == 1)
        {
          ans = ans + pow(2,0);
        }
        break;
    }
  }
  integerdata[i] = ans;
}


int sum =0;
for(i =0;i<que;i++)
{
  sum = sum + integerdata[i];
}


i = 0;
//int temp = 0;

converttobinary(sum,binary,&i);


if(i > 4)
{
  rem = i%4;
  ans = 0;
  for(j = 0;j<4;j++)
  {
    switch(j)
    {
      case 0:
        if(binary[j] == 1)
        {
          ans = ans + pow(2,0);
        }
        break;
      case 1:
        if(binary[j] == 1)
        {
          ans = ans + pow(2,1);
        }
        break;
      case 2:
        if(binary[j] == 1)
        {
          ans = ans + pow(2,2);
        }
        break;
      case 3:
        if(binary[j] == 1)
        {
          ans = ans + pow(2,3);
        }
        break;
    }
  }



  for(j = 4;j<4+rem;j++)
  {
    switch(j)
    {
      case 4:
        if(binary[j] == 1)
        {
          ans = ans + pow(2,0);
        }
        break;
      case 5:
        if(binary[j] == 1)
        {
          ans = ans + pow(2,1);
        }
        break;
      case 6:
        if(binary[j] == 1)
        {
          ans = ans + pow(2,2);
        }
        break;
      case 7:
        if(binary[j] == 1)
        {
          ans = ans + pow(2,3);
        }
        break;
    }
  }

  printf("binary in reverse = \n");
  for(j = 0;j<i;j++)
  {
    printf("%d ",binary[j]);
  }
  printf("\n");

  int k = 0;
  converttobinary(ans,binary,&k);

  printf("i = %d\n",k);
  if(k<4)
  complete(binary,binary1,k);

  complement(binary1,k);

  for(j = 0;j<k;j++)
  {
    printf("%d ",binary1[j]);
  }
}

return 0;
}


void complete(int binary[50],int binary1[50],int i)
{
  int j;
    binary1[0] = 0;
    for(j = 1;j<=i;j++)
    {
        binary1[j] = binary[j-1];
    }

}


void complement(int binary[50],int *index)
{
  int i;
  for(i = 0;i<index;i++)
  {
    if(binary[i] == 0)
    binary[i]  = 1;
    else
    binary[i] = 0;
  }
}
void converttobinary(int sum,int binary[50],int *index)
{
  while(sum != 0)
  {
    binary[*index] = (sum%2);
    sum = sum/2;
    (*index)++;
  }
}
