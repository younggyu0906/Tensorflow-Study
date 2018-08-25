// DataInputStream, DataOutputStream 은 byte stream만 지원
// byte 단위 io가 아니고 data type 단위의 io
// 출력 순서대로 입력해야함

import java.io.*;

public class Pro01_DataStreamTest {
	public static void main(String[] args) {
		DataInputStream in = null;
		DataOutputStream out = null;
		
		try {
			out = new DataOutputStream(new BufferedOutputStream(
					new FileOutputStream("data.bin")));
		// data.bin 파일에 바이트 단위 파일 추력 스트림 개설 ->
		// 바이트 단위 풀력 스트림을 버퍼링 ->
		// 바이트 단위 풀력을 데이터 형 단위 출력으로 변환
			out.writeDouble(3.14);
			out.writeInt(100);
			out.writeChar('c');
			out.writeBoolean(true);
			out.writeUTF("test data");
			System.out.println(out.size());// 현재ㅏ지 출력된 데이터의 바이트 수
			out.flush();// buffer에 남아있는 데이터 강제 출력
			
			in = new DataInputStream(new BufferedInputStream(
					new FileInputStream("data.bin")));
			System.out.println(in.readDouble());
			System.out.println(in.readInt());
			System.out.println(in.readChar());
			System.out.println(in.readBoolean());
			System.out.println(in.readUTF());
			if (out != null)
				out.close();
			if (in != null)
				in.close();
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}
}
