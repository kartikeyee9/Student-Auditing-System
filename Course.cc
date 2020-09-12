#include <iostream>
#include <iomanip>
#include <string>


#include "Course.h"

using namespace std;


Course::Course(int c, int g, int t, string i)
{
  code  = c;
  grade = g;
  term = t;
  instructor = i;
}


void Course::print()
{
  string str;

  cout << "-- COMP " << code << " " << term << ": " ;
  cout << right << setw(2) << grade   << "  ";
  getGradeStr(str);
  cout << left << setw(3) << str;
  cout << " " << instructor << endl;

}

void Course::getGradeStr(string& gradeStr)
{
  string gradeStrings[] = {
    "WDN", "F", "D-", "D", "D+", "C-", "C", "C+", 
    "B-", "B", "B+", "A-", "A", "A+" };

  if ( grade >= -1 && grade <= 12 )
    gradeStr = gradeStrings[grade+1];
  else
    gradeStr = "Unknown";
}

bool Course::lessThan(Course* other){
  if(code < other->code)
    return true;
  else if(code == other->code)
    return term < other->term;
  else
    return false;
}

int Course::getGrade() {
  return grade;
}

