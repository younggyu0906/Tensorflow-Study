class NegativeBalanceException extends Exception {
	public NegativeBalanceException() {
		super("Negative Balance Exception");
	}
}

class BankAccount {
	private int balance = 0;
	// 입금 메소드
	public void deposit(int money) {
		balance += money;
	}
	// 출금 메소드
	public void withdraw(int money) throws NegativeBalanceException {
		if(money > balance)	// 출금하려는 금액이 잔액보다 크면 예외를 발생시켜 던짐
			throw new NegativeBalanceException();
		else
			balance -= money;
	}
	// 잔액 출력 메소드
	public void display() {
		System.out.println("balance = " + balance);
	}
}

public class Ch21_Pro04 {
	public static void main(String[] args) {
		BankAccount b = new BankAccount();
		b.display();		// 잔액 0
		b.deposit(10000);	// 10000입금
		b.display();		// 잔액 10000
		try {	// 예외가 발생할 수 있는 코드
			b.withdraw(6000);	// 6000 출금
		} catch (NegativeBalanceException e) {	// 예외처리
			System.out.println(e.getMessage());	// 콘솔에 오류 메시지 출력
			e.printStackTrace();				// 오류가 발생한 정보 출력
		}
		b.display();		// 잔액 4000
		try {	// 예외가 발생할 수 있는 코드
			b.withdraw(6000);	// 6000 출금 예외발생!!
		} catch (NegativeBalanceException e) {	// 예외처리
			System.out.println(e.getMessage());	// 콘솔에 오류 메시지 출력
			e.printStackTrace();				// 오류가 발생한 정보 출력
		}
		b.display();		// 잔액 4000원
	}
}
