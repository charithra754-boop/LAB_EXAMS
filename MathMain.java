import AdvMath.TrigAlgo;
import AdvMath.AngleConverter;
import java.util.Scanner;

public class MathMain {
    public static void main(String[] args) {
        System.out.println("--- 🧮 Advanced Math Calculator 🧮 ---");
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter angle x in degrees: ");
        double degrees = sc.nextDouble();
        
        // Using Class 1: Converter
        AngleConverter converter = new AngleConverter();
        double radians = converter.toRadians(degrees);
        
        // Using Class 2: Algo
        TrigAlgo algo = new TrigAlgo();
        double result = algo.calculateComplexTrig(radians);
        
        System.out.println("Calculating y = sin(x) + cos(x) + tan(x)...");
        System.out.printf("Result for %.2f degrees: %.4f\n", degrees, result);
        
        sc.close();
    }
}
