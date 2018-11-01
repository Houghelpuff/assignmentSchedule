#include <iostream>
#ifndef SCHEDULE_CLASSES_H
#define SCHEDULE_CLASSES_H

const int SIZE = 50;

class Assignment{
  private:
    std::string toDo;
    std::string className;
    int day;
    int month;

  public:
    Assignment();
    Assignment(std::string, std::string, int, int);
    ~Assignment();

    std::string getToDo();
    void setToDo(std::string);

    std::string getClassName();
    void setClassName(std::string);

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

Assignment::Assignment(std::string to, std::string name, int d, int m){
  toDo = to;
  className = name;
  day = d;
  month = m;
}

Assignment::~Assignment(){

}

std::string Assignment::getToDo(){
  return toDo;
}

void Assignment::setToDo(std::string str){
  toDo = str;
}

std::string Assignment::getClassName(){
  return className;
}

void Assignment::setClassName(std::string str){
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

class AssignmentTracker{
  private:
    int front, rear;
    Assignment assignments[SIZE];

  public:
    AssignmentTracker();
    AssignmentTracker(Assignment[]);
    bool isEmpty();
    void addAssignment();
    void completeAssignment();
    int peek(int);
    void print();
};

AssignmentTracker::AssignmentTracker(){
  front = rear = 0;

  for(int i = 0; i < 50; i++){
    assignments[i].setToDo("None");
    assignments[i].setClassName("None");
    assignments[i].setDayDue(-1);
    assignments[i].setMonthDue(-1);
    rear++;
  }
}

AssignmentTracker::AssignmentTracker(Assignment work[]){
  front = 0;
  for(int i = 0; i < 50; i++){
    if(work[i].getDayDue() == -1){
      rear = i-1;
      break;
    }
    assignments[i] = work[i];
  }
}

bool AssignmentTracker::isEmpty(){
  if(front == rear){
    return true;
  }

  else{
    return false;
  }
}

void AssignmentTracker::addAssignment(){
  std::string forClass;
  std::string what;
  std::string due;

  std::cout << "What class is this for?" << std::endl;
  getline(std::cin, forClass);

  std::cout << "\nWhat is the assignment" << std::endl;
  getline(std::cin, what);

  std::cout << "\nWhat day is it due? (In mm/dd format)" << std::endl;
  std::cin >> due;

  std::cout << "\nAssignment added to calender!" << std::endl;

  int d = stoi(due.substr(3,4));
  int m = stoi(due.substr(0,1));

  Assignment newAssignment(what, forClass, d, m);

  assignments[rear] = newAssignment;

  rear++;

}

void AssignmentTracker::print(){
  for(int i = 0; i < rear; i++){
    std::cout << assignments[i].getToDo() << " " << assignments[i].getClassName() << " " << assignments[i].getMonthDue() << " " << assignments[i].getDayDue() << std::endl;
  }
}






#endif
