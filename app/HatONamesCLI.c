#include <stdio.h>
#include <stdlib.h>
#include "hatlib/hatlib.h"

int main(int argc, char *argv[])
{
  hat *h = NULL;

  if(argc == 2)
  {
    printf("will use studentFile @ %s\n", argv[1]);
    h = HatNewFromFile(argv[1], 24);
  }
  else
  {
    h = HatNew(16);
  }

  int cmd = 0;
  printf("~HoN 0.1.1\n> ");
  while((cmd = fgetc(stdin)) != EOF)
  {
    if(cmd == 'p')
    {
      student *s = NULL;
      s = HatPullName(h);
      if(s != NULL)
      {
        printf("Pulled: %s> ", s->name);
        free(s);
      }
      else
      {
        printf("No more names in hat :(\n> ");
      }
    }
  }
  return 0;
}
