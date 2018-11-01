#include <iostream>
#include "schedule_classes.hpp"
#include <fstream>
using namespace std;

//functions to add assignments to the schedule

int main(){
  Assignment incomplete[50];

  Assignment a1("Read p. 1-10", "ASTR", 13, 10);
  incomplete[0] = a1;

  AssignmentTracker TRACKER(incomplete);

  //cout << "Assignment: " << a1.getToDo() << " for " << a1.getClassName() << " due on " << a1.getDayDue() << "/" << a1.getMonthDue() << endl;
  //cout << "Assignment: " << incomplete[0].getToDo() << " for " << incomplete[0].getClassName() << " due on " << incomplete[0].getMonthDue() << "/" << incomplete[0].getDayDue() << endl;

  TRACKER.addAssignment();

  cout << "\n";

  TRACKER.print();

  }
