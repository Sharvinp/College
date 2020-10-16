import java.util.*;
class Employee
{
int emp_id;
String name;
String add;
String mail_id;
long mob_no;
Scanner s = new Scanner(System.in);
public void getdata()
{
System.out.println("Enter ID: ");
emp_id = s.nextInt();
System.out.println("Enter name: ");
name = s.nextLine();
System.out.println("Enter address: ");
add = s.nextLine();
System.out.println("Enter mail id: ");
mail_id = s.nextLine();
System.out.println("Enter mobile no.: ");
mob_no = s.nextLong();
}
public void putdata()
{
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
System.out.println("Name : "+name);
System.out.println("ID : "+emp_id);
System.out.println("Address : "+add);
System.out.println("Mail Id : "+mail_id);
System.out.println("Mobile No. : "+mob_no);
}
}
class Programmer extends Employee
{

double bp, da, hra, pf, cf, gs, net;
public void getdetails()
{
System.out.println("Enter basic pay of Programmer: ");
bp = s.nextDouble();
}
public void putdetails()
{
putdata();
da = 0.97*bp;
hra = 0.10*bp;
pf = 0.12*bp;
cf = 0.001*bp;
gs = bp + da + hra;
net = gs - pf - cf;
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
System.out.println(" PAY SLIP");
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
System.out.println("Bsic Pay : Rs "+bp+"/-");
System.out.println("DA : Rs "+da+"/-");
System.out.println("HRA : Rs "+hra+"/-");
System.out.println("PF : Rs "+pf+"/-");
System.out.println("CLUB FUND : Rs "+cf+"/-");
System.out.println("GROSS PAY : Rs "+gs+"/-");
System.out.println("NET PAY : Rs "+net+"/-");
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
}
}
class TeamLead extends Employee
{
double bp, da, hra, pf, cf, gs, net;
public void getdetails()
{
System.out.println("Enter basic pay of Team Lead: ");
bp = s.nextDouble();
}
public void putdetails()
{
putdata();
da = 0.97*bp;
hra = 0.10*bp;
pf = 0.12*bp;

cf = 0.001*bp;
gs = bp + da + hra;
net = gs - pf - cf;
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
System.out.println(" PAY SLIP");
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
System.out.println("Bsic Pay : Rs "+bp+"/-");
System.out.println("DA : Rs "+da+"/-");
System.out.println("HRA : Rs "+hra+"/-");
System.out.println("PF : Rs "+pf+"/-");
System.out.println("CLUB FUND : Rs "+cf+"/-");
System.out.println("GROSS PAY : Rs "+gs+"/-");
System.out.println("NET PAY : Rs "+net+"/-");
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
}
}
class AsstProManager extends Employee
{
double bp, da, hra, pf, cf, gs, net;
public void getdetails()
{
System.out.println("Enter basic pay of Assistent Project Manager: ");
bp = s.nextDouble();
}
public void putdetails()
{
putdata();
da = 0.97*bp;
hra = 0.10*bp;
pf = 0.12*bp;
cf = 0.001*bp;
gs = bp + da + hra;
net = gs - pf - cf;
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
System.out.println(" PAY SLIP");
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
System.out.println("Bsic Pay : Rs "+bp+"/-");
System.out.println("DA : Rs "+da+"/-");
System.out.println("HRA : Rs "+hra+"/-");
System.out.println("PF : Rs "+pf+"/-");
System.out.println("CLUB FUND : Rs "+cf+"/-");
System.out.println("GROSS PAY : Rs "+gs+"/-");
System.out.println("NET PAY : Rs "+net+"/-");

System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
}
}
class ProManager extends Employee
{
double bp, da, hra, pf, cf, gs, net;
public void getdetails()
{
System.out.println("Enter basic pay of Project Manager: ");
bp = s.nextDouble();
}
public void putdetails()
{
putdata();
da = 0.97*bp;
hra = 0.10*bp;
pf = 0.12*bp;
cf = 0.001*bp;
gs = bp + da + hra;
net = gs - pf - cf;
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
System.out.println(" PAY SLIP");
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
System.out.println("Bsic Pay : Rs "+bp+"/-");
System.out.println("DA : Rs "+da+"/-");
System.out.println("HRA : Rs "+hra+"/-");
System.out.println("PF : Rs "+pf+"/-");
System.out.println("CLUB FUND : Rs "+cf+"/-");
System.out.println("GROSS PAY : Rs "+gs+"/-");
System.out.println("NET PAY : Rs "+net+"/-");
System.out.println("----*----*----*----*----*----*----*----*----*----*----*----*----*----");
}
}
public class Main
{
public static void main(String[] args) {
int choice;
Scanner s = new Scanner(System.in);
System.out.println("PAY SLIP OF:");
System.out.println("1. Programmer\n2. Team Lead\n3. Assistant Project Manager\n4.

Project Manager");

System.out.println("5. Exit");

do
{
System.out.println("\nEnter your choice: ");
option = s.nextInt();
switch(choice)
{
case 1:{
Programmer p = new Programmer();
p.getdata();
p.getdetails();
p.putdetails();
break;
}
case 2:{
TeamLead t = new TeamLead();
t.getdata();
t.getdetails();
t.putdetails();
break;
}
case 3:{
AsstProManager ap = new AsstProManager();
ap.getdata();
ap.getdetails();
ap.putdetails();
break;
}
case 4:{
ProManager pm = new ProManager();
pm.getdata();
pm.getdetails();
pm.putdetails();
break;
}
case 5:{
System.out.println("Done!!");
break;
}
default:{
System.out.println("Wrong choice!!");
break;

}
}
}while(option!=5);
}
}
