import java.util.Scanner;

public class Prog02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char c;
		String str;
		
		Scanner sc = new Scanner(System.in); // Scanner class에 next()
		System.out.print("Enter character : ");
		str = sc.next(); //단어 (token) 입력
		c = str.charAt(0);  //string으로 입력받아서 0번째 문자열을 char에 저장
		switch (c) {
			case 'a' :
			case 'e' :
			case 'i' :
			case 'o' :
			case 'u' : System.out.println("Vowel"); break;
			default : System.out.println("Consonant"); break;
		}
	}
}
