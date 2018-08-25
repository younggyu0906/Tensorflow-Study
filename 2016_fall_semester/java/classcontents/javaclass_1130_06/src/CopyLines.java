//문자  stream을 BufferedReader, BufferedWriter와 같이 사용
// Buffering를 이요해 입출력 효율을 높인다.

import java.io.*;
public class CopyLines {
	public static void main(String[] args){
		BufferedReader in = null;
		BufferedWriter out = null;
		
		try{
			in = new BufferedReader(new FileReader("input.txt"));
			out = new BufferedWriter(new FileWriter("output.txt"));
			String str;
			while((str = in.readLine()) != null ){
				//line단위 입력, 줄바꿈 기호는 포함하지 않는다.
				out.write(str+ "\n");
				System.out.print(str+ "\n");
			}
			if(in != null)
				in.close();
			if(out != null)
				out.close();
		}catch(FileNotFoundException e){
			System.out.println(e.getMessage());
		}catch(IOException e){
			System.out.println(e.getMessage());
		}
	}
}
