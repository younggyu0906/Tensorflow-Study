import java.awt.*;
import javax.swing.*;
import java.awt.geom.*;

class MyPanel extends JPanel{
	public void paintComponent(Graphics g){
		Shape s; //Shape interface ���������� ��� ���� ���� ����
				 //geom ��Ű���� ��� ���������� Shape inerFace�� �����ϱ� ����
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D)g;
		
		g2.setColor(Color.black);
		g2.setStroke(new BasicStroke(3));
		s = new Rectangle2D.Double(10,10,80,80);
		g2.draw(s);
		s = new RoundRectangle2D.Double(110,10,70,80,20,20);
		g2.draw(s);
		g2.drawRect(200, 10, 80, 80);
		
		g2.setFont(new Font("Courier",Font.BOLD,30));
		g2.drawString("Text antialiasing",50,150);
//Graphics�� ������ ��ü �������� ���
//Graphics2D�� ������ ��ü ���� �� draw() �޼ҵ� �̿��Ͽ� ���
	}			
	
}
public class javaclass_1114_03 extends JFrame {
	public javaclass_1114_03(){
		setSize(600,200);
		setTitle("Java 2D Shape");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JPanel panel = new MyPanel();
		add(panel);
		setVisible(true);
	}
	public static void main(String args[]){
		 javaclass_1114_03 f= new  javaclass_1114_03();
	}

}
