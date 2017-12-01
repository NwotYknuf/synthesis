package expert;

import drawable.DrawableSegment;
import main.JCanvas;

public class ExpertSegment extends Expert {

	private JCanvas cadre;

	public ExpertSegment(Expert e, JCanvas jc) {
		super(e);
		cadre = jc;

	}

	@Override
	public void decide(String requete) throws Exception {

		String arguments[] = requete.split(",");

		if (arguments[0].equals("segment"))
			gere(requete);
		else {
			if (getSuivant() != null)
				getSuivant().decide(requete);
			return;
		}
	}

	@Override
	public void gere(String requete) throws Exception {

		// On récupère les arguments
		String arguments[] = requete.split(",");

		String couleur = arguments[1].trim();
		int x1 = Integer.parseInt(arguments[2].trim());
		int y1 = Integer.parseInt(arguments[3].trim());
		int x2 = Integer.parseInt(arguments[4].trim());
		int y2 = Integer.parseInt(arguments[5].trim());

		// On dessine
		DrawableSegment segment = new DrawableSegment(x1, y1, x2, y2, couleur);
		cadre.addDrawable(segment);
	}

}
