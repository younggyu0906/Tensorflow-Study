import java.io.FileInputStream;
import java.io.FileOutputStream;  //FILE I/O 바이트 스트림
import java.io.IOException;
import java.io.FileNotFoundException;

public class FileCopy {
	public static void main(String[] args){
		FileInputStream in = null;
		FileOutputStream out = null;
		try{
			in = new FileInputStream("input.txt");
			out = new FileOutputStream("output.txt");
			int c; //하위 8비트만 사용
			
			while((c = in.read()) != -1){//read() 는 int return,EOF == -1,하위 8비트 사용
				out.write(c);            //read(), write()는 IOException 처리 해줘야함
			}
			if(in != null)
				in.close();
			if(out != null)
				out.close();
		}catch(FileNotFoundException e){
			System.out.println("File open error");
			System.out.println(e.getMessage());
		}catch(IOException e){
			System.out.println("IOExcepton 발생");
			System.out.println(e.getMessage());
		}
	}
}
