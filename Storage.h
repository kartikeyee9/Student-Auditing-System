#ifndef STORAGE_H
#define STORAGE_H

#include "defs.h"
#include "Student.h"

class Storage
{
  public:
    Storage();
    ~Storage();
    void print();
    Storage& operator+=(Student* );

  private:
    Student** students;
    int    numStudents;
};

#endif
