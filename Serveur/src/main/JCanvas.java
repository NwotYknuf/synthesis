package main;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import javax.swing.JPanel;

import drawable.Drawable;

import java.awt.Graphics;


public class JCanvas extends JPanel {

	private List drawables = new LinkedList();
	
	public void paint(Graphics g) {
		super.paint(g);
		for (Iterator iter = drawables.iterator(); iter.hasNext();) {
			Drawable d = (Drawable) iter.next();
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