import java.awt.Color; 
@SuppressWarnings ("unused") 
  
interface car 
{ //interface car 
 public String getModel (); 
 public void setWheel (String wheel); 
 public String getWheel (); 
 public void setEngine (String engine); 
 public String getEngine (); 
} 
interface carFactory 
 { //interface carfactory 
 public abstract car buildCar(String model, String wheel, String engine);  } 
class HatchbackCar implements car 
{ //hatchvbackcar class 
 String model; 
 String wheel; 
 String engine; 
 HatchbackCar (String model, String wheel, String engine)  { 
 this.model = model; 
 this.wheel = wheel; 
 this.engine = engine; 
 } 
  
 public String getModel () 
 { 
 return model; 
 } 
  
 public void setWheel (String wheel) 
 { 
 this.wheel = wheel; 
 } 
  
 public String getWheel () 
 { 
 return wheel; 
 } 
  
 public void setEngine (String engine) 
 { 
 this.engine = engine; 
 } 
  
 public String getEngine () 
 { 
 return engine; 
 } 
} 
class HatchbackCarFactory implements carFactory 
{ 
 @Override public car buildCar (String model, String wheel, String engine) 
 { 
 car car = new HatchbackCar (model, wheel, engine); 
  
 /*Can declare and call internal method to assemble parts here 
 System.out.println("%s car is assembled with wheels from %s and engine from % s "+ car.model+  car.wheel+ car.engine);*/ 
  
 return car; 
 } 
} 
class SedanCar implements car  
{ //sedan car class 
 String model; 
 String wheel; 
 String engine; 
  
 SedanCar(String model, String wheel, String engine) 
 { 
 this.model = model; 
 this.wheel = wheel; 
 this.engine = engine; 
 } 
  
 public String getModel() 
 { 
 return model; 
 } 
  
 public void setWheel(String wheel) 
 { 
 this.wheel = wheel;
 } 
  
 public String getWheel() 
 { 
 return wheel; 
 } 
 public void setEngine(String engine) 
 { 
 this.engine = engine; 
 } 
  
 public String getEngine() 
 { 
 return engine; 
 } 
} 
class SUVCarFactory implements carFactory 
{ 
 @Override 
 public car buildCar(String model, String wheel, String engine)   { 
 car car = new SedanCar(model, wheel, engine); 
 return car; 
 } 
} 
public class Main 
{ 
 carFactory carBuilder; 
 car car; 
 public static void main(String[] args)  
 { 
 Main client = new Main(); 
 client.buildCarMethod(); 
 } 
  
 public void buildCarMethod()  
 { 
 System.out.println(" building Hatchback car "); 
 carBuilder = new HatchbackCarFactory(); 
 car = carBuilder.buildCar(" Polo ", " Michelin ", " VW ");   
 //carBuilder.paintCar(Color.BLUE); 
 System.out.println(" Car is assembled and painted now.Model of car is:"+  car.getModel()); 
 System.out.println(" building SEDAN car ");
 carBuilder = new SUVCarFactory(); 
 car = carBuilder.buildCar(" Dzire ", " MRF ", " Suzuki "); 
  
 //carBuilder.paintCar(Color.YELLOW); 
 System.out.println(" Car is assembled and painted now.Color of car is:"+  car.getModel()); 
 System.out.println(" building SUV car "); 
 carBuilder = new SUVCarFactory(); 
 car = carBuilder.buildCar(" Innova ", " Bridgestone ", 
 " Fiat "); 
 //carBuilder.paintCar(Color.RED); 
  
 System.out.println(" Car is assembled and painted now.Engine of car is:"+  car.getModel()); 
 /*Tomorrow if we want to build new type say MUV then we just hv to create  new subclass of Car class and new subclass of CarFactory. No need  to update exixtsing class. 
 This is beauty of factory method. Consumer always uses factory  interface instead of implementation*/ 
 } 
} 
