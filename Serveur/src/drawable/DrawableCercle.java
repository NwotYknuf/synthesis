package drawable;

import java.awt.Color;
import java.awt.Graphics;

public class DrawableCercle extends DrawableForme{
	
	private int x;
	private int y;
	private int rayon;
	
	public void setX(int x){
		this.x = x;
	}
	public void setY(int y){
		this.y = y;
	}
	public void setRayon(int rayon){
		this.rayon = rayon;
	}

	public DrawableCercle(int x, int y, int rayon, String couleur) throws Exception{
		super(couleur);
		setX(x);
		setY(y);
		setRayon(rayon);
	}

	public void draw(Graphics c) {
		Color couleur = c.getColor();
		c.setColor(this.couleur);
		c.fillOval(x - rayon/2, y - rayon/2, rayon, rayon);
		c.setColor(couleur);
	}
}
