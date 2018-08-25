//ChangeListener  : stateChanged()를 가진 인터페이스
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class MyFrame extends JFrame{
	private JButton button;
	private Color color =  Color.LIGHT_GRAY;
	private JPanel panel; 
	private MyListener listener = new MyListener();
	
	public MyFrame(){
		setTitle("Color chooser Test");
		setSize(300,200);
     	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		panel = new JPanel();
		panel.setBackground(color);
		button = new JButton("Change Color");
		button.addActionListener(listener);
		add(panel, BorderLayout.CENTER);
		add(button, BorderLayout.SOUTH);
		setVisible(true);
	}
	
	private class MyListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			color = JColorChooser.showDialog(MyFrame.this, "Choose a color", color);
			//parent component, title, initial color
			panel.setBackground(color);
		}
	}

}
public class javaclass_1114_01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			MyFrame f = new MyFrame();
	}

}
