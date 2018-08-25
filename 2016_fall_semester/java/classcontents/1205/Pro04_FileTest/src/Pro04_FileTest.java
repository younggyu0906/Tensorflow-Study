import java.io.*;

class Student implements Serializable {
	private static final long serialVersionUID = 100L;
	private int id;
	private String name;
	
	public Student(int id, String name) {
		this.id = id;
		this.name = name;
	}
	public String toString() {
		return id + ", " + name;
	}
}
public class Pro04_FileTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ObjectInputStream in = null;
		ObjectOutputStream out = null;
		File file = new File("object.dat");
		
		
		try {
			out = new ObjectOutputStream(new FileOutputStream(file));
			out.writeObject(new Student(1, "Hong"));	// IOException
			out.writeObject(new Student(2, "Kim"));
			out.writeObject(new Student(3, "Choi"));
			out.flush();
			
			in = new ObjectInputStream(new FileInputStream("object.dat"));
			
			System.out.println((Student)in.readObject());	// ClassNotFoundException
			// readObject() 는 Object를 리턴하기 때문에 형변환 필요
			System.out.println((Student)in.readObject());
			System.out.println((Student)in.readObject());
			if (in != null)
				in.close();
			if (out != null)
				out.close();
		} catch (ClassNotFoundException e) {
			System.out.println("classNotFoundException");
			System.out.println(e.getMessage());
		} catch (IOException e) {
			System.out.println("IOException");
			System.out.println(e.getMessage());
		}
		
		System.out.println("Name : " + file.getName());
		System.out.println("Path : " + file.getPath());
		System.out.println("Parent : " + file.getParent());
		System.out.println("Absolute pate : " + file.getAbsolutePath());
		System.out.println("Is directory : " + file.isDirectory());
		System.out.println("Is file : " + file.isFile());
		System.out.println("Lengte : " + file.length());
		// file.deleteOnExit();
	}

}
