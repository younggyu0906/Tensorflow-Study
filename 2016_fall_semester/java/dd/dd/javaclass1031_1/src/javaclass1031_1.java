import javax.swing.*;

import java.awt.*;

class MyFrame extends JFrame{
	public MyFrame(){
		super("Test"); //��������
		Toolkit kit = Toolkit.getDefaultToolkit(); //���α׷� �ڿ� ���� ����
		Dimension screenSize = kit.getScreenSize();
		System.out.println(screenSize.width+", "+screenSize.height);
		
		setSize(300,200);
		setLocation(screenSize.width/2,screenSize.height/2);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//setTitle("My Frame");
		
		Image img = kit.getImage("Chrysanthemum.jpg");//���� �ϳ� �ҷ�����
		setIconImage(img);//�ҷ����̹����� ������ �̹����� ���
		
		setLayout(new FlowLayout());
		JButton button = new JButton("Button");
		this.add(button);
		
		setResizable(false);//ũ�� ���� false
		setVisible(true);
	}
}
public class javaclass1031_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame mf = new MyFrame();

	}

}
