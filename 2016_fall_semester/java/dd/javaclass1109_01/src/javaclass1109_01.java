import java.awt.*;
import javax.swing.*;

class MyFrame extends JFrame{
	public MyFrame(){
		setTitle("FlowLayout Test");
		setSize(500,200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		//JPanel panel = new JPanel();
		//panel.setLayout(new FlowLayout(FlowLayout.LEADING,10,20));
		JPanel panel = new JPanel(new FlowLayout(FlowLayout.TRAILING,10,20));
		//FlowLayout.LEADING, FlowLayout.CENTER, FlowLayout.TRAILING
		panel.add(new JButton("Button1"));
		panel.add(new JButton("Button2"));
		panel.add(new JButton("Button3"));
		panel.add(new JButton("B4"));
		panel.add(new JButton("Long Button1"));
		add(panel);
		//ㅇㄹpanel.applyComponentOrientation(ComponentOrientation.RIGHT_TO_LEFT);
		pack(); // frame 크지 조절
		setVisible(true);
	}
}
public class javaclass1109_01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame f = new MyFrame();

	}

}
