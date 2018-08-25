import java.util.Scanner;

public class Ch05_pro10 {

	public static void main(String[] args) {
		double sBase, pBase, sHieght, pHieght;
		Scanner input = new Scanner(System.in);
		
		System.out.print("지팡이의 그림자 길이 : ");
		sBase = input.nextDouble();				// 지팡이의 그림자 길이 AC
		System.out.print("지팡이의 높이 : ");
		sHieght = input.nextDouble();			// 지팡이의 높이 BC
		System.out.print("피라미드 그림자 길이 : ");
		pBase = input.nextDouble();				// 피라미드 그림자 길이 AE
		
		pHieght = (pBase * sHieght) / sBase;	// DE = AE * BC / AC
		System.out.println("피라미드의 높이는 " + pHieght + " 입니다.");
	}
}
