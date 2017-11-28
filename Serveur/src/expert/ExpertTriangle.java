package expert;

import drawable.DrawableTriangle;
import main.JCanvas;

public class ExpertTriangle extends Expert {

	private JCanvas cadre;

	public ExpertTriangle(Expert e, JCanvas jc) {
		super(e);
		cadre = jc;
	}

	@Override
	public void decide(String requete) throws Exception {
		String arguments[] = requete.split(",");
		if (arguments[0].equals("triangle"))
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
		int y2 = Integer.parseInt(arguments[4].trim());
		int x3 = Integer.parseInt(arguments[5].trim());
		int y3 = Integer.parseInt(arguments[6].trim());

		// On dessine
		DrawableTriangle triangle = new DrawableTriangle(x1, y1, x2, y2, x3, y3, couleur);
		cadre.addDrawable(triangle);
	}

}
