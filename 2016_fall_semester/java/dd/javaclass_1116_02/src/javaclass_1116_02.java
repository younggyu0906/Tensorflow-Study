import java.awt.Color;
import java.awt.event.*;

import javax.swing.*;

class MyFrame extends JFrame{
	private JButton button;
	private JLabel label;
	private int count =0;
	
	public MyFrame(){
		setSize(300,200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Event Example");

		JPanel panel = new JPanel();
		button = new JButton("Press Button");
		label = new JLabel("Button is not pressed yet");
		button.addActionListener(new MyListener());
		panel.add(button);
		panel.add(label);
		add(panel);
		setVisible(true);
	}
	private class MyListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			if(e.getSource() == button)
				label.setText("버튼이 눌러진 회수 : " + ++count);
		}
	}
}

public class javaclass_1116_02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MyFrame();
	}

}
