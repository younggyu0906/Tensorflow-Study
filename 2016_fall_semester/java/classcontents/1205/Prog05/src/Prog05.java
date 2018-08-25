//FileMerge

import java.io.*;
public class Prog05 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader in1, in2;
		BufferedWriter out;
		String line;
		
		try {
			in1 = new BufferedReader(new FileReader("in1.txt"));
			in2 = new BufferedReader(new FileReader("in2.txt"));
			out = new BufferedWriter(new FileWriter("out.txt"));
			while ((line = in1.readLine()) != null) {
				out.write(line, 0, line.length());
				out.newLine();
			}
			while ((line = in2.readLine()) != null) {
				out.write(line, 0, line.length());
				out.newLine();
			}
			out.flush();
			in1.close();
			in2.close();
			
			BufferedReader in = new BufferedReader(new FileReader("out.txt"));
			while ((line = in.readLine()) != null)
				System.out.println(line);
			in.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
