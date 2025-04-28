package DrawLibAWT;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
 
import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class BaseAWT extends JFrame {
 
    public BaseAWT() {
        super("Lines Drawing Demo");
 
        setSize(480, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    }
 
    void drawLines(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
 
        g2d.drawLine(120, 50, 360, 50);
 
        g2d.draw(new Line2D.Double(59.2d, 99.8d, 419.1d, 99.8d));
        g2d.setColor(new Color(255,0,0,128));
        g2d.setStroke(new BasicStroke(5.0f));
        g2d.draw(new Line2D.Float(21.50f, 132.50f, 459.50f, 132.50f));
        g2d.draw(new Line2D.Float(21.50f, 132.50f, 459.50f, 132.50f));
        g2d.drawRect(50, 50, 50, 50);
 
    }
 
    public void paint(Graphics g) {
        super.paint(g);
        drawLines(g);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new BaseAWT().setVisible(true);
            }
        });
    }
}