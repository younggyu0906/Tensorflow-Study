import java.io.FileReader;
import java.io.FileWriter;  //FILE I/O ���� ��Ʈ��
import java.io.IOException;
import java.io.FileNotFoundException;

public class FileCopy2 {
	public static void main(String[] args){
		try{
			FileReader in = new FileReader("input.txt");//FileNotFoundException
			FileWriter out = new FileWriter("output.txt");
			int c; //���� 8��Ʈ�� ���
			System.out.println(System.getProperty("file.encoding"));
			while((c = in.read()) != -1){//read() �� int return,EOF == -1,����16��Ʈ ���
				out.write(c);            //read(), write()�� IOException ó�� �������
				System.out.println((char)c);//����ȯ �ʿ�
			}
			if(in != null)
				in.close();
			if(out != null)
				out.close();
		}catch(FileNotFoundException e){
			System.out.println("File open error");
			System.out.println(e.getMessage());
		}catch(IOException e){
			System.out.println("IOExcepton �߻�");
			System.out.println(e.getMessage());
		}
	}
}
