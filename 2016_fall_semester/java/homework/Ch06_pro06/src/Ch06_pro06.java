public class Ch06_pro06 {
	public static void main(String[] args) {
		boolean primeNumber;			// 소수인지 아닌지참 거짓 값을 저장할 변수
		
		for(int i = 2; i <= 100; i++) {	// 2부터 100까지 소수인지 아닌지를 판별
			primeNumber = true;			// true로 초기화
			for(int j = 2; j < i; j++) { 
				if(i % j == 0) { // i를 2부터 i-1까지 나누어 나머지가 0이면 소수가 아님
					primeNumber = false;
					break;
				}
				else
					continue;
			}
			if(primeNumber)		// i가 소수일 때 i 출력 
				System.out.print(i + " ");
			else
				continue;
		}
	}
}