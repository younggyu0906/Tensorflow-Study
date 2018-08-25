import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

class MyPanel extends JPanel {
	private JLabel label;
	private JButton button;
	private int count = 0;
	private ImageIcon icon = new ImageIcon("icon.jpg");
	private ImageIcon dog = new ImageIcon("dog.jpg");
	
	public MyPanel() {
		label = new JLabel("Press button to see image");
		button = new JButton("Image Button");
		button.setIcon(icon);
		button.addActionListener(new MyListener());
		button.setBorder(BorderFactory.createTitledBorder("Image"));
		setBorder(BorderFactory.createEtchedBorder());	// javax.swing
		add(label);
		add(button);
	}
	private class MyListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			if(count % 2 == 0) {
				label.setIcon(dog);
				label.setText(null);
			}
			else {
				label.setIcon(null);
				label.setText("Press button to see image");
			}
		}
	}
}
public class Ch17_Pro01_ImagLabelTest extends JFrame {
	public Ch17_Pro01_ImagLabelTest() {
		setTitle("Image Label");
		setSize(300, 350);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		add(new MyPanel());
		setVisible(true);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Ch17_Pro01_ImagLabelTest();
	}
}
