package drawable;

import java.awt.Color;
import java.awt.Graphics;

public class DrawableTriangle extends DrawableForme{
	
	private int x;
	private int y;
	private int x2;
	private int y2;
	private int x3;
	private int y3;
	
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
	public void setX3(int x3){
		this.x3 = x3;
	}
	public void setY3(int y3){
		this.y3 = y3;
	}

	public DrawableTriangle(int x, int y, int x2, int y2, int x3, int y3, String couleur) throws Exception {
		super(couleur);
		setX(x);
		setY(y);
		setX2(x2);
		setY2(y2);
		setX3(x3);
		setY3(y3);
	}

	public void draw(Graphics c) {
		Color couleur = c.getColor();
		c.setColor(this.couleur);
		int xT[] = {x, x2, x3 };
		int yT[] = {y, y2, y3 };
		c.fillPolygon(xT,  yT,  3);
		c.setColor(couleur);
	}
}
