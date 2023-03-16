#include<iostream>

using namespace std;

int current = 0;

void q0(char c)
{
	if(c=='0')
		current = 1;
	else if(c=='1')
		current = 0;
	else
		current =-1;
}

void q1(char c)
{
	if(c=='0')
		current = 2;
	else if(c=='1')
		current = 0;
	else
		current =-1;
}

void q2(char c)
{
	if(c=='0')
		current = 1;
	else if(c=='1')
		current = 3;
	else
		current =-1;
}

void q3(char c)
{
	if(c=='0')
		current = 1;
	else if(c=='1')
		current = 3;
	else
		current =-1;
}

int main()
{
	char str[10],c;
	int i=0;
	printf("Enter the input string: ");
	gets(str);
	c=str[i];
	while(c!='\0')
	{
		switch(current){
			case 0:
				q0(c);
				break;
			case 1:
				q1(c);
				break;
			case 2:
				q2(c);
				break;
			case 3:
				q3(c);
				break;
			default:
				break;
		}
		c=str[++i];
	}
	if(current == 3)
		printf("Accepted");
	else
		printf("Rejected");
	return 0;
}
