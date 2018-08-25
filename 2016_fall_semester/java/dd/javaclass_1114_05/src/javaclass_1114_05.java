import java.awt.*;
import javax.swing.*;
import java.awt.geom.*;//도형들의 클래스

class MyPanel extends JPanel{
	public void paintComponent(Graphics g){
		Shape s;
		
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D)g;
		
		GradientPaint gp = new GradientPaint(100,100,Color.red,0,0,Color.blue);
		//화면 좌표
		g2.setPaint(gp);
		
		s = new Rectangle2D.Double(10,10,80,80);
		g2.fill(s);
		
		s = new RoundRectangle2D.Double(110,10,80,80,20,20);
		g2.fill(s);
	}
}
public class javaclass_1114_05 extends JFrame {
	public javaclass_1114_05(){
		setSize(600,200);
		setTitle("Gradient Fill");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		add(new MyPanel());
		setVisible(true);
	}
	public static void main(String args[]){
		javaclass_1114_05 f = new javaclass_1114_05();
	}
}
