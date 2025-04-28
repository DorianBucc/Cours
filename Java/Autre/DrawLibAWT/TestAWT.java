package DrawLibAWT;

import java.awt.Color;
import java.awt.Graphics; 
import javax.swing.JFrame;

public class TestAWT extends JFrame {
 
    public TestAWT() {
        super("Programme 1");
 
        setSize(500, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //setLocationRelativeTo(null);
    }
     
    public void paint(Graphics g) {
        super.paint(g);
        g.drawLine(120, 50, 360, 50);
        g.setColor(Color.RED);
        g.drawLine(120, 100, 360, 100);
        g.drawLine(120, 150, 360, 150);
        g.drawString("Test", 240, 100);
        
    }

    public static void main(String[] args) {
        new TestAWT().setVisible(true);
    }
}