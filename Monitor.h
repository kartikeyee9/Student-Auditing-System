#ifndef MONITOR_H
#define MONITOR_H
using namespace std;
#include <string>
#include <vector>
#include "Student.h"

class Monitor
{
  public:
    virtual void update(Student*) = 0;
    void printLogs();

  protected:
    vector<string> logs;
};


class GPAMonitor: public Monitor {
public:
  GPAMonitor(float=0);
  virtual void update(Student*);

private:
  float minThreshold;
};

class FWMonitor: public Monitor {
public:
  FWMonitor(int=0);
  virtual void update(Student*);

private:
  int minThreshold;
};

#endif
