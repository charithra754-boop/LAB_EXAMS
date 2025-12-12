import java.util.Scanner;

public class AreaMain {
    public static void main(String[] args) {
        System.out.println("--- 📐 Geometry Area Calculator 📐 ---");
        // Fun Fact: Triangles are the strongest shape! That's why bridges are made of them.
        
        Scanner sc = new Scanner(System.in);
        
        // Rectangle
        System.out.println("\nRectangle:");
        System.out.print("Enter Length: ");
        double len = sc.nextDouble();
        System.out.print("Enter Width: ");
        double wid = sc.nextDouble();
        
        Rectangle rect = new Rectangle(len, wid);
        System.out.println("Area of Rectangle: " + rect.calculateArea());
        
        // Triangle
        System.out.println("\nTriangle:");
        System.out.print("Enter Base: ");
        double base = sc.nextDouble();
        System.out.print("Enter Height: ");
        double height = sc.nextDouble();
        
        Triangle tri = new Triangle(base, height);
        System.out.println("Area of Triangle: " + tri.calculateArea());
        
        sc.close();
    }
}
