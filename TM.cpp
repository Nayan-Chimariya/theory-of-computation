#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int current = 0;
  char inputstr[20],i;

  for(i=0; i<20; i++)
      inputstr[i]='\0';

  printf("Enter input string: ");
  gets(inputstr);

  i=0;
  while (1)
  {
    switch (current)
    {
      case 0:
        if (inputstr[i] == '0')
        {
            current = 1;
            inputstr[i] = 'X';
            i++;
        }

        else if (inputstr[i] == 'Y')
        {
          current = 3;
          i++;
        }

        else
          current = -1;

        break;

      case 1:
        if (inputstr[i] == '0')
        {
            current = 1;
            i++;
        }

        else if (inputstr[i] == 'Y')
        {
          current = 1;
          i++;
        }

        else if (inputstr[i] == '1')
        {
            current = 2;
            inputstr[i] = 'Y';
            i--;
        }

        else
            current = -1;

        break;

      case 2:
        if (inputstr[i] == '0')
        {
          current = 2;
          i--;
        }

        else if (inputstr[i] == 'Y')
        {
          current = 2;
          i--;
        }

        else if (inputstr[i] == 'X')
        {
          current = 0;
          i++;
        }

        else
          current = -1;

        break;

      case 3:
        if (inputstr[i] == 'Y')
        {
            current = 3;
            i++;
        }

        else if (inputstr[i] == '\0')
        {
          current = 4;
        }

        else
          current = -1;

        break;
    }

    if (current == -1 || current == 4)
      break;
  }

  if (current == 4)
    printf("\nAccepted by TM.\n");
  else
    printf("\nRejected by TM.\n");
}
