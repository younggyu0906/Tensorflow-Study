import java.awt.event.*;
import javax.swing.*;

class TransMileToKm extends JFrame {
	private JLabel label;		// 메세지를 보여 줄 레이블 객체 생성
	private JButton button;		// 변환 이벤트처리를 할 버튼 객체 생성
	private JTextField tfMile;	// 마일 단위를 입력받을 텍스트 필드 객체 생성
	private JTextField tfKm;	// 마일을 km로 면환한 값을 출력 할 텍스트 필드 객체 생성
	MyActionListener listener = new MyActionListener();	// 리스너 객체 생성
	
	public TransMileToKm() {
		setTitle("마일을 킬로미터로 변환");	// 제목 설정
		setSize(350, 150);	// 크기 설정
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		label = new JLabel("거리를 마일 단위로 입력하시오");
		tfMile = new JTextField(8);
		tfKm = new JTextField(25);
		button = new JButton("변환");
		button.addActionListener(listener);	// 버튼에 이벤트 리스너 객체 등록
		
		panel.add(label);	// 패널에 레이블 추가
		panel.add(tfMile);	// 패널에 mile 텍스트 필드 추가
		panel.add(button);	// 패널에 변환 버튼 추가
		panel.add(tfKm);	// 패널에 km 텍스트 필드 추가
		add(panel);
		setVisible(true);
	}
	private class MyActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			double mile = Double.parseDouble(tfMile.getText());
			// double형 변수 mile을 선언하고, tfMile의 값을 받아 double형으로 변환한 값을 저장
			tfKm.setText(trans(mile));
			// tfMile로 부터 입력받은 mile값을 km로 변환하여 tfKm의 문자열로 출력
		}
	}
	private String trans(double mile) {	// 매개변수로 받은 mile값을 km로 변환한 값을 String으로 리턴
		double km = mile * 1.6;	// 매개변수로 받은 mile 값을 km 값으로 변환 후 km 변수에 저장
		return mile + " 마일은 " + km + " 킬로미터입니다.";	// 문자열 리턴
	}
}

public class Ch16_Pro01 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TransMileToKm test = new TransMileToKm();
	}
}
