#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int current = 0;

int main()
{
  char inputstr[20], c;
  int i = 0;
  printf("Enter input string: ");
  fgets(inputstr, sizeof(inputstr), stdin);
  while (1)
  {
    c = inputstr[i];
    switch (current)
    {
      case 0:
        if (c == '0')
        {
          inputstr[i] = 'X';
          i++;
          current = 1;
        }

        else if (c == 'Y')
        {
          i++;
          current = 3;
        }

        else
        {
          current = -1;
        }
        break;

      case 1:
        if (c == '0')
        {
          i++;
          current = 1;
        }
        else if (c == 'Y')
        {
          i++;
          current = 1;
        }
        else if (c == '1')
        {
          inputstr[i] = 'Y';
          i--;
          current = 2;
        }
        break;

      case 2:
        if (c == '0')
        {
          i--;
          current = 2;
        }
        else if (c == 'Y')
        {
          i--;
          current = 2;
        }
        else if (c == 'X')
        {
          i++;
          current = 0;
        }
        else
          current = -1;
        break;

      case 3:
        if (c == 'Y')
        {
          i++;
          current = 3;
        }
        else if (c == '\0')
        {
          i++;
          current = 4;
        }
        else
          current = -1;
        }
        break;

    if (current == -1 || current == 4)
      break;
  }

  if (current == 4)
    printf("\nAccepted by TM.\n");
  else
    printf("\nRejected by TM.\n");
}
