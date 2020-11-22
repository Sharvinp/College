import java.util.*;
class Excep (
Scanner sc = new Scanner( System.1n) ;
1nt numl,num2;
f1oat result ;
Int[ ] arr = (I, 2,3,4,5, 6, 7, 8,9,10) ;
int num;
void getNums()(
try (
System.out.println(“Enter number 1: “); numl=Integer.parseInt(sc.next()); sc.nextLine(); System.out.println(“Enter number 2: “); numZ-Integer.parseInt(sc.next());
sc . nextL1ne( ) ;
result = num1/num2;
System.out.println(“The value of numl/num2 is “+result);
 
catch(ArithmeticException e) ‹ System.out.println(“\n••*******EXCEPTI0N CAUGHT*””””””’“); System.out,println(“The denominator cannot be O!\nJava says:
’+e.getMessage());
 
catch(NumberFormatException e1) { System.out.println(”\n"***”°’*EXCEPTION CAUlHT”*’**’*””””); System.our.println(“The input must be a number gnlyl\nJava says:
"+e1. getNessage ( ) ) ;
 
finally (
System.out.println(“All done!!!\n“);
 
 
void readArray() (
System.out.prInt1n(”Enter the position whose value you want to read(0-9): ”);
try (
num=Integer.parseInt(sc.next()); sc.nextLine();
System.out.println(“The element you are looking for is: ’+arr[num]);
 
catch(Arrayl ndex0ut0fBoundsExcept1on e2) (
System. out . pr1ntln("\n”’* *“’**EXCEPTION CAUGHT”*”***”***’**" );
System.out.println(“Please enter a number between 1 to 10.\nJava
says : "+e2. getfdess age( ) ) ;
 
catch(NumberFormatException e3) { System.out.println(’\n**"******EXCEPTI0N CAUGHT*°***’°**°"°**”); System.out.println(“The input must be a number only!\nJava says:
’+e3.getMessage()); 
I-Inal ly (
Systen. out . pr1nt1n("All done I I I \n" ) ;
public class Excpetions {
pub11c stat:tC void naln (5tr1ng[ ] arts) ( scanner sc = new Sc anne (system. In) ; int choice-0;
ExCep obj a nex Excep( ) j // creat 1ng object of- Excep class
do (

System. out . pr1nt1n("”””  ' *”””” OP TIONS	"’	”*”") ; System. out , pr1ntln("1. Perl-arm d1vis1on of tuo number,s
");

System. out . pr1n t 1n("2. Read a va1ue of predef1ned array. \n3. Ex1t” ) ;
 
System. out . pr1nt In( "Enter your cholc e : ") j cho1ce = Integer.parselnt(sc .next ( ) ) ;
s c , next L1ne ( ) ;
switch(chgice) { case 1:
obj.getN ums();
break;
 
obj . readArray( ) ; break;
case 3:
break; default:
System.out.pr1ntln(-Please enter a number from 1 to 3.“);
break;
 
catch(NunberFornatExcept1on e4)(
System. out . pr1nt1n( "\ n’ * ””‘* *EXCEPTION CAUGHT’””’”• ””*”**") ;
System,out.println(”Java say5: “+e4,getMe5sage()+“\n”);
 
} wh11e ( cho1ce I =3) ;
