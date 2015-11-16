#include<stdio.h>
#include<string.h>

int pos=-1,l;
char id;
char input[100];

void error()
{
    printf("\nnot accepted\n");
    exit(1);
}

void advance()
{
    pos++;
    if(pos<l)
    {
        if(input[pos]>='a' && input[pos]<='z')
        id=input[pos];
    }
}

void S()
{
    if(input[pos]=='b')
    advance();
    if(input[pos]=='a')
    {
        advance();
        A();
    }
}

void A()
{
    if(input[pos]=='b')
    {
        advance();
        if(input[pos]=='d')
        {
            advance();
            Ad();
        }
        else
        error();
    }

    Ad();
}

void Ad()
{
    if(input[pos]=='c')
    {
        advance();
        Ad();
    }
    if(input[pos]=='a')
    {
        advance();
        if(input[pos]=='d')
        {
            advance();
            Ad();
        }
        else
        error();
    }

}

int main()
{
    printf("enter the string:\t");
    scanf("%s",input);
    l=strlen(input);
    input[l]='$';
    advance();
    S();
    if(pos==l)
    printf("\naccepted\n");
    else
    printf("\not accepted\n");
    return 0;
}
