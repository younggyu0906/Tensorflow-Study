import java.awt.event.*;
import javax.swing.*;

class CalcInterest extends JFrame {
	private JLabel lblPrin, lblRate;	// 레이블 객체 생성
	private JButton button;				// 버튼 객체 생성
	private JTextField tfPrin, tfRate, tfResult;	// 텍스트 필드 객체 생성
	MyActionListener listener = new MyActionListener();	// 리스너 객체 생성
	
	public CalcInterest() {
		setTitle("이자 계산기");	// 제목 설정
		setSize(300, 180);		// 크기 설정
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		lblPrin = new JLabel("원금을 입력하시오        ");
		lblRate = new JLabel("이율을 입력하시오        ");
		tfPrin = new JTextField(7);
		tfRate = new JTextField(7);
		tfResult = new JTextField(20);
		button = new JButton("변환");
		button.addActionListener(listener);	// 버튼에 이벤트 리스너 객체 등록
		
		panel.add(lblPrin);	// 패널에 레이블 추가
		panel.add(tfPrin);	// 패널에 mile 텍스트 필드 추가
		panel.add(lblRate);	// 패널에 레이블 추가
		panel.add(tfRate);	// 패널에 km 텍스트 필드 추가
		panel.add(button);	// 패널에 변환 버튼 추가
		panel.add(tfResult);	// 패널에 km 텍스트 필드 추가
		add(panel);
		setVisible(true);
	}
	private class MyActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			tfResult.setText(trans(tfPrin.getText(), tfRate.getText()));
			// tfResult의 글자를 trans함수를 호출하여 tfPrin와 tfRate의 값을 변환한 값으로 설정
		}
	}
	private String trans(String principal, String rate){	// 매개변수로 받은 principal값을 rate로 변환한 값을 String으로 리턴
		int iPrin = Integer.parseInt(principal);	// int형 iPrin을 선언하고 매개변수로 받은 principal값을 int형으로 변환하여 저장
		double dRate = Double.parseDouble(rate);	// double형 drate를 선언하고 매개변수로 받은 rate값을 double형으로 변환하여 저장
		int interest = (int)(iPrin * dRate / 100);	// int형 interest를 선언하고 이자를 계산한 값을 int형으로 저장
		return "이자는 연 " + interest + "만원 입니다.";	// 문자열 리턴
	}
}

public class Ch16_Pro02 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CalcInterest test = new CalcInterest();
	}
}