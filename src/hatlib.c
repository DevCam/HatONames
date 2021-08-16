#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "hatlib/hatlib.h"

hat *HatNew(int capacity)
{
  srand(time(NULL));
  hat *hat = malloc(sizeof(hat));
  hat->capacity= capacity;
  hat->students= calloc(capacity, sizeof(student*));
  hat->count= 0;
  return hat;
}

void HatDelete(hat *hat)
{
  for(int i=0; i < hat->capacity; i++)
  {
    if(hat->students[i] != NULL) free(hat->students[i]);
  }
  free(hat->students);
  free(hat);
}

student *HatPullName(hat *hat)
{
  if(hat->count > 0)
  {
    int r = rand();
    while(hat->students[r % hat->capacity] == NULL) r++;
    student* s = hat->students[r % hat->capacity];
    hat->count--;
    hat->students[r % hat->capacity] = NULL;
    return s;
  }
  return NULL;
}

void HatPutName(hat *hat,student *student)
{
  for(int i=0; i < hat->capacity; i++)
  {
    if(hat->students[i] == NULL)
    {
      hat->students[i] = student;
      hat->count++;
      return;
    }
  }
}

hat *HatNewFromFile(const char *path, int maxStudents)
{
  FILE *f = NULL;
  f = fopen(path, "r");
  if(f == NULL)
  {
    fprintf(stderr, "Cant open file @ %s\n", path);
    return NULL;
  }

  char buffer[MAX_STUDENT_NAME_LEN];
  hat *h = HatNew(maxStudents);

  while(fgets(buffer, MAX_STUDENT_NAME_LEN, f) != NULL)
  {
    student *s = calloc(1, sizeof(student));
    strcpy(s->name, buffer);
    HatPutName(h, s);
  }

  return h;
}
