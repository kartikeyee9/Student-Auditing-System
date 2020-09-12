#ifndef STUDENT_H
#define STUDENT_H

#include "defs.h"
#include "Course.h"
#include "List.h"

class Student
{
  public:
    Student(int=0);
    ~Student();
    void print();
    Student& operator+=(Course* );
    float computeGPA();
  	int computeNumFW();
  	int getId();

  private:
    int    id;
   	CourseList courses;
    int    numCourses;
};

#endif
