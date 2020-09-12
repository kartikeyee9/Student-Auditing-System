#include <iostream>
#include <string>
#include "Storage.h"
#include "View.h"

using namespace std;

int View::displayMenuAndRead(){
	int numOptions = 1;
	int selection = -1;

	cout << endl;
	cout << "(1) Add student" << endl;
	cout << "(0) Exit" << endl;

	while (selection < 0 || selection > numOptions) {
		cout << "Enter your selection: ";
		cin >> selection;
	}

	return selection;
}

void View::readStudentId(int &id){
 	cout << "student id:   ";
    cin  >> id;
}

void View::readCourseDetails(int &courseCode, int &grade, int &term, string &instructor) {
	cout << "course code <0 to end>:  ";
    cin  >> courseCode;
    if (courseCode == 0)
     	return;


    cout << "grade:                   ";
    cin  >> grade;

    cout << "term:                    ";
    cin  >> term;

    cout << "instructor:              ";
    cin  >> instructor;
}

void View::print(Storage& s) {
	s.print();
}


