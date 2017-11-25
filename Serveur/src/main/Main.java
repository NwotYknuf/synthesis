package main;

import java.awt.*;

public class Main {
	public static void main (String[] args){
		JCanvas jc = new JCanvas();
		jc.setBackground(Color.BLACK);
		jc.setPreferredSize(new Dimension(1024, 860));
		GUIHelper.showOnFrame(jc,"test JCanvas with IDrawables");
		
	}
}
