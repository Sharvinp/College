#include <iostream>
using namespace std;

class myClass {
  static int i;
  public:
  void add(int a, int b) {
    cout << "Addition: " << (a + b) << endl;
    i++;
  }
  static void display() {
    cout << "The number of times the function has been called is: " << i << endl;
  }
};
int myClass :: i;
int main() {
  myClass obj1, obj2, obj3;
  obj1.add(22, 20);
  obj2.add(105, 206);
  obj3.add(46, 98);
  myClass :: display();
}