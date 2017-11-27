package drawable;

import java.awt.Color;
import java.awt.Graphics;

public abstract class DrawableForme implements Drawable {
	
	protected Color couleur;
	
	public void setCouleur(Color couleur) {
		this.couleur = couleur;
	}
	
	public DrawableForme (Color couleur) {
		setCouleur(couleur);
	}

}
