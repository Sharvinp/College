import java.util.*;
interface Vehicles
{
Scanner s = new Scanner(System.in);
public void gearchange();
public void speedup();
public void apply_brakes();
}
class Bicycle implements Vehicles
{
double speed;
int gear;
double newspeed;
public void gearchange()
{
System.out.println("Enter gear of Bicycle: ");
gear = s.nextInt();
}
public void speedup()
{
double add;
System.out.println("Enter spped of Bicycle:");
speed = s.nextDouble();
System.out.println("Enter speed increment:");
add = s.nextDouble();
newspeed = speed + add;
}
public void apply_brakes()
{
double sub;
System.out.println("Enter spped of Bicycle:");
speed = s.nextDouble();
System.out.println("Enter speed decrement:");
sub = s.nextDouble(); Name :- Sharvin Pharande
Roll No :- 8022
newspeed = speed - sub;
}
public void displayBicycle()
{
System.out.println("Gear of Bicycle: "+gear+"\nNew speed of Bicycle: "+newspeed);
}
}
class Bike implements Vehicles
{
double speed;
int gear;
double newspeed;
public void gearchange()
{
System.out.println("Enter gear of Bike: ");
gear = s.nextInt();
}
public void speedup()
{
double add;
System.out.println("Enter spped of Bike:");
speed = s.nextDouble();
System.out.println("Enter speed increment:");
add = s.nextDouble();
newspeed = speed + add;
}
public void apply_brakes()
{
double sub;
System.out.println("Enter spped of Bike:");
speed = s.nextDouble();
System.out.println("Enter speed decrement:");
sub = s.nextDouble();
newspeed = speed - sub;
}
public void displayBike()
{
System.out.println("Gear of Bike: "+gear+"\nNew speed of Bike: "+newspeed);
}
}
class Car implements Vehicles
{
double speed;
int gear;
double newspeed;
public void gearchange()
{
System.out.println("Enter gear of Car: ");
gear = s.nextInt();
}
public void speedup()
{
double add;
System.out.println("Enter spped of Car:");
speed = s.nextDouble();
System.out.println("Enter speed increment:");
add = s.nextDouble();
newspeed = speed + add;
}
public void apply_brakes()
{
double sub;
System.out.println("Enter spped of Car:");
speed = s.nextDouble();
System.out.println("Enter speed decrement:");
sub = s.nextDouble();
newspeed = speed - sub;
}
public void displayCar()
{
System.out.println("Gear of Car: "+gear+"\nNew speed of Car: "+newspeed);
}
}
public class Main
{
public static void main(String[] args) {
int choice;
Scanner s = new Scanner(System.in);
Bicycle b = new Bicycle();
Bike bk = new Bike();
Car c = new Car();
do
{
System.out.println("\n1.Speed up Bicycle\n2.Apply brkes to Bicycle\n3.Speed up Bike");
System.out.println("4.Apply brakes toBike\n5.Speed up Car\n6.Apply brakes to Car\n7.Exit");
System.out.println("\nEnter your choice:");
choice = s.nextInt();
switch(choice)
{
case 1:
b.gearchange();
b.speedup();
b.displayBicycle();
break;
case 2:
b.gearchange();
b.apply_brakes();
b.displayBicycle();
break;
case 3:
bk.gearchange();
bk.speedup();
bk.displayBike();
break;
case 4:
bk.gearchange();
bk.apply_brakes();
bk.displayBike();
break;
case 5:
c.gearchange();
c.speedup();
c.displayCar();
break;
case 6:
c.gearchange();
c.apply_brakes();
c.displayCar();
break;
case 7:
System.out.println("Done!!");
break;
default:
System.out.println("Wron choice!!");
break;
}
}while(choice!=7);
}
}
