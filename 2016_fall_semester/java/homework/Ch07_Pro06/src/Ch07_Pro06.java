import java.util.Scanner;

class CntConVow {	// ����, ������ ������ ���� Ŭ����
	private int consonant = 0;	// ������ ����
	private int vowel = 0;		// ������ ����
	private int length;			// ���ڿ� ����
	private String str;			// ���ڿ�
	private char c;				// ���ڸ� �� ���ھ� �б� ���� ����
	
	public String getStr() { return str; }				// str getter
	public void setStr(String str) { this.str = str; }	// str setter
	public void print() {		// ��� �Լ�
		System.out.println("String : " + str);
		System.out.println("consonant : " + consonant + ", vowel : " + vowel);
	}
	public void count() {		// ����, ������ ������ ���� �Լ�
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
				case 'U' : vowel++; break;		// ������ ��� vowel++
				default : consonant++; break;	// ������ �ƴ� ���(����) consonant++
			}
		}
	}
}

public class Ch07_Pro06 {
	public static void main(String[] args) {
		String str;		// ����ڷκ��� ���ڿ��� �Է¹޾� ������ ����
		CntConVow c1 = new CntConVow();	// ��ü ����
		Scanner input = new Scanner(System.in); // Scanner ��ü ����
		
		System.out.print("Enter String : ");
		str = input.next();		// ���ڿ��� �Է� �޾� str�� ����
		c1.setStr(str);			// str ����
		c1.count();				// ����, ������ ���� ī��Ʈ
		c1.print();				// ���
	}
}
