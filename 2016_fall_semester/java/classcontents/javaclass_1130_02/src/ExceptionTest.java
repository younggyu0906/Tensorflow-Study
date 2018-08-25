/*
import java.util.Scanner;
//RuntimeException은 화면에 보이지는 않지만 실행과정에서 생길수 있으므로 처리해줘야 한다.
public class ExceptionTest {
	public static void main(String args[]){
		method();
	}
	public static void method(){
		int [] list;
		int sum = 0, count =0;
		
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter size : ");
		count = sc.nextInt();
		list = new int[count];
		
		for(int i =0;i<count;i++){
			System.out.println("Enter number : ");
			list[i] = sc.nextInt();
		}
		for (int i=0 ;i<count;i++)
			sum += list[i];
		System.out.println("Average : "+sum/count);
	}
}
*/
import java.util.Scanner;
//RuntimeException은 화면에 보이지는 않지만 실행과정에서 생길수 있으므로 처리해줘야 한다.
public class ExceptionTest {
	public static void main(String args[]){
		method();
	}
	public static void method(){
		int [] list;
		int sum = 0, count =0;
		try{
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter size : ");
			count = sc.nextInt();
		  //if (count < 0) throws NegativeArraySizeException
			list = new int[count];
	      //list = null;//NullPointerException
			for(int i =0;i<count;i++){
				System.out.println("Enter number : ");
				list[i] = sc.nextInt();
			}
			for (int i=0 ;i<count;i++)
	      //for (int i=0 ;i<=count;i++)//ArrayIndexOutOfBoundsException
				sum += list[i];
			System.out.println("Average : "+sum/count);
		  //System.out.println("Average : "+sum/0);//ArithmeticException
		}catch(ArithmeticException e){
			System.out.println("ArithmeticException");
		}catch(NegativeArraySizeException e){
			System.out.println("NegativeArraySizeException");
		}catch(ArrayIndexOutOfBoundsException e){
			System.out.println("ArrayIndexOutOfBoundsException");
		}catch(NullPointerException e){
			System.out.println("NullPointerException");
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
	}
}