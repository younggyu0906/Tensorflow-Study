import java.util.Scanner;

class CntConVow {	// 자음, 모음의 개수를 세는 클래스
	private int consonant = 0;	// 자음의 개수
	private int vowel = 0;		// 모음의 개수
	private int length;			// 문자열 길이
	private String str;			// 문자열
	private char c;				// 문자를 한 글자씩 읽기 위한 변수
	
	public String getStr() { return str; }				// str getter
	public void setStr(String str) { this.str = str; }	// str setter
	public void print() {		// 출력 함수
		System.out.println("String : " + str);
		System.out.println("consonant : " + consonant + ", vowel : " + vowel);
	}
	public void count() {		// 자음, 모음의 개수를 세는 함수
		length = str.length();
		for(int i = 0; i < length; i++) {
			c = str.charAt(i);
			switch (c) {
				case 'a' :
				case 'e' :
				case 'i' :
				case 'o' :
				case 'u' :
				case 'A' :
				case 'E' :
				case 'I' :
				case 'O' :
				case 'U' : vowel++; break;		// 모음일 경우 vowel++
				default : consonant++; break;	// 모음이 아닐 경우(자음) consonant++
			}
		}
	}
}

public class Ch07_Pro06 {
	public static void main(String[] args) {
		String str;		// 사용자로부터 문자열을 입력받아 저장할 변수
		CntConVow c1 = new CntConVow();	// 객체 생성
		Scanner input = new Scanner(System.in); // Scanner 객체 생성
		
		System.out.print("Enter String : ");
		str = input.next();		// 문자열을 입력 받아 str에 저장
		c1.setStr(str);			// str 설정
		c1.count();				// 자음, 모음의 개수 카운트
		c1.print();				// 출력
	}
}
