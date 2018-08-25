import java.util.Scanner;

public class Pro02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int price, pay, vat, change;
		final double VAT_RATE = 0.1;
		
		Scanner input = new Scanner(System.in);
		System.out.print("Enter price : ");
		price = input.nextInt();
		System.out.print("Enter pay : ");
		pay = input.nextInt();
		vat = (int)(price * VAT_RATE);
		change = pay - price - vat;
		
		System.out.println("price " + price);
		System.out.println("payment " + pay);
		System.out.println("vat " + vat);
		System.out.println("change " + change);
		
		input.close();
	}

}
