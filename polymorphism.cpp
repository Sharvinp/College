#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      int width, height;
      
   public:
      Shape( int a, int b){
         width = a;
         height = b;
      }
      virtual int area() {
         cout << "Area :" <<endl;
         return 0;
      }
};
class Rectangle: public Shape {
   public:
      Rectangle( int a, int b):Shape(a, b) { }
      
      int area () { 
         cout << "Area of rectangle:" <<endl;
         return (width * height); 
      }
};

class Triangle: public Shape {
   public:
      Triangle( int a, int b):Shape(a, b) { }
      
      int area () { 
         cout << "Area of triangle :" <<endl;
         return (width * height / 2); 
      }
};

// Main function for the program
int main() {
   Shape *shape;
   Rectangle rec(16,11);
   Triangle  tri(12,8);

   // store the address of Rectangle
   shape = &rec;
   
   // call rectangle area.
   shape->area();

   // store the address of Triangle
   shape = &tri;
   
   // call triangle area.
   shape->area();
   
   return 0;
}