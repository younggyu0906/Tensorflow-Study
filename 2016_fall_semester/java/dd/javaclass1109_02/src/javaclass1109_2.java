import java.awt.*;
import javax.swing.*;

class MyFrame extends JFrame{
	public MyFrame(){
		setTitle("BorderLayout Test");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new BorderLayout(5,5));
		setSize(200,300);
		
		JButton button = new JButton("Center");
		add(button,BorderLayout.CENTER);
		add(new JButton("West"),BorderLayout.WEST);
		add(new JButton("East"),BorderLayout.EAST);
		add(new JButton("North"),BorderLayout.NORTH);
		add(new JButton("South"),BorderLayout.SOUTH);
		
		//ㅇㄹpanel.applyComponentOrientation(ComponentOrientation.RIGHT_TO_LEFT);
		pack(); // frame 크지 조절
		setVisible(true);
	}
}
public class javaclass1109_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame f = new MyFrame();

	}

}
