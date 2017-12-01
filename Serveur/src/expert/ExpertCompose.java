package expert;

import java.util.ArrayList;

public class ExpertCompose extends Expert {

	public ExpertCompose(Expert e) {
		super(e);
	}
	
	private ArrayList<String> getComposants(String str, char splitDebut, char splitFin){

		ArrayList<String> res = new ArrayList<String>();
		int pos = 0, debut, fin;
		int hauteur = 0;

		while (pos < str.length()) {

			while (str.charAt(pos) != splitDebut && pos < str.length()) {
				pos++;//On cherche le caractère de début
			}
			debut = pos;
			hauteur++;
			pos++;
			
			while (hauteur > 0 && pos < str.length()) {
				
				if (str.charAt(pos) == splitFin) {
					hauteur--;
				}
				else {
					if (str.charAt(pos) == splitDebut) {
						hauteur++;
					}
				}
				pos++;
			}
			//pos >= longueur de la chaine OU on a trouvé la fin du composant
			if (pos <= str.length()) {
				fin = pos;
				res.add(str.substring(debut+1, fin-1));
			}		
		}
		
		return res;
	}

	@Override
	public void decide(String requete) throws Exception {
		String arguments[] = requete.split(",");
		if (arguments[0].equals("compose"))
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
		String args[] = requete.split(",");
		
		String suiteReq = requete.substring(args[0].length() + 1 + args[1].length() + 1, requete.length());

		ArrayList<String> composants = getComposants(suiteReq, '[', ']');
		
		for(String req : composants){
			this.decide(req);
		}
	}

}
