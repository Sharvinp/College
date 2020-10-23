import java.util.*;

class Publication
{
    String title;
    int price,copies;
   
    Scanner s = new Scanner(System.in);
   
    public void getdata()
    {
        System.out.println("Enter title of book:");
        title = s.nextLine();
       
        System.out.println("Enter price:");
        price = s.nextInt();
       
        System.out.println("Enter no. of copies:");
        copies = s.nextInt();
    }
   
    public void saleCopy()
    {
        System.out.println("Title of book: "+title);
        System.out.println("Price: "+price);
        System.out.println("No. of copies: "+copies);
    }
}

class Book extends Publication
{
    String aut, order;
    int qty;
   
    public void getdetails()
    {
        System.out.println("Enter author:");
        aut = s.nextLine();
    }
   
    public void orderCopies()
    {
        System.out.println("Enter book to order/search:");
        order = s.nextLine();
        /*System.out.println("Enter author of required book:");
        abuy = s.nextLine();*/
    }
   
    public void orders()
    {
        System.out.println("Enter number of copies required:");
        qty = s.nextInt();
       
        if(qty<=copies)
        {
            copies = copies - qty;
            System.out.println(qty+" books bought successfully!");
            int amt = price*qty;
            System.out.println("Amout required to pay: Rs "+amt);
        }
        else
        {
            System.out.println("Sorry, quantity is more than available stock!!");
        }
    }
   
    public void putdetails()
    {
        saleCopy();
        System.out.println("Author: "+aut);
    }
   
    public void search()
    {
        if(order.equals(title))   //to compare author and title string using equals()
        {
            System.out.println("Book found!!");
            System.out.println("Book details are:");
            putdetails();
        }
        else
        {
            System.out.println("Book not found!!");
        }
    }
   
}

class Magazine extends Publication
{
    int qty;
    String issue;
   
    public void get_data()
    {
        System.out.println("Enter issue:");
        issue = s.nextLine();
    }
   
    public void orderQty()
    {
        System.out.println("Enter number of copies required:");
        qty = s.nextInt();
       
        if(qty<=copies)
        {
            copies = copies - qty;
            System.out.println(qty+" magazines bought successfully!");
            int amt = price*qty;
            System.out.println("Amout required to pay: Rs "+amt);
        }
        else
        {
            System.out.println("Sorry, quantity is more than available stock!!");
        }
    }
   
    public void currentIssue()
    {
        System.out.println("Current issue: "+issue);
    }
   
    public void recieveIssue()
    {
        System.out.print("Your issue for "+issue+" will be delivered within 10 days.\nThanks for ordering!");
    }
   
}

public class Main
{
public static void main(String[] args) {
int choice;

Book b = new Book();
Magazine mag = new Magazine();

Scanner s = new Scanner(System.in);

do
{
   System.out.println("1.Book Entry\n2.Magazine Entry\n3.Search Book\n4.Buy Book\n5.Buy Magazine\n6.Exit\n");

   System.out.println("Enter your choice:");
   choice = s.nextInt();
   
   switch(choice)
   {
       case 1:
           b.getdata();
           b.getdetails();
           break;
           
       case 2:
           mag.getdata();
           mag.get_data();
           break;
           
       case 3:
           b.orderCopies();
           b.search();
           break;
           
       case 4:
           b.orderCopies();
           b.orders();
           break;
           
       case 5:
           mag.orderQty();
           mag.currentIssue();
           mag.recieveIssue();
           break;
           
       case 6:
           System.out.println("Done!!");
           break;
           
       default:
       System.out.println("Wrong choice!!");
       break;
           
   }
}while(choice!=6);
}
}
