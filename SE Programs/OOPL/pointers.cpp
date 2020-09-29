#include <iostream>
using namespace std;

int main() {
  int *x = new int;
  int *y = new int;
  int *add = new int;
  cout << "Enter first number: ";
  cin >> *x;
  cout << "Enter second number: ";
  cin >> *y;
  *add = *x + *y; // Just like normal addition
  cout << "Addition is: " << *add << endl;
  delete x;
  cout << "First pointer deleted." << endl;
  delete y;
  cout << "Second pointer deleted." << endl;
  delete add;
  cout << "Addition pointer deleted." << endl;
}