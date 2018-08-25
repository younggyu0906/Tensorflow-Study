import java.awt.*;
import javax.swing.*;
import java.awt.geom.*;

class MyPanel extends JPanel{
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D)g;
		QuadCurve2D q = new QuadCurve2D.Double();
		q.setCurve(100,100,50,500,400,400);
		g2.draw(q);
		g2.fill(new Ellipse2D.Double(95,95,10,10));
		g2.fill(new Ellipse2D.Double(395,395,10,10));
		g2.fill(new Ellipse2D.Double(45,495,10,10));
		
	}
}
public class javaclass_1114_06 extends JFrame{
	public javaclass_1114_06(){
		setSize(1000,1000);
		setTitle("Curve Test");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		add(new MyPanel());
		setVisible(true);
	}
	public static void main(String args[]){
		javaclass_1114_06 f = new javaclass_1114_06();
	}

}
