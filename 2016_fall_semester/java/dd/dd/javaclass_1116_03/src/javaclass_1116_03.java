import java.awt.event.*;
import javax.swing.*;
//Event handler를 annoymous class로 작성하는 방법
//간단하지만 button이 여러개이면 button 마다 작성해줘야함
class MyFrame extends JFrame{
	private JButton button;
	private JLabel label;
	
	public MyFrame(){
		setSize(200,100);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Event Example");
		
		JPanel panel = new JPanel();
		button = new JButton("Press Button");
		label = new JLabel("Button is not pressed yet");
		button.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				if(e.getSource() == button)
					label.setText("Button is pressed");
			}
		});
		panel.add(button);
		panel.add(label);
		add(panel);
		setVisible(true);
	}
}
public class javaclass_1116_03 {
 public static void main(String args[]){
	 MyFrame f = new MyFrame();
 }
}
