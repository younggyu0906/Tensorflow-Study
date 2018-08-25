import java.awt.*;
import javax.swing.*;

class MyFrame extends JFrame{
	public MyFrame(){
		setTitle("GridLayout Test");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new GridLayout(2,3,5,5));
	
		add(new JButton("Button1"));
		add(new JButton("Button2"));
		add(new JButton("Button3"));
		add(new JButton("B4"));
		add(new JButton("Long Button5"));
	
		pack();
		setVisible(true);
	}
}
public class javaclass1109_03 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame f = new MyFrame();
	}
}
