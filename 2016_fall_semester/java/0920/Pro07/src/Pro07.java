
public class Pro07 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			String s = "no news is good news";
			int n = 0;
			
			for (int i = 0; i < s.length(); i++) {	//String의 길이
				if (s.charAt(i) != 'n')		//s 문자열의 i번째 문자
					continue;
				n++;
			}
			System.out.println("Number of n : " + n);
	}

}
