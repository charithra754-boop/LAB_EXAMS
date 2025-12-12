import MyPack.BankCustomer;
import java.util.Scanner;

public class BankMain {
    public static void main(String[] args) {
        System.out.println("--- Welcome to the Java Bank ---");
        // Fun Fact: The oldest bank in existence is Banca Monte dei Paschi di Siena in Italy, operating since 1472!
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Customer Name: ");
        String name = sc.nextLine();
        
        System.out.print("Enter Balance: ");
        double balance = sc.nextDouble();
        
        // Creating object of the class in the package
        BankCustomer customer = new BankCustomer(name, balance);
        customer.display();
        
        sc.close();
    }
}
