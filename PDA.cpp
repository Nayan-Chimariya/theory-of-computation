#include <stdio.h>
void maketransition(char,char,int);
void push(char);
void pop();
char gettop();
int current=0;
char stack[20];
int top=-1;
void push(char c)
{
    if(top==19)
    {
        printf("stack full");
        return;
    }
    stack[++top]=c;
}
void pop()
{
    if(top==-1)
    {
        printf("stack empty");
        return;
    }
    stack[top]=' ';
    top--;
}
char gettop()
{
    if (top==-1)
    {
        printf("STACK IS EMPTY");
        return 'e';
    }
return stack[top];

}

void maketransition(char c,char st,int state)
{
    switch(state)
    {
        case 0:
        if(c=='e'&& st=='e')
        {
            push('$');
            current=1;
        }
        break;
        case 1:
        if(c=='0'&& st=='$')
        {
            push('0');
            current=1;
        }
        else if(c=='0' && st=='0')
        {
            push('0');
            current=1;
        }
        else if(c=='0' && st=='1')
        {
            pop();
            current=1;
        }
        else if(c=='1' && st=='$')
        {
            push('1');
            current=1;
        }
        else if(c=='1' && st=='1')
        {
            push('1');
            current=1;
        }
        else if(c=='1' && st=='0')
        {
            pop();
            current=1;
        }
        else if(c=='e' && st=='$')
        {
            pop();
            current=2;
        }
        break;

        case 2:
        break;
    }
}
int main()
{
    char inputstr[20],c;
    int i=0;
    printf("enter an input string:");
    gets(inputstr);
    maketransition('e','e',current);
    c=inputstr[i];
    while(c!='\0')
    {
    maketransition(c,gettop(),current);
    c=inputstr[++i];
    }
    maketransition('e',gettop(),current);

    if (current ==2)
        printf("\nAccepted");
    else
       printf("\nRejected");

    return 0;
}

