#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Storage.h"
#include "Student.h"

Storage::Storage()
{
  numStudents = 0;
  students = new Student*[MAX_NUM_STU];
  
}

Storage::~Storage() {
  for (int i = 0; i < numStudents; ++i)
  {
    delete students[i];
  }
  delete[] students;
}

Storage& Storage::operator+=(Student* student) {
  students[numStudents++] = student;
  return *this;
}



void Storage::print()
{
  for (int i=0; i<numStudents; ++i)
    students[i]->print();
}

