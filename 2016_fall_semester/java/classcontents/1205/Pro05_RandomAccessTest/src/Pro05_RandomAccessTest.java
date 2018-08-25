// ���� ���� ���� (Sequential access file)
// ���� ���� ���� (Random access file) : file pointer�� ����Ͽ�
// ������ ���� ��ġ�� ���� ����
// �߿�!
import java.io.*;

public class Pro05_RandomAccessTest {
	public static void main(String[] args) {
		RandomAccessFile inout;
		try {
			inout = new RandomAccessFile("inout.bin", "rw");
			
			inout.setLength(0);
			for (int i = 0; i < 10; i++)
				inout.writeInt(i);
			System.out.println("File length : " + inout.length());// ���� ����
			System.out.println(inout.getFilePointer());	// ���� ���� ������ ��ġ
			
			inout.seek(0);// ó������ �̵�
			System.out.println("number : " + inout.readInt());
			
			inout.skipBytes(4);	// 4byte �̵�
			System.out.println("number : " + inout.readInt());
			
			inout.seek(5 * 4);	//6��°�� �̵�
			System.out.println(inout.getFilePointer());
			System.out.println("number : " + inout.readInt());
			
			inout.writeInt(555);	// 7��° ����
			inout.seek(inout.length());	// ���� ������ �̵�
			
			inout.writeInt(999);	// �������� �߰�
			System.out.println("new length : " + inout.length());// ���� ���� Ȯ��
			
			inout.seek(10 * 4);	// 11��°�� �̵�
			System.out.println("number : " + inout.readInt());
			
			inout.seek(0);
			for (int i = 0; i < inout.length(); i += 4)
				System.out.println(inout.readInt());
			inout.close();
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}

}
