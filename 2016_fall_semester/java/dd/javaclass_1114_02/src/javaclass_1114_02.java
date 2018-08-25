import java.awt.*;
import javax.swing.*;

class MyPanel extends JPanel{
	Font f;
	public MyPanel(){
		String[] fontList;
		GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
		fontList = ge.getAvailableFontFamilyNames();
		for( int i= 0;i< fontList.length;i++)
			 System.out.println(fontList[i]);
	}
		
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		f = new Font("Agency FB",Font.BOLD,20 );
		//이름, 스타일, 크기(1 포인트 = 1/72인치)
		g.setFont(f);
		g.drawString("Font Test",20,50);
		
		f = new Font("Serif", Font.BOLD | Font.ITALIC,20);
		g.setFont(f);
		g.drawString("Serif Font Test", 20, 70);
	}	
}
	
public class javaclass_1114_02 extends JFrame {
	public javaclass_1114_02(){
		setSize(500,200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Font Test");
		add(new MyPanel());
		setVisible(true);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		javaclass_1114_02 f = new javaclass_1114_02();

	}

}
