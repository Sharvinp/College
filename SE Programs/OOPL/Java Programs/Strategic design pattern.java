import java.awt.List;
import java.util.ArrayList;

@SuppressWarnings("unused")
interface PaymentStrategy 
{
    public void pay(int amount);
}

class CreditCardStrategy implements PaymentStrategy 
{
    private String Name;
    private String cardNumber;
    private String CVV;
    private String dateOfExpiry;
    public CreditCardStrategy(String name, String ccNum, String cvv, String expiryDate) 
    {
        this.Name=name;
        this.cardNumber=ccNum;
        this.CVV=cvv;
        this.dateOfExpiry=expiryDate;
    }
    @Override
    public void pay(int amount) 
    {
        System.out.println(" Amount paid with credit/debit card : "+amount);
    }
}

class Item 
{
    private String upcCode;
    private int price;
    
    public Item(String upc, int cost) 
    {
        this.upcCode=upc;
        this.price=cost;
    }
    
    public String getUpcCode() {
        return upcCode;
    }
    
    public int getPrice() 
    {
        return price;
    }
}

class PaypalStrategy implements PaymentStrategy 
{
    private String upiID;
    private String password;
    
    public PaypalStrategy(String upi, String pwd) 
    {
        this.upiID=upi;
        this.password=pwd;
    }
    //@Override
    public void pay(int amount) 
    {
        System.out.println(" Amount paid using Paypal : "+amount);
    }
}

class ShoppingCart 
{
    ArrayList<Item> items;
    
    public ShoppingCart() 
    {
        this.items=new ArrayList<Item>();
    }
    
    public void addItem(Item item) 
    {
        this.items.add(item);
    }
    
    public void removeItem(Item item) 
    {
        this.items.remove(item);
    }
    
    public int calculateTotal() 
    {
        int sum = 0;
        for(Item item : items) 
        {
            sum += item.getPrice();
        }
        
        return sum;
    }
    
    public void pay(PaymentStrategy paymentMethod) 
    {
        int amount = calculateTotal();
        paymentMethod.pay(amount);
    }
}

public class Main {
public static void main(String[] args) {
    // TODO Auto-generated method stub
    ShoppingCart cart = new ShoppingCart();
    Item item1 = new Item("5678",110);
    Item item2 = new Item("9012",125);
    cart.addItem(item1);
    cart.addItem(item2);
    cart.pay(new PaypalStrategy("sharvin@qrst", "abc"));
    cart.pay(new CreditCardStrategy("Sharvin Pharande", "62347890243768511", "300",
    "25/20"));
    }
}
