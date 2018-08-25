import javax.swing.*;

import java.awt.*;

class MyFrame extends JFrame{
	public MyFrame(){
		super("Test"); //생략가능
		Toolkit kit = Toolkit.getDefaultToolkit(); //프로그램 자원 정보 제공
		Dimension screenSize = kit.getScreenSize();
		System.out.println(screenSize.width+", "+screenSize.height);
		
		setSize(300,200);
		setLocation(screenSize.width/2,screenSize.height/2);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//setTitle("My Frame");
		
		Image img = kit.getImage("Chrysanthemum.jpg");//파일 하나 불러오기
		setIconImage(img);//불러온이미지를 아이콘 이미지로 사용
		
		setLayout(new FlowLayout());
		JButton button = new JButton("Button");
		this.add(button);
		
		setResizable(false);//크기 조절 false
		setVisible(true);
	}
}
public class javaclass1031_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame mf = new MyFrame();

	}

}
