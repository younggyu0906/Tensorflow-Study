import javax.swing.*;
import java.awt.event.*;

class MyFrame extends JFrame{	
	private JPanel panel = new JPanel();
	public MyFrame(){
		super();
		setTitle("Key Event Example");
		setSize(300,200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JTextField tf = new JTextField(20);
		tf.addKeyListener(new MyKeyListener());
		
		tf.requestFocus();
		panel.add(tf);
		add(panel);
		setVisible(true);
	}
	private class MyKeyListener implements KeyListener{
		public void keyPressed(KeyEvent e){
			display(e,"KeyPressed");
		}
		public void keyReleased(KeyEvent e){
			display(e,"KeyReleased");
		}
		public void keyTyped(KeyEvent e){ //유니코드의 경우 추카
			display(e ,"KeyTyped");
		}
	}
	private void display(KeyEvent e, String s){
		char ch = e.getKeyChar();
		int keyCode = e.getKeyCode();
		String modifiers = e. isAltDown() + " " + e.isControlDown() + " "+ e.isShiftDown();
		System.out.println(s + " "+ ch +" "+ keyCode + " "+ modifiers);
	}
}
public class javaclass_1116_06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MyFrame();

	}

}
