import java.applet.*; 
import java.awt.*; 

public class p19rectWithSpecifiedCoordinate extends Applet { 
    int x; 
    int y; 
    int  width; 
    int height; 
    Color col; 
    public void init() { 
        x=Integer.parseInt(getParameter("x")); 
        y=Integer.parseInt(getParameter("y")); 
        width=Integer.parseInt(getParameter("width")); 
        height=Integer.parseInt(getParameter("height")); 
        col=new Color(Integer.parseInt(this.getParameter("c"),16)); 
    } 
    public void paint(Graphics g) { 
        g.setColor(col); 
        g.drawRect(x,y,width,height);
    } 
}