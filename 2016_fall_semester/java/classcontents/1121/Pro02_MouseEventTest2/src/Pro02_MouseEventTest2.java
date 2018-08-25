// MouseAdapter 클래스나 MyMotionMouseListener

import java.awt.event.*;
import javax.swing.*;

class MyFrame extends JFrame{
	JPanel panel;
	
	public MyFrame() {
		setTitle("Mouse Event Test");
		setSize(300, 200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		panel = new JPanel();
		panel.addMouseListener(new MyMouseListener());
		panel.addMouseMotionListener(new MyMouseMotionListener());
		add(panel);
		setVisible(true);
	}
	private class MyMouseListener extends MouseAdapter {
		public void mouseClicked(MouseEvent e) {
			display("Mouse Clicked (# of clicks : " + e.getClickCount() + ")", e);
		}
	}
	private class MyMouseMotionListener extends MouseMotionAdapter {
		public void mouseDragged(MouseEvent e) {
			display("Mouse dragged", e);
		}
	}
	public void display(String s, MouseEvent e) {
		System.out.println(s + " x = " + e.getX() + " y = " + e.getY());
		System.out.println(e.getButton());
	}
}


public class Pro02_MouseEventTest2 {
	public static void main(String[] args) {
		MyFrame f = new MyFrame();
	}
}