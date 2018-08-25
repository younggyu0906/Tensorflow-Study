//GUI 는 컨테이너와 컴포넌트로 구성 - AWT(구버전) or SWING(플랫폼 독립)
//최상위 컨테이너 : 저대 다른 컨테이너 안에 포함 될수 없는 컨테이너
//일반 컨테이너 : 다른 컨테이너 안에 포함될 수 있는 컨테이너
import javax.swing.*;
import java.awt.*; //layout 관련 class

class MyFrame extends JFrame{
	public MyFrame(){
		super(); //생략가능
		setSize(300,200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("My Frame");
		setLocation(100,200); //default 는 0,0
		
		setLayout(new FlowLayout());  //component 배치 설정
		JButton button = new JButton("Button");
		button.
		add(button);   //만든 컴포넌트를 창에 추가
		setVisible(true);
	}
}
public class javaclass1031 {

	public static void main(String[] args) {
		MyFrame f = new MyFrame();
		
	}

}
