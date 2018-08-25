import javax.swing.*;

import java.awt.*;
//Jpanel : 컴포너트를 가지면서 다른 컨테이너에 들어갈수 있음.
class MyFrame extends JFrame{
	public MyFrame(){
		Toolkit kit = Toolkit.getDefaultToolkit(); //프로그램 자원 정보 제공
		Dimension screenSize = kit.getScreenSize();
		System.out.println(screenSize.width+", "+screenSize.height);
		
		setSize(300,200);
		setLocation(screenSize.width/2,screenSize.height/2);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("My Frame");
		
		JPanel panel = new JPanel();
		JLabel label = new JLabel("Hello World!");

		JButton button1 = new JButton("Left");
		JButton button2 = new JButton("Center");
		JButton button3 = new JButton("Right");
		
		
		button1.setBorderPainted(false);
		button2.setBorderPainted(false);
		button3.setBorderPainted(false);
		//button3.setContentAreaFilled(false);
		//button3.setRolloverEnabled(false);
		button1.setToolTipText("Button test");
		
		panel.add(label);
		panel.add(button1);
		panel.add(button2);
		panel.add(button3);
		
		JTextField t1 = new JTextField(10);
		JTextField t2 = new JTextField(10);
		t2.setEditable(true);
		t1.setText("Enter Text");
		t2.setText("Not Editable");
		
		panel.add(t1);
		panel.add(t2);
		
		add(panel);
		setVisible(true);
		System.out.println(label.getText());
		
	}
}
public class javaclass1031_3{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame mf = new MyFrame();

	}

}
