import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MyFrame extends JFrame{
	private JButton b1,b2;
	private JTextField t;
	private JPanel panel;
	MyListener listener = new MyListener();
	
	public MyFrame(){
		setSize(300,200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Action Event Example");
		
		panel = new JPanel();
		b1 = new JButton("Yellow");
		b1.addActionListener(listener);
		b2 = new JButton("PINK");
		b2.addActionListener(listener);
		t = new JTextField(10);
		panel.add(b1);
		panel.add(b2);
		panel.add(t);
		add(panel);
		setVisible(true);
	}
	private class MyListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			if(e.getSource() == b1){
				t.setText("b1 clicked");
				panel.setBackground(Color.yellow);
			}
			if(e.getSource() == b2){
				t.setText("b2 clicked");
				panel.setBackground(Color.PINK);
			}
		}
	}
	
}
public class javaclass_1116_04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MyFrame();
	}

}
