public class CarProgram{
       public static class Car{
       int speed;
	double regularPrice;
	String color;
	public Car(int speed, double regularPrice, String color){
	this.speed = speed;	
	this.regularPrice = regularPrice;
	this.color = color;
	}
	double class getSalePrice(){
		return regularPrice;
       }
	class Truck extends Car{
	 int weight;
	 public Truck(int dpeed, double regularPrice, String color, int weight)
	 {
		 super(speed, regularPrice, color);
		 this.weight = weight;
	 }
 	double class getSalePrice(){
		double discountRate = (weight>2000)?0.10:0.20;
		return regularPrice*(1.0 -discountRate);
	}	

