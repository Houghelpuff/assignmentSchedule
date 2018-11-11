#include <iostream>
#ifndef SCHEDULE_CLASSES_H
#define SCHEDULE_CLASSES_H

const int SIZE = 50;

class Assignment {
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

Assignment::Assignment() {
  toDo = "";
  className = "";
  day = -1;
  month = -1;
}

Assignment::Assignment(std::string to, std::string name, int d, int m) {
  toDo = to;
  className = name;
  day = d;
  month = m;
}

Assignment::~Assignment() {}

std::string Assignment::getToDo() {
  return toDo;
}

void Assignment::setToDo(std::string str) {
  toDo = str;
}

std::string Assignment::getClassName() {
  return className;
}

void Assignment::setClassName(std::string str) {
  className = str;
}

int Assignment::getDayDue() {
  return day;
}

void Assignment::setDayDue(int d) {
  day = d;
}

int Assignment::getMonthDue() {
  return month;
}

void Assignment::setMonthDue(int m) {
  month = m;
}

class AssignmentTracker {
 private:
  int front, rear;
  Assignment assignments[SIZE];

 public:
  AssignmentTracker();              // done
  AssignmentTracker(Assignment[]);  // done
  bool isEmpty();                   // done
  void addAssignment();             // done
  void completeAssignment();
  Assignment peek(int);  // done
  void print();          // done
};

AssignmentTracker::AssignmentTracker() {
  front = rear = -1;

  for (int i = 0; i < 50; i++) {
    assignments[i].setToDo("None");
    assignments[i].setClassName("None");
    assignments[i].setDayDue(-1);
    assignments[i].setMonthDue(-1);
    rear++;
  }
}

AssignmentTracker::AssignmentTracker(Assignment work[]) {
  if (work[0].getDayDue() == -1) {
    front = rear = -1;
  }

  else {
    for (int i = 0; i < 50; i++) {
      if (work[i].getDayDue() == -1) {
        rear = i - 1;
        break;
      }
      assignments[i] = work[i];
    }
  }
}

bool AssignmentTracker::isEmpty() {
  if (front == rear) {
    std::cout << "Front: " << this->front << " Rear: " << this->rear
              << std::endl;
    return true;
  }

  else {
    return false;
  }
}

void AssignmentTracker::addAssignment() {
  std::string forClass;
  std::string what;
  std::string due;

  std::cout << "What class is this for?" << std::endl;
  std::cin.ignore();
  getline(std::cin, forClass);

  std::cout << "\nWhat is the assignment" << std::endl;
  getline(std::cin, what);

  std::cout << "\nWhat day is it due? (In mm/dd format)" << std::endl;
  std::cin >> due;

  std::cout << "\nAssignment added to calender!" << std::endl;

  int d = stoi(due.substr(3, 4));
  int m = stoi(due.substr(0, 1));

  Assignment newAssignment(what, forClass, d, m);

  if (isEmpty()) {
    front = rear = 0;
    std::cout << "Test" << std::endl;
  }

  else {
    rear = (rear + 1) % SIZE;
  }

  std::cout << "Front: " << this->front << " Rear: " << this->rear << std::endl;

  assignments[rear] = newAssignment;
}

void AssignmentTracker::print() {
  if (this->isEmpty() == true) {
    std::cout << "There are no assignments due!" << std::endl;
  }

  else {
    for (int i = 0; i < rear + 1; i++) {
      std::cout << assignments[i].getToDo() << " "
                << assignments[i].getClassName() << " "
                << assignments[i].getMonthDue() << "/"
                << assignments[i].getDayDue() << std::endl;
    }
  }
}

Assignment AssignmentTracker::peek(int idx) {
  return assignments[idx];
}

void AssignmentTracker::completeAssignment() {
  if (isEmpty()) {
    std::cout << "You have no assignments to complete" << std::endl;
  }

  else if (front == rear) {
    front = rear = -1;
  }

  else {
    front = (front + 1) % SIZE;
  }
}

#endif
