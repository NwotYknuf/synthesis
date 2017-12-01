package expert;

public class ExpertPolygone extends Expert {

	public ExpertPolygone(Expert e) {
		super(e);
	}

	@Override
	public void decide(String requete) throws Exception {
		String arguments[] = requete.split(",");
		if (arguments[0].equals("polygone"))
			gere(requete);
		else {
			if (getSuivant() != null)
				getSuivant().decide(requete);
			return;
		}
	}

	@Override
	public void gere(String requete) throws Exception {
		// On r�cup�re les arguments
		String suiteReq = requete.substring(9, requete.length());
		
		String ssReq[] = suiteReq.split(";");
		
		for(String req : ssReq){
			getSuivant().decide(req);
		}
	}
}
