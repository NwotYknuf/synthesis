package main;
import java.net.Socket;
import java.awt.Color;
import java.awt.Dimension;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.SocketException;
import expert.*;

public class SessionDessin extends Thread{
	Socket socket;
	BufferedReader fluxEntrant;

	public SessionDessin(Socket socket) throws IOException {
		this.socket = socket;
		this.fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
	}

	@Override
	public void run() {
		String requete;

		try {
			requete = this.fluxEntrant.readLine();
			System.out.println("requête reçue : " + requete);
			String arguments[] = requete.split(",");
			
			String titre;
			int Ox, Oy, largeur, hauteur;

			titre = arguments[0].trim();
			Ox = Integer.parseInt(arguments[1].trim());
			Oy = Integer.parseInt(arguments[2].trim());
			largeur = Integer.parseInt(arguments[3].trim());
			hauteur = Integer.parseInt(arguments[4].trim());

			JCanvas jc = new JCanvas();
			jc.setBackground(Color.BLACK);
			jc.setPreferredSize(new Dimension(largeur, hauteur));
			GUIHelper.showOnFrame(jc,titre);
			
			ExpertSegment Segment = new ExpertSegment(null, jc);
			ExpertCercle Cercle = new ExpertCercle(Segment, jc);
			ExpertTriangle Triangle = new ExpertTriangle(Cercle, jc);
			ExpertPolygone Polygone = new ExpertPolygone(Triangle);
			ExpertCompose Compose = new ExpertCompose(Polygone);

			while (true) {
				requete = this.fluxEntrant.readLine();
				System.out.println("requête reçue : " + requete);
				Compose.decide(requete);
			}
		}

		catch (SocketException e) {
			System.out.println("session de dessin terminée par le client");
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (InterruptedException e) {
			e.printStackTrace();
		} catch(Exception e){
			e.printStackTrace();
		}
	}
}
