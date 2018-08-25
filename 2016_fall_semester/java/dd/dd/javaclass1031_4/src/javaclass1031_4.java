import javax.swing.*;
import java.awt.*;
//Jpanel : 컴포너트를 가지면서 다른 컨테이너에 들어갈수 있음.
class MyFrame extends JFrame{
	public MyFrame(){
		super();
		setSize(300,150);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		JPanel panelA = new JPanel();
		JPanel panelB = new JPanel();
		
		JLabel label = new JLabel("welcome!. select pizza");
		panelA.add(label);

		JButton button1 = new JButton("Left");
		JButton button2 = new JButton("Center");
		JButton button3 = new JButton("Right");
		
		
		panelB.add(button1);
		panelB.add(button2);
		panelB.add(button3);
		
		panel.add(panelA);
		panel.add(panelB);
		
		panel.setBackground(Color.BLUE);
		panelA.setBackground(Color.GREEN);
		panelB.setBackground(new Color(255,0,0));
		
		add(panel);
		setVisible(true);
		System.out.println(label.getText());
		
	}
}
public class javaclass1031_4{

	public static void main(String[] args) {
		MyFrame mf = new MyFrame();

	}

}
