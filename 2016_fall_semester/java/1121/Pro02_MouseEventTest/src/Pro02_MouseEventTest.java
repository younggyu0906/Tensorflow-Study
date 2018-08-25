// MouseListener interface와 MouseMotion interface룰 implements 허는 경우 MouseListener에 선언된 메쏘드 5개와 MouseMotionListener에 선언된 2개의 메쏘드를 모두 구현해야 한다


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
	public class MyMouseListener implements MouseListener {
		public void mousePressed(MouseEvent e) {
			display("Mouse Pressed ", e);
		}
		public void mouseReleased(MouseEvent e) {
			display("Mouse Released ", e);
		}
		public void mouseClicked(MouseEvent e) {
			display("Mouse Clicked ", e);
		}
		public void mouseEntered(MouseEvent e) {
			display("Mouse Entered ", e);
		}
		public void mouseExited(MouseEvent e) {
			display("Mouse Exited ", e);
		}
	}
	// MouseMotion은 시스템 overhead가 많기 때문에 따로 작성
	private class MyMouseMotionListener implements MouseMotionListener {
		public void mouseDragged(MouseEvent e) {
			display("Mouse dragged", e);
		}
		public void mouseMoved(MouseEvent e) {
			display("Mouse moved", e);
		}
	}
	public void display(String s, MouseEvent e) {
		System.out.println(s + " x = " + e.getX() + " y = " + e.getY());
		System.out.println(e.getButton());
	}
}


public class Pro02_MouseEventTest {
	public static void main(String[] args) {
		MyFrame f = new MyFrame();
	}
}
