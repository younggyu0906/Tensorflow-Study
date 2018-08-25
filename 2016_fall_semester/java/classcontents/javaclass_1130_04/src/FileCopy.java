import java.io.FileInputStream;
import java.io.FileOutputStream;  //FILE I/O ����Ʈ ��Ʈ��
import java.io.IOException;
import java.io.FileNotFoundException;

public class FileCopy {
	public static void main(String[] args){
		FileInputStream in = null;
		FileOutputStream out = null;
		try{
			in = new FileInputStream("input.txt");
			out = new FileOutputStream("output.txt");
			int c; //���� 8��Ʈ�� ���
			
			while((c = in.read()) != -1){//read() �� int return,EOF == -1,���� 8��Ʈ ���
				out.write(c);            //read(), write()�� IOException ó�� �������
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
