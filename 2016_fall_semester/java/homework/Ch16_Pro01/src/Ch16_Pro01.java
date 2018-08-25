import java.awt.event.*;
import javax.swing.*;

class TransMileToKm extends JFrame {
	private JLabel label;		// �޼����� ���� �� ���̺� ��ü ����
	private JButton button;		// ��ȯ �̺�Ʈó���� �� ��ư ��ü ����
	private JTextField tfMile;	// ���� ������ �Է¹��� �ؽ�Ʈ �ʵ� ��ü ����
	private JTextField tfKm;	// ������ km�� ��ȯ�� ���� ��� �� �ؽ�Ʈ �ʵ� ��ü ����
	MyActionListener listener = new MyActionListener();	// ������ ��ü ����
	
	public TransMileToKm() {
		setTitle("������ ų�ι��ͷ� ��ȯ");	// ���� ����
		setSize(350, 150);	// ũ�� ����
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		label = new JLabel("�Ÿ��� ���� ������ �Է��Ͻÿ�");
		tfMile = new JTextField(8);
		tfKm = new JTextField(25);
		button = new JButton("��ȯ");
		button.addActionListener(listener);	// ��ư�� �̺�Ʈ ������ ��ü ���
		
		panel.add(label);	// �гο� ���̺� �߰�
		panel.add(tfMile);	// �гο� mile �ؽ�Ʈ �ʵ� �߰�
		panel.add(button);	// �гο� ��ȯ ��ư �߰�
		panel.add(tfKm);	// �гο� km �ؽ�Ʈ �ʵ� �߰�
		add(panel);
		setVisible(true);
	}
	private class MyActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			double mile = Double.parseDouble(tfMile.getText());
			// double�� ���� mile�� �����ϰ�, tfMile�� ���� �޾� double������ ��ȯ�� ���� ����
			tfKm.setText(trans(mile));
			// tfMile�� ���� �Է¹��� mile���� km�� ��ȯ�Ͽ� tfKm�� ���ڿ��� ���
		}
	}
	private String trans(double mile) {	// �Ű������� ���� mile���� km�� ��ȯ�� ���� String���� ����
		double km = mile * 1.6;	// �Ű������� ���� mile ���� km ������ ��ȯ �� km ������ ����
		return mile + " ������ " + km + " ų�ι����Դϴ�.";	// ���ڿ� ����
	}
}

public class Ch16_Pro01 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TransMileToKm test = new TransMileToKm();
	}
}
