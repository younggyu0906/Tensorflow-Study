import javax.swing.*;
import java.awt.*;
//Jpanel : 컴포너트를 가지면서 다른 컨테이너에 들어갈수 있음.
class MyFrame extends JFrame{
	public MyFrame(){
		setSize(300,150);
		setLocation(500,500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Frame Test");
		
		JPanel panel1 = new JPanel();
		JLabel label = new JLabel("welcome!. select pizza");
		panel1.add(label);
		
		JPanel panel2 = new JPanel();
		JButton button1 = new JButton("1");
		JButton button2 = new JButton("2");
		JButton button3 = new JButton("3");
		JButton button4 = new JButton("4");
		JButton button5 = new JButton("5");
		panel2.add(button1);
		panel2.add(button2);
		panel2.add(button3);
		panel2.add(button4);
		panel2.add(button5);
		
		
		JPanel panel3 = new JPanel();
		
		

		
		
		

		
	}
}
public class javaclass1031_5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
