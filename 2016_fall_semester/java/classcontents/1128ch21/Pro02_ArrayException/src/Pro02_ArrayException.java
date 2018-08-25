/*
public class Pro02_ArrayException {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] array = {1, 2, 3, 4, 5};
		
		for (int i = 0; i <= array.length; i++)
			System.out.println(array[i] + " ");
		
		System.out.println("Program ends\n");
	}
}
*/
public class Pro02_ArrayException {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] array = {1, 2, 3, 4, 5};
		
		try {
			for (int i = 0; i <= array.length; i++)
				System.out.println(array[i] + " ");
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Array index out of bounds exception");
		} finally {
			System.out.println("Finally block");
		}
		System.out.println("Program ends\n");
	}
}