import java.util.*;
abstract class Shape
{
double a, b, r;
double area;
Scanner s = new Scanner(System.in);
public void getdata()
{
System.out.println("Enter length: ");
a = s.nextDouble();
System.out.println("Enter breadth: ");
b = s.nextDouble();
}
public void getrad()
{
System.out.println("Enter radius of circle:");
r = s.nextDouble();
}
public abstract void computeArea();
}
class Triangle extends Shape
{
public void computeArea()
{
area = 0.5*a*b;
System.out.println("Area of triangle is: "+area);
}
}
class Rectangle extends Shape
{
public void computeArea()
{
area = a*b;
Name :- Sharvin Pharande
Roll No :- 8022
System.out.println("Area of rectangle is: "+area);
}
}
class Circle extends Shape
{
public void computeArea()
{
area = 3.14*r*r; //pi=3.14
System.out.println("Area of circle is: "+area);
}
}
public class Main
{
public static void main(String[] args) {
int choice;
Triangle tri = new Triangle();
Rectangle rect = new Rectangle();
Circle cir = new Circle();
Scanner s = new Scanner(System.in);
do
{
System.out.println("1.Area of Triangle\n2.Area of Reactangle\n3.Area of Circle\n4.Exit");
System.out.println("Enter your choice:");
choice = s.nextInt();
switch(choice)
{
case 1:
tri.getdata();
tri.computeArea();
break;
case 2:
rect.getdata();
rect.computeArea();
break;
case 3:
cir.getrad();
cir.computeArea();
break;
case 4:
System.out.println("Done!!");
break;
default:
System.out.println("Wrong choice!!");
break;
}
}while(choice!=4);
}
}
