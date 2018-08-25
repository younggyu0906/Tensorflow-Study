
import javax.swing.*;
import java.awt.event.*;

class MyListener implements ActionListener{
	public void actionPerformed(ActionEvent e){
		JButton button = (JButton)e.getSource();
		button.setText("Button Pressed");
		//label.setText("Burron is Pressed");
		//laber은 MyFrame class의 private member이기 때문에 접근이 어려움
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
/*이벤트 처리기 작성
1. 독립적인 클래스로 이벤트 처리기 작성
2. 내부 클래스로 이벤트 처리기 작성
3.프레임 클래스에 이벤트 처리를 구현
4.무명 클래스를 사용하는 방법
*/