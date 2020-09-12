#ifndef CONTROL_H
#define CONTROL_H

#include <string>
#include <vector>
#include "Storage.h"
#include "View.h"
#include "Monitor.h"
#include "StuServer.h"

class Control
{
  public:
  	Control();
  	~Control();
    void launch();
    void notify(Student* newStu);

  private:
  	Storage storage;
   	View view;
   	vector<Monitor*> monitors;
   	StuServer server;
};

#endif
