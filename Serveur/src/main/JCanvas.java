package main;

import javax.swing.JPanel;
import drawable.Drawable;
import java.awt.Graphics;
import java.util.ArrayList;

public class JCanvas extends JPanel {

	private ArrayList<Drawable> drawables = new ArrayList<Drawable>();
	
	public void paint(Graphics g) {
		super.paint(g);
		for(Drawable d : drawables){
			d.draw(g);	
		}
	}

	public void addDrawable(Drawable d) {
		drawables.add(d);
		repaint();
	}

	public void removeDrawable(Drawable d) {
		drawables.remove(d);
		repaint();
	}

	public void clear() {
		drawables.clear();
		repaint();
	}
	
}