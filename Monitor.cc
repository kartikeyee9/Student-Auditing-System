#include <string>
#include <iostream>
#include <vector>
#include "Monitor.h"
#include "Student.h"


using namespace std;

void Monitor::printLogs() {
	cout << "---------- LOGS ----------" << endl;
	for (int i=0; i<logs.size(); ++i)
    	cout << logs[i] << endl;
    cout << "--------------------------" << endl;
}

GPAMonitor::GPAMonitor(float threshold) {
	minThreshold = threshold;
}

void GPAMonitor::update(Student* s){
	if(s->computeGPA() < minThreshold) {
		logs.push_back(to_string(s->getId()) + " -> GPA: " + to_string(s->computeGPA()));
	}
}

FWMonitor::FWMonitor(int threshold) {
	minThreshold = threshold;
}

void FWMonitor::update(Student* s){
	if(s->computeNumFW() > minThreshold) {
		logs.push_back(to_string(s->getId()) + " -> F/W: " + to_string(s->computeNumFW()));
	}
}

