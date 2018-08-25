import java.awt.event.*;
import javax.swing.*;

class CalcInterest extends JFrame {
	private JLabel lblPrin, lblRate;	// ���̺� ��ü ����
	private JButton button;				// ��ư ��ü ����
	private JTextField tfPrin, tfRate, tfResult;	// �ؽ�Ʈ �ʵ� ��ü ����
	MyActionListener listener = new MyActionListener();	// ������ ��ü ����
	
	public CalcInterest() {
		setTitle("���� ����");	// ���� ����
		setSize(300, 180);		// ũ�� ����
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		lblPrin = new JLabel("������ �Է��Ͻÿ�        ");
		lblRate = new JLabel("������ �Է��Ͻÿ�        ");
		tfPrin = new JTextField(7);
		tfRate = new JTextField(7);
		tfResult = new JTextField(20);
		button = new JButton("��ȯ");
		button.addActionListener(listener);	// ��ư�� �̺�Ʈ ������ ��ü ���
		
		panel.add(lblPrin);	// �гο� ���̺� �߰�
		panel.add(tfPrin);	// �гο� mile �ؽ�Ʈ �ʵ� �߰�
		panel.add(lblRate);	// �гο� ���̺� �߰�
		panel.add(tfRate);	// �гο� km �ؽ�Ʈ �ʵ� �߰�
		panel.add(button);	// �гο� ��ȯ ��ư �߰�
		panel.add(tfResult);	// �гο� km �ؽ�Ʈ �ʵ� �߰�
		add(panel);
		setVisible(true);
	}
	private class MyActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			tfResult.setText(trans(tfPrin.getText(), tfRate.getText()));
			// tfResult�� ���ڸ� trans�Լ��� ȣ���Ͽ� tfPrin�� tfRate�� ���� ��ȯ�� ������ ����
		}
	}
	private String trans(String principal, String rate){	// �Ű������� ���� principal���� rate�� ��ȯ�� ���� String���� ����
		int iPrin = Integer.parseInt(principal);	// int�� iPrin�� �����ϰ� �Ű������� ���� principal���� int������ ��ȯ�Ͽ� ����
		double dRate = Double.parseDouble(rate);	// double�� drate�� �����ϰ� �Ű������� ���� rate���� double������ ��ȯ�Ͽ� ����
		int interest = (int)(iPrin * dRate / 100);	// int�� interest�� �����ϰ� ���ڸ� ����� ���� int������ ����
		return "���ڴ� �� " + interest + "���� �Դϴ�.";	// ���ڿ� ����
	}
}

public class Ch16_Pro02 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CalcInterest test = new CalcInterest();
	}
}