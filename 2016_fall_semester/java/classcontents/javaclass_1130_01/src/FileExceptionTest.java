/*
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
public class FileExceptionTest {

	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new File("data.txt"));//data.txt ���� �о����
			//File ��ü ������ ����  FileNotFoundException ó�� �������, runtimeException�� �ڼ��� �ƴ�,�ڼ��̸� ����ó���� �ʼ� �ƴ�
		} catch (FileNotFoundException e) {
			System.out.println("Exception �߻�");
		}	
	}
}
*/
/*
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
public class FileExceptionTest {

	public static void main(String[] args) throws FileNotFoundException {//�׳� os�� å������, not good but �ڵ�ª�� �����Ͽ��� ����
			Scanner in = new Scanner(new File("data.txt"));//data.txt ���� �о����
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
			System.out.println("Exception �߻�");
		}
		return in;
	}
}
*/
/*
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
//ȣ���Լ����� main �޼ҵ�� exception�����ϰ�
//main �޼ҵ忡�� �ѹ��� ���������� exeptionó��(�Լ��� ������ ����ó���ϴ°� ���ٴ� ȿ����)
public class FileExceptionTest {
	public static void main(String args[]){
		try {
			Scanner in = myScanner();
		} catch (FileNotFoundException e) {
			System.out.println("Exception �߻�");
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
//�������� Exception�� main�� ����
public class FileExceptionTest {
	public static void main(String args[]){
		try {
			Scanner in = myScanner();
		} catch (FileNotFoundException e) {
			System.out.println("FileNotFoundException �߻�");
		} catch (Exception e) {
			System.out.println("Exception �߻�");
		}
		
	}
	public static Scanner myScanner() throws FileNotFoundException,Exception{
		Scanner in = null;
		in = new Scanner(new File("data.txt"));
		return in;
	}
}