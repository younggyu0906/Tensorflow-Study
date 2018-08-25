import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.awt.image.BufferedImage;

class MyPanel extends JPanel {
	private BufferedImage img = null;
	private int x = 200, y = 200;
	
	public MyPanel() {
		try {
			img = ImageIO.read(new File("car.jpg"));
		} catch (IOException e) {
			System.out.println("No Image");
			System.exit(1);
		}
	}
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D)g;
		g2.drawImage(img, x, y, null);
	}
}

public class Pro01_CarGameTest extends JFrame {
	public Pro01_CarGameTest() {
		setTitle("Car Game");
		setSize(600, 600);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		add(new MyPanel());
		setVisible(true);
	}
	public static void main(String[] args) {
		Pro01_CarGameTest test = new Pro01_CarGameTest();
	}
}
