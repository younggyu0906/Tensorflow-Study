import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

class MyPanel extends JPanel{
	JButton button;
	Color color = new Color(0,0,0);
	MyListener listener = new MyListener();
	
	public MyPanel(){
		setLayout(new BorderLayout());
		button = new JButton("Color Change");
		button.addActionListener(listener);
		add(button,BorderLayout.SOUTH);
	}
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		g.setColor(Color.green);
		g.fillRect(10, 10, 210, 220);
		setBackground(Color.yellow);
	}
	private class MyListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			color = new Color((int)(Math.random()*255),
					(int)(Math.random()*255),
					(int)(Math.random()*255));
			repaint();
		}
	}
}
public class javaclass1109_10 extends JFrame {
	public javaclass1109_10(){
		setSize(280,300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Color Test");
		setVisible(true);
		JPanel panel = new MyPanel();
		add(panel);
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		javaclass1109_10 f = new javaclass1109_10();
	}

}