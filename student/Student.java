package student;

public class Student {
    String usn;
    String deptName;
    int[] grades = new int[3];
    double sgpa;

    public Student(String usn, String deptName, int g1, int g2, int g3) {
        this.usn = usn;
        this.deptName = deptName;
        this.grades[0] = g1;
        this.grades[1] = g2;
        this.grades[2] = g3;
        calculateSGPA();
    }

    private void calculateSGPA() {
        // Simplified SGPA calc: Average / 10
        double total = grades[0] + grades[1] + grades[2];
        this.sgpa = (total / 3) / 10; 
    }

    public void display() {
        System.out.println("\n--- 🎓 Student Profile 🎓 ---");
        System.out.println("USN: " + usn);
        System.out.println("Department: " + deptName);
        System.out.println("Grades: " + grades[0] + ", " + grades[1] + ", " + grades[2]);
        System.out.printf("SGPA: %.2f\n", sgpa);
    }
}
