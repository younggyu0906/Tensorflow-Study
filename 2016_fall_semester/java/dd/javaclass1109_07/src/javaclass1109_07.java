import java.awt.*;
import javax.swing.*;
	
class MyPanel extends JPanel{
	
		public void paintComponent(Graphics g){
			super.paintComponents(g);
			g.setColor(Color.green);
			g.drawString("Hello, java programming", 10, 10);
			g.drawLine(10, 30, 110, 130);
			g.drawRect(10, 30, 100, 100);
		}
}
public class javaclass1109_07 extends JFrame {
	public javaclass1109_07(){
		setTitle("My Frame");
		setSize(300,700);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		MyPanel p = new MyPanel();
		add(p);
		setVisible(true);
	}
	public static void main(String args[]){
		javaclass1109_07 f = new javaclass1109_07();
	}

}
