//����  stream�� BufferedReader, BufferedWriter�� ���� ���
// Buffering�� �̿��� ����� ȿ���� ���δ�.

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
				//line���� �Է�, �ٹٲ� ��ȣ�� �������� �ʴ´�.
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
