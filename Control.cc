#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "Control.h"
#include "View.h"
#include "Storage.h"
#include "Course.h"
#include "Student.h"
#include "Monitor.h"
#include "StuServer.h"

using namespace std;

Control::Control() {
	GPAMonitor* gpaMonitor = new GPAMonitor(3.0);
	FWMonitor* fwMonitor = new FWMonitor(2);

	monitors.push_back(gpaMonitor);
	monitors.push_back(fwMonitor); 

	vector<string> allStudents;
	server.retrieve(allStudents);

	int id;
	int code, grade;
	string instructor;
	int term;
	stringstream ss;

	for (int i = 0; i < allStudents.size(); ++i){
		ss.clear();
		ss.str(allStudents[i]);

		ss >> id;

		Student* student = new Student(id);

		while(true) {
			ss >> code;
			if(code == 0)
				break;

			ss >> term >> grade >> instructor;
			(*student) += (new Course(code, grade, term, instructor));
		}

		storage += student;
		notify(student);
	}
}

Control::~Control(){
	for (int i = 0; i < monitors.size(); ++i)
	{
		cout << endl;
		monitors[i]->printLogs();
		delete monitors[i];
	}
}

void Control::launch() {
	  int     stuId, courseCode, grade, term;
	  string instructor;
	  int     menuSelection;

	int choice = view.displayMenuAndRead();
	while(choice != 0) {
		if(choice == 1) {
			view.readStudentId(stuId);

			Student* student = new Student(stuId);

			while(true) {
				view.readCourseDetails(courseCode, grade, term, instructor);
				if(courseCode == 0)
					break;
				else {
					(*student) += (new Course(courseCode, grade, term, instructor));
				}

			}
			
			storage += (student);
			notify(student);
		} 

		choice = view.displayMenuAndRead();
	}

	
	view.print(storage);
}

void Control::notify(Student* newStu){
	for (int i = 0; i < monitors.size(); ++i)
	{
		monitors[i]->update(newStu);
	}
}
