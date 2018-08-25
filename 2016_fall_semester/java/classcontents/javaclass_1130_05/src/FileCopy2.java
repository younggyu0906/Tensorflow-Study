import java.io.FileReader;
import java.io.FileWriter;  //FILE I/O 문자 스트림
import java.io.IOException;
import java.io.FileNotFoundException;

public class FileCopy2 {
	public static void main(String[] args){
		try{
			FileReader in = new FileReader("input.txt");//FileNotFoundException
			FileWriter out = new FileWriter("output.txt");
			int c; //하위 8비트만 사용
			System.out.println(System.getProperty("file.encoding"));
			while((c = in.read()) != -1){//read() 는 int return,EOF == -1,하위16비트 사용
				out.write(c);            //read(), write()는 IOException 처리 해줘야함
				System.out.println((char)c);//형변환 필요
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
