#include "student.h"

Student::Student() {
  code = -1;
  name = " ";
}

Student::Student(int code, string name) {
  this->code = code;
  this->name = name;
};

int Student::getCode() {
  return code;
};

string Student::getName() {
  return name;
};