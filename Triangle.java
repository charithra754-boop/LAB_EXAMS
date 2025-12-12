public class Triangle implements Shape {
    double base;
    double height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    public double calculateArea() {
        // Area of Triangle = 0.5 * base * height
        return 0.5 * base * height;
    }
}
