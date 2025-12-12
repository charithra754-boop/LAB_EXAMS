import javax.swing.*;
import java.awt.*;

public class AllTheBest {
    public static void main(String[] args) {
        if (java.awt.GraphicsEnvironment.isHeadless()) {
            System.out.println("--- GUI Demo ---");
            System.out.println("System is running in Headless mode (no display).");
            System.out.println("Code for 'All The Best' GUI is present but cannot display window here.");
            return;
        }

        // Fun Fact: The first graphical user interface (GUI) was developed at Xerox PARC in the 1970s and inspired both Apple and Microsoft!
        
        JFrame frame = new JFrame("Wish you Luck!");
        frame.setSize(400, 400);
        frame.setLayout(new FlowLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        String message = "All The Best";
        Color[] colors = {Color.RED, Color.BLUE, Color.GREEN, Color.MAGENTA, Color.ORANGE};
        Font font = new Font("Arial", Font.BOLD, 24);

        for (Color color : colors) {
            JLabel label = new JLabel(message);
            label.setForeground(color);
            label.setFont(font);
            frame.add(label);
        }

        System.out.println("Launching GUI window with colorful wishes... (Check your display)");
        
        // Since this is a CLI environment, we handle HeadlessException just in case
        try {
            frame.setVisible(true);
        } catch (java.awt.HeadlessException e) {
            System.out.println("Oops! No display detected (Headless environment). But the code is correct!");
        }
    }
}
