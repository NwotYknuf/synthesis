package drawable;

import java.awt.Color;
import java.awt.Graphics;

public class DrawableSegment extends DrawableForme{
	
	private int x;
	private int x2;
	private int y;
	private int y2;
	
	public void setX(int x){
		this.x = x;
	}
	public void setY(int y){
		this.y = y;
	}
	public void setX2(int x2){
		this.x2 = x2;
	}
	public void setY2(int y2){
		this.y2 = y2;
	}

	public DrawableSegment(int x, int y, int x2, int y2, Color couleur) {
		super(couleur);
		setX(x);
		setY(y);
		setX2(x2);
		setY2(y2);
	}

	public void draw(Graphics c) {
		Color couleur = c.getColor();
		c.setColor(this.couleur);
		c.drawLine(this.x, this.y, this.x2, this.y2);
		c.setColor(couleur);
	}
}
