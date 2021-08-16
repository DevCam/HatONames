// HatLib
// Select random names from a "hat"

#ifndef HATLIB_H
#define HATLIB_H

#define MAX_STUDENT_NAME_LEN 255

typedef struct student
{
  char name[MAX_STUDENT_NAME_LEN];
}
student;

typedef struct hat
{
  int capacity;
  int count;
  student **students;
}
hat;

hat *HatNew(int capacity);
hat *HatNewFromFile(const char *path, int maxStudents);
void HatDelete(hat *hat);

student *HatPullName(hat *hat);
void HatPutName(hat *hat, student* student);

#endif
