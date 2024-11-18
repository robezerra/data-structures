#include <iostream>

using namespace std;

class Student {
private:
  int code;
  std::string name;

public:
  Student();
  Student(int code, string name);
  int getCode();
  string getName();
};