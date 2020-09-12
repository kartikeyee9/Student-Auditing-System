#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "Storage.h"


class View
{
public:
	int displayMenuAndRead();
	void readStudentId(int& id);
	void readCourseDetails(int &courseCode, int &grade, int &term, string &instructor);
	void print(Storage& s);
};

#endif
