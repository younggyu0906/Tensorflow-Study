import java.awt.*;
import javax.swing.*;

class MyFrame extends JFrame{
	public MyFrame(){
		setTitle("BoxLayout Test");
		setSize(300,500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JPanel panel = new JPanel();
		
		panel.setLayout(new BoxLayout(panel,BoxLayout.Y_AXIS));
		//BoxLayout.X_AXIS
		makeButton(panel,"Button1");
		makeButton(panel,"Button2");
		makeButton(panel,"Button3");
		makeButton(panel,"B4");
	}
	private void makeButton(JPanel,String){}
}
public class javaclass1109_04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
