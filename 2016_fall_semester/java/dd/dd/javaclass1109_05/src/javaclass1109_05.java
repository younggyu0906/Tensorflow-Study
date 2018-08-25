import java.awt.*;
import javax.swing.*;

class MyFrame extends JFrame{
	private JButton b1,b2,b3;
	
	public MyFrame(){
		setTitle("Absolute Test");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new BorderLayout(5,5));
		setSize(300,200);
		
		JPanel p = new JPanel();
		p.setLayout(null);
		b1 = new JButton("Button #1");
		b2 = new JButton("Button #2");
		b3 = new JButton("Button #3");
		p.add(b1);
		p.add(b2);
		p.add(b3);
		b1.setBounds(20,5,85,30);
		b2.setBounds(55,45,105,70);
		b3.setBounds(180,15,105,90);
		add(p);
		setVisible(true);
	}
}
public class javaclass1109_05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame f = new MyFrame();

	}

}
