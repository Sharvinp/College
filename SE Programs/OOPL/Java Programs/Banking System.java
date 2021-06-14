import java.util.*;

class BankSystem
{
    public String name, date, dob, type, id;
    public int acc_no = 19013000;
    public int acc_id = 3000;
    public long ident_no, bal;
    
    Scanner s = new Scanner(System.in);
    
    public void createAccount()
    {
        
        System.out.println("Fill the following information to create a new account:");
        System.out.println("Name:");
        name = s.nextLine();
        System.out.println("Date Of Birth:");
        dob = s.nextLine();
        System.out.println("Type of Account: ");
        type = s.nextLine();
        System.out.println("Document for identity proof (Aadhar/Pan/Passport) :");
        id = s.nextLine();
        System.out.println("Aadhaar/Pan/Passport No:");
        ident_no = s.nextLong();
        do{
            System.out.println("Basic Balance:");
            bal = s.nextLong();
            if(bal<2000)
            {
                System.out.println("Minimum Basic Balance must be Rs.2000.");
            }
        }while(bal<2000);
        
        System.out.println("\nCongrats!!\nNew Account Created Successfully!!");
        acc_no++;
        System.out.println("\nYour New Account No is "+acc_no);
        acc_id++;
        System.out.println("Your Account ID is KHKOP"+acc_id);
        
    }
    
    public void deposite()
    {
        long dep;
        
        System.out.println("Enter the amount to be deposited:");
        dep = s.nextLong();
        
        bal = bal + dep;
        
        System.out.println("Rs."+dep+" deposited to your account successfuly!!");
        System.out.println("Total Balance: "+bal);
    }
    
    public void cashwithdraw()
    {
        long withdraw;
        
        do
        {
            System.out.println("Enter the amount you wnt to withdraw:");
            withdraw = s.nextLong();
            if(withdraw>bal)
            {
                System.out.println("Amount greater than current balance!!\nYour Balance: "+bal);
            }
            else
            {
                continue;
            }
        }while(withdraw>bal);
        
        bal = bal - withdraw;
        
        System.out.println("Amount of Rs."+withdraw+" was debited from your account.");
        System.out.println("Total Balance: "+bal);
    }
    
    public void checkbal()
    {
        System.out.println("Your current balance is: "+bal);
    }
    
    public void display()
    {
        System.out.println("Your Account details are as follows:");
        System.out.println("Account Holder: "+name);
        System.out.println("Accound ID: "+acc_id);
        System.out.println("Account Number: "+acc_no);
        System.out.println("Current Balance: "+bal);
    }
}

public class Main
{
	public static void main(String[] args) {
		
		int choice;
		
		Scanner sc = new Scanner(System.in);
		
		BankSystem bank = new BankSystem();
		System.out.println("Greetings...Welcome to KHATA BANK...");
		
		do
		{
		    System.out.println("\n------------------------");
		    System.out.println("1.Create Account\n2.Deposite Money\n3.Cash Withdrawal\n4.Check Balance\n5.Display Account details\n6.Exit");
		    System.out.println("------------------------\n");
		    
		    System.out.println("Enter the operation to be performed:");
		    choice = sc.nextInt();
		    
		    switch(choice)
		    {
		        case 1:
		            bank.createAccount();
		            break;
		            
		        case 2:
		            bank.deposite();
		            break;
		            
		        case 3:
		            bank.cashwithdraw();
		            break;
		            
		        case 4:
		            bank.checkbal();
		            break;
		            
		        case 5:
		            bank.display();
		            break;
		            
		        case 6:
		            System.out.println("\nDone!!");
		            break;
		            
		        default:
		        System.out.println("\nWrong choice!!");
		        break;
		    }
		    
		    System.out.println("\n\n");
		}while(choice!=6);
		
	}
}
