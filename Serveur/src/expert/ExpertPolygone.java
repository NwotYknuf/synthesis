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
		// On récupère les arguments
		String args[] = requete.split(",");
		String suiteReq = requete.substring(args[0].length() + 1 + args[1].length() + 1, requete.length());
		
		String ssReq[] = suiteReq.split(";");
		
		for(String req : ssReq){
			getSuivant().decide(req);
		}
	}
}
