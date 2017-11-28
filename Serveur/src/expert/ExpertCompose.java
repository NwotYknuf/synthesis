package expert;

public class ExpertCompose extends Expert {

	public ExpertCompose(Expert e) {
		super(e);
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
		String suiteReq = requete.substring(8, requete.length()-1);

		String ssReq[] = suiteReq.split(";");
		
		for(String req : ssReq){
			this.decide(req);
		}
	}

}
