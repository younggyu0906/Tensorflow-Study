// DataInputStream, DataOutputStream �� byte stream�� ����
// byte ���� io�� �ƴϰ� data type ������ io
// ��� ������� �Է��ؾ���

import java.io.*;

public class Pro01_DataStreamTest {
	public static void main(String[] args) {
		DataInputStream in = null;
		DataOutputStream out = null;
		
		try {
			out = new DataOutputStream(new BufferedOutputStream(
					new FileOutputStream("data.bin")));
		// data.bin ���Ͽ� ����Ʈ ���� ���� �߷� ��Ʈ�� ���� ->
		// ����Ʈ ���� Ǯ�� ��Ʈ���� ���۸� ->
		// ����Ʈ ���� Ǯ���� ������ �� ���� ������� ��ȯ
			out.writeDouble(3.14);
			out.writeInt(100);
			out.writeChar('c');
			out.writeBoolean(true);
			out.writeUTF("test data");
			System.out.println(out.size());// ���礿�� ��µ� �������� ����Ʈ ��
			out.flush();// buffer�� �����ִ� ������ ���� ���
			
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
