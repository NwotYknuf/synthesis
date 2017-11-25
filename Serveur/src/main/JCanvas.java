package main;
import java.awt.*;
import javax.swing.*;

public class JCanvas extends JPanel {
	
	public void paint(Graphics g) {
		super.paint(g);
		int x[] = {20,50,50,20};
		int y[] = {150,150,20,20};
		Color c = g.getColor();
		g.setColor(Color.PINK);
		g.fillOval(5,  135,  30,  30);
		g.fillOval(35,  135,  30,  30);
		g.fillOval(20,  5,  30,  30);
		g.fillPolygon( x, y, 4 );
		g.setColor(Color.BLACK);
		g.drawLine(35,  5, 35, 10);
		g.setColor(Color.PINK);
		g.drawString("CREDITS BY LUCAS",  35, 200);
		g.drawString("CREDITS BY LUCAS",  35,  201);
		g.setColor(c);
	}

}
        

