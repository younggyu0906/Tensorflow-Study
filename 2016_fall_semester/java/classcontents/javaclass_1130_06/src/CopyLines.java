//����  stream�� BufferedReader, BufferedWriter�� ���� ���
// Buffering�� �̿��� ����� ȿ���� ���δ�.

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
				//line���� �Է�, �ٹٲ� ��ȣ�� �������� �ʴ´�.
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
