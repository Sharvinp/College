public class Generics { 
static boolean isPrime(int num) { 
int flag=0; 
for(int i=2,i<num;i++) 
if (num%i==0) 
{ 
flag=1; 
break; 
} 
if (flag==0) 
return true; 
return false; 
} 
static<T> void count (String type,T[] element) { 
// TODO Auto-generated method stub 
int even =0,odd=0,prime=0,palindrome=0; 
if(type.equals("even")) { 
for (T value:element) 
if (Integer.parseInt(value.toString())%2==0) 
even++; 
System.out.println("Even numbers are: "+even); 
} 
if(type.equals("odd")) { 
for (T value:element) 
if (Integer.parseInt(value.toString())%2!=0) 
odd++; 
System.out.println("Odd numbers are: "+odd); 
} 
if(type.equals("prime")) { 
for (T value:element) 
if (isPrime(Integer.parseInt(value.toString()))) 
prime++; 
System.out.println("Prime numbers are: "+prime); 
} 
if(type.equals("palindrome")){ 
 for(T value : element) 
 { 
 StringBuffer rev = new StringBuffer(value.toStrin());  if(value.toString().equals(new String(rev.reverse())))  palindrome++;
 } 
 System.out.println("Plaindrome numbers are "+palindrome);  } 
 } 
} 
public static void main(String[] args) { 
Integer arr[]= {44, 23, 87, 95, 68, 83, 54}; 
count("even",arr); 
count("odd",arr); 
count("prime",arr); 
count("palindrome",arr) 
} 
} 
