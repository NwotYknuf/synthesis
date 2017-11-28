package main;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Main {
	public static void main(String[] args) {

		int portServeurDessin = 8091;

		try {
			ServerSocket serveurDessin = new ServerSocket(portServeurDessin);

			System.out.println("serveur de dessin pr�t, \n d�tails : " + "adresse : "
					+ serveurDessin.getLocalSocketAddress() + " port : " + serveurDessin.getLocalPort());

			int nombreClients;

			nombreClients = 0;
			boolean stop = false;

			while (!stop) {
				System.out.println("serveur de dessin en attente du prochain client");
				Socket socket = serveurDessin.accept();
				++nombreClients;
				System.out.println("nouveau client connect� n� = " + nombreClients);
				SessionDessin sessionDessin = new SessionDessin(socket);
				sessionDessin.start();
			}
			
			serveurDessin.close();

		} catch (IOException e) {
			System.err.println("Le serveur n'a pu �tre connect� sur le port d'�coute ou "
					+"la connexion sur ce port a �t� rompue. \n D�tails : " + e);
		}
	}
}
