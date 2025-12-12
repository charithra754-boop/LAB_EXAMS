import java.util.Scanner;

public class ExceptionDemo {
    public static void main(String[] args) {
        System.out.println("--- 🚫 Exception Handling Demo 🚫 ---");
        // Fun Fact: The first 'bug' was a real moth trapped in a relay of the Harvard Mark II computer in 1947.
        
        Scanner sc = new Scanner(System.in);
        int[] luckyNumbers = {7, 11, 21, 42};
        
        System.out.println("Available indices: 0 to 3");
        System.out.print("Enter an index to access: ");
        
        try {
            int index = sc.nextInt();
            // This might throw ArrayIndexOutOfBoundsException
            System.out.println("Value at index " + index + ": " + luckyNumbers[index]);
            
            // Force a division by zero if they pick 0 just for fun multiple catch testing?
            // No, the question asks to "Throw an error in try block to handle array out of bound index".
            // So just accessing it is enough.
            
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("\n[Catch 1] Oops! You went out of bounds! 🏃‍♂️💨");
            System.out.println("Error Message: " + e);
        } catch (Exception e) {
            System.out.println("\n[Catch 2] Some other error occurred! 🤷‍♂️");
            System.out.println("Error Message: " + e);
        } finally {
            System.out.println("\n[Finally] This block runs no matter what! Cleaning up resources...");
            sc.close();
        }
        
        System.out.println("Program continues safely...");
    }
}
