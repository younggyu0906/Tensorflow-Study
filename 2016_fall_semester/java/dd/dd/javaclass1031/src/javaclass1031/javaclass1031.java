//GUI �� �����̳ʿ� ������Ʈ�� ���� - AWT(������) or SWING(�÷��� ����)
//�ֻ��� �����̳� : ���� �ٸ� �����̳� �ȿ� ���� �ɼ� ���� �����̳�
//�Ϲ� �����̳� : �ٸ� �����̳� �ȿ� ���Ե� �� �ִ� �����̳�
import javax.swing.*;
import java.awt.*; //layout ���� class

class MyFrame extends JFrame{
	public MyFrame(){
		super(); //��������
		setSize(300,200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("My Frame");
		setLocation(100,200); //default �� 0,0
		
		setLayout(new FlowLayout());  //component ��ġ ����
		JButton button = new JButton("Button");
		button.
		add(button);   //���� ������Ʈ�� â�� �߰�
		setVisible(true);
	}
}
public class javaclass1031 {

	public static void main(String[] args) {
		MyFrame f = new MyFrame();
		
	}

}
