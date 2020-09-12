#ifndef COURSE_H
#define COURSE_H

#include <string>


using namespace std;

class Course
{
  public:
    Course(int=0, int=0, int=0,string="unknown");
    void print();
    bool lessThan(Course* c);
    int getGrade();

  private:
    int code;	// course code, for example 2404 for COMP2404
    int grade;	// numeric grade from 0 (F) to 12 (A+), with -1 for WDN
    int term;
    string instructor;
    void getGradeStr(string&);
};

#endif
