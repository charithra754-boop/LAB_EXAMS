package MyPack;

/**
 * Fun Fact: The word "bank" comes from the Italian word "banco", 
 * which referred to the bench that money changers used in marketplaces!
 */
public class BankCustomer {
    String name;
    double balance;

    // Constructor to initialize details
    public BankCustomer(String name, double balance) {
        this.name = name;
        this.balance = balance;
    }

    // Display function
    public void display() {
        System.out.println("\n=== 🏦 Banking Details 🏦 ===");
        System.out.println("Customer Name : " + name);
        System.out.println("Account Balance: $" + balance);
        System.out.println("=============================");
        if (balance > 1000000) {
            System.out.println("Wow! High roller alert! 🤑");
        } else {
            System.out.println("Keep saving! 💰");
        }
    }
}
