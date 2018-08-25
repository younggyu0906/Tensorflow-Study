public class Ch06_pro07 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a = 1, b = 1, c = 1; //삼각형 밑변, 높이, 빗변의 길이를 저장 할 변수
		int count = 0; //피타고라스의 정리가 성립하는 삼각형의 갯수를 저장 할 변수

		for(c = 1; c <= 100; c++) {
			if(Math.pow(c, 2) == Math.pow(a, 2) + Math.pow(b, 2)) {
				System.out.println(a + "^2 + " + b +  "^2 = "  + c +  "^2 피타고라스의 정리가 성립합니다.");//피타고라스의 정리가 성립할 경우 성립하는 경우 출력   
				count++;//성립하는 경우 갯수 값 증가
			}
			else {//성립하지 않는 경우 b값 증가하여 성립여부 판별
				for(b = 1; b <= 100; b++) {
					if(Math.pow(c, 2) == Math.pow(a, 2) + Math.pow(b, 2)) {
						System.out.println(a + "^2 + " + b +  "^2 = "  + c +  "^2 피타고라스의 정리가 성립합니다.");//피타고라스의 정리가 성립할 경우 성립하는 경우 출력   
						count++;//성립하는 경우 갯수 값 증가
					}
					else {//성립하지 않는 경우 a값 증가하여 성립여부 판별	
						for(a = 1; a <= 100; a++) {
							if(Math.pow(c, 2) == Math.pow(a, 2) + Math.pow(b, 2)) {
								System.out.println(a + "^2 + " + b +  "^2 = "  + c +  "^2 피타고라스의 정리가 성립합니다.");//피타고라스의 정리가 성립할 경우 성립하는 경우 출력   
								count++;//성립하는 경우 갯수 값 증가
							}
						}
					}
				}
			}
		}
		System.out.println("각 변의 길이 100이하의 피타고라스의 정리가 성립하는 삼각형은 " + count + "개 입니다"); //결과 값 출력
	}
}