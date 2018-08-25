public class Ch06_pro08 {
	public static void main(String[] args) {
		for(int i = 1; i <= 10; i++) {	//구구단 1단~10단
			for(int j = 1; j <= 10; j++) {
				System.out.printf("%d\t", i * j); // 구구단 출력
			}
			System.out.printf("\n");
		}
	}
}
