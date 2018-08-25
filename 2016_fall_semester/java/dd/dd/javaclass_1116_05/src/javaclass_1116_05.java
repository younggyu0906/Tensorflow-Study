import javax.swing.*;

import java.util.*;
import java.awt.*;
import java.awt.event.*;

class MyFrame extends JFrame{
	private JPasswordField pw;
	private JTextField tf;
	private JPanel panel = new JPanel();
	MyListener listener = new MyListener();

	public MyFrame(){
		setSize(300,200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Action Event Example");
		
		tf = new JTextField(20);
		pw = new JPasswordField(20);
		pw.setEchoChar('*');
		tf.addActionListener(listener);
		pw.addActionListener(listener);
		
		panel.add(tf);
		panel.add(pw);
		add(panel);
		setVisible(true);
	}
	private class MyListener implements ActionListener{
		StringTokenizer st;
		String[] str = new String[3];
		int i= 0;
		public void actionPerformed(ActionEvent e){
			if(e.getSource() == tf){
				st = new StringTokenizer(tf.getText());
				while(st.hasMoreTokens()){
					str[i] = st.nextToken();
					i++;
				}
				calculate();
			}
			else if(e.getSource() == pw)
				System.out.println(pw.getPassword());
		}
		public void calculate(){
			int n1,n2,result = 0;
			
			n1 = Integer.parseInt(str[0]);
			n2 = Integer.parseInt(str[2]);
			switch(str[1]){
			case "+" : result = n1 + n2 ;break;
			case "-" : result = n1 - n2 ;break;
			case "*" : result = n1 * n2 ;break;
			case "/" : result = n1 / n2 ;break;
			default : break;
			}
			tf.setText(str[0] + " " + str[1] + " " +  str[2] + " = " + result);
		}
	}
}
public class javaclass_1116_05 {
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MyFrame();

	}

}
