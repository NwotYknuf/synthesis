package expert;

import java.awt.Color;

public abstract class Expert {

	private Expert suivant = null;
	
	public Expert(Expert e) {
		suivant = e;
	}
	
	void setSuivant(Expert e) {
		suivant = e;
	}
	
	Expert getSuivant() {
		return suivant;
	}
		
	public abstract void decide(String requete)throws Exception;
	
	public abstract void gere(String requete) throws Exception;
	
	public Color couleurAWT(String couleur) throws Exception {
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
