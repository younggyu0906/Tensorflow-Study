import java.awt.event.*;

import javax.swing.*;

import java.awt.*;

class MyPanel extends JPanel {
	private JRadioButton small, medium, large;
	private JLabel text;
	private JPanel top, size, result;
	private MyListener listener = new MyListener();
	
	public MyPanel() {
		setLayout(new BorderLayout());
		top = new JPanel();
		JLabel label = new JLabel("Select coffee size");
		top.add(label);
		add(top, BorderLayout.NORTH);
		top.setBorder(BorderFactory.createEtchedBorder());
		
		size = new JPanel();
		small = new JRadioButton("Small");
		medium = new JRadioButton("Medium");
		large = new JRadioButton("Large");
		ButtonGroup group = new ButtonGroup();		
		medium.addActionListener(listener);
		large.addActionListener(listener);
		size.add(small); size.add(medium); size.add(large);
		add(size, BorderLayout.CENTER);
		size.setBorder(BorderFactory.createTitledBorder("Size"));
		
		result = new JPanel();
		text = new JLabel("Size is not selcted");
		text.setForeground(Color.red);
		result.setBackground(Color.green);
		result.add(text);
		add(result, BorderLayout.SOUTH);
		result.setBorder(BorderFactory.createRaisedSoftBevelBorder());
	}
	private class MyListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
		if(e.getSource() == small)
			text.setText("Small");
		else if(e.getSource() == medium)
			text.setText("Medium");
		else
			text.setText("Larger");
		System.out.println(small.isSelected() + " " +
			medium.isSelected() + " " + large.isSelected());
		}
	}
}
public class Ch17_ProRadioButton extends JFrame {
		public Ch17_ProRadioButton() {
			setTitle("Image Label");
			setSize(300, 250);
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			add(new MyPanel());
			setVisible(true);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Ch17_ProRadioButton();
	}
}
