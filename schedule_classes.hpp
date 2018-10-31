#include <iostream>
using namespace std;
#ifndef SCHEDULE_CLASSES_H
#define SCHEDULE_CLASSES_H

const int SIZE = 50;

class Assignment{
  private:
    string toDo;
    string className;
    int day;
    int month;

  public:
    Assignment();
    Assignment(string, string, int, int);
    ~Assignment();

    string getToDo();
    void setToDo(string);

    string getClassName();
    void setClassName(string);

    int getDayDue();
    void setDayDue(int);

    int getMonthDue();
    void setMonthDue(int);
};

Assignment::Assignment(){
  toDo = "";
  className = "";
  day = -1;
  month = -1;
}

Assignment::Assignment(string to, string name, int d, int m){
  toDo = to;
  className = name;
  day = d;
  month = m;
}

Assignment::~Assignment(){

}

string Assignment::getToDo(){
  return toDo;
}

void Assignment::setToDo(string str){
  toDo = str;
}

string Assignment::getClassName(){
  return className;
}

void Assignment::setClassName(string str){
  className = str;
}

int Assignment::getDayDue(){
  return day;
}

void Assignment::setDayDue(int d){
  day = d;
}

int Assignment::getMonthDue(){
  return month;
}

void Assignment::setMonthDue(int m){
  month = m;
}

class assignmentTracker{
  private:
    int front, rear;
    Assignment assignments[SIZE];

  public:
    assignmentTracker();
    assignmentTracker(Assignment[]);
    bool isEmpty();
    void addAssignment();
    void completeAssignment();
    int peek(int);
    void print();
};

assignmentTracker::assignmentTracker(){
  front = rear = 0;

  for(int i = 0; i < 50; i++){
    assignments[i].setToDo("None");
    assignments[i].setClassName("None");
    assignments[i].setDayDue(-1);
    assignments[i].setMonthDue(-1);
    rear++;
  }
}

assignmentTracker::assignmentTracker(Assignment work[]){
  front = 0;
  for(int i = 0; i < 50; i++){
    if(work[i].getDayDue() == -1){
      rear = i-1;
      break;
    }
    assignments[i] = work[i];
  }
}

bool assignmentTracker::isEmpty(){
  if(front == rear){
    return true;
  }

  else{
    return false;
  }
}

void assignmentTracker::addAssignment(){
  string forClass;
  string what;
  string due;

  cout << "What class is this for?" << endl;
  cin >> forClass;

  cout << "\nWhat is the assignment" << endl;
  cin >> what;

  cout << "\nWhat day is it due? (In mm/dd format)" << endl;
  cin >> due;

  cout << "\nAssignment added to calender!" << endl;

  int d = stoi(due.substr(3,4));
  int m = stoi(due.substr(0,1));

  Assignment newAssignment(what, forClass, d, m);

  assignments[rear] = newAssignment;

  rear++;

}

void assignmentTracker::print(){
  for(int i = 0; i < rear; i++){
    cout << assignments[i].getToDo() << " " << assignments[i].getClassName() << " " << assignments[i].getMonthDue() << " " << assignments[i].getDayDue() << endl;
  }

}






#endif
