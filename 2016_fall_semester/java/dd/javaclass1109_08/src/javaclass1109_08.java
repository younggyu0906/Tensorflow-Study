import java.awt.*;
import javax.swing.*;
class MyPanel extends JPanel{
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		g.setColor(Color.GREEN);
		g.drawRect(50, 50, 50, 50);
		g.fillRect(150, 50, 50, 50);
		
		g.draw3DRect(250, 50, 50, 50, true);
		g.fill3DRect(350, 50, 50, 50, true);
		
		g.drawRoundRect(450, 50, 50, 50, 20, 20);
		g.drawRoundRect(550, 50, 50, 50, 10, 10);
	}
}
public class javaclass1109_08 extends JFrame {
	public javaclass1109_08(){
		super("Basic Hape Drawing");
		setSize(700,300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
		MyPanel p = new MyPanel();
		add(p);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		javaclass1109_08 j = new javaclass1109_08();

	}

}
