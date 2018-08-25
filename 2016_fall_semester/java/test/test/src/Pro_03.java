import java.util.Scanner;


public class Pro_03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*int hight, feet;
		double inch;
		Scanner input = new Scanner(System.in);
		
		System.out.print("키를 입력하시오(정수, cm) : ");
		hight = (input.nextInt());
		
		inch = hight / 2.54;
		if(inch < 12)
			System.out.print(hight + "cm는 " + inch + "입니다.");
		else {
			feet = (int)(inch / 12);
			inch = inch % 12;
			System.out.print(hight + "cm는 " + feet + "피트 " + inch + "인치 입니다.");
		}
		input.close();
	}*/
		
		double cm, inch, feet;
		
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter height(cm)");
		cm = sc.nextDouble();
		inch = cm / 2.54;
		System.out.println(cm + " : " + inch);
		
		feet = inch / 12;
		inch = (feet - (int)feet) * 12;
		System.out.println((int)feet + "feet " + inch + "inch");
		System.out.printf("%d feet %.3f inch\n\n", (int)feet, inch);
		//%lf 대신 %f 사용
		
		feet = cm / (2.54 * 12);
		System.out.println(feet);
		inch = (feet - (int)feet) * 12;
		System.out.printf("%d feet %.3f inch\n", (int)feet, inch);
		
		
	}

}
