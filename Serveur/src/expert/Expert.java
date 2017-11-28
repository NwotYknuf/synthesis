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
	
}
