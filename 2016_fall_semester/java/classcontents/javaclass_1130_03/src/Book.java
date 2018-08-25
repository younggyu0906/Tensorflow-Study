
public class Book {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		sub();
	}
	public static void sub(){
		int []array = new int[10];
		try{
			int i = array[10];
		}catch(ArrayIndexOutOfBoundsException e){
			e.printStackTrace();
		}
	}
}
