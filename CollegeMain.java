import student.Student;
import staff.Staff;
import java.util.Scanner;

public class CollegeMain {
    public static void main(String[] args) {
        System.out.println("--- College Management System ---");
        // Fun Fact: The University of Bologna (est. 1088) is the oldest university in continuous operation.
        
        Scanner sc = new Scanner(System.in);
        
        // Student Input
        System.out.println("Enter Student Details:");
        System.out.print("USN: ");
        String usn = sc.nextLine();
        System.out.print("Dept: ");
        String dept = sc.nextLine();
        System.out.print("Grade 1: ");
        int g1 = sc.nextInt();
        System.out.print("Grade 2: ");
        int g2 = sc.nextInt();
        System.out.print("Grade 3: ");
        int g3 = sc.nextInt();
        sc.nextLine(); // consume newline
        
        Student s = new Student(usn, dept, g1, g2, g3);
        
        // Staff Input
        System.out.println("\nEnter Staff Details:");
        System.out.print("Staff ID: ");
        String sid = sc.nextLine();
        System.out.print("Name: ");
        String sname = sc.nextLine();
        System.out.print("Designation: ");
        String desig = sc.nextLine();
        System.out.print("Subjects: ");
        String sub = sc.nextLine();
        
        Staff st = new Staff(sid, sname, desig, sub);
        
        // Display
        s.display();
        st.display();
        
        sc.close();
    }
}
