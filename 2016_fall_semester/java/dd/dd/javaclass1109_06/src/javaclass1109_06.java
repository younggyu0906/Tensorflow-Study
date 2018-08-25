import java.awt.*;
import javax.swing.*;
	
class MyFrame extends JFrame{
	public MyFrame(){
		setTitle("Interest Calculator");
		setSize(300,200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new GridLayout(4,1));
		JPanel p1,p2,p3,p4;
		p1 = new JPanel();
		p2 = new JPanel();
		p3 = new JPanel();
		p4 = new JPanel();
		
		JLabel I1 = new JLabel("Enter Principal : ");
		JTextField f1 = new JTextField(10);
		JLabel I2 = new JLabel("Enter Interst Rate : ");
		JTextField f2 = new JTextField(10);
		JLabel b = new JLabel("Calculate: ");
		JTextField f3 = new JTextField(20);
		p1.add(I1);
		p1.add(f1);
		p2.add(I2);
		p2.add(f2);
		p3.add(b);
		p4.add(f3);
		add(p1); add(p2); add(p3) ; add(p4);
		pack();
		setVisible(true);
	}
}
public class javaclass1109_06 {
	public static void main(String args[]){
		MyFrame f = new MyFrame();
	}

}
