#include<stdio.h>
#include<conio.h>
int i=0;
void A(char []);
void error();
void APRIME(char []);
void S(char arr[])
{
   if(arr[i]=='b')
   i++;
   else
   {              
   A(arr);
   if(arr[i]=='a')
   (i)++;
}
   if(arr[i]=='$')
   printf("accepted");
   else
   error();
   return;
}

void A(char arr[])
{
 if(arr[i]=='b')
 {
      (i)++;  
      if(arr[i]=='d')
      {
                        (i)++;
                        APRIME(arr);
      }
      else 
      error();                  
 }
  else
  APRIME(arr);
  return;                  
}

void APRIME(char arr[])
{
 
      if(arr[i]=='c')
      {
             (i)++;
             APRIME(arr);
                  
                        }
       else if(arr[i]=='a')
       {
            (i)++;
            
            if(arr[i]=='d')
            {
                        (i)++;
                        APRIME(arr);
            }
            else
            return;       
      }
      else
      error();
      return;      
}

void error()
{
     printf("not accepted");
     i++;
     return;
}


int main()
{
    char arr[100];
    printf("enter the string\n");
    gets(arr);
    
    S(arr);  
    getch();
    return 0; 
}        
