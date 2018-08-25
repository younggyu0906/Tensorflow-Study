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

		JButton button = new JButton("Button");
		
		//button.setBorderPainted(false);
		//button.setContentAreaFilled(false);
		button.setRolloverEnabled(true);
		button.setToolTipText("Button test");
		
		panel.add(label);
		panel.add(button);
		add(panel);
		setVisible(true);
		System.out.println(label.getText());
	}
}
public class javaclass1031_2{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame mf = new MyFrame();

	}

}
