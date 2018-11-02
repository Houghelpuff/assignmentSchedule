#include <iostream>
#include "schedule_classes.hpp"
#include <fstream>
using namespace std;

//functions to add assignments to the schedule

void menu(AssignmentTracker t){
  int numChoice;
  bool valid = true;

  cout << "What would you like to do?\n1. View assignments Due\n2.Add an assignment\n3.Complete an assignment\n4. Save and quit" << endl;
  cin >> numChoice;

if(numChoice < 1 || numChoice > 3){
  cout << "Please choice a valid option" << endl;
  valid = false;
}

while(valid == false){
  cin >> numChoice;

  if(numChoice < 1 && numChoice > 3){ cout << "Please choice a valid option" << endl; }

  else { valid = true;}
}

if(numChoice == 1){
  t.print();
}

}

int main(){
  Assignment incomplete[50];

  Assignment a1("Read p. 1-10", "ASTR", 13, 10);
  incomplete[0] = a1;

  AssignmentTracker TRACKER(incomplete);

  //cout << "Assignment: " << a1.getToDo() << " for " << a1.getClassName() << " due on " << a1.getDayDue() << "/" << a1.getMonthDue() << endl;
  //cout << "Assignment: " << incomplete[0].getToDo() << " for " << incomplete[0].getClassName() << " due on " << incomplete[0].getMonthDue() << "/" << incomplete[0].getDayDue() << endl;

  menu(TRACKER);

  }
