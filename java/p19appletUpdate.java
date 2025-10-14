import javax.swing.*;
import java.awt.*;

public class p19appletUpdate extends JPanel { 
    int x; 
    int y; 
    int width; 
    int height; 
    Color col; 
    
    // Constructor replaces init() method
    public p19appletUpdate(int x, int y, int width, int height, String colorHex) { 
        this.x = x; 
        this.y = y; 
        this.width = width; 
        this.height = height; 
        this.col = new Color(Integer.parseInt(colorHex, 16)); 
        setBackground(Color.WHITE);
    } 
    
    @Override
    public void paintComponent(Graphics g) { 
        super.paintComponent(g);
        g.setColor(col); 
        g.drawRect(x, y, width, height);
    }
    
    // Main method to run as standalone application
    public static void main(String[] args) {
        // Create frame
        JFrame frame = new JFrame("Rectangle with Specified Coordinates");
        
        // Create panel with parameters (matching your HTML parameters)
        p19appletUpdate panel = new p19appletUpdate (
            10,      // x
            20,      // y
            500,     // width
            300,     // height
            "FF0000" // color (red)
        );
        
        // Add panel to frame
        frame.add(panel);
        frame.setSize(600, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null); // Center on screen
        frame.setVisible(true);
    }
}
