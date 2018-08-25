
import javax.swing.*;
import java.awt.event.*;

class MyListener implements ActionListener{
	public void actionPerformed(ActionEvent e){
		JButton button = (JButton)e.getSource();
		button.setText("Button Pressed");
		//label.setText("Burron is Pressed");
		//laber�� MyFrame class�� private member�̱� ������ ������ �����
	}
	
}

class MyFrame extends JFrame{
	private JButton button;
	private JLabel label;
	private MyListener listener = new MyListener();
	private int count = 0;
	
	public MyFrame(){
		setSize(300,200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Event Example");
		
		JPanel panel =  new JPanel();
		button = new JButton("Press Button");
		label = new JLabel("Button is not pressed yet");
		button.addActionListener(new MyListener());
		panel.add(button);
		panel.add(label);
		add(panel);
		setVisible(true);
	}
}
public class javaclass_1116_01 {
 public static void main(String args[]){
	 MyFrame f= new MyFrame();
 }
}
/*�̺�Ʈ ó���� �ۼ�
1. �������� Ŭ������ �̺�Ʈ ó���� �ۼ�
2. ���� Ŭ������ �̺�Ʈ ó���� �ۼ�
3.������ Ŭ������ �̺�Ʈ ó���� ����
4.���� Ŭ������ ����ϴ� ���
*/