import java.util.Scanner;


public class Pro_03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*int hight, feet;
		double inch;
		Scanner input = new Scanner(System.in);
		
		System.out.print("Ű�� �Է��Ͻÿ�(����, cm) : ");
		hight = (input.nextInt());
		
		inch = hight / 2.54;
		if(inch < 12)
			System.out.print(hight + "cm�� " + inch + "�Դϴ�.");
		else {
			feet = (int)(inch / 12);
			inch = inch % 12;
			System.out.print(hight + "cm�� " + feet + "��Ʈ " + inch + "��ġ �Դϴ�.");
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
		//%lf ��� %f ���
		
		feet = cm / (2.54 * 12);
		System.out.println(feet);
		inch = (feet - (int)feet) * 12;
		System.out.printf("%d feet %.3f inch\n", (int)feet, inch);
		
		
	}

}
