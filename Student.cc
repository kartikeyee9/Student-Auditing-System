#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Student.h"
#include "List.h"

Student::Student(int i)
{
  id = i;
  numCourses = 0;
  
}

Student::~Student() {
  
}

Student&  Student::operator+=(Course* course) {
  courses += course;
  return *this;
}



void Student::print()
{
  cout<< endl << "Id: " << id << endl;
  courses.print();
  cout << "GPA: " << computeGPA() << endl;
}

float Student::computeGPA()
{
  return courses.computeGPA();
}


int Student::computeNumFW()
{
  return courses.computeNumFW();
}

int Student::getId()
{
  return id;
}



