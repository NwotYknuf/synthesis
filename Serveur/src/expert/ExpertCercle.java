package expert;
import java.awt.Color;
import java.awt.color.*;

import drawable.DrawableCercle;
import main.JCanvas;


public class ExpertCercle extends Expert {

	private JCanvas cadre;
	
	public ExpertCercle(Expert e, JCanvas c) {
		super(e);
		cadre = c;
	}
	
	@Override
	public void decide(String requete) throws Exception {
		
		String arguments[] = requete.split(",");
		
		if(arguments[0].equals("cercle"))
			gere(requete);
		else {
			if(getSuivant() != null)
				getSuivant().decide(requete);
			return;
		}
	}

	@Override
	public void gere(String requete) throws Exception {
		
		//On récupère les arguments
		String arguments[] = requete.split(",");
		
		String couleur = arguments[1].trim();
	    int Ox = Integer.parseInt(arguments[2].trim());
	    int Oy = Integer.parseInt(arguments[3].trim());
	    int rayon = Integer.parseInt(arguments[4].trim());
	    
	    //On dessine
	    DrawableCercle cercle = new DrawableCercle(Ox, Oy, rayon, couleurAWT(couleur));
	    cadre.addDrawable(cercle);	    
	}
	
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
