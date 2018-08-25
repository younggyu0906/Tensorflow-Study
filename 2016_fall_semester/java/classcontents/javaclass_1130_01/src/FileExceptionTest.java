/*
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
public class FileExceptionTest {

	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new File("data.txt"));//data.txt 에서 읽어들임
			//File 객체 생성에 대한  FileNotFoundException 처리 해줘야함, runtimeException의 자손이 아님,자손이면 예외처리가 필수 아님
		} catch (FileNotFoundException e) {
			System.out.println("Exception 발생");
		}	
	}
}
*/
/*
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
public class FileExceptionTest {

	public static void main(String[] args) throws FileNotFoundException {//그냥 os에 책임전가, not good but 코드짧고 컴파일에러 없음
			Scanner in = new Scanner(new File("data.txt"));//data.txt 에서 읽어들임
	}
}
*/
/*
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class FileExceptionTest {
	public static void main(String args[]){
		Scanner in = myScanner();
	}
	public static Scanner myScanner(){
		Scanner in = null;
		try{
			in = new Scanner(new File("data.txt"));
		}catch (FileNotFoundException e){
			System.out.println("Exception 발생");
		}
		return in;
	}
}
*/
/*
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
//호출함수에서 main 메소드로 exception전달하고
//main 메소드에서 한번에 종합적으로 exeption처리(함수가 개별로 예외처리하는거 보다는 효율적)
public class FileExceptionTest {
	public static void main(String args[]){
		try {
			Scanner in = myScanner();
		} catch (FileNotFoundException e) {
			System.out.println("Exception 발생");
		}
		
	}
	public static Scanner myScanner() throws FileNotFoundException{
		Scanner in = null;
		in = new Scanner(new File("data.txt"));
		return in;
	}
}
*/
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
//여러개의 Exception을 main에 전달
public class FileExceptionTest {
	public static void main(String args[]){
		try {
			Scanner in = myScanner();
		} catch (FileNotFoundException e) {
			System.out.println("FileNotFoundException 발생");
		} catch (Exception e) {
			System.out.println("Exception 발생");
		}
		
	}
	public static Scanner myScanner() throws FileNotFoundException,Exception{
		Scanner in = null;
		in = new Scanner(new File("data.txt"));
		return in;
	}
}