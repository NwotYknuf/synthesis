package expert;
import java.awt.Color;
import java.awt.color.*;

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
	    
	}

}
