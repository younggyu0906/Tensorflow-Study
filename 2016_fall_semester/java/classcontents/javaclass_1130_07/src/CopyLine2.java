//문자  stream을 BufferedReader, BufferedWriter와 같이 사용
// Buffering를 이요해 입출력 효율을 높인다.

import java.io.*;
public class CopyLine2 {
	public static void main(String[] args){
		BufferedInputStream in = null;
		BufferedOutputStream out = null;
		
		try{
			in = new BufferedInputStream(new FileInputStream("input.txt"));
			out = new BufferedOutputStream(new FileOutputStream("output.txt"));
			byte buffer[] =new byte[100]; 
			while((in.read(buffer)) != -1){
				//line단위 입력, 줄바꿈 기호는 포함하지 않는다.
				out.write(buffer);
				System.out.print(new String(buffer));
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
