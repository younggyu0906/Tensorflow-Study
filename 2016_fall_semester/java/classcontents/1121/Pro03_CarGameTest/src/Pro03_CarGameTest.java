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
		this.addKeyListener(new MyKeyListener());
		addMouseListener(new MyMouseListener());
		addMouseMotionListener(new MyMouseMotionListener());
		requestFocus();		// JPanel은 default로 key vent를 받을 수 없기 때문에
		setFocusable(true);	// Key event를 받도록 한다
	}
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D)g;
		g2.drawImage(img, x, y, null);
	}
	private class MyMouseListener extends MouseAdapter {
		public void mouseClicked(MouseEvent e) {
			x = e.getX();
			y = e.getY();
			repaint();
		}
	}
	private class MyMouseMotionListener extends MouseMotionAdapter {
		public void mouseDragged(MouseEvent e) {
			x = e.getX();
			y = e.getY();
			repaint();
		}
	}
	private class MyKeyListener implements KeyListener {
		public void keyPressed(KeyEvent e) {
			int keycode = e.getKeyCode();
			switch (keycode) {
//		==		case 'U' 				:
				case KeyEvent.VK_U		:
				case KeyEvent.VK_UP		: y -= 10; break;
//		==		case 'D' 				:				
				case KeyEvent.VK_D		:
				case KeyEvent.VK_DOWN	: y += 10; break;
//		==		case 'L' 				:				
				case KeyEvent.VK_L		:
				case KeyEvent.VK_LEFT	: x -= 10; break;
//		==		case 'R' 				:			
				case KeyEvent.VK_R		:
				case KeyEvent.VK_RIGHT	: x += 10; break;
			}
			repaint();
		}
		public void keyReleased(KeyEvent e) {
		}
		public void keyTyped(KeyEvent e) {
		}
	}
}

public class Pro03_CarGameTest extends JFrame {
	public Pro03_CarGameTest() {
		setTitle("Car Game");
		setSize(600, 600);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		add(new MyPanel());
		setVisible(true);
	}
	public static void main(String[] args) {
		Pro03_CarGameTest test = new Pro03_CarGameTest();
	}
}