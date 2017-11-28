package drawable;

import java.awt.Color;

public abstract class DrawableForme implements Drawable {
	
	protected Color couleur;
	
	public void setCouleur(String couleur)throws Exception {
		this.couleur = couleurAWT(couleur);
	}
	
	public DrawableForme (String couleur) throws Exception {
		setCouleur(couleur);
	}
	
	private Color couleurAWT(String couleur) throws Exception {
		switch (couleur) {
		case "noir" :
			return Color.BLACK;
		case "blanc" :
			return Color.WHITE;
		case "vert" :
			return Color.GREEN;
		case "rouge" :
			return Color.RED;
		case "bleu" :
			return Color.BLUE;
		case "jaune" :
			return Color.YELLOW;
		case "cyan" :
			return Color.CYAN;
		 default :
			throw new Exception("Couleur non conforme");
		}
	}	
}
