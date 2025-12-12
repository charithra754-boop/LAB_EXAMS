package staff;

public class Staff {
    String staffId;
    String name;
    String designation;
    String subjects;

    public Staff(String staffId, String name, String designation, String subjects) {
        this.staffId = staffId;
        this.name = name;
        this.designation = designation;
        this.subjects = subjects;
    }

    public void display() {
        System.out.println("\n--- 👩‍🏫 Staff Profile 👨‍🏫 ---");
        System.out.println("ID: " + staffId);
        System.out.println("Name: " + name);
        System.out.println("Designation: " + designation);
        System.out.println("Subjects Handled: " + subjects);
    }
}
