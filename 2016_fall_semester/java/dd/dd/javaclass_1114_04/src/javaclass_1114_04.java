import java.awt.*;

import javax.swing.*;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

class MyPanel extends JPanel{
	private BufferedImage img;
	
	public MyPanel(){
		try{
			img = ImageIO.read(new File("Penguins.jpg"));
		} catch(IOException e){
			System.out.println("No Image");
			System.exit(0);
		}
	}
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D)g;
		g2.drawImage(img,50,50,this);
	}
}
public class javaclass_1114_04 extends JFrame {
	public javaclass_1114_04(){
		setSize(500,500);
		setTitle("Image Load");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JPanel panel = new MyPanel();
		add(panel);
		setVisible(true);
	}
	public static void main(String args[]){
		javaclass_1114_04 f= new javaclass_1114_04();
		
	}
}
