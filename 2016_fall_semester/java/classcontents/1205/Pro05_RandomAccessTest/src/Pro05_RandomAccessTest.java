// 순차 접근 파일 (Sequential access file)
// 임의 접근 파일 (Random access file) : file pointer를 사용하여
// 파일의 임의 위치에 접근 가능
// 중요!
import java.io.*;

public class Pro05_RandomAccessTest {
	public static void main(String[] args) {
		RandomAccessFile inout;
		try {
			inout = new RandomAccessFile("inout.bin", "rw");
			
			inout.setLength(0);
			for (int i = 0; i < 10; i++)
				inout.writeInt(i);
			System.out.println("File length : " + inout.length());// 파일 길이
			System.out.println(inout.getFilePointer());	// 현재 파일 포인터 위치
			
			inout.seek(0);// 처음으로 이동
			System.out.println("number : " + inout.readInt());
			
			inout.skipBytes(4);	// 4byte 이동
			System.out.println("number : " + inout.readInt());
			
			inout.seek(5 * 4);	//6번째로 이동
			System.out.println(inout.getFilePointer());
			System.out.println("number : " + inout.readInt());
			
			inout.writeInt(555);	// 7번째 변경
			inout.seek(inout.length());	// 파일 끝으로 이동
			
			inout.writeInt(999);	// 마지막에 추가
			System.out.println("new length : " + inout.length());// 길이 변경 확인
			
			inout.seek(10 * 4);	// 11번째로 이동
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
