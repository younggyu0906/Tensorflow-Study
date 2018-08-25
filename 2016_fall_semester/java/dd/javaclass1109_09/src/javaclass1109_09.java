import java.awt.*;
import javax.swing.*;

class MyPanel extends JPanel{
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		g.setColor(Color.green);
		g.fillOval(20, 40, 200, 200);
		g.setColor(Color.black);
		g.drawArc(60, 80, 50, 50, 0 , 180);
		g.drawArc(150, 80, 50, 50, 0 , 180);
		g.drawArc(70, 130, 100, 70, 0 , -180);
	}
}
public class javaclass1109_09 extends JFrame {
	public javaclass1109_09(){
		super("dkjf");
		setSize(280,300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Snow Man Face");
		add(new MyPanel());
		setVisible(true);
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		javaclass1109_09 f = new javaclass1109_09();
	}

}
