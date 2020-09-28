#include <iostream>
using namespace std;

int main() {
  // new keyword is used for dynamic memory allocation
  // Syntax : datatype ptr_name = new datatype;
  int *ptr1 = new int(16); 
  float *ptr2 = new float(16.13);
  char *ptr3 = new char('a');
  cout << "Integer pointer is: " << *ptr1 << endl;
  cout << "Float pointer is: " << *ptr2 << endl;
  cout << "Character pointer is: " << *ptr3 << endl;
  // Delete is used to destroy the variable space which has been created using the new operator dynamically
  // Syntax : delete ptr_name;
  delete ptr1;
  cout << "Integer pointer deleted using delete keyword." << endl;
  delete ptr2;
  cout << "Float pointer deleted using delete keyword." << endl;
  delete ptr3;
  cout << "Character pointer deleted using delete keyword." << endl;
}